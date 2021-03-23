#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_sort.h"

static int sort(int32_t *in, int p, int r);
static int merge(int32_t *in, int p, int q, int r);

int merge_sort(int32_t *in, size_t in_size)
{
    sort(in, 0, in_size - 1);

    return 0;
}

static int sort(int32_t *in, int p, int r)
{
    int result = 0;
    int q;

    if(p < r)
    {
        q = (r + p) / 2;
        sort(in, p, q);
        sort(in, q + 1, r);
        merge(in, p, q, r);
    }

    return result;
}

/*
 * in[q] - is a part of the first half.
 * in[q+1] - second half's first element.
 * in[r] - last element of the second half.
 */
static int merge(int32_t *in, int p, int q, int r)
{
    int a_size, b_size;
    int32_t *a, *b;
    int i, j, k; // i - index in input array.
                 // j - index in the first half copy.
                 // k - index in the second half copy.

    a_size = q - p + 1;
    b_size = r - q;
    a = malloc(a_size * sizeof(int32_t));
    if(a == NULL) { return 1; }
    memcpy(a, &in[p], a_size * sizeof(int32_t));
    b = malloc(b_size * sizeof(int32_t));
    if(b == NULL) { return 1; }
    memcpy(b, &in[q+1], b_size * sizeof(int32_t));
    i = p;
    j = 0;
    k = 0;
    while(i <= r)
    {
        // [1] - first half is over - take element from the second.
        if(j > (a_size - 1))
        {
            in[i] = b[k];
            k++;
        }
        // [2] - second half is over - take element from the first.
        else if(k > (b_size - 1))
        {
            in[i] = a[j];
            j++;
        }
        // [3] - there are still elements in both halves -
        //       choose the smaller one.
        else
        {
            if(a[j] < b[k])
            {
                in[i] = a[j];
                j++;
            }
            else
            {
                in[i] = b[k];
                k++;
            }
        }
        i++; 
    }
    free(a);
    free(b);

    return 0;
}
