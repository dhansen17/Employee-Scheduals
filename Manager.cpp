//
//  Manager.cpp
//  Final Project #2
//
//  Created by Derek Hansen on 6/29/15.
//  Copyright (c) 2015 Derek Hansen. All rights reserved.
//

#include "Manager.h"
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <map>
#include <unordered_map>



typedef vector<string> FileLines;
typedef map<string, string> Dict;
typedef vector<Dict> VectorDict;


// "Everything is a String" - Derek Hansen
typedef string Derek;
// "If it's not a String then It's a Vector String" - Derek Hansen
typedef vector<string> VectorDerek;


bool fileExist(string fname){
    if(ifstream(fname.c_str()))
    {
        return true;
    }
    else{
        return false;
    }
}

bool fileExistC(string fname){
    if(access(fname.c_str(), F_OK ) != -1) {
        return true;
    }
    else {
        return false;
    }
}

void writeFile(string fname, string data){
    if(!fileExist(fname)){
        ofstream file(fname.c_str());
    }
    ofstream outfile(fname.c_str(), ios_base::app);
    outfile << data;
    outfile.close();
}

void writeFileLine(string fname, string data){
    if(!fileExist(fname)){
        ofstream file(fname.c_str());
    }
    ofstream outfile(fname.c_str(), ios_base::app);
    outfile << data << "\n";
    outfile.close();
}

void writeFileLines(string fname, FileLines data){
    if(!fileExist(fname)){
        ofstream file(fname.c_str());
    }
    ofstream outfile(fname.c_str(), ios_base::app);
    for (int i=0; i<data.size(); i++) {
        outfile << data[i] << "\n";
    }
    outfile.close();
}

void emptyFile(string fname){
    ofstream file(fname.c_str());
    file.close();
}

Derek readFile(string fname){
    Derek line;
    Derek data;
    ifstream infile(fname.c_str());
    while(getline(infile,line))
    {
        data += line;
    }
    infile.close();
    return data;
}

FileLines readFileLines(string fname){
    FileLines lines;
    string line;
    ifstream infile(fname.c_str());
    while(getline(infile,line))
    {
        lines.push_back(line);
    }
    infile.close();
    return lines;
}

VectorDerek splitStringByDelim(Derek data, char delim){
    int pos = 0;
    Derek item;
    VectorDerek val;
    while (data[pos]){
        if (data[pos] == delim) {
            val.push_back(item);
            item = "";
        }
        else{
            item += data[pos];
        }
        pos += 1;
    }
    // we check if we have something in item
    if (item != "") {
        val.push_back(item);
    }
    return val;
}

VectorDict parseFileData(FileLines lines){
    /*
     this is too simple and assumes that
     val[0] => Name
     val[1] => Hours
     but it works so heck yeah
     */
    VectorDict data;
    for (int i=0; i<lines.size(); i++) {
        Dict row;
        VectorDerek val = splitStringByDelim(lines[i], '|');
        // naive way to assign it to dict
        if (val.size() >= 2) {
            row["name"] = val[0];
            row["hours"] = val[1];
            data.push_back(row);
        }
        else if (val.size() == 1){
            row["name"] = val[0];
            row["hours"] = "";
            data.push_back(row);
        }
    }
    return data;
}

int Manager::headcount()
{

    return employeelist.size();
    
}
//this is not needed when you call the hours from people

int Manager::shiftlength(int length)
{
    length = 8;
    
    return length;
}

string Manager::dayswork()
{
    return this->daysworkday;
}

void Manager::listEmployees()
{
    for (int j = 0 ; j < employeelist.size(); j++)
    {
        People k = employeelist[j];
        
        cout << k.getname() << "; " << k.hrswork() << endl;
    }
}

void Manager::addEmployee(People p)
{
    employeelist.push_back(p);
    
}


void Manager::oncall()
{
    for (int j = 0 ; j < employeelist.size(); j++)
    {
        People k = employeelist[j];
        
        if(k.oncall)
        {
            cout << "Your on call employee is " << k.getname()<< endl;
            return;
        }
    }
    cout << "You have no employees on call \n";
    
}

void Manager::removemployee()
{
    string name;
    
    cout << " what person do you need removed?\n";
    cin.ignore();
    getline(cin,name);
    
    for (int j = 0 ; j < employeelist.size(); j++)
    {
        People k = employeelist[j];
        
        if (k.getname() == name)
        {
        employeelist.erase(employeelist.begin()+j);
                   return;
        }
    }
    cout << "No one has that name. \n";
}

void Manager::updateinfo()
{
    string name;
    cout << " what person do you want to edit \n";
    cin.ignore();
    getline(cin,name);
    int pos = -1;
    
    for(int j = 0 ; j < employeelist.size(); j++)
    {
        People k = employeelist[j];
        //cout << "Checking name " << k.getname() << endl;
        //cout << "With name " << name << endl;
        if (k.getname() == name)
        {
            //cout << "found it " << j << endl;
            pos = j;
            break;
        }
    }
    
    if(pos < 0){
        cout << "No one has that name. \n"; // << pos << endl;
        return;
    }
    
    People def = employeelist[pos];
    People newEmp = People(def.getname(), def.hrswork());
    
    int hours;
    cout << " enter a new name, or else keep the name and simply press enter \n";
    cin.ignore(0);
    getline(cin, name);
    if(name!="")
    {
        newEmp.setName(name);
    }
    //
    cout << " enter the new hours, or else keep the hours by simply pressing 1 \n";
    cin >> hours;
    if(hours !=1)
    {
        newEmp.setHours(hours);
        
    }

    employeelist.erase(employeelist.begin()+pos);
    this->addEmployee(newEmp);

    /*
    // just creating empty people since we are going to override in the for loop
    People k = People("");
    
    for (int j = 0 ; j < employeelist.size(); j++)
    {
        k = employeelist[j];
        
        if (k.getname() == name)
        {
            //employeelist.erase(employeelist.begin()+j);
        
            break;
            //return;
        }
    }
    if (k.getname() == "")
    {
    cout << "No one has that name. \n";
    }
    
    else
    {
        //if we are here, we found individual
        
        string name;
       
        int hours;
        
        cout << " enter a new name, or else keep the name and simply press enter \n";
        
        cin.ignore();
        
        getline(cin, name);
        
        if(name!="")
        {
            k.setName(name);
        }
       
        cout << " enter the new hours, or else keep the hours by simply pressing 1 \n";
        
        cin >> hours;
        
        if(hours !=1)
        {
            k.setHours(hours);
        
        }
    }
    */
}

void Manager::write_to_file()
{
    
    string line ="";
    
    int num=0;
    
    ofstream your_file;
    your_file.open("Weekly_Schedual.csv");
    
    if(your_file.fail())
    {
        cout << "File doesn't exist \n";
        cout << "Exiting program \n";
    }
    
    your_file << "Monday, Tuesday, Wensday, Thursday, Friday, \n";
    
    for (int j = 0 ; j < employeelist.size(); j++)
    {
        People k = employeelist[j];
        
        if (num<5)
        {
            line +=  k.getname() + ",";
            num++;
        }
        
        else
        {
            your_file << line+"\n";
        
            line = "";
            num = 0;
        }
    }
    
    your_file << line+"\n";
    
    your_file.close();

}

void Manager::open_file()
{
    string filename;
    string ch;
    
    cout << "Enter the filename please. \n";
    
    cin >> filename;
    
    ifstream input(filename.c_str());
    
    if (input.fail())
    {
        cout << "sorry we didn't find that file, want to try again? (y/n) \n";
        
        cin >> ch;
        {
        if (ch == "Yes"||"yes")
        {
            cout << "Enter a filename please. \n";
            cin >> filename;
        }
        }
    }
    else
    {
      //  cout << filename << " exsits \n";
        
    }
}

void Manager::readempfile()
{
    FileLines fline = readFileLines("employee.csv");
    VectorDict parsedata = parseFileData(fline);
    
    for (int i=0; i<parsedata.size(); i++)
    {
        int h = atoi(parsedata[i]["hours"].c_str());
        People k = People(parsedata[i]["name"],h);
        addEmployee(k);
 
    }
}

void Manager::saveempfile()
{
    for (int i=0; i<employeelist.size(); i++)
    {
        writeFileLine("employee.csv", employeelist[i].saveemp());
    }
}

