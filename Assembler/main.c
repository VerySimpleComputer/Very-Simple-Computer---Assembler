//
//  main.c
//  Assembler
//
//  Created by Harrison on 10/16/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "FileIO.h"
#include "Assembler.h"



int main(int argc, const char * argv[]) {
    
    char *file = "/Users/harrison/Documents/Personal/programming/Assembler/Assembler/test.txt";
    
    FILE *f = open_file(file);
    
    buffer *buff = read_file(f);
    
    // Note, buff will be released by stip_comments
    buffer *stripped = strip_comments(buff);
    
    
    
//    for(int i = 0; i < stripped->size; i++)
//    {
//        printf("%c", stripped->buffer[i]);
//    }
    
    strip_whitespace(stripped);
    
    
    
    return 0;
}
