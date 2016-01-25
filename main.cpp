//
//  main.cpp
//  Final Project #2
//
//  Created by Derek Hansen on 6/25/15.
//  Copyright (c) 2015 Derek Hansen. All rights reserved.
//

#include <fstream>
#include "people.h"
#include <string>
#include "Manager.h"

using namespace std;
//list of things you can choose to do
void menu_items(){
    cout << "\n\n\n1. Add Employee(s)" << endl;
    cout << "2. Update Employee" << endl;
    cout << "3. Remove Employee" << endl;
    cout << "4. List Employee" << endl;
    cout << "5. If you have already created a file, please give me that file name " << endl;
    cout << "6. Quit" << endl;
    //this is our menu items
    
}


int main()
{
    Manager mgr; //creating mgr type of Manager class type
    mgr.readempfile(); //read the emoloyee file defined in manager calss
    int number_emp;
    string name;
    int hours;
    
    
    int choice = 0;
    while (true) {
        menu_items();
        cout<<"Chose an option number:";
        cin>>choice;
        switch (choice) {
            case 1:
            {
                cout << " How many employees do you have? \n";
                
                cin >> number_emp;
                
                vector<People> employees;
                
                
                for (int i = 0 ; i < number_emp; i++)
                {
                    cout << "give me the name of the " << i + 1 << " person \n";
                    
                    cin.ignore();
                    
                    getline(cin, name);
                    
                    cout << " Please give me the hours that " << name << " is working, or enter 0 if they are on call \n";
                    
                    cin >> hours;
                    
                    
                    People Kootnie = People(name, hours);
                    
                    mgr.addEmployee(Kootnie);
                    
                    mgr.write_to_file();
                    
                }
            }
             break;
           
            case 2:
                mgr.updateinfo();
                
                mgr.write_to_file();

                break;
           
            case 3:
                mgr.removemployee();
                mgr.write_to_file();
                break;
           
            case 4:
                mgr.listEmployees();
                mgr.write_to_file();
                break;
            
                        case 5:
                mgr.open_file();
                
                
                break;
            case 6:
                 mgr.saveempfile();
                return 0;
                break;
            
            default:
                 mgr.saveempfile();
                return 0;
                break;
        }
    }
    
   
    
    return 0;

}
