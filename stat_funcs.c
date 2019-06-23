#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stat_funcs.h"
#include "linked_list.h"
#include "searching.h"

double median(sized_arr array) {
    double median;
    quicksort(array.values, 0, array.length - 1);
    if (array.length & 1) {
        int med_index;
        med_index = (array.length - 1) / 2;
        median = array.values[med_index];
    }
    else {
        float med_index;
        int index_a, index_b;
        med_index = (float) (array.length - 1) / 2;
        index_a = floor(med_index);
        index_b = ceil(med_index);
        median = (array.values[index_a] + array.values[index_b]) / 2;
    }
    return median;
}
