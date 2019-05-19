#include "new_Array.h"
#include "Array_exeption.h"
#include <cstdlib>
#include <cstring>
#include <iostream>


void testing_of_constructor_of_copy(Array<int,3> arr)
{ 
    int a[3] = {};
    Array<int,3> arr1(a);
    arr = arr1;
}

int main()
{
    std::cout <<"Testing array:" << std::endl;
    int a[3] = {1,2,3};
    Array<int,3> arr1(a);
    std::cout <<"arr1 = " << arr1 << std::endl;
    a[2] = 4;
    Array<int,3> arr2(a);
    std::cout <<"arr2 = " << arr2 << std::endl;
    arr2 = arr1;
    std::cout <<"After arr2 = arr1:" << std::endl;
    std::cout <<"arr1 = " << arr1 << std::endl;
    std::cout <<"arr2 = " << arr2 << std::endl;
    testing_of_constructor_of_copy(arr1);
    std::cout <<"arr1 = " << arr1 << std::endl;
    
    std::cout <<"Testing of iterator:" << std::endl;
    std::cout <<"arr1 = " <<std::endl;
    for (Array<int,3>::Iterator i = arr1.begin(); i != arr1.end() ; ++i)
    {
        std::cout << *i<<" ";
    }
    std::cout << std::endl;

    std::cout <<"Reversed arr1 = " <<std::endl;
    for (Array<int,3>::Iterator i = --arr1.end(); i != --arr1.begin() ; --i)
    {
        std::cout << *i<<" ";
    }
    std::cout << std::endl;

    std::cout <<"arr1 = " <<std::endl;
    for (Array<int,3>::Iterator i = arr1.begin(); i != arr1.end() ; i++)
    {
        std::cout << *i<<" ";
    }
    std::cout << std::endl;

    std::cout <<"Reversed arr1 = " <<std::endl;
    for (Array<int,3>::Iterator i = --arr1.end(); i != --arr1.begin() ; i--)
    {
        std::cout << *i<<" ";
    }
    std::cout << std::endl;

    std::cout <<"Enter array b:" << std::endl;
    int l[5] = {};
    Array<int,5> b(l);
    std::cin >> b;
    std::cout <<"b = " << b << std::endl;
    std::cout <<"b[0] = " << b[0] << std::endl;
    std::cout <<"b[1] = " << b[1] << std::endl;
    std::cout <<"b[2] = " << b[2] << std::endl;
    std::cout <<"b[3] = " << b[3] << std::endl;
    std::cout <<"b[4] = " << b[4] << std::endl;
    b.qsort(std::less<>());
    std::cout <<"After b.qsort:" << std::endl;
    std::cout <<"b[0] = " << b[0] << std::endl;
    std::cout <<"b[1] = " << b[1] << std::endl;
    std::cout <<"b[2] = " << b[2] << std::endl;
    std::cout <<"b[3] = " << b[3] << std::endl;
    std::cout <<"b[4] = " << b[4] << std::endl;
    int c = 0;
    while (c != 1234)
    {
        std::cout <<"Enter date you want to find or write 1234 to finish:" << std::endl;
        std::cin >> c;
        std::cout <<"Number of that element is" << b.find(c) << std::endl;
    }
    return 0;
}