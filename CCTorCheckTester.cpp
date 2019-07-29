#include "CTorCheckTester.h"
#include "TestClass.h"

#include <vector>
#include <algorithm>

void test_vector();

TestClass funcVal(TestClass);
TestClass funcRef(const TestClass&);

void test_CCTorCheck() {
  //auto DefCtorAnch = TestClass::countDefaultCTors();
  //auto CopyCtorAnch = TestClass::countCopyCTors();
  //auto MoveCtorAnch = TestClass::countMoveCTors();
  //auto CopyAsgnmtAnch = TestClass::countCopyAsgnmts();
  //auto MoveAsgnmtAnch = TestClass::countMoveAsgnmts();

  TestClass a0;
  TestClass a1(a0);
  TestClass a2 = a0;
  TestClass a3{};
  TestClass a4{a0};
  TestClass a5 = {};
  TestClass a6 = { a0 };
  TestClass a7(std::move(a0));
  TestClass a8 = std::move(a0);
  TestClass a9 = { std::move(a0) };

  test_vector();

}

void test_vector() {
  auto DefCtorAnch = TestClass::countDefaultCTors();
  auto CopyCtorAnch = TestClass::countCopyCTors();
  auto MoveCtorAnch = TestClass::countMoveCTors();
  auto CopyAsgnmtAnch = TestClass::countCopyAsgnmts();
  auto MoveAsgnmtAnch = TestClass::countMoveAsgnmts();
 
  auto VecPushAnch = TestClass::CPrinter::print("Vector Test");
  using VectorTest = std::vector<TestClass>;
  VectorTest MyVector;
  MyVector.reserve(5);
  MyVector.push_back(TestClass());
  MyVector.emplace_back(TestClass());
  MyVector.push_back(TestClass());
  MyVector.emplace_back(TestClass());
  MyVector.push_back(TestClass());
  VecPushAnch.release();

  auto VecReverseAnch = TestClass::CPrinter::print("Vector reverse");
  std::reverse(MyVector.begin(), MyVector.end());
  VecReverseAnch.release();

  auto FuncValAnch = TestClass::CPrinter::print("funcVal");
  TestClass var = funcVal(TestClass());
  FuncValAnch.release();

  auto FuncRefAnch = TestClass::CPrinter::print("funcRef");
  TestClass var2 = funcRef(var);
  FuncRefAnch.release();
}

TestClass funcVal(TestClass arg) {
  return arg;
}

TestClass funcRef(const TestClass& arg) {
  return arg;
}
