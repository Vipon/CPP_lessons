#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iterator>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t I>
class Array{
protected:
    T arr[I + 2];
public:
    Array(){};
    Array(const Array &A);
    Array(Array &&A);
    Array(const T A[I]);
    ~Array(){};
    class iterator : public std::iterator<
                std::random_access_iterator_tag,
                T, int, T*, T&
                >{
    public:
        iterator() : lord(nullptr), pos(0) {};
        iterator(const iterator &it) : lord(it.lord), pos(it.pos) {};
        ~iterator(){};
        iterator operator++ ();
        iterator operator++ (int);
        iterator operator-- ();
        iterator operator-- (int);
        T &operator*();
        bool operator==(iterator it);
        bool operator!=(iterator it);
        bool operator<(iterator it);
        bool operator>(iterator it);
        bool operator<=(iterator it);
        bool operator>=(iterator it);
        iterator &operator= (const iterator &it);
        T &operator[](const int place);
        iterator operator+(const int place);
        iterator operator-(const int place);
        iterator operator+=(const int place);
        iterator operator-=(const int place);
        int operator-(const iterator &it);
    protected:
        Array <T, I> *lord;
        std::size_t pos;
        friend Array<T, I>;
    };
    iterator begin();
    iterator rbegin();
    iterator end();
    iterator rend();
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
    memcpy(this->arr, A.arr, I + 1);
}

template <typename T, std::size_t I>
Array<T, I>::Array(Array<T, I> &&A){
    T *i = this->arr;
    this->arr = A.arr;
    A.arr = i;
}

template <typename T, std::size_t I>
Array<T, I>::Array(const T A[I]){
    memcpy(this->arr + 1, A, I);
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator++ (){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos == I + 1){
        return (*this);
    }
    ++(this->pos);
    return (*this);
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator++ (int){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos == I + 1){
        return (*this);
    }
    Array<T, I>::iterator it;
    it.lord = this->lord;
    it.pos = this->pos;
    ++(this->pos);
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator-- (){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos == 0){
        return (*this);
    }
    --(this->pos);
    return *this;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::iterator::operator-- (int){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos == 0){
        return (*this);
    }
    Array<T, I>::iterator it;
    it.lord = this->lord;
    it.pos = this->pos;
    --(this->pos);
    return it;
}

template <typename T, std::size_t I>
T &Array<T, I>::iterator::operator*(){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos == I + 1 || this->pos == 0){
        throw "ptr_to_dummy_element";
    }
    return *(this->lord->arr + this->pos);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator==(iterator it){
    return (this->lord == it.lord && this->pos == it.pos);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator!=(iterator it){
    return (this->pos != it.pos || this->lord != it.lord);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator<(iterator it){
    return (this->pos < it.pos && this->lord == it.lord);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator>(iterator it){
    return (this->pos > it.pos && this->lord == it.lord);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator<=(iterator it){
    return (this->pos <= it.pos && this->lord == it.lord);
}

template <typename T, std::size_t I>
bool Array<T, I>::iterator::operator>=(iterator it){
    return (this->pos >= it.pos && this->lord == it.lord);
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator &Array<T,I>::iterator::operator= (const iterator &it){
    this->lord = it.lord;
    this->pos = it.pos;
    return *this;
}

template <typename T, std::size_t I>
T &Array<T,I>::iterator::operator[](const int place){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos + place >= I + 1 || this->pos + place == 0){
        throw "*ptr_over_array";
    }
    return *(this->lord->arr + this->pos + place);
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator Array<T,I>::iterator::operator+(const int place){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    Array<T, I>::iterator it = *this;
    if (it.pos + place < 0){
        it.pos = 0;
        return it;
    }
    it.pos += place;
    if (it.pos > I + 1){
        it.pos = I + 1;
    }
    return it;
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator Array<T,I>::iterator::operator-(const int place){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    Array<T, I>::iterator it = *this;
    if (it.pos - place < 0){
        it.pos = 0;
        return it;
    }
    it.pos -= place;
    if (it.pos > I + 1){
        it.pos = I + 1;
    }
    return it;
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator Array<T,I>::iterator::operator+=(const int place){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos + place < 0){
        this->pos = 0;
        return *this;
    }
    this->pos += place;
    if (this->pos > I + 1){
        this->pos = I + 1;
    }
    return *this;
}

template <typename T, std::size_t I>
typename Array<T,I>::iterator Array<T,I>::iterator::operator-=(const int place){
    if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos - place < 0){
        this->pos = 0;
        return *this;
    }
    this->pos -= place;
    if (this->pos > I + 1){
        this->pos = I + 1;
    }
    return *this;
}

template <typename T, std::size_t I>
int Array<T,I>::iterator::operator-(const iterator &it){
    if (this->lord == nullptr){
        throw "invalid_left_ptr";
    }
    if (it.lord == nullptr){
        throw "invalid_right_ptr";
    }
    if (it.lord != this->lord){
        throw "different_ptrs";
    }
    return (this->pos - it.pos);
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::begin(){
    Array<T, I>::iterator it;
    it.lord = this;
    it.pos = 1;
    return it;
}
template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::rbegin(){
    Array<T, I>::iterator it;
    it.lord = this;
    it.pos = I;
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::end(){
    Array<T, I>::iterator it;
    it.lord = this;
    it.pos = I + 1;
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::rend(){
    Array<T, I>::iterator it;
    it.lord = this;
    it.pos = 0;
    return it;
}

template <typename T, std::size_t I>
typename Array<T, I>::iterator Array<T, I>::operator[](std::size_t place){
    if (place >= I){
        throw "*ptr_over_array";
    }
    Array<T, I>::iterator it;
    it.lord = this;
    it.pos = place + 1;
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
    memcpy(this->arr, A.arr, I + 1);
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
