#ifndef VARRAY
#define VARRAY

#include "Array_exeption.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>

template <typename Type, typename Function>
void my_qsort (Type* arr, int b, int e, Function Func);

template <typename Type>
class vArray
{
public:
    vArray();
    vArray(size_t size);
    vArray(const Type* arr, size_t size);
    vArray(const vArray& arr);
    vArray(vArray&& arr);
    ~vArray();
    size_t get_size() { return varray_size; };
    void change_size(size_t new_varray_size);
    size_t find(Type date) const;
    void push_back(const Type date);
    void push_back(const vArray<Type>& varray);
    void push_forward(const Type date);
    void push_forward(const vArray<Type>& varray);

    template <typename Func>
    void qsort(Func f){ my_qsort(varray, 0, varray_size - 1, f); };

    vArray& operator= (const vArray&& arr);
    vArray& operator= (const vArray& arr);
    vArray& operator+= (const vArray& arr);
    vArray operator+ (const vArray& arr) const;
    Type& operator[] (size_t num);

    template <typename T>
    friend std::ostream& operator<<(std::ostream & os, const vArray<T>& arr);

    template <typename T>
    friend std::istream& operator>>(std::istream & os, vArray<T>& arr);
    //Look at comment in defenition, before using

private:
    size_t varray_size;
    Type* varray;
};




template <typename T>
vArray<T>::vArray():
    varray_size(0),
    varray(nullptr)
{}

template <typename T>
vArray<T>::vArray(size_t size):
    varray_size(size),
    varray(new T [size])
{}

template <typename T>
vArray<T>::vArray(const T* arr, size_t size):
    varray_size(size),
    varray(new T [size])
{
    memcpy(varray, arr, varray_size * sizeof(T));
}

template <typename T>
vArray<T>::vArray(const vArray& arr):
    varray_size(arr.varray_size),
    varray(new T [arr.varray_size])
{
    memcpy(varray, arr.varray, varray_size * sizeof(T));
}

template <typename T>
vArray<T>::vArray(vArray&& arr):
    varray_size(arr.varray_size),
    varray(arr.varray)
{
    arr.varray_size = 0;
    arr.varray = nullptr;
}

template <typename T>
vArray<T>::~vArray()
{
    delete[] varray;
}

template <typename T>
void vArray<T>::change_size(size_t new_varray_size)
{
    T* new_varray = new T [new_varray_size];
    size_t min_size = std::min(new_varray_size, varray_size);
    memcpy(new_varray, varray, min_size * sizeof(T));
    varray_size = new_varray_size;
    delete[] varray;
    varray = new_varray;
}

template <typename T>
size_t vArray<T>::find(T date) const
{
    for (size_t i = 0; i < varray_size; ++i)
    {
        if (varray[i] == date) { return i; };
    }
    return -1; // if there isn't date in array
}

template <typename T>
void vArray<T>::push_back(const T date)
{
    this->change_size(varray_size + 1);
    (*this)[varray_size - 1] = date;
}

template <typename T>
void vArray<T>::push_back(const vArray<T>& arr)
{
    size_t old_size = varray_size;
    this->change_size(varray_size + arr.varray_size);
    memcpy(varray + old_size, arr.varray, arr.varray_size * sizeof(T));
}

template <typename T>
void vArray<T>::push_forward(const T date)
{
    T* new_varray = new T [varray_size + 1];
    memcpy(new_varray + 1, varray, varray_size * sizeof(T));
    new_varray[0] = date;
    varray_size++;
    delete[] varray;
    varray = new_varray;
}

template <typename T>
void vArray<T>::push_forward(const vArray<T>& arr)
{
    T* new_varray = new T [varray_size + arr.varray_size];
    memcpy(new_varray, arr.varray, arr.varray_size * sizeof(T));
    memcpy(new_varray + arr.varray_size, varray, varray_size * sizeof(T));
    varray_size += arr.varray_size;
    delete[] varray;
    varray = new_varray;
}

template <typename T, typename Function>
void my_qsort (T* arr, int b, int e, Function Func)
{
    int l = b;
    int r = e;
    T piv = arr[(l + r) / 2];
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

template <typename T>
vArray<T>& vArray<T>::operator= (const vArray<T>&& arr)
{
    if (arr.varray_size > varray_size)
    {
        this->change_size(arr.varray_size);
    }
    memcpy(varray, arr.varray, varray_size * sizeof(T));
    return *this;
}

template <typename T>
vArray<T>& vArray<T>::operator= (const vArray<T>& arr)
{
    if (arr.varray_size > varray_size)
    {
        this->change_size(arr.varray_size);
    }
    memcpy(varray, arr.varray, varray_size * sizeof(T));
    return (*this);
}

template <typename T>
vArray<T>& vArray<T>::operator+= (const vArray<T>& arr)
{
    this->push_back(arr);
    return (*this);
}

template <typename T>
vArray<T> vArray<T>::operator+ (const vArray<T>& arr) const
{
    return (vArray(this->varray, varray_size) += arr);
}

template <typename T>
T& vArray<T>::operator[] (size_t num)
{
    if (num + 1 > varray_size)
    {
        throw ArrayException(
        "Size of array less then argument in [].To add element in end, use push_back()");
    }
    return varray[num];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vArray<T>& arr)
{
    for (size_t i = 0; i < arr.varray_size; ++i)
    {
        os << arr.varray[i] <<' ';
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& os, vArray<T>& arr)
{
    size_t i = 0;//Counter
    bool k = 0;//Идентификатор продолжения считывания
    os >> k;
    while((i < arr.varray_size) && k)
    {
        os >> arr.varray[i++];
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

#endif //VARRAY