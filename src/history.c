#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history()
{
  List *list = (List*)malloc(sizeof(List));
  list-> root = (Item*)malloc(sizeof(Item));
  return list;
}


void add_history(List *list, char *str)
{
  Item *currNode = list -> root;
  if(list->root->id == 0)
  {
    list-> root-> str = str;
    list-> root-> id = 1;
  }
  else
  {
    int id = 2;
    while(currNode->next != 0)
    {
      currNode = currNode->next;
      id++;
    }
    currNode-> next = malloc(sizeof(Item));
    currNode-> next-> str = str;
    currNode-> next-> id = id;
  }
}


char *get_history(List *list, int id)
{
  Item *tempNode = list-> root;
  while(tempNode != NULL)
  {
    if(tempNode-> id == id)
      return tempNode-> str;
    
    tempNode = tempNode-> next;
  }
  return "ID not in list";
}


void print_history(List *list)
{
  Item *currNode = list-> root;
  while(currNode != NULL)
  {
    printf("%d) %s\n", currNode-> id, currNode-> str);
    currNode = currNode-> next;
  }
}


void free_history(List *list)
{
  Item *nextNode = list->root;
  while(nextNode-> next != NULL)
  {
    Item *currNode = nextNode;
    nextNode = nextNode-> next;
    //free(currNode-> str);
    //free(currNode-> next);
    free(currNode);
  }
  //free(nextNode-> str);
  //free(nextNode-> next);
  free(nextNode);
  free(list);
}
