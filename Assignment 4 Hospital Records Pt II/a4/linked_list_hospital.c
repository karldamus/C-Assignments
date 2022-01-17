
/*
File name is linked_list_hospital.c
 Purpose: file contains functions for manipulating singly linked list

 Revisions
 Doron Nussbaum 2021
 Karl Damus 2021

 Copyright 2021 Doron Nussbaum
 */

/******************************************************************/
// INCLUDE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list_hospital.h"
#include "patient.h"

/************************************************************************/
// Define

/************************************************************************/

/*
Purpose: compare two PatientInfo structs

input:
  patient1
  patient2

return
  0 if equal
  1 if not equal
*/
/*
int comparePatients(PatientInfo* p1, PatientInfo* p2) {
  if (
    p1->id == p2->id &&
    p1->arrivalTime == p2->arrivalTime &&
    p1->priorityLevel == p2->priorityLevel &&
    p1->medicalProblem == p2->medicalProblem &&
    p1->firstName == p2->firstName &&
    p1->familyName == p2->familyName
  ) { return 0 }

  return 1
}
*/ // method!

/*
Purpose: insert a new node into the list as the first element

input
patient - the patient record

input/output
head - head of linked list

return
A pointer to the node that was allocated.

NULL - if the operation was not successful
*/
ListNode * insertToList(ListNode **head, PatientInfo *patient) {
  // initialize node
	ListNode *p = NULL;

  // allocate memory
  p = (ListNode *) malloc(sizeof(ListNode));

  if (p == NULL)
    return NULL;

  // set data
  p->patient = *patient;

  // make new node point to current head
  p->next = *head;

  // update head
  *head = p;

  return p;
}

/*
Purpose: insert a new node into the list after the given node

Input
input
patient - the patient record

return
A pointer to the node that was allocated.

NULL - if the operation was not successful
*/
ListNode * insertAfter(ListNode *node, PatientInfo *patient) {
  // initialize node
  ListNode *p = NULL;

  // allocate memory
  p = (ListNode *) malloc(sizeof(ListNode));

  if (p == NULL)
    return NULL;

  // set data
  p->patient = *patient;

  // connect list to new node
  p->next = node->next;
  node->next = p;

  return p;
}

/*
Purpose: search for the first patient with the matching priority
Input
head - the head of the list
priority - first priority of the patient

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty
*/
ListNode * searchFirstPatientByPriority(ListNode *head, unsigned char priority, PatientInfo *patient) {
	 // initialize iterator
	 ListNode *p = NULL;

	 // allocate
	 p = head;
	 if (p == NULL) {
		 return NULL;
	 }

	 // loop through patient list
	 while (p != NULL) {
		 // if priority of p == priority
		 if (p->patient.priorityLevel == priority) {
			 *patient = p->patient;
			 return p;
		 }
		 p = p->next;
	 }

	 return NULL;
}

/*
Purpose: search for the first patient with the matching criteria.  The criteria is determined
by the comparison function
Input
head - the head of the list
findPatient -  a function pointer that returns a 0 if the patient's record matches that criteria

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty
*/
ListNode * searchNextPatient(ListNode *head, int (*findPatient)(PatientInfo *), PatientInfo *patient) {

}

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
patient - the patient record

return
0 if node was deleted
1 if node was not deleted or list is empty
*/
int deleteFromList(ListNode **head, PatientInfo *patient) {
	ListNode *temp = *head, *prev;

	if (temp != NULL && (comparePatients(&temp->patient, patient, 0) == 0)) {
		head = &temp->next;
		free(temp);
		return 1;
	}

	while (temp != NULL && (comparePatients(&temp->patient, patient, 0) != 0)) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		return 1;
	}

	prev->next = temp->next;

	free(temp);
}

/*
Purpose: Retrieve the first node that matches the priority.  When found the node is deleted and the patient
information is provided.

Input
head - the head of the list

output
head - the head of the list
patient - the patient record

return
0 if node was deleted
1 if node was not found or list is empty
*/
int retrieveNextPatientByPriority(ListNode **head, unsigned char priority, PatientInfo *patient) {
	// initialize iterator
	ListNode *p = NULL;
	// ListNode *prev = NULL;

	// allocate
	p = *head;
	// prev = *head;
	if (p == NULL) {
		return 1;
	}

	// loop through patient list
	while (p != NULL) {
		// if priority of p == priority
		if (p->patient.priorityLevel == priority) {
			*patient = p->patient;
			deleteFromList(head, patient);
			return 0;
		}
		p = p->next;
	}

	return 1;
}

/*
Purpose: Retrieve the patient with the highest criteria to be treated.  The maximum criteria is determined by
a comparePatients function.  Once the patient is found it is deleted from the list and its information is
returned.

Input
head - the head of the list
comparePatients - this function takes two paitent records and compares them.
				It returns, -1, 0 or 1 if p1 < p2, p1 == p2, or p1 > p2, respectively.

output
head - the head of the list
patient - the patient record

return
0 if  patient was found and the node was deleted
1 if no paitent was found or the list is empty

Algorithm:
The function first finds the patient with the hights criteria by comparing all the patients records and
finding the first patient with the maximum criteria to be treated.  It then deletes the patient and returns
its information.
*/
int retrieveNextPatientByCriteria(ListNode **head, int (*comparePatients)(PatientInfo *p1, PatientInfo *p2, int currentTime), int currentTime, PatientInfo *patient) {
	// initialize iterator
	ListNode *p = NULL;
	// ListNode *prev = NULL;

	// allocate
	p = *head;
	// prev = head;
	if (p == NULL) {
		return 1;
	}

	// loop through patient list
	while (p != NULL) {
		// if priority of p == priority
		if (comparePatients(patient, &p->patient, currentTime) < 0) {
			*patient = p->patient;
		}
		p = p->next;
	}

	deleteFromList(head, patient);

	return 0;

}

/*
Purpose: deletes all nodes from the list

input/output
head - the head of the list
*/
void deleteList(ListNode **head) {

}

/*
Purpose: prints all the records in the list

input
head - the head of the list
myPrint - a function pointer for print the patient information.
*/
void printList(ListNode *head, void (*myPrint)(PatientInfo *patient)) {
  // initialize iterator
	ListNode *p = NULL;

  // allocate memory
  p = head;

  if (p == NULL)
    return;

  while (p != NULL) {
    printPatient(&p->patient);
    p = p->next;
  }
}

/*
Purpose: counts the number of patients that are waiting to be treted
input
head - the head of the list

return
the number of registered patients
*/
int numPatientsInEmergency(ListNode *head) {
  int count = 0;

  // initialize node
	ListNode *p = NULL;

  // allocate memory
  p = head;

  if (p == NULL)
    return -1;

	// increase count for every patient
  while (p != NULL) {
    count += 1;
    p = p->next;
  }

	return count;
}

/*
Purpose: counts the number of patients with a matching priority
input
head - the head of the list

return
the number of patients with a matching priority
*/
int countPatients(ListNode *head, unsigned char priority) {
  int count = 0;

  // initialize node
	ListNode *p = NULL;

  // allocate memory
  p = head;

  if (p == NULL)
    return -1;

  while (p != NULL) {
    if (p->patient.priorityLevel == priority)
      count += 1;
    p = p->next;
  }

  return count;
}

/*
Purpose: store all the patients records in the file by printing out the information i.e., in ASCII readable format.

input
filename - the name of the file to be used for storing the data
head - the head of the  list

Algorithm:
use the '$' character as a delimeter between the fields
For example:
Miya                 $Bronson                 $ 9700    $ 20  $ 2 $ Broken Bone
*/
int createAsciiBackup(char *fileName, ListNode *head) {
	// add code

	// open the file
	FILE *fp = fopen(fileName, "w");

	// store each patient records in the file
	ListNode *p = NULL;

	p = head;
	if (p == NULL) {
		return 1;
	}

	while (p != NULL) {
		PatientInfo pi = p->patient;
		fprintf(fp, "%-10s $ %-10s $ %-6i $ %-4i $ %-4d $ %s \n",
								pi.firstName, pi.familyName, pi.id, pi.arrivalTime, pi.priorityLevel, pi.medicalProblem);
	 	p = p->next;
	}

	// close the file
	fclose(fp);

    return(0);
}

/*
Purpose: store all the patients records in the file in their binary format.

input
filename - the name of the file to be used for storing the data
head - the head of the  list
*/
int createBinaryBackup(char *fileName, ListNode *head) {
	ListNode *p = head;
	FILE *fp = fopen(fileName, "wb");

	while (p != NULL) {
		PatientInfo pi = p->patient;
		fwrite(pi.firstName, sizeof(char), NAME_LENGTH + 1, fp);
		fwrite(pi.familyName, sizeof(char), NAME_LENGTH + 1, fp);
    fwrite(&pi.id, sizeof(int), 1, fp);
		fwrite(&pi.arrivalTime, sizeof(int), 1, fp);
		fwrite(&pi.priorityLevel, sizeof(char), 1, fp);
		fwrite(pi.medicalProblem, sizeof(char), PROBLEM_LENGTH + 1, fp);
		if (p->next != NULL) {
			fprintf(fp, "\n");
		}
    p = p->next;
	}

	fclose(fp);

  return(0);
}


// BONUS SECTION

/*
Purpose: removes all Patients with priority less than or equal to the given priority
(remove all patients with priorityLevel <= priority).

input
head - the head of the  list

Ouput
head - the head of the list where all patients with priorityLevel < priority are removed
*/
int releasePatients(ListNode **head, unsigned char priority) {
	// add code

	// remove all patients that head is pointing to and meet the criteria


	// remove all other patients that meet the crieria
	return(0);
}

/*
Purpose: prints all the patients' records in the list in reverse order using recursion

input
head - the head of the list
*/
void printListReverse(ListNode *head, void (*myPrint)(PatientInfo *patient)) {
	if (head == NULL) {
		return;
	}
	printListReverse(head->next, printPatient);

	printPatient(&head->patient);
}

/*
Purpose: Reverse the list such that the last node in the list becomes the first node and the first node in the list becomes the last node.

Restrictions:
1.	This operation must be achieved using recursive calls
2.	No memory is to be allocated or released at any time during the execution of the function

input
head - the head of the list

Returns:
the head of the new list
*/
ListNode *reverse(ListNode *head) {
	if(head == NULL) {
		return NULL;
	}

   if (head->next == NULL) {
	 		return head;
	}

   ListNode *newList = reverse(head->next);

	 // make new head, and make link null
   head->next->next = head;
   head->next = NULL;

   return newList;
}
