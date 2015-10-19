//
//  FileIO.c
//  Assembler
//
//  Created by Harrison on 10/17/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#include "FileIO.h"
#include <stdlib.h>
#include "Buffer.h"

/**
 * open_file()
 *
 * Open a file.
 *
 * @params  char *
 * @return  FILE *
 */

FILE *open_file(char *file_name) {
    
    char *mode = "r";
    FILE *f = fopen(file_name, mode);
    
    if(f == NULL) {
        fprintf(stderr, "Cannot open file. \n");
        return NULL;
    }
    
    return f;
}


/**
 * file_size()
 *
 * Get the size of the file in bytes.
 *
 * @params  FILE *
 * @return  unsigned int
 */

unsigned long file_size(FILE *f) {
    
    unsigned long size = 0;
    
    fseek(f, 0, SEEK_END);
    size = (unsigned long) ftell(f);
    rewind(f);
    
    return size;
}



/**
 * read_file()
 *
 * Read a file.
 *
 * @params  FILE *
 * @return  char *
 */

struct buffer *read_file(FILE *f) {
    
    int c;
    int i = 0;
    
    unsigned long size = file_size(f); // the number of bytes to allocate.
    
    buffer *buff = buffer_init(size);
    
    do {
        c = fgetc(f);
        buff->buffer[i] = c;
        i++;
        
    } while(c != EOF);

    return buff;
}





