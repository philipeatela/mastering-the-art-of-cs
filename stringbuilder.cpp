#include "doctest.h"

class StringBuilder {
  static const int DEFAULT_SIZE = 16;

  std::string *data;
  int capacity;
  int length;

public:
  StringBuilder() {
    capacity = DEFAULT_SIZE;
    length = 0;
    data = new std::string[capacity];
  }

  StringBuilder(int initialCapacity) {
    capacity = initialCapacity;
    length = 0;
    data = new std::string[capacity];
  }

  StringBuilder(std::string initialData) {
    capacity = initialData.length();
    length = 0;
    data = new std::string[capacity];
  }

  int getLength() { return length; }

  int getCapacity() { return capacity; }

  std::string charAt(int index) { return data[index]; }

  void expandCapacity(int minimumCapacity) {
    std::string *newArray;
    int newCapacity = (length + 1) * 2;

    if (minimumCapacity > newCapacity) {
      newCapacity = minimumCapacity;
    }

    newArray = new std::string[newCapacity];

    for (int i = 0; i < length; i++) {
      newArray[i] = data[i];
    }
    data = newArray;
  }

  void append(std::string value) {
    int remainingCapacity = capacity - length;

    if (remainingCapacity < value.length()) {
    }
  }

  void insert(int offset, std::string value) {}

  void ensureCapacity() {
    // todo
  }

  void setLength(int newLength) {}

  void setCharAt() {}

  void getChars() {}

  void replace(int startIndex, int endIndex, std::string value) {}

  void deleteSequence(int startIndex, int endIndex) {}

  void reverse() {}

  void substring(int beginIndex) {}

  void substring(int beginIndex, int endIndex) {}
};