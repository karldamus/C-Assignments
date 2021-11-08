#include "string.h"
#include "stdio.h"
#include <stdlib.h>
#include "patient.h"

/**
  Print the details of a single patient.

  I/O:
    Input: a single instance of a person struct
      (must be of type PATIENT_TYPE)
    Output: printed details of the patient

  Returns: N/A
*/
void printPatient(PersonRec person) {
    // get full name as one char[]
    char name[34];
    sprintf(name, "%s %s", person.firstName, person.familyName);

    // print patient details
    printf("%-20s Daily Cost: %i.00 Num Days in Hospital: %i Department: %i Severity: %i \n",
            name, person.patient.dailyCost, person.patient.numDaysInHospital,
            person.patient.department, person.patient.severity);
}



/**
  Print all persons where TYPE == PATIENT_TYPE
*/
void printPatients(struct person *person, int numPersons) {
  for (int i = 0; i < numPersons; i++) {
    if (person[i].emplyeeOrPatient == PATIENT_TYPE) {
      printPatient(person[i]);
    }
  }
}


/**
  struct for use by printPatientSummary(. . .)
*/
struct tmpPatientData {
  int numPatients;
  float costToDate;
  float dailyCost;
  // float aveDailyCostPerPatient;
};

void printPatientSummary(PersonRec *person, int numPersons) {
  // create and allocate memory for the tmpPatientData struct
  struct tmpPatientData *tmpPatientData = NULL;
  tmpPatientData = malloc(7 * sizeof(struct tmpPatientData));

  // initialize each value in each position of struct array to 0
  for (int i = 0; i < 7; i++) {
    tmpPatientData[i].numPatients = 0;
    tmpPatientData[i].costToDate = 0;
    tmpPatientData[i].dailyCost = 0;
    // tmpPatientData[i].aveDailyCostPerPatient = 0;
  }

  // fill data for:
  //    - all patients (index 0)
  //    - department specific (index 1 - 6)
  for (int i = 0; i < numPersons; i++) {
    // only persons with PATIENT_TYPE
    if (person[i].emplyeeOrPatient == PATIENT_TYPE) {
      // add to total patients (index 0)
      tmpPatientData[0].numPatients += 1;
      tmpPatientData[0].costToDate += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
      tmpPatientData[0].dailyCost += person[i].patient.dailyCost;

      // add to department specific (index 1 - 6)
      tmpPatientData[person[i].patient.department].numPatients += 1;
      tmpPatientData[person[i].patient.department].costToDate += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
      tmpPatientData[person[i].patient.department].dailyCost += person[i].patient.dailyCost;
    }
  }

  // print all data
  for (int i = 0; i < 7; i++) {
    if (i == 0) {
      printf("\n\033[36mPatient Summary:\033[0m \n");
      // ALL patients format
      printf("\033[1mTotal number of patients:\033[0m %i \033[1mCost to-date:\033[0m %.2f \033[1mAverage Cost per Patient to-date:\033[0m %.2f \n",
              tmpPatientData[0].numPatients, tmpPatientData[0].costToDate, tmpPatientData[0].costToDate / tmpPatientData[0].numPatients);
      printf("\033[36mSummary by Department:\033[0m\n");
    } else {
      printf("\033[1mDepartment [%i] - Patients:\033[0m %i  \033[1mCost to-date:\033[0m %7.2f  \033[1mDaily Cost:\033[0m %6.2f  \033[1mAverage Daily Cost per Patient:\033[0m %5.2f \n",
              i, tmpPatientData[i].numPatients, tmpPatientData[i].costToDate, tmpPatientData[i].dailyCost, tmpPatientData[i].dailyCost / tmpPatientData[i].numPatients);
    }
  }

  free(tmpPatientData);
}



/**
  Method to receive input and call searchPatientsByFamilyName with given input.

  I/O:
    Input:
      - an array of type person's
      - number of persons in array
    Output: see searchPatientsByFamilyName

    Returns: N/A
*/
void searchPatients(struct person *person, int numPersons) {
  char familyName[NAME_SIZE];
  printf("Enter patient's last name: ");
  scanf(" %s", familyName);

  searchPatientsByFamilyName(person, numPersons, familyName);
}

/**
  Given a patient's family name, output the details of that patient.

  I/O:
    - array of type person's
    - number of persons in array
    - family name to find
  Output: printed details of the patient

  Returns: N/A
*/
void searchPatientsByFamilyName(struct person *person, int numPersons, char familyName[]) {
  printf("\n");
  printf("\033[1;36m"); // cyan
  printf("Patients Found:\n");
  printf("\033[0m"); // default
  // loop through all persons
  for (int i = 0; i < numPersons; i++) {
    // if person is a PATIENT_TYPE
    if (person[i].emplyeeOrPatient == PATIENT_TYPE) {
      // if familyName is same as input
      if (strcmp(person[i].familyName, familyName) == 0) {
        // display details
        printPatient(person[i]);
      }
    }
  }
}
