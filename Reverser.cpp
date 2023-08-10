#include "Reverser.h"
#include <string>
#include <iostream>

Reverser::Reverser()
{}

std::string Reverser::reverseString(std::string str)
{
    if (str.length()<=1)
        return str;
    
    char last_char = str.back();
    std::string remaining_str = str.substr(0, str.length()-1);
    return last_char + reverseString(remaining_str);
}
 
int Reverser::reverseDigit(int value) 
{
    if (value<10)
        return value;

    int lastDigit = value % 10; 
    int rem_digit = value / 10;

    while (rem_digit>0)
    {
        rem_digit /= 10;
        lastDigit *= 10;
    }
    
    return lastDigit + reverseDigit(value/10);
}

