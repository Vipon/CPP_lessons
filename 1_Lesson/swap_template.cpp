#include <cstdio>
#include <cstdlib>
#include <cstring>


//template <class T> // C++03
template <typename T> // C++11
void swapP(T *a, T *b)
{
    printf("I'm ordinary swapP.\n");
    if (a == NULL || b == NULL)
        return;

    T t = *a;
    *a = *b;
    *b = t;
}


struct section {
    double start;
    double end;
};


template <> void swapP<section>(section *a, section *b)
{
    printf("I'm special swapP for struct section.\n");
    if (a == NULL || b == NULL)
        return;

    section t = {};
    t.start = a->start;
    t.end = a->end;
    a->start = b->start;
    a->end = b->end;
    b->start = t.start;
    b->end = t.end;
}


template <typename T> // C++11
void swap(T &a, T &b)
{
    printf("I'm swap with references.\n");

    T t = a;
    a = b;
    b = t;
}


int main()
{
    int ai = 0, bi = 1;
    double ad = 10.0, bd = 11.0;

    printf("ai = %d, bi = %d\n", ai, bi);
    swapP(&ai, &bi);
    printf("ai = %d, bi = %d\n\n", ai, bi);

    printf("ad = %lf, bd = %lf\n", ad, bd);
    swapP(&ad, &bd);
    printf("ad = %lf, bd = %lf\n\n", ad, bd);

    section sec0 = {-10.0, 30.5};
    section sec1 = {10.0, 56.7};
    swapP(&sec0, &sec1);

    swap(sec0, sec1);

    return 0;
}
