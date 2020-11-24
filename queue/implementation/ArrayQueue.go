package implementation

import "fmt"

// ArrayQueue struct
type ArrayQueue struct {
	values          []int
	lastIn, nextOut int
}

func (q ArrayQueue) InitQueue() {
	q.values = []int{}
}

func (q *ArrayQueue) PushQueue(val int) {
	q.values = append(q.values, val)
	q.lastIn = q.values[len(q.values)-1]
	q.nextOut = q.values[0]
	fmt.Printf("Pushed value : %d\n", val)
}

func (q *ArrayQueue) PopQueue() int {
	if len(q.values) > 0 {
		value := q.values[0]
		q.values = q.values[1:]
		fmt.Printf("Poped value : %d\n", value)
		return value
	}
	fmt.Println("The queue is empty!")
	return -1
}

// Recursive display
func (q ArrayQueue) DisplayQueue() {
	if len(q.values) > 0 {
		fmt.Printf("Queue : %d ", q.values[0])
		displayQueue(q.values[1:])
		fmt.Println()
	} else {
		fmt.Println("The queue is empty!")
	}
}

func displayQueue(values []int) {
	if len(values) > 0 {
		fmt.Printf("%d ", values[0])
		displayQueue(values[1:])
	}
}
