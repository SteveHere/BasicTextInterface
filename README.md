# BasicTextInterface
A text-based interface. Built using gcc, that is installed via Cygwin on Windows. 

# How to use
Windows

1. Install cygwin
2. Using cygwin, install gcc
3. Run the program in the cygwin command line interface (CLI).
4. That's it.

Linux/OSX/Every other OS

1. *shrugs* I can't help you here. I've been on Windows since day 1. Sorry. :(
2. ...Did you try googling "install gcc *insert OS here*" ?
3. ?
4. Run the program in a CLI.
5. That's it.

# Why build this
I was bored and decided to try to make a simple text-based interface in C.

# Where is everything?

Apps/Tools.c : All of the self-made functions that can be used more than once within the program go in here.

Apps folder : All of the application files and their headers are here. 

EverythingFromApps.c : The file where most of the magic happens. Include your app here. Modify ListOptions() to add it to the list of options available to the user. Lastly, add it to Selection(char select, char* name) under one of the free cases.

Envrionment.c : A bit of the magic happens here. This place is mostly a high-level view of the entire thing.

Project.c : Almost nothing special here. Contains the main() method, so make sure to compile this file. Was set up like this for future expansions (See TODO in Project.c).

