#pragma once
#include "Node.h"

class LinkedList
{
private:
  Node* head;
  int length;

public:
  LinkedList();
  LinkedList(int* array, int len);
  ~LinkedList();

  void insertPosition(int pos, int newNum);
  bool deletePosition(int pos);
  int get(int pos);
  int search(int target);
  void printList();
  int getLength();
};

