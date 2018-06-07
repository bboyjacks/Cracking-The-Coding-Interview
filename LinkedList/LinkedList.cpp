#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList()
{
}

void LinkedList::PushBack(const int _data)
{
  Node* new_node = new Node(_data);
  if (m_top_node == nullptr)
  { 
    m_top_node = new_node;
  }
  else
  {
    m_cur_node = m_top_node;
    while (m_cur_node->m_next != nullptr)
    {
      m_cur_node = m_cur_node->m_next;
    }
    m_cur_node->m_next = new_node;
  }
}

void LinkedList::Delete(const int _data)
{
  if (m_top_node == nullptr)
    return;

  m_cur_node = m_top_node;

  if (_data == m_top_node->m_data)
  {
    m_cur_node = m_top_node->m_next;
    delete(m_top_node);
    m_top_node = m_cur_node;
  }
  else
  {
    while (m_cur_node->m_next != nullptr)
    {
      if (_data == m_cur_node->m_next->m_data)
      {
        Node* node_to_delete = m_cur_node->m_next;
        m_cur_node->m_next = m_cur_node->m_next->m_next;
        delete(node_to_delete);
        break;
      }
    }
  }

}

void LinkedList::PrintList()
{
  m_cur_node = m_top_node;
  while (m_cur_node != nullptr)
  {
    std::cout << m_cur_node->m_data << " -> ";
    m_cur_node = m_cur_node->m_next;
  }
}

LinkedList::~LinkedList()
{
  if (m_top_node != nullptr) {
    m_cur_node = m_top_node->m_next;
    while (m_cur_node != nullptr && m_cur_node->m_next != nullptr)
    {
      Node* node_to_delete = m_cur_node;
      m_cur_node = m_cur_node->m_next;
      delete(node_to_delete);
    }
  }
}
