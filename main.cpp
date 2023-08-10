#include "Reverser.h"
#include "Truckloads.h"
#include <string>
#include <iostream>

int main(){

    Reverser rev;

    std::string test = rev.reverseString("Hello");

    std::cout << test << std::endl;

    Reverser rev1;

    int test1 = rev1.reverseDigit(4321);

    std::cout<< test1 << std::endl;

    Truckloads tru;

    int test2 = tru.numTrucks(14,3);

    std::cout<< test2 << std::endl;


    return 0;


}