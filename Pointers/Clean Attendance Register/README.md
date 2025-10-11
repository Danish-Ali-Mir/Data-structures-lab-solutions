📌 Clean Attendance Register
📖 Description

This program manages the attendance of participants in a workshop.
It dynamically allocates memory to store each participant’s attendance status, where:

0 = Absent

1 = Present

By default, all participants are marked absent, and the user can update the attendance by marking selected participants as present. Finally, the program displays the complete attendance register.

⚙️ Features

Ask the user for the number of participants.

Dynamically allocate memory for attendance using calloc.

Initialize all participants as absent (0).

Allow the user to mark selected participants as present (1).

Display the final attendance register in a clean format.

Free the dynamically allocated memory at the end.

🖥️ Example Run
Enter the number of participants: 5
Enter the number of students present: 2
Enter the numbers of students who are present (1 to 5):
2 5

Final Attendance Register:
Participant 1: Absent
Participant 2: Present
Participant 3: Absent
Participant 4: Absent
Participant 5: Present

🛠️ Concepts Used

Dynamic memory allocation (calloc, free).

Pointers in C++.

Loops (for).

Conditional checks (if-else).

🚀 How to Run

Copy the code into a file named attendance.cpp.

Compile using any C++ compiler (e.g., g++, DevC++).

g++ attendance.cpp -o attendance


Run the program:

./attendance
