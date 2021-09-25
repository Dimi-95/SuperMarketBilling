#include <iostream>
#include "Storage.h"


int main()
{
    int option;

    std::cout << "Super Market Billing System\n ====================" << std::endl;
    std::cout << "1.Bill Report" << std::endl;
    std::cout << "2.Add/Remove/Edit  Item" << std::endl;
    std::cout << "3.Exit" << std::endl;

    std::cin >> option;

    Actions action;

    action.menu(option);


    



    return 0;

}
