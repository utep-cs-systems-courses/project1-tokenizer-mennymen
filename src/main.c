#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  
  char *c = "hello how are you?";
  char *s = "one two three four five";
  char **test1 = tokenize(s);
  //print_tokens(test1);
  //free_tokens(test1);
  char **test2 = tokenize(c);
  //print_tokens(test2);
  // free_tokens(test2);
  
  List *history = init_history();
  int i = 0;
  while(test1[i] != 0)
    {
      add_history(history,test1[i]);
      i++;
    }
  //printf("%s\n", get_history(history, 2));
  // printf("%s\n", get_history(history, 5));
  print_history(history);
  // free_history(history);

}
