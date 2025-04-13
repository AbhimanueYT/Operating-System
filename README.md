# Operating-System

🛠️ How to Run .sh and .c Files in Linux Terminal (No -o Flag)
📁 Prerequisites
Make sure the following are installed:

GCC compiler for C

Bash shell

Install GCC if not already available:

bash
Copy
Edit
sudo apt update
sudo apt install build-essential
🚀 Running a .c File
1. Write your C program
Example: priority_scheduler.c

c
Copy
Edit
#include <stdio.h>

int main() {
    printf("Hello, world from C!\n");
    return 0;
}
2. Compile the C file (without -o)
bash
Copy
Edit
gcc priority_scheduler.c
This creates an output file named a.out by default.

3. Run the compiled program
bash
Copy
Edit
./a.out
🔧 Running a .sh File
1. Write your shell script
Example: run_scheduler.sh

bash
Copy
Edit
#!/bin/bash
gcc priority_scheduler.c
./a.out
2. Make the script executable
bash
Copy
Edit
chmod +x run_scheduler.sh
3. Run the shell script
bash
Copy
Edit
./run_scheduler.sh
✅ Notes
a.out is the default executable name when you don’t use -o.

You can rename a.out manually using mv, or let GCC handle it with -o if needed in future.

chmod +x is only required once per script.
