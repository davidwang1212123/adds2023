#pragma once
#include <list>
#include <string>
using namespace std;

class bigNumCalc
{
public:
  bigNumCalc();
  ~bigNumCalc();
  list<int> buildBigNum(string numString);
  list<int> add(list<int> num1, list<int> num2);
  list<int> sub(list<int> num1, list<int> num2);
  list<int> mul(list<int> num1, list<int> num2);
};
