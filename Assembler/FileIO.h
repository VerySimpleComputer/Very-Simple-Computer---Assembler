//
//  FileIO.h
//  Assembler
//
//  Created by Harrison on 10/17/15.
//  Copyright © 2015 HarrisonStatham. All rights reserved.
//

#ifndef FileIO_h
#define FileIO_h

#include <stdio.h>
#include "Buffer.h"


FILE *open_file(char *filename);

unsigned long file_size(FILE *f);

buffer *read_file(FILE *f);

#endif /* FileIO_h */
