/* 
 * File:   GameOfLife.h
 * Author: caner
 *
 * Created on November 13, 2014, 2:07 PM
 */
#include <vector>
#include <iostream>
#include "Cell.h"
#ifndef GAMEOFLIFE_H
#define	GAMEOFLIFE_H

#define MAX 20

using namespace std;

namespace GameLife
{
    class GameOfLife {
    public:
        GameOfLife();
        const GameOfLife& operator=(const GameOfLife &rightside);
        GameOfLife(const GameOfLife &gameoflife);
        void getInitials(char fileName[MAX]);
        void printTabletoFile(char fileName1[MAX]);
        void playGame();
        void setStartRow(int ro);
        void setStartColumn(int col);
        void setCurrentX(int x);
        void setCurrentY(int y);
        int getStartCol() const { return StartColumn; }
        int getStartRow() const { return StartRow; }
        int getCurrentX() const { return currentX; }
        int getCurrentY() const { return currentY; }
        GameOfLife operator ++(int);
        GameOfLife & operator ++();
        GameOfLife operator --();
        GameOfLife operator --(int);
        void settings(const GameOfLife &game1,const GameOfLife &game2);
        friend const GameOfLife operator +(const GameOfLife &game1,const GameOfLife &game2);
        friend const GameOfLife operator -(const GameOfLife &game1,const GameOfLife &game2);
        friend const GameOfLife operator +(GameOfLife &game1,const Cells::Cell &c1);
        friend const GameOfLife operator -(GameOfLife &game1,const Cells::Cell &c1);
        const GameOfLife operator +=(GameOfLife &game1);
        friend ostream& operator <<(ostream &outputStream,GameOfLife &game1);
        bool checkLives(int coory,int coorx);
        ~GameOfLife();
    private:
        void checkColumnsRows();
        static int cellnumber;
        static int tempcellnumber;
        Cells::Cell *arr1;
        Cells::Cell *arr;
        Cells::Cell **arr2;
        static int count;
        int capacity;
        int currentX;
        int currentY;
        int StartRow;
        int StartColumn;
    };

}
#endif	/* GAMEOFLIFE_H */

