#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != '\0')
    return 1;

  return 0;
}



int non_space_char(char c)
{
  if((c != ' ' && c != '\t') && c != '\0')
    return 1;

  return 0;
}



char *word_start(char *str)
{
  char *new_start = str;
  while(space_char(*new_start))
    new_start++;

  return new_start;
}



char *word_terminator(char *word)
{
  char *new_end = word;
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
  while(str[i] != '\0')
  {
    if(str[i] == ' ' && non_space_char(str[i+1]))
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
  t = (char*)malloc(sizeof(char)*(len+1));
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
  char **tokens = (char **) malloc(sizeof(char*)*(num_words+1));
  for(int i = 0; i < num_words; i++)
  {
    tokens[i] = copy_str(str, word_terminator(str) - word_start(str));
    str = word_terminator(str)+1;
  }
  return tokens;
}



void print_tokens(char** tokens)
{
  while(*tokens)
  {
    printf("%s\n", *tokens++);
  }
}


void free_tokens(char** tokens)
{
  int i = 0;
  while(tokens[i])
  {
      free(tokens[i]);
      i++;
  }
  free(tokens);
}

