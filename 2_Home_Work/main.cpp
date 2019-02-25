#include <cstdio>
#include<iostream>

#include "Stack.h"


int main(){
	
	Stack ST;

	for (uint8_t i = 0; i < 9; ++i){
		ST.push(i); 
	
	}
	
	ST.dump();

	ST.push(456);
	std::cout << ST.pop() << std::endl;	


	return 0;
}