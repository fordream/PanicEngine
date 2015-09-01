#include <iostream>
#include <core/vector/Vector2D.h>

using namespace std;
using namespace panicengine::core;

int main()
{
    cout << "Hello World!" << endl;
    vector::Vector2D test(1.0, 2.0);
    vector::Vector2D test2(3.0, 4.0);

    std::cout << test + test2 << std::endl;
    std::cout << test - test2 << std::endl;
    std::cout << !test << std::endl;
    std::cout << -test << std::endl;
    test.normalize();
    std::cout << test << std::endl;
    std::cout << test.length() << std::endl;
    vector::Vector2D perp = test.perp();
    std::cout << perp*test << std::endl;
    vector::Vector2D big (10, 30);
    std::cout << big.length() << std::endl;
    big.truncate(2);
    std::cout << big << std::endl;
    std::cout << big.length() << std::endl;
    std::cout << big.reverse() + big << std::endl;
    return 0;
}

