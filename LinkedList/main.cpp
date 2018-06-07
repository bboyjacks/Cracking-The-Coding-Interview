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

  // Problem 2.1
  void DeleteRepeatedNode(LinkedList* _linked_list)
  {
    if (_linked_list->m_top_node == nullptr)
      return;

    Node* cur_node = _linked_list->m_top_node;

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

  // Problem 2.5
  void AddNums(const LinkedList& _num_1, const LinkedList& _num_2, LinkedList& _result)
  {
    Node* num_1 = _num_1.m_top_node;
    Node* num_2 = _num_2.m_top_node;

    Node* cur_node = nullptr;

    while (num_1 != nullptr && num_2 != nullptr)
    {
      const int new_num = num_1->m_data + num_2->m_data;
      const int remainder = new_num / 10;
      const int digit = new_num % 10;
      Node* digit_node = new Node(digit);
      Node* remainder_node = new Node(remainder);
      digit_node->m_next = remainder_node;

      if (_result.m_top_node == nullptr)
        _result.m_top_node = digit_node;
      else
      {
        cur_node->m_data = cur_node->m_data + digit_node->m_data;
        cur_node->m_next = remainder_node;
        delete digit_node;
      }
      cur_node = remainder_node;

      num_1 = num_1->m_next;
      num_2 = num_2->m_next;
    }

    if (cur_node != nullptr && num_1 != nullptr)
    {
      cur_node->m_data = cur_node->m_data + num_1->m_data;
      const int extra_digit = cur_node->m_data / 10;
      cur_node->m_data = cur_node->m_data % 10;
      if (extra_digit > 0)
      {
        Node* extra_value = new Node(extra_digit);
        cur_node->m_next = extra_value;
      }
    }

    if (cur_node != nullptr && num_2!= nullptr)
    {
      cur_node->m_data = cur_node->m_data + num_2->m_data;
      const int extra_digit = cur_node->m_data / 10;
      cur_node->m_data = cur_node->m_data % 10;
      if (extra_digit > 0)
      {
        Node* extra_value = new Node(extra_digit);
        cur_node->m_next = extra_value;
      }
    }

  }
  // Couldn't really test. In order to solve this
  // I need to implement iterator pattern. I don't know that 
  // yet and it's out of the scope of this exercise
  TEST_F(LinkedListGoogleTest, problem_2_1)
  {

  }

  TEST_F(LinkedListGoogleTest, problem_2_5)
  {
    LinkedList num_1;
    num_1.PushBack(6);
    num_1.PushBack(7);
    num_1.PushBack(2);

    LinkedList num_2;
    num_2.PushBack(5);
    num_2.PushBack(6);

    LinkedList result;
    AddNums(num_1, num_2, result);

    LinkedList expected_result;
    expected_result.PushBack(1);
    expected_result.PushBack(4);
    expected_result.PushBack(3);

    ASSERT_TRUE(result.m_top_node != nullptr);

    Node* cur_node_1 = result.m_top_node;
    Node* cur_node_2 = expected_result.m_top_node;
    while (cur_node_1 != nullptr)
    {
      EXPECT_TRUE(cur_node_2 != nullptr);
      EXPECT_EQ(cur_node_1->m_data, cur_node_2->m_data);
      cur_node_1 = cur_node_1->m_next;
      cur_node_2 = cur_node_2->m_next;
    }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  const int result = RUN_ALL_TESTS();
  std::getchar();
  return result;
}