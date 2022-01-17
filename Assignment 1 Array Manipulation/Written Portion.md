# 1)
How many different values can be represented using 9 digits in the following bases:

**Base 2:**
$2^9 = 512 \therefore \mbox{you can represent 512 values using 9 digits in base 2}$

**Base 16:**
$16^9 = 68719476736 \therefore \mbox{you can represent 68719476736 values using 9 digits in base 16}$

**Base 8:**
$8^9 = 134217728 \therefore \mbox{you can represent 134217728 values using 9 digits in base 8}$
- - -
# 2)
Find the decimal equivalent of the following
**a) **
$(542)_8 = (5 * 8^2) + (4 * 8^1) + (2 * 8^0)$
==$= (354)_{10}$==

**b) **
$(EAB1)_{16} = (14 * 16^3) + (10 * 16^2) + (11 * 16^1) + (1 * 16^0)$
==$= (60081)_{10}$==

**c) **
$(2E)_{16} = (2 * 16^1) + (14 * 16^0)$
==$= (46)_{10}$==

**d) **
$(00010111)_2 = (0 * 2^7) + (0 * 2^6) + (0 * 2^5) + (1 * 2^4) + (0 * 2^3) + (1 * 2^2) + (1 * 2^1) + (1 * 2^0)$
==$= (23)_{10}$==
- - -
# 3)
What is the simple binary, octal, and hexa equivalent of the following decimal numbers:

**a) 231 -> binary**
$$
\begin{gather}

231/2 = 115 (1) \\
115/2 = 57 (1) \\
57/2 = 28 (1) \\
28/2 = 14 (0) \\
14/2 = 7 (0) \\
7/2 = 3 (1) \\
3/2 = 1 (1) \\
1/2 = 0 (1) \\\\

= (11100111)_2

\end{gather}
$$

**a) 231 -> octal**
$$
\begin{gather}

231/8 = 28 (7) \\
28/8 = 3 (4) \\
3/8 = 0 (3) \\\\

= (347)_8

\end{gather}
$$

**a) 231 -> hexa**
$$
\begin{gather}

231/16 = 14 (7) \\
14/16 = 0 (14 = E) \\\\

= (E7)_{16}

\end{gather}
$$

**b) 1183 -> binary**
$$
\begin{gather}

1183/2 = 591 (1) \\
591/2 = 295 (1) \\
295/2 = 147 (1) \\
147/2 = 73 (1) \\
73/2 = 36 (1) \\
36/2 = 18 (0) \\
18/2 = 9 (0) \\
9/2 = 4 (1) \\
4/2 = 2 (0) \\
2/2 = 1 (0) \\
1/2 = 0 (1) \\\\

= (10010011111)_2

\end{gather}
$$

**b) 1183 -> octal**

$$
\begin{gather}

1183/8 = 147 (7) \\
147/8 = 18 (3) \\
18/8 = 2 (2) \\
2/8 = 0 (2) \\\\

= (2327)_8

\end{gather}
$$

**b) 1183 -> hexa**
$$
\begin{gather}

1183/16 = 73 (15 = F) \\
73/16 = 4 (9) \\
4/16 = 0 (4) \\\\

= (49F)_{16}

\end{gather}
$$

**c) 1928 -> binary**
$$
\begin{gather}

1928/2 = 964 (0) \\
964/2 = 482 (0) \\
482/2 = 241 (0) \\
241/2 = 120 (1) \\
120/2 = 60 (0) \\
60/2 = 30 (0) \\
30/2 = 15 (0) \\
15/2 = 7 (1) \\
7/2 = 3 (1) \\
3/2 = 1 (1) \\
1/2 = 0 (1) \\\\

= (11110001000)_2


\end{gather}
$$

**c) 1928 -> octal**
$$
\begin{gather}

1928/8 = 241 (0) \\
241/8 = 30 (1) \\
30/8 = 3 (6) \\
3/8 = 0 (3) \\\\

= (3610)_8

\end{gather}
$$

**c) 1928 -> hexa**
$$
\begin{gather}

1928/16 = 120 (8) \\
120/16 = 7 (8) \\
7/16 = 0 (7) \\\\

= (788)_{16}

\end{gather}
$$
- - -
# 4)
Assume that a system has 6-bits bytes for storing binary numbers. Specify the range of numbers that can be represented in one byte in the following data models:

**a) Unsigned Integers (Positive Numbers)**
$2^6 = 64$, therefore you can store ==64 different unsigned integers==. It covers all numbers from 0 to 63 (inclusive).

**b) Two's Complement**
You can store 64 different signed integers however one bit is reserved for telling whether the number is negative or not. Therefore you have 5 bits to work with. $2^5 = 32$ with a negative operator therefore you can represent all numbers from -32 to +31 (inclusive) Therefore you can still represent a ==total of 64 different integers==.
- - -
# 5)
Perform the operation on the following 8-bit binary numbers. The numbers are represented in 2's-complement notation. Show the work using base 2.

**a)** $01011101 + 10101001$
```c
	01011101
+	10101001
------------
   100000110
```
==$= 100000110$==

**b)** $10110111 - 11001011$
```c
	10110111
-	11001011
------------
	00110100
```
==$= -10100$==

**c)** $00000111 * 00000101$
```c
		00000111
x		00000101
----------------
		00000111	+	
	   000000000	+	
	  0000011100	+	
	 00000000000	+	
	000000000000	+	
   0000000000000	+	
  00000000000000	+	
 000000000000000
 
================
		00000111
+	  0000011100
----------------
	 	  100011
```
==$= 100011$==
- - -
# 6)
Convert the following decimal numbers into 2's complement representations.

**a) 72**
$$
\begin{gather}

\mbox{Convert to regular binary:} \\\\

72/2 = 36 (0) \\
36/2 = 18 (0) \\
18/2 = 9 (0) \\
9/2 = 4 (1) \\
4/2 = 2 (0) \\
2/2 = 1 (0) \\
1/2 = 0 (1) \\\\

= (1001000)_2 \\\\

\mbox{Convert to Two's Complement:} \\\\

01001000 \mbox{ // padded with 0's to make 8bit and non-negative}

\end{gather}
$$

**b) 0**
$00000000$

**c) -128**
$11111111$

**-5**
$5_{10} = 101_2$
$-5_{10} = 10000101$

- - -
# 7)
Find the decimal equivalent of the following binary numbers assuming that each number is expressed in: (1) unsigned integer, (2) 2's complement (3) excess 127

**a) 01011000**
==Unsigned int: $= 88$==
==2's Complement: $= 88$==
==Excess 127: $= 1.011000 * 2^7*$==

**b) 000101111110**
==Unsigned int: $= 382$==
==2's Complement: $382$==
==Excess 127: $= 1.01111110 * 2^5$==


- - -
# 8)
Convert the following decimal numbers to normalized floating point representation (e.g., 0.5 should be $1.0 * 2^{-1}$)
**a) 4.625**
```c
i = 0:
	y = 0.625*2 = 1.25
	print(1)
	x = 1.25 - 1 = 0.25
i = 1:
	y = 0.25*2 = 0.5
	print(0)
	x = 0.5
i = 2:
	y = 0.5*2 = 1
	print(1)
	x = 1 - 1 = 0
```
$= 100.101$
==$= 1.00101 * 2^2$==

**b) -1.25**
```c
i = 0:
	y = 0.25*2 = 0.5
	print(0)
	x = 0.5
i = 1:
	y = 0.5*2 = 1
	print(1)
	x = 1 - 1 = 0
```
$= -1.01$
==$= -1.01 * 2^0$==

- - -
# 9) 
Convert the following binary integers directly into (i) octal and (ii) hexadecimal (by grouping the bits)
**a) 101111110010**

**To Octal:**

| 4   | 2   | 1   | 4   | 2   | 1   | 4   | 2   | 1   | 4   | 2   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 0   | 0   | 1   | 0   |

$(4 + 1), (4 + 2 + 1), (4 + 2), (2)$
==$= 5762$==

**To Hexa:**

| 8   | 4   | 2   | 1   | 8   | 4   | 2   | 1   | 8   | 4   | 2   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 0   | 0   | 1   | 0   |

$(8+2+1), (8+4+2+1), (2)$
$= 11(B), 15(F), 2$
==$= BF2$==

**b) 000101111110**

**To Octal:**

| 4   | 2   | 1   | 4   | 2   | 1   | 4   | 2   | 1   | 4   | 2   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 1   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 0   |

$(0), (4 + 1), (4 + 2 + 1), (4 + 2)$
==$= 0576 = 576$==

**To Hexa:**

| 8   | 4   | 2   | 1   | 8   | 4   | 2   | 1   | 8   | 4   | 2   | 1   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 1   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 0   |

$(1), (4+2+1), (8+4+2)$
$= 1, 7, 14(E)$
==$= 17E$==

- - -
# 10)
Assuming that you are required to make an 8-bit floating point representation, with a 3 bits exponent using excess-4 notation and a 4 bits mantissa using normalized notation.

**a) How would the number 0.5 be stored in the byte?**

| 0   | 011 | 0001 |
| --- | --- | ---- |

**b) What is the number 11101010**

| 1   | 110 | 1010 | 
| --- | --- | ---- |

Facts:
- Negative
- Exponent = $110_2 = 6_{10}; 6 - k = 6 - 3 = 3$
- Mantissa = $1.1010_2 * 2^3 = 1101.0$

| $2^3$ | $2^2$ | $2^1$ | $2^0$ | $2^{-1}$ |
| ----- | ----- | ----- | ----- | ------ |
| 1     | 1     | 0     | 1     | 0      |
| 8     | 4     | 0     | 1     | 0      |

$= 8 + 4 + 1 = 13$
Negative ==$\therefore 11101010 = -13$==

**c) Can the number 8.75 be stored in this system? If it can be stored then show the bit pattern. If not explain why.**

$8_{10} = 1000_2$

```c
i = 0:
	y = 0.75 * 2 = 1.5
	print(1)
	x = 1.5 - 1 = 0.5
i = 1:
	y = 0.5 * 2 = 1
	print(1)
	x = 1 - 1 = 0
```

$0.75_{10} = 0.11_2$

$8.75_{10} = 1000.11_2 * 2^0$

Normalize: $8.75_{10} = 1.00011_2 * 2^3$

Facts: 
- Mantissa $= 00011$
- Exponent $= 3 + k = 3 + 3 = 6 = 110_2$
- Sign is 0

Our mantissa is greater than 4 bits but we can change the exponent and remove one leading 0 from the mantissa. Therefore our new facts are:

- Mantissa $= 0011$
- Exponent $= 2 + k = 5 = 101_2$
- Sign is 0

==Therefore, it would be displayed as:==

| 0   | 101 | 0011 | 
| --- | --- | ---- |

**d) Can the number 6.25 be stored in this system? If it can be stored then show the bit pattern. If not explain why.**

$6_{10} = 110_2$

```c
i = 0:
	y = 0.25 * 2 = 0.5
	print(0)
	x = 0.5
i = 1:
	y = 0.5 * 2 = 1
	print(1)
	x = 1 - 1 = 0
```

$0.25_{10} = 0.01_2$

$6.25_{10} = 110.01_2$

Normalize: $110.01_2 * 2^0 = 1.1001_2 * 2^2$

Facts:
- Mantissa $= 1001$
- Exponent $= 2 + k = 2 + 3 = 5_{10} = 101_2$
- Sign is 0

==Therefore, we can display 6.25 as:==

| 0   | 101 | 0011 |
| --- | --- | ---- |

- - -
# 11)
Assuming that you are required to make an 8-bit floating point representation, with a 3 bits exponent using excess-4 notation and a 4 bits mantissa using normalized notation. 

**What is the smallest positive number that can be stored?**
$100_2 = -4_{10}$ 
Therefore the smallest exponent we can use is -4
The lowest (non-zero mantissa) we can use is a 1 therefore 0001

==Therefore we can make the number $1.0001 * 2^{-4} = 0.06250625$==

**What is the smallest negative number that can be stored?**
All 1's to get the smallest possible number:

| 1   | 111 | 1111 | 
| --- | --- | ---- |

$1111111_2 = 127_{10}$

==Therefore, the smallest negative number we can store is -127==


