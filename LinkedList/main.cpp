#include <gtest/gtest.h>
#include "LinkedList.h"
#include "Node.h"

namespace
{
  class LinkedListGoogleTest : public ::testing::Test
  {
  protected:
    void SetUp() override
    {
      m_linked_list.PushBack(1);
      m_linked_list.PushBack(2);
      m_linked_list.PushBack(3);
      m_linked_list.PushBack(3);
      m_linked_list.PushBack(4);
      m_linked_list.PushBack(3);
    }

    void TearDown() override
    {

    }

    LinkedList m_linked_list;
  };

  // Problem 1.1
  void DeleteRepeatedNode(LinkedList* _linked_list)
  {
    if (_linked_list->top_node == nullptr)
      return;

    Node* cur_node = _linked_list->top_node;

    while (cur_node->m_next != nullptr)
    {
      if (cur_node->m_next->m_data == cur_node->m_data)
      {
        Node* node_to_delete = cur_node->m_next;
        cur_node->m_next = cur_node->m_next->m_next;
        delete node_to_delete;
      }
      else
        cur_node = cur_node->m_next;
    }
  }

  TEST_F(LinkedListGoogleTest, problem_1_1)
  {

  }
}

int main()
{
  std::getchar();
  return 0;
}