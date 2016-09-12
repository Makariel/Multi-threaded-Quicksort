#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Node {
   char *word;
   struct Node *next;
}  Node; 

void list_add(char *word, Node **n);
void list_display(Node **n);
void list_free(Node **n);
int list_size(Node *n);
void malloc_fail(char *source);