#include "vArray.h"
#include "Array_exeption.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

void testing_of_constructor_of_copy(vArray<int> arr)
{
    arr[0] = 1234;
}

int main()
{
    try
    {
        vArray<int> arr0;
        std::cout <<"arr0 = " << arr0 << std::endl;
        std::cout <<"arr0.get_size() = " << arr0.get_size() << std::endl;
        arr0.change_size(2);
        arr0[0] = 0;
        arr0[1] = 1;
        std::cout <<"After arr0.change_size(2); arr0[0] = 0; arr0[1] = 1;" << std::endl;
        std::cout <<"arr0 = " << arr0 << std::endl;
        std::cout <<"arr0.get_size() = " << arr0.get_size() << std::endl;
        arr0.push_forward(2);
        std::cout <<"After arr0.push_forward(2):" << std::endl;
        std::cout <<"arr0 = " << arr0 << std::endl;
        arr0.push_back(4);
        std::cout <<"After arr0.push_back(4):" << std::endl;
        std::cout <<"arr0 = " << arr0 << std::endl;
        int a[3] = {1,2,3};
        vArray<int> arr1(a, 3);
        std::cout <<"arr1 = " << arr1 << std::endl;
        arr0.push_forward(arr1);
        std::cout <<"After arr0.push_forward(arr1):" << std::endl;
        std::cout <<"arr0 = " << arr0 << std::endl;
        arr0.push_back(arr1);
        std::cout <<"After arr0.push_back(arr1):" << std::endl;
        std::cout <<"arr0 = " << arr0 << std::endl;
        std::cout <<"arr1 = " << arr1 << std::endl;
        testing_of_constructor_of_copy(arr1);
        std::cout <<"arr1 = " << arr1 << std::endl;
        a[2] = 4;
        vArray<int> arr2(a, 3);
        std::cout <<"arr2 = " << arr2 << std::endl;
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
        int c = 0;
        while (c != 1234)
        {
            std::cout <<"Enter date you want to find or write 1234 to finish:" << std::endl;
            std::cin >> c;
            std::cout <<"Number of that element is" << b.find(c) << std::endl;
        }
        return 0;
    }
    catch(ArrayException& s)
    {
        std::cout << s.what() << std::endl;
    }
}