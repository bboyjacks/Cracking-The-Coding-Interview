#pragma once

#include <memory>
struct Node
{
  Node* m_next{ nullptr };
  int m_data{ 0 };

  Node(const int _data);
  virtual ~Node();
};
