//
//  arrayfunctions.h
//  DGAttempt5
//
//  Created by Harvard Virgil Humphrey on 2019/3/25.
//  Copyright © 2019 Harvard Virgil Humphrey. All rights reserved.
//

#ifndef arrayfunctions_h
#define arrayfunctions_h

bool isequal(double*& array1,double*& array2,int length);
void sortascend(int*& array,int length);
void arrayassign(int*& target,int*& origin,int length);
void insertzerosdouble(double*& target,int length);
void zerosarraydouble(double*& target,int length);
void arrayassigndouble(double*& target,double*& origin,int length);
void circshift(int*& array,int length,int cycles);
void circshiftdouble(double*& array,int length,int cycles);
void printintarray(int*& array,int length);
void printdoublearray(double*& array,int length);
void printboolarray(bool*& array,int length);
int dotproductint(int*& array1,int*& array2,int length);
double dotproductdouble(double*& array1,double*& array2,int length);
int sumintvector(int*& array,int length);
double sumdoublevector(double*& array,int length);
int maxintvector(int*& array,int length);
double maxdoublevector(double*& array,int length);

#endif /* arrayfunctions_h */
