#include "new_vArray.h"
#include <cstdlib>
#include <iostream>

void testing_of_constructor_of_copy(vArray<int> arr)
{
    arr[0] = 1234;
}

int main()//!!!!!!Нужно проверить итератор, push_back, push_forward
{
    int a[3] = {1,2,3};
    vArray<int> arr1(a, 3);
    std::cout <<"arr1 = " << arr1 << std::endl;
    testing_of_constructor_of_copy(arr1);
    std::cout <<"After testing_of_constructor_of_copy" << std::endl;
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
    vArray<int> arr3(a, 3);
    int c[3] = {4,5,6};
    vArray<int> arr4(c, 3);
    std::cout <<"arr3 = " << arr3 << std::endl;
    std::cout <<"arr4 = " << arr4 << std::endl;
    arr3.push_forward(4);
    std::cout <<"After arr3.push_forward(4):" << std::endl;
    std::cout <<"arr3 = " << arr3 << std::endl;
    arr3.push_back(5);
    std::cout <<"After arr3.push_back(5):" << std::endl;
    std::cout <<"arr3 = " << arr3 << std::endl;
    arr3.push_forward(arr4);
    std::cout <<"After arr3.push_forward(arr4):" << std::endl;
    std::cout <<"arr3 = " << arr3 << std::endl;
    arr3.push_back(arr4);
    std::cout <<"After arr3.push_back(arr4):" << std::endl;
    std::cout <<"arr3 = " << arr3 << std::endl;
    std::cout <<"arr4 = " << arr4 << std::endl;
    std::cout <<"Enter array b:" << std::endl;
    int l[5] = {};
    vArray<int> b(l, 5);
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
    int d = 0;
    while (d != 1234)
    {
        std::cout <<"Enter date you want to find or write 1234 to finish:" << std::endl;
        std::cin >> d;
        std::cout <<"Number of that element is" << b.find(d) << std::endl;
    }
    return 0;
}