//
//  Buffer.c
//  Assembler
//
//  Created by Harrison on 10/19/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#include "Buffer.h"
#include <assert.h>
#include <stdlib.h>

void buffer_allocation_failed(unsigned long size, int line) {
    
    fprintf(stderr, "Could not allocate buffer of size: %lu on line: %d\n", size, line);
}

buffer *buffer_init(unsigned long size) {
    
    buffer *b = (buffer *) malloc(sizeof(buffer));
    
    if(b == NULL) {
        
        buffer_allocation_failed(size, __LINE__);
        return NULL;
    }
    
    b->size = size;
    
    b->buffer = (char *) malloc(sizeof(char *) * size);
    
    if(b->buffer == NULL) {
        
        buffer_allocation_failed(size, __LINE__);
        return NULL;
    }
    
    
    return b;
}



void buffer_destroy(buffer *buff) {
    
    free(buff->buffer);
    free(buff);
}



void buffer_print(buffer *b) {
    
    printf("Buffer: { \n");
    for(int i = 0; i < b->size; i++)
    {
        char c = b->buffer[i];
        
        printf("%c", c);
    }
    
    printf("\n }\n");
}



