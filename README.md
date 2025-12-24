# Text-Encryption-System

🔐 **Text Encryption System in C++**

This project is a text encryption and decryption system developed in **C++**, designed to allow users to securely transform messages using classic cryptographic methods through a terminal-based interface.

The system operates interactively, offering menus that guide the user through encryption or decryption processes and allowing continuous use without restarting the program.

---

## ⚠️ Important Note

This project was developed using **only the programming concepts studied during the first semester of university**, without relying on advanced libraries or topics beyond that scope.

---

## 🎯 Project Objective

The main goal of this project is to reinforce fundamental programming concepts by implementing a practical system capable of encrypting and decrypting text messages using classical ciphers.

This project serves as an **academic exercise**, focusing on programming logic, string manipulation, modularization, and control flow in C++.

---

## 📌 Main Features

- Encryption of text messages  
- Decryption of text messages  
- Support for up to **100 characters per message**  
- Two cryptographic methods available:
  - 🅰️ **Caesar Cipher**
  - 🔄 **Atbash Cipher**
- Interactive menu system that allows the user to:
  - Choose between encryption or decryption
  - Select the cryptographic method
  - Reuse the same message with a different cipher
  - Insert new messages without restarting the program
- Program execution continues until the user chooses to exit

---

## 🔐 Cryptographic Methods

### 🅰️ Caesar Cipher

- Substitution cipher based on shifting letters of the alphabet
- User provides a **numeric key** that defines the shift
- Works with uppercase and lowercase letters
- Non-alphabetic characters remain unchanged
- Supports encryption and decryption

### 🔄 Atbash Cipher

- Symmetric substitution cipher
- Each letter is replaced by its mirrored counterpart in the alphabet  
  - Example: `A ↔ Z`, `B ↔ Y`, `a ↔ z`
- Does **not** require a key
- Same function is used for encryption and decryption

---

## 🧠 Programming Concepts Applied

All concepts used in this project are part of the **first semester undergraduate curriculum**:

- Use of `struct`
- Character arrays for string handling
- Modular function design
- Parameter passing by reference
- Conditional structures (`if`, `else`, `switch`)
- Loop structures (`for`, `while`, `do-while`)
- Input validation
- Menu-driven program flow
- ASCII character manipulation

---

## ▶️ How to Run the Project

### Requirements

- C++ compiler (e.g., `g++`)
- Terminal or command prompt

### Steps

1. Download the source code file  
2. Open the terminal in the project folder  
3. Compile the program:

```bash
g++ main.cpp -o encryption_system
```

4. Run the program:
- Linux / macOS
```bash
./encryption_system
```

- Windows
```bash
encryption_system.exe
```

---

## 🏗️ Project Structure

```bash
Text-Encryption-System/
│
├── main.cpp
└── README.md
```

---

## 📖 General Workflow

- User chooses whether to encrypt or decrypt a message
- User inputs a text with up to 100 characters
- User selects the cryptographic method
- If required, a key is provided (Caesar Cipher)
- System processes the message and displays the result
- User can repeat the process or exit the program

---

## 👨‍🎓 Author

This project was developed as part of academic studies in C++, focusing on programming logic, string manipulation, and basic data structures.

**Author:** Gustavo Borges Rodrigues
**Course:** Science and Technology – UFRN








