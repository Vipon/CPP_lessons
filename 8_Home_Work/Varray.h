#ifndef VARRAY_H_INCLUDED
#define VARRAY_H_INCLUDED

#include <iterator>
#include <cstddef>
#include <cstring>
#include <iostream>

template <typename T>
class Varray{
protected:
    T *arr;
    std::size_t Length;
public:
    std::size_t NUM = 0;
    Varray(std::size_t length);
    Varray(const Varray &A);
    Varray(Varray &&A);
    Varray(const T *A, const std::size_t length);
    ~Varray();
    std::size_t length();
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
        Varray <T> *lord;
        std::size_t pos;
        friend Varray<T>;
    };
    iterator begin();
    iterator rbegin();
    iterator end();
    iterator rend();
    T &operator[](std::size_t place);
    template <typename U>
    friend std::ostream &operator<< (std::ostream &out, Varray<U> &A);
    template <typename U, std::size_t S>
    friend std::istream &operator>> (std::istream &in, Varray<U> &A);
    Varray &operator= (const Varray &A);
    Varray &operator= (Varray &&A);
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
    memcpy(this->arr, A.arr, (A.Length + 1) * sizeof(T));
    this->NUM = A.NUM;
}

template <typename T>
Varray<T>::Varray(Varray<T> &&A){
    this->arr = A.arr;
    A.arr = new T[1];
    this->NUM = A.NUM;
}

template <typename T>
Varray<T>::Varray(const T *A, const std::size_t length){
    this->arr = new T[length + 2];
    this->Length = length;
    memcpy(this->arr + 1, A, length * sizeof(T));
    this->NUM = length;
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
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos == this->lord->Length + 1){
        return (*this);
    }
    ++(this->pos);
    return (*this);
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator++ (int){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos == this->lord->Length + 1){
        return (*this);
    }
    Varray<T>::iterator it;
    it.lord = this->lord;
    it.pos = this->pos;
    ++(this->pos);
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-- (){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos == 0){
        return (*this);
    }
    --(this->pos);
    return *this;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-- (int){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos == 0){
        return (*this);
    }
    Varray<T>::iterator it;
    it.lord = this->lord;
    it.pos = this->pos;
    --(this->pos);
    return it;
}

template <typename T>
T &Varray<T>::iterator::operator*(){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }
    if (this->pos == this->lord->Length + 1 || this->pos == 0){
        throw "ptr_to_dummy_element";
    }*/
    return *(this->lord->arr + this->pos);
}

template <typename T>
bool Varray<T>::iterator::operator==(iterator it){
    return (this->lord == it.lord && this->pos == it.pos);
}

template <typename T>
bool Varray<T>::iterator::operator!=(iterator it){
    return (this->lord != it.lord || this->pos != it.pos);
}

template <typename T>
bool Varray<T>::iterator::operator<(iterator it){
    return (this->lord == it.lord && this->pos < it.pos);
}

template <typename T>
bool Varray<T>::iterator::operator<=(iterator it){
    return (this->lord == it.lord && this->pos <= it.pos);
}

template <typename T>
bool Varray<T>::iterator::operator>(iterator it){
    return (this->lord == it.lord && this->pos > it.pos);
}

template <typename T>
bool Varray<T>::iterator::operator>=(iterator it){
    return (this->lord == it.lord && this->pos >= it.pos);
}

template <typename T>
typename Varray<T>::iterator &Varray<T>::iterator::operator= (const iterator &it){
    this->lord = it.lord;
    this->pos = it.pos;
    return *this;
}

template <typename T>
T &Varray<T>::iterator::operator[](const int place){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }
    if (this->pos + place >= this->lord->Length + 1 || this->pos + place == 0){
        throw "*ptr_over_array";
    }*/
    return *(this->lord->arr + this->pos + place);
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator+(const int place){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    Varray<T>::iterator it = *this;
    if (it.pos + place < 0){
        it.pos = 0;
        return it;
    }
    it.pos += place;
    if (it.pos > this->lord->Length + 1){
        it.pos = this->lord->Length + 1;
    }
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-(const int place){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    Varray<T>::iterator it = *this;
    if (it.pos - place < 0){
        it.pos = 0;
        return it;
    }
    it.pos -= place;
    if (it.pos > this->lord->Length + 1){
        it.pos = this->lord->Length + 1;
    }
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator+=(const int place){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos + place < 0){
        this->pos = 0;
        return *this;
    }
    this->pos += place;
    if (this->pos > this->lord->Length + 1){
        this->pos = this->lord->Length + 1;
    }
    return *this;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::iterator::operator-=(const int place){
    /*if (this->lord == nullptr){
        throw "invalid_ptr";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_ptr";
    }*/
    if (this->pos - place < 0){
        this->pos = 0;
        return *this;
    }
    this->pos -= place;
    if (this->pos > this->lord->Length + 1){
        this->pos = this->lord->Length + 1;
    }
    return *this;
}

template <typename T>
int Varray<T>::iterator::operator-(const iterator &it){
    /*if (this->lord == nullptr){
        throw "invalid_left_ptr";
    }
    if (it.lord == nullptr){
        throw "invalid_right_ptr";
    }
    if (it.lord != this->lord){
        throw "different_ptrs";
    }
    if (this->pos > this->lord->Length + 1){
        throw "too_big_left_ptr";
    }
    if (it.pos > this->lord->Length + 1){
        throw "too_big_right_ptr";
    }*/
    return (this->pos - it.pos);
}

template <typename T>
typename Varray<T>::iterator Varray<T>::begin(){
    Varray<T>::iterator it;
    it.lord = this;
    it.pos = 1;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::rbegin(){
    Varray<T>::iterator it;
    it.lord = this;
    it.pos = this->Length;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::end(){
    Varray<T>::iterator it;
    it.lord = this;
    it.pos = this->Length + 1;
    return it;
}

template <typename T>
typename Varray<T>::iterator Varray<T>::rend(){
    Varray<T>::iterator it;
    it.lord = this;
    it.pos = 0;
    return it;
}

template <typename T>
T &Varray<T>::operator[](std::size_t place){
    /*if (place >= this->Length){
        throw "*ptr_over_array";
    }*/
    Varray<T>::iterator it;
    it.lord = this;
    it.pos = place + 1;
    return *it;
}

template <typename T>
std::ostream &operator<< (std::ostream &out, Varray<T> &A){
    std::size_t i = 0;
    for (auto it = A.begin(); it != A.end(); ++it){
        if (i == A.NUM){
            continue;
        }
        ++i;
        out << *it << " ";
    }
    out << std::endl;
    return out;
};

template <typename T>
std::istream &operator>> (std::istream &in, Varray<T> &A){
    T num;
    A.NUM = 0;
    for (auto it = A.begin(); it != A.end(); ++it){
        if (in >> num){
            *it = num;
            ++(A.NUM);
        } else{
            continue;
        }
    }
    in.clear();
    return in;
}

template <typename T>
Varray<T> &Varray<T>::operator=(const Varray<T> &A){
    memcpy(this->arr + 1, A.arr + 1, sizeof(T) * std::min(this->Length, A.length));
    this->NUM = A.NUM;
    return *this;
}

template <typename T>
Varray<T> &Varray<T>::operator=(Varray<T> &&A){
    T *i = this->arr;
    this->arr = A.arr;
    A.arr = i;
    this->NUM = A.NUM;
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
    this->NUM = std::min(this->Length, this->NUM);
}

#endif // VARRAY_H_INCLUDED
