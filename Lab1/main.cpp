#include <cstdlib>
#include "trapeze.h"
#include "rhombus.h"
#include "pentagon.h"

void Menu()
{
    std::cout << "\n"
              << std::endl;
    std::cout << "1. Trapeze" << std::endl;
    std::cout << "2. Rhombus" << std::endl;
    std::cout << "3. Pentagon" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter figure number:";
}

int main(int argc, char **argv)
{
    Menu();
    int action;
    std::cin >> action;
    while (action != 0)
    {
        if (action == 1)
        {
            /*int* a = (int*)malloc(sizeof(int)*5);
            a[0] = 1;
            free(a);*/
            //Trapeze
            std::cout << "Trapeze created" << std::endl;
            Figure *ptr = new Trapeze(std::cin);
            ptr->Print();
            std::cout << "Square of trapeze:" << ptr->Square() << std::endl;
            delete ptr;
            Menu();
            std::cin >> action;
        }
        else if (action == 2)
        {

            //Rhombus
            std::cout << "Rhombus created: " << std::endl;
            Figure *ptr = new Rhombus(std::cin);
            ptr->Print();
            std::cout << "Square of rhombus:" << ptr->Square() << std::endl;
            delete ptr;
            Menu();
            std::cin >> action;
        }
        else if (action == 3)
        {

            //Pentagon
            std::cout << "Pentagon created: " << std::endl;
            Figure *ptr = new Pentagon(std::cin);
            ptr->Print();
            std::cout << "Square of pentagon:" << ptr->Square() << std::endl;
            delete ptr;
            Menu();
            std::cin >> action;
        }
        else
        {
            std::cout << "Incorrect input!" << std::endl;
            Menu();
            std::cin >> action;
        }
    }
    return 0;
}
