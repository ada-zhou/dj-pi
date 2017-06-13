//
//  round.c
//  
//
//  Created by Cui Zhou on 6/12/17.
//
//

#include "round.h"

int round_int(double num){
    if (num >= (double)((int)num) + 0.5)
        return num + 1;
    return num;
}
