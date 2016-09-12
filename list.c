#include "list.h"

int list_size(Node *n) {
  
  int size = 0;
  Node *temp = n;

    while (temp != NULL) {
	size++;
	temp = temp->next;
    } 
    return size;
}

// Add a word to the list

void list_add(char *word, Node **n) {
    printf("In method list_add\n");
  if((*n) == NULL) {
    
    printf("Adding first element\n\n");
    
    (*n) = malloc(sizeof(struct Node));
    if((*n) == NULL) malloc_fail("List.c: n");
    size_t word_size = (strlen(word) * sizeof(char));
    (*n)->word = malloc(word_size);
    if((*n)->word == NULL) malloc_fail("List.c: n->word");
    strncpy((*n)->word, word, word_size);
    (*n)->next = NULL;
    
    printf("Added first element \n");
    list_display(n);
    
  } else {
     
    printf("Adding additional element\n\n");
    
    Node *temp = (*n);
    
    printf("After temp alloc\n");
    
    while(temp->next != NULL) {
      temp = temp->next;
    }
    
    printf("After while loop\n");
    
    temp->next = malloc(sizeof(struct Node));
    if(temp->next == NULL) malloc_fail("List.c: temp->next");
    
    temp = temp->next;
    
    if(temp == NULL) malloc_fail("List.c: temp");
    
    temp->next = NULL;
    
    size_t word_size = (strlen(word) * sizeof(char));
    temp->word = malloc(word_size);
    
    if(temp->word == NULL) malloc_fail("List.c: temp->word");
    strncpy(temp->word, word, word_size);  
    
    printf("Added additional element\n");
    list_display(n);
  }
}

// For debugging purposes

void malloc_fail(char *source) {
 printf("[Malloc has failed]\n Source: %s\n", source);
 exit(-1); 
}

// Display the list of stored words

void list_display(Node **n){
  
 printf("\n[Displaying List] Size: %d\n-------------------------------------------\n", list_size((*n)));
  
Node *temp = (*n);

    while (temp != NULL) { 
	printf( "%s\n", temp->word );
	temp = temp->next;
    } 
}

void list_free(Node **n) {
  
  Node *temp = (*n);
  // Temporary variable used to free memory without altering the loop
  Node *free_this;
  
    while (temp != NULL) {
  
        free_this = temp;
        temp = temp->next;
	free(free_this->word);
	free(free_this);
    }
}
  