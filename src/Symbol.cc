#ifndef SYMBOL_CC
#define SYMBOL_CC

#include "Symbol.h"

/*
      string symb;      
      bool terminal;
*/

Symbol::Symbol()
{
}

Symbol::Symbol(string in, bool term)
{
  symb = in;
  terminal = term;
}

Symbol::Symbol(const Symbol& sym)
{
  symb = sym.symb;
  terminal = sym.terminal;
}

Symbol::~Symbol()
{
}

bool Symbol::operator ==(const Symbol& sym)
{
  return( symb == sym.symb );
}

bool Symbol::operator !=(const Symbol& sym)
{
  return( symb != sym.symb );
}

Symbol& Symbol::operator = (const Symbol& sym)
{
  symb = sym.symb;
  terminal = sym.terminal;
  return(*this);
}

string Symbol::getSymbol()
{
  return(symb);
}

bool Symbol::isTerminal()
{
  return(terminal);
}

ostream& Symbol::display(ostream& os) const
{
  os << symb << " ";
  return(os);
}

ostream& operator << (ostream& os, const Symbol& sym)
{
  sym.display(os);
  return(os);
}

#endif
