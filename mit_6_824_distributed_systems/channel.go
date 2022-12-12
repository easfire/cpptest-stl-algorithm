package main

import "fmt"

func main() {
	fmt.Println("vim-go")
}
func worker(url string, ch chan []string, fetcher Fetcher) { // ④
	urls, err := fetcher.Fetch(url)
	if err != nil {
		ch <- []string{}
	} else {
		ch <- urls
	}
}

func master(ch chan []string, fetcher Fetcher) {
	n := 1
	fetched := make(map[string]bool) // ①
	for urls := range ch {           // ②
		for _, u := range urls { // ③
			if fetched[u] == false {
				fetched[u] = true
				n += 1
				go worker(u, ch, fetcher)
			}
		}
		n -= 1
		if n == 0 {
			break // ⑥
		}
	}
}

func ConcurrentChannel(url string, fetcher Fetcher) {
	ch := make(chan []string)
	go func() { // ⑤
		ch <- []string{url}
	}()
	master(ch, fetcher)
}
