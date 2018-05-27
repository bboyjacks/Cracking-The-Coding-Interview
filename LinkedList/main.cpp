#include <iostream>
#include "Node.h"

int main()
{
  Node* first;
  Node* second;
  Node* third;
  {
    Node nodes(2);
    nodes.PushBack(3);
    nodes.PushBack(4);

    first = &nodes;
    second = nodes.m_next;
    third = nodes.m_next->m_next;
    
    if (first != nullptr)
      std::cout << "First not null" << std::endl;
    if (second != nullptr)
      std::cout << "Second not null" << std::endl;
    if (third != nullptr)
      std::cout << "Third is not null" << std::endl;
  }

  if (first == nullptr)
    std::cout << "First is null" << std::endl;
  if (second == nullptr)
    std::cout << "Second is null" << std::endl;
  if (third == nullptr)
    std::cout << "Third is null" << std::endl;

  std::getchar();
  return 0;
}