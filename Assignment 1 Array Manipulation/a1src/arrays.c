// files is arrays.c
/* The program in this file computes an average gpa
grade of a student



 Revisions:
 19/9/2021 - Initial version   DN
 */


/*************************************************************************/

/* Include files */
#include "stdio.h"
#include "stdlib.h"



/*************************************************************************/

/* DEFINE */
#define ARR_SIZE  20
#define MIN_GPA   7


/**********************************************************************/

/* PROTOTYPES */

int populateArray(int numbers[], int maxArrSize, int* arrSize);
int removeValues(/*add parameters*/);
int printArray(int numbers[], int arrSize);


/**********************************************************************/




int main(int argc, char* argv[])
{

    int gpa[ARR_SIZE];
    int arrSize;
    int rc;


    // populate the array with numbers
    populateArray(gpa, ARR_SIZE, &arrSize);

    // printf the array
    printf("The courses grades are:\n");
    printArray(gpa, arrSize);

    // compute the average gpa
    //add code
    double sum = 0;

    for (int i = 0; i < arrSize; i++) {
      sum += gpa[i];
    }

    // print the number of courses and the average gpa
    //add code
    printf("The number of course = %i \n", arrSize);
    printf("Average GPA = %0.2f \n", sum/arrSize);

    // remove low grades
    printf("Removing all gpa elements smaller than 7 \n");
    removeValues(gpa, arrSize, 7, arrSize);

    // print remining grades
    printf("the grades with grades >= 7 are:\n");
    printArray(gpa, arrSize);

    // compute the average gpa
    //add code
    sum = 0;

    for (int i = 0; i < arrSize; i++) {
      sum += gpa[i];
    }

    // print the number of courses and the average gpa
    //add code
    printf("The number of course = %i \n", arrSize);
    printf("Average GPA = %0.2f \n", sum/arrSize);

    return(0);



}






/************************************************************************/

/* Purpose: populate the array with random in the given range of numbers until the array is full or the user's input is -1


input:
arr -  array of integers
maxArrSize - the numbers of elements in the array

output:
arr - the modified array
arrSize - the number of elements in the array after the array was populated

Assumptions:
the user is a friendly user - there is no need to check input or clear the buffer
*/
int populateArray(int arr[], int maxArrSize, int *arrSize)
{
    // initialize counter for array position and the value we will add
    int counter = 0;
    int valueToAdd = -1;

    // get input from user and update valueToAdd
    while (scanf("%i", &valueToAdd)) {
      // check if value is -1 or array full
      if (valueToAdd == -1 || counter == maxArrSize) {
        break;
      }
      // printf("%i", counter);

      // update array and increase counter
      arr[counter] = valueToAdd;
      counter += 1;
      // arrSize = &counter;

    }

    *arrSize = counter;



    // for (int i = 0; i < counter; i++) {
    //   printf("%i ", arr[i]);
    // }
    //
    // printf("\n");

    return(0);
}




/************************************************************************/

/*
Purpose: remove all number that are smaller than the given min value.
For example if minValue is 5 then all number in the array that are smaller than 5 are
to be removed from the array and the array size needs to be adjusted.

input:


output:

return
0

*/


int removeValues(int arr[], int *arrSize, int min, int actualArrSize)
{
    // set local size variable for easy updates
    int size = actualArrSize;
    int counter = 0;
    int tmpCounter = 0;

    //
    for (int i = 0; i < size; i++) {
      if (arr[i] >= min) {
        counter += 1;
      }
    }

    int returnArr[counter];

    for (int i = 0; i < size; i++) {
      if (arr[i] >= min) {
        returnArr[tmpCounter] = arr[i];
        tmpCounter += 1;
      }
    }

    *arr = *returnArr;

    // *arrSize = size;

    return(0);
}





/************************************************************************/

/*
Purpose: prints the array.  All grades should appear in one row.


input:
arr - the array of integers
arrSize - the numbers of elements in the array


return
0
*/


int printArray(int arr[], int arrSize)
{

    //add code
    for (int i = 0; i < arrSize; i++) {
      printf("%i ", arr[i]);
    }

    printf("\n");

    return(0);

}
