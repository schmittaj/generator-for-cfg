#ifndef GRAMMARREADER_CC
#define GRAMMARREADER_CC

#include "GrammarReader.h"

/*
    string filename;
    Grammar gram;
*/

GrammarReader::GrammarReader()
{
}

GrammarReader::GrammarReader(string file)
{
  filename = file;
}

GrammarReader::~GrammarReader()
{
}
/*
void GrammarReader::readFile()
{
  ifstream in(filename.c_str());  //file to read
  string temp;						//line
  char tempChar;					//single char

  tempChar = in.get();				//grab the first char
  while(tempChar != '\n')			//read in the word until you get to the end of the line
  {
    temp.push_back(tempChar);
    tempChar = in.get();
  }
  
  while(!in.eof())					//until we hit end of file
  {
    Symbol tempNT(temp,false);		// make a new Symbol object with our read in word
    RuleSet tempSet(tempNT);		// add this Symbol to a new RuleSet
    while( !temp.empty() && !in.eof() )		//jump over if blank line or end of the file
    {
      temp.clear();							//empty temp string we're using
      tempChar = in.get();					//read in the first char
      while(tempChar != '\n' && !in.eof())	//not end of line or end of file
      {
        while(tempChar != '\n' && !in.eof())//again not end of line or end of file
        {
          if(tempChar == '>')			//if we've hit the end of a non-terminal symbol
          {
            temp.push_back(tempChar);   //put the > at the end then load a space
            tempChar = ' ';
          }
          temp.push_back(tempChar);		//push on the char, space if a non-terminal was just there or whatever non \n or non eof char
          tempChar = in.get();			// read next char
        }
        temp.push_back(' ');
        temp.push_back('z');
        temp.push_back('z');
        temp.push_back('y');
        temp.push_back('z');
        temp.push_back('z');
        temp.push_back(' ');            //at the end of a word add " zzyzz " as a delimiter between words
        tempChar = in.get();			//grab the next char
      }                                 //what we end up with at the end here is the complete rule set with " zzyzz " between each word
      stringstream ssTemp(stringstream::in | stringstream::out);
      string tempString;

      ssTemp << temp;                 //now we feed in our rule set that is one long string
      while(!ssTemp.eof())            // while we're not at the end of our rule set string
      {
        Queue<Symbol> tempQue(100);   //making a queue of symbols
        ssTemp >> tempString;         // reading in a word
        while(tempString != "zzyzz")  //while we're not dealing with a delimiter 
        {
          if(tempString[0] == '<')    //if we have a non terminal
          {
            Symbol thing(tempString,false); // make a non-terminal symbol
            tempQue.enqueue(thing);			// add it to our queue
          }
          else if(tempString != "zzyzz")
          {
            Symbol thing(tempString,true);	//make symbol, add to queue
            tempQue.enqueue(thing);
          }
          ssTemp >> tempString;				//grab next word
        }									
		
        if(!tempQue.isEmpty())				//I don't think this will ever be empty here
        {
          tempSet.addProduction(tempQue);	
        }
		
		tempSet.addProduction(tempQue);		//adds our queue of Symbols as a production group to our rule set
        temp.clear();						
      }
    }										
    gram.addRuleSet(tempSet);				//add the RuleSet to the grammar
    tempChar = in.get();					
    while(tempChar != '\n' && !in.eof())	//grabs the next word for the next production group or will exit 
    {										//CHECK if this will ever be a \n and if so, will it break it
      temp.push_back(tempChar);
      tempChar = in.get();
    }
  }
  in.close();								//close the reader
}
*/
void GrammarReader::altReadFile()
{
  ifstream in(filename.c_str());  //file to read
  string tempString;		
  getline(in, tempString);
  while(!in.eof())
  {
	bool noProdSym = true;
	RuleSet rs;
    while(!in.eof() && !tempString.empty())
	{
	  DList<Symbol> holder;
	  int loc = tempString.find_first_of(" ",0);
	  while(loc != string::npos)
	  {
		  string processString = tempString.substr(0,loc);
		  holder.addToTail(parseSymbol(processString));
		  tempString = tempString.substr(loc+1,tempString.length()-loc);
		  loc = tempString.find_first_of(" ",0);
	  }
	  holder.addToTail(parseSymbol(tempString));
	  if(noProdSym)
	  {		  
	    rs.setProductionSymbol(holder.getAt(0));
		holder.removeHead();
		noProdSym = false;
	  }
	  getline(in, tempString);
	  if(!holder.isEmpty())
	  {
		rs.addProduction(holder);
	  }
	}
	if(tempString.empty())
	{
		gram.addRuleSet(rs);
		getline(in, tempString);
	}
  }
}

Symbol GrammarReader::parseSymbol(string tmp)
{
	bool terminal = true;
	string processString = tmp;
	if(processString[0] == '<')
	{
		terminal = false;
		processString = processString.substr(1,processString.length()-2);
	}
	return(Symbol(processString,terminal));
}

void GrammarReader::setFile(string file)
{
  filename = file;
}

Grammar GrammarReader::giveGrammar()
{
  return(gram);
}

#endif
