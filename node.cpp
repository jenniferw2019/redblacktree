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
      cout << root->data << "(" << root->color << ")" << "/";
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
