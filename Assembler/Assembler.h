//
//  Assembler.h
//  Assembler
//
//  Created by Harrison on 10/18/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#ifndef Assembler_h
#define Assembler_h

#include <stdio.h>
#include "FileIO.h"
#include "Buffer.h"
#include <stdlib.h>
#include <ctype.h>

buffer *strip_whitespace(buffer *buff);
buffer *strip_comments(buffer *buff);


#endif /* Assembler_h */
