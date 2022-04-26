#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

enum nodeColor {black, red};

struct node
{
  int data;
  nodeColor color;
  node* parent;
  node* left;
  node* right;
  
};

void insert(node* &root, node* parent, node* current, int value);
void print(node* root);
void visualize(node* root, int level);

#endif
