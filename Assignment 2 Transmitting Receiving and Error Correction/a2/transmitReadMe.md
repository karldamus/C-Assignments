# transmit.c
This program takes a plain English sentence converts it to short representations of each character and checks / sets the parity of each short to ensure proper transmission for use by the receive.c program.

As an example, with input "Hello" the corresponding output would be "2960 3160 3264 3264 3324".

Note: this program makes use of bit_manipulation.c

### Compiling the program
```
gcc -o tran transmit.c bit_manipulation.c
```

### Running the program

```
./tran
```

Enter your input and copy the output to use in receive.c
