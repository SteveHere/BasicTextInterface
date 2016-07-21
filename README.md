# BasicTextInterface
A text-based interface. Developed using Eclipse, that is compiled via gcc with Cygwin on Windows. 

# How to use
Windows

1. Install cygwin
2. Using cygwin, install gcc
3. Run the program in the cygwin command line interface (CLI).

Linux/OSX

1. Install gcc
2. Compile and run the program in a CLI.

# Why build this
3 main reasons:
1. I was bored and decided to try to make a simple text-based interface in C.
2. I wanted to write code that can serve as the basis for implementing SQLite in C, and for writing readable C code
3. I wanted to outline how files are structured in Eclipse. 

# Where is everything?

Apps/Tools.c : All of the self-made functions that can be used more than once within the program go in here.

Apps folder : All of the application files and their headers are here. 

EverythingFromApps.c : The file where most of the magic happens. Include your app here. Modify ListOptions() to add it to the list of options available to the user. Lastly, add it to Selection(char select, char* username) under one of the free cases.

Envrionment.c : A bit of the magic happens here. This place is mostly a high-level view of the entire application.

Project.c : Almost nothing special here. Contains the main() method, so make sure to compile this file. Was set up like this for future expansions (See TODO in Project.c).

