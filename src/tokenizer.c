#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  //Return true if c is space or tab but not \0
  if((c == ' ' || c == '\t') && c != '\0')
    return 1;

  return 0;
}



int non_space_char(char c)
{
  //Return true if c is not a space or tab and is not \0
  if((c != ' ' && c != '\t') && c != '\0')
    return 1;

  return 0;
}



char *word_start(char *str)
{
  char *new_start = str;
  //If the current character is a space character, it skips it
  while(space_char(*new_start))
    new_start++;

  return new_start;
}



char *word_terminator(char *word)
{
  char *new_end = word;
  //While the current character is not a space, it keeps moving on to the next one
  while(non_space_char(*new_end))
  {
    new_end++;
  }
  return new_end;
}



int count_words(char *str)
{
  int count = 0;
  int i = 0;
  //Iterate through all the characters and counts the spaces
  while(str[i] != '\0')
  {
    if(space_char(str[i]) && non_space_char(str[i+1]))
    {
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
  int i = 0;
  //Allocate memory for all the characters of input plus one
  t = (char*)malloc(sizeof(char)*(len+1));
  //Copy each character into the new pointer
  for(; len > i; i++)
  {
    t[i] = inStr[i];
  }
  t[i] = 0;
  return t;
}



char **tokenize(char *str)
{
  int num_words = count_words(str);
  //Allocate memory for all the words to be tokenized
  char **tokens = (char **) malloc(sizeof(char*)*(num_words+1));
  for(int i = 0; i < num_words; i++)
  {
    //We get the length of each word by getting their start and end
    tokens[i] = copy_str(str, word_terminator(str) - word_start(str));
    str = word_terminator(str)+1;
  }
  return tokens;
}



void print_tokens(char** tokens)
{
  //Iterate through each pointer
  while(*tokens)
  {
    printf("%s\n", *tokens++);
  }
}


void free_tokens(char** tokens)
{
  int i = 0;
  //Iterate through each pointer to free them
  while(tokens[i])
  {
      free(tokens[i]);
      i++;
  }
  //Then we free the pointer of pointers
  free(tokens);
}

