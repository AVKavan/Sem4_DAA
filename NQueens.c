
#include<stdio.h> 
int count = 0;
int noAttack(char board[100][100],int row,int col,int n){
    
    for(int Y =0;Y<n;Y++){
        if(board[row][Y] == 'Q'){
            return 0; 
        }
    }
    
    for(int X=0;X<n;X++){
        if(board[X][col] == 'Q'){
            return 0;
        }
    }
    
    int x = row;
    int y = col;
    
    while(x>=0 && y>=0){
        if(board[x][y] == 'Q'){
            return 0; 
        }
     
        x--;
        y--;
    }

    
    int x1 = row;
    int y1 = col;
    while(x1>=0 && y1<n){
        if(board[x1][y1] == 'Q'){
            return 0; 
        }
        x1--; 
        y1++; 
    }

    
    return 1;
}

int solveNQueenProblem(char board[100][100],int n,int row){
    
    if(row == n){
        printf("\n*********************Solution %d**************\n",++count);
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                printf("%c ",board[x][y]);
            }
            printf("\n");
        }
        
       
        return 0; 
    }
    
    for(int col=0;col<n;col++){
        if(noAttack(board,row,col,n)){
                board[row][col] = 'Q';

                int agliQueenRakhSakteHai = solveNQueenProblem(board,n,row+1); 
                if(agliQueenRakhSakteHai == 1){
                    return 1;
                }
                
                board[row][col] = '-';
        }       
    }
    return 0; 
    
}

void main(){

    char board[100][100]; 
    int n;
    printf("\nEnter the number of Queens:\t");
    scanf("%d",&n);


    
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            board[x][y] = '-'; 
        }
    }
    
    solveNQueenProblem(board,n,0);

}