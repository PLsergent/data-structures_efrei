package main

import (
	q "queue/implementation"
	"fmt"
)

// Main function
func main() {
	fmt.Println("====== Linked list implementation ======")
	queue := q.ListQueue{}
	queue.InitQueue()
	queue.PushQueue(1)
	queue.PushQueue(2)
	queue.PushQueue(3)
	queue.DisplayQueue()
	queue.PopQueue()
	queue.DisplayQueue()
	fmt.Println("========================================")
	
	fmt.Println("========= Array implementation =========")
	queue2 := q.ArrayQueue{}
	queue2.InitQueue()
	queue2.PushQueue(1)
	queue2.PushQueue(2)
	queue2.PushQueue(3)
	queue2.DisplayQueue()
	queue2.PopQueue()
	queue2.DisplayQueue()
	fmt.Println("========================================")
}
