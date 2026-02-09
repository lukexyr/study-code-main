# Lab 7: Playlist Manager

## Introduction
In this lab exercise, you will implement a simple music playlist manager using the C programming language.  
The goal of this assignment is to practice working with:

- `struct` data types
- pointers
- dynamic memory allocation (`malloc`, `free`)
- singly linked lists

The playlist is implemented as a linked list where each element represents a song consisting of a title and an artist.

## Requirements

Your program must fulfill the following requirements:

### Data Structures

1. Define a structure `Song` that contains:
   - a dynamically allocated string for the song title
   - a dynamically allocated string for the artist name
   - a pointer to the next song in the playlist

2. Define a structure `Playlist` that contains:
   - a pointer to the first song in the playlist

---

### Functions

Implement at least the following functions:

- `init_playlist`  
  Initializes an empty playlist.

- `add_song`  
  Adds a new song to the end of the playlist.  
  Memory for the song structure and its strings must be allocated dynamically.

- `print_playlist`  
  Prints all songs in the playlist in the following format:
  
  Title: __title__, Artist: __artist__

- `delete_firstSong`  
Removes the first song from the playlist and frees all allocated memory.

- `delete_playlist`  
Removes all songs from the playlist and frees all allocated memory.

---

### Main Program

In the `main` function, demonstrate the functionality of your program by:

1. Creating and initializing a playlist
2. Adding multiple songs to the playlist
3. Printing the playlist
4. Deleting the first song
5. Printing the playlist again
6. Deleting the complete playlist

## Example

Title: Crawling, Artist: Linkin Park
Title: Layla, Artist: Eric Clapton
Title: Esperanto, Artist: Max Herre

## Hints

- Use only standard C libraries:
  - `<stdio.h>`
  - `<stdlib.h>`
  - `<string.h>`
- Always free dynamically allocated memory to avoid memory leaks
- Check the return value of `malloc` before using allocated memory
- Keep your code modular by separating functionality into functions
- Use meaningful variable and function names
- Optional extensions:
  - delete a song by title
  - count the number of songs in the playlist
  - insert a song at a specific position in the playlist

