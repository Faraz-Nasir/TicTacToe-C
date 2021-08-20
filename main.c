#include<stdlib.h>
#include<stdio.h>

char matrix[3][3];
char check(void);
void init_matrix(void);
void getPlayerMove(void);
void getComputerMove(void);
void dispMatrix(void);

int main(void){
    char done;
    printf("TIC TAC TOE\n");
    printf("HUMAN V/S COMPUTER\n");
    done=' ';
    initMatrix();
    do{
        dispMatrix();
        getPlayerMove();
        done=check();
        if(done!=' ') break;
        getComputerMove();
        done=check();
    }while(done==' ');
    if(done=='X') printf("You Won\n");
    else printf("I won!!!\n");
    dispMatrix();
    return 0;
}

void initMatrix(void){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matrix[i][j]=' ';
        }
    }
}
void getPlayerMove(void)
{
        int x,y;
        printf("Enter coordinates for your move: ");
        scanf("%d%*c%d",&x,&y);
        x--;y--;
        if(matrix[x][y]!=' '){
            printf("Invalid Move,Try Again.\n");
            getPlayerMove();
        }
        else matrix[x][y]='X';
}
void getComputerMove(void){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matrix[i][j]==' ')break;
        if(matrix[i][j]==' ')break;
        }
    }
    if(i*j==9){
        printf("draw\n");
        exit(0);
    }else matrix[i][j]='O';
}
void dispMatrix(void){
    int t;
    for(t=0;t<3;t++){
        printf("   %c |  %c  |  %c  |",matrix[t][0],matrix[t][1],matrix[t][2]);
        if(t!=2) printf("\n----|---|---\n");
    }
    printf("\n");
}
char check(void){
    int i;
    for(i=0;i<3;i++){
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2]) return matrix[i][0];
    }
    for(i=0;i<3;i++){
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i]) return matrix[0][i];
    }
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) return matrix[0][0];
    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0]) return matrix[0][2];

    return ' ';

}


