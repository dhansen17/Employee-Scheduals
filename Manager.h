//
//  Manager.h
//  Final Project #2
//
//  Created by Derek Hansen on 6/29/15.
//  Copyright (c) 2015 Derek Hansen. All rights reserved.
//

#ifndef __Final_Project__2__Manager__
#define __Final_Project__2__Manager__

#include <stdio.h>
#include <string>
#include <algorithm>
#include "people.h"

using namespace std;

class Manager
{
    
public:
  
    void addEmployee(People p);
    
    int headcount(); // keep trak of how many we have
    
    int shiftlength(int length);
    
    string dayswork();//days emp. wants to work
    
    void listEmployees();
    
    void oncall();
    
    void removemployee();
    
    void updateinfo();
    
    void write_to_file();
    
    void open_file();
    
    void readempfile();
    
    void saveempfile();
    
private:
    
    int numofemp;
    
    int length; //for length of shift
    
    int lengthofshift;
    
    string daysworkday;
    
    vector<People> employeelist;
    

};

#endif /* defined(__Final_Project__2__Manager__) */
