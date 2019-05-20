#ifndef vArray_h
#define vArray_h

#include <exception>
#include <iostream>

class vArray {
public:
    vArray(){
        ar = new int[64];
        size = 64;
    }
    
    vArray(const int& s){ // s - new size
        ar = new int[s];
        size = s;
        for(int i = 0; i < size; i++) {
            ar[i] = 0;
        }
    }
    
    vArray(const vArray& var){ //constructor of copying
        ar = new int[var.size];
        size = var.size;
        for(int i = 0; i < size; i++) {
            ar[i] = var.ar[i];
        }
    }
    
    ~vArray(){
        delete[] ar;
    }
    
    void resize (const int& s){
        int* a = new int[s];
        if(size > s){
            for(int i = 0; i < s; i++){
                a[i]=a[i];
            }
            delete[] ar;
            ar = a;
        } else {
            for(int i = 0; i < size; i++){
                a[i]=a[i];
            }
            delete[] ar;
            ar = a;
        }
    }
    
    int& operator[] (const int& i) {
        if(i >= size){
            std::cout << "Out of the edge" << std::endl;
            system("pause");
            exit(1);
        }
        return ar[i];
    }
    
    friend std::ostream& operator << (std::ostream& stream, const vArray& var){
        bool isfirst = true;
        for(int i = 0; i < var.size; i++){
            if(!isfirst){
                stream << " ";
            } else {
                isfirst = false;
            }
            stream << var.ar[i];
        }
        return stream;
    }
    
    friend std::istream& operator >> (std::istream& stream, vArray& var){ //beat it
        
        //int s = var.size;
        
        //delete[] var.ar;
        
        stream >> var.size;
        for(int i = 0; i < var.size; i++){
            stream >> var.ar[i];
        }
        return stream;
    }
    
    vArray operator = (const vArray& var){
        
        delete[] ar;
        
        ar = new int[var.size];
        size = var.size;
        for(int i = 0; i < size; i++){
            ar[i] = var.ar[i];
        }
        
        return *this;
    }
    
private:
    int* ar;
    int size;
};


#endif /* vArray_h */
