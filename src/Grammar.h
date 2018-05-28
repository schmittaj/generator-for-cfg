#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <cstdlib>
#include <iostream>
#include "RuleSet.h"
#include "DList.h"

using namespace std;

class Grammar
{
  protected:
    DList<RuleSet> rules;
    DList<Symbol> symbols;
 
  public:
    Grammar();
    Grammar(const Grammar &);
    ~Grammar();
    Grammar& operator = (const Grammar &);
    void addRuleSet(RuleSet);
    DList<Symbol> doProduction(Symbol);
    friend ostream& operator <<(ostream& os , const Grammar& gram);
};

#endif
