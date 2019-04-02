#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include "quick.h"



int main() {
    int a[] = {2,1,4,9,0,3,5,8,7,6};
    for(int i=0;i<10;i++) printf("a[%d] = %d\n", i, a[i]);
    quicksort(a, 10);
    for(int i=0;i<10;i++) printf("a[%d] = %d\n", i, a[i]);
    return 0;
}
