#include "Stack.h"
#include <cstdio>
#include <cstdlib> 
#include <iostream>

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