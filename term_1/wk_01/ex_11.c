#include <stdio.h>

int main(){
    // process cmd args (NAIVE):
    int array[300];
    for (int i=0; i<502; i++){
       array[i] = i%5;
//       printf("i= %d array[i] = %d\n", i, array[i]);
    }
    return 0;
}
