📘 Custom Score Tracker
📌 Overview

This program is a simple sports score tracker built in C++.
It demonstrates how to use dynamic memory allocation with calloc to store player scores when the number of players is only known at runtime.

The program asks the user for the number of players, allocates memory dynamically, stores their scores, displays them, and finally releases the allocated memory.

🛠 Features

Asks the user how many players are participating.

Dynamically allocates memory using calloc.

Accepts input scores for each player.

Displays all players’ scores in a clean format.

Frees the allocated memory after use to prevent memory leaks.

📂 How It Works

User enters the number of players.

Memory is allocated using:

int* scores = (int*)calloc(nplayers, sizeof(int));


calloc initializes all values to 0 by default.

Scores are taken as input and stored in the dynamically allocated array.

Scores are displayed with proper formatting.

Memory is released using:

free(scores);

▶️ Example Run
Enter the number of players: 3
Enter score of player 1: 25
Enter score of player 2: 30
Enter score of player 3: 18

--- End of the Tournament Scores ---
Player 1 Score: 25
Player 2 Score: 30
Player 3 Score: 18

🧾 Notes

calloc is used instead of malloc because it initializes allocated memory with zeros.

Always check if memory allocation is successful (if (scores == nullptr)).

Always free dynamically allocated memory at the end of the program.
