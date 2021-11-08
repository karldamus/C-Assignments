#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "ctype.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20

// pre-def MENU methods
// used by user

int menu();
void sizeOfStructures();
void quit();

// ===============

int main(int argc, char *argv[]) {
    // initialization
    struct person *person = NULL;
    int numRecords = 0;         // number of records to be created
	  char rc = 0;
    int i;

    /*
      Get number of records to create from user argument.
      Warn user if input is not valid or missing.
    */
    if (argc != 2 || !isdigit(*argv[1])) {
      printf("You must provide a single integer as a second argument for the number of records you would like to create. \n");
      return (0);
    } else {
      numRecords = atoi(argv[1]);
      if (numRecords > 2400) {
        printf("ERROR: You cannot create that many records.\n");
        return(0);
      }
    }

    // allocate memory for number of records
    person = (struct person *) malloc(numRecords * sizeof(struct person));

    // check to make sure memory is allocated properly
    if (person == NULL) {
      printf("error: could not allocate memory for the array \n");
      return(1);
    }

    // initialize each of the elements to NULL
    for (i = 0; i < numRecords; i++) {
      person = NULL;
      person++;
    }

    // create a person element by allocating new memory
    for (i = 0; i < numRecords; i++) {
      person = malloc(sizeof(struct person *));
      person++;
    }

    // populate all records
    populateRecords(person, numRecords);

    printf("\nSuccessfully created %i records.\n", numRecords);

    int menuLoop = 1;

    // continue showing menu
    // until quit is called
    // or program is force closed
    while (menuLoop == 1) {
      // display menu and receive input from user
      int menuOption = menu();

      // determine what to do with given input
      switch(menuOption) {
        case 1: printAllEmployees(person, numRecords); break;
        case 2: employeeData(person, numRecords); break;
        case 3: searchPatients(person, numRecords); break;
        case 4: printPatientSummary(person, numRecords); break;
        case 5: sizeOfStructures(person, numRecords); break;
        case 0: quit();
        default:
          printf("\033[31m");
          printf("\nYou must enter a valid integer from 0-5.\n");
          printf("\033[0m");
      }
    }

    return 0;
}

/**
  Command line style menu for user.

  I/O:
    Input: an integer corresponding to a menu menuOption
    Output: See output from associated methods

  Returns: value of user input
*/
int menu() {
  // display all menu functions
  printf("\n");
    printf("\033[1m"); // brighter
  printf("MENU:\n");
  printf("----------------------------------------------\n");
    printf("\033[32m"); // green
  printf("1. Print All Employees \n");
  printf("2. Summary of Employees Data \n");
    printf("\033[36m"); // cyan
  printf("3. Search for all Patients by Family Name \n");
  printf("4. Summary of Patients Data \n");
    printf("\033[33m"); // yellow
  printf("5. Size of Structures (PersonRec, PatientRec, and EmployeeRec) \n");
    printf("\033[31m"); // red
  printf("0. Quit \n");
    printf("\033[0;1m"); // brighter
  printf("----------------------------------------------\n");
    printf("\033[0m"); // default
  int input;

  printf("Enter your input: ");
  // request input from user
  scanf(" %i", &input);
  getchar();

  return input;
}

/**
  Display the size of structures:
    - PersonRec
    - EmployeeRec
    - PatientRec
*/
void sizeOfStructures() {
  printf("\n\033[33;1mSize of Structures:\033[0m \n");
  printf("Size of PersonRec = %li \n", sizeof(struct person));
  printf("Size of EmployeeRec = %li \n", sizeof(struct employee));
  printf("Size of PatientRec = %li \n", sizeof(struct patient));
}

/**
  Receive input to confirm if user wants to exit.

  I/O:
    Input: char: 'y' or 'n'
    Output: ending (or error) message

  Returns: ends program or nothing
*/
void quit() {
  char confirm;
  char yes = 'y';
  char no = 'n';

  printf("\nYou are about to quit, are you sure? (y/n): ");

  // get input
  scanf(" %c", &confirm);
  getchar();

  // check input
  if (confirm == yes) {
    printf("\nBye for now :)\n");
    exit(0);
  } else if (confirm == no) {
    printf("\nOkay, stick around a little longer :)\n");
  } else {
    printf("\nSorry that is not a valid answer.\n");
    quit();
  }
}
