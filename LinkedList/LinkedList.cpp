#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList()
{
}

void LinkedList::PushBack(const int _data)
{
  Node* new_node = new Node(_data);
  if (top_node == nullptr)
  { 
    top_node = new_node;
  }
  else
  {
    cur_node = top_node;
    while (cur_node->m_next != nullptr)
    {
      cur_node = cur_node->m_next;
    }
    cur_node->m_next = new_node;
  }
}

void LinkedList::Delete(const int _data)
{
  if (top_node == nullptr)
    return;

  cur_node = top_node;

  if (_data == top_node->m_data)
  {
    cur_node = top_node->m_next;
    delete(top_node);
    top_node = cur_node;
  }
  else
  {
    while (cur_node->m_next != nullptr)
    {
      if (_data == cur_node->m_next->m_data)
      {
        Node* node_to_delete = cur_node->m_next;
        cur_node->m_next = cur_node->m_next->m_next;
        delete(node_to_delete);
        break;
      }
    }
  }

}

void LinkedList::PrintList()
{
  cur_node = top_node;
  while (cur_node != nullptr)
  {
    std::cout << cur_node->m_data << " -> ";
    cur_node = cur_node->m_next;
  }
}

LinkedList::~LinkedList()
{
  cur_node = top_node->m_next;
  while (cur_node->m_next != nullptr)
  {
    Node* node_to_delete = cur_node;
    cur_node = cur_node->m_next;
    delete(node_to_delete);
  }
}
