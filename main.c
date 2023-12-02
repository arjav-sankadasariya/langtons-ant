#include <stdio.h>
#include <stdlib.h>
#include "newSleep.h"
#include "random.h"
#include "conio.h"
#include "color.h"

int m,n;
int a1i,a1j,a2i,a2j;
char position1,position2; 
int c;//temp

void display(char *arr){
    system("CLS"); // clearing screen 
    printf("\n\n\t+");//outer box
    for(int i=0;i<=n;i++) printf("-");
    printf("+");
    printf("\n");
    
    for(int i=0;i<m;i++){
        printf("\t| ");
        for(int j=0;j<n;j++){
            char color_code = *(arr + i * n + j); // get the color status of cell 
            switch (color_code){ //set that color for background [ next character ]
                    case '0': 
                        setBackground("black");
                        break;
                    case '1':
                        setBackground("green");
                        break;
                    case '2':
                        setBackground("red");
                        break;
                    case '3':
                        setBackground("blue");
                        break;
                    default:
                        break;
                }
            if(a1i == i && a1j == j) printf("%c",position1); // if ant present at cell print ant position
            else if(a2i == i && a2j == j) printf("%c",position2);
            else printf(" "); // else print special character " "
        }
        setBackground("black");
        printf("|\n");
    }

    printf("\t+");//outer box
    for(int i=0;i<=n;i++) printf("-");
    printf("+\n\n");
}

// moveAntOne function updates the positions and direction of ant 1
void moveAntOne(char *arr){


    if(*(arr + a1i * n + a1j) =='0'){ //anti-clockwise

        // updating color of cell in map where ant is present
        *(arr + a1i * n + a1j)='2';

        // updating the position and location variables of ant 
        if(position1=='^' && a1j!=0 && (a1i!=a2i || a2j!=(a1j-1))){
            position1='<';
            a1j--;
        }else if (position1=='v' && a1j!=n-1 && (a1i!=a2i || a2j!=(a1j+1))){
            position1='>';
            a1j++;
        }else if(position1=='>' && a1i!=0 && (a1i!=a2i || a2j!=(a1j-1))){
            position1='^';
            a1i--;
        }else if (position1=='<' && a1i!=m-1 && (a1i!=a2i || a2j!=(a1j+1))){
            position1='v';
            a1i++;
        }
    }else {// clockwise

        // updating color of cell in map where ant is present
        *(arr + a1i * n + a1j)='0';

        // updating the position and location variables of ant 
        if(position1=='v' && a1j!=0 && (a1i!=a2i || a2j!=(a1j-1))){
            position1='<';
            a1j--;
        }else if (position1=='^' && a1j!=n-1 && (a1i!=a2i || a2j!=(a1j+1))){
            position1='>';
            a1j++;
        }else if(position1=='<' && a1i!=0 && (a1i!=a2i || a2j!=(a1j-1))){
            position1='^';
            a1i--;
        }else if (position1=='>' && a1i!=m-1 && (a1i!=a2i || a2j!=(a1j+1))){
            position1='v';
            a1i++;
        }
    }
}

// moveAntTwo function updates the positions and direction of ant 2
void moveAntTwo(char *arr){

    initRandom();
    int r = random(1,4);

    // updating color of cell in map where ant is present
    if(*(arr + a2i * n + a2j)=='0') *(arr + a2i * n + a2j)='3';
    else *(arr + a2i * n + a2j)='0';

    // updating the position and location variables of ant 
    switch (r){
        case 1://right
            if(a2j!=n-1 && (a1i!=a2i || a1j!=(a2j+1))){
                position2='>';
                a2j++;
            } 
            break;
        case 2://left
            if(a2j!=0 && (a1i!=a2i || a1j!=(a2j-1))){
                position2='<';
                a2j--;
            } 
            break;
        case 3://top
            if(a2i!=0 && (a1j!=a2j || a1i!=(a2i+1))){
                position2='^';
                a2i--;
            } 
            break;
        case 4://bottom   
            if(a2i!=m-1 && (a1j!=a2j || a1i!=(a2i-1))){
                position2='v';
                a2i++;
            } 
            break;
        default:
            break;
    }
}

int main(int argc,char *argv[]){
    //-------------------------------------------------+ ERROR CHECKS 
    if(argc != 4){
        printf("\n\t+-------------------------------------------+\n");
        printf("\t+      ERROR IN COMMAND LINE ARGUMENTS      +\n");
        printf("\t+-------------------------------------------+\n\n");
        return 0;
    }

    int niterations = atoi(argv[2]);
    if(niterations <0) return 0;
    float tsleep = atof(argv[3]);
    if(tsleep <0) return 0;

    //-------------------------------------------------+ READING FILE
    FILE *fp;
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("\n\t+-------------------------------------------+");
        printf("\n\t+        ERROR IN OPEANING %s FILE          +",argv[1]);
        printf("\n\t+-------------------------------------------+\n\n");
        return 0;
    }
                            // FIRST LINE OF FILE M=Rows N=column
    fscanf(fp,"%d ",&m);
    fscanf(fp,"%d\n",&n);

                            // SECOND LINE OR FILE ant one positions
    fscanf(fp,"%d ",&a1i);
    fscanf(fp,"%d ",&a1j);
    fscanf(fp, "%c\n", &position1);

                            // THIRD LINE OR FILE ant two positons 
    fscanf(fp,"%d ",&a2i);
    fscanf(fp,"%d ",&a2j);
    fscanf(fp, "%c\n", &position2);

                            // GRID SCANNING
    char *arr = (char *)malloc(m * n * sizeof(char));
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            fscanf(fp, "%c ", (arr + i * n + j));
        }
        fscanf(fp, "%c\n", (arr + i * n + n-1)); 
    }

    // making positon vectors  index competable
    a1j--;
    a1i--;
    a2i--;
    a2j--;

    //--------------------------------------------------------+ CYCLE
    // this displays the map 2 times in 1 cycle 
    // because 2 ant updates are there which are not simultaneous 
    for(int i=0; i<niterations; i++){

        display(arr);
        newSleep(tsleep);
        moveAntOne(arr);
        display(arr);
        newSleep(tsleep);
        moveAntTwo(arr);
    } // display -> sleep -> update ant1 -> display ->sleep ->update ant2
    display(arr);
}