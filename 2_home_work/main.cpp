#include "Stack.h"
#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstdlib> 

using namespace std;

int main()
{
	Stack st(5);
	int i = 0;
	while (i < 5)
	{
		st.push(i++);
	}
	st.dump();
	cout << st.isFull() << endl;
	st.~Stack();
	return 0;
}