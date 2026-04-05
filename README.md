# Data Structures & Algorithms (DSA) - C++ Implementation

A comprehensive collection of Data Structures and Algorithms implemented in C++. This repository covers fundamental DSA concepts with working code examples and detailed explanations.

---

## 📚 Topics Covered

### 1. [Pointers](1-Pointers/)

Understanding pointers - memory addresses, pointer operations, and practical applications.

**Files:**

- [pointer_basics.cpp](1-Pointers/pointer_basics.cpp) - Pointer declaration, initialization, and fundamental operations
- [pointer_arithmetic.cpp](1-Pointers/pointer_arithmetic.cpp) - Advanced pointer concepts and operations

**Concepts:** Pointer declaration, address-of operator (&), dereference operator (\*), pointer arithmetic, memory management

---

### 2. [Linked Lists](2-LinkedLists/)

Implementation of linked list data structures with various operations like insertion, deletion, and traversal.

**Files:**

- [singly_linked_list.cpp](2-LinkedLists/singly_linked_list.cpp) - Singly Linked List with insert, display, search, and reverse operations
- [doubly_linked_list.cpp](2-LinkedLists/doubly_linked_list.cpp) - Doubly Linked List with insert operations and two-directional navigation
- [circular.cpp](2-LinkedLists/circular.cpp) - Circular Linked List implementation

**Concepts:** Node structure, singly/doubly linked lists, circular lists, insertion/deletion, traversal, memory management

---

### 3. [Hashing](3-Hashing/)

Hash table and hashing techniques implementation. Multiple collision handling approaches.

**Files:**

- [hash_basic.cpp](3-Hashing/hash_basic.cpp) - Basic hash function using modulo operation
- [hash_linear_probing.cpp](3-Hashing/hash_linear_probing.cpp) - Linear probing collision handling
- [hash_quadratic_probing.cpp](3-Hashing/hash_quadratic_probing.cpp) - Quadratic probing collision handling
- [hash_separate_chaining.cpp](3-Hashing/hash_separate_chaining.cpp) - Separate chaining using linked lists
- [hash_double_hashing.cpp](3-Hashing/hash_double_hashing.cpp) - Double hashing approach

**Concepts:** Hash functions, hash tables, collision handling (linear probing, quadratic probing, separate chaining), load factors

---

### 4. [Data Structures](4-DataStructures/)

Complex data structures combining multiple linked lists and hierarchical relationships.

**Files:**

- [multi_level_linked_list.cpp](4-DataStructures/multi_level_linked_list.cpp) - Multi-level linked lists with hierarchical node relationships

**Concepts:** Multi-level lists, nested structures, multiple pointer chains, hierarchical data organization

---

### 5. [Object-Oriented Programming (OOP)](5-OOP/)

OOP concepts in C++ including encapsulation, data hiding, and class design principles.

**Files:**

- [encapsulation.cpp](5-OOP/encapsulation.cpp) - Encapsulation, data hiding, public/private members, getters/setters

**Concepts:** Class definition, public/private members, encapsulation, data hiding, access control, abstraction

---

### 6. [Arrays & Basics](6-Arrays-Basics/)

Array operations and fundamental revision exercises. Basic DSA concept review.

**Files:**

- [array_basics.cpp](6-Arrays-Basics/array_basics.cpp) - Array operations and basic DSA concepts with OOP applications
- [linear_search.cpp](6-Arrays-Basics/linear_search.cpp) - Linear search algorithm implementation

**Concepts:** Array declaration, traversal, manipulation, linear search, basic algorithm implementations

---

### 7. [Searching & Sorting](7-Searching-and-Sorting/)

Implementation of searching and sorting algorithms with various approaches.

**Files:**

- [binary_search.cpp](7-Searching-and-Sorting/binary_search.cpp) - Binary search (iterative/recursive) for sorted arrays
- [binary2.cpp](7-Searching-and-Sorting/binary2.cpp) - Alternative binary search implementation
- [merge_sort.cpp](7-Searching-and-Sorting/merge_sort.cpp) - Merge sort using divide and conquer
- [quick_sort.cpp](7-Searching-and-Sorting/quick_sort.cpp) - Quick sort with last element pivot
- [quick_sort_mid_pivot.cpp](7-Searching-and-Sorting/quick_sort_mid_pivot.cpp) - Quick sort with middle element pivot
- [bubblesort.cpp](7-Searching-and-Sorting/bubblesort.cpp) - Bubble sort implementation
- [insertionsort.cpp](7-Searching-and-Sorting/insertionsort.cpp) - Insertion sort implementation
- [iselectionsort.cpp](7-Searching-and-Sorting/iselectionsort.cpp) - Selection sort implementation
- [stablevsunstable.cpp](7-Searching-and-Sorting/stablevsunstable.cpp) - Comparison of stable vs unstable sorting algorithms

**Concepts:** Linear search, binary search, merge sort, quick sort, bubble sort, insertion sort, selection sort, divide & conquer, time/space complexity analysis, pivot selection

---

### 8. [Trees](8-%20Trees/)

Tree data structures and tree traversal algorithms.

**Files:**

- [Binarytree.cpp](8-%20Trees/Binarytree.cpp) - Binary tree implementation
- [binarysearchtree.cpp](8-%20Trees/binarysearchtree.cpp) - Binary Search Tree (BST) implementation
- [AVL075.cpp](8-%20Trees/AVL075.cpp) - AVL tree (self-balancing BST) implementation
- [infixtopostix.cpp](8-%20Trees/infixtopostix.cpp) - Infix to postfix expression conversion using trees

**Concepts:** Binary trees, BST operations, tree traversal, AVL trees, self-balancing, expression trees

---

### 9. [Stack](9-Stack/)

Stack data structure and related algorithms.

**Files:**

- [stack.cpp](9-Stack/stack.cpp) - Stack implementation with push, pop, and basic operations

**Concepts:** LIFO (Last-In-First-Out), stack operations, applications (expression evaluation, backtracking)

---

### 10. [Queue](10-Queue/)

Queue data structures with different implementations.

**Files:**

- [simplequeue.cpp](10-Queue/simplequeue.cpp) - Simple queue implementation
- [circularqueue.cpp](10-Queue/circularqueue.cpp) - Circular queue implementation

**Concepts:** FIFO (First-In-First-Out), queue operations, circular queues, memory optimization

---

## 🚀 How to Compile and Run

### General Compilation

```bash
g++ -o output_name filename.cpp
./output_name.exe
```

### Example

```bash
# Navigate to the desired folder
cd 1-Pointers

# Compile
g++ -o pointer_basics pointer_basics.cpp

# Run
./pointer_basics.exe
```

---

## 📝 Topics Summary

| Topic               | Difficulty            | Files | Key Concepts                       |
| ------------------- | --------------------- | ----- | ---------------------------------- |
| Pointers            | Beginner              | 2     | Memory, addresses, operations      |
| Linked Lists        | Beginner-Intermediate | 3     | Dynamic structures, traversal      |
| Hashing             | Intermediate          | 5     | Hash functions, collision handling |
| Data Structures     | Intermediate          | 1     | Multi-level relationships          |
| OOP                 | Beginner-Intermediate | 1     | Classes, encapsulation             |
| Arrays & Basics     | Beginner              | 2     | Array operations, search           |
| Searching & Sorting | Intermediate          | 9     | Algorithms, complexity analysis    |
| Trees               | Intermediate-Advanced | 4     | Binary trees, BST, AVL             |
| Stack               | Beginner-Intermediate | 1     | LIFO, applications                 |
| Queue               | Beginner-Intermediate | 2     | FIFO, circular implementation      |

---

## 💡 Learning Path

**Recommended Order:**

1. Start with **Pointers** - foundation for understanding memory
2. Learn **Arrays & Basics** - fundamental data structure
3. Explore **Linked Lists** - dynamic data structures
4. Study **Searching & Sorting** - essential algorithms
5. Understand **Stack & Queue** - important abstract data types
6. Learn **Trees** - hierarchical structures
7. Study **Hashing** - advanced searching technique
8. Explore **Data Structures** - complex combinations
9. Master **OOP** - encapsulation and design principles

---

## 📖 Resources

- Each folder contains implementations with complete working code
- Concepts are documented for each file
- Compilation instructions are provided for easy testing
- Examples demonstrate both theoretical concepts and practical applications

---

## 🎯 Purpose

This repository serves as:

- A learning resource for DSA fundamentals in C++
- A reference for implementation patterns
- Practice material for interview preparation
- A foundation for advanced data structure courses

---

**Happy Learning! 🚀**
