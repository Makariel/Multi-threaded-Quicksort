#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include "list.h"

void error (char *msg);
void read_file(char *fn, size_t buf_size);

