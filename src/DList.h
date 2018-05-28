#ifndef DLIST_H
#define DLIST_H

#include <iostream>

using namespace std;

template <typename T>
class DList;

template <typename T>
ostream& operator << (ostream& os , const DList<T>& theList);

template <typename T>
class Link 
{
  protected:
    T item;
    Link<T>* pNext;
    Link<T>* pPrev;
    friend class DList<T>;

  public:
    Link();           // O(1)
    Link(T item, Link<T>* next, Link<T>* prev);     // O(1)
};

template <typename T>
class DList 
{
  protected:
    Link<T>* pHead;
    Link<T>* pTail;
    int size;       

  public:
    DList();             // O(1)
    DList(T item);      // O(1)
    DList(const DList<T> &); // O(N)
    virtual ~DList();     // O(N)
    DList<T>& operator = (const DList<T> &);        // O(N)
	bool operator == (const DList<T> &);
    ostream& display(ostream & os) const;       // O(N)
    virtual bool isEmpty() const;    // O(1)
    virtual bool isFull() const;     // O(1)
    virtual void addToHead( T item);     // O(1)
    virtual void addToTail( T item);      // O(1)
    virtual void removeHead();               // O(1)
    virtual void removeTail();             // O(1)
    virtual void insertAfter( T oldval , T newval);        // O(N)
    virtual void insertBefore( T oldval, T newval);         // O(N)
    virtual void remove(T item);              // O(N)
    virtual T getAt(unsigned place);         //O(N)
    virtual int getSize() const;              //O(1)
    virtual int find(T);                //O(N)
    friend ostream& operator << <T> (ostream& os , const DList<T>& theList);    // O(N)
};

#endif
