//
//  mathfunctions.cpp
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

bool ispos(int number)  {
    bool check = false;
    if(number>0)    {
        check = true;
    }
    return check;
}

bool isposdouble(double number) {
    bool check = false;
    if(number>0)    {
        check = true;
    }
    return check;
}

int absint(int number)  {
    bool check = ispos(number);
    if(check==false)    {
        number = -number;
    }
    return number;
}

double absdouble(double number)  {
    bool check = isposdouble(number);
    if(check==false)    {
        number = -number;
    }
    return number;
}
