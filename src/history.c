#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List));
  list->root = (Item*)malloc(sizeof(Item));
  return list;
}


void add_history(List *list, char *str)
{
  int strLen = 0;
  char *temp = str;
  while (*temp != '\0') {
    temp++;
    strLen++;
  }
  
  char *strCopy = copy_str(str, strLen);
  Item *currNode = list->root;
  
  if (list->root->id == 0) { /* If list is empty */
    list->root->str = strCopy;
    list->root->id = 1;
    
  } else {  /* If list already has at least one element */
    int id = 2;
    while (currNode->next != 0) {
      currNode = currNode->next;
      id++;
    }
    currNode->next = malloc(sizeof(Item));
    currNode->next->str = strCopy;
    currNode->next->id = id;
  }
}


char *get_history(List *list, int id)
{
  Item *tempNode = list->root;
  while (tempNode != NULL) { /* Iterate through the entire list */
    if (tempNode->id == id)
      return tempNode->str;
    
    tempNode = tempNode->next;
  }
  return "ID not in list";
}


void print_history(List *list)
{
  Item *currNode = list->root;
  while(currNode != NULL) { /* Iterate through the entire list */
    printf("%d) %s\n", currNode->id, currNode->str); /* Print id and string of current node */
    currNode = currNode->next;
  }
}


void free_history(List *list)
{
  Item *nextNode = list->root;
  while(nextNode-> next != NULL) { /* Iterate through the list to free each node */
    Item *currNode = nextNode;
    nextNode = nextNode->next;
    free(currNode->str);  /* First free the string from the current node */
    free(currNode);    /* Free the current node */
  }
  free(nextNode->str);  /* Free the string from the last node */
  free(nextNode);   /* Free the last node */
  free(list); /* Free the list itself */
}
