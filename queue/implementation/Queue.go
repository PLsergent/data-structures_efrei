package implementation

// Queue struct
type Queue interface {
	InitQueue()        // initalize the data structure
	PushQueue(val int) // push value into queue
	PopQueue() int     // pops value from queue
	DisplayQueue()     // displays the contents of the queue
}
