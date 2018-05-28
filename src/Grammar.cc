#ifndef GRAMMAR_CC
#define GRAMMAR_CC

#include "Grammar.h"

/*
    DList<RuleSet> rules;
    DList<Symbols> symbols;
*/

Grammar::Grammar()
{
  srand(time(NULL));
}

Grammar::Grammar(const Grammar & gram)
{
  srand(time(NULL));
  rules = gram.rules;
  symbols = gram.symbols;
}

Grammar::~Grammar()
{
}

Grammar& Grammar::operator = (const Grammar & gram)
{
  rules = gram.rules;
  symbols = gram.symbols;
  return(*this);  
}

void Grammar::addRuleSet(RuleSet set)
{
  rules.addToTail(set);
  symbols.addToTail(set.getProductionSymbol());
}

DList<Symbol> Grammar::doProduction(Symbol prodSymb)
{
  int index = symbols.find(prodSymb);
  int randomNumber = rand();
  int prodAmt = rules.getAt(index).numOfProductions();
  int randd = randomNumber % prodAmt;
  return(rules.getAt(index).getProduction(randd));
}

ostream& operator <<(ostream& os , const Grammar& gram)
{
  os << gram.rules << endl;
  return(os);
}

#endif
