#include "Reverser.h"
#include <string>
#include <iostream>

int main(){

    Reverser rev;

    std::string test = rev.reverseString("Hello");

    std::cout << test << std::endl;

    Reverser rev1;

    int test1 = rev1.reverseDigit(4321);

    std::cout<< test1 << std::endl;

    return 0;
}