#ifndef STACK_CC
#define STACK_CC

#include "Stack.h"

  /*
    T* stack;
    int topOfStack;
    int maxCapacity;
   */

template <typename T>
Stack<T>::Stack()
{
  maxCapacity = 100;
  stack = new T[maxCapacity];
  topOfStack = -1;
}

template <typename T>
Stack<T>::Stack(int max)
{
  maxCapacity = max;
  stack = new T[maxCapacity];
  topOfStack = -1;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& aStack)
{
  topOfStack = aStack.topOfStack;
  maxCapacity = aStack.maxCapacity;
  stack = new T[maxCapacity];
  for(int a = 0; a < maxCapacity; a++)
  {
    stack[a] = aStack.stack[a];
  }
}


template <typename T>
Stack<T>::~Stack()
{
  delete [] stack;
}

template <typename T>
void Stack<T>:: display(ostream & os) const
{
  for(int a = 0; a <= topOfStack; a++)
  {
    os << stack[a] << " ";
  }
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& aStack)
{
  if(stack != aStack.stack)
  {
    delete [] stack;
    topOfStack = aStack.topOfStack;
    maxCapacity = aStack.maxCapacity;
    stack = new T[maxCapacity];
    for(int a = 0; a < maxCapacity; a++)
    {
      stack[a] = aStack.stack[a];
    }
  }
}

template <typename T>
bool Stack<T>::isEmpty()
{
  return(topOfStack == -1);
}

template <typename T>
bool Stack<T>::isFull()
{
  return(false);
}

template <typename T>
T& Stack<T>::top()
{
  return(stack[topOfStack]);
}

template <typename T>
const T& Stack<T>::top() const
{
  return(stack[topOfStack]);
}

template <typename T>
void Stack<T>::push(const T& item)
{
  if( topOfStack != (maxCapacity -1) )
  {
    topOfStack++;
    stack[topOfStack] = item;
  }
  else
  {
    T* temp = new T[maxCapacity*2];
    for(int a = 0; a < maxCapacity; a++)
    {
      temp[a] = stack[a];
    }
    maxCapacity = maxCapacity * 2;
    delete [] stack;
    stack = temp;
    topOfStack++;
    stack[topOfStack] = item;
  }
}

template <typename T>
void Stack<T>::pop()
{
  if(!isEmpty())
  {
    topOfStack--;
  }
}

template <typename T>
ostream& operator << (ostream& os, const Stack<T>& s)
{
  s.display(os);
  return (os);  
}

#endif
