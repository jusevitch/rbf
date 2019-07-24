//
//  arrayfunctions.cpp
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

bool isequal(double*& array1,double*& array2,int length)    {
    bool check = true;
    for(int i=0;i<length;i++)   {
        if(array1[i]!=array2[i])    {
            check = false;
            return check;
        }
    }
    return check;
}

void sortascend(int*& array,int length)    {
    int number = 0;
    for(int i=0;i<length;i++)   {
        number = array[i];
        for(int j=i;j<length;j++)   {
            if(number>array[j]) {
                array[i] = array[j];
                array[j] = number;
            }
        }
    }
}

void arrayassign(int*& target,int*& origin,int length)  {
    for(int i=0;i<length;i++)   {
        target[i] = origin[i];
    }
}

void arrayassigndouble(double*& target,double*& origin,int length)  {
    for(int i=0;i<length;i++)   {
        target[i]=origin[i];
    }
}

void circshift(int*& array,int length,int cycles)   {
    bool check = ispos(cycles);
    int loops = absint(cycles);
    int* copy = new int[length];
    if(check==true) {
        for(int n=0;n<loops;n++) {
            for (int i = 0; i < length; i++) {
                if (i == 0) {
                    copy[i] = array[length - 1];
                    //cout << copy[i] << endl;
                } else {
                    copy[i] = array[i - 1];
                }
            }
            arrayassign(array,copy,length);
        }
    }
    else    {
        for(int n=0;n<loops;n++) {
            for (int i = 0; i < length; i++) {
                if (i == length - 1) {
                    copy[i] = array[0];
                } else {
                    copy[i] = array[i + 1];
                }
            }
            arrayassign(array,copy,length);
        }
    }
    delete[] copy;
}

void circshiftdouble(double*& array,int length,int cycles)  {
    bool check = ispos(cycles);
    int loops = absint(cycles);
    double* copy = new double[length];
    if(check==true) {
        for(int n=0;n<loops;n++) {
            for (int i = 0; i < length; i++) {
                if (i == 0) {
                    copy[i] = array[length - 1];
                    //cout << copy[i] << endl;
                } else {
                    copy[i] = array[i - 1];
                }
            }
            arrayassigndouble(array,copy,length);
        }
    }
    else    {
        for(int n=0;n<loops;n++) {
            for (int i = 0; i < length; i++) {
                if (i == length - 1) {
                    copy[i] = array[0];
                } else {
                    copy[i] = array[i + 1];
                }
            }
            arrayassigndouble(array,copy,length);
        }
    }
    delete[] copy;
}

void printintarray(int*& array,int length) {
    for(int i=0;i<length;i++)   {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void printdoublearray(double*& array,int length) {
    for(int i=0;i<length;i++)   {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void printboolarray(bool*& array,int length) {
    for(int i=0;i<length;i++)   {
        cout<<array[i]<<endl;
    }
    cout<<endl;
}

int dotproductint(int*& array1,int*& array2,int length)  {
    int number=0;
    for(int i=0;i<length;i++)   {
        number+= array1[i]*array2[i];
    }
    return number;
}

double dotproductdouble(double*& array1,double*& array2,int length)  {
    int number=0;
    for(int i=0;i<length;i++)   {
        number+= array1[i]*array2[i];
    }
    return number;
}

int sumintvector(int*& array1,int length)   {
    int number=0;
    for(int i=0;i<length;i++)   {
        number+= array1[i];
    }
    return number;
}

double sumdoublevector(double*& array1,int length)   {
    int number=0;
    for(int i=0;i<length;i++)   {
        number+= array1[i];
    }
    return number;
}

int maxintvector(int*& array,int length)    {
    int number =0;
    for(int i=0;i<length;i++)   {
        if(array[i]>number) {
            number = array[i];
        }
    }
    return number;
}

double maxdoublevector(double*& array,int length)    {
    double number =array[0];
    for(int i=0;i<length;i++)   {
        if(array[i]>number) {
            number = array[i];
        }
    }
    return number;
}

void zerosarraydouble(double*& target,int length) {
    target = new double[length];
    for(int i=0;i<length;i++)   {
        target[i] = 0.0;
    }
}

void insertzerosdouble(double*& int length) {
    for(int i=0;i<length;i++)   {
        target[i] = 0.0;
    }
}
