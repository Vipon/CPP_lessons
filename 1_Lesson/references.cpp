#include <cstdio>


int main()
{
    int a = 0;
    int *pointA = &a;
    int &refA = a;
    // refA = pointA;   // Error: second definition of references.

    printf("a = %d\t\t\trefA = %d\n", a, refA);
    printf("*a = %p\t*refA = %p\t*pointA = %p\n\n", &a, &refA, &pointA);
    printf("a = 100:\n");
    a = 100;
    printf("\ta = %d\t\trefA = %d\n", a, refA);
    printf("refA = 1000:\n");
    refA = 1000;
    printf("\ta = %d\trefA = %d\n", a, refA);
    return 0;
}