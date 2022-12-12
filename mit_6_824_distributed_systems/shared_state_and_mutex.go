package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

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
}

type Fetcher struct {
	urls []string
}

func (f Fetcher) Fetch(url string) ([]string, error) {
	fmt.Println(url)
	rand.Seed(time.Now().UnixNano())
	return f.urls[:rand.Intn(6)], nil
}

// Concurrent crawler with shared state and Mutex
type fetchState struct {
	mu      sync.Mutex
	fetched map[string]bool
}

func ConcurrentMutex(url string, fetcher Fetcher, f *fetchState) {
	//f.mu.Lock()
	already := f.fetched[url]
	f.fetched[url] = true
	//f.mu.Unlock()

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
			defer done.Done()
			ConcurrentMutex(u, fetcher, f)
		}(u)
	}
	done.Wait()
	return
}
