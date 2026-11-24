#include <iostream>
#include "Vector.h"

int main()
{
    Vector numbers(3);
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Capacity: " << numbers.capacity() << std::endl;
    std::cout << "Second element: " << numbers[1] << std::endl;

    Vector copy(numbers);
    copy[0] = 99;
    std::cout << "Original first element: " << numbers[0] << std::endl;
    std::cout << "Copy first element: " << copy[0] << std::endl;

    std::cout << "Removed element: " << numbers.pop_back() << std::endl;
    numbers.resize(5, 7);
    std::cout << "Last new element: " << numbers[4] << std::endl;

    return 0;
}
