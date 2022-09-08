#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stdexcept>
#include "hashmap.h"

#define CONFIG_DEFAULT_SIZE 10
#define CONFIG_RESIZING_FACTOR 2

class Person : public IPerson {
public:
  std::string name;
  int age;
  Person(std::string _name, int _age) {
    age = _age;
    name = _name;
  }
  std::string getName() {
    return name;
  }
  int getAge() {
    return age;
  }
};

class Item : public IItem {
public:
  std::string key;
  Person person;

  Item(void);
  Item(std::string _key, std::string name, int age) : person(name, age) {
    key = _key;
    // person = new Person(name, age);
    return;
  }
};

class HashMap : IHashMap {
  static const int ARRAY_SIZE = 1000;
  static const int RESIZING_FACTOR = 2;

  Item data[ARRAY_SIZE];

public:
  HashMap() : data() {
    // arraySize = DEFAULT_SIZE;
    // arrayLength = 0;
    // data = new std::string[arraySize];
  }

  void insert(std::string key, Person value) {
    std::cout << "Testing..." << "\n";
  }

  int hashFunction(std::string value) {
    std::cout << "Testing..." << "\n";
    return 0;
  }

  void find(std::string key) {
    std::cout << "Testing..." << "\n";
  }

  void test() {
    std::cout << "Testing..." << "\n";
  }
};

TEST_CASE("HashMap") {

  SUBCASE("test") {
    HashMap hs;
    hs.test();
    REQUIRE(10 == 10);
  }
}

// TEST_CASE("ArrayList") {
//   ArrayList al;

//   REQUIRE(al.getSize() == 10);
//   REQUIRE(al.getLength() == 0);

//   SUBCASE("Adding items") {
//     SUBCASE("When adding items beyond default length, it automatically doubles "
//             "in size") {
//       al.add("one");
//       al.add("two");
//       al.add("three");
//       al.add("four");
//       al.add("five");
//       al.add("six");
//       al.add("seven");
//       al.add("eight");
//       al.add("nine");
//       al.add("ten");
//       al.add("eleven");
//       al.add("twelve");

//       CHECK(al.getSize() == 20);
//       CHECK(al.getLength() == 12);
//       CHECK(al.getData()[11] == "twelve");
//     }
//     SUBCASE("When adding item to the middle of a full array, resizes and "
//             "reorganizes properly") {
//       al.add("one");
//       al.add("two");
//       al.add("three");
//       al.add("four");
//       al.add("five");
//       al.add("six");
//       al.add("seven");
//       al.add("eight");
//       al.add("nine");
//       al.add("ten");

//       al.add(5, "new");

//       CHECK(al.getSize() == 20);
//       CHECK(al.getLength() == 11);
//       CHECK(al.getData()[5] == "new");
//     }
//     SUBCASE(
//         "When adding item to the middle of an array, reorganizes properly") {
//       al.add("one");
//       al.add("two");
//       al.add("three");
//       al.add("four");

//       al.add(2, "new");

//       CHECK(al.getSize() == 10);
//       CHECK(al.getLength() == 5);
//       CHECK(al.getData()[2] == "new");
//     }
//     SUBCASE("When attempting to add item to invalid index, throws exception") {
//       CHECK_THROWS_AS(al.add(-5, "new"), std::invalid_argument);
//     }
//   }
//   SUBCASE("Setting items") {
//     SUBCASE("When setting a valid index, it replaces the value") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       al.set(1, "new");

//       CHECK(al.get(1) == "new");
//     }
//     SUBCASE("When setting an invalid index, logs an error and doesn't change "
//             "anything") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       CHECK_THROWS_AS(al.set(8, "new"), std::invalid_argument);
//     }
//   }
//   SUBCASE("Removing items") {
//     SUBCASE("When removing a valid index, it removes the value") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       al.remove(1);

//       CHECK(al.get(1) == "three");
//       CHECK(al.getLength() == 2);
//       CHECK(al.getSize() == 10);
//     }
//     SUBCASE("When removing an invalid index, it logs an error and doesn't "
//             "change anything") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       CHECK_THROWS_AS(al.remove(8), std::invalid_argument);
//     }
//   }
//   SUBCASE("Clearing items") {
//     SUBCASE("When array is valid, calling clear wipes it out") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       al.clear();

//       CHECK(al.get(1) == "");
//       CHECK(al.getLength() == 0);
//       CHECK(al.getSize() == 10);
//     }
//   }
//   SUBCASE("Finding items") {
//     SUBCASE("When value exists in array, finds it") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       CHECK(al.find("three") == 2);
//       CHECK(al.getLength() == 3);
//       CHECK(al.getSize() == 10);
//     }
//     SUBCASE("When value does not exist in array, returns -1") {
//       al.add("one");
//       al.add("two");
//       al.add("three");

//       CHECK(al.find("abc") == -1);
//       CHECK(al.getLength() == 3);
//       CHECK(al.getSize() == 10);
//     }
//   }
// }
