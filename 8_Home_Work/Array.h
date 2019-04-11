#ifndef ARRAY
#define ARRAY

#include <cstdlib>
#include <iostream> 
#include <cstring>

template <typename Type, size_t size>
class Array
{
private:
    Type array[size];
public:
    Array() = default;

    Array(const Type arr[size])//it's more safe, then Type* arr 
    {
        memcpy(array, arr, size * sizeof(Type));
    }

    Array(const Array& arr)
    {
        memcpy(array, arr.array, size * sizeof(Type));
    }

    //We don't need in move-constructor, becouse Array can't be rvalue in my realization

    Type& operator[] (size_t num)
    {
        if (num > size - 1)
        {
            abort(); //I will correct it later
        }
        return array[num];
    }

    Array& operator= (const Array& arr)
    {
        memcpy(array, arr.array, size * sizeof(Type));
        return *this;
    }

    friend std::ostream& operator<<(std::ostream & os, const Array& arr)
    {
        for (size_t i = 0; i < size; ++i)
        {
            os << arr.array[i] <<' ';
        }
        os << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream & os, Array& arr)
    {
        for (size_t i = 0; i < size; ++i)
        {
            os >> arr.array[i];
        }
        return os;
    }

    ~Array() = default;
};
#endif //ARRAY