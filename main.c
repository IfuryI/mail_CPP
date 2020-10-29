#include <stdio.h>
#include "include/proccesing.h"


int main()
{
    FILE *fin = fopen("test.txt", "r");
    proccesing(fin, stdout);
    fclose(fin);
    return 0;
}
