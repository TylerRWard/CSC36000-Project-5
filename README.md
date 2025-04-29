# CSC36000-Project-5
---
## Project Details

- **Name**: Tyler Ward  
- **Date**: April 27, 2025  
- **Platform**: macOS 
- **Errors**: None that I know of

---

## Summary
 This project implements a solution to find the minimum cost set of doors to ensure all rooms in a house are reachable from each other. The problem is modeled as finding the minimum spanning tree of a graph using Kruskal's algorithm.
 The code is modularized with the UnionFind class separated into a header and implementation file.
 The program is optimized to meet the O(m log m) time complexity requirement.
 This program uses an unordered map to associate each room name with a unique integer index.
---

# Compilation
```bash
g++ -std=c++20 proj5.cpp union_find.cpp -o proj5

./proj5 <input_file>

```