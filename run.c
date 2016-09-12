#include "utilities.h"
#include "list.h"
#include "threads.h"

    int main (int argc, char *argv[]) {

	if(argc != 2) {
	    printf("Illegal arguments supplied\n");
	    exit(-1);
	 }
	
	  Node *new = NULL;
	  char *argument = argv[1];
          Node *file = read_file(argument, 128, &new);
	  
          printf("\n\n---------------- FINISHED ------------------\n\n");  
	  
	  int numofcpus = sysconf(_SC_NPROCESSORS_ONLN); 
	  
	  if (numofcpus < 0) {
	   printf("FATAL ERROR\n"); 
	   exit(-1);
	  } else {
	   printf("%d\n",numofcpus);
	  }
	  
//           int word_distribution = (list_size(new) / numofcpus);
//           int remainder = (list_size(new) % numofcpus);
	  
// 	  word_distribution = remainder + word_distribution;
	  
          // Distribute the words among the cpu's
                     
           printf("\n\n - - - - [Fetching file] - - - - \n\n");
           
           	  
 	Node *temp = file;
 
 	while (temp != NULL) { 
 	printf( "%s\n", temp->word );
 	temp = temp->next;
	} 
	
// 	free(file);
	list_free(&file);
    
    printf("Attempting to free memory...\n");
    
//     list_free(file);
	  	  
    return 0;
}