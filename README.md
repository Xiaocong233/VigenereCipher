## Description
Program wrote for CS50x Pset2 on edX in C. What it does is outputting enciphered message from user's input of a message and an alphabetic key, which is what differed it from the simple Caesar Cipher. According to algorithim, this program should automatically encrypts user's input message by “rotating” each letter by a numerical value of the corresponding letter in the key. What made Vigenere powerful is that it shifts the alphabet differently per character, such that the same letter in the message being encrypted could yield different output depend on the rotation of the letter of the key.

## Usage
```python
$ make vigenere
$ ./vigenere key # key can be any combinations of English characters (a letter, a word, even a sentence with no space in between)
```

## What I have learned
* Manipulation of the values of English alphabetical letters using their ASCII values
* Low level uppercase and lowercase conversion
* Implementing Vigenère Cipher
