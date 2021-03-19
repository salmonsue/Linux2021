#include "linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool list_is_ordered(node_t *list) {
  bool first = true;
  int value;
  while (list) {
    if (first) {
      value = list->value;
      first = false;
    } else {
      if (list->value < value)
        return false;
      value = list->value;
    }
    list = list->next;
  }
  return true;
}

static void list_display(node_t *list) {
  printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
  while (list) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("\n");
}

static node_t *list_make_node_t(node_t *list, int val) {
  node_t *tmp = list;
  node_t *n = malloc(sizeof(node_t));
  n->value = val;
  n->next = NULL;
  if (!list)
    return n;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = n;
  return list;
}

static void list_free(node_t **list) {
  node_t *pNode;
  while (*list) {
    pNode = *list;
    *list = ((*list)->next);
    free(pNode);
  }
}

int main(int argc, char **argv) {
  size_t count = 20;

  node_t *list = NULL;
  while (count--)
    list = list_make_node_t(list, random() % 1024);

  list_display(list);
  quicksort(&list);
  list_display(list);

  if (!list_is_ordered(list))
    return EXIT_FAILURE;

  list_free(&list);
  return EXIT_SUCCESS;
}
