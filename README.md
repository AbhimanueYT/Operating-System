# Operating-System

## 🛠️ How to Run `.sh` and `.c` Files in Linux Terminal (No `-o` Flag)

### 📁 Prerequisites
Make sure the following are installed:
- GCC compiler for C
- Bash shell (usually pre-installed on Linux)

Install GCC if not already available:

```bash
sudo apt update
sudo apt install build-essential
```

---

## 🚀 Running a `.c` File

### 1. Write your C program

Example: `priority_scheduler.c`

```c
#include <stdio.h>

int main() {
    printf("Hello, world from C!\n");
    return 0;
}
```

### 2. Compile the C file (without `-o`)

```bash
gcc priority_scheduler.c
```

> This creates an output file named `a.out` by default.

### 3. Run the compiled program

```bash
./a.out
```

---

## 🔧 Running a `.sh` File

### 1. Write your shell script

Example: `run_scheduler.sh`

```bash
#!/bin/bash
gcc priority_scheduler.c
./a.out
```

### 2. Make the script executable

```bash
chmod +x run_scheduler.sh
```

### 3. Run the shell script

```bash
./run_scheduler.sh
```

---

## ✅ Notes
- `a.out` is the default executable name when you don’t use the `-o` flag.
- You can rename `a.out` manually using `mv`, or use `gcc -o filename` if desired.
- `chmod +x` is only required once per script.
