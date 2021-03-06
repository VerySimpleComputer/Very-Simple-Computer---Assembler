//
//  Assembler.c
//  Assembler
//
//  Created by Harrison on 10/18/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#include "Assembler.h"

static int is_boundary(int start, int finish, int i) {
    
    return (i > start && i < finish);
}


buffer *strip_whitespace(buffer *buff) {
    
    buffer *b;
    
    
    
    return b;
}


buffer *strip_comments(buffer *buff) {
    
    buffer *b = buffer_init(buff->size);
    
    if(b == NULL)
    {
        buffer_allocation_failed(buff->size, __LINE__);
        return NULL;
    }
    
    int actualIndex = 0;
    int inComment = 0;
    int finish = (int) buff->size;
    char c;
    char prev = 0;
    char next = 0;
    char hasSeenChar = 0;
    
    for(int i = 0; i < finish; i++)
    {
        c = buff->buffer[i];
        
        if(!is_boundary(0, finish, i)) {
            
            prev = buff->buffer[i-1];
            next = buff->buffer[i+1];
        }
        
        if(c == ';') {
            
            // If we have a ';', then just ignore it.
            inComment = 1;
            continue;
        
        } else if(inComment && c != '\n') {
            
            // If we are inside a comment and we dont have an end of line
            // then we just ignore the current character.
            continue;
        
        } else {
            
            if(isalpha(c) && !hasSeenChar) {
                hasSeenChar = 1;
            }
            
            // Only push \n preceded by characters.
            if(c == '\n') {
                
                if(inComment)
                {
                    // end comment.
                    inComment = 0;
                }
                
                if(!hasSeenChar) {
                    continue;
                }
                
            }
            
            // Just push the character.
            
            b->buffer[actualIndex] = c;
            
            actualIndex++;
        }
    }
    
    // Go ahead and release the previous buffer.
    
    buffer_print(b);
    
    buffer_destroy(buff);
    
    return b;
}