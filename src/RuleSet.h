#ifndef RULESET_H
#define RULESET_H

#include <iostream>
#include "Symbol.h"
#include "DList.cc"

using namespace std;

class RuleSet
{
  protected:
    Symbol productionSymbol;
    DList< DList<Symbol> > productions;

  public:
    RuleSet();
    RuleSet(Symbol);  //give the production symbol
    RuleSet(const RuleSet&);
    ~RuleSet();
    RuleSet& operator = (const RuleSet&);
    bool operator == (const RuleSet&);
    void addProduction(DList<Symbol>);
    ostream& display(ostream&) const;
    unsigned numOfProductions();
    unsigned numOfProductions() const;
	void setProductionSymbol(const RuleSet&);
	void setProductionSymbol(Symbol);
    DList<Symbol> getProduction(unsigned);
    Symbol getProductionSymbol();
    friend ostream& operator <<(ostream& os , const RuleSet&);
};

#endif
