package main

import "fmt"
func main() {
	var total,sandi,n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&sandi)
		total+= (sandi % 10) + (sandi / 1000)
	}
	fmt.Println(total)
}