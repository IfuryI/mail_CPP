#include <stdio.h>
#include <string.h>
#include "../include/parallel.h"
#include "../include/consistently.h"
#include "../include/utils.h"


int proccesing(FILE *fin, FILE *fout)
{
    char *arr = read_str(fin);

    fprintf(fout, "%d ", get_max_len_of_num_seq_parallel(arr));
    fprintf(fout, "%d", get_max_len_of_num_seq(arr, 0, strlen(arr)));
}
