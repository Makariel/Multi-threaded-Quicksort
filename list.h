#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Node {
 char *word;
 struct Node *next;
} Node;

void list_add(char *word);
void list_display();
void list_free();
void malloc_fail();