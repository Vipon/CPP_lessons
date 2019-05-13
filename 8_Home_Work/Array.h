#ifndef ARRAY
#define ARRAY

#include "Array_exeption.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

template <typename Type, typename Function>
void my_qsort (Type* arr, int b, int e, Function Func);

template <typename Type, size_t size>
class Array
{
public:
    Array() = default;
    Array(const Type arr[size]);//it's more safe, then Type* arr 
    Array(const Array& arr);
    //We don't need in move-constructor, becouse Array can't be rvalue in my realization
    ~Array() = default;
    Type& operator[] (size_t num);
    Array& operator= (const Array& arr);
    size_t find(Type date);
    template <typename Func>
    void qsort(Func f){ my_qsort(array, 0, size - 1, f); };

    template <typename T, size_t s>
    friend std::ostream& operator<<(std::ostream & os, const Array<T,s>& arr);

    template <typename T, size_t s>
    friend std::istream& operator>>(std::istream & os, Array<T,s>& arr);
    //Look at comment in defenition, before using
private:
    Type array[size];
};




template <typename Type, size_t size>
Array<Type,size>::Array(const Type arr[size])
{
    memcpy(array, arr, size * sizeof(Type));
}

template <typename Type, size_t size>
Array<Type,size>::Array(const Array& arr)
{
    memcpy(array, arr.array, size * sizeof(Type));
}

template <typename Type, size_t size>
Type& Array<Type,size>::operator[] (size_t num)
{
    if (num > size - 1)
    {
        throw ArrayException ("Size of array less then argument in []");
    }
    return array[num];
}

template <typename Type, size_t size>
Array<Type,size>& Array<Type,size>::operator= (const Array<Type,size>& arr)
{
    memcpy(array, arr.array, size * sizeof(Type));
    return *this;
}

template <typename Type, size_t size>
size_t Array<Type,size>::find(Type date)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] == date) { return i; };
    }
    return -1; // if there isn't date in array
}


template <typename Type, typename Function>
void my_qsort (Type* arr, int b, int e, Function Func)
{
    int l = b;
    int r = e;
    Type piv = arr[(l + r) / 2];
    while(l <= r)
    {
        while (Func(arr[l], piv)) { l++; };
        while ((!Func(arr[r], piv)) && (arr[r] != piv)) { r--; };
        if (l <= r)
        {
            std::swap (arr[l++], arr[r--]);
        }
    }
    if (b < r) { my_qsort (arr, b, r, Func); };
    if (e > l) { my_qsort (arr, l, e, Func); };
}

template <typename Type, size_t size>
std::ostream& operator<<(std::ostream & os, const Array<Type,size>& arr)
{
    for (size_t i = 0; i < size; ++i)
    {
        os << arr.array[i] <<' ';
    }
    os << std::endl;
    return os;
}

template <typename Type, size_t size>
std::istream& operator>>(std::istream & os, Array<Type,size>& arr)
{
    size_t i = 0;//Counter
    bool k = 0;//Идентификатор продолжения считывания
    os >> k;
    while((i < size) && k)
    {
        os >> arr.array[i++];
        os >> k;
    }
    return os;
}

/*Реализовать оператор >>, в котором можно будет ввести меньше 
элементов чем размер массива, возможно только если перед вводом 
каждого элемента будет вводиться символ продолжения/остановки считывания. 
Причина: В ф-ию operator>> нельзя, как аргумент передать количество
элементов для считывания, следовательно информация об остановке ввода должна быть 
получена из потока ввода. Элементами массива могут оказаться строки, следовательно
как идентификатор остановки считывания может использоваться только 
пробельный символ, а все пробельные символы пропускаются ф-ей operator>> до тех
пор пока не встретится элемент для инициализации массива.

P.S. Я бы мог написать это на английском, но представьте каково бы вам было это
читать.*/

#endif //ARRAY