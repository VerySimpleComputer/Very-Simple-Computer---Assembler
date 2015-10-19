//
//  Buffer.h
//  Assembler
//
//  Created by Harrison on 10/19/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#ifndef Buffer_h
#define Buffer_h

#include <stdio.h>

struct buffer {
    
    char *buffer;
    unsigned long size;
};

typedef struct buffer buffer;

buffer *buffer_init(unsigned long size);

void buffer_destroy(buffer *b);

void buffer_print(buffer *b);

void buffer_allocation_failed(unsigned long size, int line);

#endif /* Buffer_h */
