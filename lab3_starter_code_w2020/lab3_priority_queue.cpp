//#include "lab3_priority_queue.hpp"
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
//	if (size == 0)
//		return true;
//	else
//		return false;
//}
//
//// PURPOSE: Returns true if the priority queue is full; false, otherwise
//bool PriorityQueue::full() const {
//	
//	// capacity = size of queue
//	if( capacity == size)
//		return true;
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
//		cout << "list is empty" << '\n' << "------------" << endl;
//	//case 2: non empty list
//	else
//	{
//		cout << "**************************************" << endl;
//		TaskItem* temp;
//		for (int i=1; i <= size; i++)
//		{
//			temp = heap[i];
//			cout << "Position: " << i << '\n' << "Priority: " << temp->priority << '\n' << "Description: " << temp->description << '\n' << "------------" << endl;			
//		}
//		cout << "**************************************" << endl;
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
//		return *heap[1];
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
//		size++;
//		return true;
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
//		size++;
//		return true;	
//	}
//	
//	return false;
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
//		//swap root with last leaf node
//		int j = size;
//		TaskItem *temp = heap[j];
//		heap[j] = heap[1];
//		heap[1] = temp;
//		
//		//remove root from last position
//		TaskItem *del = heap[j];
//		delete del;
//		del = NULL;
//		
//		size--;		
//		
//		//traverse tree top-to-bottom and swap nodes appropriately
//		int i = 1; //start at root node
//		bool flag = 0;
//		
//		//case 2: parent has 2 children
//		while (flag == 0) //parent < left_child OR parent < right_child
//		{			
//			//case 1: parent < left_child
//			if (2*i < size)
//			{
//				if (heap[i]->priority < heap[2*i]->priority)
//				{
//					TaskItem *temp = heap[i]; //holds parent
//					heap[i] = heap[2*i];
//					heap[2*i] = temp;
//					
//					i = 2*i; //will now be at previous position of child					
//				}
//			}
//			
//			//case 2: parent < right_child
//			else if (2*i+1 < size)
//			{
//				if (heap[i]->priority < heap[2*i+1]->priority)
//				{
//					TaskItem *temp = heap[i]; //holds parent
//					heap[i] = heap[2*i+1];
//					heap[2*i+1] = temp;
//					
//					i = 2*i+1; //will now be at previous position of child					
//				}
//			}
//			
//			//stop looping
//			if ((heap[i]->priority > heap[2*i+1]->priority) || (heap[i]->priority > heap[2*i]->priority))
//				flag = 1;			
//		}
//	}
//	
//	return true;
//}
