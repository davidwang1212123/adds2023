#include "Reverser.h"
#include <string>
#include <iostream>

Reverser::Reverser()
{}

std::string Reverser::reverseString(std::string str)
{
    if (str.length()==1)
        return str;
    
    char last_char = str.back();
    std::string remaining_str = str.substr(0, str.length()-1);
    return last_char + reverseString(remaining_str);
}

int Reverser::reverseDigit(int digit)
{
    if (digit<10)
        return digit;

    int lastDigit = digit % 10; 
    int rem_digit = digit / 10;

    while (rem_digit>0)
    {
        rem_digit /= 10;
        lastDigit *= 10;
    }
    
    return lastDigit + reverseDigit(digit/10);
}

int main(){

    Reverser rev;

    std::string test = rev.reverseString("Hello");

    std::cout << test << std::endl;

    Reverser rev1;

    int test1 = rev1.reverseDigit(4321);

    std::cout<< test1 << std::endl;

    return 0;
}