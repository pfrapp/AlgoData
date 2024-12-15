#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

#include "array.h"
#include "radixsort.h"

using namespace std;

#define N   (20)

int integer_key(int& v, int i)
{
    int a = pow(10, i+1);
    int b = pow(10, i);
    int foo = (v % a) / b;
    return foo;
}

int main()
{
    // Generate array with random floats between 0.0 and 1.0
    Array<int> my_array(N);
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<int> dis(0, 9999);
    for(int i = 0; i < N; i++)
    {
        my_array.push_back(dis(gen));
    }

    // Sort and print
    cout << my_array << endl;
    radixsort<int>(my_array, 4, 10, integer_key);
    cout << my_array << endl;
}