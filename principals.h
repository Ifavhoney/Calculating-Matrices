//
//  principals.h
//  assgn3
//
//  Created by Jason Eddy on 2019-10-31.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

#ifndef principals_h
#define principals_h

#include <stdio.h>

struct title_principals{
    char *tconst;
    char *nconst;
    char *characters;
};

struct title_principals *get_title_principals(char *value);


#endif /* principals_h */
