#include "TestClass.h"

TestClass::TestClass(int value) : value_(value) {
}

int TestClass::value() const {
  return value_;
}

TestClass& TestClass::operator+=(const TestClass& other) {
  value_ += other.value_;
  return *this;
}


TestClass operator+(const TestClass& lhs, const TestClass& rhs) {
  TestClass result(lhs);
  result += rhs;
  return result;
}