#include "Truckloads.h"
#include <cmath>

Truckloads::Truckloads()
{

}

int Truckloads::numTrucks(int numCrates, int loadSize) 
{
    if (numCrates<loadSize)
    {
        return 1;
    }

    int pile1 = floor(((float) numCrates)/2);
    int pile2 = ceil(((float) numCrates)/2);

    int numTrucks1 = numTrucks(pile1, loadSize);
    int numTrucks2 = numTrucks(pile2, loadSize);

    return numTrucks1+numTrucks2;
}