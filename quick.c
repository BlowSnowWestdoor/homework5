#include "quick.h"

#include <stdio.h>



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
static void sort_three_item(int *a)
{
    sort_two_item(a);
    if(a[1] < a[2]) return;
    else if(a[2] < a[1] && a[2] > a[0]) swap(a+1, a+2);
    else if(a[2] < a[0]) 
    {
        swap(a, a+2);
        swap(a+1, a+2);
    }
}

static int * pivot(int *a, int length)
{
    if( length == 3)
    {
        return a;
    }
    int middle = length/2;
    if(a[0] < a[length-1]) {
        if(a[middle] < a[0])
            return a;
        else {
            if(a[middle] < a[length-1])
                return a+middle;
            else return a+length-1;        
        }
    }
    else {
        if(a[length-1]>a[middle])
            return a+length-1;
        else {
            if(a[middle] < a[0])
                return a+middle;
            else return a;      
        }
    }
}


static void sort(int *a, int length) {
    if(length <= 3) {
        switch(length) {
            case 0:break;
            case 1:break;
            case 2:sort_two_item(a);break;
            case 3:sort_three_item(a);break;
            default:break;
        }
        return;
    }
    swap(pivot(a, length), a);
    int i=1, j=length-1, posmark;
    while(i<j) {
        if(a[i] > a[0] && a[j] < a[0]) {
            swap(a+i, a+j);
            ++i;
            --j;
        }   
        else {
            if (a[i]<a[0]) ++i;
            if (a[j]>a[0]) --j;
        } 
    }
    if(i == j)
    {
        if(a[i] < a[0])
        {
            posmark = i;
        }
        else 
        {
            posmark =i-1;
        }
    }
    else
    {
        posmark = j;
    }
    
    swap(a, a+posmark);
    printf("the pivot item is a[%d] = %d\n", posmark, a[posmark]);
    sort(a, posmark);
    sort(a+posmark+1, length-posmark-1);
    
}

void quicksort(int *a, int length) {
    sort(a, length);
}