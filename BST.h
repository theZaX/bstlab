#pragma once
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
public:
	BST() { root = NULL; }
	virtual ~BST()
	{
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface *getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	void replace(Node *&old_root, Node *&local_root);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	bool remove(Node *&local_root, int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

private:
	bool add(int data, Node *&node);
	void recursiveClear(Node *node);

protected:
	Node *root;
};
