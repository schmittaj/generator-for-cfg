#ifndef RULESET_CC
#define RULESET_CC

#include "RuleSet.h"

/*
    Symbol productionSymbol
    DList<DList<Symbol>> productions
*/

RuleSet::RuleSet()
{
}

RuleSet::RuleSet(Symbol symb)
{
  productionSymbol = symb;
}

RuleSet::RuleSet(const RuleSet& rul)
{
  productionSymbol = rul.productionSymbol;
  productions = rul.productions;
}

RuleSet::~RuleSet()
{
}

RuleSet& RuleSet::operator = (const RuleSet& rul)
{
  productionSymbol = rul.productionSymbol;
  productions = rul.productions;
  return(*this);
}

bool RuleSet::operator == (const RuleSet& rul)
{
  return( productionSymbol == rul.productionSymbol );
}

void RuleSet::addProduction(DList<Symbol> prod)
{
  productions.addToTail(prod);
}

unsigned RuleSet::numOfProductions()
{
  return(productions.getSize());
}

unsigned RuleSet::numOfProductions() const
{
  return(productions.getSize());
}

DList<Symbol> RuleSet::getProduction(unsigned prod)
{
  DList<Symbol> output;
  if(prod < numOfProductions())
  {
    output = productions.getAt(prod);
  }
  return(output);
}

void RuleSet::setProductionSymbol(const RuleSet& rul)
{
  productionSymbol = rul.productionSymbol;
  productions = rul.productions;
}

void RuleSet::setProductionSymbol(Symbol sym)
{
	productionSymbol = sym;
}

Symbol RuleSet::getProductionSymbol()
{
  return(productionSymbol);
}

ostream& RuleSet::display(ostream& os) const
{
  os << endl << productionSymbol << "  has " << productions.getSize() << " productions." << endl;
  os << productions;
  os << endl;
  return(os);
}

ostream& operator <<(ostream& os , const RuleSet& rul)
{
  rul.display(os);
  return(os);
}

#endif
