#ifndef __LIST_H
#define __LIST_H

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>


class ListException : public std::exception {
public:
    ListException(std::string&& err) noexcept : exc(std::move(err)) {}
    ListException(ListException&& gExc) noexcept : exc(std::move(gExc.exc)) {}
    const char* what() const noexcept { return exc.c_str(); }
private:
    std::string exc;
};

template <typename T>
class List {

public:
    // default constructor
    List() {};

    List(T* Arr, size_t sizeArr) {
        begin = new Elem;
        if (begin == nullptr) {
            throw ListException("OUT OF MEMORY");
        }
        Elem *current = begin;
        for (int i = 0; i < sizeArr - 1; i++) {
            current->val = Arr[i];
            current->next = new Elem;
            if (current->next == nullptr) {
                throw ListException("OUT OF MEMORY");
            }
            current = current->next;
        }

        current->val = Arr[sizeArr - 1];
        current->next = nullptr;
        size = sizeArr;
     };

    //copy constructor
    List(const List<T>& L) {
        Elem* current = L.begin;
        begin = new Elem;
        if (begin == nullptr) {
            throw ListException("OUT OF MEMORY");
        }
        Elem* elem = begin;
        elem->val = current->val;

        while (current->next) {
            elem->next = new Elem;
            if (elem->next == nullptr) {
                throw ListException("OUT OF MEMORY");
            }

            elem = elem->next; 
            current = current->next;
            elem->val = current->val;
        }

        elem->next = nullptr;
        size = L.size;
    };


     //destructor
    ~List() {
        Elem* entry = begin;

        while (entry) {
            Elem* temp = entry;
            entry = entry->next;
            delete temp;
        }
        delete entry;
    }

    friend std::ostream& operator<<(std::ostream& out, List& list) {
        Elem* current = list.begin;

        while(current) {
            out << current->val << "  ";
            current = current->next;
        };
        out << std::endl;
        return out;
    }
    
    void push_front(T value) {
        begin->val = value;
    }

    //this fuction inserts element 'value' after element 'elem'
    void insert(T value, T elem) {
        Elem* current = begin;
        while (current->val != elem && current) {
            current = current->next;
        }

        if (current == nullptr) {
            throw ListException("ELEMENT NOT FOUND");
        }

        Elem* addElem = new Elem;
        if (addelem == nullptr) {
            throw ListException("OUT OF MEMORY");
        }
        Elem* temp = current->next;
        current->next = addElem;
        addElem->val = value;
        addElem->next = temp;

        size = size + 1;
    }
 
    //this function searches and removes first met element with value 'value'
    void search_and_remove(T value) {
        if (begin->val == value) {
            Elem* temp = begin;
            begin = begin->next;
            delete temp;
            size = size - 1;
            return;
        }

        Elem* current = begin;
        Elem* temp = current;

        while (current) {
            if (current->val == value) {
                temp->next = current->next;
                delete current;
                size = size - 1;
                return;
            }
            temp = current;
            current = current->next;
        }
        return;
    }


    friend std::istream& operator>>(std::istream& is, List& list) {
        T closing_el;
        T value;
        Elem* current;
        //first element you write wil be used only as closing one and not be put in list
        is >> closing_el;
        is >> value;
        
        if (value != closing_el) {
            list.size = 1;
            list.begin = new Elem;
            if (list.begin == nullptr) {
                throw ListException("OUT OF MEMORY");
            }
            list.begin->val = value;
            current = list.begin;
            is >> value;
        }
        else {
            list.size = 0;
            return is;
        }

        while (value != closing_el) {
            current->next = new Elem;
            if (current->next == nullptr) {
                throw ListException("OUT OF MEMORY");
            }
            current->next->val = value;
            list.size = list.size + 1;
            is >> value;
            if (value == closing_el) {
                current = current->next;
                current->next = nullptr;
            }
            else {
                current = current->next;
            }
        }
        return is;
    }
    


    T& operator[](size_t pos) {
        Elem* b = begin;

        for (size_t i = 0; i < pos; i++) {
            b = b->next;
        }
        return b->val;
    }
    

private:
    struct Elem {
        Elem *next;
        T val;
    };

    Elem *begin;
    size_t size;
    };

#endif //__LIST_H