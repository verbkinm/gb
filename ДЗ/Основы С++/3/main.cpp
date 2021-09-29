#include <iostream>
#include <ctime>

int main()
{
    // 2
    std::cout << "task 2:" << std::endl;
    srand(time(NULL));
    int digit = 10 + rand() % 30;
    int result = 0;

    result = (digit <= 21 ? digit - 21 : (digit - 21) * 2);

    std::cout << "digit = " << digit << std::endl;
    std::cout << "result = " << result << std::endl;

    // 3
    std::cout << std::endl << "task 3:" << std::endl;

    int arr[3][3][3] = { { {11, 12, 13}, {14, 15, 16}, {17, 18, 19} },
                         { {21, 22, 23}, {24, 555, 26}, {27, 28, 29} },
                         { {31, 32, 33}, {34, 35, 36}, {37, 38, 39} }
                       };

    int *ptr = &arr[1][1][1];
    std::cout << "arr[1][1][1] = " << *ptr << std::endl;

    ptr = arr[0][0]; // ptr = &arr[0][0][0];
    std::cout << "arr[1][1][1] = " << *(ptr + 13) << std::endl;

    void* ptrV = &arr;
    std::cout << "arr[1][1][1] = " << *(static_cast<int*>(ptrV) + 13) << std::endl;

    // 4
    std::cout << std::endl << "task 4:" << std::endl;

    extern int a, b, c, d;
    std::cout << "result = " << a * (b + (static_cast<float>(c) / d));

    return 0;
}
