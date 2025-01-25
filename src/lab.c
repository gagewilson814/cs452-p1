/**
 * @file lab.c
 * @brief implementation of a circular doubly linked list with a sentinel node.
 * @author Gage Wilson, CS452-001 Spring 2025
 */

#include "lab.h"

list_t *list_init(void (*destroy_data)(void *), int (*compare_to)(const void *, const void *)) {

  list_t *list = (list_t *)malloc(sizeof(list_t));
  // check if the list was allocated in memory successfully
  if (!list) {
    return NULL;
  }

  // setup function pointers
  list->destroy_data = destroy_data;
  list->compare_to = compare_to;
  list->size = 0;

  list->head = (node_t *)malloc(sizeof(node_t));
  if (!list->head) {
    return NULL;
  }

  // setup the sentinel node
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

  // free all the nodes in the list
  while (curr != l->head) {
    node_t *tmp = curr;
    curr = curr->next;
    l->destroy_data(tmp->data);
    free(tmp);
  }

  // free the sentinel node
  free(l->head);
  free(l);
  *list = NULL;
}

list_t *list_add(list_t *list, void *data) {
  if (!list) {
    return NULL;
  }

  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  // check if the new node was allocated successfully
  if (!newNode) {
    return NULL;
  }
  if (!data) {
    free(newNode);
    return list;
  }

  // setup the new node
  newNode->data = data;
  newNode->next = list->head->next;
  newNode->prev = list->head;

  // update the pointers of the nodes around the new node
  list->head->next->prev = newNode;
  list->head->next = newNode;
  list->size++;
  return list;
}

void *list_remove_index(list_t *list, size_t index) {
  // check if the list is valid and the index is within bounds
  if (!list || index >= list->size) {
    return NULL;
  }

  node_t *curr = list->head->next;
  // check if current was allocated successfully
  if (!curr) {
    return NULL;
  }

  // find the node at the index
  for (size_t i = 0; i < index; i++) {
    curr = curr->next;
  }

  // update the pointers of the nodes around the node to be removed
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  void *data = curr->data;
  free(curr);
  list->size--;
  return data;
}

int list_indexof(list_t *list, void *data) {
  // check if the list is valid
  if (!list || !data) {
    return -1;
  }

  int currentIndex = 0;
  node_t *curr = list->head->next;
  if (!curr) {
    return -1;
  }

  // find the index of the data
  while (curr != list->head) {
    if (list->compare_to(curr->data, data) == 0) {
      return currentIndex;
    }
    // move to the next node and increment our index as we walk though the list
    curr = curr->next;
    currentIndex++;
  }
  return -1;
}