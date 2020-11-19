
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Procedure:
 * countSort
 * 
 * Parameters
 * input, an integer array
 * length, the length of input
 * radix, an integer that is some positive integer power of 10
 * 
 * Purpose
 * For a given digit such that digit = Log(radix) (where Log is base 10)
 * sort the input in ascending order based on that digit 
 * 
 * Produces
 * Alters input such that it is in ascending order based a given digit
 * 
 * Preconditions
 * input's length > 0 and all values are nonegative integers
 * Log(radix) yields a positive integer
 * 
 * Postconditions
 * i = Log(radix), a digit 
 * input = (input sorted in ascending order according to each values i_th digit)
 * For values with same digit, their ordering will be preserved.
*/
void countSort(int input[], int length, int radix){
    
    if(length == 0){
        perror("Length of Array is 0. Why call this?");
        exit(0);
    }

    typedef struct Node{
        int value; //integer from input
        struct Node * next;
    }node_t;
    
    //holds all input values with the same digit for a given radix
    typedef struct {
        node_t * valueList;
        node_t * end;
        int count;
        int digit;
    }digit_t;

    int summationArray[10];
    digit_t * workingArray[10];

    //initialize digit_t * pointers and corresponding structs
    for(int i = 0; i < 10; i++){
        workingArray[i] = malloc(sizeof(digit_t));
        workingArray[i]->valueList = NULL;
        workingArray[i]->end = NULL;
        workingArray[i]->count = 0;
        workingArray[i]->digit = i;
        
    }

    //Adds values to workingArray based on digit being looked at
    int currentVal;
    for(int i = 0; i < length; i++){
        //Determines the digit of the value and gets corresponding digit_t
        currentVal = input[i];
        printf("Current Val: %d", currentVal);
        int currentDigit = (currentVal % radix)/(radix/10);
        printf("Current Digit: %d\n", currentDigit);
        digit_t * currentWorkingDigit = workingArray[currentDigit];
        currentWorkingDigit->count++;
        //initialize the new node_t for the value
        node_t * newNode = malloc(sizeof(node_t));
        newNode->next = NULL;
        newNode->value = currentVal;
        //Adds new node_t to valueList of digit_t
        if(currentWorkingDigit->valueList == NULL){
            currentWorkingDigit->valueList = newNode;
            currentWorkingDigit->end = newNode;
        }
        else{
            currentWorkingDigit->end->next = newNode;
            currentWorkingDigit->end = newNode;
        }
    }

    //Determines, for each digit, how many items come before it with respect to digit order
    summationArray[0] = 0;  //initializes the first element of summationArray for use in loop
    for(int i = 1; i < 10; i++){
        summationArray[i] = workingArray[i-1]->count + summationArray[i-1];
    }

    //Inserts elements into list in sorted order
    for(int i = 0; i < 10; i++){
        int currentIndex = summationArray[i];
        node_t * currentNode = workingArray[i]->valueList;
        //loops through and inserts elements with same digit
        while(currentNode != NULL){
            input[currentIndex] = currentNode->value;
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
    printf("Radix %d\n", radix);
    printArray(input, length);

    //Frees malloced memory
    for(int i = 0; i < 10; i++){
        free(workingArray[i]);
    }




}

/**
 * Procedure
 * printArray
 * 
 * Parameters
 * input, an integer array.
 * length, the length of input
 * 
 * Purpose
 * Print out the contents of input
 * 
 * Produces
 * A text printout of input
 * 
 * Preconditions
 * input is an integer array
 * length = the length of input
 * 
 * Postconditions
 * [input[i], ..., input[length-1],]
*/
void printArray(int input[], int length){
    printf("[");
    for(int i = 0; i < length; i++){
        printf("%d,", input[i]);
    }
    printf("]\n");
}

/**
 * Procedure
 * radixsort
 * 
 * Parameters
 * input, an integer array
 * length, the integer length of input
 * 
 * Purpose
 * Sort input using Radix Sort
 * 
 * Produces
 * An array of integer elements in ascending order
 * 
 * Preconditions
 * length = length of input
 * length > 0, otherwise findMax will error
 * input's values are nonegative integers
 * 
 * Postconditions
 * For 1 <= 1 <= length - 1
 *  input[i] >= input[i-1]
 * 
 * if input[a] == input[b] where a < b
 *  then input[a] relocates to input[i] and 
 *  input[b] relocates to input[i+1] for some i -- stable sort 
*/
void radixsort(int input[], int length){
    int maxValue = findMax(input, length); //finds max value of input

    //Determines the number of digits from the maximum value
    int looking = 1; 
    int base = 1; 
    int maxDigit = 1;
    while(looking){
        if(maxValue/base  < 10){
            looking = 0;
        }
        else{
            base*=10; //since dealing with base-10 numbers, each digit increase is a multiplication by 10
            maxDigit++;
        }
    }

    //Performs the radix sort
    for(int i = 1; i < maxDigit+1; i++){
        int radix = pow(10, i);
        countSort(input, length, radix);
    }
    
}

/**
 * Procedure
 * findMax
 * 
 * Parameters
 * input, an integer array
 * length, the integer length of input
 * 
 * Purpose
 * returns the largest value of input
 * 
 * Produces
 * the largest value of input
 * 
 * Preconditions
 * length = length of input array
 * length > 0
 * 
 * Postconditions
 * let maxVal be returned value
 * 
 * for each value of input
 *  maxValue >= value
*/

int findMax(int input[], int length){
    if(length == 0){
        perror("Length of Array is 0");
        exit(0);
    }
    int currentMax = input[0];
    for(int i = 1; i < length; i++){
        if(input[i] > currentMax){
            currentMax = input[i];
        }
    }

    return currentMax;
}


