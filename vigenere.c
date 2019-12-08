#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
void RotationalCipher(int Key, string text, int Pos);

int main(int argc, string argv[])
{
    string userInput = argv[1];
    if (argc == 2) //check if there is exactly 2 inputs of strings
    {
        bool check = false;
        int keyLength = strlen(userInput);
        int restoration = keyLength;
        for (int i = 0; i < keyLength; i++) //check if all characters in the second string input that is the key are all alphabetical
        {
            if (userInput[i] >= 'A' && userInput[i] <= 'z')
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check == true) //if passed the check
        {
            string plaintext = get_string("plaintext:  "); //prompt for the user's input of text that needs to be ciphered
            int key;
            int n = 0;
            int numOfSpace = 0;
            printf("ciphertext: ");
            for (int i = 0; i < strlen(plaintext); i++) //encrypting every characters of the text with the corresponding key character
            {
                if (plaintext[i] == ' ' || plaintext[i] == ',' || plaintext[i] == '.' || plaintext[i] == '!' || plaintext[i] == '?' || plaintext[i] == '\"' || plaintext[i] == '\'') //nullify the rotation of the key if the character being encrypted are any of the special characters
                {
                    numOfSpace++;
                    n--;
                }
                if (i == (keyLength + numOfSpace)) //restore the encrypting key character to the first character if reaches the end of the key
                {
                    n = 0;
                    keyLength += restoration;
                }
                key = shift(argv[1][n]); //assign key as an integer value converted from the current letter of the user's string input
                RotationalCipher(key, plaintext, i); //execute rotational cipher function
                n++;
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./vigenere key\n"); //gives user correct instruction for the input
            return 1;
        }
    }
    else
    {
        printf("Usage: ./vigenere key\n"); //gives user correct instruction for the input
        return 1;
    }
}

int shift(char c) //return the number of alphabetic shift needed from the character of the key to encrypt the message
{
    int shiftNumber = toupper(c) - 65;
    return shiftNumber;
}

void RotationalCipher(int Key, string text, int Pos) //prints the ciphered text based on the rotation of the characters in user's text input alphabetically according to user's input of a key that marks the number of rotation
{
    if (text[Pos] >= 'A' && text[Pos] <= 'Z') //check if the character is captilized
    {
        printf("%c", (65 + ((text[Pos] - 65 + Key) % 26))); //calculate and print the new character
    }
    else if (text[Pos] >= 'a' && text[Pos] <= 'z') //check if the character is lowercased
    {
        printf("%c", (97 + ((text[Pos] - 97 + Key) % 26))); //calculate and print the new character
    }
    else
    {
        printf("%c", text[Pos]); //print the character as it is
    }
}
