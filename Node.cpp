#include "Node.h"

Node::Node(int data)
{
  this->data = data;
  this->link = nullptr;
}

int Node::getData()
{
  return data;
}

Node* Node::getLink()
{
  return link;
}

void Node::setLink(Node* link)
{
  this->link = link;
}
