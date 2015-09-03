#include <core/vector/Vector2D.h>
#include <core/util/State.h>
#include <core/util/StateMachine.h>
#include <iostream>

using namespace std;
using namespace panicengine;

int main()
{
    cout << "Hello World!" << endl;
    Vector2D test(1.0, 2.0);
    Vector2D test2(3.0, 4.0);

    std::cout << test + test2 << std::endl;
    std::cout << test - test2 << std::endl;
    std::cout << !test << std::endl;
    std::cout << -test << std::endl;
    test.normalize();
    std::cout << test << std::endl;
    std::cout << test.length() << std::endl;
    Vector2D perp = test.perp();
    std::cout << perp*test << std::endl;
    Vector2D big (10, 30);
    std::cout << big.length() << std::endl;
    big.truncate(2);
    std::cout << big << std::endl;
    std::cout << big.length() << std::endl;
    std::cout << big.reverse() + big << std::endl;
    big.zero();
    std::cout << big << std::endl;

    // util::State<vector::Vector2D> state;
    return 0;
}

