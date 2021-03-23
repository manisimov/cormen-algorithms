#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ins_sort.h"
#include "merge_sort.h"

#define AR_SIZE(ar) ( sizeof(ar)/sizeof(ar[0]) )

int32_t orig_array[] = {1, 6, 4, 2, 8, 13, 9, 15, 3, 56, -3};
int32_t array[AR_SIZE(orig_array)];

int main()
{
    printf("Input :\n");
    for(int i = 0; i < AR_SIZE(orig_array); i++)
    {
        printf("%d ", orig_array[i]);
    }
    printf("\n");
    //
    // Insertion sort.
    //
    memcpy(array, orig_array, sizeof(orig_array));
    ins_sort(array, AR_SIZE(array));
    printf("Insertion. Sorted :\n");
    for(int i = 0; i < AR_SIZE(array); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    //
    // Merge sort.
    //
    memcpy(array, orig_array, sizeof(orig_array));
    merge_sort(array, AR_SIZE(array));
    printf("Merge. Sorted :\n");
    for(int i = 0; i < AR_SIZE(array); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
