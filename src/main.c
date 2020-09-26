#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100]; 
  List *history = init_history(); 
  while (1) {   /* Infinite loop for our UI */
  
    printf("Welcome, here are your options:\n"); /* Given options to use the UI */
    printf("Input any sentence to tokenize\n");
    printf("Input '$' to see all the sentences you have tokenized\n");
    printf("Input '!' followed by a number to retrieve a specific sentence that was tokenized\n");
    printf("Input '@' to quit\n");
    printf("$ ");
    fgets(input, 100, stdin);    /* Get user input */
    
    if (input[0] == '!') {  /*If the first character is '!', it will retrieve the sentence corresponding to the number */
      int value; 
      value = atoi(input+1);  /* Convert input into an int */
      if (value <= 0) {    /* Handling 0 or negative integers */
	printf("Invalid input\n");

      } else {
	  printf("Here's your sentence:\n");
	  printf("%s\n", get_history(history, value));  /* Retrieve sentence using get_history */    
      }
      
    } else if (input[0] == '$') { /* If the first character is '$', it will print out the entire history */
        printf("These are the sentences you have tokenized so far:\n");
        print_history(history);
        printf("\n");
      
    } else if (input[0] == '@') {  /* If the first character is '@', it will end the program */
        printf("Have a nice day!\n");
        free_history(history); /* Free history before ending the program */
        return 0;
      
    } else { /* If it is anything else, it will tokenize it and print it */
        char *str = input;
        add_history(history,str);
        char **tokens = tokenize(str);
        printf("Here are your tokens from your input:\n");
        print_tokens(tokens);
        free_tokens(tokens); /* Free the tokens */
    }
  }   
}
