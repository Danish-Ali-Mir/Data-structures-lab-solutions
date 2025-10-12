🎽 Code-a-Thon T-Shirt Queue Management System
📘 Overview

The Code-a-Thon T-Shirt Queue Management System is a console-based C++ application designed to manage the queue of students waiting to receive T-shirts at a university event.
It ensures fair, first-come, first-served distribution using a linked list–based queue implementation.

🧠 Objective

To develop an efficient and interactive queue system that:

Manages student entries dynamically

Serves students in FIFO (First-In, First-Out) order

Allows students to leave voluntarily

Displays the current queue status

Tracks the total number of participants

⚙️ Features

Add Student: Enter a student’s name and ID to join the queue

Serve Student: Serve and remove the first student in line

Student Leaves: Remove a specific student from the queue by ID

Display Queue: View all students currently waiting

Count Students: Show the total number of students in queue

🧩 Data Structure Used

The program uses a Linked List to represent the queue.
Each Node stores:

name — the student’s name

id — the student’s unique ID

next — pointer to the next student in the queue

This approach allows dynamic memory management and efficient insertion/removal operations.

💻 Class Structure
Node

Represents a single student in the queue.

struct Node {
    string name;
    int id;
    Node* next;
    Node(string n, int i);
};

TShirtQueue

Encapsulates all queue operations.

class TShirtQueue {
private:
    Node* front;
    Node* rear;
    int count;
public:
    void addStudent();
    void serveStudent();
    void studentLeaves();
    void displayQueue();
    void countStudents();
};

🧭 Program Flow

Start the program

Choose from the displayed menu options

Perform queue operations (Add, Serve, Remove, Display, Count)

Exit when done — all memory is automatically released

🖥️ Sample Output
====== Code-a-Thon T-Shirt Queue ======
1. Add Student
2. Serve Student
3. Student Leaves Queue
4. Display Queue
5. Count Students
6. Exit
Choose an option: 1
Enter Student Name: Ali
Enter Student ID: 101
Ali has joined the queue.

📊 Algorithm Summary

Enqueue (Add Student): Add new node at the rear

Dequeue (Serve Student): Remove node from the front

Delete by ID: Search and remove specific node

Display: Traverse and print each node

Count: Return the total number of nodes

🧾 Example Use Case

At a Code-a-Thon event, the first 100 participants receive free T-shirts.
This system ensures:

Orderly queue management

No skipping or duplication

Accurate participant tracking

🧰 Technologies Used

Language: C++

Concepts: OOP, Linked List, Queue, Dynamic Memory

🏁 Conclusion

The Code-a-Thon T-Shirt Queue Management System efficiently demonstrates queue operations using linked lists in C++.
It provides a real-world example of applying data structures for event organization and resource distribution.
