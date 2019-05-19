#include "nonTypeTemplate.h"

int main()
{
    int i5[] = {0, 1, 2, 4, 5};
    // Implicit creation new class nonTypeTemplate<int, 5> from template.
    nonTypeTemplate<int, sizeof(i5)/sizeof(int)> iNtt5(i5, sizeof(i5)/sizeof(int));
    iNtt5.show();

    // Implicit creation new class nonTypeTemplate<int, 100> from template.
    nonTypeTemplate<int, 100> iNtt100;
    iNtt100.show();

    // Implicit creation new class nonTypeTemplate<double, 100> from template.
    nonTypeTemplate<double, 100> dNtt100;
    dNtt100.show();

    // All three classes are different and not sublings.
    return 0;
}