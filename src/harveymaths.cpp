//
//  harveymaths.cpp
//  leaderfollower
//
//  Created by Harvard Virgil Humphrey on 2019/7/22.
//  Copyright © 2019 Harvard Virgil Humphrey. All rights reserved.
//

#include "harveymaths.hpp"
#include <math.h>

double wrap2pi(double number) {
    double pi = 3.141592654;
    number = fmod(number + pi,2*pi);
    if (number < 0)
        number += 2*pi;
    return number - pi;
}

