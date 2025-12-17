# Sorting Algorithms Time Comparison (C++)

## Overview

This program reads a large list of integers from a file and compares the execution time of **Bubble Sort** and **Selection Sort**. The goal is to analyze the performance difference between the two sorting algorithms using the same dataset.

---

## Features

* Reads integers from a file (`numbers.txt`)
* Stores data in dynamically allocated arrays
* Implements:

  * Optimized Bubble Sort (early exit if already sorted)
  * Selection Sort
* Measures execution time using `chrono`
* Displays time taken by each sorting algorithm in milliseconds

---

## Input File Format

The input file must be named **`numbers.txt`** and should contain integers separated by commas.

Example:

```
10,45,23,89,12,7,34
```

---

## How the Program Works

1. Opens and reads the entire line from `numbers.txt`
2. Counts how many numbers are present
3. Stores the numbers in two separate arrays
4. Sorts one array using Bubble Sort
5. Sorts the second array using Selection Sort
6. Measures and prints the time taken by each algorithm

---

## Sample Output

```
Bubble Sort: 4 milliseconds
Selection Sort: 13 milliseconds
```

(Actual time may vary depending on system performance and input size.)

---

## Requirements

* C++11 or later
* A compiler such as `g++`
* `numbers.txt` file in the same directory as the program

---

## Notes

* Bubble Sort is optimized using a swap-check mechanism
* Selection Sort always performs the same number of comparisons
* Dynamic memory is properly released to avoid memory leaks

---

## Purpose

This program is designed for academic and learning purposes to demonstrate:

* File handling in C++
* Sorting algorithms
* Time complexity comparison
* Performance measurement using modern C++ features

---

## Author

Student Project
