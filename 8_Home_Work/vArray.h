#ifndef VARRAY_H
#define VARRAY_H

#include <iostream>
#include <cstddef>
#include <exception>

const size_t N = 16;
const double END = 0;

template<class T>
class vArray {
public:
    vArray();
    vArray(const size_t& n);
    ~vArray();
    const size_t& GetSize() const;
    const size_t& GetCap() const;
    void Resize();
    void SetSize(const size_t& n);
    void PushBack(const T& val);
    T &operator[](const size_t &n);
    T operator[](const size_t &n) const;
    void operator+=(const vArray<T>& array_);
    bool operator==(const vArray<T>& array_);
    void operator=(const vArray<T>& array_);
    template<typename Q>
    friend std::ostream &operator<<(std::ostream &stream, const vArray<Q>& array);
    template<typename Q>
    friend std::istream &operator>>(std::istream& stream, vArray<Q>& array);

private:
    T *data;
    size_t cap;
    size_t size;
};

template<typename T>
vArray<T> operator+(const vArray<T>& array, const vArray<T>& array_);

template<typename T>
vArray<T>::vArray() : cap(N), size(0) {
    data = new T[cap];
}

template<typename T>
vArray<T>::vArray(const size_t &n): cap(n), size(0) {
    data = new T[cap];
}

template<typename T>
vArray<T>::~vArray() {
    cap = 0;
    size = 0;
    delete[] data;
}

template<typename T>
void vArray<T>::SetSize(const size_t& n) {
    cap = n;
    T* newData = new T[cap];
    if (n > cap) {
        for(int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
    } else if (n < cap) {
        for(int i = 0; i < cap; ++i) {
            newData[i] = data[i];
        }
    }
    delete[] data;
    data = newData;
}

template<typename T>
const size_t& vArray<T>::GetSize() const {
    return size;
}

template<typename T>
const size_t& vArray<T>::GetCap() const {
    return cap;
}

template<typename T>
void vArray<T>::PushBack(const T &val) {
    if (cap == size)
        this->Resize();
    data[size++] = val;
}

template<typename T>
void vArray<T>::Resize() {
    if (cap){
        cap << 2;
    } else {
        cap = 1;
    }

    T *newData = new T[cap];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template<typename T>
T &vArray<T>::operator[](const size_t &n) {
    if (n > cap) {
        throw std::runtime_error("Out of range");
    }
    return data[n];
}

template<typename T>
T vArray<T>::operator[](const size_t &n) const{
    if (n > size) {
        throw std::runtime_error("Out of range");
    }
    return data[n];
}

template<typename T>
void vArray<T>::operator+=(const vArray<T>& array_) {
    for(int i = 0; i < array_.GetSize(); ++i) {
        this->PushBack(array_[i]);
    }
}

template<typename T>
vArray<T> operator+(const vArray<T>& array, const vArray<T>& array_) {
    vArray<T> NewVArray = vArray<T>(array.GetSize() + array_.GetSize());
    for(int i = 0; i < array.GetSize(); ++i){
        NewVArray.PushBack(array[i]);
    }
    for(int i = 0; i < array_.GetSize(); ++i){
        NewVArray.PushBack(array_[i]);
    }
    return NewVArray;
}

template<typename T>
bool vArray<T>::operator==(const vArray<T>& array_) {
    if (array_.GetSize() != size){
        return false;
    }
    for(int i = 0; i < size; ++i) {
        if (array_[i] != this[i])
            return false;
    }
    return true;
}


template<typename T>
void vArray<T>::operator=(const vArray<T>& array_) {
    size = array_.size;
    cap = array_.cap;
    delete[] data;
    data = new T[cap];
    for(int i = 0; i < size; ++i) {
        data[i] = array_[i];
    }
}

template<typename Q>
std::ostream &operator<<(std::ostream &stream, const vArray<Q>& array) {
    for (int i = 0; i < array.GetSize(); ++i) {
        stream << array[i] << ' ';
    }
    return stream;
}

template<typename Q>
std::istream &operator>>(std::istream& stream, vArray<Q>& array) {
    size_t i = 0;
    Q c;
    stream >> c;
    while (c != END) {
        if (array.GetCap() == i) {
            array.Resize();
        }
        array[i] = c;
        stream >> c;
        ++i;
    }
    array.size = i;
    return stream;
}


#endif //VARRAY_H