package waitingRoom

import "fmt"

// Each pair := {examination time, total waiting time} (in minutes)
type Pair struct {
	vals [2]int
}

func MakePair(k, v int) Pair {
	return Pair{[2]int{k, v}}
}

func (p Pair) Get(i int) int {
	return p.vals[i]
}

func (p *Pair) Set(index int, value int) {
	p.vals[index] = value
}

func (p Pair) Print() {
	fmt.Print("{", p.Get(0), ", ", p.Get(1), "} ")
}