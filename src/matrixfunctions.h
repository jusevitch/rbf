//
//  matrixfunctions.h
//  DGAttempt5
//
//  Created by Harvard Virgil Humphrey on 2019/3/25.
//  Copyright © 2019 Harvard Virgil Humphrey. All rights reserved.
//

#ifndef matrixfunctions_h
#define matrixfunctions_h

void insertzeros(int**& matrixA,int length,int width);
void insertzerosdouble(double**& matrix,int length,int width);
void insertones(int**& matrixA,int length,int width);
void insertonesdouble(double**& matrix,int length,int width);
void deletematrixint(int**& matrixA,int length,int width);
void deletematrixdouble(double**& matrixA,int length,int width);
void buildint(int**& matrixA,int length,int width);
void builddouble(double**& matrixA,int length,int width);
void zerosint(int**& matrixA,int length,int width);
void zerosdouble(double**& matrixA,int length,int width);
void matrixmulti(double**& product,double**& matrixA,int lengthA,int widthA,double**& matrixB,int lengthB,int widthB);
void printdoublemat(double**& matrixA,int length,int width);
void printintmat(int**& matrixA,int length,int width);
void matrixscalar(double**& product,double**& matrixA,int length,int width,double scalar);
void transposedouble(double**& flipped,double**& matrixA,int length,int width);
int summatrixint(int**& matrix,int length,int width);
double summatrixdouble(double**& matrix,int length,int width);
double absmaxmatrix(double**& matrix,int length,int width);
void doubleidentity(double**& identity,int length);
void equatematrix(double**& target,double**& origin,int length,int width);
void inversematrix(double**& inverse,double**& origin,int length);
void chunk(double**& piece,double**& origin,int startrow,int desiredlength,int width);
void assignpartial(double**& target,double**& small,int startrow,int desiredlength,int width);
void matrixsubtraction(double**& target,double**& matrixA,double**& matrixB,int length,int width);
void matrixaddition(double**& target,double**& matrixA,double**& matrixB,int length,int width);
void delete3Ddouble(double***& target,int length,int width,int depth);
#endif /* matrixfunctions_h */
