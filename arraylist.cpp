#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stdexcept>

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

  void validateIndex(int index) {
    if (index < 0 || index > arraySize - 1) {
      throw std::invalid_argument("Error - invalid index requested.");
    }
  }

  // also prevents index higher than current arrayLength
  void validateIndexStrict(int index) {
    validateIndex(index);
    if (index > arrayLength - 1) {
      throw std::invalid_argument("Error - invalid index requested.");
    }
  }

  std::string *resizeArray(std::string *originalArray, int newSize) {
    std::string *newArray;
    newArray = new std::string[newSize];
    for (int i = 0; i < arrayLength; i++) {
      newArray[i] = originalArray[i];
    }
    return newArray;
  }

  std::string *copyAndResizeArray(std::string *array) {
    int newSize = arraySize * RESIZING_FACTOR;
    arraySize = newSize;
    return resizeArray(array, newSize);
  }

  std::string get(int index) {
    validateIndex(index);
    return data[index];
  }

  void add(std::string value) {
    if (arrayLength == arraySize) {
      data = copyAndResizeArray(data);
    }

    data[arrayLength] = value;
    arrayLength++;
  }

  void add(int index, std::string value) {
    validateIndex(index);

    std::string *newArray;
    if (arrayLength == arraySize) {
      newArray = copyAndResizeArray(data);
    } else {
      newArray = new std::string[arraySize];
    }

    for (int i = 0; i < arrayLength; i++) {
      if (i == index) {
        newArray[i + 1] = data[i];
        newArray[i] = value;
      } else if (i > index) {
        newArray[i + 1] = data[i];
      } else {
        newArray[i] = data[i];
      }
    }
    data = newArray;
    arrayLength++;
  }

  void printArray() {
    std::cout << "Printing array:";

    for (int i = 0; i < arrayLength; i++) {
      std::cout << data[i] << "\n";
    }
  }

  void set(int index, std::string value) {
    validateIndexStrict(index);
    data[index] = value;
    return;
  }

  void remove(int index) {
    validateIndexStrict(index);

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

  int find(std::string value) {
    for (int i = 0; i < arrayLength; i++) {
      if (data[i] == value) {
        return i;
      }
    }
    return -1;
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
    }
    SUBCASE("When adding item to the middle of a full array, resizes and "
            "reorganizes properly") {
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

      al.add(5, "new");

      CHECK(al.getSize() == 20);
      CHECK(al.getLength() == 11);
      CHECK(al.getData()[5] == "new");
    }
    SUBCASE(
        "When adding item to the middle of an array, reorganizes properly") {
      al.add("one");
      al.add("two");
      al.add("three");
      al.add("four");

      al.add(2, "new");

      CHECK(al.getSize() == 10);
      CHECK(al.getLength() == 5);
      CHECK(al.getData()[2] == "new");
    }
    SUBCASE("When attempting to add item to invalid index, throws exception") {
      CHECK_THROWS_AS(al.add(-5, "new"), std::invalid_argument);
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

      CHECK_THROWS_AS(al.set(8, "new"), std::invalid_argument);
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

      CHECK_THROWS_AS(al.remove(8), std::invalid_argument);
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
  SUBCASE("Finding items") {
    SUBCASE("When value exists in array, finds it") {
      al.add("one");
      al.add("two");
      al.add("three");

      CHECK(al.find("three") == 2);
      CHECK(al.getLength() == 3);
      CHECK(al.getSize() == 10);
    }
    SUBCASE("When value does not exist in array, returns -1") {
      al.add("one");
      al.add("two");
      al.add("three");

      CHECK(al.find("abc") == -1);
      CHECK(al.getLength() == 3);
      CHECK(al.getSize() == 10);
    }
  }
}
