#include <stdlib.h>
#include "merge.h"



static void swap(int * x, int * y)
{
    int tem = *x;
    *x = *y;
    *y = tem;
}


static void sort_two_item(int *a)
{
    if(a[0]<=a[1]) return;
    else swap(a, a+1);
}

void merge(int *a, int *tem, int right, int left)
{
    int i = 0, j = 0, len = right+left;
    for(int k=0;k<len;k++){
        if(a[i] <= a[j+left]){
            tem[k] = a[i];
            ++i;
            if(i == left) {
                ++k;
                while(j<right) {
                    tem[k] = a[j+left];
                    ++j;
                    ++k;
                }
                break;
            }
        }
        else {
            tem[k] = a[left+j];
            ++j;
            if(j == right) {
                while(i<left) {
                    tem[k] = a[i];
                    ++i;
                    ++k;
                }
                break;
            }
        }
    }
    for(int k=0;k<len;k++) a[k] = tem[k];
    return;
}

static void sort(int * a, int *tem, int length)
{
    if(length == 2) sort_two_item(a);
    else if(length == 1) return;
    else
    {
        int left = length/2;
        int right = length-left;
        sort(a, tem, left);
        sort(a+left, tem+left, right);
        merge(a, tem, right, left);
    } 
    
}


void mergesort(int * a, int length)
{
    int *tem = (int *)malloc(length*sizeof(int));
    sort(a, tem, length);
}