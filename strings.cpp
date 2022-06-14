#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

#define CONFIG_DEFAULT_SIZE 10
#define CONFIG_RESIZING_FACTOR 2

class ArrayList {
  static const int DEFAULT_SIZE = 10;
  static const int RESIZING_FACTOR = 2;

  std::string *data;
  int arraySize;
  int arrayLength;

public:
  ArrayList() {
    arraySize = DEFAULT_SIZE;
    arrayLength = 0;
    data = new std::string[arraySize];
  }

  std::string *getData() { return data; }

  int getLength() { return arrayLength; }

  int getSize() { return arraySize; }

  void add(std::string value) {
    if (arrayLength == arraySize) {
      int newSize = arraySize * RESIZING_FACTOR;
      arraySize = newSize;

      std::string *newArray;
      newArray = new std::string[newSize];
      for (int i = 0; i < arrayLength; i++) {
        newArray[i] = data[i];
      }
      data = newArray;
    }

    data[arrayLength] = value;
    arrayLength++;
  }

  void printArray() {
    std::cout << "printing array:";

    for (int i = 0;i < 20;i++) {
      std::cout << data[i] << "\n";
    }
  }

  void printMyArray(std::string arr[]) {
    std::cout << "printing my array:";

    for (int i = 0;i < 20;i++) {
      std::cout << arr[i] << "\n";
    }
  }

  // void resizeArray() {

  // }

  // void set(int index, std::string value) {
  //   if (index > arraySize - 1) {
  //     std::cout << "Invalid array position given";
  //     return;
  //   }
  //   data[index] = value;
  //   return;
  // }

  // void remove(int index) {
  //   if (index < 0 || index > arraySize - 1) {
  //     std::cout << "Invalid array position given";
  //     return;
  //   }
  //   std::string *newArray[arraySize];
  //   for (int i = 0; i < arrayLength; i++) {
  //     newArray[i] = &data[i];
  //   }
  // }

  // void clear() {
  //   // std::string *newArray[DEFAULT_SIZE];
  //   // data = newArray;
  //   data = nullptr;
  //   data = new std::string[DEFAULT_SIZE];
  // }
};

TEST_CASE("ArrayList") {
  ArrayList al;

  REQUIRE(al.getSize() == 10);
  REQUIRE(al.getLength() == 0);

  SUBCASE("Adding items") {
    SUBCASE("When adding items beyond default length, it automatically doubles "
            "in size") {
      al.add("one");
      al.add("two");
      al.add("three");
      al.add("four");
      al.add("five");

      al.add("six");
      al.add("seven");
      al.add("eight");
      al.add("nine");
      al.add("ten");
      al.add("eleven");
      al.add("twelve");

      CHECK(al.getSize() == 20);
      CHECK(al.getLength() == 12);
      CHECK(al.getData()[11] == "twelve");
    }
  }
}
