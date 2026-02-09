# Lab 5: Random Particle Simulation with Pointers

## Introduction
In this exercise, you will simulate a simple 1D particle system using pointers in C.  
Each particle can move randomly either left or right at each discrete time step.  
You will practice:

- Using pointers to manipulate arrays
- Pointer dereferencing and pointer arithmetic
- Handling collisions
- Implementing a discrete-time simulation

## Requirements

1. Create an integer array initialized with zeros.
2. Place **three particles** at positions 2, 4, and 6 (set array values to 1 at these indices).
Note: If you place the particles with an odd distance, the will never collide.
3. Create a pointer pointing to the first element of the array.
4. Create a **temporary array** and a pointer to it to help you create and store the next state of the simulation.
5. Simulate in **discrete time steps**. For each step:
   - Print the current field (1 for particle, 0 for empty).
   - Move each particle randomly to the left or right by one cell.
   - Ensure particles **do not move out of bounds** but stay at the edge of the field.
   - If multiple particles move into the same cell, remove them (set cell to 0).
6. Do **not** use structs or additional functions; keep everything in `main`.
7. Use `<stdlib.h>` and `<time.h>` for random number generation.

## Example

Time 0: 0 0 1 0 1 0 1 0 0 0 

Time 1: 0 1 0 0 0 1 0 1 0 0

Collision on index 6

Time 2: 0 0 1 0 0 0 0 0 0 0

Time 3: 0 1 0 0 0 0 0 0 0 0


## Hints

- Use pointer dereferencing: `*(p_field + i)` to access elements.
- Use pointer arithmetic for both reading and writing.
- Generate random movement with `(rand() % 2)`.
- Ensure random numbers with `srand(time(NULL))`.
- Handle collisions after all movements are applied.

