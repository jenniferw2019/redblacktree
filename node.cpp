#include "node.h"
#include <iostream>

using namespace std;

void insert(node* &root, node* parent, node* current, int value)
{
  if (root == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      newNode->color = red;
      root = newNode;
      root->parent = NULL;
      root->left = NULL;
      root->right = NULL;
    }
  else if (current == NULL)
    {
      node* newNode = new node();
      newNode->data = value;
      newNode->color = red;
      newNode->left = NULL;
      newNode->right = NULL;
      current = newNode;
      if (value < parent->data)
	{
	  parent->left = current;
	  current->parent = parent;
	}
      if (value > parent->data)
	{
	  parent->right = current;
	  current->parent = parent;
	}
      
    }
  else
    {
      parent = current;
      if (current->data > value)
	{
	  current = current->left;
	}
      else if (current->data < value)
	{
	  current = current->right;
	}
      insert(root, parent, current, value);
    }
}

void print(node* root)
{
  if (root != NULL)
    {
      print(root->left);
      cout << root->data << " ";
      print(root->right);
    }
}

void visualize(node* root, int level)
{
  if (root != NULL)
    {
      visualize(root->right, level + 1);
      for (int i = 0; i < level; i++)
	{
	  cout << '\t';
	}
      cout << root->data;
      if (root->color == black)
	{
	  cout << "(B)";
	}
      else
	{
	  cout << "(R)";
	}
      cout << "|";
      if (root->parent != NULL)
	{
	  cout << (root->parent)->data << endl;
	}
      else
	{
	  cout << endl;
	}
      visualize(root->left, level + 1);
    }
}

node* search(node* root, node* parent, node* current, int searchNum)
{
  if (current == NULL)
    {
      return NULL;
    }
  else if (current->data == searchNum)
    {
      return current;
    }
  else
    {
      parent = current;
      if (parent->data < searchNum)
	{
	  current = current->right;
	}
      else
	{
	  current = current->left;
	}
      return search(root, parent, current, searchNum);
    }
}

node* getParent(node* root, node* current, node* previous, node* lookParent)
{
  if (root == lookParent)
    {
      return NULL;
    }
  else if (current == lookParent)
    {
      return previous;
    }
  else
    {
      previous = current;
      if(previous->data < lookParent->data)
	{
	  current = current->right;
	}
      else
	{
	  current = current->left;
	}
      return getParent(root, current, previous, lookParent);
    }
}

void treeRotationRight(node* &root, node* subRoot)
{
  node* rootParent = subRoot->parent;
  node* leftChild = subRoot->left;
  node* grandChild;
  if (leftChild != NULL)
    {
      grandChild = leftChild->right;
    }
  subRoot->left = grandChild;
  if (grandChild != NULL)
    {
      grandChild->parent = subRoot;
    }

  leftChild->right = subRoot;
  subRoot->parent = leftChild;

  if (rootParent != NULL)
    {
      if (rootParent->right == subRoot)
	{
	  rootParent->right = leftChild;
	}
      else
	{
	  rootParent->left = leftChild;
	  leftChild->parent = rootParent;
	}
    }
  else
    {
      root = leftChild;
      root->parent = NULL;
    }
}

void treeRotationLeft(node* &root, node* subRoot)
{
  node* rootParent = subRoot->parent;
  node* rightChild = subRoot->right;
  node* grandChild;
  if (rightChild != NULL)
    {
      grandChild = rightChild->left;
    }
  subRoot->right = grandChild;
  if (grandChild != NULL)
    {
      grandChild->parent = subRoot;
    }

  rightChild->left = subRoot;
  subRoot->parent = rightChild;

  if (rootParent != NULL)
    {
      if (rootParent->left == subRoot)
	{
	  rootParent->left = rightChild;
	}
      else
	{
	  rootParent->right = rightChild;
	  rightChild->parent = rootParent;
	}
    }
  else
    {
      root = rightChild;
      root->parent = NULL;
    }
}

void updateTree(node* &root, node* n)
{
  node* parent;
  node* grandParent;
  node* uncle;
  node* child;

  if (n == root)
    {
      n->color = black;
    }
  else // n!= root
    {
      do {
	parent = n->parent;
	if (parent->color == black) // case 1: parent color is black
	  {
	    return;
	  }
	else //parent color == red
	  {
	    grandParent = parent->parent;
	    if (grandParent == NULL) // case 2: parent is red root
	      {
		parent->color = black;
		return;
	      }
	    else //grandparent != NULL
	      {
		if (parent == grandParent->left)
		  {
		    uncle = grandParent->right;
		  }
		else
		  {
		    uncle = grandParent->left;
		  }
		if (parent->color == red || uncle->color == red) // case 3: parent and uncle are red
		  {
		    parent->color = black;
		    uncle->color = black;
		    grandParent->color = red;
		    n = grandParent;
		    parent = n->parent;
		  }
	      }//grandparent != NULL
	    
	  } //parent color == red
	
      } while (parent != NULL);

      root->color = black;
    } // n!= root
}
