//
//  harveymaths.cpp
//  leaderfollower
//
//  Created by Harvard Virgil Humphrey on 2019/7/22.
//  Copyright © 2019 Harvard Virgil Humphrey. All rights reserved.
//

#include "harveymaths.hpp"

double wrap2pi(double number) {
    double pi = 3.141592654
    number = fmod(number + pi,2*pi);
    if (x < 0)
        x += 2*pi;
    return x - pi;
}

