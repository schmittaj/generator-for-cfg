#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <iostream>

using namespace std;

class Symbol
{
  protected:
    string symb;
    bool terminal;

  public:
    Symbol();
    Symbol(string, bool);
    Symbol(const Symbol&);
    virtual ~Symbol();
    Symbol& operator = (const Symbol&);
    bool operator ==(const Symbol&);
	bool operator !=(const Symbol&);
    string getSymbol();
    bool isTerminal();
    ostream& display(ostream& os) const;
    friend ostream& operator <<(ostream& os , const Symbol&);
};

#endif
