package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintf(os.Stderr, "Missing Parameters!\n")
		os.Exit(1)
	}
	words, chars := 0, 0
	for i := 1; i < len(os.Args); i++ {
		words++
		fmt.Printf("[%d] %s -> %d\n", i, os.Args[i], len(os.Args[i]))
		chars += len(os.Args[i])
	}
	fmt.Printf("\nWords -> %d\n", words)
	fmt.Printf("Characters -> %d\n", chars)
}

