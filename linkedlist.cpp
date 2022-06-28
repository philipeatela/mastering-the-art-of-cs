#include <exception>
#include <stdexcept>
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

  Node* search(std::string key) {
    if (head == NULL)
      throw "Error - list is empty.";

    // declare helper pointer
    Node *temp;
    // point it to the start of the list
    temp = head;
    // don't stop until next node is NULL
    while (temp != NULL) {
      if (key == temp->data) {
        return temp;
      }
      temp = temp->next;
    }
      throw "Error - could not find key in list.";
  }

  // removes first occurence of key
  void remove(std::string key) {
    // handle empty list
    if (head == NULL)
      return;

    Node *to_be_deleted = search(key);
    std::cout << "to_be_deleted:" << to_be_deleted->data << " ";

    // handle deleting head node
    if (to_be_deleted == head) {
      head = to_be_deleted->next;
      delete to_be_deleted;
      return;
    }
    
    // iterate until element is the previous to the one that will be deleted,
    // then delete and readjust pointers
    Node* temp = head;
    temp = head;
    while (temp != NULL) {
      if (temp->next == to_be_deleted) {
        temp->next = temp->next->next;
        delete to_be_deleted;
        return;
      }
    }
  }

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

  SUBCASE("append") {
    ll.append("one");
    ll.append("two");
    ll.append("three");

    ll.display();

    CHECK(20 == 20);
  }

  SUBCASE("search") {
    ll.append("one");
    ll.append("two");
    ll.append("three");
    ll.append("four");

    Node *item = ll.search("three");

    CHECK(item->data == "three");
  }

  SUBCASE("remove") {
    ll.append("one");
    ll.append("two");
    ll.append("three");
    ll.append("four");

    ll.remove("three");

    ll.display();
    // CHECK(item->data == "three");
  }
}