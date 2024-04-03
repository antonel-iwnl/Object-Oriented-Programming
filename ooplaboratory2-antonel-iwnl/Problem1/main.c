#include <stdio.h>
#include <limits.h>
#include "tests.h"


// Write a function that takes as an input an array of integer numbers (both positive and negative numbers and returns the value of the triplet with the maximum product, as well as the elements that form this triplet (in increasing order). 
// Use pass by pointer/address to return the elements that form that triplet. 
// Think about the appropriate data type for the result. If the size of the array is less than 3, you should return the minimum
// representable value of the data type and the elements that form the triplet should be set to 0.
long long computeMaxTriplet(int arr[], unsigned int sz, int *t1, int* t2, int* t3){
    // TODO your code here
    *t1 = 0;
    *t2 = 0;
    *t3 = 0;
    if (sz < 3)
        return LLONG_MIN;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < sz; i++){
        if (arr[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2){
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
            max3 = arr[i];
        if (arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
            min2 = arr[i];
    }
    long long prod1 = (long long)max1 * max2 * max3;
    long long prod2 = (long long)max1 * min1 * min2;
    if (prod1 > prod2){
        *t1 = max1;
        *t2 = max2;
        *t3 = max3;
        return prod1;
    }
    else{
        *t1 = min1;
        *t2 = min2;
        *t3 = max1;
        return prod2;
    }
}

int main()
{
#if ENABLE_TESTS > 0
    run_tests(true); 
#endif
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int t1, t2, t3;
    // long long res = computeMaxTriplet(arr, 9, &t1, &t2, &t3);
    // printf("The triplet with the maximum product is\n: %d, %d, %d and the product is\n: %lld", t1, t2, t3, res);
    return 0;
}
