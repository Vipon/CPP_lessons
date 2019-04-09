#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <cstddef>
#include <iostream>

template <typename T, std::size_t I>
class Array{
protected:
    T arr[I + 1];
public:
    Array(){};
    Array(const Array &A);
    Array(Array &&A);
    Array(const T A[I]);
    ~Array(){};
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
        friend Array<T, I>;
    };
    iterator begin();
    iterator end();
    iterator operator[](std::size_t place);
    template <typename U, std::size_t S>
    friend std::ostream &operator<< (std::ostream &out, Array<U,S> &A);
    template <typename U, std::size_t S>
    friend std::istream &operator>> (std::istream &in, Array<U,S> &A);
    Array operator= (const Array &A);
    Array operator= (Array &&A);
    friend Array<T, I>::iterator;
};

template <typename T, std::size_t I>
Array<T, I>::Array(const Array<T, I> &A){
    memcpy(this->arr, A.arr, I);
}

template <typename T, std::size_t I>
Array<T, I>::Array(Array<T, I> &&A){
    T *i = this->arr;
    this->arr = A.arr;
    A.arr = i;
}

template <typename T, std::size_t I>
Array<T, I>::Array(const T A[I]){
    memcpy(this->arr, A, I);
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator++ (){
    ++(this->iter);
    return (*this);
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator++ (int){
    Array<T, I>::iterator it = this->iter;
    ++(this->iter);
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator-- (){
    --(this->iter);
    return *this;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator-- (int){
    Array<T, I>::iterator it = this->iter;
    --(this->iter);
    return it;
}

template <typename T, std::size_t I>
T &Array<T, I>::iterator::operator*(){
    return *(this->iter);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator==(iterator it){
    return (this->iter == it.iter);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator!=(iterator it){
    return (this->iter != it.iter);
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator &Array<T,I>::iterator::operator= (const iterator &it){
    this->iter = it.iter;
    *this;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::begin(){
    Array<T, I>::iterator it;
    it.iter = this->arr;
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::end(){
    Array<T, I>::iterator it;
    it.iter = this->arr;
    it.iter += I;
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::operator[](std::size_t place){
    Array<T, I>::iterator it = this->begin();
    it.iter += place;
    return it;
}

template <typename T, std::size_t I>
std::ostream &operator<< (std::ostream &out, Array<T,I> &A){
    for (auto it = A.begin(); it != A.end(); ++it){
        out << *it << " ";
    }
    out << std::endl;
    return out;
};

template <typename T, std::size_t I>
std::istream &operator>> (std::istream &in, Array<T,I> &A){
    for (auto it = A.begin(); it != A.end(); ++it){
        in >> *it;
    }
    return in;
}

template <typename T, std::size_t I>
Array<T, I> Array<T, I>::operator=(const Array<T, I> &A){
    memcpy(this->arr, A.arr, I);
    return *this;
}

template <typename T, std::size_t I>
Array<T, I> Array<T, I>::operator=(Array<T, I> &&A){
    T *i = this->arr;
    this->arr = A.arr;
    A.arr = i;
    return *this;
}

#endif // ARRAY_H_INCLUDED
