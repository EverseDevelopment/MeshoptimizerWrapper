
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "json_fixture.h"
#include "unittest_core.h"


int main(int argc, char **argv) {

  std::cout << "Executing tests\n";


  unittest_core::configuration_json["file_name"] = "file.json";
  unittest_core::configuration_json["counter"] =  2;

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
