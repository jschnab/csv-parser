#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// function to convert a linked list to an array
sized_arr convert_list_array(Node *list) {
    sized_arr sized_array;
    int size_list = get_size(list);
    double *array = NULL;
    array = malloc(sizeof(double) * size_list);
    Node *temp = list;
    int i;
    for (i = 0; i < size_list; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }
    sized_array.values = array;
    sized_array.length = size_list;
    return sized_array;
}

// functions to work with linked lists containing double data
void insert_begin(double x, Node **head) {
    Node *n;
    n = (Node*) malloc(sizeof(Node));
    if (*head == NULL) {
        n->data = x;
        n->next = NULL;
        *head = n;
        return;
    }
    n->data = x;
    n->next = *head;
    *head = n;
}

void insert_end(double x, Node **head) {
    Node *n, *temp;
    n = (Node*) malloc(sizeof(Node));
    if (*head == NULL) {
        n->data = x;
        n->next = NULL;
        *head = n;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->data = x;
    n->next = NULL;
}

void traverse(Node *head) {
    Node *n;
    n = head;
    if (n == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    while (n->next != NULL) {
        printf("%.3f, ", n->data);
        n = n->next;
    }
    printf("%.3f\n", n->data);
}

int get_size(Node *head) {
    Node *n;
    n = head;
    if (n == NULL)
        return 0;
    int c = 1;
    while (n->next != NULL) {
        c++;
        n = n->next;
    }
    return c;
}

void delete_begin(Node **head) {
    Node *n;
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
    }
    n = (*head)->next;
    free(*head);
    *head = n;
}

void delete_end(Node **head) {
    Node *n, *m;
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }
    n = *head;
    while (n->next != NULL) {
        m = n;
        n = n->next;
    }
    m->next = NULL;
    free(n);
}

// functions to work with linked lists containing
// other linked lists
void insert_begin_l(Node *data, Node_l **head) {
    Node_l *n;
    n = (Node_l*) malloc(sizeof(Node_l));
    if (*head == NULL) {
        n->data = data;
        n->next = NULL;
        *head = n;
        return;
    }
    n->data = data;
    n->next = *head;
    *head = n;
}

void insert_end_l(Node *data, Node_l **head) {
    Node_l *n, *temp;
    n = (Node_l*) malloc(sizeof(Node_l));
    if (*head == NULL) {
        n->data = data;
        n->next = NULL;
        *head = n;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->data = data;
    n->next = NULL;
}

void traverse_l(Node_l *head) {
    Node_l *n;
    n = head;
    if (n == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    int i = 1;
    while (n->next != NULL) {
        printf("Row %d : ", i);
        traverse(n->data);
        n = n->next;
        i++;
    }
    printf("Row %d : ", i);
    traverse(n->data);
}

int get_size_l(Node_l *head) {
    Node_l *n;
    n = head;
    if (n == NULL)
        return 0;
    int c = 1;
    while (n->next != NULL) {
        c++;
        n = n->next;
    }
    return c;
}

void delete_begin_l(Node_l **head) {
    Node_l *n;
    if ((*head) == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }
    n = (*head)->next;
    free(*head);
    *head = n;
}

void delete_end_l(Node_l **head) {
    Node_l *n, *m;
    if (*head == NULL) {
        printf("Linked list is already empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        head = NULL;
        return;
    }
    n = *head;
    while (n->next != NULL) {
        m = n;
        n = n->next;
    }
    m->next = NULL;
    free(n);
}
