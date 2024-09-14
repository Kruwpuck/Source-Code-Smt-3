package main

import "fmt"

func main() {
	var n, ganjil, genap int
	fmt.Scan(&n)
	hitung(n, &ganjil, &genap)
	fmt.Println(ganjil, genap)
}
func hitung(n int, ganjil, genap *int) {
	for i := 2; i <= n; i++ {
		if prima(i) {
			if i %2 == 0{
				*genap++
			}else{
				*ganjil++
			}
		}
	}

}
func prima(i int) bool  {
	if i %2 == 0 && i>2{
		return false
	}
	for j := 2; j <= i-1; j++ {
		if i % j == 0{
			return false
		}
	}
	return true
}