# Hashing

Examples of hash table construction and collision resolution.

## Files

- hash_basic.cpp: basic hashing with modulo indexing
- hash_linear_probing.cpp: open addressing with linear probing
- hash_quadratic_probing.cpp: open addressing with quadratic probing
- hash_separate_chaining.cpp: collision handling with chaining
- hash_double_hashing.cpp: collision handling with double hashing

## Compile and Run

```bash
g++ -std=c++17 -g hash_basic.cpp -o hash_basic.exe
./hash_basic.exe

g++ -std=c++17 -g hash_linear_probing.cpp -o hash_linear_probing.exe
./hash_linear_probing.exe

g++ -std=c++17 -g hash_quadratic_probing.cpp -o hash_quadratic_probing.exe
./hash_quadratic_probing.exe

g++ -std=c++17 -g hash_separate_chaining.cpp -o hash_separate_chaining.exe
./hash_separate_chaining.exe

g++ -std=c++17 -g hash_double_hashing.cpp -o hash_double_hashing.exe
./hash_double_hashing.exe
```

## Concepts Covered

- hash functions and indexing
- collision-resolution techniques
- probing vs chaining trade-offs
