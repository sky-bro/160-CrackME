// 以十六进制形式输出P-boxes和S-boxes的内容（也就是Pi的小数部分）
package main

import (
	"fmt"

	"github.com/claygod/PiHex"
)

func main() {
	fmt.Println("P-boxes")
	pi := PiHex.New()
	start := 0
	end := 18
	for i := start; i < end; {
		for k := 0; k < 5 && i < end; k++ {
			for _, j := range pi.Get(i*8, 8) {
				fmt.Printf("%X", j)
			}
			fmt.Print(" ")
			i++
		}
		fmt.Println()
	}

	fmt.Println("S-boxes")
	start = 18
	end = 18 + 1024
	for i := start; i < end; {
		for k := 0; k < 5 && i < end; k++ {
			for _, j := range pi.Get(i*8, 8) {
				fmt.Printf("%X", j)
			}
			fmt.Print(" ")
			i++
		}
		fmt.Println()
	}
}
