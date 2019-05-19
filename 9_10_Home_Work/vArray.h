#ifndef __vARRAY_H
#define __vARRAY_H
#include <iterator>
#include <cstddef>
#include <cstring>
#include "Exceptions.h"

template <typename T>
class vArray {

public:
    // default constructor
    vArray(size_t size = 0);
    vArray(T A[], size_t length);
    vArray(const vArray& vA);
    vArray(T &&vA) noexcept;
    ~vArray();

    template <typename T0>
    friend std::ostream& operator<<(std::ostream &out, const vArray<T0> &vA);
    template <typename T0>
    friend std::istream& operator>>(std::istream &in, vArray<T0> &vA);

    vArray& operator=(const vArray<T>& vA);
    vArray& operator=(vArray<T>&& vA);
    T& operator[](size_t pos);

    int find(T Req_val);
    void QSort(int begin, int end);
    void set_size(size_t new_size);
    void push_back(T elem);

    class Iterator : public std::iterator<std::random_access_iterator_tag, T, int> {
    public:
        Iterator() {};
        Iterator(const Iterator& it) : p(it.p), pos(it.pos), size(it.size) {};
        Iterator(T** elem, size_t pos, size_t* size) : p(elem), pos(pos), size(size) {};
        ~Iterator() {};

        Iterator operator+(int n);
        Iterator operator+=(int n);
        Iterator operator-(int n);
        Iterator operator-=(int n);
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
        int operator-(const Iterator &it);
        Iterator& operator=(const Iterator &it);
        bool operator==(Iterator& it);
        bool operator!=(Iterator& it);
        bool operator<(Iterator& it);
        bool operator>(Iterator& it);
        bool operator<=(Iterator& it);
        bool operator>=(Iterator& it);

        T& operator*();
        size_t it_pos();

    private:
        T** p; 
        int pos;
        size_t* size; 
        friend vArray<T>;
    };

    Iterator begin();
    Iterator end();
 
private:
    T* val;
    size_t size;
};


template <typename T>
vArray<T>::vArray(size_t size) :
    size(size),
    val(new T[size]) {};

template <typename T>
vArray<T>::vArray(T A[], size_t length) :size(length), val(new T[length]) {
    if (val == nullptr) {
        throw ArrException("OUT OF MEMORY");
    }
    memcpy(val, A, sizeof(T) * size);
};

// constructor of copy
template <typename T>
vArray<T>::vArray(const vArray& vA) : size(vA.size), val(new T[vA.size]) {
    if (val == nullptr) {
        throw ArrException("OUT OF MEMORY");
    }
    memcpy(val, vA.val, sizeof(T) * vA.size);
};

// move constructor
template <typename T>
vArray<T>::vArray(T &&vA) noexcept : val(vA.val), size(vA.size) {
    vA.val = nullptr;
    vA.size = 0;
};

//destructor
template <typename T>
vArray<T>::~vArray() { delete[] val; }

template <typename T>
vArray<T>& vArray<T>::operator=(const vArray<T>& vA) {
    size = vA.size;
    delete[] val;

    val = new T[size];
    if (val == nullptr) {
        throw ArrException("OUT OF MEMORY");
    }

    memcpy(val, vA.val, size * sizeof(T));
    return *this;
}

template <typename T>
vArray<T>& vArray<T>::operator=(vArray<T>&& vA) {
    size = vA.size;
    val = vA.val;
    vA.size = 0;
    vA.val = nullptr;
    return *this;
}

template <typename T>
T& vArray<T>::operator[](size_t pos) {
    if (pos > size - 1) {
        throw ArrException("OUT OF SIZE");
    }
    return val[pos];
}

/*first element you write wil be used only as closing one and not be put in list,
also you have to put the same element at the end to finish input */
template <typename T>
std::istream& operator>>(std::istream &in, vArray<T> &vA) {
    T end;
    T elem;
    in >> end;
    in >> elem;
    size_t i = 0;
    vA.size = 0;

    while (elem != end) {
        if (i >= vA.size) {
            T* temp = vA.val;

            vA.val = new T[(vA.size + 1) * 2];
            if (vA.val == nullptr) {
                throw ArrException("OUT OF MEMORY");
            }

            memcpy(vA.val, temp, sizeof(T) * vA.size);
            vA.size = (vA.size + 1) * 2;
            delete[] temp;
        }

        vA.val[i] = elem;
        i++;
        in >> elem;
    }

    T* temp = vA.val;
    vA.val = new T[i];
    if (vA.val == nullptr && vA.size != 0) {
        throw ArrException("OUT OF MEMORY");
    }

    memcpy(vA.val, temp, i * sizeof(T));
    delete[] temp;
    vA.size = i;

    return in;
}

template <typename T>
int vArray<T>::find(T Req_val) {
    for (size_t i = 0; i < size; i++) {
        if (Req_val == val[i]) {
            return i;
        }
    }
    return -1;
};


template <typename T>
std::ostream& operator<<(std::ostream &out, const vArray<T> &vA) {
    for (size_t i = 0; i < vA.size; i++) {
        out << (vA.val)[i] << ' ';
    }
    out << '\n';
    return out;
}

template <typename T>
void vArray <T>::QSort(int begin, int end) {
    if ((begin < 0) || (end > size - 1)) {
        throw ArrException("OUT OF SIZE");
    }

    T temp;
    int b = begin;
    int e = end;

    while (b <= e) {
        while (val[b] < val[((b + e) / 2)]) {
            b++;
        }

        while (val[e] > val[((b + e) / 2)]) {
            e--;
        }

        if (b <= e) {
            temp = val[b];
            val[b++] = val[e];
            val[e--] = temp;
        }
    }

    if (begin < e) {
        QSort(begin, e);
    }

    if (end > b) {
        QSort(b, end);
    }
}

template <typename T>
void vArray<T>::set_size(size_t new_size) {
    if (new_size == size) {
        return;
    }

    T* temp = val;
    val = new T[new_size];
    if (new_size < size) {
        memcpy(val, temp, new_size * sizeof(T));
    }
    else {
        memcpy(val, temp, size * sizeof(T));
    }
    size = new_size;
}


template <typename T>
void vArray<T>::push_back(T elem) {
    T* temp = val;
    val = new T[size + 1];
    if (val == nullptr) {
        throw ArrException("OUT OF MEMORY");
    }

    memcpy(val, temp, size * sizeof(T));
    delete[] temp;

    val[size] = elem;
    size++;
}

template <typename T>
T& vArray<T>::Iterator::operator*() {
    return (*p)[pos];
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator++() {
    if (pos == (*size)) {
        return (*this);
    };

    ++pos;
    return (*this);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator++(int) {
    if (pos == (*size)) {
        return (*this);
    };

    return Iterator(this->p, (pos++), size);
}

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator--() {
    if (pos == 0) {
        return (*this);
    };

    --pos;
    return (*this);
};

template <typename T>
typename vArray<T>::Iterator vArray<T>::Iterator::operator--(int) {
    if (pos == 0) {
        return (*this);
    };

    return Iterator(this->p, (pos--), size);
}

template <typename T>
 bool vArray<T>::Iterator::operator==(Iterator& it) {
    return (p == it.p) && (pos == it.pos) && (size == it.size);
}

 template <typename T>
 bool vArray<T>::Iterator::operator!=(Iterator& it) {
     return !((p == it.p) && (pos == it.pos) && (size == it.size));
 };

 template <typename T>
 typename vArray<T>::Iterator& vArray<T>::Iterator::operator=(const Iterator &it) {
     p = it.p;
     pos = it.pos;
     size = it.size;
     return (*this);
 };

 template <typename T>
 typename int vArray<T>::Iterator::operator-(const Iterator &it) {
     return (pos - it.pos);
 }

 template <typename T>
 bool vArray<T>::Iterator::operator<(Iterator& it) {
     return ((this->pos) < (it.pos));
 }

 template <typename T>
 bool vArray<T>::Iterator::operator>(Iterator& it) {
     return ((this->pos) > (it.pos));
 }

 template <typename T>
 bool vArray<T>::Iterator::operator<=(Iterator& it) {
     return ((this->pos) <= (it.pos));
 }

 template <typename T>
 bool vArray<T>::Iterator::operator>=(Iterator& it) {
     return ((this->pos) >= (it.pos));
 }

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::Iterator::operator+(int n) {
     if (((pos + n) > (*size)) || ((pos + n) < 0)) {
         return (*this);
     };

     return Iterator((this->p), ((this->pos) + n), this->size);
 }

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::Iterator::operator+=(int n) {
     if (((pos + n) > (*size)) || ((pos + n) < 0)) {
         return (*this);
     };

     this->pos += n;

     return (*this);
 }

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::Iterator::operator-(int n) {
     if (((pos - n) > (*size)) || ((pos - n) < 0)) {
         return (*this);
     };

     return Iterator((this->p), ((this->pos) - n), this->size);
 }

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::Iterator::operator-=(int n) {
     if (((pos - n) > (*size)) || ((pos - n) < 0)) {
         return (*this);
     };

     this->pos -= n;

     return (*this);
 }

 template <typename T>
 size_t vArray<T>::Iterator::it_pos() {
     return pos;
 }

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::begin() {
     return Iterator(&val, 0, &size);
 };

 template <typename T>
 typename vArray<T>::Iterator vArray<T>::end() {
     return Iterator(&val ,size, &size);
 };



#endif //__vARRAY_H