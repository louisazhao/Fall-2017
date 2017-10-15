//
//  main.cpp
//  Knight's Tour
//
//  Created by Zhao Rui on 2017-08-22.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

const size_t column{8};
const size_t row{8};
unsigned int counter{1};
array<int, 8> horizontal {2,1,-1,-2,-2,-1,1,2};
array<int, 8> vertical {-1,-2,-2,-1,1,2,2,1};
array<array<int, column>, row> access;
array<array<int, column>, row> grid{};

void moves(int&, int&, int, array<array<int, column>, row>&);
bool canMove(int,int,int,array<array<int, column>, row>&);
int opMoveNumber(int, int, const array<array<int, column>, row>&);


int main() {
    access[0]={2,3,4,4,4,4,3,2}; access[7]={2,3,4,4,4,4,3,2};
    access[1]={3,4,6,6,6,6,4,3};access[6]={3,4,6,6,6,6,4,3};
    access[2]={4,6,8,8,8,8,6,4}; access[3]={4,6,8,8,8,8,6,4}; access[4]={4,6,8,8,8,8,6,4};access[5]={4,6,8,8,8,8,6,4};

    cout<<"Game starts!\nThe Knight is palced at the center of the grid with position[3][4]."<<endl;
    int currentRow=3;
    int currentColumn=4;
    grid[currentRow][currentColumn]=1;
//    srand(static_cast<unsigned int>(time (0)));
//    int moveNumber{rand()%8};
    
    
    int moveNumber=opMoveNumber(currentRow, currentColumn, access);
    while(counter<=64&&moveNumber!=8)
    {
        moves(currentRow,currentColumn,moveNumber,grid);
        moveNumber=opMoveNumber(currentRow, currentColumn, access);
    }
    
    cout<<"\n\nNo more avaliable moves!"<<endl;
}


void moves(int& currentRow, int& currentColumn, int moveNumber, array<array<int, column>, row>& array)
{
        currentRow+=vertical[moveNumber];
        currentColumn+=horizontal[moveNumber];
        cout<<"Move "<<counter;
        cout<<"\nUsing the "<<moveNumber<<" kind of moving.\nThe knight has moved to position ["<<currentRow<<"]["<<currentColumn<<"]."<<endl;
        counter++;
        array[currentRow][currentColumn]=1;
        access[currentRow][currentColumn]=10;
}

bool canMove(int currentRow, int currentColumn, int moveNumber, array<array<int, column>, row>& array)
{
    int potentialRow{currentRow+vertical[moveNumber]};
    int potentialColumn{currentColumn+horizontal[moveNumber]};
    
    return array[potentialRow][potentialColumn]==0&&potentialRow>=0&&potentialRow<=7&&potentialColumn>=0&&potentialColumn<=7;
}

int opMoveNumber(int currentRow, int currentColumn, const array<array<int, column>, row>& array)
{
    int minAccess=9;
    int optiMoveNumber=8;

    if(canMove(currentRow, currentColumn, 0, grid)&&access[currentRow+vertical[0]][currentColumn+horizontal[0]]<minAccess)
    {
        minAccess=array[currentRow+vertical[0]][currentColumn+horizontal[0]];
        optiMoveNumber=0;
    }
    if(canMove(currentRow, currentColumn, 1, grid)&&array[currentRow+vertical[1]][currentColumn+horizontal[1]]<minAccess)
    {
        minAccess=array[currentRow+vertical[1]][currentColumn+horizontal[1]];
        optiMoveNumber=1;
    }
    if(canMove(currentRow, currentColumn, 2, grid)&&array[currentRow+vertical[2]][currentColumn+horizontal[2]]<minAccess)
    {
        minAccess=array[currentRow+vertical[2]][currentColumn+horizontal[2]];
        optiMoveNumber=2;
    }
    if(canMove(currentRow, currentColumn, 3, grid)&&array[currentRow+vertical[3]][currentColumn+horizontal[3]]<minAccess)
    {
        minAccess=array[currentRow+vertical[3]][currentColumn+horizontal[3]];
        optiMoveNumber=3;
    }
    if(canMove(currentRow, currentColumn, 4, grid)&&array[currentRow+vertical[4]][currentColumn+horizontal[4]]<minAccess)
    {
        minAccess=array[currentRow+vertical[4]][currentColumn+horizontal[4]];
        optiMoveNumber=4;
    }
    if(canMove(currentRow, currentColumn, 5, grid)&&array[currentRow+vertical[5]][currentColumn+horizontal[5]]<minAccess)
    {
        minAccess=array[currentRow+vertical[5]][currentColumn+horizontal[5]];
        optiMoveNumber=5;
    }
    if(canMove(currentRow, currentColumn, 6, grid)&&array[currentRow+vertical[6]][currentColumn+horizontal[6]]<minAccess)
    {
        minAccess=array[currentRow+vertical[6]][currentColumn+horizontal[6]];
        optiMoveNumber=6;
    }
    if(canMove(currentRow, currentColumn, 7, grid)&&array[currentRow+vertical[7]][currentColumn+horizontal[7]]<minAccess)
    {
        minAccess=array[currentRow+vertical[7]][currentColumn+horizontal[7]];
        optiMoveNumber=7;
    }
    
    return optiMoveNumber;
}
