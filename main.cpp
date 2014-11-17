/* 
 * File:   main.cpp
 * Author: caner
 *
 * Created on November 13, 2014, 1:56 PM
 */

#include <iostream>
#include <cstdlib>
#include "GameOfLife.h"
#include "Cell.h"

using namespace std;
using GameLife::GameOfLife;
using Cells::Cell;
int GameOfLife::cellnumber=0;
int GameOfLife::tempcellnumber=0;
int GameOfLife::count=-1;
/*
 * 
 */
int main() {
    char fileName1[20],fileName2[20];
    GameOfLife game1,game2,game3,game4,game5,game6,game7,game8,game9,game10;
    GameOfLife game11,game12,game13,game14,game15,game16,game17;
    int boolss;
    Cell c1,c2,c3,c4,c5;
    c1.setCoorX(3);
    c1.setCoorY(0);
    c2.setCoorY(0);
    c2.setCoorX(0);
    c3.setCoorX(3);
    c3.setCoorY(2);
    
    cout <<"Enter the coorx and coory for cell"<<endl;
    cin >> c3;
    cout << "Initials value"<<endl;
    cout << c3<<endl;
    ++c3;
    cout << "PRE INCREMENT"<<endl;
    cout << c3<<endl;
    c4=c3++;
    cout << "POST INCREMENT"<<endl;
    cout << c4<<endl;
    --c4;
    cout << "PRE DECREMENT"<<endl;
    cout << c4<<endl;
    c5=c4--;
    cout << "POST DECREMENT"<<endl;
    cout << c5<<endl;
    
    boolss=c1<c2;
    cout << boolss<<endl;
    boolss=c1>c2;
    cout << boolss<<endl;
    boolss=c1>=c2;
    cout << boolss<<endl;
    boolss=c1<=c2;
    cout << boolss<<endl;
    boolss=c1==c2;
    cout << boolss<<endl;
    boolss=c1!=c2;
    cout << boolss<<endl;

    
    game1.setStartColumn(0);
    game1.setStartRow(0);
    game2.setStartColumn(0);
    game2.setStartRow(0);
    game3.setStartColumn(0);
    game3.setStartRow(0);
    game4.setStartColumn(0);
    game4.setStartRow(0);
    game5.setStartColumn(0);
    game5.setStartRow(0);
    game6.setStartColumn(0);
    game6.setStartRow(0);
    game7.setStartColumn(0);
    game7.setStartRow(0);
    game8.setStartColumn(0);
    game8.setStartRow(0);
    game9.setStartColumn(0);
    game9.setStartRow(0);
    game10.setStartColumn(0);
    game10.setStartRow(0);
    game11.setStartColumn(0);
    game11.setStartRow(0);
    game12.setStartColumn(0);
    game12.setStartRow(0);
    game13.setStartColumn(0);
    game13.setStartRow(0);
    game14.setStartColumn(0);
    game14.setStartRow(0);
    game15.setStartColumn(0);
    game15.setStartRow(0);
    game16.setStartColumn(0);
    game16.setStartRow(0);
    game17.setStartColumn(0);
    game17.setStartRow(0);


    cout << "Enter the file name for game1"<<endl;
    cin >> fileName1;
    cout << "Enter the file name for game2"<<endl;
    cin >> fileName2;
    
    game1.getInitials(fileName1);
    cout << "Initials"<<endl;
    cout << game1;
    game2=game1++;
    cout << "GAME PLAYED POSTFIX"<<endl;
    cout << game2;
    cout << endl;
    game3.getInitials(fileName1);
    game5=++game3;
    cout << "GAME PLAYED PREFIX"<<endl;
    cout << game5;
    game4.getInitials(fileName1);
    game6.getInitials(fileName2);
    game7=game4+game6;
    cout << "GAME1+GAME2"<<endl;
    cout << game7;
    game8.getInitials(fileName1);
    game9.getInitials(fileName2);
    game10=game8-game9;
    cout << "GAME1-GAME2"<<endl;
    cout << game10;
    cout << endl;
    game11.getInitials(fileName1);
    game12.getInitials(fileName2);
    game11+=game12;
    cout << "GAME1+=GAME2"<<endl; 
    cout << game11;
    game13.getInitials(fileName1);
    game13=game13+c2;
    cout << "GAME1+CELL"<<endl; 
    cout << game13;
    game14.getInitials(fileName1);
    game14=game14-c1;
    cout << "GAME1-CELL"<<endl; 
    cout << game14;
    game15.getInitials(fileName1);
    cout << "INITIALS"<<endl;
    cout << game15<<endl;
    ++game15;
    cout << "GAME PLAYED 1(PREFIX)"<<endl;
    cout << game15<<endl;
    ++game15;
    cout << "GAME PLAYED 2(PREFIX)"<<endl;
    cout << game15<<endl;
    --game15;
    cout << "GAME BACK TO 1"<<endl;
    cout << game15<<endl;
    --game15;
    cout << "GAME BACK TO INITIALS"<<endl;
    cout << game15 <<endl;
    game16.getInitials(fileName1);
    cout << "INITIALS"<<endl;
    cout << game16 <<endl;
    cout << "GAME PLAYED 1(PREFIX)"<<endl;
    ++game16;
    cout << game16;
    game17=game16--;
    cout << "GAME BACK TO(--) POSTFIX"<<endl;
    cout << game17<<endl;
    return 0;
}

