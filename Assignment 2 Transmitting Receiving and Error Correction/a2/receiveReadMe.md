# receive.c
This program takes a line of short ints produced by the output of transmit.c. It checks the parity of each and appropriately corrects any accidental bit-flips. It then converts the short ints back to chars and outputs the corrected message.

As an example, with input "2960 3160 3264 3264 3324" the corresponding output would be "Hello".

Note: this program makes use of bit_manipulation.c

### Compiling the program

```
gcc -o recv receive.c bit_manipulation.c
```

### Running the program

```
./recv
```

Enter your input and see the corrected message.
