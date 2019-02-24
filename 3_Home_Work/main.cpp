#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix <int,3> A, B, C;
    for (int i = 0; i < 9; ++i){
        A[{i / 3, i % 3}] = i * 2;
    }
    cout << A;
    cout << endl;

    B = A;
    B *= 3;
    cout << B;
    cout << endl;

    B -= A + A;
    cout << B;
    cout << endl;

    C = B + A;
    cout << C;
    cout << endl;

    C = B + (A * (-4));
    C = (A * (-4)) + B;
    cout << C;
    cout << endl;

    cout << A;
    cout << endl;

    int arr[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix <int, 3> E(arr);
    cout << E;
    cout << endl;

    A *= E;
    cout << A;
    cout << endl;

    B = A * (3 * E);
    cout << B;
    cout << endl;

    cin >> C;
    cout << C;
    return 0;
}
