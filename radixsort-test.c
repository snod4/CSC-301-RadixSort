#include "./radixsort.h"


int main(){
    
    int length = 10;
    int input[length];
    for(int i = 0; i < length; i++){
        input[i] = random()%10000;
    }
    printf("Initial List: ");
    printArray(input, length);
    radixsort(input, length);
    printf("Sorted Array: ");
    printArray(input, length);
    return 0;
}