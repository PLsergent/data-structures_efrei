package waitingRoom

import "fmt"

// PatientsQueue struct
// Each pair := {examination time, total waiting time} (in minutes)
type PatientsQueue struct {
	values          []Pair
	lastIn, nextOut Pair
}

func (q PatientsQueue) InitQueue() {
	q.values = []Pair{}
}

// Push at the end of the queue
func (q *PatientsQueue) PushQueue(val int) {
	pair := MakePair(val, 0)
	q.values = append(q.values, pair)
	q.lastIn = pair
	q.nextOut = q.values[0]
	fmt.Printf("Pushed value : ")
	pair.Print()
	fmt.Println()
}

// Insert in the sorted queue, based on examination time
func (q *PatientsQueue) PushQueueTime(val int) {
	pair := MakePair(val, 0)
	index := 0

	// Iterate over the array to find the index where we'll insert the new Pair
	for index = 0; index < len(q.values); index++ {
		// If the inserted Pair has an examination time lower than the current Pair 
		if (pair.Get(0) < q.values[index].Get(0)) {
			// then we break the loop to keep the index value
			break
		}
	}
	q.values = insertSort(q.values, pair, index) // Insert the pair at the index
	q.lastIn = pair
	q.nextOut = q.values[0]
	fmt.Printf("Pushed value : ")
	pair.Print()
	fmt.Println()
}

func insertSort(data []Pair, el Pair, index int) []Pair {
	data = append(data, Pair{})
	copy(data[index+1:], data[index:])
	data[index] = el
	return data
}

func (q *PatientsQueue) PopQueue() Pair {
	if len(q.values) > 0 {
		pair := q.values[0]
		examTime := pair.Get(0)
		waitingTime := pair.Get(1)

		if len(q.values) == 1 {
			q.values = []Pair{}
		} else {
			q.values = q.values[1:]
			// We add the previous patient waiting time + his examination time
			// to the total waiting time of the next patient
			q.values[0].Set(1, waitingTime + examTime)
			q.nextOut = q.values[0]
		}
		
		fmt.Printf("Poped value : ")
		pair.Print()
		fmt.Println()
		return pair
	}
	fmt.Println("The queue is empty!")
	return MakePair(-1, -1)
}

func (q PatientsQueue) Size() int {
	return len(q.values)
}

// Recursive display
func (q PatientsQueue) DisplayQueue() {
	if len(q.values) > 0 {
		fmt.Printf("Queue : ")
		q.values[0].Print()
		displayQueue(q.values[1:])
		fmt.Println()
	} else {
		fmt.Println("The queue is empty!")
	}
}

func displayQueue(values []Pair) {
	if len(values) > 0 {
		values[0].Print()
		displayQueue(values[1:])
	}
}
