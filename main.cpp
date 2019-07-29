#include <iostream>

#include "PrinterTester.h"
#include "CTorCheckTester.h"

int main() {
  std::cout << "CCTorCheck" << std::endl;
  test_CPrinter();
  test_CCTorCheck();
  test_operator();
  return 0;
}