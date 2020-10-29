#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include "../include/parallel.h"
#include "../include/consistently.h"
#include "../include/utils.h"


int max_len_arr[100] = { 0 };

void parallel_hanlder(void *args)
{
    TArgs_t *th_args = (TArgs_t *) args;

    int th_num = th_args->th_num;
    int start = th_args->start;
    int end = th_args->end;
    CArr_t arr = th_args->arr;

    max_len_arr[th_num] = get_max_len_of_num_seq(arr, start, end);
}


int get_max_len_of_num_seq_parallel(char *arr)
{
    pthread_t threads[100] = { 0 };

    TArgs_t seg_arr[100] = { 0 };

    int th_count = divide_arr(arr, strlen(arr), &seg_arr, strlen(arr));

    for (int i = 0; i < th_count; i++)
    {
        pthread_create(&threads[i], NULL, (void *(*)(void *)) parallel_hanlder, (void*)&seg_arr[i]);
    }

    for (int i = 0; i < th_count; i++)
    {
        pthread_join(threads[i], NULL);
    }

    int maxs = 0;

    for (int i = 0; i < th_count; i++)
    {
        if (max_len_arr[i] > maxs)
        {
            maxs = max_len_arr[i];
        }
    }

    return maxs;
}

