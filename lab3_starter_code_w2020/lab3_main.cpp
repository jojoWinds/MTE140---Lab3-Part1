#include <iostream>
#include <string>
#include "lab3_tests.hpp"
#include "lab3_priority_queue.hpp"
#include "lab3_binary_search_tree.hpp"

using namespace std;

/*
// PURPOSE: Returns the test result
string get_status_str(bool status) {
    return status ? "TEST PASSED" : "TEST FAILED";
}

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;
*/

//test main function
int main()
{
	BinarySearchTree tree1;		//test constructor //status: pass
	tree1.~BinarySearchTree(); 	//test destructor //status: pass
	
	bool test = tree1.insert(BinarySearchTree::TaskItem(1,"task1"));	//test insert //status: pass but need to put back to 'protected'
	cout << "test insert: " << test << endl;
	test = tree1.insert(BinarySearchTree::TaskItem(2,"task2"));
	cout << "test insert: " << test << endl;
	test = tree1.insert(BinarySearchTree::TaskItem(3,"task3"));
	cout << "test insert: " << test << endl;
	
	BinarySearchTree::TaskItem task1 = tree1.max(); //test max() //status: pending
	cout << "test max:" << '\n' << "priority: " << task1.priority << '\n' << "description: " << task1.description << endl;
	BinarySearchTree::TaskItem task2 = tree1.min(); //test max() //status: pending
	cout << "test max:" << '\n' << "priority: " << task2.priority << '\n' << "description: " << task2.description << endl;
	
	/*
	test = tree1.remove(BinarySearchTree::TaskItem(1,"task1")); //test remove //status: pass
	cout << "test remove: " << test << endl;
	*/
	tree1.print();
	
	
	return 0;
}

/* //ORIGINAL main function
int main() {

    PriorityQueueTest pqueue_test;
    BinarySearchTreeTest bst_test;

	string pqueue_test_descriptions[4] = {
      "Test1: New queue is valid",
      "Test2: Enqueue one item and then dequeue it",
      "Test3: Enqueue too many",
      "Test4: Enqueue too many then dequeue too many"
	};
	
	bool pqueue_test_results[4];
    pqueue_test_results[0] = pqueue_test.test1();
    pqueue_test_results[1] = pqueue_test.test2();
    pqueue_test_results[2] = pqueue_test.test3();
    pqueue_test_results[3] = pqueue_test.test4();

	cout << "PRIORITY QUEUE TESTING RESULTS \n";
	cout << "****************************** \n";
	for (int i = 0; i < 4; ++i) {
    	cout << pqueue_test_descriptions[i] << endl << get_status_str(pqueue_test_results[i]) << endl;
	}
	cout << endl;
    
	string bst_test_descriptions[8] = {
      "Test1: New tree is valid",
      "Test2: Test a tree with one node",
      "Test3: Insert, remove, and size on linear list formation with three elements",
      "Test4: Test removal of a node with one child",
      "Test5: Insert multiple elements and remove till nothing remains",
      "Test6: Test removal of root node when both children of root have two children",
      "Test7: Test depth with many inserts and some removes",
      "Test8: Lots of inserts and removes"
	};    
    bool bst_test_results[8];
    bst_test_results[0] = bst_test.test1();
    bst_test_results[1] = bst_test.test2();
    bst_test_results[2] = bst_test.test3();
    bst_test_results[3] = bst_test.test4();
    bst_test_results[4] = bst_test.test5();
    bst_test_results[5] = bst_test.test6();
    bst_test_results[6] = bst_test.test7();
    bst_test_results[7] = bst_test.test8();

	cout << "BINARY SEARCH TREE TESTING RESULTS \n";
	cout << "********************************** \n";
	for (int i = 0; i < 8; ++i) {
    	cout << bst_test_descriptions[i] << endl << get_status_str(bst_test_results[i]) << endl;
	}
	cout << endl;
	return 0;
}

*/






//---------------------------------------------------------------------------------------------------------------------------------
	
//	MANUAL TESTING FOR QUEUE CLASS-----------------------------------------------------------------------------------------
//	PriorityQueue q1(5);
//	ASSERT_TRUE( q1.empty() );
//	ASSERT_TRUE( !q1.full() );
//	ASSERT_TRUE( q1.get_size() == 0 );
	
//	PriorityQueue q2(2);
//	cout << "test1: " << q2.enqueue(PriorityQueue::TaskItem(10,"Test Task")) << endl;
//	cout << "test2: " << !q2.empty() << endl;
//	cout << "test3: " << !q2.full() << endl;
//	bool test;
//	if (q2.get_size() == 1)
//		test = 1;
//	else
//		test = 0;
//	cout << "test4: " << test << endl;
//	if (q2.max().priority == 10)
//		test = 1;
//	else
//		test = 0;
//	cout << "test5: " << test << endl;
//	cout << "test6: " << q2.dequeue() << endl;
//	cout << "test7: " << q2.empty() << endl;
//	cout << "test8: " << !q2.full() << endl;
//	if (q2.get_size() == 0)
//		test = 1;
//	else
//		test = 0;
//	cout << "test9: " << test << endl;
	
//	PriorityQueue q(3);
//	q.enqueue(PriorityQueue::TaskItem(5,"Test Task"));
//	bool test;
//	if (q.max().priority == 5)
//		test = 1;
//	else
//		test = 0;
//	cout << "test1: " << test << endl;
//	q.enqueue(PriorityQueue::TaskItem(3,"Test Task"));
//	if (q.max().priority == 5)
//		test = 1;
//	else
//		test = 0;
//	cout << "test2: " << test << endl;
//	q.enqueue(PriorityQueue::TaskItem(4,"Test Task"));
//	if (q.max().priority == 5)
//		test = 1;
//	else
//		test = 0;
//	cout << "test3: " << test << endl;
//	cout << "test4: " << q.full() << endl;
//
//	if (!q.enqueue(PriorityQueue::TaskItem(7,"Test Task")))
//		test = 1;
//	else
//		test = 0;
//	cout << "test5: " << test << endl;
//	
//	if (q.max().priority == 5)
//		test = 1;
//	else
//		test = 0;
//	cout << "test6: " << test << endl;
//	
//	if (q.full())
//		test = 1;
//	else
//		test = 0;
//	cout << "test7: " << test << endl;
//	
//	
//	PriorityQueue q(3);
//	q.enqueue(PriorityQueue::TaskItem(5,"Test Task"));
//	bool test;
//	if( q.max().priority == 5 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test1: " << test << endl;
//	
//	q.enqueue(PriorityQueue::TaskItem(3,"Test Task"));
//	if( q.max().priority == 5 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test2: " << test << endl;
//	
//	q.enqueue(PriorityQueue::TaskItem(4,"Test Task"));
//	if( q.max().priority == 5 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test3: " << test << endl;
//	if( q.full() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test4: " << test << endl;
//
//	if( !q.enqueue(PriorityQueue::TaskItem(7,"Test Task")) )
//		test = 1;
//	else
//		test = 0;
//	cout << "test5: " << test << endl;
//	if( q.max().priority == 5 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test6: " << test << endl;
//	if( q.full() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test7: " << test << endl;
//
//	cout << "test7-: " << q.dequeue() << endl;
//	
//	if( q.max().priority == 4 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test8: " << test << endl;
//	cout << "test8-: " << q.dequeue() << endl;
//	if( q.max().priority == 3 )
//		test = 1;
//	else
//		test = 0;
//	cout << "test9: " << test << endl;
//	q.dequeue();
//	if( q.empty() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test10: " << test << endl;
//	if( !q.full() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test11: " << test << endl;
//
//	if( !q.dequeue() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test12: " << test << endl;
//	if( q.empty() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test13: " << test << endl;
//	if( !q.full() )
//		test = 1;
//	else
//		test = 0;
//	cout << "test14: " << test << endl;


//int main()
//{
//	PriorityQueue queue1(6);
////	queue1.print();
////	cout << queue1.get_size() << endl;
////	cout << queue1.full() << endl;
//	
//	queue1.enqueue(PriorityQueue::TaskItem(4,"1st entered item"));
////	queue1.print();
//	
//	queue1.enqueue(PriorityQueue::TaskItem(112,"2nd entered item"));
////	queue1.print();
//	
//	queue1.enqueue(PriorityQueue::TaskItem(11,"3rd entered item"));
////	queue1.print();
//	
//	queue1.enqueue(PriorityQueue::TaskItem(300,"4th entered item"));
////	queue1.print();
//	
//	queue1.enqueue(PriorityQueue::TaskItem(50,"5th entered item"));
//	queue1.print();
//	
//	queue1.dequeue();
//	queue1.print();
//	
//	queue1.enqueue(PriorityQueue::TaskItem(11,"6th entered item"));
//	queue1.enqueue(PriorityQueue::TaskItem(12,"7th entered item"));
//	queue1.enqueue(PriorityQueue::TaskItem(60,"8th entered item"));
//	queue1.print();
//	
//	cout << queue1.full() << endl;
//	
//	return 0;
//}
