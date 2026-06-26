```markdown
#Student Management System (C-CLI)

A lightweight, robust, and completely modular command-line application built in C to manage student data and calculate high-level performance analytics. 

This repository serves as an excellent demonstration of **clean architecture** in low-level programming by cleanly decoupling structure schemas, analytical processing, and application control flow into independent modules.

---

##Repository Structure

The project is structured modularly to avoid monolithic file issues and to encourage maintainable scalability:

```text
├── main.c           # Application entry point & interactive loop controller
├── student.h        # Student data structure configuration & user prototypes
├── student.c        # Logic implementations for user entry, search, & table views
├── statistics.h     # Analytics engine definitions & math prototypes
└── statistics.c     # Data processing algorithms (mean calculations & bounds tracking)

```

---

## Key Features & Architectural Mechanics

* **Robust Buffer Cleansing:** Utilizes safe string handling via `fgets` and cleanly strips trailing newlines (`\n`) using `strcspn` to completely avoid memory corruption and buffer overflows.
* **Input Stream Sanitization:** Protects the command-line interface from dropping into infinite loops or crashing if non-numeric string data (like letters) is supplied to integer menus.
* **Dynamic Record Tagging:** Automatically tracks counts and issues sequentially unique, incremental database IDs (`1, 2, 3...`) as new student metrics are mapped.
* **Tabular Data Formatting:** Implements strict layout metrics (`%-5d %-32s %.2f`) to cleanly align text in a uniform matrix resembling an Excel database spreadsheet.
* **Fail-Safe Analytics Engine:** Computes dataset statistics safely; handles empty array metrics elegantly by passing down fallback values (`-1.00`) instead of throwing arithmetic division errors.

---

## Compilation & Getting Started

Because the code logic spans multiple compilation units, all `.c` resource files must be combined simultaneously so the linker can bridge cross-referenced hooks.

### Prerequisites

You will need a C compiler installed (such as `gcc` or `clang`).

### Command Line Installation

1. **Clone or download this repository** to your local machine.
2. **Compile all files together:**
```bash
gcc main.c student.c statistics.c -o school_system

```


3. **Run the executable:**
* **Linux/macOS:** `./school_system`
* **Windows:** `school_system.exe`



---

## Live Sample Preview

```text
=== Welcome to the Student Management System ===

================ MAIN MENU ================
1. Add a Student
2. Display All Students
3. Search Student by ID
4. Show Class Statistics (Highest & Average)
5. Exit
===========================================
Enter your choice (1-5): 2

--- Displaying All Students ---
------------------------------------------
ID   Name                            Marks
------------------------------------------
1    Alice                           95.50
2    Bob                             88.15
3    Charlie                         100.00

```

---

## Technical Core Concepts Implemented

### Defensive Header Guards

To protect against duplication issues during dependency compilation, headers are wrapped in protective compilation guards:

```c
#ifndef STATISTICS_H
#define STATISTICS_H
// Declared prototypes safely isolated here
#endif

```

### Pass-By-Reference Mechanics

Data states are tightly managed across scopes. Pointers are specifically chosen over value copying to manipulate array sizes globally:

```c
void addStudent(Student *students, int *count); // Passes global tracking reference

```