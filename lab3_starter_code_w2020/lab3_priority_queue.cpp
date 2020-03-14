//#include "lab3_priority_queue.hpp"
//
//using namespace std;
//
//// PURPOSE: Parametric constructor 
//// initializes heap to an array of (n_capacity + 1) elements
//PriorityQueue::PriorityQueue(unsigned int n_capacity) {
//
//	// double pointer array with capacity of n_capacity + 1
//	heap = new TaskItem*[n_capacity + 1]();
//	
//	//initialise capacity to constructor argument and size to 0
//	capacity = n_capacity;
//	size = 0;
//	
//}
//
//// PURPOSE: Explicit destructor of the class PriorityQueue
//PriorityQueue::~PriorityQueue() {
//	
//	for (int i=1; i < size; ++i)
//	{
//		delete heap[i];
//		heap[i] = NULL;
//	}
//	
//	delete [] heap;
//	heap = NULL;
//	capacity = 0;
//	size = 0;
//}
//
//// PURPOSE: Returns the number of elements in the priority queue
//unsigned int PriorityQueue::get_size() const {
//	
//	//1st case: if heap is empty
//	if(size == 0)
//	{
//		return 0;
//	}
//	//2nd case: list not empty
//	else
//	{
//		// manual check for size 
//		/*
//		int count = 0;
//		while(heap[count])
//		{
//			count++;
//		}
//		
//		return count;
//		*/
//		
//		return size;
//	}
//	
//	return 0;
//}
//
//// PURPOSE: Returns true if the priority queue is empty; false, otherwise
//bool PriorityQueue::empty() const {
//	
//	if (this->get_size() == 0 || *heap[0] == NULL || size == 0)
//		return true;
//	else
//		return false;
//}
//
//// PURPOSE: Returns true if the priority queue is full; false, otherwise
//bool PriorityQueue::full() const {
//	
//	// capacity = size of queue
//	if( capacity == this->get_size())
//		return true
//	else
//		return false;
//}
//
//// PURPOSE: Prints the contents of the priority queue; format not specified
//void PriorityQueue::print() const {
//	//printing format:
//	
//	// Priority: #
//	// Description:
//	//---------------
//	
//	//case 1: empty list
//	if (this->empty())
//		cout << "list is empty" << endl;
//	//case 2: non empty list
//	else
//	{
//		TaskItem* temp;
//		for (int i=1; i < this->get_size(); i++)
//		{
//			temp = heap[i];
//			cout << "Priority: " << temp->priority << '\n' << "Description: " << temp->description << '\n' << "------------" << endl;			
//		}
//	}
//}
//
//// PURPOSE: Returns the max element of the priority queue without removing it
//// if the priority queue is empty, it returns (-1, "N/A")
//PriorityQueue::TaskItem PriorityQueue::max() const {
//	
//	//1st case: if the priority queue is empty
//	if(size == 0)
//	{
//		return TaskItem(-1, "NULL"); 
//	}
//	
//	//2nd case: returning what is in the 1st index as based on Max Heap ADT 
//	else
//	{
//		return **heap[1];
//	}
//	//return TaskItem(-1, "NULL");
//}
//
//// PURPOSE: Inserts the given value into the priority queue
//// re-arranges the elements back into a heap
//// returns true if successful and false otherwise
//// priority queue does not change in capacity
//bool PriorityQueue::enqueue( TaskItem val ) {
//	
//	//case 0: fixed capacity array of pointers
//	if (size == capacity)
//		return false;
//	
//	//case 1: base case: empty heap
//	if (size == 0)
//	{
//		heap [1] = new TaskItem(val);
//	}
//	
//	//case 2: general case: non-empty heap
//	else
//	{
//		int i = size + 1;
//		heap[i] = new TaskItem(val);
//		while (i > 1 && heap[i/2]->priority < heap[i]->priority)
//		{
//			TaskItem* temp = heap[i]; //swap values
//			heap[i] = heap[i/2];
//			heap[i/2] = temp;
//			i /= 2;
//		}
//	}
//	
//	size++;
//	return true;
//}
//
//// PURPOSE: Removes the top element with the maximum priority
//// re-arranges the remaining elements back into a heap
//// returns true if successful and false otherwise
//// priority queue does not change in capacity
//bool PriorityQueue::dequeue() {
//	
//	//1st case: if list is empty
//	if(size == 0)
//	{
//		return false;
//	}
//	
//	//2nd case: list is populated
//	else
//	{
//		while( size + 1 > 1 && heap[(size+1)/2]->priority < heap[size + 1]->priority)
//		{
//			*TaskItem temp = heap[size + 1];
//			heap[size + 1] = heap[(size + 1)/2];
//			heap[(size + 1)/2] = temp;
//			(size + 1) /= 2;
//		}
//		
//	}
//	
//	size--;
//	return true;
//}
