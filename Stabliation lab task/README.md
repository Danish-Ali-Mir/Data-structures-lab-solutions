CHRONOS TIME STABILIZER
Binary Search Tree (BST) Implementation in C++
Overview

The Chronos Time Stabilizer is a C++ program that uses a Binary Search Tree (BST) to store, search, delete, and display time-based events.
Each node in the tree represents a Time Capsule, containing:

A year (used as the BST key)

An event name

Links to left and right child nodes

The user interacts with the program by entering commands such as:
INJECT, PARADOX, SEARCH, REPORT, and EXIT.

This creates a command-line simulation of a “timeline management system.”

Features
1. Insert an Event (INJECT)

Adds a new time capsule (year + event name) to the BST.

Format:

INJECT <year> <event name>


Example:

INJECT 1999 Y2K Preparation

2. Delete an Event (PARADOX)

Removes a time capsule for a specific year.
Handles all BST delete cases:

Leaf node

Node with one child

Node with two children (uses inorder successor)

Format:

PARADOX <year>

3. Search for an Event (SEARCH)

Looks up a year in the BST and displays the associated event.

Format:

SEARCH <year>

4. Generate Chronological Report (REPORT)

Displays all events in ascending order of years using an inorder traversal.

Format:

REPORT

5. Exit the Program (EXIT)

Stops all input processing and terminates the program.

How the BST Works

The program uses a standard Binary Search Tree where:

Left child contains years less than the node

Right child contains years greater than the node

No duplicate years are inserted

The BST operations are implemented using recursive helper functions stored in the private section of the TimeTree class.

Internal Components
TimeCapsule (struct)

Represents each node in the tree:

year

eventName

left

right

TimeTree (class)

Implements all major operations:

inject() – Public insertion

resolveParadox() – Public deletion

search() – Public search

report() – Inorder traversal

Destructor – Deletes entire tree from memory

(There is also an optional calculateTimeSpan() function, included as a bonus feature but not used in the main program.)

Example Input
INJECT 2001 First Human Genome Draft
INJECT 2025 Mars Base Established
SEARCH 2001
PARADOX 2025
REPORT
EXIT

How to Compile

Use any C++ compiler supporting C++11 or above.

Compile:

g++ LabTask_Stabalization.cpp -o chronos


Run:

./chronos

Program Output (Example)
> System: Injecting 2001... Timeline stable.
> System: Injecting 2025... Timeline stable.

> Query: Searching for 2001...
> Result: Event Found! [2001: First Human Genome Draft]

> Alert: Paradox detected at 2025!
> System: Paradox resolved. Year removed.

> COMMAND: CHRONOLOGICAL REPORT
-------------------------------
2001 → First Human Genome Draft
-------------------------------
