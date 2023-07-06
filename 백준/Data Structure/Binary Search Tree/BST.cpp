#include <iostream>
using namespace std;

typedef int Key;

typedef struct _BSTNode{
	Key key;
	struct _BSTNode * left_child;
	struct _BSTNode * right_child;
}BSTNode;

// Create a new node
BSTNode * CreateNode(Key key);
// Destroy a node
void DestroyNode(BSTNode* node);
// Connect the root to a left-side node
void CreateLeftSubtree(BSTNode* root, BSTNode* left);
// Connect the root to a right-side node
void CreateRightSubtree(BSTNode* root, BSTNode* right);

// Verify whether the tree is a binary search tree or not
bool Verify(BSTNode* root,int min, int max);
// Search an item in BST
BSTNode* Search(BSTNode* root, Key key);
// Insert an item to BST
void Insert(BSTNode* root, Key key);
// Remove an item from BST
void Remove(BSTNode* node, Key key);

// Traverse BST (the inorder traversal is a sorted list)
void Traverse(BSTNode* root);
// Clear a tree
void ClearTree(BSTNode* root);


int main(void){
	return 0;
}

// Create a new node
BSTNode * CreateNode(Key key){
	BSTNode* node = new BSTNode;
	node->key = key;
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}
// Destroy a node
void DestroyNode(BSTNode* node){
	delete node;
}
// Connect the root to a left-side node
void CreateLeftSubtree(BSTNode* root, BSTNode* left){
	if(root->left_child != NULL)
		return;
	root->left_child = left;
}
// Connect the root to a right-side node
void CreateRightSubtree(BSTNode* root, BSTNode* right){
	if(root->right_child != NULL)
		return;
	root->right_child = right;
}

// Initialize the minimum and maximum as INT_MIN and INT_MAX
bool Verify(BSTNode* root,int min, int max){
	if(root != NULL){
		// Return false if this node violates the min/max constraints.
		if(root->key < min || root->key > max)
			return false;
		// Check the subtrees with the min/max constrains.
		return Verify(root->left_child,min,root->key) && Verify(root->right_child,root->key,max);
	}
	else
		return true; // an empty tree is BST.
}

// Search an item in BST
BSTNode* Search(BSTNode* root, Key key){
	if(root == NULL || root->key == key)
		return root;
	else if(root->key < key)
		Search(root->right_child,key);
	else
		Search(root->left_child,key);
}
// Insert an item to BST
void Insert(BSTNode* root, Key key){
	if(root->key == key)
		return;
	if(root->key > key){
		// Insert a new node for a left child
		if(root->left_child == NULL)
			CreateLeftSubtree(root,CreateNode(key));
		else
			Insert(root->left_child,key);
	}else{
		// Insert a new node for a right child
		if(root->right_child == NULL)
			CreateRightSubtree(root,CreateNode(key));
		else
			Insert(root->right_child,key);
	}
}

// Remove an item from BST
void Remove(BSTNode* root, Key key){
	BSTNode* cur = root, *parent = NULL;

	// Find the current node and its parent node.
	while(cur != NULL && cur->key != key){
		parent = cur; // Update the parent node.
		if(cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}

	if(cur == NULL)
		return;

	if(cur->left_child == NULL && cur->right_child == NULL){
		if(parent != NULL){
			if(cur == parent->left_child)
				parent->left_child = NULL;
			else
				parent->right_child = NULL;

		}else // The current node is the root
			cur = NULL;
		DestroyNode(cur);
	}else if(cur->left_child == NULL || cur->right_child == NULL){
		BSTNode* child;
		// Replace a node with its child node
		if(cur->left_child == NULL)
			child = cur->right_child;
		else
			child = cur->left_child;

		// Replace the child node of its parent node
		if(parent != NULL){
			if(parent->left_child == cur)
				parent->left_child = child;
			else
				parent->right_child = child;
		}
		DestroyNode(cur);
	}else{
		BSTNode* succ_parent = cur, *succ = cur->right_child;
		// Find the successor (left-most node of the current node)
		while(succ->left_child != NULL){
			succ_parent = succ;
			succ = succ->left_child;
		}

		// If the successor has a child, update its child node
		if(succ_parent->left_child == succ)
			succ_parent->left_child = succ->right_child;
		else
			succ_parent->right_child = succ->right_child;

		cur->key = succ->key;
		cur = succ;
	}
}

// Traverse BST (the inorder traversal is a sorted list)
void Traverse(BSTNode* root){
	if(root != NULL){
		Traverse(root->left_child);
		cout << root->key << ' ';
		Traverse(root->right_child);
	}
}
// Clear a tree
void ClearTree(BSTNode* root){

}