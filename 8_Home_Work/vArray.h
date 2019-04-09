#ifndef VARRAY
#define VARRAY

#include <cstdlib>
#include <iostream>
#include <cstring>

template <typename Type>
class vArray
{
private:
    size_t varray_size;
    Type* varray;
public:
    vArray(const size_t size):
        varray_size(size),
        varray(new Type [size])
    {}

    vArray(const Type* arr, size_t size):
        varray_size(size),
        varray(new Type [size])
    {
        memcpy(varray, arr, varray_size * sizeof(Type));
    }

    vArray(const vArray& arr):
        varray_size(arr.varray_size),
        varray(new Type [arr.varray_size])
    {
        memcpy(varray, arr.varray, varray_size * sizeof(Type));
    }

    vArray(vArray&& arr):
        varray_size(arr.varray_size),
        varray(arr.varray)
    {
        arr.varray_size = 0;
        arr.varray = nullptr;
    }

    ~vArray()
    {
        delete[] varray;
    }

    void change_size(size_t new_varray_size)
    {
        Type* new_varray = new Type [new_varray_size];
        memcpy(new_varray, varray, varray_size * sizeof(Type));
        memset(new_varray + varray_size, 0,
            (new_varray_size - varray_size) * sizeof(Type));
        varray_size = new_varray_size;
        delete[] varray;
        varray = new_varray;
    }

    vArray& operator= (const vArray&& arr)
    {
        if (arr.varray_size > varray_size)
        {
            this->change_size(arr.varray_size);
        }
        memcpy(varray, arr.varray, varray_size * sizeof(Type));
        return *this;
    }

    vArray& operator= (vArray& arr)
    {
        if (arr.varray_size > varray_size)
        {
            this->change_size(arr.varray_size);
        }
        memcpy(varray, arr.varray, varray_size * sizeof(Type));
        return (*this);
    }

    vArray& operator+= (vArray& arr)
    {
        Type* new_varray = new Type [varray_size + arr.varray_size];
        memcpy(new_varray, varray, varray_size * sizeof(Type));
        memcpy(new_varray + varray_size, arr.varray, arr.varray_size * sizeof(Type));
        varray = new_varray;
        varray_size = varray_size + arr.varray_size;
        return (*this);
    }

    vArray operator+ (vArray& arr) const
    {
        return (vArray(this->varray, varray_size) += arr);
    }

    Type& operator[] (size_t num)
    {
        if (num > varray_size - 1)
        {
            this->change_size(num + 1);
        }
        return varray[num];
    }

    friend std::ostream& operator<<(std::ostream & os, const vArray& arr)
    {
        for (size_t i = 0; i < arr.varray_size; ++i)
        {
            os << arr.varray[i] <<' ';
        }
        return os;
    }

    friend std::istream& operator>>(std::istream & os, vArray& arr)
    {
        for (size_t i = 0; i < arr.varray_size; ++i)
        {
            os >> arr.varray[i];
        }
        return os;
    }
};

#endif //VARRAY