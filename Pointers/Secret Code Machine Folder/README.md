🔒 Project Overview

This project is a Secret Code Machine for a spy agency. The program takes a number from the user and generates a secret code by multiplying all numbers from that number down to 1 (factorial). The twist is that the factorial function is called indirectly through a function pointer, and the result is stored in dynamically allocated memory.

⚡ Features

Accepts user input (the agent’s number).

Computes factorial using a loop.

Uses a function pointer to call the factorial function dynamically.

Allocates memory on the heap using malloc.

Performs a safety check to ensure memory allocation succeeds.

Stores the secret code in heap memory and prints it.

Frees memory at the end to prevent leaks.

📂 Program Explanation

A function named codemachine is defined to calculate the factorial of the number. It also handles the base case where input is zero and returns one.

A function pointer is declared and assigned to the factorial function. This ensures the function can be called indirectly.

The program asks the user for a number.

Memory is allocated on the heap to store the result. A check is performed to make sure memory allocation was successful.

The factorial function is called through the pointer, and its result is stored in the allocated memory.

The secret code is printed to the user.

Finally, the allocated memory is freed, and the pointer is reset to NULL.

▶️ How to Run

Save the file with a .cpp extension, for example secret_code.cpp.

Compile the program with a C++ compiler such as g++. Example command: g++ secret_code.cpp -o secret_code

Run the program: ./secret_code

Enter any number when prompted. The program will display the secret code, which is the factorial of the input number.

📝 Notes

If the user enters 0, the program correctly prints 1.

Memory is allocated using malloc and should be freed using free. Do not mix malloc with delete.

Using new and delete instead of malloc and free would make the program more modern C++ style, but the current version demonstrates dynamic memory with malloc as intended.
