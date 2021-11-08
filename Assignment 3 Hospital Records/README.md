DATE: November 1-5 2021

DEVELOPER: Karl Damus
DEVELOPER: Doron Nussbaum


PURPOSE:
  Program to manipulate records of patients and employees in a hospital.
  Administrators can query the data to obtain some summary information.


INITIALIZATION:
  The data of patients and employees is initialized
      using the function populateRecords().
  The data is stored in an array, and the size of the array is given
      based on the second argument from the administrator executing the program.


COMPILING and RUNNING:
  Compile the following files all together:
    - hospital.c
    - patient.c
    - employee.c
    - populateRecords.c
  into a program called hospital

  Example: `gcc -o hospital hospital.c patient.c employee.c populateRecords.c`

  Run the program by entering the name of the program followed by the number
      of records you would like to create.

  Example: `./hospital 20`


ISSUES/LIMITATIONS:
  The number of records you can create is limited to approximately 2400.


USE OF SOFTWARE INSTRUCTIONS:
  On execution of the program, there will be a text-based menu.
  Enter a number corresponding to a menu option to execute that function.
  To quit, enter '0' and then 'y' when prompted.
