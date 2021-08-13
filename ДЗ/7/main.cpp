#include "mylib.h"
#include "employee.h"

#define SIZE 5

#define CHECK_RANGE(value, max) (value > 0 && value < max ? "true" : "false")
#define SWAP_INT(a,b) {int buff; buff = a; a = b; b = buff;}

int main()
{
    //TASK 1

    float* arr = MyLib::initArray(SIZE);
    if(arr)
    {
        MyLib::printArray(arr, SIZE);
        MyLib::calculateArr(arr, SIZE);

        delete[] arr;
    }

//    //TASK 2

//    std::cout << CHECK_RANGE(11, 10) << std::endl;

//    //TASK 3

//    int arrInt[SIZE];

//    for(int i = 0; i < SIZE; i++)
//        std::cin >> arrInt[i];

//    printArray(arrInt, SIZE);

//    for(int i = 0; i < SIZE; i++)
//    {
//        for(int j = 0; j < SIZE - 1; j++)
//        {
//            if(arrInt[j] > arrInt[j + 1])
//                SWAP_INT(arrInt[j], arrInt[j + 1]);
//        }
//    }
//    printArray(arrInt, SIZE);

    //TASK 4

//    employee *ptrEmplyee = new employee;

//    ptrEmplyee->id = 1;
//    strcpy(ptrEmplyee->name, "Joe");
//    ptrEmplyee->phone = 555;

//    ptrEmplyee->printData();
//    std::cout << "Size employee struct: " << sizeof (*ptrEmplyee);
//    ptrEmplyee->saveToFile("save.txt");

//    delete ptrEmplyee;

    return 0;
}
