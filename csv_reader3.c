#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // add "-lm" when compiling
#include "linked_list.h"
#include "stat_funcs.h"
#include "searching.h"


int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("Please provide a filename : ./csv_reader3 <file name>\n");
        exit(0);
    }

    else if (argc > 2) {
        printf("Please provide a single argument.\n");
        exit(0);
    }

    // open file
    FILE *csv = NULL;
    csv = fopen(argv[1], "r");
    if (csv == NULL) {
        printf("Could not read file\n");
        exit(0);
    }
    
    char line[100] = {0};

    char *token;

    // this is a linked list made of linked lists
    Node_l *dataframe = NULL;

    // iterate through file rows
    // put row in a linked list
    printf("Reading CSV file '%s'\n", argv[1]);
    while (fgets(line, 100, csv) != NULL) {

        // iterate through characters
        // put character in linked list called 'row'
        Node *row = NULL;

        token = strtok(line, ",");

        while (token != NULL) {
            insert_end(atof(token), &row);
            token = strtok(NULL, ",");
        }

        insert_end_l(row, &dataframe);
    }

    fclose(csv);

    printf("Finished reading file\n\n");

    traverse_l(dataframe);


    Node *temp = dataframe->data;
    printf("\nTraverse temp:\n");
    traverse(temp);
    printf("\n");

    sized_arr array = convert_list_array(dataframe->next->data);

    quicksort(array.values, 0, array.length - 1);

    printf("Sorted array\n");

    int i = 0;
    for (i = 0; i < array.length; i++)
        printf("array[%d] = %f\n", i, array.values[i]);

    printf("\nMedian : %f\n", median(array));

    printf("\nMedians of the dataframe\n------------------------\n");

    // iterate over rows of dataframe and print median
    Node_l *row = dataframe;
    i = 1;
    while (row != NULL) {
        sized_arr array = convert_list_array(row->data);
        printf("Median of row %d : %.3f\n", i, median(array));
        row = row->next;
        i++;
    }

    return 0;
}
