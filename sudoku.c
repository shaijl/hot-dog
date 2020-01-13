
// sudoku 
//algorithm - backtracking

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// checking the same number exist in the column
bool iscolumnsafe( int sudoku[9][9] , int x , int y , int num){
    
    int i ;
    for( i = 0 ; i < 9 ; i ++)
         if( sudoku[x][i] == num) return false ; // not safe

    return true ; // safe 
}

// checking the same number exist in the row
bool isrowsafe( int sudoku[9][9] , int x , int y , int num){

    for(int i = 0 ; i < 9 ; i ++)
         if( sudoku[i][y] == num) return false ; // not safe

    return true ; // safe 
}

// checking smaller squares are safe

bool isgridsafe(int sudoku[9][9] , int x , int y , int num){

    // set the starting X,Y co-ordinate
    if( x < 3)  x = 0; 
    else if ( x < 6) x = 3 ;
    else x = 6 ;
   
    if( y < 3)  y = 0; 
    else if ( y < 6) y = 3 ;
    else y = 6 ;

    int i , j ;
    for( i =  x ; i < x + 3 ; i++)
       for( j = y ; j < y + 3 ; j++)
          if( sudoku[i][j] == num) return false ;
    return true ;      
 }

////solver

bool sudokusolver(int sudoku[9][9] , int x , int y){
    int num = 1 ;
if(x < 9 && y < 9){
    if( sudoku[x][y] != 0){
        if( x < 8) return sudokusolver(sudoku , x + 1 , y);
        else if( y < 8) return sudokusolver(sudoku , 0 , y + 1);
        else return true ; // else condition is x = 8 and y = 8 ,completed sudoku
    }
    else {           // sudoku[x][y] == 0
        for( num = 1 ; num < 10 ; num++ ){
            if(iscolumnsafe(sudoku , x , y , num) == true && isgridsafe(sudoku , x ,y , num) == true  && isrowsafe(sudoku, x , y , num) == true){
                sudoku[x][y] = num ;
                if( x < 8){
                    if(sudokusolver(sudoku , x + 1 , y)) return true;
                    else sudoku[x][y] = 0 ; // backtracking
                }
                else if( y < 8){
                    if(sudokusolver(sudoku , 0 , y + 1)) return true;
                    else sudoku[x][y] = 0 ; // back track
                }
                else return true ; // x == 8 and  y == 8
               } 
            } return false;
        }
 
} return true ;
}

// printing sudoku
void print(int sudoku[9][9]){
    int i , j ;
      
    for( i = 0 ; i < 9 ; i++){
         if( i % 3 == 0  && i != 0) printf(" -----------------------\n");
       for (j = 0 ; j < 9 ; j++){
           
           if( j % 3 == 0 && j != 0) printf("  |") ;
           printf(" %d" , sudoku[i][j]);
       }
       printf("\n");
}
}

//driver program
int main(){

    // sudoku
    int sudoku[9][9] = { 5 , 3 , 0 , 0 , 7 , 0 , 0 , 0 , 0,
                           6 , 0 , 0 , 1 , 9 , 5 , 0 , 0 , 0,
                           0 , 9 , 8 , 0 , 0 , 0 , 0 , 6 , 0,
                           8 , 0 , 0 , 0 , 6 , 0 , 0 , 0 , 3,
                           4 , 0 , 0 , 8 , 0 , 3 , 0 , 0 , 1,
                           7 , 0 , 0 , 0 , 2 , 0 , 0 , 0 , 6,
                           0 , 6 , 0 , 0 , 0 , 0 , 2 , 8 , 0,
                           0 , 0 , 0 , 4 , 1 , 9 , 0 , 0 , 5,
                           0 , 0 , 0 , 0 , 8 , 0 , 0 , 7 , 9 }; 
     // printing unsolved sudokku
    print(sudoku);
    sudokusolver(sudoku , 0 , 0);
    printf("\n\n");
    //solved sudoku
    print(sudoku) ;

    return 0 ;                      

}
