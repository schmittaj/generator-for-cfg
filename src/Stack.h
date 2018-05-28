#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename T>   // declare class Stack as a template, so can be used as an argument in declaration 
class Stack;            //  in this line
 
template <typename T>  //  declare operator << itself as a template, regardless of later friend declaration
ostream & operator << (ostream & os, const Stack<T> & s);
 

template <typename T>
class Stack
{
  protected:
    int maxCapacity;
    T* stack;
    int topOfStack;
    void display(ostream & os) const;     // helper function for display

  public:
    Stack(); // An empty stack of default maximum capacity
    Stack(int max); // An empty stack of specified maximum capacity
    Stack(const Stack<T>& aStack); // A deep copy constructor
    Stack<T>& operator =(const Stack<T>& aStack); // A deep assignment operator
    virtual ~Stack(); // A destructor
    virtual bool isEmpty(); // Returns true when there are zero elements held in stack
    virtual bool isFull(); // Returns true when there are maximum capacity items held in stack
    virtual T& top(); // Returns copy of the top element in stack
    virtual const T& top() const; // Returns constant access to top element in stack
    virtual void push(const T& item); // Adds an additional item to the top of the stack
    virtual void pop(); // Removes the top element of the stack
    friend ostream& operator << <T> (ostream& os, const Stack<T>& s); // outputs entire stack
};

#endif
