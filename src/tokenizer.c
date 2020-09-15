#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


int space_char(char c)
{
  return c == ' ' || c == '\t' || c == '\0';
}



int non_space_char(char c)
{
  return c != ' ' && c != '\t' && c != '\0';
}



char *word_start(char *str)
{
  int i = 0;
  while(str)
  {
    if(non_space_char(*(str+i)))
	return str+i;
    
    i++;
  }
  if(*str == '\0')
    return 0;

  return &str[i];
}



char *word_terminator(char *word)
{
  int i = 0;
  while(non_space_char(word[i+1]))
  {
    i++;
  }
  return &word[i];
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
  for(; len > 0; len--)
  {
    t[i] = inStr[i];
    i++;
  }
  t[i] = '\0';
  return t;
}



char **tokenize(char *str)
{
  int num_words = count_words(str);
  char **tokens = (char **) malloc(sizeof(char*)*(num_words+1));
  int i;
  for(i = 0; i < num_words; i++)
  {
    tokens[i] = copy_str(str, word_terminator(str) - word_start(str) + 1);
    str = word_terminator(str)+2;
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

