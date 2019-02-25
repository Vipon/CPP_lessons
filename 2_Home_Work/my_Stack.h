#ifndef MY_STACK_H_INCLUDED
#define MY_STACK_H_INCLUDED

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
    List(){
        this->first = new Elem;
        this->last = new Elem;
        this->Length = 0;
        this->first->prev = this->first;
        this->first->next = this->last;
        this->last->prev = this->first;
        this->last->next = this->last;
    }

    ~List(){
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

    bool empty() const {
    return (this->length == 0);
    }

    std::size_t length() const {
        return this->Length;
    }

    class iterator{
    public:
        iterator(){};

        ~iterator(){};

        iterator operator++ (){
            this->iter = this->iter->next;
            return *this;
        }

        iterator operator++ (int){
            iterator it = this->iter;
            ++(this->iter);
            return it;
        }

        iterator operator-- (){
            this->iter = this->iter->prev;
            return *this;
        }

        iterator operator-- (int){
            iterator it = this->iter;
            --(this->iter);
            return it;
        }

        T &operator*(){
            return this->iter->Val;
        }

        bool operator==(iterator it){
            return (this->iter == it.iter);
        }

        bool operator!=(iterator it){
            return (this->iter != it.iter);
        }

    protected:
        Pelem iter;

        friend List<T>;
    };

    iterator begin() const {
        iterator it;
        it.iter = this->first;
        return ++it;
    }

    iterator end() const {
        iterator it;
        it.iter = this->last;
        return it;
    }

    iterator operator[](std::size_t place){
        iterator it = this->begin();
        for (std::size_t i = 0; i < place; ++i){
            ++it;
        }
        return it;
    }

    iterator insert(const T &val, iterator place){
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

    iterator push_back(const T &val){
        return this->insert(val, this->end());
    }

    iterator push_front(const T &val){
        return this->insert(val, this->begin());
    }

    iterator remove(iterator place){
        Pelem nex = place.iter->next, pre = place.iter->prev;
        nex->prev = pre;
        pre->next = nex;
        delete place.iter;
        place.iter = nex;
        return place;
    }

    iterator pop_front(){
        return remove(begin());
    }

    iterator pop_back(){
        iterator it = end();
        --it;
        return remove(it);
    }

    T &front(){
        return *(begin());
    }

    T &back(){
        iterator it = end();
        --it;
        return *it;
    }

    friend List<T>::iterator;
};

template <typename T>
class Stack : protected List<T>{
public:
    Stack() : List<T>(){};

    ~Stack();

    bool empty() const;

    std::size_t length() const;

    void push(const T &val){
        List<T>::push_back(val);
    }

    void pop(){
        List<T>::pop_back();
    }

    T &back();
};

#endif // MY_STACK_H_INCLUDED
