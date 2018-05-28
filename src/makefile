Stack.o: Stack.cc Stack.h
	g++ -c Stack.cc

StackDB.o: Stack.cc Stack.h
	g++ -g -o StackDB.o -c Stack.cc

DList.o: DList.cc DList.h
	g++ -c DList.cc

DListDB.o: DList.cc DList.h
	g++ -g -o DListDB.o -c DList.cc

GrammarReader.o: GrammarReader.cc GrammarReader.h RuleSet.o DList.o Grammar.o Symbol.o
	g++ -c GrammarReader.cc

GrammarMain.o: GrammarMain.cc RuleSet.o GrammarReader.o Stack.o Grammar.o Symbol.o DList.o
	g++ -c GrammarMain.cc

Grammar.o: Grammar.cc Grammar.h RuleSet.o DList.o
	g++ -c Grammar.cc

RuleSet.o: RuleSet.cc RuleSet.h DList.o DList.o
	g++ -c RuleSet.cc

Symbol.o: Symbol.cc Symbol.h
	g++ -c Symbol.cc

grammar: GrammarMain.o GrammarReader.o RuleSet.o Symbol.o DList.o Stack.o Grammar.o
	g++ -o grammar GrammarMain.o GrammarReader.o RuleSet.o Symbol.o DList.o Stack.o Grammar.o

GrammarReaderDB.o: GrammarReader.cc GrammarReader.h RuleSetDB.o QueueDB.o GrammarDB.o SymbolDB.o
	g++ -g -o GrammarReaderDB.o -c GrammarReader.cc

GrammarMainDB.o: GrammarMain.cc RuleSetDB.o GrammarReaderDB.o StackDB.o GrammarDB.o SymbolDB.o DListDB.o
	g++ -g -o GrammarMainDB.o -c GrammarMain.cc

GrammarDB.o: Grammar.cc Grammar.h RuleSetDB.o DListDB.o
	g++ -g -o GrammarDB.o -c Grammar.cc

RuleSetDB.o: RuleSet.cc RuleSet.h DListDB.o QueueDB.o
	g++ -g -o RuleSetDB.o -c RuleSet.cc

SymbolDB.o: Symbol.cc Symbol.h
	g++ -g -o SymbolDB.o -c Symbol.cc

MainDB: GrammarMainDB.o GrammarReaderDB.o RuleSetDB.o SymbolDB.o DListDB.o StackDB.o GrammarDB.o
	g++ -o MainDB GrammarMainDB.o GrammarReaderDB.o RuleSetDB.o SymbolDB.o DListDB.o StackDB.o GrammarDB.o

clean:
	-rm *.o
	-rm *~
	-rm Main
	-rm MainDB
