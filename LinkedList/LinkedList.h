#pragma once

class Node;

class LinkedList
{
public:
  Node * top_node{ nullptr };
  Node* cur_node{ nullptr };

  LinkedList();

  void PushBack(const int _data);
  void Delete(const int _data);
  void PrintList();

  virtual ~LinkedList();
};

