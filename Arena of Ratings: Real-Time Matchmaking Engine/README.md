ArenaBST – Player Management System

Author: DANISH ALI MIR
Language: C++
Description:
ArenaBST is a C++ program implementing a Binary Search Tree (BST) to manage players in an arena, where each player has a unique rating, name, and health points (HP). The program supports joining/leaving the arena, updating HP, querying player statistics, finding nearest opponents, and various BST-based operations efficiently.

Features

Player Management

JOIN r name hp: Add a player with rating r, name name, and HP hp. Duplicate ratings are rejected.

LEAVE r: Remove the player with rating r.

STATUS r: Display rating, name, and HP of a player, or NOT FOUND if missing.

DAMAGE r d: Reduce a player’s HP by d (minimum HP = 0).

HEAL r h: Increase a player’s HP by h.

Navigation & Opponent Queries

NEXT X: Find the player with the smallest rating strictly greater than X.

PREV X: Find the player with the largest rating strictly less than X.

MATCH X: Find the closest-rated player to X. Ties favor the predecessor.

Range & Statistical Queries

RANGE L R: Print all players with ratings in [L, R] in sorted order.

STATS: Print arena statistics:

SIZE: Total number of players

MIN / MAX: Players with minimum and maximum rating

HEIGHT: Height of the BST

LEAVES: Number of leaf nodes

RANK X: Number of players with rating strictly less than X.

KTH k: Player with the k-th smallest rating.

Duel & Distance Queries

DUEL A B: Computes the number of edges between two players in the BST.

Data Structure

BST Node (Node):

rating (unique integer)

name (string)

hp (long long)

left, right pointers

sz: Size of subtree rooted at this node (for KTH queries)

BST Class (ArenaBST):

Stores the root of the BST.

Supports recursive insertion, deletion, successor/predecessor search, rank, KTH, LCA, and depth queries.

Implementation Details

Duplicate ratings are not allowed.

All queries are designed to run efficiently using BST properties.

KTH queries are 1-indexed and use subtree sizes for O(log n) access.

DUEL uses Lowest Common Ancestor (LCA) and depth to compute edge distance.

In-order traversal is used for RANGE queries to maintain sorted order.

Node deletion uses the inorder successor strategy for nodes with two children.

Input Format

First line: Q – Number of queries.

Next Q lines: Each query in one of the formats:

JOIN r name hp

LEAVE r

STATUS r

DAMAGE r d

HEAL r h

NEXT X

PREV X

MATCH X

RANGE L R

STATS

RANK X

KTH k

DUEL A B

Example Input:

6
JOIN 100 Alice 500
JOIN 120 Bob 300
STATUS 100
DAMAGE 120 50
MATCH 110
STATS

Example Output
JOINED
JOINED
100 Alice 500
DAMAGED 250
100 Alice 500
SIZE 2
MIN 100 Alice 500
MAX 120 Bob 250
HEIGHT 1
LEAVES 2

Compilation & Execution

Compile:

g++ -std=c++17 -O2 -o arena ArenaBST.cpp


Run:

./arena < input.txt


or interactively:

./arena

Notes

Efficient for large numbers of players due to BST operations.

All player operations are based on unique ratings.

Supports real-time updates like HP damage/heal and dynamic queries.

Provides detailed arena statistics for strategic insights.
