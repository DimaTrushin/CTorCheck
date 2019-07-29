#pragma once
#include "CTorCheck.h"

class TestClass : public NSLibrary::CCTorCheck<TestClass, NSLibrary::CArticulateMode> {
public:
  TestClass() = default;
  TestClass(int);

  int value() const;

  TestClass& operator+=(const TestClass&);
  friend TestClass operator+(const TestClass&, const TestClass&);
private:
  int value_ = 0;
};

class TestClass2 : public NSLibrary::CCTorCheck<TestClass2, NSLibrary::CArticulateMode> {
};
