#include "utilities.h"
#include "list.h"

// Output error, and terminate the program
void error(char *msg) {
  printf("%s\n", msg);
  exit(-1);
}

// Read file into memory

struct Node *read_file(char *fn, size_t buf_size, struct Node **n) {
  
     FILE *f;
     char *token;
     char buffer[buf_size];
     char *line;
     char delimiter[] = " ";
        
   // Create a new file in read only mode
    if((f = fopen (fn, "r")) == NULL) {
       error("ERROR: [Opening file]");
    }
      
      while (fgets(buffer, buf_size, f) != NULL) {    
	
	  int buf_length = strlen(buffer);
	  int reduction = 0;
	  
	  // If there exists a newline at the end of the string, one should remove it by ignoring it  
	  if(buffer[buf_length-1] == '\n') {
	    reduction = 2;
	  }
	  
	  // Allocate memory according to the reduction variable
	  line = malloc(buf_length - reduction);
	  if(line == NULL) malloc_fail("Utilies.c: line");
          
	  // Copy from buffer to our variable "line", which is to used by strsep below
	  strncpy(line, buffer, buf_length - reduction);	   
	  
	  // Once has to copy the content of line and pass this pointer to strsep in order to free the original variable
	  char *line_copy = line;
	  
	  // Split the line read according to critera "delim" with the use of strsep
	while ((token = strsep(&line_copy, delimiter)) != NULL) {
 	       list_add(token, n);
        }
        
        // Free memory associated with allocation
         free(line);
   }
                    
     fclose(f); 
     
//          char memory[(sizeof(struct Node))];
//           Node *results = malloc(sizeof(struct Node));
//          results = (*n) ;
     
     
     return (*n);
}
