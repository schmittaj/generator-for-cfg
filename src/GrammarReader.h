#ifndef GRAMMARREADER_H
#define GRAMMARREADER_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "DList.cc"
#include "RuleSet.h"
#include "Grammar.h"
#include "Symbol.h"

using namespace std;

class GrammarReader
{
  protected:
    string filename;
    Grammar gram;

  public:
    GrammarReader();
    GrammarReader(string);
    ~GrammarReader();
    //void readFile();
	void altReadFile();
	Symbol parseSymbol(string);
    void setFile(string);
    Grammar giveGrammar();
};

#endif
