#include <list>
#include <string>
#include <iostream>
#include "BigNumCalc.h"
using namespace std;

BigNumCalc::BigNumCalc()
{
}

BigNumCalc::~BigNumCalc()
{
}

list<int> BigNumCalc::buildBigNum(string numString)
{
  list<int> result;
  bool leadingZero = true;
  int digit;

  // check parameter
  if (numString.length() == 0)
  {
    cout << "numString cannot be empty for buildBigNum method." << endl;
    return result;
  }

  for (int i = 0; i < numString.length(); i++)
  {
    // check digit, if it is leading zero, skip
    digit = stoi(numString.substr(i, 1));
    if (digit == 0)
    {
      if (leadingZero)
        continue;
    }
    else
      leadingZero = false;

    result.push_back(digit);
  }

  // handle "000" type of cases
  if (result.size() == 0)
    result.push_back(0);

  return result;
}

list<int> BigNumCalc::add(list<int> num1, list<int> num2)
{
  list<int> result;

  int num1Size = num1.size();
  int num2Size = num2.size();

  // check parameters
  if (num1Size == 0)
  {
    cout << "num1 cannot be empty for add method." << endl;
    return result;
  }

  if (num2Size == 0)
  {
    cout << "num2 cannot be empty for add method." << endl;
    return result;
  }

  // make num1 and num2 size identical
  if (num1Size > num2Size)
  {
    // insert leading zeros to num2
    for (int i = 0; i < num1Size - num2Size; i++)
      num2.push_front(0);
  }
  else if (num1Size < num2Size)
  {
    // insert leading zeros to num1
    for (int i = 0; i < num2Size - num1Size; i++)
      num1.push_front(0);
  }

  // performance calculation from the back of the list
  list<int>::const_reverse_iterator itr1 = num1.crbegin();
  list<int>::const_reverse_iterator itr2 = num2.crbegin();
  int n1, n2, n3, stepDigit = 0;

  while (true)
  {
    if (itr1 == num1.crend())
    {
      // if there is step digit, push it
      if (stepDigit == 1)
        result.push_front(stepDigit);

      break;
    }

    n1 = *itr1;
    n2 = *itr2;
    n3 = n1 + n2 + stepDigit;

    if (n3 >= 10)
    {
      // there is a step digit
      result.push_front(n3 - 10);
      stepDigit = 1;
    }
    else
    {
      // there is no step digit
      result.push_front(n3);
      stepDigit = 0;
    }

    itr1++;
    itr2++;
  }

  // filter out leading zero
  while ((result.front() == 0) && (result.size() > 1))
  {
    result.pop_front();
  }

  return result;
}

list<int> BigNumCalc::sub(list<int> num1, list<int> num2)
{
  list<int> result;

  int num1Size = num1.size();
  int num2Size = num2.size();

  // check parameters

  if (num1Size == 0)
  {
    cout << "num1 cannot be empty for sub method." << endl;
    return result;
  }

  if (num2Size == 0)
  {
    cout << "num2 cannot be empty for sub method." << endl;
    return result;
  }

  // make num1 and num2 size identical
  if (num1Size > num2Size)
  {
    // insert leading zeros to num2
    for (int i = 0; i < num1Size - num2Size; i++)
      num2.push_front(0);
  }
  else if (num1Size < num2Size)
  {
    // invalid data
    cout << "num1 cannot be less than num2 for sub method." << endl;
    return result;
  }

  list<int>::const_reverse_iterator itr1 = num1.crbegin();
  list<int>::const_reverse_iterator itr2 = num2.crbegin();
  int n1, n2, n3, stepDigit = 0;
  bool errorCondition = false;

  while (true)
  {
    if (itr1 == num1.crend())
    {
      // given num1 >= num2, there should not be a step digit at last
      if (stepDigit == 1)
      {
        cout << "num1 cannot be less than num2 for sub method" << endl;
        errorCondition = true;
      }

      break;
    }

    n1 = *itr1;
    n2 = *itr2;
    n3 = n1 - n2 - stepDigit;

    if (n3 < 0)
    {
      result.push_front(n3 + 10);
      stepDigit = 1;
    }
    else
    {
      result.push_front(n3);
      stepDigit = 0;
    }

    itr1++;
    itr2++;
  }

  if (errorCondition)
    result.clear(); // something is wrong, clear existing data members
  else
  {
    // filter out leading zero
    while ((result.front() == 0) && (result.size() > 1))
    {
      result.pop_front();
    }
  }

  return result;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2)
{
  list<int> result;

  int num1Size = num1.size();
  int num2Size = num2.size();

  // check parameters

  if (num1Size == 0)
  {
    cout << "num1 cannot be empty for mul method." << endl;
    return result;
  }

  if (num2Size == 0)
  {
    cout << "num2 cannot be empty for mul method." << endl;
    return result;
  }

  if (num2Size > 1)
  {
    cout << "num2 cannot have more than 1 digit for mul method." << endl;
    return result;
  }

  list<int>::const_reverse_iterator itr1 = num1.crbegin();

  int n1, n3, stepDigit = 0;
  int n2 = num2.back(); // assume num2 has only 1 digit

  while (true)
  {
    if (itr1 == num1.crend())
    {
      // handle the step digit at last
      if (stepDigit > 0)
        result.push_front(stepDigit);

      break;
    }

    n1 = *itr1;
    n3 = n1 * n2 + stepDigit;

    if (n3 >= 10)
    {
      // handle the step digit
      result.push_front(n3 % 10);
      stepDigit = n3 / 10;
    }
    else
    {
      result.push_front(n3);
      stepDigit = 0;
    }

    itr1++;
  }

  // filter out leading zero
  while ((result.front() == 0) && (result.size() > 1))
  {
    result.pop_front();
  }

  return result;
 }

