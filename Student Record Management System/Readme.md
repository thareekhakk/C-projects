# Student Record Management System

A modular, CLI-based Student Record Management System implemented in C using singly linked lists, dynamic memory allocation, and persistent file handling.

---

## Overview

The application manages student records dynamically in memory. It supports operations such as inserting records with automatic roll number generation, searching, updating, sorting, in-place pointer reversal, and file storage.

---

## Features

- **Dynamic Memory Allocation**: Every student record is allocated dynamically using `malloc()` and freed using `free()`.
- **Automatic Roll Number Assignment**: Assigns the lowest available positive integer not currently in use (reclaiming unused or previously deleted IDs).
- **Persistent Storage**: Saves records to and loads records from `student.dat`.
- **List Operations**:
  - Add new records with validation (percentage must be within `0.00` to `100.00`).
  - Search and delete records by roll number or name (handles duplicate names gracefully).
  - Search and modify records by roll number, name, or percentage.
  - Sort records alphabetically by name or descending by percentage.
  - Reverse the singly linked list using pointer reassignment.
  - Delete all records and release memory cleanly on exit.

---

## Project Structure

```text
.
├── Makefile        # Compilation instructions
├── README.md       # Project documentation
├── student.h       # Structure definitions and function prototypes
├── stud_main.c     # Application entry point and menu-driven loop
├── stud_add.c      # Node creation and insertion logic
├── stud_del.c      # Record deletion (single node and delete all)
├── stud_show.c     # Tabular display and node counting
├── stud_mod.c      # Record search and modification
├── stud_save.c     # File I/O (load on boot, save to student.dat)
└── stud_sort.c     # Link reversal and bubble sorting
