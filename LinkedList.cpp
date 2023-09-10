#include <iostream>
#include <limits>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
  head = nullptr;
  length = 0;
}

LinkedList::LinkedList(int* array, int len) : LinkedList()
{
  if ((array == nullptr) || (len <= 0))
    return;

  Node* pNew = nullptr;
  Node* pLast = nullptr;

  for (int i = 1; i <= len; i++)
  {
    pNew = new Node(*array);
    
    if (i == 1)
      head = pNew;
    else
      pLast->setLink(pNew);

    pLast = pNew;
    length++;
    array++;
  }
}

LinkedList::~LinkedList()
{
  Node* pCurr = head;
  Node* pNext = nullptr;

  while (pCurr != nullptr)
  {
    pNext = pCurr->getLink();
    delete pCurr;
    pCurr = pNext;
  }

  head = nullptr;
  length = 0;
}

void LinkedList::insertPosition(int pos, int newNum)
{
  Node* pNew = new Node(newNum);

  if (pos < 1)
    pos = 1;

  if (pos > length)
    pos = length + 1;

  if (pos == 1)
  {
    // insert a new node at the front of the list
    pNew->setLink(head);
    head = pNew;
  }
  else
  {
    // move to pos -1 location
    Node* pCurr = head;
    for (int i = 1; i <= pos - 2; i++)
      pCurr = pCurr->getLink();

    pNew->setLink(pCurr->getLink());
    pCurr->setLink(pNew);
  }

  // increase the LinkedList length
  length++;
}

bool LinkedList::deletePosition(int pos)
{
  if ((pos < 1) || (pos > length))
    return false;

  Node* pCurr = head;
  Node* p = nullptr;

  if (pos == 1)
  {
    head = pCurr->getLink();
    delete pCurr;
  }
  else
  {
    // move to pos - 1 location
    for (int i = 1; i <= pos - 2; i++)
      pCurr = pCurr->getLink();

    p = pCurr->getLink();
    pCurr->setLink(p->getLink());
    delete p;
  }

  // decrease the LinkedList length
  length--;
  return true;
}

int LinkedList::get(int pos)
{
  if ((pos < 1) || (pos > length))
    return numeric_limits<int>::max();

  Node* pCurr = head;

  // move to pos - 1 location
  for (int i = 1; i <= pos - 1; i++)
    pCurr = pCurr->getLink();

  return pCurr->getData();
}

int LinkedList::search(int target)
{
  Node* pCurr = head;
  int index = 1;
  int result = -1;

  while (pCurr != nullptr)
  {
    if (pCurr->getData() == target)
    {
      result = index;
      break;
    }

    pCurr = pCurr->getLink();
    index++;
  }

  return result;
}

void LinkedList::printList()
{
  if (head != nullptr)
  {
    Node* pCurr = head;
    cout << "[";

    while (pCurr != nullptr)
    {
      cout << pCurr->getData();
      pCurr = pCurr->getLink();

      if (pCurr != nullptr)
        cout << " ";
    }

    cout << "]";
  }
}

int LinkedList::getLength()
{
  return length;
}
