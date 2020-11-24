package implementation

import "fmt"

// Node struct
type Node struct {
	next *Node
	val  int
}

// ListQueue struct
type ListQueue struct {
	head *Node
	tail *Node
}

func (l *ListQueue) InitQueue() {
	l.head = nil
	l.tail = nil
}

func (l *ListQueue) PushQueue(val int) {
	newNode := &Node{
		next: nil,
		val:  val,
	}

	if l.head == nil {
		l.head = newNode
		l.tail = newNode
	} else {
		l.tail.next = newNode
		l.tail = newNode
	}
	fmt.Printf("Pushed value : %d\n", val)
}

func (l *ListQueue) PopQueue() int {
	if l.head == nil {
		fmt.Println("The queue is empty!")
		return -1
	}
	value := l.head.val
	l.head = l.head.next
	fmt.Printf("Poped value : %d\n", value)
	return value
}

func (l *ListQueue) DisplayQueue() {
	node := l.head
	fmt.Print("Queue : ")
	for node != nil {
		fmt.Printf("%d ", node.val)
		node = node.next
	}
	fmt.Println()
}
