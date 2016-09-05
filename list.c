#include "list.h"

// Points to an object that conforms to the struct "Array"
Node *root = NULL;
int size = 0;


void list_add(char *word) {
  
  
 //  
  if(root == NULL) {
    
    root = malloc(sizeof(Node));
    if(root == NULL) malloc_fail();
    size_t word_size = (strlen(word) * sizeof(char));
    root->word = malloc(word_size);
    if(root->word == NULL) malloc_fail();
    strncpy(root->word, word, word_size);
    root->next = NULL;
    size++;   
     
  } else {
    
    Node *temp = root;
    
    while(temp->next != NULL) {
      temp = temp->next;
    }
    
    temp->next = malloc(sizeof(Node));
    if(temp->next == NULL) malloc_fail();
    
    temp = temp->next;
    
    if(temp == NULL) malloc_fail();
    
    temp->next = NULL;
    
    size_t word_size = (strlen(word) * sizeof(char));
    temp->word = malloc(word_size);
    if(temp->word == NULL) malloc_fail();
    strncpy(temp->word, word, word_size);  
    size++;
  }
  
}

void malloc_fail() {
 printf("[Malloc has failed]\n");
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

int list_size() {
  return size;
}

void list_free() {
  
  
}