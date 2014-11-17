/* 
 * File:   GameOfLife.cpp
 * Author: caner
 * 
 * Created on November 13, 2014, 2:07 PM
 */
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "GameOfLife.h"

using namespace std;
using Cells::Cell;


namespace GameLife{
    
    void GameOfLife::getInitials(char fileName[]){
        int rowc=0, columnc=0,number,row, column,j=0;
        char line;
		FILE *inp;
        inp = fopen(fileName, "r");

        cellnumber=0;
        count=-1;

        if (inp == NULL){
            cout << "You have wrote the wrong filen name,Program aborted"<<endl;
            exit(1);
        }
        
        fscanf(inp,"%d%d",&row,&column);
        
        for (int i=0;i<row*column;++i){
            fscanf(inp,"%d%c",&number,&line);
            if ( number == 1)
                ++cellnumber;
        }
        fclose(inp);
        
        inp = fopen(fileName, "r");
        
        fscanf(inp,"%d%d",&row,&column);
        
        setCurrentX(column);
        setCurrentY(row);
        setStartRow(0);
        setStartColumn(0);
        
        arr=new Cell[cellnumber];
        
        arr1=new Cell[cellnumber+cellnumber];
        
        arr2=new Cell*[cellnumber];

        for (int i=0;i<cellnumber;++i)
        	arr2[i]=new Cell[cellnumber];

        
        for (int i=0;i<row*column;++i){
            fscanf(inp,"%d%c",&number,&line);
            if ( number == 1){
                arr[j].setCoorX(rowc);
                arr[j].setCoorY(columnc);
                ++j;
            }
            if ( line == '\n'){
                ++columnc;
                rowc=-1;
            }
            ++rowc;
        }
        
        capacity=cellnumber;
	
        fclose(inp);    
    }
    
    //another class member
    
    void GameOfLife::printTabletoFile(char fileName1[]){
        FILE *outp;
        outp = fopen(fileName1, "w");
		for (int i=getStartRow(); i<getCurrentY(); ++i){
	        for (int j=getStartCol(); j<getCurrentX(); ++j){
	            if ( checkLives(i,j) == true )
	                fprintf(outp, "X");
	            else 
	                fprintf(outp, "-");
	        }
	    fprintf(outp, "\n");
	    }
	    fclose(outp);
    }
    //setters
    
    void GameOfLife::setStartRow(int ro){

        StartRow=ro;

    }

    void GameOfLife::setStartColumn(int col){

        StartColumn=col;

    }

    void GameOfLife::setCurrentY(int y){

        currentY=y;

    }

    void GameOfLife::setCurrentX(int x){

        currentX=x;

    }

    void GameOfLife::playGame(){
        int k=0,b=0;
        int rowc=getCurrentY()+1;
        int columnc=getCurrentX()+1;
        
        tempcellnumber=0;

         //count is static member that holds the played game numbers.
        ++count;

        for (int i=0;i<capacity;++i){
        	arr2[count][i].setCoorX(arr[i].getCoorX());
        	arr2[count][i].setCoorY(arr[i].getCoorY());
        }
        
        for (int i = getStartCol()-1; i<rowc; ++i){
            for (int j = getStartRow()-1; j<columnc; ++j){
                if (checkLives(i,j+1) == true )
                    ++k;
                if (checkLives(i,j-1) == true)
                    ++k;
                if (checkLives(i+1,j) == true)
                    ++k;
                if (checkLives(i-1,j) == true)
                    ++k;
                if (checkLives(i+1,j+1) == true)
                    ++k;
                if (checkLives(i-1,j-1) == true)
                    ++k;
                if (checkLives(i+1,j-1) == true )
                    ++k;
                if (checkLives(i-1,j+1) == true)
                    ++k;
                if ( checkLives(i,j) == false ){
                    if( k == 3 ){
                        ++tempcellnumber;
                        arr1[b].setCoorX(j);
                        arr1[b].setCoorY(i);
                        ++b;
                    }
                }
                else if ( checkLives(i,j) == true){
                    if(k == 3 || k == 2){
                        ++tempcellnumber;
                        arr1[b].setCoorX(j);
                        arr1[b].setCoorY(i);
                        ++b;
                    }
                }       		               
            k = 0;
            }
        } 
        
        delete []arr;
        arr=new Cell [tempcellnumber];

        ++count;
        
        for (int i=0;i<capacity;++i){
        	arr2[count][i].setCoorX(arr1[i].getCoorX());
        	arr2[count][i].setCoorY(arr1[i].getCoorY());
        }
        
        // count holds the previous game, prefix count holds the current game, in -- operator this array extract
        // to arr(other dynamic array) array.
        
        for (int i=0;i<tempcellnumber;++i){
            arr[i].setCoorX(arr1[i].getCoorX());
            arr[i].setCoorY(arr1[i].getCoorY());
        }
        cellnumber=tempcellnumber;
        checkColumnsRows();
        
    }
    
    void GameOfLife::checkColumnsRows(){
        int a,b;
        int temp1=-20,temp2=-20,temp3=20,temp4=20;

        for (int i=0; i<2; ++i){
            for (int k=0; k<cellnumber; ++k){
                a=arr[k].getCoorX();
                b=arr[k].getCoorY();
                if(a>temp1)
                    temp1=a;
                else if (a<temp3)
                    temp3=a;
                if (b>temp2)
                    temp2=b;
                else if (b<temp4)
                    temp4=b;
                }
        }
        setCurrentY(temp2+1);
        setCurrentX(temp1+1);
        setStartRow(temp3);
        setStartColumn(temp4);
    }
    
    bool GameOfLife::checkLives(int coory,int coorx){
        
        for (int i=0;i<cellnumber;++i){
            if ( arr[i].getCoorX() == coorx && arr[i].getCoorY() == coory )
                return true;
        }
        return false;
    }
    
    GameOfLife::~GameOfLife(){
    	delete []arr;
    	delete []arr1;
    	//for (int i=0;i<cellnumber;++i)
    		//delete [] arr2[i];
    	//delete []arr2;
    	
    }
    
    GameOfLife::GameOfLife(const GameOfLife& gameoflife){
        
        if ( this != &gameoflife){
            cellnumber=gameoflife.cellnumber;
            arr=new Cell[cellnumber];
            arr1=new Cell[cellnumber];

	        setCurrentX(gameoflife.getCurrentX());
	        setCurrentY(gameoflife.getCurrentY());
	        setStartColumn(gameoflife.getStartCol());
	        setStartRow(gameoflife.getStartRow());	
            
            for (int i=0;i<cellnumber;++i){
                arr[i].setCoorX(gameoflife.arr[i].getCoorX());
                arr[i].setCoorY(gameoflife.arr[i].getCoorY());
            }
		}	

    }
    
    GameOfLife::GameOfLife()
    {
    	arr=NULL;
    	arr1=NULL;
    	arr2=NULL;               
    }
    
    const GameOfLife& GameOfLife::operator =(const GameOfLife& rightside){
        delete []arr;
        arr=new Cell[rightside.cellnumber];
        
        setCurrentX(rightside.getCurrentX());
        setCurrentY(rightside.getCurrentY());
        setStartColumn(rightside.getStartCol());
        setStartRow(rightside.getStartRow());
        
        cellnumber=rightside.cellnumber;

        for (int i=0;i<cellnumber;++i){
           arr[i].setCoorX(rightside.arr[i].getCoorX());
           arr[i].setCoorY(rightside.arr[i].getCoorY());
        }
        
        return *this; 
    }
    
    void GameOfLife::settings(const GameOfLife& game1, const GameOfLife& game2){
    
        if ( game2.getCurrentX() > game1.getCurrentX())
            setCurrentX(game2.getCurrentX());
        else
            setCurrentX(game1.getCurrentX());

        if ( game2.getCurrentY() > game1.getCurrentY())
            setCurrentY(game2.getCurrentY());
        else
            setCurrentY(game1.getCurrentY());

        if ( game2.getStartCol() < game1.getStartCol())
            setStartColumn(game2.getStartCol());
        else
            setStartColumn(game1.getStartCol());

        if ( game2.getStartRow() < game1.getStartRow())
            setStartRow(game2.getStartRow());
        else
            setStartRow(game1.getStartRow());
    }

    ostream& operator << (ostream& outputStream,GameOfLife &game1){
    
        for (int i=game1.getStartCol(); i<game1.getCurrentY(); ++i){
            for (int j=game1.getStartRow(); j<game1.getCurrentX(); ++j){
                if ( game1.checkLives(i,j) == true )
                    outputStream << "X";
                else 
                    outputStream << "-";
            }
            outputStream << "\n";
        }
        return outputStream;
    }

    GameOfLife& GameOfLife::operator ++(){
    
        playGame();
        return *this;
    }
    GameOfLife GameOfLife::operator ++(int){
    
        GameOfLife temp1=*this;
        ++*this;
        return temp1;
    }

    const GameOfLife operator +(const GameOfLife &game1,const GameOfLife &game2){
        int b=0;
        GameOfLife game3;

        game3.settings(game1,game2);

        game3.arr=new Cell[game1.capacity+game2.capacity];        

        game3.cellnumber=game1.capacity+game2.capacity;

        for (int a=0;a<game2.capacity; ++a){
            game3.arr[a].setCoorX(game2.arr[a].getCoorX());
            game3.arr[a].setCoorY(game2.arr[a].getCoorY());
            ++b;
        }
        for (int a=0;a<game1.capacity; ++a){
        	
            game3.arr[b].setCoorX(game1.arr[a].getCoorX());
            game3.arr[b].setCoorY(game1.arr[a].getCoorY());
            ++b;
        }
        return game3;
    
    }
    const GameOfLife operator -(const GameOfLife &game1,const GameOfLife &game2){
    
	    GameOfLife game3;
	    int b=0,c=0;
	    
	    game3.settings(game1,game2);
	    
	    game3.arr=new Cell[game1.capacity];      

	    for(int i=0; i<game2.capacity;++i){
	        for (int j=0; j<game1.capacity;++j){
	            if ( ( game1.arr[j].getCoorX() != game2.arr[i].getCoorX() ) || ( game1.arr[j].getCoorY() != game2.arr[i].getCoorY() ) ){ 
	                game3.arr[b].setCoorX(game1.arr[j].getCoorX());
	                game3.arr[b].setCoorY(game1.arr[j].getCoorY());
	            	++b;
	            }	
	        }
	    	for (int a=0;a<b;++a){
	    		game1.arr[a].setCoorX(game3.arr[a].getCoorX());
	            game1.arr[a].setCoorY(game3.arr[a].getCoorY());
	    	}
	    	if ( game2.capacity != i+1)
	    		b=0;
	    }
	    if (b == game1.capacity)
	    	game3.cellnumber=game1.capacity;
	    else
	    	game3.cellnumber=game1.capacity-game2.capacity;

	    return game3;
	
	}

	const GameOfLife GameOfLife::operator +=(GameOfLife& game1){
    
	    int b=capacity;
	    
	    delete []arr1;
	    arr1=new Cell[game1.capacity+b];
	    
	    cellnumber=game1.capacity+b;

	    for (int a=0;a<capacity; ++a){
	    	arr1[a].setCoorX(arr[a].getCoorX());
	        arr1[a].setCoorY(arr[a].getCoorY());
	    }
	    for (int a=0;a<game1.capacity; ++a){
	        arr1[b].setCoorX(game1.arr[a].getCoorX());
	        arr1[b].setCoorY(game1.arr[a].getCoorY());
	        ++b;
	    }
	    
	    delete []arr;
	    arr=new Cell[b];
	    
	    for (int a=0;a<b; ++a){
	        arr[a].setCoorX(arr1[a].getCoorX());
	        arr[a].setCoorY(arr1[a].getCoorY());
	    }
	    
	    return *this;
	}
	const GameOfLife operator +(GameOfLife &game1,const Cell &c1){
        
	    int a=game1.capacity;
	    
	    delete []game1.arr1;
	    game1.arr1=new Cell[a+1];

	    for (int i=0;i<game1.capacity;++i){
	    	game1.arr1[i].setCoorX(game1.arr[i].getCoorX());
	        game1.arr1[i].setCoorY(game1.arr[i].getCoorY());
	    }
	    
	    delete []game1.arr;
	    game1.arr=new Cell[a+1];
	    
	    game1.arr1[a].setCoorX(c1.getCoorX());
	    game1.arr1[a].setCoorY(c1.getCoorY());
	    
	    for (int i=0;i<a+1;++i){
	    	game1.arr[i].setCoorX(game1.arr1[i].getCoorX());
	        game1.arr[i].setCoorY(game1.arr1[i].getCoorY());
	    }

	    game1.cellnumber=a+1;

	    return game1;
	}
	const GameOfLife operator -(GameOfLife &game1,const Cell &c1){
    	
    	int a=game1.capacity;
	    
	    delete []game1.arr1;
	    game1.arr1=new Cell[a];

	    int b=0;

	    for (int i=0;i<game1.capacity;++i){
	    	game1.arr1[i].setCoorX(game1.arr[i].getCoorX());
	        game1.arr1[i].setCoorY(game1.arr[i].getCoorY());
	    }

	    delete []game1.arr;
	    game1.arr=new Cell[a];
	    
	    for(int i=0; i<a;++i){
	       if ( (game1.arr1[i].getCoorX() != c1.getCoorX()) || (game1.arr1[i].getCoorY() != c1.getCoorY()) ){
	           	game1.arr[b].setCoorX(game1.arr1[i].getCoorX());
	       		game1.arr[b].setCoorY(game1.arr1[i].getCoorY());
	    		++b;
	    	}
	    }
	    if ( b == game1.capacity-1)
	   		game1.cellnumber =a-1;
	   	else 
	   		game1.cellnumber=a;
	   
	   return game1; 
	}

	GameOfLife GameOfLife::operator --(){
        //count is static member that holds the played game numbers
        for (int i=0;i<capacity;++i){
			arr[i].setCoorX(arr2[count-1][i].getCoorX());
        	arr[i].setCoorY(arr2[count-1][i].getCoorY());
        }
            cellnumber=capacity;
            --count;
            --count;
            checkColumnsRows();
            return *this;
    }
    GameOfLife GameOfLife::operator--(int){

    	GameOfLife game1=*this;

    	for (int i=0;i<capacity;++i){
			arr[i].setCoorX(arr2[count-1][i].getCoorX());
        	arr[i].setCoorY(arr2[count-1][i].getCoorY());
        }

            cellnumber=capacity;
            --count;
            --count;
            checkColumnsRows();

    	return game1;
    }

}