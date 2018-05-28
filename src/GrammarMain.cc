#ifndef GRAMMARMAIN_CC
#define GRAMMARMAIN_CC

#include <iostream>
#include <string>
#include "GrammarReader.h"
#include "Grammar.h"
#include "Stack.cc"
#include "Symbol.h"
#include "DList.cc"

using namespace std;

int main(int argc, char** argv)
{
  Stack<Symbol> pushDownAtomata(100);
  Symbol start("start", false);
  pushDownAtomata.push(start);
  string filename;
  if(argc == 1)
  {
    cout << "Enter the file name for the grammar:" << endl;
    cin >> filename;
  }
  else
  {
	string arg = argv[1];
	if(arg.compare("-f") == 0)
	{
	  filename = argv[2];
	}
	else if(arg.compare("-h") == 0 || arg.compare("-help") == 0 || arg.compare("help") == 0)
	{
	  cout << "Usage: grammar [options]" << endl ;
	  cout << "Options:" << endl;
	  cout << "-f FILE\t\t\tRead FILE as Grammar." << endl;
	  cout << "-h, -help, help\t\tPrint this message and exit." << endl;
	  return(0);
    }
  }
  GrammarReader read(filename);
  read.altReadFile();
  Grammar gram = read.giveGrammar();
  cout << endl << endl;
  while( !pushDownAtomata.isEmpty() )
  {
    if( pushDownAtomata.top().isTerminal() )
    {
      cout << pushDownAtomata.top();
      pushDownAtomata.pop();
    }
    else
    {
      DList<Symbol> temp = gram.doProduction(pushDownAtomata.top());
      pushDownAtomata.pop();
      while(!temp.isEmpty())
      {
		pushDownAtomata.push(temp.getAt(0));
        temp.removeHead();
      }
    }
  }
cout << endl << endl;
  return(0);
}

#endif
