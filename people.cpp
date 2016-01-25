//
//  people.cpp
//  Final Project #2
//
//  Created by Derek Hansen on 6/25/15.
//  Copyright (c) 2015 Derek Hansen. All rights reserved.
//

#include "people.h"

People::People(string name)//give me a name, everything else is defaulted
{
   this->name = name;
    
    oncall = false;
   
    hours = 40;
   // name = nwname; either way works. this is implicit (bad)
}

People::People(string name, int hours) //give me both hours and name of employee, also tell me if they are on call or not
{
    this->name = name;
    
    this->hours = hours;
    
    if(hours == 0)
    {
        oncall = true;
        
        this->hours = 40;
    }
    else
    {
    oncall = false;
    }
}


string People::getname()
{
    return this->name;
}

int People::hrswork()
{
    return hours;
}

void People::setName(string name)
{
    this->name = name;
}

void People::setHours(int hours)
{
    this->hours = hours;
}

string People::saveemp()
{
    string s = to_string(hours);
 
    return  name +"|" + s;
}