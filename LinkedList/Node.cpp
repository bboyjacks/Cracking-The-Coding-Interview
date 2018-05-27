#include "Node.h"



Node::Node(const int _data)
{
  m_data = _data;
}

void Node::PushBack(const int _data)
{
  Node* new_node = new Node(_data);
  Node* cur_node = this;
  while (cur_node->m_next != nullptr)
  {
    cur_node = cur_node->m_next;
  }
  cur_node->m_next = new_node;
}

void Node::Delete(const int _data)
{
  Node* cur_node = this;

}

Node::~Node()
{
  Node* cur_node = m_next;
  if (cur_node != nullptr)
  {
    Node* prev = cur_node;
    cur_node = cur_node->m_next;
    delete(prev);
  }
}
