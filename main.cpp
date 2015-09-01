#include <iostream>
#include <core/vector/Vector2D.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    core::vector::Vector2D test(1, 2);
    core::vector::Vector2D test2(3, 4);

    std::cout << test + test2 << std::endl;
    std::cout << test - test2 << std::endl;
    std::cout << !test << std::endl;
    std::cout << -test << std::endl;
    return 0;
}

