# 🧮 Design and Analysis of Algorithms Lab (Practicals 5–8)

## 📘 Practical 5 – Dynamic Programming Problems: LCS & LRS
This section contains C++ implementations of two classic dynamic programming problems.

### Longest Common Subsequence (LCS)
- **Problem:** Find the length of the longest subsequence common to both given strings.
- A subsequence is formed by deleting some (or none) characters without changing the relative order.
- If no common subsequence exists, the output is `0`.

### Longest Repeating Subsequence (LRS)
- **Problem:** Find the longest subsequence which appears at least twice in the same string.
- The two subsequences must not have the same character indices in the original string.

🔗 **LeetCode Link:** [Longest Repeating Subsequence](https://leetcode.com/problems/longest-repeating-subsequence/)

**Language:** C++ (Dynamic Programming)

---

## 🚚 Practical 6 – Single Source Shortest Path (Bellman-Ford)

**Aim:** Construction of Single Source Shortest Path

**Problem Statement:**  
Develop a system to optimize delivery routes for a fleet of vehicles in a metropolitan area.  
The system calculates the shortest paths between multiple pickup and delivery points,  
considering traffic congestion and road conditions.

### Key Features
- Implements **Bellman-Ford Algorithm** to find the shortest route from a **central depot (Zero Mile)**.  
- Uses **latitude and longitude** of real addresses within the same city to form a fully connected graph.  
- Ensures all computed distances are **non-negative**.  
- Detects and reports any **negative weight cycles**.  
- Displays shortest path distances (in kilometers) from the pickup point to each delivery location.

**Language:** C++  
**Concepts Used:** Graphs, Shortest Path, Haversine Distance Formula

---

## 📚 Practical 7 – Smart Library Search Optimization (Optimal BST)

**Aim:** Construction of an Optimal Binary Search Tree (OBST)

**Problem Statement:**  
A university digital library system stores book IDs using a binary search structure.  
To minimize the average search time for book lookups, the system constructs an **Optimal Binary Search Tree (OBST)**  
based on the probabilities of successful and unsuccessful searches.

### Input Format
- `n`: number of book IDs  
- Sorted book IDs (keys)  
- Probabilities of successful searches `p[i]`  
- Probabilities of unsuccessful searches `q[i]`

### Output Format
- Minimum expected search cost of the Optimal BST (rounded to 4 decimal places)

🔗 **Reference:** [GeeksforGeeks – Optimal Binary Search Tree Problem](https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1)

**Language:** C++  
**Concept Used:** Dynamic Programming

---

## 🧰 Language & Tools
- **Language:** C++  
- **Paradigm:** Dynamic Programming & Graph Algorithms  
- **Environment:** Visual Studio Code / Dev-C++ / Any C++17 compiler  

---

## 📁 Repository
**GitHub Repo:** [DAA_LAB_P5-8](https://github.com/Mayank3969/DAA_LAB_P5-8)  

Contains source codes and documentation for Practicals **5 to 8**  
of the **Design and Analysis of Algorithms Laboratory (CSE, RCOEM)**.
