#include <stdint.h>
#include <stddef.h>

void ins_sort(int32_t *in, size_t in_size)
{
    int32_t key;
    int i;

    if( (in != NULL) && (in_size > 1) )
    {
        for(int j = 1; j < in_size; j++)
        {
            key = in[j];
            for(i = j - 1; i >= 0; i--)
            {
                if(in[i] <= key)
                {
                    break;
                }
                else
                {
                    in[i+1] = in[i];
                }
            }
            in[i+1] = key;
        }
    }
}

