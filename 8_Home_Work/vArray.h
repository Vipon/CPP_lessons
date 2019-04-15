#ifndef VARRAY
#define VARRAY

#include <cstdlib>
#include <iostream>
#include <cstring>

template <typename Type>
class vArray
{
public:
    vArray(const size_t size);
    vArray(const Type* arr, size_t size);
    vArray(const vArray& arr);
    vArray(vArray&& arr);
    ~vArray();
    void change_size(const size_t new_varray_size);
    vArray& operator= (const vArray&& arr);
    vArray& operator= (const vArray& arr);
    vArray& operator+= (const vArray& arr);
    vArray operator+ (const vArray& arr) const;
    Type& operator[] (const size_t num);
    template <typename T>
    friend std::ostream& operator<<(std::ostream & os, const vArray<T>& arr);
    template <typename T>
    friend std::istream& operator>>(std::istream & os, vArray<T>& arr);
private:
    size_t varray_size;
    Type* varray;
};




template <typename T>
vArray<T>::vArray(const size_t size):
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
void vArray<T>::change_size(const size_t new_varray_size)
{
    T* new_varray = new T [new_varray_size];
    memcpy(new_varray, varray, varray_size * sizeof(T));
    memset(new_varray + varray_size, 0,
        (new_varray_size - varray_size) * sizeof(T));
    varray_size = new_varray_size;
    delete[] varray;
    varray = new_varray;
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
    T* new_varray = new T [varray_size + arr.varray_size];
    memcpy(new_varray, varray, varray_size * sizeof(T));
    memcpy(new_varray + varray_size, arr.varray, arr.varray_size * sizeof(T));
    varray_size = varray_size + arr.varray_size;
    varray = new_varray;
    return (*this);
}

template <typename T>
vArray<T> vArray<T>::operator+ (const vArray<T>& arr) const
{
    return (vArray(this->varray, varray_size) += arr);
}

template <typename T>
T& vArray<T>::operator[] (const size_t num)
{
    if (num > varray_size - 1)
    {
        this->change_size(num + 1);
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
    for (size_t i = 0; i < arr.varray_size; ++i)
    {
        os >> arr.varray[i];
    }
    return os;
}

#endif //VARRAY