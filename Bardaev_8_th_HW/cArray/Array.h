#ifndef Array_h
#define Array_h

#include <iostream>
#include <exception>

template<typename data, int N = 64>
class Array {
public:
    
    data& operator[] (const int& i) {
        if(i >= N){
            std::cout << "Out of the edge" << std::endl;
            system("pause");
            exit(1);
        }
        return _ar[i];
    }
    
    Array() = default;
    Array(const int& val){ //constructor
        for(int i = 0; i < N; i++) {
            _ar[i] = val;
        }
    }
    /*Array(const Array& var){ //constructor of copy
     for(int i = 0; i < N; i++) {
     _ar[i] = var[i];
     }
     }*/
    
    ~Array() = default;
    
    friend std::ostream& operator << (std::ostream& stream, const Array& var){ //output
        /*bool isfirst = true;
         for(int i = 0; i < N; i++){
         if(!isfirst){
         stream << " ";
         } else {
         isfirst = false;
         }
         stream << var;
         }*/
        return stream;
    }
    
    friend std::istream& operator >> (std::istream& stream, Array& var){ //beat it, input
        
        for(int i = 0; i < N; i++){
            stream >> var[i];
        }
        return stream;
    }
    
    Array operator = (const Array& var){
        
        for(int i = 0; i < N; i++){
            _ar[i] = var[i];
        }
        
        return *this;
    }
    
private:
    data* _ar;
    unsigned int size = N;
    unsigned int current = 0;
};

#endif /* Array_h */
