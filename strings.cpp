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

  std::string *resizeArray(int newSize) {
    std::string *newArray;
    newArray = new std::string[newSize];
    for (int i = 0; i < arrayLength; i++) {
      newArray[i] = data[i];
    }
    return newArray;
  }

  std::string get(int index) {
    if (index < 0 || index > arraySize - 1) {
      std::cout << "Error - invalid index requested.";
      return "Error - invalid index requested.";
    }
    return data[index];
  }

  void add(std::string value) {
    if (arrayLength == arraySize) {
      int newSize = arraySize * RESIZING_FACTOR;
      arraySize = newSize;
      data = resizeArray(newSize);
    }

    data[arrayLength] = value;
    arrayLength++;
  }

  void printArray() {
    std::cout << "Printing array:";

    for (int i = 0; i < 20; i++) {
      if (data[i] == "") {
        break;
      }
      std::cout << data[i] << "\n";
    }
  }

  void set(int index, std::string value) {
    if (index > arrayLength - 1) {
      std::cout << "Invalid array position given\n";
      return;
    }
    data[index] = value;
    return;
  }

  void remove(int index) {
    if (index < 0 || index > arrayLength - 1) {
      std::cout << "Invalid array position given\n";
      return;
    }

    std::string *newArray;
    newArray = new std::string[arraySize];
    for (int i = 0; i < arrayLength; i++) {
      int adjustedIndex;

      if (i == index) {
        continue;
      } else if (i > index) {
        adjustedIndex = i - 1;
      } else {
        adjustedIndex = i;
      }
      newArray[adjustedIndex] = data[i];
    }
    data = newArray;
    arrayLength--;
  }

  void clear() {
    data = nullptr;
    data = new std::string[DEFAULT_SIZE];
    arrayLength = 0;
    arraySize = DEFAULT_SIZE;
  }
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

      al.printArray();
    }
  }
  SUBCASE("Setting items") {
    SUBCASE("When setting a valid index, it replaces the value") {
      al.add("one");
      al.add("two");
      al.add("three");

      al.set(1, "new");

      CHECK(al.get(1) == "new");
    }
    SUBCASE("When setting an invalid index, logs an error and doesn't change "
            "anything") {
      al.add("one");
      al.add("two");
      al.add("three");

      al.set(8, "new");

      CHECK(al.get(8) != "new");
      CHECK(al.get(8) == "");
    }
  }
  SUBCASE("Removing items") {
    SUBCASE("When removing a valid index, it removes the value") {
      al.add("one");
      al.add("two");
      al.add("three");

      al.remove(1);

      CHECK(al.get(1) == "three");
      CHECK(al.getLength() == 2);
      CHECK(al.getSize() == 10);
    }
    SUBCASE("When removing an invalid index, it logs an error and doesn't "
            "change anything") {
      al.add("one");
      al.add("two");
      al.add("three");

      al.remove(8);

      CHECK(al.get(1) == "two");
      CHECK(al.getLength() == 3);
      CHECK(al.getSize() == 10);
    }
  }
  SUBCASE("Clearing items") {
    SUBCASE("When array is valid, calling clear wipes it out") {
      al.add("one");
      al.add("two");
      al.add("three");

      al.clear();

      CHECK(al.get(1) == "");
      CHECK(al.getLength() == 0);
      CHECK(al.getSize() == 10);
    }
  }
}
