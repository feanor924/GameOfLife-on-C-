/* 
 * File:   Cell.cpp
 * Author: caner
 * 
 * Created on November 13, 2014, 2:09 PM
 */

#include "Cell.h"

namespace Cells{
    
    void Cell::setCoorX(int x){               
        coorX=x;
    }

    void Cell::setCoorY(int y){               
        coorY=y;
    }
    
    Cell::Cell()
    {           }
    
    Cell::Cell(int coorx,int coory) : coorX(coorx), coorY(coory)
    {           }
    
    bool Cell::operator <(const Cell &c1){
    
        if ( coorY < c1.coorY )
            return true;
        else if ( coorY > c1.coorY)
            return false;
        else{
            if ( coorX < c1.coorX)
                return true;
        }
            return false;
    }
    bool Cell::operator >(const Cell &c1){

        if ( coorY > c1.coorY )
            return true;
        else if ( coorY < c1.coorY)
            return false;
        else{
            if ( coorX > c1.coorX)
                return true;
        }
        return false;
    }
    bool Cell::operator >=(const Cell &c1){

        if ( coorY >= c1.coorY )
            return true;

        return false;
    }

    bool Cell::operator <=(const Cell &c1){

       if ( coorY <= c1.coorY )
            return true;

       return false;
    }
    bool Cell::operator ==(const Cell &c1){

        if ( coorY == c1.coorY && coorX == c1.coorX )
            return true;

        return false;
    }

    bool Cell::operator !=(const Cell &c1){

        if ( coorY != c1.coorY || coorX != c1.coorX)
            return true;

        return false;

    }
    ostream& operator <<(ostream& outputStream,const Cell& c1){

        outputStream <<"coorx:" << c1.getCoorX()<<endl;
        outputStream <<"coory:"<< c1.getCoorY()<<endl;

        return outputStream;
    }

    istream& operator >>(istream& inputStream,Cell& c1){

        inputStream >> c1.coorX;
        inputStream >> c1.coorY;

        return inputStream;

    }

    Cell Cell::operator --(){

        coorX--;
        coorY--;

        return Cell(coorX,coorY);

    }

    Cell Cell::operator ++(){

        coorX++;
        coorY++;
        return Cell(coorX,coorY);

    }
    Cell Cell::operator ++(int){
        int temp1,temp2;
        temp1=coorX;
        temp2=coorY;
        coorX++;
        coorY++;
        return Cell(temp1,temp2);    
    }
    Cell Cell::operator --(int){
        int temp1,temp2;
        temp1=coorX;
        temp2=coorY;
        coorX--;
        coorY--;
        return Cell(temp1,temp2); 

    }

}


