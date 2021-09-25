#include <iostream>
#include "Storage.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>


int main()
{
  std::string str = "foo bar foobar";
  std::istringstream iss(str);
  std::string first_word;
  iss >> first_word;
  std::cout << "first word of '" << str << "' is '" << first_word << "'" << std::endl;

    return 0;
}