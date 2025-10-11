🚍 Data Structures Lab Task – Linked List (BRT Peshawar Use Case)
📘 Project Overview

This project implements a Linked List in C++ to simulate a Bus Rapid Transit (BRT) passenger queue system for Peshawar.
It demonstrates key Data Structure operations (Insertion, Deletion, and Traversal) using a real-world scenario — managing passengers joining and leaving a queue.

🎯 Objective

To understand how linked lists work in dynamic memory management by simulating passenger flow in a BRT queue:

Adding passengers at the end of the queue.

Adding emergency passengers at the front.

Adding special booking passengers at a specific position.

Removing passengers from the beginning as they board the bus.

⚙️ Features Implemented
Operation	Function	Description
Insert at Beginning	insertAtBeginning(int value)	Adds a passenger to the front (for emergencies).
Insert at End	insertAtEnd(int value)	Adds a passenger at the end of the queue (normal entry).
Insert at Position	insertAtPosition(int value, int position)	Adds a passenger at a specific queue position (special booking).
Delete from Beginning	deleteFromBeginning(int* removedvalue)	Removes the first passenger (boarding simulation).
Display	display()	Prints the entire passenger queue in order.
🧩 Data Structure Used
struct Node

Each node represents a passenger:

struct Node {
    int passID;   // Unique Passenger ID
    Node* next;   // Pointer to next node (next passenger)
};

class linklist

This class manages the linked list, performing all operations on nodes dynamically.

🧠 Key Concepts Demonstrated

Dynamic Memory Allocation using new and delete.

Pointers and Structures.

Linked List Traversal and manipulation.

Real-life queue simulation using abstract data structures.

🧾 Example Output
Initial Queue after adding passengers:
101 -> 102 -> 103

After adding an emergency passenger at beginning:
999 -> 101 -> 102 -> 103

After inserting special booking passenger at position 2:
999 -> 101 -> 555 -> 102 -> 103

After first passenger boards (deletion):
101 -> 555 -> 102 -> 103

🧮 Code Flow Summary

Insert 3 normal passengers → added to end of queue.

Insert emergency passenger → added to beginning.

Insert special booking passenger → added at position 2.

Delete first passenger → simulates boarding process.

Display queue after each operation.

🖥️ How to Run

Copy the code into a file named brt_linkedlist.cpp.

Compile using any C++ compiler:

g++ brt_linkedlist.cpp -o brt


Run the executable:

./brt

📚 Learning Outcome

By completing this lab task, you’ll learn:

How to create, traverse, and manipulate linked lists.

How dynamic nodes can represent real-world queue systems.

How to manage memory safely in C++ using destructors.
