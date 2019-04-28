#ifndef VARRAY
#define VARRAY

#include <cstdlib>
#include <iostream>
#include <cstring>


template <typename Type>
class Iterator_vArray;

template <typename Type, typename Function>
void my_qsort (Type* arr, int b, int e, Function Func);

template <typename Type>
class vArray{
public:
    friend class Iterator_vArray<Type>;
    vArray(const size_t size);
    vArray(const Type* arr, size_t size);
    vArray(const vArray& arr);
    vArray(vArray&& arr);
    ~vArray();
    Iterator_vArray<Type>& begin() { return Iterator_vArray<Type>(*this, 0); };
    Iterator_vArray<Type>& end() { return Iterator_vArray<Type>(*this, varray_size); };
    size_t get_size() const { return varray_size; };
    void change_size(const size_t new_varray_size);
    int find(Type date) const;
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
private:
    size_t varray_size;
    Type* varray;
};


class Iter_vArrayException : public std::exception {
public:
    Iter_vArrayException(std::string&& err) noexcept : exc(std::move(err)) {}
    Iter_vArrayException(Iter_vArrayException&& iaExc) noexcept : 
    exc(std::move(iaExc.exc))
    {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};


template <typename Type>
class Iterator_vArray{
public:
    Iterator_vArray(vArray<Type>& arr, size_t num);
    Iterator_vArray(Iterator_vArray& i_arr) = default;
    Iterator_vArray(Iterator_vArray&& i_arr);
    ~Iterator_vArray() = default;
    Type& operator*() const { return (*i_varray)[num_elem]; }
    Iterator_vArray& operator=(const Iterator_vArray& i_arr);
    Iterator_vArray& operator=(const Iterator_vArray&& i_arr);
    bool operator==(const Iterator_vArray& i_arr) const;
    bool operator!=(const Iterator_vArray& i_arr) const { return !(*this == i_arr); };
    Iterator_vArray& operator++();
    Iterator_vArray& operator++(int);
    Iterator_vArray& operator--();
    Iterator_vArray& operator--(int);

private:
    size_t num_elem;
    vArray<Type>* i_varray; //there is "i" at begining, becouse this is field of Iterator
};



//DEFENITION OF MEMBERS OF CLASS VARRAY:

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
    varray_size = new_varray_size;
    delete[] varray;
    varray = new_varray;
}

template <typename T>
int vArray<T>::find(T date) const
{
    for (size_t i = 0; i < varray_size; ++i)
    {
        if (varray[i] == date) { return i; };
    }
    return -1; // if there isn't date in array
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
void vArray<T>::push_back(const T date)
{
    (*this)[varray_size] = date;
    //It's right, I know that number of first elem is 0, look operator[]
}

template <typename T>
void vArray<T>::push_back(const vArray<T>& arr)
{
    this->change_size(varray_size + arr.varray_size);
    memcpy(varray + varray_size, arr.varray, arr.varray_size * sizeof(T));
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
    delete [] varray;
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
T& vArray<T>::operator[] (size_t num)
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

//END OF DEFENITION OF MEMBERS OF CLASS VARRAY:

//DEFENITION OF MEMBERS OF CLASS Iterator_vArray:

template <typename Type>
Iterator_vArray<Type>::Iterator_vArray(vArray<Type>& arr, size_t num):
    num_elem(num),
    i_varray(&arr)
{}

template <typename Type>
Iterator_vArray<Type>::Iterator_vArray(Iterator_vArray<Type>&& i_arr):
    num_elem(i_arr.num_elem),
    i_varray(i_arr.i_varray)
{}// We don't need to change fields of i_arr

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator=(const Iterator_vArray<Type>& i_arr)
{
    num_elem = i_arr.num_elem;
    i_varray = i_arr.i_varray;
}

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator=(const Iterator_vArray<Type>&& i_arr)
{
    num_elem = i_arr.num_elem;
    i_varray = i_arr.i_varray;
}

template <typename Type>
bool Iterator_vArray<Type>::operator==(const Iterator_vArray<Type>& i_arr) const
{
    return (num_elem == i_arr.num_elem)&&(i_varray == i_arr.i_varray);
}

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator++()
{
    if(num_elem == i_varray->varray_size)
    {
        throw Iter_vArrayException("You try to increase iterator of end");
    }
    num_elem++;
    return (*this);
}

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator++(int)
{
    if(num_elem == i_varray->varray_size)
    {
        throw Iter_vArrayException("You try to increase iterator of end");
    }
    Iterator_vArray<Type> copy (*this);
    num_elem++;
    return copy;
}

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator--()
{
    if(num_elem == 0)
    {
        throw Iter_vArrayException("You try to reduce iterator of beginning");
    }
    num_elem--;
    return (*this);
}

template <typename Type>
Iterator_vArray<Type>& Iterator_vArray<Type>::operator--(int)
{
    if(num_elem == 0)
    {
        throw Iter_vArrayException("You try to reduce iterator of beginning");
    }
    Iterator_vArray<Type> copy (*this);
    num_elem--;
    return copy;
}

//END OF DEFENITION OF MEMBERS OF CLASS Iterator_vArray:

#endif //VARRAY