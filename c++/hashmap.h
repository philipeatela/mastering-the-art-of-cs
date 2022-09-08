#include <string>
#include "item.h"

class IHashMap {
public:
  IItem data;
  void insert(std::string key, IPerson value);
  int hashFunction(std::string value);
  IPerson find(std::string key);
  void test();
};