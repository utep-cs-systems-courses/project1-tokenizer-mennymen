#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"




int space_char(char c)
{
  return c == ' ' || c == '\t';
}



int non_space_char(char c)
{
  return c != ' ' && c != '\t';
}



char *word_start(char *s)
{
  while(space_char(*s))
    s++;

  if(s == '\0')
    return 0;

  return s;
}



char *word_terminator(char *word)
{
  int i = 0;
  while(word[i+1] != '\0')
    i++;

  return &word[i];
}



int count_words(char *s)
{
  int count = 0;
  int i = 0;
  while(s[i] != '\0')
  {

      if(s[i] == ' ')
	count++;
      
      i++;
  }
  count++;
  return count;
}



char *copy_str(char *inStr, short len)
{
  char *t;
  int i = 0;
  t = (char*)malloc(sizeof(char)*len);
  for(; len > 0; len--)
  {
      t[i] = inStr[i];
      i++;
  }
  return t;
}


void print_tokens(char** ptr){
  while(ptr != NULL)
  {
    printf("%s\n", *ptr++);
  }
}


char **tokenize(char *str)
{
  int num_words = count_words(str);
  char **tokens = (char **) malloc(sizeof(char*)*(num_words+1));
  int i;
  tokens[0] = str;
  for(i = 1; i < num_words; i++)
  {
      tokens[i] = word_terminator(str);
      str = word_start(tokens[i]);
  }
  tokens[i] = "\0";
  return tokens;
}

