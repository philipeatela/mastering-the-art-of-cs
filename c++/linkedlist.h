#include <string>
#include "node.h"

class ILinkedList {
public:
  virtual void destroy() = 0;
  void append(std::string new_data);
  void appendAtStart(std::string new_data);
  void insert(std::string, int index);
  INode search(std::string key);
  std::string get(int index);
  void remove(std::string key);
  void display();
};