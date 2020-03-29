#include <iostream>
#include <queue>
#include "lab3_binary_search_tree.hpp"

using namespace std;

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
	while (curr && cur->left) //until find nodes that has NULL on left
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

// PURPOSE: Prints the contents of the tree; format not specified [1]
void BinarySearchTree::print() const {
	
	print_content(root, 0); //calls helper function	
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
	while(cur)
	{
		if (cur->priority == val->priority)
			return true;
		
		//move left if val's priority is smaller than cur's priority
		if (val->priority < cur->priority)
			cur = cur->left;
		//move right if val's priority is greater than cur's priority
		else
			cur = cur->right;
	}
	
	return false;
	
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
	
	//check if node exists in tree
	if (!n->priority.exists())
		return;
	
	//find node and return depth value
	BinarySearchTree::TaskItem* cur = root;
	int depth = 0;
	
	while(cur)
	{
		if (cur->priority == n->priority)
			return depth;
		
		//move left if val's priority is smaller than cur's priority
		if (val->priority < cur->priority)
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
	
	*cur = new BinarySearchTree::TaskItem(val->priority, val->description); //add new node to tree
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
	
	
	
	//case 0
	if (!exists(val))
		return false;
	//case 0.1.
	if (root->left == NULL && root->right == NULL && root->priority == val->priority)
	{
		delete root;
		root = NULL;
		
		return true;
	}
	
	BinarySearchTree::TaskItem* parent = NULL;
	BinarySearchTree::TaskItem* cur = root;
	while(cur->priority != val->priority) //iterate through tree until find desired node
	{
		parent = cur;
		
		//move left if val's priority is smaller than cur's priority
		if (val->priority < cur->priority)
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
		else if (parent->left == cur)
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
		while (successor_node && successor_node->left != NULL)
			successor_node = successor_node->left;
		
		//case 3.1: left of parent
		if (parent->left == cur)
			parent->left = successor_node;
		
		//case 3.2: right of parent
		else (parent->right == cur)
			parent->right = successor_node;
		
		//assign successor_node w/ cur's children
		successor_node->right = cur->right;
		successor_node->left = cur->left;
		
		//remove cur
		delete cur;
		cur = NULL;
		
		return true;
	}
	
    return false;
}

// PURPOSE: Recursive function to help destructor remove all nodes
void clean_up(BinarySearchTree::TaskItem* task_item)
{
	if (task_item == NULL)
		return;
	clean_up(task_item->left);
	clean_up(task_item->right);
	delete task_item;
}

// PURPOSE: This function does the actual printing (helper function for print function) [1]
void print_content(BinarySearchTree::TaskItem *root_item, int space)
{
	const int count = 10;
	
	//base case
	if (root_item == NULL)
		return;
	
	//increase distance between levels
	space += count;
	
	//process right child first
	print_content(root->right, space);
	
	//print current node after space
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << root_item->priority << endl;
	
	//process left child
	print_content(root->left, space);	
}

