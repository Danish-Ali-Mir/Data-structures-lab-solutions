Music Player with Previous Track Feature (C++ Project)

This project demonstrates a simple Music Player implemented in C++ using a stack-like linked list.
The player keeps track of previously played songs and allows the user to jump back through the history of tracks.

🎵 Features

Plays tracks in sequence.

Saves the previously played track automatically.

Allows going back to earlier tracks using playPrevious().

Uses a linked-list stack (no STL containers).

Simple and easy-to-understand implementation.

🧠 How It Works

The logic simulates a "previous tracks" list:

When a new track plays:

If a current track exists, it is pushed onto the stack.

The new track becomes the current track.

When playPrevious() is called:

The most recently played track is popped from the stack.

It becomes the current track.

The stack is built manually using a linked list where:

Each node stores a track name.

top represents the most recent previous track.

📂 Code Structure
Component	Description
Node struct	Defines a linked-list node storing a track name
MusicPlayer class	Implements play, history stack, and previous-track navigation
main()	Demonstrates playing 3 tracks and going back through history
🚀 Usage

Example sequence inside main():

player.playTrack("Bohemian Rhapsody");
player.playTrack("Stairway to Heaven");
player.playTrack("Hotel California");

player.playPrevious(); // Plays "Stairway to Heaven"
player.playPrevious(); // Plays "Bohemian Rhapsody"
player.playPrevious(); // No previous tracks left

🛠 How to Run

Save the file as main.cpp

Compile:

g++ main.cpp -o music


Run:

./music

📘 Example Output
Now playing: Bohemian Rhapsody
Now playing: Stairway to Heaven
Now playing: Hotel California
Now playing: Stairway to Heaven
Now playing: Bohemian Rhapsody
No previous tracks.

✅ Summary

This program gives you hands-on experience with:

Linked list operations

Stack behavior (LIFO)

Basic memory management

Simulation of a music player history feature

You can extend it by adding:

“Next track” support

Playlist loading

Track deletion

A complete UI system
