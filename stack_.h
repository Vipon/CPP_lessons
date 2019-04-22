#ifndef stack__h
#define stack__h
#include <exception>
#include <iostream>

/*int NOD (int a, int b){
    
    while (a && b){
        if(a>0 && b>0){
            if (a>b){
                a%=b;
            } else {
                b%=a;
            }
        }
    }
    return a+b;
}*/

int absNOD (int a, int b){
    
    while (a && b){
        
        if(a>0 && b>0){
            if (a>b){
                a%=b;
            } else {
                b%=a;
            }
        } else {
            if(a<0){
                a*=-1;
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            }
            if(b<0){
                b*=-1;
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            }
        
    }
        
        /*if(a>=0){
            if(b>0){
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            } else {
                b*=-1;
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            }
        } else {
            a*=-1;
            if(b>0){
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            } else {
                b*=-1;
                if (a>b){
                    a%=b;
                } else {
                    b%=a;
                }
            }
        }*/
        
    }
    return a+b;
}

class Rational {
    
public:
    
    Rational(){
        nominator = 0;
        denominator = 1;
    }
    
    Rational(const int& a, const int& b){ //there is a mistake in the constructor of class
        
        int c = absNOD(a, b);
        
        if(b == 0){
            throw std::invalid_argument("Never divide by 0!");
        }
        
        if(a>=0){
            if(b>0){
                nominator = a/c;
                denominator = b/c;
            } else {
                nominator = -a/c;
                denominator = -b/c;
            }
        } else {
            if(b>0){
                nominator = a/c;
                denominator = b/c;
            } else {
                nominator = -a/c;
                denominator = -b/c;
            }
        }
    }
    
    /*Rational(const int& a, const int& b){ //there is a mistake in the constructor of class
        
        int c = abs(NOD(a, b));
        
        if (b==0){
            throw std::invalid_argument("Never divide by 0!");
        } else {
            if (a>=0 && b>0){
                nominator = a/c;
                denominator = b/c;
            } else {
                if (a>0 && b<0){
                    nominator = -a/c;
                    denominator = -b/c;
                } else {
                    if (a<0 && b>0){
                        nominator = -a/c;
                        denominator = -b/c;
                    }
                }
            }
        }
    }*/
    
    /*Rational(const int& a, const int& b){ //there is a mistake in the constructor of class
        
        int c = abs(NOD(a, b));
        
        if(b == 0){
            throw std::invalid_argument("Never divide by 0!");
        }
        
        if(a>=0 && b>0){
            nominator = a/c;
            denominator = b/c;
        } else {
            nominator = -a/c;
            denominator = -b/c;
        }
        
    }*/
    
    friend Rational operator + (const Rational& a, const Rational& b) { 
        
        return Rational(a.nominator*b.denominator+b.nominator*a.denominator, a.denominator*b.denominator);
    }
    
    friend Rational operator + (const Rational& a, const int& b) {
        
        return Rational(a.nominator+a.denominator*b, a.denominator);
    }
    
    friend Rational operator - (const Rational& a, const Rational& b) {
        
        return Rational(a.nominator*b.denominator-b.nominator*a.denominator, a.denominator*b.denominator);
    }
    
    friend Rational operator - (const Rational& a, const int& b) {
        
        return Rational(a.nominator-a.denominator*b, a.denominator);
    }
    
    friend Rational operator * (const Rational& a, const Rational& b) {
        
        return Rational(a.nominator*b.nominator, a.denominator*b.denominator);
    }
    
    friend Rational operator * (const Rational& a, const int& b) {
        
        return Rational(a.nominator*b, a.denominator);
    }
    
    friend Rational operator / (const Rational&a, const Rational& b) {
        if (b.nominator == 0){
            throw std::invalid_argument("Never divide by 0!");
        }
        return Rational(a.nominator*b.denominator, a.denominator*b.nominator);
    }
    
    friend Rational operator / (const Rational& a, const int& b) {
        if(b == 0){
            throw std::invalid_argument("Never divide by 0!");
        }
        return Rational(a.nominator, a.denominator*b);
    }
    
    friend Rational operator / (const int& b, const Rational& a) {
        if (a.nominator == 0){
            throw std::invalid_argument("Never divide by 0!");
        }
        return Rational(b*a.denominator,a.nominator);
    }
    
    friend std::ostream& operator << (std::ostream& stream, const Rational& R){
        if (R.denominator == 1){
            stream << R.nominator;
        } else {
            if (R.nominator == 0){
                stream << R.nominator;
            } else {
            stream << R.nominator << "/" << R.denominator;
            }
        }
        return stream;
    }
    
    friend std::istream& operator >> (std::istream& stream, Rational& R){

        stream >> R.nominator;
        if( stream.peek() == '/' ) { //смотрит символ в потоке, но не забирает его
            stream.ignore(1);
            if(stream.peek()=='-')
            {
                stream.ignore(1);
                R.nominator*=-1;
                R.denominator*=-1;
            }
            stream >> R.denominator;
        } else {
            R.denominator = 1;
        }
        
        return stream;
    } //check how to work with strings
    
    friend void RPrint(const Rational& a){
        std::cout<<"nominator = "<<a.nominator<<std::endl;
        std::cout<<"denominator = "<<a.denominator<<std::endl;
     }
    
private:
    int nominator;
    int denominator;
};

template<typename data, int N = 64>
class Stack {
public:
    
    void push(const data& F){
        if (current >= N) {
            throw std::range_error("out of range");
        }
        _ar[current++] = F;
    }
    
    data pop(){
        if (current == 0){
            throw std::underflow_error("Invalid memory");
        }
        return _ar[--current];
    }
    
    void dump(){
        for(current = 0; current<N;current++){
            std::cout << _ar[current] << " ";
        }
    }
    
    void isFull(){
        if (current >= N) {
            std::cout << "Full" << std::endl;
        } else {
            std::cout << "Not Full" << std::endl;
        }
    }
    
    void isEmpty(){
        if (current == 0){
            std::cout << "Empty" << std::endl;;
        } else {
            std::cout << "Not Empty" << std::endl;
        }
    }
    
    Stack() = default;
    Stack(const Stack& p);
      /*  while(auto: w *_ar){
            _ar[n] = 0;
            N--;
        } */ //TODO!
    ~Stack() = default;
    
    
    
private:
    data _ar[N];
    unsigned int current = 0;
};

#endif /* stack__h */

// methods >> alchoritms in priority of using
// qt for graphics, works with 3D objects, maps and sensors on phone (and not only)
// boost library is essential for C++ programminsts
// qt has expand for C++, Python etc. (расширения) 
