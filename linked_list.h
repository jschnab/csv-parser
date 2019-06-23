#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

// node linked list containing double data
typedef struct node {
    double data;
    struct node *next;
} Node;

// node of linked list containing other linked lists
typedef struct node_l {
    Node *data;
    struct node_l *next;
} Node_l;

// array of 'double' numbers and variable to store array size
typedef struct arr {
    double *values;
    size_t length;
} sized_arr;


// function declarations to work with "double" linked lists
void insert_begin(double x, Node **head);
void insert_end(double x, Node **head);
void traverse(Node *head);
int get_size(Node *head);
void delete_begin(Node **head);
void delete_end(Node **head);

// function declarations to work with linked lists containing
// other linked lists
void insert_begin_l(Node *data, Node_l **head);
void insert_end_l(Node *data, Node_l **head);
void traverse_l(Node_l *head);
int get_size_l(Node_l *head);
void delete_begin_l(Node_l **head);
void delete_end_l(Node_l **head);

// function to convert a linked list to an array of double
sized_arr convert_list_array(Node *list);

#endif
