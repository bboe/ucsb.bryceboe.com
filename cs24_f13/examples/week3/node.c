#include <stdio.h>
#include <stdlib.h>

struct int_node {
  int data;
  struct int_node *next;
};


/*
  Note in this example we are not validating any of the malloc returns.
  You will need to do that.
*/

int main() {
  struct int_node *first, *tmp;

  // Add an item to the head of the linked structure
  first = malloc(sizeof(struct int_node));
  first->data = 1;
  first->next = NULL;  // This node does not point to anything

  // Add to the beginning
  tmp = first;
  first = malloc(sizeof(struct int_node));
  first->data = 2;
  first->next = tmp;

  // Add in the middle
  tmp = malloc(sizeof(struct int_node));
  tmp->next = first->next;
  tmp->data = 3;
  first->next = tmp;

  // Output the items of the linked structure
  tmp = first;
  while (tmp != NULL) {
    printf("%d\n", tmp->data);
    tmp = tmp->next;
  }



  free(first->next->next);
  free(first->next);
  free(first);

  struct list *list = list_construct();
  list_insert_at(list, -1, 1);
  list_insert_at(list, 0, 2);
  list_insert_at(list, 1, 3);
  list_output(list);
  list_destruct(list);

  return 0;
}
