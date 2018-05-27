#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
  Node* first;
  Node* second;
  Node* third;
  {
    LinkedList list;
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);

    list.PrintList();

    first = list.top_node;
    second = list.top_node->m_next;
    third = list.top_node->m_next->m_next;
    
    if (first != nullptr)
      std::cout << "First not null" << std::endl;
    if (second != nullptr)
      std::cout << "Second not null" << std::endl;
    if (third != nullptr)
      std::cout << "Third is not null" << std::endl;
    
    list.Delete(5);
    list.PrintList();
    list.Delete(2);
    list.PrintList();
    list.Delete(3);
    list.PrintList();
    list.Delete(4);
    list.PrintList();
    list.Delete(10);
    list.PrintList();
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