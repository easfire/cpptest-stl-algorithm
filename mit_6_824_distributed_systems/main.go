package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	urls := []string{"aa", "bb", "cc"}
	fmt.Println(urls[:1])
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 4; i++ {
		println(rand.Intn(5))
	}
}
