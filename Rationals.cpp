#include "Rationals.h"

int main() {

    try {
        Rational a(3,4); //check C++11 new initialization
        Rational b = Rational(10,12);
        Rational f(0,1);
        
        std::cout<<"NOD of 4 and 7 = "<<absNOD(4,7)<<std::endl;
        std::cout<<"Simple form of a = 3/4 is "<<a<<std::endl;
        std::cout<<"Simple form of b = 10/12 is "<<b<<std::endl;
        std::cout<<"a + b = "<<a+b<<std::endl; //shows plus
        std::cout<<"a * b = "<<a*b<<std::endl; //shows multiplication
        
        std::cout<<"Now checking input from the console: ";
        std::cin >> f ;
        std::cout<<"Program see f = "<<f<<std::endl;
        
        std::cout<<"Rational f + integer 1 = "<<f+1<<std::endl;
        std::cout<<"Rational f - integer 1 = "<<f-1<<std::endl; //update constructor to work with negative values
        std::cout<<"Rational f * integer 2 = "<<f*2<<std::endl;
        std::cout<<"Rational f / integer 2 = "<<f/2<<std::endl;
        std::cout<<"integer 2 / Rational f = "<<2/f<<std::endl;
        
    } catch(std::invalid_argument& msg) {
        std::cerr<<std::endl;
        std::cerr<< msg.what()<<std::endl;
    }
    
    return 0;
}
