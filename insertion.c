#include "insertion.h"

static void swap(int *x, int *y){
    int tem = *x;
    *x = *y;
    *y = tem;
}

void insertion_sort(int * a, int length) {
    for(int i=0;i<length;) {
        while(a[i]<=a[i+1] && i<length-1) i++;
        if(i==length-1) break;
        else {
            int posmark = i;
            while(a[i]>a[i+1]) {
                swap(a+i, a+i+1);
                if(i==0) break;
                else i--;
            }
            i = posmark+1;
        }    
    }
}