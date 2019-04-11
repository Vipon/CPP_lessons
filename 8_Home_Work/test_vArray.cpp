#include "vArray.h"
#include <cstdlib>
#include <iostream>

void testing_of_constructor_of_copy(vArray<int> arr)
{
    int a[3] = {};
    vArray<int> arr1(a, 3);
    arr = arr1;
    std::cout <<"arr =  " << arr << std::endl; 
}

int main()
{
    int a[3] = {1,2,3};
    vArray<int> arr1(a, 3);
    std::cout <<"arr1 = " << arr1 << std::endl;
    testing_of_constructor_of_copy(arr1);
    std::cout <<"arr1 = " << arr1 << std::endl;
    a[2] = 4;
    vArray<int> arr2(a, 3);
    std::cout <<"arr2 = " << arr2 << std::endl;
    std::cout <<"arr1[3] = " << arr1[3] << std::endl;
    arr2 = arr1;
    std::cout <<"After arr2 = arr1:" << std::endl;
    std::cout <<"arr1 = " << arr1 << std::endl;
    std::cout <<"arr2 = " << arr2 << std::endl;
    arr2 += arr1;
    std::cout <<"After arr2 += arr1:" << std::endl;
    std::cout <<"arr1 = " << arr1 << std::endl;
    std::cout <<"arr2 = " << arr2 << std::endl;
    arr1 = arr1 + arr2;
    std::cout <<"After arr1 = arr1 + arr2:" << std::endl;
    std::cout <<"arr1 = " << arr1 << std::endl;
    std::cout <<"arr2 = " << arr2 << std::endl;
    std::cout <<"arr1 + arr2 = " << arr1 + arr2 << std::endl;
    std::cout <<"Enter array b:" << std::endl;
    vArray<int> b(3);
    std::cin >> b;
    std::cout <<"b = " << b << std::endl;
    std::cout <<"b[0] = " << b[0] << std::endl;
    std::cout <<"b[1] = " << b[1] << std::endl;
    std::cout <<"b[2] = " << b[2] << std::endl;
    return 0;
}