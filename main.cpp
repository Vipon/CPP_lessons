#include "stack_.h"

int main() {
 
    /*Stack<int, 8> s;
    
    try{
        s.push(2);
        s.push(7);
        s.push(1);
        s.push(8);
        s.push(2);
        s.push(6);
        s.push(1);
        s.push(8);
        s.push(2);
    } catch(std::range_error& msg) {
        std::cerr << msg.what() << std::endl;
    }
    
    s.dump();
    std::cout << std::endl;
    
    try{
        std::cout << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << std::endl;
    } catch(std::underflow_error& msg) {
        std::cerr << std::endl;
        std::cerr << msg.what() << std::endl;
    }
    
    s.isEmpty();
    s.isFull();*/
    try {
    Rational a(3,4); //check C++11 new initialization 
    Rational b = Rational(10,12);
    Rational f(0,1);
        
    //Rational e(1,0); //error!
    
    //std::cout<<e<<std::endl;
    
    std::cout<<"NOD of 4 and 7 = "<<absNOD(4,7)<<std::endl;
    std::cout<<"Simple form of a = 3/4 is "<<a<<std::endl;
    std::cout<<"Simple form of b = 10/12 is "<<b<<std::endl;
    std::cout<<"a + b = "<<a+b<<std::endl; //shows plus
    std::cout<<"a * b = "<<a*b<<std::endl; //shows multiplication
    
    std::cout<<"Now checking input from the console: ";
    std::cin >> f ;
    std::cout<<"Program see f = "<<f<<std::endl;
    
    //RPrint(f); //checks interpritation of Rational value
    
    std::cout<<"Rational f + integer 1 = "<<f+1<<std::endl;
    std::cout<<"Rational f - integer 1 = "<<f-1<<std::endl; //update constructor to work with negative values
    std::cout<<"Rational f * integer 2 = "<<f*2<<std::endl;
    std::cout<<"Rational f / integer 2 = "<<f/2<<std::endl;
    std::cout<<"integer 2 / Rational f = "<<2/f<<std::endl;
        
    //std::cout<<f+a<<std::endl;
    
    //std::cout<<"f - a = "<<f-a<<std::endl; //shows how f interract with other Rationals
    //std::cout<<"f / b = "<<f/b<<std::endl; //shows dividence
    
    //std::cout<<"Simple form of z = -5/15 is "<<Rational(5,15)<<std::endl;
    //std::cout<<"z - 1 = "<<Rational(-5,15)-1<<std::endl;
        
    } catch(std::invalid_argument msg) {
        std::cerr<<std::endl;
        std::cerr<< msg.what()<<std::endl;
    }
    
    return 0;
}
