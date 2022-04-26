#include "node.h"
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
  char option[20];
  int spaceCount = 0;
  int tokenCount = 0;
  int filelength;
  char* bufferFile;
  int* numberArray;
  node* Tree = NULL;

  
  cout << "Type CONSOLE or FILE" << endl;
  cin.get(option, 20);
  cin.get();

  if (strcmp(option, "FILE") == 0)
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
      cout << "line 62" << endl;
      for (int i = 0; i < tokenCount; i++)
	{
	  insert(Tree, Tree, Tree, numberArray[i]);
	}

      print(Tree);
      cout << endl;
      visualize(Tree, 0);
    }
  
  else if (strcmp(option, "CONSOLE") == 0)
    {	
      int numInput = 0;
      cout << "Enter a number" << endl;
      cin >> numInput;
      cin.get();
      
      insert(Tree, Tree, Tree, numInput);
      print(Tree);
      visualize(Tree, 0);
    }
  
}
