#include <iostream>
#include "Storage.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>

bool isWanted(const std::string & line);
std::string i_number;
std::fstream read;

std::map<int, std::string> m;

void Actions::menu(int option)
{
    int option_2;
    

    switch(option)
    {

        case 1:
        std::cout << "Here is the content of your purchased Items: ";
        std::cout << std::endl;


        read.open("Items.txt", std::ios::in);
        if ( read.is_open())
        {
            std::string r;
            while(std::getline(read, r))
            {
                std::cout << r << "\n";
            }
            read.close();

        }

        break;
        case 2: 
        std::cout << "What would you like to do with an Item\n";
        std::cout << "1.Add\n2.Remove\n3.Edit:" << std::endl; 
        std::cin >> option_2;
        if ( option_2 == 1)
        {   
            Storage item;
            int length;
            std::ifstream emptyOrNot;

            emptyOrNot.open("Items.txt", std::ios::binary); 
            emptyOrNot.seekg(0, std::ios::end); //puts the cursors at the end of the file 
            length = emptyOrNot.tellg(); //finds the position of the cursos = numbers of chars
            emptyOrNot.close();

            std::cout << "The length is: " << length << std::endl;

            if( length == 0)
            {
                item.item_num = 1;

                std::cout << "Enter the details of the Item" << std::endl;
                std::cout << "Item Name:" << std::endl;
                std::cin >> item.item_name;
                std::cout << "Date of purchase:" << std::endl;
                std::cin >> item.item_date;
                std::cout << "Item Price:" << std::endl;
                std::cin >> item.item_price;

                std::cout << "Has been added to your bill: " << item.item_num << " " <<"Product: " + item.item_name + "| " + " Bought: " +  item.item_date + "| " +  "Price: " + item.item_price + " Eur" << std::endl;
                
                std::ofstream myfile ("Items.txt", std::ios::app);
                if (myfile.is_open())
                {
                    myfile << item.item_num << " Product: " + item.item_name + " | " + " Bought: " +  item.item_date + "| " +  "Price: " + item.item_price + " Eur" << std::endl;
                    myfile.close();
                }
            }

            else
            {
                std::string s;
                int sTotal;
                std::ifstream in;
                in.open("Items.txt");

                while (!in.eof())
                {
                    getline(in, s);
                    sTotal ++;
                }
                std::cout << "The amount of lines is: "<< sTotal - 2 << std::endl;

                in.close();
                
                item.item_num = sTotal - 2;



                std::cout << "Enter the details of the Item" << std::endl;
                std::cout << "Item Name:" << std::endl;
                std::cin >> item.item_name;
                std::cout << "Date of purchase:" << std::endl;
                std::cin >> item.item_date;
                std::cout << "Item Price:" << std::endl;
                std::cin >> item.item_price;

                 

                std::cout << "Has been added to the biling list: " << item.item_num << " " <<"Product: " + item.item_name + "| " + " Bought: " +  item.item_date + "| " +  "Price: " + item.item_price + " Eur" << std::endl;

                std::ofstream myfile ("Items.txt", std::ios::app);
                if (myfile.is_open())
                {
                    myfile << item.item_num << " Product: " + item.item_name + " | " + " Bought: " +  item.item_date + " | " +  "Price: " + item.item_price + " Eur" << std::endl;
                    myfile.close();
                }
            }


            
           

        }   
        
        else if( option_2 == 2)
        {
            std::cout << "Work in Progress 2";
        }
        else if( option_2 == 3)
        {
            std::string filename ="Items.txt";
            std::ifstream fin;
            fin.open(filename);
            if(fin.is_open())
            {
                fin.seekg(-1, std::ios_base::end);

                bool keepGoing = true;
                while(keepGoing)
                {
                    char ch;
                    fin.get(ch);

                    if((int)fin.tellg() <= 1)
                    {
                        fin.seekg(0);
                        keepGoing = false;
                    }
                    else if(ch == '\n')
                    {
                        keepGoing = false;
                    }
                    else
                    {
                        fin.seekg(-2, std::ios_base::cur);
                    }
                }

                std::string lastLine;
                getline(fin, lastLine);
                std::cout << "Result: " << lastLine << "\n";
            }
        }
        else
        {
            std::cout << "Wrong input, the progam will now exit";
        }
        break;
        case 3:
        break;
   }




};
