#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100];
  List *history = init_history();
  while(1)
  {
    printf("Welcome, here are your options:\n");
    printf("Input any sentence to tokenize\n");
    printf("Input & to see all the sentences you have tokenized\n");
    printf("Input ! followed by a number to retrieve the sentence tokenized\n");
    printf("Input '@' to quit\n");
    fgets(input, 100, stdin);

    if(input[0] == '!')
    {
      int value = sscanf(input+1, "%d", &value);
      printf("%s\n", get_history(history, value));
    }

    else if(input[0] == '&')
    {
      print_history(history);
      printf("\n");
    }
    
    else if(input[0] == '@')
    {
      printf("Have a nice day!\n");
      free_history(history);
      return 0;
    }

    else
    {
      add_history(history,input);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }

    
    



    /*
  char *c = "hello how are you?";
  char *s = "one two three four five";
  char **test1 = tokenize(s);

  print_tokens(test1);

  //free_tokens(test1);

  char **test2 = tokenize(c);

  print_tokens(test2);

  //free_tokens(test2);



  List *history = init_history();

  int i = 0;

  while(test1[i] != 0)

    {

      add_history(history,test1[i]);

      i++;

    }

  printf("%s\n", get_history(history, 2));

  printf("%s\n", get_history(history, 5));

  print_history(history);

  free_history(history);
  free_tokens(test1);
  free_tokens(test2);*/
  }

}
