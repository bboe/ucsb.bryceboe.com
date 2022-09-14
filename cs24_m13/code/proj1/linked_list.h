#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* The list structure is used to store a list of strings.

   The linked implementation should use a linked set of Nodes.
*/

struct Node {
  char *_data;
  struct Node *_next;
};

struct List {
  struct Node *_head;
};

/* Return the value of the item at the indicated position, or NULL if the
   position is invalid.

   Negative numbers are supported to mean position from the end of the
   list. For instance -1 is the last element in the list and -SIZE would be the
   first element. -(SIZE + 1) is invalid.
 */
char *list_at(struct List *list, int position);

/* Allocate a List structure and return it for use. Return NULL if allocation
   fails. */
struct List *list_construct();

/* Free any memory allocated by the list, including the List structure
   itself.

   An interesting question is what to do with the character strings. Do they
   need to be freed? The answer is, yes they do, but should this function be
   responsible for that, or should the function simply enforce that it can only
   be called when the list is empty? We'll take the later approach because the
   list shouldn't be responsible for managing the items it is storing.

*/
void list_destruct(struct List *list);

/* Return the size, or number of elements, in the list. */
int list_get_size(struct List *list);

/* Return 1 if the list is empty, 0 otherwise */
int list_is_empty(struct List *list);

/* Output the contents of the list */
void list_output(struct List *list);

/* Add item to the end of the list. Return 1 upon success or 0 upon failure. */
int list_push_back(struct List *list, char *item);

/* Remove and return the element at the indicated position. Return NULL if the
   position is not valid.

   Negative numbers are supported to mean position from the end of the
   list. For instance -1 is the last element in the list and -SIZE would be the
   first element. -(SIZE + 1) is invalid.
*/
char *list_remove_at(struct List *list, int position);


#endif /* ARRAY_LIST_H */
