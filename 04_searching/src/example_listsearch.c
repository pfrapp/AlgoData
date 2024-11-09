#include <stdio.h>
#include "listsearch.h"


int main()
{
    char singlton_array[]   = {'d'};
    char uniform_array[]    = {'a','b','c','d','e','f','g','h','i'};
    char nonuniform_array[] = {'a','a','a','a','a','a','a','d','i'};
    
    printf("BINARY SEARCH\n");    
    printf("Not found: %i\n", binary_search(nonuniform_array, 0, 8, 'x'));
    printf("Singleton array: %i\n", binary_search(singlton_array, 0, 1, 'd'));
    printf("Uniform array: %i\n", binary_search(uniform_array, 0, 8, 'd'));
    printf("Non-uniform array: %i\n\n", binary_search(nonuniform_array, 0, 8, 'd'));
    
    printf("INTERPOLATION SEARCH\n");
    printf("Not found: %i\n", interpolation_search(nonuniform_array, 0, 8, 'x'));
    printf("Singleton array: %i\n", interpolation_search(singlton_array, 0, 1, 'd'));
    printf("Uniform array: %i\n", interpolation_search(uniform_array, 0, 8, 'd'));
    printf("Non-uniform array: %i\n\n", interpolation_search(nonuniform_array, 0, 8, 'd'));

    printf("EXPONENTIAL SEARCH\n");   
    printf("Not found: %i\n", exponential_search(nonuniform_array, 0, 8, 'x'));
    printf("Singleton array: %i\n", exponential_search(singlton_array, 0, 1, 'd'));
    printf("Uniform array: %i\n", exponential_search(uniform_array, 0, 8, 'd'));
    printf("Non-uniform array: %i\n", exponential_search(nonuniform_array, 0, 8, 'd'));

    return 0;
}