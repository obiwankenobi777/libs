package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) < 3 {
		fmt.Fprintf(os.Stderr, "Missing Parameters!\n")
		os.Exit(1)
	}

	if os.Args[1] != os.Args[2] {
		fmt.Println("String are differents!")
	} else {
		fmt.Println("The Strigs are equals!")
	}
}

