package main

import "fmt"

func printPrimes(limit int) {
	primes := make([]bool, limit+1)

	// 0 and 1 are not prime
	primes[0] = false
	primes[1] = false

	for i := 2; i <= limit; i++ {
		primes[i] = true
	}

	for i := 2; i*i <= limit; i++ {
		if primes[i] {
			for j := i * i; j <= limit; j += i {
				primes[j] = false
			}
		}
	}

	for i := 2; i <= limit; i++ {
		if primes[i] {
			fmt.Println(i)
		}
	}
}

func main() {
	printPrimes(100000000)
}
