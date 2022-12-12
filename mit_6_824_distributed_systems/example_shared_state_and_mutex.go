package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

/*



















 */
// Concurrent crawler with shared state and Mutex
//

func main() {
	var fetcher Fetcher
	fetcher.urls = []string{
		"http://golang.org",
		"http://golang.org/pkg",
		"http://golang.org/pkg/os",
		"http://golang.org/pkg/fmt",
		"http://golang.org/cmd",
	}
	var f fetchState
	f.fetched = map[string]bool{"http://golang.org": false}
	ConcurrentMutex("http://golang.org", fetcher, &f)

	//	urls, err := fetcher.Fetch("a")
	//	if err != nil {
	//		fmt.Println("nothing crawled")
	//		return
	//	}
	//	fmt.Println(urls)
}

type Fetcher struct {
	urls []string
}

func (f Fetcher) Fetch(url string) ([]string, error) {
	fmt.Println(url)
	rand.Seed(time.Now().UnixNano())
	return f.urls[:rand.Intn(6)], nil
}

type fetchState struct {
	mu      sync.Mutex
	fetched map[string]bool
}

func ConcurrentMutex(url string, fetcher Fetcher, f *fetchState) {
	f.mu.Lock()
	already := f.fetched[url]
	f.fetched[url] = true
	f.mu.Unlock()

	if already {
		return
	}

	urls, err := fetcher.Fetch(url)
	if err != nil {
		return
	}
	var done sync.WaitGroup
	for _, u := range urls {
		done.Add(1)
		go func(u string) {
			ConcurrentMutex(u, fetcher, f)
			done.Done()
		}(u)
	}
	done.Wait()
	return
}
