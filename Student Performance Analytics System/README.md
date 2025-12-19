📘 Student Performance Analytics System
📌 Project Overview

The Student Performance Analytics System is a C++ program developed for analyzing academic performance data of university students.
It reads student records from a text file, stores them using dynamic memory allocation with a singly linked list, and generates multiple analytical reports based on different sorting and grouping criteria.

The system is designed to work entirely with file input/output, ensuring data integrity and modular processing.

🎯 Objectives

Read student academic records from a text file

Store records dynamically using a linked list

Perform multi-criteria sorting and analysis

Generate professional, well-formatted report files

Ensure proper memory management (no leaks)

📥 Input File
File Name
students_data.txt

Format

Each line represents one student record:

<StudentID> <FirstName> <LastName> <Department> <Semester> <CGPA> <Credits> <EnrollmentYear>

Example
202301 Alice Johnson CSE 5 3.85 142 2020
202145 Bob Smith EEE 6 3.92 168 2019
203012 Charlie Brown MEC 3 3.45 89 2022

🗂 Data Structure Used

Singly Linked List

Each node contains:

Student ID

Student Name

Department Code

Semester

CGPA

Credit Hours

Enrollment Year

Pointer to next node

Dynamic memory (new / delete) is used throughout the program.

🧠 Sorting Algorithms Used
Purpose	Algorithm	Time Complexity
CGPA ranking	Selection Sort	O(n²)
Enrollment year sorting	Selection Sort	O(n²)
Department analysis	Selection Sort	O(n²)
Name-based tier sorting	Insertion Sort	O(n²)

Two different comparison-based sorting algorithms are implemented as required.

📄 Output Files Generated
1️⃣ ranked_by_cgpa.txt

Students ranked by CGPA (descending)

Tie-breaker: Credit hours (descending)

Includes ranking numbers

Displayed in a formatted table

2️⃣ sorted_by_enrollment.txt

Students sorted by Enrollment Year (ascending)

Within the same year: Student ID (ascending)

Separate sections per year

Displays average CGPA per year

3️⃣ department_analysis.txt

Students grouped by Department (alphabetical)

Sorted by:

Semester (ascending)

CGPA (descending)

Department-wise statistics:

Total students

Average CGPA

Highest & lowest CGPA

Average credit hours

4️⃣ performance_tiers.txt

Students categorized into performance tiers:

Tier	CGPA Range
Elite	≥ 3.70
High Achievers	3.30 – 3.69
Good Standing	3.00 – 3.29
Satisfactory	2.50 – 2.99
Needs Improvement	< 2.50

Students sorted alphabetically by name within each tier

Displays count and percentage per tier

⚠ Data Validation

Invalid records are skipped:

CGPA not in 0.00 – 4.00

Semester not in 1 – 8

Invalid entries are logged in:

data_issues.txt

🧹 Memory Management

All dynamically allocated nodes are properly deallocated

No memory leaks

Original linked list is preserved during sorting (copies are used)

▶ Compilation & Execution
Compile
g++ main.cpp -o analytics

Run
./analytics

⏱ Performance Analysis

Overall time complexity: O(n²)

Suitable for small to medium datasets (up to a few thousand records)

Not intended for very large datasets (e.g., 100,000+ records)

📝 Assumptions

Input file is space-separated

Student names consist of first and last name

Department codes are exactly 3 characters

Academic dataset size is reasonable (as per academic requirements)

🏁 Conclusion

This project demonstrates effective use of:

Linked lists

Dynamic memory allocation

File handling

Sorting algorithms

Modular program design
