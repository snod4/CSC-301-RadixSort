/* Academic Honesty Certification
* Written sources used: Introduction to Algorithms
* (Include textbook(s), complete citations for web or other written sources.
* Note that you are not allowed to use the web for this assignment.
* Write "none" if no sources used.)
* 
*
*
* Help obtained:
* (Include names of anyone other than the instructor.)
* None
*
*
* My written or typed signature below confirms that the above list * of sources is complete. 
* Signature: Chase Snodgrass
*/


#include "./radixsort.h"




int main(){
    
    int testCase1[] = {0,0,0,0,0,0,214748364,0}; //test numbers with a lot of digits
    int testCase2[] = {10,0,8,7,6,5,4,3,2,1,0}; //Test descending list
    int testCase3[] = {111,1,11,1111,1111111,1111,1}; //Test case where are values contain only one digit type
    int testCase4[] = {0,1,2,3,4,5,6,7,8,9,10}; //Test ascending order list
    int testCase5[] = {234,151,161,207,397,980,999,120,678,298}; //Test case where all values have same number of digits


    printf("Testing one entry with large number of digits\n");
    printf("Oringal Array: ");
    printArray(testCase1, sizeof(testCase1)/sizeof(testCase1[0]));
    printf("Array after radixsort: ");
    radixsort(testCase1, sizeof(testCase1)/sizeof(testCase1[0]));
    printArray(testCase1, sizeof(testCase1)/sizeof(testCase1[0]));
    printf("\n");

    
    printf("Testing Array Sorted in ascending order\n");
    printf("Oringal Array: ");
    printArray(testCase2, sizeof(testCase2)/sizeof(testCase2[0]));
    printf("Array after radixsort: ");
    radixsort(testCase2, sizeof(testCase2)/sizeof(testCase2[0]));
    printArray(testCase2, sizeof(testCase2)/sizeof(testCase2[0]));
    printf("\n");


    printf("Testing numbers with all the same digits\n");
    printf("Oringal Array: ");
    printArray(testCase3, sizeof(testCase3)/sizeof(testCase3[0]));
    printf("Array after radixsort: ");
    radixsort(testCase3, sizeof(testCase3)/sizeof(testCase3[0]));
    printArray(testCase3, sizeof(testCase3)/sizeof(testCase3[0]));
    printf("\n");


    printf("Testing list in ascending order\n");
    printf("Oringal Array: ");
    printArray(testCase4, sizeof(testCase4)/sizeof(testCase4[0]));
    printf("Array after radixsort: ");
    radixsort(testCase4, sizeof(testCase4)/sizeof(testCase4[0]));
    printArray(testCase4, sizeof(testCase4)/sizeof(testCase4[0]));        
    printf("\n");

    printf("Testing list where all values have same number of digits\n");
    printf("Oringal Array: ");
    printArray(testCase5, sizeof(testCase5)/sizeof(testCase5[0]));
    printf("Array after radixsort: ");
    radixsort(testCase5, sizeof(testCase5)/sizeof(testCase5[0]));
    printArray(testCase5, sizeof(testCase5)/sizeof(testCase5[0]));        
    printf("\n");


    return 0;
}