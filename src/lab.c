#include "lab.h"

list_t *list_init(void (*destroy_data)(void *),
                  int (*compare_to)(const void *, const void *)) {
  list_t *list = (list_t *)malloc(sizeof(list_t));
  if (!list) {
    return NULL;
  }

  list->destroy_data = destroy_data;
  list->compare_to = compare_to;
  list->size = 0;

  list->head = (node_t *)malloc(sizeof(node_t));
  if (!list->head) {
    free(list);
    return NULL;
  }

  list->head->data = NULL;
  list->head->next = list->head;
  list->head->prev = list->head;

  return list;
}

void list_destroy(list_t **list) {
  if (!list || !*list) {
    return;
  }

  list_t *l = *list;
  node_t *curr = l->head->next;
  while (curr != l->head) {
    node_t *tmp = curr;
    curr = curr->next;
    l->destroy_data(tmp->data);
    free(tmp);
  }

  free(l->head);
  free(l);
  *list = NULL;
}