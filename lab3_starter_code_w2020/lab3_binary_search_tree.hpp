//[1] GeeksforGeeks, "Print Binary Tree in 2-Dimensions," [Online]. Available: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/.
//[2] GeeksforGeeks, "Iterative Method to find height of Binary Tree," [Online]. Available: https://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree/.

#ifndef LAB3_BINARY_SEARCH_TREE_HPP
#define LAB3_BINARY_SEARCH_TREE_HPP

#include <string>
#include <queue>
#include <iostream>

using namespace std;

// PURPOSE: Models a Binary Search Tree of Task Items
class BinarySearchTree {
protected:
	// PURPOSE: Models a single Task Item as a Tree Node
	struct TaskItem {
		int priority; // normal values are greater than zero
		string description; // task description
		TaskItem(int new_priority, string new_desc) : 
			priority(new_priority), description(new_desc), left(NULL), right(NULL) {}
	    TaskItem* left;    // pointer to the left node
    	TaskItem* right;   // pointer to the right node
    	bool operator==(const TaskItem& rhs) {
			bool are_equal = priority == rhs.priority;
			return are_equal && description == rhs.description;
		}
	};
	
	friend class BinarySearchTreeTest;

	// pointer to the root node of the tree	
	TaskItem* root;
  
	// number of nodes in the tree
	unsigned int size;

public:
	// CONSTRUCTOR AND DESTRUCTOR

	// PURPOSE: Default/empty constructor
	 BinarySearchTree();

	// PURPOSE: Explicit destructor of the class BinarySearchTree
	~BinarySearchTree();

  	// ACCESSORS  
	// PURPOSE: Returns the number of nodes in the tree
  	unsigned int get_size() const;
  
	// PURPOSE: Returns the maximum value of a node in the tree
  	// if the tree is empty, it returns (-1, "N/A")
  	TaskItem max() const;

	// PURPOSE: Returns the minimum value of a node in the tree
  	// if the tree is empty, it returns (-1, "N/A")
	TaskItem min() const;
	
	// PURPOSE: Returns the tree height
	unsigned int height() const;
	
	// PURPOSE: Prints the contents of the tree; format not specified [1]
	void print() const;
	
	// PURPOSE: Returns true if a node with the value val exists in the tree	
	// otherwise, returns false
	bool exists(TaskItem val) const;
  
  	// PURPOSE: Optional helper function that returns a pointer to the root node
	TaskItem* get_root_node();

	// PURPOSE: Optional helper function that returns the root node pointer address
	TaskItem** get_root_node_address();
  
  	// PURPOSE: Optional helper function that gets the maximum depth for a given node
	int get_node_depth(TaskItem* n) const;
  
  	// MUTATORS
  
	// PURPOSE: Inserts the value val into the tree if it is unique
  	// returns true if successful; returns false if val already exists
	bool insert(TaskItem val);
	
	// PURPOSE: Removes the node with the value val from the tree
	// returns true if successful; returns false otherwise
	bool remove(TaskItem val);
	
	// HELPER FUNCTIONS
	
	// PURPOSE: Recursive function to help destructor remove all nodes
	void clean_up(TaskItem* task_item);
	
	// PURPOSE: Prints out post-order tree
	bool pre_order(TaskItem* node);
	
	// PURPOSE: Prints out in-order tree
	bool in_order(TaskItem* node);
};



//-------------------------------------------------------------------------------------------------
// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
	root = NULL;
	root = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {
	clean_up(root);	
	root = NULL;
	size = 0;	
}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {	
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	
	//Logic:
	//1. traverse to right child of root node if right child exists
	//2. at current node:
	// 2.1. if right child exists, travel to the right child
	// 2.2. if right child doesn't exist, then current node is the node w/ highest key value
	
	
	//base case: empty tree
	if (size == 0)
		return BinarySearchTree::TaskItem(-1, "N/A");
	
	//general case: non-empty tree
	BinarySearchTree::TaskItem* cur = root;
	while (cur && cur->right) //until find nodes that has NULL on right
	{
		cur = cur->right; //iterate through tree
	}
	
	return BinarySearchTree::TaskItem(cur->priority, cur->description); //return found max val	
	
	
	//returns max priority since this is max heap. so return top (root node)
	//return BinarySearchTree::TaskItem(-1, "N/A");
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	
	
	//Logic:
	//1. traverse to left child of root node if left child exists
	//2. at current node:
	// 2.1. if left child exists, travel to the left child
	// 2.2. if left child doesn't exist, then current node is the node w/ lowest key value
	
	
	//base case: empty tree
	if (size == 0)
		return BinarySearchTree::TaskItem(-1, "N/A");
		
	//general case: non-empty tree
	BinarySearchTree::TaskItem* cur = root;
	while (cur && cur->left) //until find nodes that has NULL on left
	{
		cur = cur->left; //iterate through tree
	}
	
	return BinarySearchTree::TaskItem(cur->priority, cur->description); //return found min val
	
	
	//return BinarySearchTree::TaskItem(-1, "N/A");
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
	
	//base case: empty tree
	if (root == NULL) //or size == 0
		return 0;
	
	//general case: non-empty tree
	else
	{
		//create empty queue for level order traversal
		queue<BinarySearchTree::TaskItem *> q;
		
		//enqueue root and initialize height
		q.push(root);
		unsigned int height = 0;
		
		while (1)
		{
			//number of nodes at current level
			int nodeCount = q.size();
			
			//if number of nodes at this level is 0
			if (nodeCount == 0)
				return height;
			
			//increase height
			height++;
			
			//dequeue all nodes of current level & enqueue all nodes of nxt level
			while (nodeCount > 0)
			{
				BinarySearchTree::TaskItem* node = q.front();
				q.pop();
				
				//push its children to queue
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
					
				nodeCount--;
				
				//at this point, queue has nodes of next level
			}
		}
	}
	
	return 0;
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
		
	//print pre-order content
	cout << "pre-order:" << endl;
	bool test = pre_order(root);
	cout << endl;
	
	//print in-order content
	cout << "in-order:" << endl;
	test = in_order(root);
	cout << endl;
}

// PURPOSE: Returns true if a node with the value val exists in the tree	
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	
	
	//Logic: *note: similar to search function
	//1. set root node as current node to visit
	//2. compare desired key value K w/ key value of current node Kc
	//3. if K < Kc, then continue search in the left subtree of the current node
	//4. if K > Kc, then continue search in the right subtree of the current node
	//5. if K = Kc, then return current node and stop searching
	//6. if current node is empty, serach has failed and so we stop searching
	
	
	BinarySearchTree::TaskItem* cur = root;
	BinarySearchTree::TaskItem* new_val = new BinarySearchTree::TaskItem(val);
	while(cur)
	{
		if (cur->priority == new_val->priority)
			return true;
		
		//move left if val's priority is smaller than cur's priority
		if (new_val->priority < cur->priority)
			cur = cur->left;
		//move right if val's priority is greater than cur's priority
		else
			cur = cur->right;
	}
	
	return false;
	
	
	/* //alternative method?
	bool exists(int key) {
		return exists(root, key);
	}
	*/
	
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return root;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return &root;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node [2]
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	
	BinarySearchTree::TaskItem* new_val = new BinarySearchTree::TaskItem(*n);
	
	//find node and return depth value
	BinarySearchTree::TaskItem* cur = root;
	int depth = 0;
	
	while(cur)
	{
		if (cur->priority == new_val->priority)
			return depth;
		
		//move left if val's priority is smaller than cur's priority
		if (new_val->priority < cur->priority)
			cur = cur->left;
		//move right if val's priority is greater than cur's priority
		else
			cur = cur->right;
			
		depth++;
	}
	
	return 0;
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
	
	//Logic:
	//1. set root node as the current node to visit
	//2. compare the key value of the new node K w/ key value of current node Kc
	//3. if K < Kc, then continue performing the insert operation on the left subtree
	//4. if K > Kc, then continue performing the insert operation on the left subtree
	//5. if current node is actually empty, insert node at current location and stop searching
	
	
	BinarySearchTree::TaskItem** cur = &root; //set cur to point to address of root
	while(*cur)
	{
		//check for duplicates
		if ((*cur)->priority == val.priority)
			return false;
		
		//move left if priority of val is smaller than cur's
		if (val.priority < (*cur)->priority)
			cur = &((*cur)->left); //points to location where *cur's left pointer is stored
		//move right if priority of val is greater than cur's
		else
			cur = &((*cur)->right); //points to location where *cur's right pointer is stored
	}
	BinarySearchTree::TaskItem* new_val = new BinarySearchTree::TaskItem(val);
	*cur = new BinarySearchTree::TaskItem(new_val->priority, new_val->description); //add new node to tree
	++size; //iterate size
	
	return true;
	
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
	
	//Logic:
	
	//case 0: doesn't exist in tree (base case)
	//1. return false
	
	//case 0.1.: there's only one node in tree (root node) (base case 2)
	//1. delete root node
	
	//case 1: node is leaf node
	//1. delete node
	
	//case 2: node has 1 child
	//1. create a temp pointer to the node being deleted
	//2. link the parent node to the child node
	//3. delete the node pointed to by the temporary pointer
	
	//case 3: node has 2 child
	//Option 1
	//1. replace current node C w/ node w/ smallest key value D from C's right sub-tree
	//2. delete node used for C's replacement
	//Option 2
	//1. replace current node C w/ node w/ largest key value D from C's left sub-tree
	//2. delete node used for C's replacement
	
	BinarySearchTree::TaskItem* new_val = new BinarySearchTree::TaskItem(val);
	
	
	//case 0.1.
	if (root->left == NULL && root->right == NULL && root->priority == new_val->priority)
	{
		delete root;
		root = NULL;
		
		return true;
	}
	
	BinarySearchTree::TaskItem* parent = NULL;
	BinarySearchTree::TaskItem* cur = root;
	while(cur->priority != new_val->priority) //iterate through tree until find desired node
	{
		parent = cur;
		
		//move left if val's priority is smaller than cur's priority
		if (new_val->priority < cur->priority)
			cur = cur->left;
		//move right if val's priority is greater than cur's priority
		else
			cur = cur->right;
	}
	
	//case 1
	if (cur->left == NULL && cur->right == NULL)
	{
		//case 1.1: left of parent
		if (parent->left == cur)
			parent->left = NULL;
		//case 1.2: right of parent
		else if (cur->right == cur)
			parent->right = NULL;
		
		//remove cur
		delete cur;
		cur = NULL;
		
		return true;
	}
	
	//case 2
	else if ((cur->left != NULL && cur->right == NULL) || (cur->right != NULL && cur->left == NULL))
	{
		//case 2.1: left of parent
		if (parent->left == cur)
		{
			//left of cur
			if (cur->left != NULL && cur->right == NULL)
				parent->left = cur->left;
			//right of cur
			else if (cur->right != NULL && cur->left == NULL)
				parent->left = cur->right;
		}
		
		//case 2.2: right of parent
		else if (parent->right == cur)
		{
			//left of cur
			if (cur->left != NULL && cur->right == NULL)
				parent->right = cur->left;
			//right of cur
			else if (cur->right != NULL && cur->left == NULL)
				parent->right = cur->right;
		}
		
		//remove cur
		delete cur;
		cur = NULL;
		
		return true;
	}

	//case 3
	else
	{
		//find cur's successor node to swap (smallest in right subtree)
		BinarySearchTree::TaskItem* successor_node = cur->right;
		while (successor_node->left != NULL)
			successor_node = successor_node->left;
		
		//case 3.1: left of parent
		if (parent->left == cur){
			parent->left = successor_node;
		}			
		
		//case 3.2: right of parent
		else if (parent->right == cur){
			parent->right = successor_node;
		}			
		
		//assign successor_node w/ cur's children
		successor_node->right = cur->right;
		successor_node->left = cur->left;
		
		//remove cur
		delete cur;
		cur = NULL;
		
		return true;
	}
	
    return false; //case0: if node doesn't exist
}

// PURPOSE: Recursive function to help destructor remove all nodes
void BinarySearchTree::clean_up(BinarySearchTree::TaskItem* task_item)
{
	if (task_item == NULL)
		return;
	clean_up(task_item->left);
	clean_up(task_item->right);
	delete task_item;
}

// PURPOSE: Prints out post-order tree
bool BinarySearchTree::pre_order(BinarySearchTree::TaskItem* node)
{
	if (node == NULL)
		return 0;
	cout << node->priority << " ";
	bool test = 1;
	test = pre_order(node->left);
	test = pre_order(node->right);
}

// PURPOSE: Prints out in-order tree
bool BinarySearchTree::in_order(BinarySearchTree::TaskItem* node)
{
	if (node == NULL)
		return 0;
	bool test = 1;
	test = pre_order(node->left);
	test = pre_order(node->right);
	cout << node->priority << " ";
}



#endif
