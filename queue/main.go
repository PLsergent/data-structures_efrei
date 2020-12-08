package main

import (
	q "queue/implementation"
	wr "queue/waitingRoom"
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

	fmt.Println("========== Patients queue n°1 ==========")
	// First In, First Out
	waiting_room := wr.PatientsQueue{}
	waiting_room.InitQueue()
	waiting_room.PushQueue(30)
	waiting_room.PushQueue(20)
	waiting_room.PushQueue(10)
	waiting_room.PushQueue(5)
	waiting_room.DisplayQueue()

	waitingTime := []int{}
	for {
		lastPatient := waiting_room.PopQueue()
		waitingTime = append(waitingTime, lastPatient.Get(1))
		if waiting_room.Size() == 0 {
			break
		}
	}
	waiting_room.DisplayQueue()

	result := 0  
	for _, v := range waitingTime {  
		result += v
	}

	fmt.Println("Average waiting time :", float64(result)/float64(len(waitingTime)), "min")
	fmt.Println("========================================")

	fmt.Println("========== Patients queue n°2 ==========")
	// Lowest examination time, First out
	waiting_room2 := wr.PatientsQueue{}
	waiting_room2.InitQueue()
	waiting_room2.PushQueueTime(30)
	waiting_room2.PushQueueTime(20)
	waiting_room2.PushQueueTime(10)
	waiting_room2.PushQueueTime(5)
	waiting_room2.DisplayQueue()

	waitingTime2 := []int{}
	for {
		lastPatient2 := waiting_room2.PopQueue()
		waitingTime2 = append(waitingTime2, lastPatient2.Get(1))
		if waiting_room2.Size() == 0 {
			break
		}
	}
	waiting_room2.DisplayQueue()

	result2 := 0  
	for _, v := range waitingTime2 {  
		result2 += v
	}

	fmt.Println("Average waiting time :", float64(result2)/float64(len(waitingTime2)), "min")
	fmt.Println("========================================")
	// Answer :
	// When the patient with the lowest examination time goes first (first out of the queue,
	// the average waiting time is lower.
	// Indeed, having the patient with the highest examination time first will increase all the other patients
	// waiting time. So the average will be higher.
	// Moreover when the queue is sorted the average waiting time is fixed
}
