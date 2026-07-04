# LRU Cache Simulator

A C++ implementation of an **LRU (Least Recently Used) Cache** using a **Hash Map (`unordered_map`)** and **Doubly Linked List**.

## Features

- Insert Key-Value Pair
- Retrieve Value by Key
- Automatic LRU Eviction
- Display Current Cache
- Menu-Driven Interface

---

## Technologies Used

- C++
- STL
- Hash Map (`unordered_map`)
- Doubly Linked List

---

## Time Complexity

| Operation | Complexity |
|----------|------------|
| Put | O(1) |
| Get | O(1) |
| Display | O(n) |

---

## How to Run

```bash
clang++ main.cpp -o lru
./lru
```

---

## Sample Output

```
===== LRU Cache Simulator =====

1. Put
2. Get
3. Display Cache
4. Exit

Most Recently Used --> Least Recently Used
[4 : D] [2 : B] [3 : C]
```

---
