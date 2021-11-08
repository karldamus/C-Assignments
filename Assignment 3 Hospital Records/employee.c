#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "employee.h"
#include "stdio.h"
#include "struct.h"

/**
  Print all persons where TYPE == EMPLOYEE_TYPE
*/
void printAllEmployees(struct person *person, int numPersons) {
  printf("\033[32;1m"); // green
  printf("\nHospital Employees:\n");
  printf("\033[0m"); // default
  for (int i = 0; i < numPersons; i++) {
    if (person[i].emplyeeOrPatient == EMPLOYEE_TYPE) {
      printSingleEmployee(person[i]);
    }
  }
}

/**
  Print the details of a single employee.

  I/O:
    Input: a single instance of a person struct
      (must be of type EMPLOYEE_TYPE)
    Output: printed details of the employee

  Returns: N/A
*/
void printSingleEmployee(struct person person) {
  char name[34];
  sprintf(name, "%s %s", person.firstName, person.familyName);

  float salaryToDate = person.emp.salary * person.emp.yearsService;

  // printf("\033[47;30m"); // white background black text
  printf("\033[1m%-20s dept:\033[0m %d \033[1m salary:\033[0m %9.2f \033[1m position:\033[0m %i \033[1m years of service:\033[0m %2d \033[1m salary to-date:\033[0m %11.2f\n",
        name, person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService, salaryToDate);
  printf("\033[0m"); // default
}

/**
  struct for use by employeData(. . .)
*/
struct tmpEmployeeData {
  float totalSalary;
  int numEmployees;
};

/**
  Display summary of employee data including:
    - number of employees
    - total salary
    - average salary
    - sumarry of employees by position

  I/O:
    Input:
      - array of persons
      - number of persons in array
    Output: details of employees, all and position specific

    Returns: N/A
*/
void employeeData(struct person *person, int numPersons) {
  // create and allocate memory for tmp employee data struct
  struct tmpEmployeeData *tmpEmployeeData = NULL;
  tmpEmployeeData = malloc(5 * sizeof(struct tmpEmployeeData));

  // initialize each value in each position of struct array to 0
  for (int i = 0; i < 5; i++) {
    tmpEmployeeData[i].totalSalary = 0;
    tmpEmployeeData[i].numEmployees = 0;
  }

  // fill totalSalary and numEmployees for:
  //    - all employees (index 0)
  //    - position specific (index 1 - 4)
  for (int i = 0; i < numPersons; i++) {
    // only persons with EMPLOYEE_TYPE
    if (person[i].emplyeeOrPatient == EMPLOYEE_TYPE) {
      // add to total employees (index 0)
      tmpEmployeeData[0].totalSalary += person[i].emp.salary;
      tmpEmployeeData[0].numEmployees += 1;

      // add to position specific (index 1 - 4)
      tmpEmployeeData[person[i].emp.position + 1].totalSalary += person[i].emp.salary;
      tmpEmployeeData[person[i].emp.position + 1].numEmployees += 1;
    }
  }

  // print all data
  for (int i = 0; i < 5; i++) {
    if (i == 0) {
      printf("\033[32;1m"); // green
      printf("\nEmployee Summary:\n");
      printf("\033[0m"); // default
      // different output format for ALL employees
      printf("\033[1mTotal number of employees:\033[0m %i \033[1mTotal salary:\033[0m %.2f \033[1mAverage salary:\033[0m %.2f \n",
              tmpEmployeeData[i].numEmployees, tmpEmployeeData[i].totalSalary, tmpEmployeeData[i].totalSalary / tmpEmployeeData[i].numEmployees);

      // employee summary will only occur once so print next "intro sentence"
      printf("\033[32;1m"); // green
      printf("\nSummary by Position:\n");
      printf("\033[0m"); // default
    } else {
      // position specific output format
      printf("\033[1mPosition[%i] - employees:\033[0m %i \033[1mTotal salary:\033[0m %.2f \033[1mAverage salary:\033[0m %.2f \n",
              i-1, tmpEmployeeData[i].numEmployees, tmpEmployeeData[i].totalSalary, tmpEmployeeData[i].totalSalary / tmpEmployeeData[i].numEmployees);
    }
  }

  free(tmpEmployeeData);
}
