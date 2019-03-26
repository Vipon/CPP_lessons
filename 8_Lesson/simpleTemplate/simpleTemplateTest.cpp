#include "simpleTemplate.h"
#include <iostream>


void iShow(const simpleTemplate<int>& t)
{
    t.show();
}


int main()
{
    simpleTemplate<int> iTemplate(100);
    simpleTemplate<double> dTemplate(100.0);

    // Correct call;
    iShow(iTemplate);

    // Wrond call - simpleTemplate<double> and simpleTemplate<int> are different classes.
    // iShow(dTemplate);

    return 0;
}
