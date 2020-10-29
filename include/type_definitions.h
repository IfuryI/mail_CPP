#ifndef MAIN_CPP_TYPE_DEFINITIONS_H
#define MAIN_CPP_TYPE_DEFINITIONS_H


extern int max_len_arr[100];

typedef int* IArr_t;
typedef char* CArr_t;

typedef struct TArgs_t
{
    int th_num;
    int start;
    int end;
    CArr_t arr;

} TArgs_t;


#endif //MAIN_CPP_TYPE_DEFINITIONS_H
