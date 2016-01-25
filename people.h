//
//  people.h
//  Final Project #2
//
//  Created by Derek Hansen on 6/25/15.
//  Copyright (c) 2015 Derek Hansen. All rights reserved.
//

#ifndef __Final_Project__2__people__
#define __Final_Project__2__people__

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class People
{

    public:
    
    People(string name);
    
    People(string name, int hours);
    
    string getname();
    
    int hrswork();
    
    bool oncall;
    
    void setName(string name);
    
    void setHours(int hours);
    
    string saveemp();
    
    private:
    
    string name;
    
    int hours;

};

#endif /* defined(__Final_Project__2__people__) */
