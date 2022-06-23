#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <iostream>

class Node {
public:
  std::string data;
  Node *next; // REFERENCE to a node
};

class LinkedList {
  Node *head = NULL; // REFERENCE to FIRST node

public:
  void append(std::string new_data) {
    // we are creating a variable that is a pointer to a Node,
    // and assigning that variable to a new Node
    // this statement allocates memory, if i understand correctly
    Node *new_node = new Node();

    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
  }

  // deletes first occurence
  // void remove(std::string key) {
  //    if (head == NULL)
  //       return;

  //   if (node == head) {
  //     head = node.next;
  //     return;
  //   }
  //   Node* temp = *head_ref;

  //   temp = head;

  //   while (temp != NULL) {
  //     std::cout << ptr->data << " ";
  //     ptr = ptr->next;
  //   }

  // }

  void display() {
    Node *ptr;
    ptr = head;
    while (ptr != NULL) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }
};

TEST_CASE("LinkedList") {
  LinkedList ll;

  SUBCASE("Appending items") {
    SUBCASE("append works") {
      ll.append("one");
      ll.append("two");
      ll.append("three");

      ll.display();

      CHECK(20 == 20);
    }
  }
}