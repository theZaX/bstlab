#include "BST.h"
/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
NodeInterface *BST::getRootNode() const
{
	cout << "getRootNode" << endl;
	return this->root;
}

/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
bool BST::add(int data)
{
	cout << "add" << endl;
	return add(data, this->root);
}

bool BST::add(int data, Node *&node)
{
	if (node == NULL)
	{
		node = new Node(data);
		return true;
	}
	else if (node->getData() == data)
	{
		return false;
	}
	else if (data < node->getData())
	{
		return add(data, node->getLeft());
	}
	else
	{
		return add(data, node->getRight());
	}
}

/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
bool BST::remove(int data)
{

	cout << "remove" << endl;

	return remove(this->root, data);
}

bool BST::remove(Node *&local_root, int data)

{
	if (local_root == NULL)
	{
		return false;
	}

	if (data < local_root->getData())
	{
		return remove(local_root->getLeft(), data);
	}
	else if (data > local_root->getData())
	{
		return remove(local_root->getRight(), data);
	}
	else
	{
		cout << "passed checks" << endl;

		Node *old_root = local_root;
		if (local_root->getLeft() == NULL)
		{
			local_root = local_root->getRight();
			delete old_root;
		}
		else if (local_root->getRight() == NULL)
		{
			local_root = local_root->getLeft();
			delete old_root;
		}
		else
		{
			replace(old_root, local_root->getLeft());
		}
		return true;
	}
}

void BST::replace(Node *&old_root, Node *&local_root)
{
	if (local_root->getRight() != NULL)
	{
		replace(old_root, local_root->getRight());
	}
	else
	{
		cout << "in the recursive case" << local_root->getData();

		old_root->setData(local_root->getData());
		remove(old_root->getLeft(), local_root->getData());
	}
}

/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
void BST::clear()
{
	cout << "clear" << endl;
	recursiveClear(this->root);
	root = NULL;
}

void BST::recursiveClear(Node *node)
{

	if (node != NULL)
	{
		recursiveClear(node->getLeft());
		recursiveClear(node->getRight());
		delete node;
	}
}