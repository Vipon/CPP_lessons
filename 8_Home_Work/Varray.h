#ifndef VARRAY_H_INCLUDED
#define VARRAY_H_INCLUDED

#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class Varray{
protected:
    T *arr;
    std::size_t Length;
public:
    Varray(std::size_t length);
    Varray(const Varray &A);
    Varray(Varray &&A);
    Varray(const T *A, const std::size_t length);
    ~Varray();
    std::size_t length();
    class iterator{
    public:
        iterator(){};
        iterator(const iterator &it) : iter(it.iter) {};
        ~iterator(){};
        iterator operator++ ();
        iterator operator++ (int);
        iterator operator-- ();
        iterator operator-- (int);
        T &operator*();
        bool operator==(iterator it);
        bool operator!=(iterator it);
        iterator &operator= (const iterator &it);
    protected:
        T *iter;
        friend Varray<T>;
    };
    iterator begin();
    iterator rbegin();
    iterator end();
    iterator rend();
    iterator operator[](std::size_t place);
    template <typename U>
    friend std::ostream &operator<< (std::ostream &out, Varray<U> &A);
    template <typename U, std::size_t S>
    friend std::istream &operator>> (std::istream &in, Varray<U> &A);
    Varray operator= (const Varray &A);
    Varray operator= (Varray &&A);
    void relength(std::size_t new_length);
    friend Varray<T>::iterator;
private:
    Varray();
};

template <typename T>
Varray<T>::Varray(const std::size_t length){
    this->arr = new T[length + 2];
    this->Length = length;
}

template <typename T>
Varray<T>::Varray(const Varray<T> &A){
    this->arr = new T[A.Length + 2];
    this->Length = A.Length;
    memcpy(this->arr, A.arr, A.Length);
}

template <typename T>
Varray<T>::Varray(Varray<T> &&A){
    this->arr = A.arr;
    A.arr = new T[1];
}

template <typename T>
Varray<T>::Varray(const T *A, const std::size_t length){
    this->arr = new T[length + 2];
    this->Length = length;
    memcpy(this->arr, A, length);
}

template <typename T>
Varray<T>::~Varray(){
    delete[] this->arr;
}

template <typename T>
std::size_t Varray<T>::length(){
    return this->Length;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator++ (){
    ++(this->iter);
    return (*this);
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator++ (int){
    Varray<T>::iterator it = this->iter;
    ++(this->iter);
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-- (){
    --(this->iter);
    return *this;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-- (int){
    Varray<T>::iterator it = this->iter;
    --(this->iter);
    return it;
}

template <typename T>
T &Varray<T>::iterator::operator*(){
    return *(this->iter);
}

template <typename T>
bool Varray<T>::iterator::operator==(iterator it){
    return (this->iter == it.iter);
}

template <typename T>
bool Varray<T>::iterator::operator!=(iterator it){
    return (this->iter != it.iter);
}

template <typename T>
typename Varray<T>::iterator &Varray<T>::iterator::operator= (const iterator &it){
    this->iter = it.iter;
    *this;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::begin(){
    Varray<T>::iterator it;
    it.iter = this->arr;
    (it.iter)++;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::rbegin(){
    Varray<T>::iterator it;
    it.iter = this->arr;
    it.iter += this->Length;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::end(){
    Varray<T>::iterator it;
    it.iter = this->arr;
    it.iter += this->Length + 1;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::rend(){
    Varray<T>::iterator it;
    it.iter = this->arr;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::operator[](std::size_t place){
    Varray<T>::iterator it = this->begin();
    it.iter += place;
    return it;
}

template <typename T>
std::ostream &operator<< (std::ostream &out, Varray<T> &A){
    for (auto it = A.begin(); it != A.end(); ++it){
        out << *it << " ";
    }
    out << std::endl;
    return out;
};

template <typename T>
std::istream &operator>> (std::istream &in, Varray<T> &A){
    for (auto it = A.begin(); it != A.end(); ++it){
        in >> *it;
    }
    return in;
}

template <typename T>
Varray<T> Varray<T>::operator=(const Varray<T> &A){
    memcpy(this->arr, A.arr, std::min(this->Length, A.length));
    return *this;
}

template <typename T>
Varray<T> Varray<T>::operator=(Varray<T> &&A){
    T *i = this->arr;
    this->arr = A.arr;
    A.arr = i;
    return *this;
}

template <typename T>
void Varray<T>::relength(std::size_t new_length){
    T *new_arr = new T[new_length + 2];
    std::size_t sz = std::min(this->Length, new_length) + 1;
    memcpy(new_arr, this->arr, sz * sizeof(T));
    delete[] this->arr;
    this->arr = new_arr;
    this->Length = new_length;
}

#endif // VARRAY_H_INCLUDED
