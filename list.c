#include "list.h"

Node *root = NULL;
int size = 0;

// Add a word to the list
void list_add(char *word) {
     
  if(root == NULL) {
    
    root = malloc(sizeof(Node));
    if(root == NULL) malloc_fail("List.c: root");
    size_t word_size = (strlen(word) * sizeof(char));
    root->word = malloc(word_size);
    if(root->word == NULL) malloc_fail("List.c: root->word");
    strncpy(root->word, word, word_size);
    root->next = NULL;
    size++;   
     
  } else {
    
    Node *temp = root;
    
    while(temp->next != NULL) {
      temp = temp->next;
    }
    
    temp->next = malloc(sizeof(Node));
    if(temp->next == NULL) malloc_fail("List.c: temp->next");
    
    temp = temp->next;
    
    if(temp == NULL) malloc_fail("List.c: temp");
    
    temp->next = NULL;
    
    size_t word_size = (strlen(word) * sizeof(char));
    temp->word = malloc(word_size);
    if(temp->word == NULL) malloc_fail("List.c: temp->word");
    strncpy(temp->word, word, word_size);  
    size++;
  }
  
}

// For debugging purposes
void malloc_fail(char *source) {
 printf("[Malloc has failed]\n Source: %s\n", source);
 exit(-1); 
}

// Display the list of stored words
void list_display(){
  
  printf("\n[Displaying List] Size: %d\n-------------------------------------------\n", size);
  
Node *temp = root;

    while (temp != NULL) {
  
	printf( "%s\n", temp->word );
	temp = temp->next;
    }
    
}


void list_free() {
  
  Node *temp = root;
  // Temporary variable used to free memory without altering the loop
  Node *free_this;
  
    while (temp != NULL) {
  
        free_this = temp;
        temp = temp->next;
	free(free_this->word);
	free(free_this);
    }
  

  
}
  
  
