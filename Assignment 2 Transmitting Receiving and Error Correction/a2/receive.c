
/*

File receive.c


Purpose: simulate the receiveing end of a message over the network.

The program converts a message encodded as an array of short integers into characters.
The input message uses 1-bit error correction code.
As part of the simulation, the program also corrects any 1-bit errors in the receiving message.


Revision:
a. Initial code - Doron Nussbaum
b. short2Char(...) - Karl Damus
c. correctCode(...) - Karl Damus

Example I/O:
	Input: 2960 3160 3264 3264 3324
	Output: Hello
*/


/************************************************************************/
// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "bit_manipulation.h"

/************************************************************************/
//MACROS  / DEFINES

#define XSTR(A) STR(A)
#define STR(A) #A
#define MAX_INPUT_LENGTH 8192
#define MAX_MSG_LENGTH 2048
#define P1_MASK 0xaa8   // 0b0101010101000
#define P2_MASK 0xcc8	// 0b0110011001000
#define P4_MASK 0x10e0	// 0b1000011100000
#define P8_MASK 0x1e00  // 0b1111000000000

/************************************************************************/
// FUNCTION PROTOTYPES

void short2Char(short encodedChar, char *c);
void correctCode(short *num);
void readEncodedMessage(short *buf, int len, int *numRead);

/**************************************************************************/

int main(int argc, char *argv[])

{
	int rc = 0;		// return code

	char s[MAX_MSG_LENGTH] = { '\0' };  // message
	short encodedMsg[MAX_MSG_LENGTH];
	int numRead = 0;  // number of characters in the message
	int i;

	// read the message
	printf("Enter the transmitted message: ");
	readEncodedMessage(encodedMsg, MAX_MSG_LENGTH, &numRead);



	// print the corrected message
	printf("\n\n Transmitted Message:\n");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
    }
    printf("\n");

    // correct the message
	for (i = 0; i < numRead; i++) {
		correctCode(&encodedMsg[i]);
	}



	// print the corrected message
	printf("\n\n Corrected Transmitted Message:\n");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
	}
	printf("\n");

	return(0);
}


/***********************************************************************************/
/* reads a message from the user

input
len - maximum length of mesage that should be read

output
receivedMsg - contains the message
numRead - the number of characters in the message

Asumption:
function does not do any error checking of the input.  It expects to receive
a sequence of positive short integers.

*/

void readEncodedMessage(short *receivedMsg, int len, int *numRead)
{
	int i;
	int rc;
	char s[MAX_INPUT_LENGTH+1];
	char *token = NULL;
	*numRead = 0;

	s[MAX_INPUT_LENGTH] = '\0';
	scanf("%"XSTR(MAX_INPUT_LENGTH)"[^\n]s", s);
	token = strtok(s, " ");

	for (i = 0; token != NULL  &&  i < len;token = strtok(NULL, " "), i++) {
		rc = sscanf(token, "%hd", &receivedMsg[i]);
	}

	*numRead = i; // set the number of read integers

    // empty the input buffer
    for( ; getchar() != '\n'; );


}




/*************************************************************************/
/* assign bits 3,5,6,7,9,10,11,12 of a integer to bits 0-7 of a char

input
encodedNum - a short integer
	example: 2448

output
*c - the modified char that is embedded in encodedNum
	example: H

return:
none

comment:
this is the "inverse" of the function char2Short in the transmit program

*/

void short2Char(short encodedNum, char *c)
{
	short mask = 0x0001;
	int i;
	int bitSet;


	*c = 0;		// initialize *c

	// loop through all bits associated with short
	for (i = 3; i < 13; i++) {
		bitSet = isShortBitSet(encodedNum, i);

		if (!bitSet) continue;

		// for each case, if the corresponding bit is set in encodedNum
		// set the appropiate bit in char *c
		switch(i) {
			case 3:
				setCharBit(0, c);
				break;
			case 4:
				break;
			case 5:
				setCharBit(1, c);
				break;
			case 6:
				setCharBit(2, c);
				break;
			case 7:
				setCharBit(3, c);
				break;
			case 8:
				break;
			case 9:
				setCharBit(4, c);
				break;
			case 10:
				setCharBit(5, c);
				break;
			case 11:
				setCharBit(6, c);
				break;
			case 12:
				setCharBit(7, c);
				break;
			default:
				printf("This should not happen !!!!\n");
				assert(0);
		}
	}
}


/*************************************************************************************/

/* purpose:
performs error corrrections, if needed on the short integer

The function checks the parity bits for error and see if thre is a discrepancy between
the transmitted parity bits and the computed parity bits for the received number.
If there is a decrepancy then it finds the bit number that was flipped.

If there is an error then it fixes it.

input
num - the address of the short number
	example: 2960

output:
*num - the modified number
	example: 2448
*/

void correctCode(short *num)
{
	int mask;
	int sum;
	int bitNumber = 0; //  bit number with the error bit
	int parity;		// a parity bit either 0 or 1
	int storedParity; // the parity bit in the encoded char
	short tmp;

	/*
		Find the checksum for X8
	*/

	sum = 0; // reset sum

	// check all bits from 8 to 12 (inclusive)
	for (int i = 8; i <= 12; i++) {
		sum += isShortBitSet(*num, i);
	}

	// if uneven, add 2^3 to bitNumber
	if (sum % 2 != 0) {
		bitNumber += 8;
	}

	printf("%s %d \n", "X8 sum from hard-code:", sum);

	sum = countBits(*num & P8_MASK);

	printf("%s %d \n", "X8 sum from countBits:", sum);

	/*
		Find the checksum for X4
	*/

	sum = 0; // reset sum

	// check all bits from 4 to 7 (inclusive)
	for (int i = 4; i <= 7; i++) {
		sum += isShortBitSet(*num, i);
	}

	// also check outlier bit 12
	sum += isShortBitSet(*num, 12);

	// if uneven, add 2^2 to bitNumber
	if (sum % 2 != 0) {
		bitNumber += 4;
	}

	printf("%s %d \n", "X4 sum from hard-code:", sum);

	sum = countBits(*num & P4_MASK);

	printf("%s %d \n", "X4 sum from countBits:", sum);

	/*
		Find the checksum for X2
	*/

	sum = 0; // reset sum

	// find all bits associated with checksum for X2
	sum += isShortBitSet(*num, 2);
	sum += isShortBitSet(*num, 3);
	sum += isShortBitSet(*num, 6);
	sum += isShortBitSet(*num, 7);
	sum += isShortBitSet(*num, 10);
	sum += isShortBitSet(*num, 11);

	// if uneven, add 2^1 to bitNumber
	if (sum % 2 != 0) {
		bitNumber += 2;
	}

	printf("%s %d \n", "X2 sum from hard-code:", sum);

	sum = countBits(*num & P2_MASK);

	printf("%s %d \n", "X2 sum from countBits:", sum);

	/*
		Find the checksum for X1
	*/

	sum = 0; // reset sum

	// find all uneven bits from 1 to 11 (inclusive)
	for (int i = 1; i < 12; i++) {
		if (i % 2 != 0) {
			sum += isShortBitSet(*num, i);
		}
	}

	// if uneven, add 2^0 to bitNumber
	if (sum % 2 != 0) {
		bitNumber += 1;
	}

	printf("%s %d \n", "X1 sum from hard-code:", sum);

	sum = countBits(*num & P1_MASK);

	printf("%s %d \n", "X1 sum from countBits:", sum);

	printf("\n\n");

	/*
		if bitNumber is not 0, then a bit was flipped
		reflip that bit to correct the error
	*/
	if (bitNumber != 0) {
		flipBitShort(bitNumber, num);
	}
}
