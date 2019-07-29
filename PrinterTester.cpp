#include "PrinterTester.h"

void test_CPrinter() {
  namespace lib = NSLibrary;
  std::cout << "test_CPrinter" << std::endl;

  using Printer = lib::CPrinter<>;
  Printer::print("first msg");
  auto anchor1 = Printer::print("second msg");
  auto anchor2 = Printer::print("third msg");
  anchor1.release();
  anchor1.release();
}