/*
Title: Homework 01: Caesar Cypher
Author: Anik Barua
Version: 1.0
Date: 02-01-2022
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Funtion protoypes for encryptedChar() and encryptLine()
char encryptedChar(char character, int rotationValue);
void encryptLine(string& line, int rotationValue);

// Main function
int main()
{
    ifstream reader("encrypted.txt"); // reading the "encrypted.txt" file
    if (!reader)
    {
        cerr << "Failed to open encrypted.txt";
        exit(1);
    }

    int rotationValue;       // variable to store the rotation value
    string line;             // line to hold the string from getline()
    vector<string> lines;    // vector containing the lines in the file
    reader >> rotationValue; // reads the integer at the beginning of the file
    getline(reader, line);   // calling getline an "extra" time, after reading the integer
    while (reader)
    {
        getline(reader, line); // reads the rest of the file line by line
        if (!line.empty())
        { // checks for empty lines
            lines.push_back(line);
        }
    }
    reader.close(); // closing the file

    // lines are stored in reversed i.e. last line is our first line, so printing in reverse order
    for (size_t i = lines.size(); i > 0; --i)
    {
        // calling the encryptLine function that takes an encrypted string and the rotation value
        encryptLine(lines[i - 1], rotationValue);
        cout << lines[i - 1] << endl;
    }
    return 0;
} // end of main

/*
encryptedChar() function takes an encrypted character and the rotation distance, and returns
the corresponding decrypted character.
*/
char encryptedChar(char character, int rotationValue)
{
    int position = 0;
    if (character >= 'a' && character <= 'z') // only lowercase characters will result in a change
    {
        position = character - rotationValue; // y letters past char in the alphabet
        if (position < 'a')
        {
            position += 26; // rotates back to 'z' if position is less than 'a'
        }
        character = position; // character at that position
    }
    return character;
} // end of encryptedChar() function

/*
encryptLine() function takes a string and the rotation distance. It modifies the string
that is passed in, changing it into its unencrypted form. Since strings in C++ are
mutable, we are doing a pass by reference for the string.
*/
void encryptLine(string& line, int rotationValue)
{
    for (size_t i = 0; i < line.length(); ++i)
    {
        line[i] = encryptedChar(line[i], rotationValue); // calls the encryptedChar() function
    }
} // end of encryptLine function