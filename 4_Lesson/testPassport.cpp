#include "Passport.h"

int main()
{
    std::cout << "Create valPass\n";
    Passport valPass("Valerii", 23, "Dolgoprudny");
    std::cout << '\n';

    std::cout << "Create markId\n";
    Id markId("Mark", 24);
    std::cout << '\n';

    std::cout << "Create markPass from markId\n";
    Passport markPass(markId, "Moscow");
    //markPass.~Passport();
    std::cout << '\n';

    std::cout << "Create moveMarkPass from markPass\n";
    Passport moveMarkPass(markPass);
    std::cout << '\n';

    std::cout << "Create newMarkPass from moveMarkPass\n";
    Passport newMarkPass(std::move(moveMarkPass));
    std::cout << '\n';

    return 0;
}
