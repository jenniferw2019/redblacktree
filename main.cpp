#include "node.h"
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
  bool runProgram = true;
  char option[20];
  int spaceCount = 0;
  int tokenCount = 0;
  int filelength;
  char* bufferFile;
  int* numberArray;
  node* Tree = NULL;

  while (runProgram == true)
    {
      cout << "Type ADD, READ, VISUALIZE, QUIT" << endl;
      cin.get(option, 20);
      cin.get();
      
      if (strcmp(option, "READ") == 0)
	{
	  ifstream file ("file.txt", ifstream::in);
	  if (file)
	    {
	      file.seekg(0, file.end);
	      filelength = file.tellg();
	      file.seekg(0, file.beg);
	      
	      bufferFile = new char[filelength];
	      file.read(bufferFile, filelength);
	      
	      file.close();
	    }
	  else
	    {
	      cout << "no such file named file.txt" << endl;
	    }
	  
	  for (int i = 0; i < filelength; i++)
	    {
	      if (bufferFile[i] == ' ')
		{
		  spaceCount++;
		}
	      tokenCount = spaceCount + 1;
	    }
	  int a = 0;
	  numberArray = new int[tokenCount];
	  char* token;
	  token = strtok(bufferFile, " ");
	  while (token != NULL)
	    {
	      numberArray[a] = atoi(token);
	      token = strtok(NULL, " ");
	      a = a + 1;
	    }
	  for (int i = 0; i < tokenCount; i++)
	    {
	      insert(Tree, Tree, Tree, numberArray[i]);
	      node* searchNode;
	      searchNode = search(Tree, Tree, Tree, numberArray[i]);
	      updateTree(Tree, searchNode);
	    }
	  
	  //print(Tree);
	  //cout << endl;
	  //visualize(Tree, 0);
	}
      
      else if (strcmp(option, "ADD") == 0)
	{	
	  int numInput = 0;
	  cout << "Enter a number" << endl;
	  cin >> numInput;
	  cin.get();
	  
	  insert(Tree, Tree, Tree, numInput);
	  //print(Tree);
	  //visualize(Tree, 0);
	  node* searchNode;
	  searchNode = search(Tree, Tree, Tree, numInput);
	  updateTree(Tree, searchNode);
	}
      else if (strcmp(option, "VISUALIZE") == 0)
	{
	  visualize(Tree, 0);
	}
      /*
      else if (strcmp(option, "ROTATE") == 0)
	{
	  int searchNumber = 0;
	  node* result;
	  node* parent;
	  cout << "Type a number to rotate" << endl;
	  cin >> searchNumber;
	  cin.get();

	  result = search(Tree, Tree, Tree, searchNumber);
	  
	  if (result != NULL)
	    {
	      
	      cout << "number is in tree" << endl;
	      parent = getParent(Tree, Tree, Tree, result);
	      if (parent != NULL)
		{
		  cout << parent->data << endl;
		}
	    }
	  else
	    {
	      cout << "number is not in tree" << endl;
	    }
	}
      */
      else if (strcmp(option, "QUIT") == 0)
	{
	  runProgram = false;
	}
    }
  
}
