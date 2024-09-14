package main

import "fmt"

const NMAX int = 1024

type himpunan [NMAX]int

func ada(himp himpunan, n, v int) int {
	var i, idx int
	idx = -1
	for i < n && idx == -1 {
		if himp[i] == v {
			idx = i
		}
	}
	return idx
}

func himpSama(h1 himpunan, n int) bool {
	var v, i, idx int
	for i = 0; i < n; i++ {
		fmt.Scan(&v)
		idx = ada(h1, n, v)
		if idx != -1 {
			h1[idx] = -1 * h1[idx]
		} else {
			break
		}
	}
	return h1[i] < 0
}

func bacaHimp(h1 *himpunan, n int) {
	var i int
	for i = 0; i < n; i++ {
		fmt.Scan(&h1[i])
	}
}

func main() {
	var n int
	var h1 himpunan
	fmt.Scan(&n)
	bacaHimp(&h1, n)
	if himpSama(h1, n) {
		fmt.Println("Kedua himpunan sama")
	} else {
		fmt.Println("Kedua himpunan berbeda")
	}
}