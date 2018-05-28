#ifndef DLIST_CC
#define DLIST_CC

#include "DList.h"

/*
    T item;
    Link<T>* pNext;
    Link<T>* pPrev;
*/

template <typename T>
Link<T>::Link()
{
  pNext = NULL;
  pPrev = NULL;
}

template <typename T>
Link<T>::Link(T thing, Link<T>* next, Link<T>* prev)
{
  item = thing;
  pNext = next;
  pPrev = prev;
}


/*
    Link<T>* pHead;
    Link<T>* pTail;
    int size
*/

template <typename T>
DList<T>::DList()
{
  pHead = NULL;
  pTail = NULL;
  size = 0;
}

template <typename T>
DList<T>::DList(T item)
{
  pHead = new Link<T>(item, NULL, NULL);
  pTail = pHead;
  size = 1;
}

template <typename T>
DList<T>::DList(const DList<T> & aList)
{
  Link<T>* pTemp;
  if(aList.pHead != NULL)
  {
    pHead = new Link<T>(aList.pHead->item,NULL,NULL);
    pTail = pHead;
  }
  pTemp = aList.pHead;
  while(pTemp != aList.pTail)
  {
    pTemp = pTemp->pNext;
    addToTail(pTemp->item);
  }
  size = aList.size;
}

template <typename T>
DList<T>::~DList()
{
  if(pHead != NULL)
  {
    while(pHead != pTail)
    {
      pTail = pTail->pPrev;
      delete pTail->pNext;
    }
    delete pHead;
  }
}

template <typename T>
ostream& DList<T>::display(ostream & os) const
{
  Link<T>* pTemp;
  if(pHead != NULL)
  {
    pTemp = pHead;
    while(pTemp != pTail)
    {
      os << pTemp->item << "  ||  ";
      pTemp = pTemp->pNext;
    }
    os << pTemp->item;
  }
  return(os);
}

template <typename T>
DList<T>& DList<T>::operator = (const DList<T>& aDList)
{
  if(pHead != aDList.pHead)
  {
    if(pHead != NULL)
    {
      while(pHead != pTail)
      {
        pTail = pTail->pPrev;
        delete pTail->pNext;
      }
      delete pHead;
    }
    Link<T>* pTemp;
    if(aDList.pHead != NULL)
    {
      pHead = new Link<T>(aDList.pHead->item,NULL,NULL);
      pTail = pHead;
    }
    pTemp = aDList.pHead;
    while(pTemp != aDList.pTail)
    {
      pTemp = pTemp->pNext;
      addToTail(pTemp->item);
    }
    size = aDList.size;
  }
  return (*this);
}

template <typename T>
bool DList<T>::operator == (const DList<T>& aDList)
{
	bool output = true;
	if(size != aDList.size | aDList.pHead == NULL)
	{
		output = false;
	}
	else
	{
		Link<T>* pTemp = pHead;
		Link<T>* pTempO = aDList.pHead;
		while(pTemp != pTail)
		{
			if(pTemp->item != pTempO->item)
			{
				output = false;
			}
			pTemp = pTemp->pNext;
			pTempO = pTempO->pNext;
		}
	}	
	return(output);
}

template <typename T>
bool DList<T>::isEmpty() const
{
  return(pHead == NULL);
}

template <typename T>
bool DList<T>::isFull() const
{
  return(false);
}

template <typename T>
void DList<T>::addToHead( T item)
{
  Link<T>* pTemp;
  if(pHead != NULL)
  {
    pTemp = new Link<T>(item, pHead, NULL);
    pHead->pPrev = pTemp;
    pHead = pTemp;
    size++;
  }
  else
  {
    pTemp = new Link<T>(item, NULL, NULL);
    pHead = pTemp;
    pTail = pTemp;
    size++;
  }
}

template <typename T>
void DList<T>::addToTail( T item)
{
  Link<T>* pTemp;
  if(pTail != NULL)
  {
    pTemp = new Link<T>(item, NULL, pTail);
    pTail->pNext = pTemp;
    pTail = pTemp;
    size++;
  }
  else
  {
    addToHead(item);
  }
}

template <typename T>
void DList<T>::removeHead()
{
  if(pHead != NULL && pHead != pTail)
  {
    pHead = pHead->pNext;
    delete pHead->pPrev;
    size--;
  }
  else if(pHead == pTail)
  {
	pHead = NULL;
	pTail = NULL;
    size = 0;
  }
}

template <typename T>
void DList<T>::removeTail()
{
  if(pTail != NULL && pHead != pTail)
  {
    pTail = pTail->pPrev;
    delete pTail->pNext;
    size--;
  }
  if(pHead == pTail)
  {
    delete pTail;
    size--;
  }
}

template <typename T>
void DList<T>::insertAfter( T oldval , T newval)
{
  Link<T>* pTemp;
  Link<T>* pNew;
  if(pHead != NULL)
  {
    pTemp = pHead;
    if(pTemp->item == oldval)
    {
      pNew = new Link<T>(newval, pTemp->pNext, pTemp);
      pNew->pPrev->pNext = pNew;
      pNew->pNext->pPrev = pNew;
      size++;
    }
    while(pTemp != pTail)
    {
      if(pTemp->item == oldval)
      {
        pNew = new Link<T>(newval, pTemp->pNext, pTemp);
        pNew->pPrev->pNext = pNew;
        pNew->pNext->pPrev = pNew;
        size++;
      }
      pTemp = pTemp->pNext;
    }
    if(pTemp->item == oldval)
    {
      addToTail(newval);  
    }
  }
}

template <typename T>
void DList<T>::insertBefore( T oldval, T newval)
{
  Link<T>* pTemp;
  Link<T>* pNew;
  if(pHead != NULL)
  {
    pTemp = pHead;
    if(pTemp->item == oldval)
    {
      addToHead(newval);
    }
    while(pTemp != pTail)
    {
      if(pTemp->item == oldval)
      {
        pNew = new Link<T>(newval, pTemp, pTemp->pPrev);
        pNew->pPrev->pNext = pNew;
        pNew->pNext->pPrev = pNew;
        size++;
      }
      pTemp = pTemp->pNext;
    }
    if(pTemp->item == oldval)
    {
      pNew = new Link<T>(newval, pTemp, pTemp->pPrev);
      pNew->pPrev->pNext = pNew;
      pNew->pNext->pPrev = pNew;
      size++;
    }
  }
}

template <typename T>
void DList<T>::remove(T item)
{
  Link<T>* pTemp;
  if(pHead != NULL)
  {
    pTemp = pHead;
    if(pTemp->item == item)
    {
      removeHead();  
    }
    while(pTemp != pTail)
    {
      if(pTemp->item == item)
      {
        pTemp->pPrev->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pTemp->pPrev;         
      }
      Link<T>* delTemp = pTemp;
      pTemp = pTemp->pNext;
      delete delTemp;
      size--;
    }
    if(pTemp->item == item)
    {
      removeTail();
    }
  }
}

template <typename T>
T DList<T>::getAt(unsigned place)
{
  Link<T>* pTemp = pHead;
  T output;
  if(place < size)
  {
    for(int curSpot = 0; curSpot < size; curSpot++)
    {
      if(curSpot == place)
      {
        output = pTemp->item;
      }
      pTemp = pTemp->pNext;
    }
  }
  return(output);
}

template <typename T>
int DList<T>::getSize() const
{
  return(size);
}

template <typename T>
int DList<T>::find(T val)  //-1 means doesn't exits
{
  int output = -1;
  unsigned spot = 0;
  Link<T>* pTemp;
  if(pHead != NULL)
  {
    pTemp = pHead;
    if(pTemp->item == val)
    {
      output = spot;
    }
    while(pTemp != pTail)
    {
      if(pTemp->item == val)
      {
        output = spot;
      }
      pTemp = pTemp->pNext;
      spot++;
    }
    if(pTemp->item == val)
    {
      output = spot;
    }
  }
  return(output);
}

template <typename T>
ostream& operator << (ostream& os , const DList<T> & theList)
{
  theList.display(os);
  return(os);
}

#endif
