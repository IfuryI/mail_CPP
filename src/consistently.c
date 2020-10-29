#include <ctype.h>
#include "../include/consistently.h"


int get_max_len_of_num_seq(const CArr_t buf, int begin, int end)
{
    int cur_length = 0;
    int max_length = 0;

    for (int i = begin; buf[i] != '\0' && i < end; i++)
    {
        if (!(isdigit(buf[i])))
        {
            cur_length = 0;
        }
        else
        {
            cur_length++;

            if (cur_length > max_length)
            {
                max_length = cur_length;
            }
        }
    }

    return max_length;
}
