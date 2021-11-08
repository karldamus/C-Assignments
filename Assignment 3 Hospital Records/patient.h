// file is patient.h

#ifndef PATIENT_HEADER
#define PATIENT_HEADER


// include files
#include "struct.h"

/******************************************************/
// function prototypes

void printPatient(PersonRec person);
void printPatients(PersonRec *person, int numPersons);
void printPatientSummary(PersonRec *person, int numPersons);
void searchPatients(PersonRec *person, int numPersons);
void searchPatientsByFamilyName(struct person *person, int numPersons, char familyName[]);
void printPatientSummary(PersonRec *person, int numPersons);


#endif
