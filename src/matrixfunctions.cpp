//
//  matrixfunctions.cpp
//  DGAttempt5
//
//  Created by Harvard Virgil Humphrey on 2019/3/25.
//  Copyright © 2019 Harvard Virgil Humphrey. All rights reserved.
//

#include<iostream>
#include<cmath>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "matrixfunctions.h"
#include "mathfunctions.h"
#include "arrayfunctions.h"
using namespace std;

void insertzeros(int**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            matrixA[i][j] = 0;
        }
    }
}

void insertzerosdouble(double**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            matrixA[i][j] = 0;
        }
    }
}

void insertones(int**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            matrixA[i][j] = 1;
        }
    }
}

void insertonesdouble(double**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            matrixA[i][j] = 1;
        }
    }
}

void deletematrixint(int**& matrixA,int length,int width)  {
    for(int i=0;i<length;i++)   {
        delete[] matrixA[i];
    }
    delete[] matrixA;
}

void deletematrixdouble(double**& matrixA,int length,int width)  {
    for(int i=0;i<length;i++)   {
        delete[] matrixA[i];
    }
    delete[] matrixA;
}

void buildint(int**& matrixA,int length,int width)   {
    matrixA = new int*[length];
    for(int i=0;i<length;i++)   {
        matrixA[i] = new int[width];
    }
}

void builddouble(double**& matrixA,int length,int width)   {
    matrixA = new double*[length];
    for(int i=0;i<length;i++)   {
        matrixA[i] = new double[width];
    }
}

void zerosint(int**& matrixA,int length,int width)   {
    buildint(matrixA,length,width);
    insertzeros(matrixA,length,width);
}

void zerosdouble(double**& matrixA,int length,int width)   {
    builddouble(matrixA,length,width);
    insertzerosdouble(matrixA,length,width);
}

void matrixmulti(double**& product,double**& matrixA,int lengthA,int widthA,double**& matrixB,int lengthB,int widthB)   {
    if(widthA!=lengthB) {
        cout<<"Matrix dimensions do not match!"<<endl;
    }
    for(int i=0;i<lengthA;i++)  {
        for(int j=0;j<widthB;j++)   {
            for(int x=0;x<widthA;x++)   {
                product[i][j]+= matrixA[i][x]*matrixB[x][j];
            }
        }
    }
}

void printdoublemat(double**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            cout<<matrixA[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printintmat(int**& matrixA,int length,int width)   {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            cout<<matrixA[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrixscalar(double**& product,double**& matrixA,int length,int width,double scalar) {
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            product[i][j] = scalar*matrixA[i][j];
        }
    }
}

void transposedouble(double**& flipped,double**& matrixA,int length,int width)    {
    builddouble(flipped,width,length);
    for(int j=0;j<width;j++)    {
        for(int i=0;i<length;i++)   {
            flipped[j][i] = matrixA[i][j];
        }
    }
}

int summatrixint(int**& matrixA,int length,int width)    {
    double number=0;
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            number+= matrixA[i][j];
        }
    }
    return number;
}

double summatrixdouble(double**& matrixA,int length,int width)    {
    double number=0;
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            number+= matrixA[i][j];
        }
    }
    return number;
}

double absmaxmatrix(double**& matrixA,int length,int width) {
    double number=0;
    double temp;
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++)    {
            temp = matrixA[i][j];
            if(absdouble(temp)>number)  {
                number = absdouble(temp);
            }
        }
    }
    return number;
}

void doubleidentity(double**& identity,int length) {
    //zerosdouble(identity,length,length);
    for(int i=0;i<length;i++)   {
        identity[i][i] = 1;
    }
}

void equatematrix(double**& target,double**& origin,int length,int width)   {
    for(int i=0;i<length;i++)  {
        for(int j=0;j<width;j++)    {
            target[i][j] = origin[i][j];
        }
    }
}

void inversematrix(double**& inverse,double**& origin,int length)    {
    doubleidentity(inverse,length);
    double** test;
    zerosdouble(test,length,length);
    equatematrix(test,origin,length,length);
    //printdoublemat(test,length,length);
    double rownumber;
    double factor;
    
    //Begin with the downward motion to turn the diagonals into 1s
    for(int i=0;i<length;i++)   {
        rownumber = test[i][i];
        // Change current row
        for(int j=0;j<length;j++)   {
            test[i][j] = test[i][j]/rownumber;
            inverse[i][j] = inverse[i][j]/rownumber;
        }
        for(int k=i+1;k<length;k++)   {
            factor = test[k][i];
            for(int j=0;j<length;j++)   {
                test[k][j] -= test[i][j]*factor;
                inverse[k][j] -= inverse[i][j]*factor;
            }
        }
    }
    for(int i=length-1;i>0;i--) {
        rownumber = test[i][i];
        //Subsequent rows above the current ith row
        for(int j=i-1;j>-1;j--)  { //row numbers
            factor = test[j][i];
            for(int k=0;k<length;k++)   { //column number
                //test[j][k] = test[j][k]-test[i][k]*factor;
                test[j][k] -= test[i][k]*factor;
                //inverse[j][k] = inverse[j][k]-inverse[i][k]*factor;
                inverse[j][k] -=inverse[i][k]*factor;
            }
        }
    }
    //printdoublemat(test,length,length);
    //    printdoublemat(inverse,length,length);
    deletematrixdouble(test,length,length);
}

void chunk(double**& piece,double**& origin,int startrow,int desiredlength,int width) {
    
    for(int i=0;i<desiredlength;i++)    {
        for(int j=0;j<width;j++)    {
            piece[i][j] = origin[startrow+i][j];
        }
    }
}

void assignpartial(double**& target,double**& small,int startrow,int desiredlength,int width)   {
    for(int i=0;i<desiredlength;i++)    {
        for(int j=0;j<width;j++)    {
            target[startrow+i][j] = small[i][j];
        }
    }
}

void matrixsubtraction(double**& target,double**& matrixA,double**& matrixB,int length,int width)   {
    //We do not build a new matrix
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++) {
            target[i][j] = matrixA[i][j]-matrixB[i][j];
        }
    }
}

void matrixaddition(double**& target,double**& matrixA,double**& matrixB,int length,int width)   {
    //We do not build a new matrix
    for(int i=0;i<length;i++)   {
        for(int j=0;j<width;j++) {
            target[i][j] = matrixA[i][j]+matrixB[i][j];
        }
    }
}

void delete3Ddouble(double***& target,int length,int width,int depth)    {
    for(int i=0;i<length;i++)   {
        deletematrixdouble(target[i],width,depth);
    }
    delete[] target;
}

void sortrowsdescend(double**& target,int colindex,int length,int width)    {
    double* array = new double[width];
    for(int i=0;i<length;i++)   {
        arrayassigndouble(array,target[i],width);
        for(int j=i;j<length;j++)   {
            if(array[colindex]<target[i][colindex]) {
                for(int k=0;k<width;k++)    {
                    target[i][k] = target[j][k];
                    target[j][k] = array[k];
                }
            }
        }
    }
}
