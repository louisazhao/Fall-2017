//
//  main.cpp
//  HardwareStore
//
//  Created by Zhao Rui on 2017-09-03.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Hardwear.h"
#include <iomanip>
using namespace std;

enum class Choice{CREATE=1, PRINT, UPDATE,INSERT,DELETE,END};

Choice enterChoice();
void creatFile(fstream&);
void printFile(fstream&);
void updateFile(fstream&);
void insertFile(fstream&);
void deleteFile(fstream&);
void outputLine(ostream&, const Hardwear&);
int getNumber(const char* const);


int main() {
    
    fstream inOutHardwear{"Hardwear.dat",ios::in|ios::out|ios::binary};
    
    if(!inOutHardwear)
    {
        cerr<<"File coule not be opened."<<endl;
        exit(EXIT_FAILURE);
    }
    
    Choice choice;
    
    while ((choice=enterChoice()) != Choice::END) {
        switch (choice) {
            case Choice::CREATE:
                creatFile(inOutHardwear);
                break;
            case Choice::PRINT:
                printFile(inOutHardwear);
                break;
            case Choice::UPDATE:
                updateFile(inOutHardwear);
                break;
            case Choice::INSERT:
                insertFile(inOutHardwear);
                break;
            case Choice::DELETE:
                deleteFile(inOutHardwear);
                break;
            default:
                cerr<<"Incorrect choice."<<endl;
                break;
        }
        inOutHardwear.clear();
    }
}

Choice enterChoice()
{
    cout<<"\nEnter your choice:\n"
    <<"1 - creat a file and input the information\n"
    <<"2 - store a formatted text file for display\n"
    <<"3 - update a tool\n"
    <<"4 - add a tool\n"
    <<"5 - delete a tool\n"
    <<"6 - end program\n?";
    
    int menuChoice;
    cin>>menuChoice;
    return static_cast<Choice>(menuChoice);
}

void creatFile(fstream& writeToFile)
{
    Hardwear blankHardwear;
    for(int i=0;i<100;i++)
    {
        writeToFile.write(reinterpret_cast<const char*>(&blankHardwear),sizeof(Hardwear));
    }

    cout<<"Enter id number (1 to 100, 0 to end input)\n?";
    
    int id;
    string name;
    int qua;
    double cost;
    
    cin>>id;
    
    while(id>0&&id<=100)
    {
        cout<<"Enter the name, the quantity and the cost of the tool\n?";
        cin>>name;
        cin>>qua;
        cin>>cost;
        
        Hardwear newItem{id,name,qua,cost};
        
        writeToFile.seekp(
                          (newItem.getIdNumber()-1)*sizeof(Hardwear));
        
        writeToFile.write(
                          reinterpret_cast<const char*>(&newItem),sizeof(Hardwear));
        
        cout<<"Enter id number (1 to 100, 0 to end input)\n?";
        cin>>id;
    }
}

void printFile(fstream& readFromFile)
{
    ofstream printFile("print.txt",ios::out);
    
    if(!printFile)
    {
        cerr<<"File could not be created."<<endl;
        exit(EXIT_FAILURE);
    }
    
    printFile<<left<<setw(10)<<"ID"<< setw(16)<<"Tool name"<<right<<setw(10)<<"Quantity"<<setw(10)<<"Cost"<<endl;
    readFromFile.seekg(0);
    
    Hardwear newItem;
    readFromFile.read(
                      reinterpret_cast<char*>(&newItem),sizeof(Hardwear));
    
    while(!readFromFile.eof())
    {
        if(newItem.getIdNumber()!=0)
        {
            outputLine(printFile, newItem);
        }
        
        readFromFile.read(
                          reinterpret_cast<char*>(&newItem),sizeof(Hardwear));
    }
}

void updateFile(fstream& updateFile)
{
    int number{getNumber("Enter the id of the tool that you want to update\n")};
    
    updateFile.seekg((number-1)*sizeof(Hardwear));
    
    Hardwear item;
    updateFile.read(reinterpret_cast<char*>(&item), sizeof(Hardwear));
    
    if(item.getIdNumber()!=0)
    {
        outputLine(cout, item);
        cout<<"\nEnter the changed quantity: "<<endl;
        int change;
        cin>>change;
        
        int oldQuan=item.getQuantity();
        item.setQuantity(oldQuan+change);
        outputLine(cout, item);
        
        updateFile.seekp((number-1)*sizeof(Hardwear));
        updateFile.write(reinterpret_cast<const char*>(&item), sizeof(Hardwear));
    }
    else
    {
        cerr<<"No information for id number "<<number<<endl;
    }
}

void insertFile(fstream& insertFile)
{
    int number{getNumber("Enter the id of the tool that you want to insert\n")};
    insertFile.seekg((number-1)*sizeof(Hardwear));
    Hardwear item;
    insertFile.read(reinterpret_cast<char*>(&item), sizeof(Hardwear));
    if(item.getIdNumber()==0)
    {
        string name;
        int quan;
        double cost;
        cout<<"Enter the name, the quantity and the cost of the tool\n?";
        cin>>name;
        cin>>quan;
        cin>>cost;

        item.setName(name);
        item.setQuantity(quan);
        item.setCost(cost);
        item.setIdNumber(number);
        
        insertFile.seekp((number-1)*sizeof(Hardwear));
        
        insertFile.write(reinterpret_cast<const char*>(&item), sizeof(Hardwear));
    }
    else
    {
        cerr<<number<<" already has information."<<endl;
    }
}

void deleteFile(fstream& deleteFile)
{
    int number{getNumber("Enter the id of the tool that you want to delete\n")};
    deleteFile.seekg((number-1)*sizeof(Hardwear));
    Hardwear item;
    deleteFile.read(reinterpret_cast<char*>(&item), sizeof(Hardwear));
    if(item.getIdNumber()!=0)
    {
        Hardwear blanketItem;
        deleteFile.seekp((number-1)*sizeof(Hardwear));
        deleteFile.write(reinterpret_cast<const char*>(&blanketItem), sizeof(Hardwear));
        cout<<"ID number "<<number<<" deleted.\n";
    }
    else
        cerr<<"No information for id number "<<number<<endl;
}

void outputLine(ostream& output, const Hardwear& item)
{
    output<<left<<setw(10)<<item.getIdNumber()<< setw(16)<<item.getName()<<right<<setw(10)<<item.getQuantity()<<setw(10)<<setprecision(2)<<fixed<<showpoint<<item.getCost()<<endl;
}

int getNumber(const char* const prompt)
{
    int number;
    do{
        cout<<prompt<<"(1-100): ";
        cin>>number;
    }while(number<1||number>100);
    
    return number;
}
