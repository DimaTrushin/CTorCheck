#include "CTorCheckTester.h"
#include "TestClass.h"

#include <vector>
#include <algorithm>

void test_vector();

TestClass funcVal(TestClass);
TestClass funcRef(const TestClass&);

void test_CCTorCheck() {

  // See test_vector description first!
  test_vector();

  // We can safely count the amount of constructors 
  // and assignments for any amount of classes
  auto DefCtorAnch = TestClass::countDefaultCTors();
  auto CopyCtorAnch = TestClass::countCopyCTors();
  auto MoveCtorAnch = TestClass::countMoveCTors();
  auto CopyAsgnmtAnch = TestClass::countCopyAsgnmts();
  auto MoveAsgnmtAnch = TestClass::countMoveAsgnmts();
  auto DestrTorAnch = TestClass::countDestructors();
  
  auto DefCtorAnch2 = TestClass2::countDefaultCTors();
  auto CopyCtorAnch2 = TestClass2::countCopyCTors();
  auto MoveCtorAnch2 = TestClass2::countMoveCTors();
  auto CopyAsgnmtAnch2 = TestClass2::countCopyAsgnmts();
  auto MoveAsgnmtAnch2 = TestClass2::countMoveAsgnmts();
  auto DestrTorAnch2 = TestClass2::countDestructors();

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

  TestClass2 b0;
  TestClass2 b1(b0);
  TestClass2 b2 = b0;
  TestClass2 b3{};
  TestClass2 b4{ b0 };
  TestClass2 b5 = {};
  TestClass2 b6 = { b0 };
  TestClass2 b7(std::move(b0));
  TestClass2 b8 = std::move(b0);
  TestClass2 b9 = { std::move(b0) };

}

void test_vector() {
  // Count amount of all constructors for TestClass
  // we need the anchor object DefCtorAnch to control
  // how long we want to count
  // We count from here until DefCtorAnch is destroyed
  // In this particular example, we count until the end
  // of the scope
  auto DefCtorAnch = TestClass::countDefaultCTors();
  // Count amount of all copy constructors for TestClass
  auto CopyCtorAnch = TestClass::countCopyCTors();
  // Count amount of all move constructors for TestClass
  auto MoveCtorAnch = TestClass::countMoveCTors();
  // Count amount of all copy assignments for TestClass
  auto CopyAsgnmtAnch = TestClass::countCopyAsgnmts();
  // Count amount of all move assignments for TestClass
  auto MoveAsgnmtAnch = TestClass::countMoveAsgnmts();
  // Count amount of all destructors for TestClass
  auto DestrTorAnch = TestClass::countDestructors();

  // block with "Vector Test" message begins
  // all messages from constructors and assignment operators
  // inside this block will be indented properly
  auto VecPushAnch = TestClass::CPrinter::print("Vector Test");
  using VectorTest = std::vector<TestClass>;
  VectorTest MyVector;
  MyVector.reserve(5);
  MyVector.push_back(TestClass());
  MyVector.emplace_back();
  MyVector.push_back(TestClass());
  MyVector.emplace_back();
  MyVector.push_back(TestClass());
  VecPushAnch.release();
  // block with "Vector Test" message ends


  // block with "Vector reverse" message begins
  // all messages from constructors and assignment operators
  // inside this block will be indented properly
  auto VecReverseAnch = TestClass::CPrinter::print("Vector reverse");
  std::reverse(MyVector.begin(), MyVector.end());
  VecReverseAnch.release();
  // block with "Vector reverse" message ends

  // block with "funcVal" message begins
  // all messages from constructors and assignment operators
  // inside this block will be indented properly
  auto FuncValAnch = TestClass::CPrinter::print("funcVal");
  TestClass var = funcVal(TestClass());
  FuncValAnch.release();
  // block with "funcVal" message ends

  // block with "funcRef" message begins
  // all messages from constructors and assignment operators
  // inside this block will be indented properly
  auto FuncRefAnch = TestClass::CPrinter::print("funcRef");
  TestClass var2 = funcRef(var);
  FuncRefAnch.release();
  // block with "funcRef" message ends
}

TestClass funcVal(TestClass arg) {
  return arg;
}

TestClass funcRef(const TestClass& arg) {
  return arg;
}

void test_operator() {
  // We can safely count the amount of constructors 
  // and assignments for any amount of classes
  auto DefCtorAnch = TestClass::countDefaultCTors();
  auto CopyCtorAnch = TestClass::countCopyCTors();
  auto MoveCtorAnch = TestClass::countMoveCTors();
  auto CopyAsgnmtAnch = TestClass::countCopyAsgnmts();
  auto MoveAsgnmtAnch = TestClass::countMoveAsgnmts();
  auto DestrTorAnch = TestClass::countDestructors();
  TestClass arg0;
  TestClass arg1(1);
  TestClass arg2(2);
  std::cout << "arg0 = " << arg0.value()
    << " arg1 = " << arg1.value()
    << " arg2 = " << arg2.value()
    << std::endl;
  {
    auto OperatorAnch = TestClass::CPrinter::print("operator+");
    TestClass result = arg0 + arg1;
    std::cout << "arg0 = " << arg0.value()
      << " arg1 = " << arg1.value()
      << " arg2 = " << arg2.value()
      << " result = " << result.value()
      << std::endl;
    //OperatorAnch.release();
  }
}