Balanced Brackets Checker (C++ Program)

This project implements a simple Balanced Bracket Checker using a custom stack data structure in C++.
It verifies whether a string containing brackets — (), {}, [] — is properly balanced.

📌 Features

Uses a manually implemented stack (no STL).

Checks balanced parentheses, curly braces, and square brackets.

Detects improper nesting (e.g., {[(])} → Not Balanced).

Demonstrates object-oriented programming with classes.

🧠 How It Works

A string is considered balanced if:

Every opening bracket has a matching closing bracket.

Brackets are properly nested in the correct order.

The BalanceBr class:

Stores a string to evaluate.

Uses a dynamic array as a stack.

Pushes opening brackets on the stack.

Pops and matches closing brackets.

Returns true if the entire string is valid and the stack becomes empty.

📂 Code Structure
File	Description
main.cpp	Contains the BalanceBr class and sample test cases
🚀 Usage

The main() function includes two test cases:

BalanceBr b1(50, "{[()]}");
// Output: Balanced

BalanceBr b2(50, "{[(])}");
// Output: Not Balanced


You can modify the input strings or add your own tests.

🛠 How to Run

Save the program as main.cpp

Compile using g++:

g++ main.cpp -o balance


Run:

./balance

📘 Example Output
Input: {[()]}  -> Balanced
Input: {[(])}  -> Not Balanced

✅ Summary

This program is a great introduction to:

Stack implementation in C++

Memory management using dynamic arrays

Parentheses matching logic

Basic class design

Feel free to extend the program by adding:

Support for additional symbols

Input through the console

Error reporting for mismatched positions
