#pragma once

class Node
{
private:
  int data;
  Node* link;

public:
  Node(int data);
  int getData();
  Node* getLink();
  void setLink(Node* link);
};

