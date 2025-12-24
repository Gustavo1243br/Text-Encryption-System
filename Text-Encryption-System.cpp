/*
Text Encryption System
----------------------
Author: Gustavo Borges
Language: C++
Purpose: Academic project (First semester)

Description:
Console-based system that allows users to encrypt and decrypt
text messages using classical cryptographic methods.

Supported ciphers:
- Caesar Cipher
- Atbash Cipher

This project uses only concepts studied during the first semester
of the Science and Technology undergraduate program.
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 100

// Structure that stores message data and encryption key
struct MessageData {
    char originalText[MAX_SIZE];
    int keyValue;
};

// Displays the main menu (encrypt, decrypt or exit)
void getInitialOption(int &selectedOption) {
    do {
        cout << endl;
        cout << "1 - Encrypt text." << endl;
        cout << "2 - Decrypt text." << endl;
        cout << "3 - Exit." << endl << endl;
        cin >> selectedOption;
        if ((selectedOption != 1) && (selectedOption != 2) && (selectedOption != 3)) {
            cout << "Invalid input. Please enter a valid option." << endl;
        }
    } while ((selectedOption != 1) && (selectedOption != 2) && (selectedOption != 3));
}

// Displays the cipher selection menu
void getCipherType(int &selectedType) {
    do {
        cout << endl;
        cout << "1 - Caesar Cipher." << endl;
        cout << "2 - Atbash Cipher." << endl;
        cout << "3 - Back to main menu." << endl << endl;
        cin >> selectedType;
        if ((selectedType != 1) && (selectedType != 2) && (selectedType != 3)) {
            cout << "Invalid input.";
        }
    } while ((selectedType != 1) && (selectedType != 2) && (selectedType != 3));
}

// Reads a text message and validates its length
void getMessage(MessageData &data, int &textLength) {

    cin.getline(data.originalText, MAX_SIZE);

    textLength = strlen(data.originalText);

    while ((textLength < 1) || (textLength > 100)) {
        cout << "Length out of bounds, please try again." << endl;
        cin.getline(data.originalText, MAX_SIZE);
        textLength = strlen(data.originalText);
        cout << endl;
    }
    cout << endl;
}

// Encrypts a message using the Caesar cipher
void executeCaesarEncrypt(MessageData data, int textLength, char encryptedResult[]) {
    int i, currentChar, wrapAdjustment;

    // Reduces the key if it is greater than the alphabet size
    if (data.keyValue >= 26) {
        data.keyValue = data.keyValue % 26;
    }

    for (i = 0; i < textLength; i++) {
        currentChar = data.originalText[i];

        // Encrypt uppercase letters
        if ((currentChar >= 'A' && currentChar <= 'Z') && (currentChar + data.keyValue <= 'Z')) {
            encryptedResult[i] = currentChar + data.keyValue;
        }

        // Encrypt lowercase letters
        else if ((currentChar >= 'a' && currentChar <= 'z') && (currentChar + data.keyValue <= 'z')) {
            encryptedResult[i] = currentChar + data.keyValue;
        }

        // Handles alphabet overflow for uppercase letters
        else if ((currentChar >= 'A' && currentChar <= 'Z') && (currentChar + data.keyValue > 'Z')) {
            wrapAdjustment = (currentChar + data.keyValue) - 91;
            currentChar = 'A';
            encryptedResult[i] = currentChar + wrapAdjustment;
        }

        // Handles alphabet overflow for lowercase letters
        else if ((currentChar >= 'a' && currentChar <= 'z') && (currentChar + data.keyValue > 'z')) {
            wrapAdjustment = (currentChar + data.keyValue) - 123;
            currentChar = 'a';
            encryptedResult[i] = currentChar + wrapAdjustment;
        }

        // Keeps symbols, numbers and spaces unchanged
        else {
            encryptedResult[i] = currentChar;
        }
    }
}

// Atbash cipher (same function for encryption and decryption)
void executeAtbash(MessageData data, int textLength, char encryptedResult[]) {
    int i, currentChar, alphabetIndex, mirroredChar;

    for (i = 0; i < textLength; i++) {
        currentChar = data.originalText[i];

        if (currentChar >= 'A' && currentChar <= 'Z') {
            alphabetIndex = currentChar - 'A';
            mirroredChar = 'Z' - alphabetIndex;
            encryptedResult[i] = mirroredChar;
        }
        else if (currentChar >= 'a' && currentChar <= 'z') {
            alphabetIndex = currentChar - 'a';
            mirroredChar = 'z' - alphabetIndex;
            encryptedResult[i] = mirroredChar;
        } else {
            encryptedResult[i] = currentChar;
        }
    }
}

// Decrypts a message encrypted with the Caesar cipher
void executeCaesarDecrypt(MessageData data, int textLength, char encryptedResult[]) {
    int i, currentChar, wrapAdjustment;

    // Reduces the key if it is greater than the alphabet size
    if (data.keyValue >= 26) {
        data.keyValue = data.keyValue % 26;
    }

    for (i = 0; i < textLength; i++) {
        currentChar = data.originalText[i];

        // Decrypt uppercase letters
        if ((currentChar >= 'A' && currentChar <= 'Z') && (currentChar - data.keyValue >= 'A')) {
            encryptedResult[i] = currentChar - data.keyValue;
        }

        // Decrypt lowercase letters
        else if ((currentChar >= 'a' && currentChar <= 'z') && (currentChar - data.keyValue >= 'a')) {
            encryptedResult[i] = currentChar - data.keyValue;
        }

        // Handles alphabet underflow for uppercase letters
        else if ((currentChar >= 'A' && currentChar <= 'Z') && (currentChar - data.keyValue < 'A')) {
            wrapAdjustment = 'A' - (currentChar - data.keyValue);
            currentChar = 'Z' + 1;
            encryptedResult[i] = currentChar - wrapAdjustment;
        }

        // Handles alphabet underflow for lowercase letters
        else if ((currentChar >= 'a' && currentChar <= 'z') && (currentChar - data.keyValue < 'a')) {
            wrapAdjustment = 'a' - (currentChar - data.keyValue);
            currentChar = 'z' + 1;
            encryptedResult[i] = currentChar - wrapAdjustment;
        }

        // Keeps symbols, numbers and spaces unchanged
        else {
            encryptedResult[i] = currentChar;
        }
    }
}

// Prints the resulting text
void displayResult(char encryptedResult[], int textLength) {
    int i;
    for (i = 0; i < textLength; i++) {
        cout << encryptedResult[i];
    }
    cout << endl;
}

// Main program execution
int main() {

    int menuOption, textLength;
    int cipherType = 4, navigationOption;
    char processedText[MAX_SIZE];
    MessageData userData;

    cout << "Welcome to the Encryption System." << endl << endl;
    cout << "Here you can:" << endl << "Encrypt or decrypt text using Caesar Cipher or Atbash Cipher." << endl;
    cout << "Let's start!";

    do {
        cout << endl;
        cout << "What would you like to do? (Enter the number): " << endl;

        getInitialOption(menuOption);

        cin.ignore();

        switch (menuOption) {
        case 1:
            cout << endl;
            cout << "Enter the message you want to encrypt (max 100 characters): " << endl;
            getMessage(userData, textLength);
            break;
        case 2:
            cout << endl;
            cout << "Enter the message you want to decrypt (max 100 characters): " << endl;
            getMessage(userData, textLength);
            break;
        case 3:
            cout << "See you later!" << endl;
            return 0;
        }

        cout << "Which cipher would you like to use? (Enter the number) " << endl;

        getCipherType(cipherType);

        if (cipherType == 1) {
            cout << "Enter the encryption key: " << endl;
            cin >> userData.keyValue;
        }

        if (menuOption == 1 && cipherType == 1) {
            executeCaesarEncrypt(userData, textLength, processedText);
            cout << endl << "Here is your encrypted message:" << endl;
        } else if (menuOption == 1 && cipherType == 2) {
            executeAtbash(userData, textLength, processedText);
            cout << endl << "Here is your encrypted message:" << endl;
        } else if (menuOption == 2 && cipherType == 1) {
            executeCaesarDecrypt(userData, textLength, processedText);
            cout << endl << "Here is your decrypted message:" << endl;
        } else if (menuOption == 2 && cipherType == 2) {
            executeAtbash(userData, textLength, processedText);
            cout << endl << "Here is your decrypted message:" << endl;
        }

    } while (cipherType == 3);

    processedText[textLength] = '\0';

    displayResult(processedText, textLength);

    do {
        cout << endl;
        cout << "Now, what would you like to do: " << endl;
        cout << "1 - Use a new message/text." << endl;
        cout << "2 - Use a different encryption type." << endl;
        cout << "3 - Exit." << endl;
        cin >> navigationOption;

        while (navigationOption != 1 && navigationOption != 2 && navigationOption != 3) {
            cout << "Option does not exist. Please enter again: " << endl;
            cin >> navigationOption;
        }

        cout << endl;

        switch (navigationOption) {
        case 1:
            cout << endl;
            cout << "Now, you will: " << endl;
            cout << "1 - Encrypt a message." << endl;
            cout << "2 - Decrypt a message." << endl;
            cin >> menuOption;

            while (menuOption != 1 && menuOption != 2) {
                cout << "Invalid input. Please enter a valid option." << endl;
                cout << "1 - Encrypt a message." << endl;
                cout << "2 - Decrypt a message." << endl;
                cin >> menuOption;
            };

            cin.ignore();

            if (menuOption == 1) {
                cout << "Enter the message you want to encrypt (max 100 characters): " << endl;
                getMessage(userData, textLength);
            } else {
                cout << "Enter the message you want to decrypt (max 100 characters): " << endl;
                getMessage(userData, textLength);
            }
            cout << "Which cipher would you like to use? (Enter the number) " << endl;
            getCipherType(cipherType);

            if (cipherType == 1) {
                cout << "Enter the encryption key: " << endl;
                cin >> userData.keyValue;
            }

            if (menuOption == 1 && cipherType == 1) {
                executeCaesarEncrypt(userData, textLength, processedText);
            } else if (menuOption == 1 && cipherType == 2) {
                executeAtbash(userData, textLength, processedText);
            } else if (menuOption == 2 && cipherType == 1) {
                executeCaesarDecrypt(userData, textLength, processedText);
            } else {
                executeAtbash(userData, textLength, processedText);
            }

            processedText[textLength] = '\0';
            displayResult(processedText, textLength);
            break;

        case 2:
            cout << "Which cipher would you like to use? (Enter the number) " << endl;
            getCipherType(cipherType);

            if (cipherType == 1) {
                cout << "Enter the encryption key: " << endl;
                cin >> userData.keyValue;
            }

            if (menuOption == 1 && cipherType == 1) {
                executeCaesarEncrypt(userData, textLength, processedText);
            } else if (menuOption == 1 && cipherType == 2) {
                executeAtbash(userData, textLength, processedText);
            } else if (menuOption == 2 && cipherType == 1) {
                executeCaesarDecrypt(userData, textLength, processedText);
            } else {
                executeAtbash(userData, textLength, processedText);
            }

            processedText[textLength] = '\0';
            displayResult(processedText, textLength);
            break;

        case 3:
            cout << "See you later!" << endl;
            navigationOption = 0;
            break;
        }

    } while (navigationOption != 0);

    return 0;
}
