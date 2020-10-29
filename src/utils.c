#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "../include/utils.h"
#include "../include/error_codes.h"


int divide_arr(CArr_t arr, int size, TArgs_t *seg_arr, int max_th)
{
    int flag = 0;
    int th_count = 0;

    int th_elem_count = size / max_th;
    int A1 = 0;
    int B1 = th_elem_count;

    for (int i = 1; flag == 0 && i <= max_th; i++)
    {
        seg_arr[i - 1].th_num = i - 1;
        seg_arr[i - 1].start = A1;
        seg_arr[i - 1].end = B1;
        seg_arr[i - 1].arr = arr;

        for (int j = seg_arr[i - 1].end; isdigit(arr[seg_arr[i - 1].end - 1]) && j < size; j++)
        {
            seg_arr[i - 1].end += 1;
        }

        if (seg_arr[i - 1].end == size)
        {
            flag = 1;
        }

        A1 = seg_arr[i - 1].end;
        B1 = seg_arr[i - 1].end + th_elem_count;

        if (B1 > size)
        {
            B1 = size;
        }

        th_count++;
    }

    return th_count;
}

int get_file_size(FILE *fin)
{
    fseek(fin,0,SEEK_END);

    int file_size = ftell (fin);

    fseek(fin, 0, SEEK_SET);

    return file_size;
}

int read_file(FILE *fin, char *buf, int file_size)
{
    if (buf == NULL)
    {
        return ERROR;
    }

    size_t result = fread(buf, 1, file_size, fin);

    if (result != file_size)
    {
        return ERROR;
    }

    buf[strlen(buf)] = '\0';

    return result;
}

int delete_n(char *str)
{
    int n_count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '\n')
        {
            n_count++;
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
        }
    }

    char *buf = (char *) realloc(str, strlen(str) - n_count);

    if (buf == NULL)
    {
        return ERROR;
    }

    str = buf;

    return n_count;
}

char *read_str(FILE *fin)
{
    if (fin == NULL)
    {
        return "";
    }

    int file_size = get_file_size(fin);

    if (file_size == 0)
    {
        return "";
    }

    char *str = (char*) malloc((sizeof(char) * file_size) + 1);

    if (str == NULL || read_file(fin, str, file_size) == ERROR)
    {
        return "";
    }

    if (delete_n(str) == ERROR)
    {
        return "";
    }

    return str;
}
