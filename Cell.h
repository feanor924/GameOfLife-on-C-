/* 
 * File:   Cell.h
 * Author: caner
 *
 * Created on November 13, 2014, 2:09 PM
 */

#include <vector>
#include <iostream>
#ifndef CELL_H
#define	CELL_H

#define MAX 20

using namespace std;

namespace Cells
{
    class Cell 
    {
        public:
            
            Cell ();
            Cell (int coorx,int coory);
            Cell operator++();
            Cell operator++(int);
            Cell operator--(int);
            Cell operator--();
            void setCoorX(int x);
            void setCoorY(int y);
            bool operator <(const Cell &c1);
            bool operator >(const Cell &c1);
            bool operator >=(const Cell &c1);
            bool operator <=(const Cell &c1);
            bool operator ==(const Cell &c1);
            bool operator !=(const Cell &c1);
            int getCoorX() const { return coorX; }
            int getCoorY() const { return coorY; }
            friend ostream& operator << (ostream& outputStream,const Cell &c1 );
            friend istream& operator >> (istream& inputStream ,Cell& c1);   
    
        private:
        
        int coorX;
        int coorY;
    
        
    };
}
#endif	/* CELL_H */

