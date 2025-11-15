Hospital Emergency Room Management (C++ Project)

This project simulates a simple Hospital Emergency Room System using a doubly linked list.
Patients (mariz) are assigned IDs and placed in a queue where they can be added, viewed, or removed based on priority and position.

🏥 Features

Add new patients at the start, end, or a specific position.

Remove the next patient to be treated from the start.

Display the queue of patients from start to end or end to start.

Fully manual doubly linked list implementation.

Clear demonstration of pointer handling and node linking.

🧠 How It Works

Each patient is stored as a Node containing:

marizID → patient’s ID

next → pointer to next patient

prev → pointer to previous patient

The HospitalSystem class maintains two pointers:

head → first patient

tail → last patient

✔ Insert at Head

For high-priority or emergency patients.

✔ Insert at Tail

When patients enter normally.

✔ Insert at a Position

Places the new patient before the given position.

✔ Delete from Start

Simulates the next patient being treated and removed.

✔ Print Forward & Backward

Uses the doubly linked structure to show the queue in both directions.

📂 Code Components
Component	Description
Node struct	Represents a patient in the linked list
HospitalSystem class	Handles adding, removing, and displaying patients
main()	Sample operations showing typical usage of the system
🚀 Usage Example

The main() function demonstrates operations:

sys.insertATtail(101);
sys.insertATtail(102);
sys.insertAThead(200);
sys.insertatPOS(150,2);

sys.PrintMarizFROMstart();
sys.PrintMarizFROMend();

sys.deleteFROMstart();

sys.insertATtail(300);

📘 Example Output
Start se : 200<->150<->101<->102<-Tail
End se :102<->101<->150<->200<-Head

removed mariz: 200
Start se : 150<->101<->102<-Tail

Start se : 150<->101<->102<->300<-Tail
End se :300<->102<->101<->150<-Head

✅ Summary

This project helps build strong understanding of:

Doubly linked list operations

Pointer relationships

Node insertion at various positions

Queue-like structures for real-life systems

Possible Enhancements:

Remove patient from the tail

Search for a patient

Edit patient information

Menu-driven interface for user interaction
