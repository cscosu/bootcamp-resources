# OSU CSC Bootcamp: Crypto

By: Yu-Shiang Jeng, Cyber Security Club @ Ohio State

## Set up

- Challenge:
  - Run this Python 3 script that prints a flag
  - Goal: Make sure that Python is installed and works

## Encoding

- Data is represented as a sequence of 1's and 0's.
- Each binary digit is a bit.

- Usually we group them into 8 known as bytes
- The value of a byte ranges from 0 to 255

- Representing integers in binary is intuitive. Just convert to base 10 to see
  the decimal equivalent

- How are strings represented? In the simplest case, each character is 1 byte.
- We can use the ASCII encoding standard: Show ASCII table

Challenge:
  - Convert array integers to ASCII
  - Get part of a flag

- Writing out huge streams of 1's and 0's is really ugly
- Instead we can use base 16 (hexadecimal)
- Each digit: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f}

- The range of a byte in hex: 0x00 - 0xff

Challenge:
  - Convert a hex number to bytes to get part of the flag
  - `bytes.fromhex()`

- Another popular encoding scheme is Base64
  - Each character encodes 6 bits (2**6 == 64)
  - Get used to seeing Base64 everywhere

Challenge:
  - Base64 decode to get part of the flag

Challenge:
  - Convert a big integer to the final part of the flag
  - Can be done in vanilla Python, but it's ugly:
    - `bytes.fromhex(hex(m)[2:])`
  - Better to use PyCryptodome `long_to_bytes`

## XOR

## Modular arithmetic

## RNGs

## SHA256

## AES

---
Probably save rest for next time

## Diffie-Hellman

## RSA
