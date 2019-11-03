//
//  common.h
//  assignment3
//
//  Created by Jason Eddy on 2019-10-29.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

#ifndef common_h
#define common_h

#include <stdio.h>


void add_new_word(const char*w);
//a string that contains entire line from the file, where contents will be copied to, a column number
char *get_column(char *src, int colNum);
//length
int totalRows(FILE* fp);
#endif /* common_h */
