#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  if ((c == ' ' || c == '\t') && c != '\0') /* Return true if c is space or tab but not \0 */
    return 1;

  return 0;
}


int non_space_char(char c)
{
  if ((c != ' ' && c != '\t') && c != '\0') /* Return true if c is not a space or tab and is not \0 */
    return 1;

  return 0;
}



char *word_start(char *str)
{
  char *new_start = str;
  while (space_char(*new_start)) /*If the current character is a space character, it skips it*/
    new_start++;
  
  return new_start;
}



char *word_terminator(char *word)
{
  char *new_end = word;
  while (non_space_char(*new_end)) { /* While the current character is not a space, it keeps moving on to the next one */
    new_end++;
  }
  return new_end;
}



int count_words(char *str)
{
  int count = 0;
  int i = 0;
  while (str[i] != '\0') { /* Iterate through all the characters and counts the spaces */
    if (space_char(str[i]) && non_space_char(str[i+1])) {
      count++;
    }
    i++;
  }
  count++;
  return count;
}



char *copy_str(char *inStr, short len)
{
  char *t;
  int i;
  t = (char*)malloc(sizeof(char)*(len+1)); /* Allocate memory for all the characters of input plus one */
  for (i = 0; len > i; i++) { /* Copy each character into the new pointer */
    t[i] = inStr[i];
  }
  t[i] = 0;
  return t;
}



char **tokenize(char *str)
{
  str = word_start(str);
  int num_words = count_words(str);
  char **tokens = (char **) malloc(sizeof(char*)*(num_words+1)); /* Allocate memory for all the words to be tokenized */
  int i;
  for (i = 0; i < num_words; i++) {
    tokens[i] = copy_str(str, word_terminator(str) - word_start(str)); /* We get the length of each word by getting their start and end */
    str = word_terminator(str)+1;
    str = word_start(str);
  }
  return tokens;
}



void print_tokens(char** tokens)
{
  while (*tokens) { /* Iterate through each pointer */
    printf("%s\n", *tokens++);
  }
}


void free_tokens(char** tokens)
{
  int i = 0;
  while(tokens[i]) { /* Iterate through each pointer to free them */
    free(tokens[i]);
    i++;
  }
  free(tokens); /* Then we free the pointer of pointers */
}

