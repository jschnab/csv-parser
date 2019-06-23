void swap(double *array, int first, int second) {
    double temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

int partition(double *array, int p, int r) {
    int q = p;
    int j;
    for (j = p; j < r; j++) {
        if (array[j] <= array[r]) {
            swap(array, q, j);
            q++;
        }
    }
    swap(array, q, r);
    return q;
}

void quicksort(double *array, int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quicksort(array, p, q - 1);
        quicksort(array, q + 1, r);
    }
}
