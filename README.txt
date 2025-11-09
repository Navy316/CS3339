#CS3339 - Homework 3: Cache Simulator

**Team Members:** 
Bryce Gill  
 

Date Due: Friday, Nov 7th 11:59 PM (Fall 2025)

1. Description

This program implements a basic cache simulator based on the configuration parameters and a sequence of memory references provided as input. The simulator determines whether each memory reference results in a HIT or a MISS.

- Assumptions based on assignment guidelines:
*   The cache is initially empty (all entries are invalid) [2].
*   Each cache entry/block holds only one word [2].
*   Input addresses are specified as word addresses [2].
*   Replacement Policy: Simple Round-Robin (FIFO approximation) is used when a set is full and a miss occurs, as complex LRU tracking was not required [1].

 2. Building the Code

The code is written in C++ (`cache_sim.cpp`). To compile the program, use a standard C++ compiler (like g++):

```bash
g++ cache_sim.cpp -o cache_sim

3. Running the Simulator
The compiled program (cache_sim) must be invoked with four arguments (the program name, a placeholder argument, total number of entries, associativity, and the input file name).
Command Syntax:
./cache_sim [PLACEHOLDER] num_entries associativity input_memory_reference_file
Ex: 
./cache_sim sim 4 2 input0.txt

4. Output
The simulator writes the output to a file named cache_sim_output.

The resulting cache_sim_output file format will look like:
1 : MISS
3 : MISS
5 : MISS
1 : MISS
3 : MISS
1 : HIT