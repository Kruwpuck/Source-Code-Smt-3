package main

import "fmt"

const NMAX int = 1024

type himpunan [NMAX]int

// Function to check if a value 'v' exists in the array 'himp' of size 'n'.
// If it exists, return the index of the value, otherwise return -1.
func ada(himp himpunan, n, v int) int {
	for i := 0; i < n; i++ {
		if himp[i] == v {
			return i
		}
	}
	return -1
}

// Function to compare the first set with a second set input by the user.
// It returns true if all elements of the second set are found in the first set.
func himpSama(h1 himpunan, n int) bool {
	var v, idx int
	for i := 0; i < n; i++ {
		fmt.Scan(&v)
		idx = ada(h1, n, v)
		if idx != -1 {
			h1[idx] = -1 * h1[idx] // Mark the element as found by negating it
		} else {
			return false
		}
	}
	return true
}

// Function to read a set of integers from the user.
func bacaHimp(h1 *himpunan, n int) {
	for i := 0; i < n; i++ {
		fmt.Scan(&h1[i])
	}
}

func main() {
	var n int
	var h1 himpunan

	fmt.Print("Enter the number of elements in the set: ")
	fmt.Scan(&n)

	fmt.Println("Enter the elements of the first set:")
	bacaHimp(&h1, n)

	fmt.Println("Enter the elements of the second set:")
	if himpSama(h1, n) {
		fmt.Println("Kedua himpunan sama")
	} else {
		fmt.Println("Kedua himpunan berbeda")
	}
}
