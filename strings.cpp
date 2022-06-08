#include <iostream>
using namespace std;

class ArrayList {
  static const int DEFAULT_SIZE = 10;
  static const int RESIZING_FACTOR = 2;

  std::string *data = nullptr;
  int arraySize;
  int arrayLength;

public:
  ArrayList(int initialSize) {
    if (initialSize) {
      arraySize = initialSize;
    } else {
      arraySize = DEFAULT_SIZE;
    }

    arrayLength = 0;
    data = new std::string[arraySize];
  }

  std::string *getData() { return data; }

  int getLength() { return arrayLength; }

  void add(std::string value) {
    if (arrayLength == arraySize) {
      int newSize = arraySize * RESIZING_FACTOR;
      std::string *newArray[newSize];
      for (int i = 0; i < arrayLength; i++) {
        newArray[i] = &data[i];
      }
    }
    data[arrayLength] = value;
    arrayLength++;
  }

  void set(int index, std::string value) {
    if (index > arraySize - 1) {
      cout << "Invalid array position given";
      return;
    }
    data[index] = value;
    return;
  }

  void remove(int index) {
    if (index < 0 || index > arraySize - 1) {
      cout << "Invalid array position given";
      return;
    }
    std::string *newArray[arraySize];
    for (int i = 0; i < arrayLength; i++) {
      newArray[i] = &data[i];
    }
  }

  void clear() {
    // std::string *newArray[DEFAULT_SIZE];
    // data = newArray;
    data = nullptr;
    data = new std::string[DEFAULT_SIZE];
  }
};

// @TODO test
int main() {
  ArrayList al(4);
  std::string *arrayData = al.getData();

  al.add("hello");
  al.add("see");
  al.add("plus");
  al.add("plus");
  al.add("exztra1");
  al.add("extra2");
  al.add("extra3");

  for (int i = 0; i < al.getLength(); i++) {
    cout << "Data: " << arrayData[i] << "\n";
  }
  return 0;
}