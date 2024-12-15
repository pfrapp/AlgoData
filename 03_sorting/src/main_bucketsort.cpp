#include <iostream>
#include <iomanip>
#include <random>

#include "array.h"
#include "bucketsort.h"

using namespace std;

#define N   (20)

int main()
{
    // Generate array with random floats between 0.0 and 1.0
    Array<double> my_array(N);
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> dis(0.0, 1.0);    
    for(int i = 0; i < N; i++)
    {
        my_array.push_back(dis(gen));
    }

    // Sort and print
    bucketsort(my_array, 0.0, 1.0, 5);
    cout << setprecision(2) << my_array << endl;
}