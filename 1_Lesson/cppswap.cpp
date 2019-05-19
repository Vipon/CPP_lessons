#include <cstdio>
#include <cstdlib>
#include <cstring>


void cppswap(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;

    int t = 0;
    t = *a;
    *a = *b;
    *b = t;
}


void cppswap(double *a, double *b)
{
    if (a == NULL || b == NULL)
        return;

    double t = 0;
    t = *a;
    *a = *b;
    *b = t;
}


void cppswap(void *a, void *b, size_t size)
{
    if (a == NULL || b == NULL)
        return;

    void *t = malloc(size);
    if (t == NULL)
        return;

    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);

    free(t);
}


int main()
{
    int ai = 0, bi = 1;
    double ad = 10.0, bd = 11.0;

    printf("ai = %d, bi = %d\n", ai, bi);
    printf("cppswap(&ai, &bi)\n");
    cppswap(&ai, &bi);
    printf("ai = %d, bi = %d\n\n", ai, bi);

    printf("ad = %lf, bd = %lf\n", ad, bd);
    printf("cppswap(&ad, &bd)\n");
    cppswap(&ad, &bd);
    printf("ad = %lf, bd = %lf\n\n", ad, bd);

    char str0[] = "dead";
    char str1[] = "beef";

    printf("str0: %s, str1: %s\n", str0, str1);
    printf("cppswap(str0, str1, sizeof(str0))\n");
    cppswap(str0, str1, sizeof(str0));
    printf("str0: %s, str1: %s\n\n", str0, str1);
    return 0;
}
