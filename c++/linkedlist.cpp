#include <exception>
#include <stdexcept>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <iostream>
#include "linkedlist.h"
class Node : public INode {
public:
  std::string data;
  Node *next; // REFERENCE to a node
};

class LinkedList : public ILinkedList {
  Node *head = NULL; // REFERENCE to FIRST node

public:
  // add to end of linked list (innefficient because we need to iterate it)
  void append(std::string new_data) {
    // we are creating a variable that is a pointer to a Node,
    // and assigning that variable to a new Node
    // this statement allocates memory, if i understand correctly
    Node *new_node = new Node();

    new_node->data = new_data;
    new_node->next = NULL;

    // if first insertion
    if (head == NULL) {
      head = new_node;
      return;
    }

    Node *temp = head;
    while (temp != NULL) {
      if (temp->next == NULL) {
        temp->next = new_node;
        return;
      }
      temp = temp->next;
    }
    return;
  }

  void appendAtStart(std::string new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;

    head = new_node;
  }

  void insert(std::string new_data, int index) {
    if (index == 0) {
      appendAtStart(new_data);
      return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;

    Node *temp = head;
    // start at second item, since we checked for the first one before
    for (int i = 1;i <= index;i++) {
      // if we are at the item before where we wanna insert, time to make the change
      if (i - 1 == index) {
        temp->next = new_node;
      }
      temp = temp->next;
    }

    while (temp != NULL) {
      if (temp->next == NULL) {
        temp->next = new_node;
        return;
      }
      temp = temp->next;
    }
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

  std::string get(int index) {
    Node *ptr = head;;

    // to get at a certain index, still needs to iterate through list
    for (int i = 0;i <= index;i++) {
      if (i == index) {
        return ptr->data;
      }
      ptr = ptr->next;
    }
    throw "Error - could not find item at this index.";
  }

  // removes first occurence of key
  void remove(std::string key) {
    // handle empty list
    if (head == NULL)
      return;

    Node *to_be_deleted = search(key);

    // handle deleting head node
    if (to_be_deleted == head) {
      head = to_be_deleted->next;
      delete to_be_deleted;
      return;
    }
    
    // iterate until element is the previous to the one that will be deleted,
    // then delete and readjust pointers
    Node* temp = head;
    while (temp != NULL) {
      if (temp->next == to_be_deleted) {
        temp->next = temp->next->next;
        delete to_be_deleted;
        return;
      }
      temp = temp->next;
    }
    return;
  }

  void display() {
    Node *ptr;
    ptr = head;
    while (ptr != NULL) {
      std::cout << "data:" << ptr->data << "\n";
      ptr = ptr->next;
    }
  }

  void destroy() { delete this; }
};

// extern "C" __declspec(dllexport) ILinkedList* __cdecl create_klass()
// {
//     return new LinkedList;
// }

TEST_CASE("LinkedList") {
  LinkedList ll;

  SUBCASE("append") {
    ll.append("one");
    ll.append("two");
    ll.append("three");

    ll.display();

    CHECK(ll.get(0) == "one");
    CHECK(ll.get(1) == "two");
    CHECK(ll.get(2) == "three");
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

    CHECK(ll.get(0) == "one");
    CHECK(ll.get(1) == "two");
    CHECK(ll.get(2) == "four");
  }

  SUBCASE("appendAtStart") {
    ll.appendAtStart("one");
    ll.appendAtStart("two");
    ll.appendAtStart("three");

    ll.display();

    CHECK(ll.get(0) == "three");
    CHECK(ll.get(1) == "two");
    CHECK(ll.get(2) == "one");
  }

  SUBCASE("insert") {
    ll.append("one");
    ll.append("two");
    ll.append("three"); //

    ll.insert("middle", 1);
    ll.insert("first", 0);
    ll.insert("last", 5);
    ll.insert("alsomiddle", 2); 

    ll.display();

    CHECK(ll.get(0) == "first");
    CHECK(ll.get(1) == "one");
    CHECK(ll.get(2) == "alsomiddle");
    CHECK(ll.get(3) == "middle");
    CHECK(ll.get(4) == "two");
    CHECK(ll.get(5) == "three");
    CHECK(ll.get(6) == "last");
  }
}