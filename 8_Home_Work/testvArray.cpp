#include "vArray.h"

int main() {
try {
    vArray<int> apple, banana;
    std::cin >> apple;
    std::cin >> banana;

    std::cout << apple << std::endl << banana << std::endl;
    apple += banana;

    std::cout << apple << std::endl;
    auto  = apple + banana;
    std::cout << cocout[999];
}   
catch (std::exception& error) {
    std::cout << error.what();
    exit (1);
};
    return 0;
} 