#include <iostream>

void task1()
{
    std::cout << std::endl << "Task 1: " << std::endl;

    int number1 = 0, number2 = 0, sum = 0;

    std::cout << "Input two number: ";
    std::cin >> number1 >> number2;

    sum = number1 + number2;

    if(sum >= 10 && sum <= 20)
    {
        std::cout << "true" << std::endl;
    }
    else
        std::cout << "false" << std::endl;
}

void task2()
{
    std::cout << std::endl << "Task 2: " << std::endl;

    const int number1 = 10, number2 = 10;
    if((number1 == 10 && number2 == 10) || ((number1 + number2) == 10))
    {
        std::cout << "true" << std::endl;
    }
    else
        std::cout << "false" << std::endl;
}

void task3()
{
    std::cout << std::endl << "Task 3: " << std::endl;

    std::cout << "Your numbers: ";
    for(int i = 1; i < 51; ++i)
    {
        if(i % 2 != 0)
            std::cout << i << " ";
    }
}

void task4()
{
    std::cout << std::endl << "Task 4: " << std::endl;

    int number = 0;

    std::cout << "Input number: ";
    std::cin >> number;

    if (number > 1)
    {
        for (int i = 2; i < number; i++)
            if (number % i == 0)
            {
                std::cout << "Number is not simple" << std::endl;
                return;
            }
        std::cout << "Number is simple" << std::endl;
    }
    else
        std::cout << "Number is not simple" << std::endl;
}

void task5()
{
    std::cout << std::endl << "Task 5: " << std::endl;

    unsigned int year;

    std::cout << "Enter year: ";
    std::cin >> year;

    if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
        std::cout << "leap year";
    else
        std::cout << "Not leap year";

}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}
