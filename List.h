#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstddef>

template <typename T>
class List{
protected:
    struct Elem{
        Elem *prev;
        T Val;
        Elem *next;
    };
    typedef Elem *Pelem;
    Pelem first;
    Pelem last;
    std::size_t Length;

public:
    List();
    List(const List &L);
    List(List &&L);
    ~List();
    bool empty() const;
    std::size_t length() const;
    class iterator{
    public:
        iterator(){};
        iterator(const iterator &it);
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
        Pelem iter;

        friend List<T>;
    };
    iterator begin() const;
    iterator end() const;
    iterator operator[](std::size_t place);
    iterator insert(const T &val, iterator place);
    iterator push_back(const T &val);
    iterator push_front(const T &val);
    iterator remove(iterator place);
    iterator pop_front();
    iterator pop_back();
    T &front();
    T &back();
    template <typename U>
    friend std::ostream &operator<< (std::ostream &out, const List<U> &lt);
    template <typename U>
    friend std::istream &operator>> (std::istream &in, List<U> &lt);
    List operator= (const List &L);
    List operator= (List &&L);
    friend List<T>::iterator;
};

template <typename T>
List<T>::List(){
    this->first = new Elem;
    this->last = new Elem;
    this->Length = 0;
    this->first->prev = this->first;
    this->first->next = this->last;
    this->last->prev = this->first;
    this->last->next = this->last;
}

template <typename T>
List<T>::List(const List<T> &L){
    this->first = new Elem;
    this->last = new Elem;
    this->Length = 0;
    this->first->prev = this->first;
    this->first->next = this->last;
    this->last->prev = this->first;
    this->last->next = this->last;
    for (auto it = L.begin(); it != L.end(); ++it){
        this->push_back(*it);
    }
}

template <typename T>
List<T>::List(List<T> &&L){
    this->first = new Elem;
    this->last = new Elem;
    this->Length = L.Length;
    this->first->prev = this->first;
    this->first->next = L.first->next;
    this->last->prev = L.last->prev;
    this->last->next = this->last;
    L.Length = 0;
    L.first->next = L.last;
    L.last->prev = L.first;
}


template <typename T>
List<T>::~List(){
    iterator it = this->end();
    iterator iit = it;
    --it;
    while (iit != this->begin()){
        delete iit.iter;
        iit = it;
        --it;
    }
    delete iit.iter;
    delete it.iter;
}

template <typename T>
bool List<T>::empty() const {
return (this->length == 0);
}

template <typename T>
std::size_t List<T>::length() const {
    return this->Length;
}

template <typename T>
List<T>::iterator::iterator(const List<T>::iterator &it){
    *this = it;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++ (){
    this->iter = this->iter->next;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++ (int){
    iterator it = this->iter;
    ++(*this);
    return it;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator-- (){
    this->iter = this->iter->prev;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator-- (int){
    iterator it = this->iter;
    --(*this);
    return it;
}

template <typename T>
T &List<T>::iterator::operator*(){
    return this->iter->Val;
}

template <typename T>
bool List<T>::iterator::operator==(iterator it){
    return (this->iter == it.iter);
}

template <typename T>
bool List<T>::iterator::operator!=(iterator it){
    return (this->iter != it.iter);
}

template <typename T>
typename List<T>::iterator &List<T>::iterator::operator= (const iterator &it){
    this->iter = it.iter;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::begin() const {
    iterator it;
    it.iter = this->first;
    return ++it;
}

template <typename T>
typename List<T>::iterator List<T>::end() const {
    iterator it;
    it.iter = this->last;
    return it;
}

template <typename T>
typename List<T>::iterator List<T>::operator[](std::size_t place){
    iterator it = this->begin();
    for (std::size_t i = 0; i < place; ++i){
        ++it;
    }
    return it;
}

template <typename T>
typename List<T>::iterator List<T>::insert(const T &val, iterator place){
    Elem *newelem = new Elem;
    newelem->Val = val;
    newelem->next = place.iter;
    newelem->prev = place.iter->prev;
    place.iter->prev->next = newelem;
    place.iter->prev = newelem;
    iterator it;
    it.iter = newelem;
    return it;
}

template <typename T>
typename List<T>::iterator List<T>::push_back(const T &val){
    return this->insert(val, this->end());
}

template <typename T>
typename List<T>::iterator List<T>::push_front(const T &val){
    return this->insert(val, this->begin());
}

template <typename T>
typename List<T>::iterator List<T>::remove(iterator place){
    Pelem nex = place.iter->next, pre = place.iter->prev;
    nex->prev = pre;
    pre->next = nex;
    delete place.iter;
    place.iter = nex;
    return place;
}

template <typename T>
typename List<T>::iterator List<T>::pop_front(){
    return remove(begin());
}

template <typename T>
typename List<T>::iterator List<T>::pop_back(){
    iterator it = end();
    --it;
    return remove(it);
}

template <typename T>
T &List<T>::front(){
    return *(begin());
}

template <typename T>
T &List<T>::back(){
    iterator it = end();
    --it;
    return *it;
}

template <typename T>
std::ostream &operator<< (std::ostream &out, const List<T> &lt){
    for (auto it = lt.begin(); it != lt.end(); ++it){
        out << *it << " ";
    }
    out << std::endl;
    return out;
};

template <typename T>
std::istream &operator>> (std::istream &in, List<T> &lt){
    for (auto it = lt.begin(); it != lt.end(); ++it){
        in >> *it;
    }
    return in;
}

template <typename T>
List<T> List<T>::operator= (const List<T> &L){
    this->first = new Elem;
    this->last = new Elem;
    this->Length = 0;
    this->first->prev = this->first;
    this->first->next = this->last;
    this->last->prev = this->first;
    this->last->next = this->last;
    for (auto it = L.begin(); it != L.end(); ++it){
        this->push_back(*it);
    }
    return *this;
}

template <typename T>
List<T> List<T>::operator= (List<T> &&L){
    this->first = new Elem;
    this->last = new Elem;
    this->Length = L.Length;
    this->first->prev = this->first;
    this->first->next = L.first->next;
    this->last->prev = L.last->prev;
    this->last->next = this->last;
    L.Length = 0;
    L.first->next = L.last;
    L.last->prev = L.first;
    return *this;
}

#endif // LIST_H_INCLUDED
