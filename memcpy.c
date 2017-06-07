//
//  memcpy.c
//  
//
//  Created by Harrison Bronfeld on 6/6/17.
//
//

#include <stddef.h>

memcpy(void *restrict dst, const void *restrict src, size_t n){
    char *d = dst;
    const char *s = src;
    for (int i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dst;
}
