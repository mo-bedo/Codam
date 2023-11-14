# Pipex
This project involves emulating the functionality of the shell pipe, directing the flow of STDIN and STDOUT through pipes.

What is Pipex?
Pipex stands as an individual project at Codam, tasking us with developing a program that mimics the shell pipe's behavior. The program takes input from a file or STDIN and redirects it through a series of commands, ultimately writing the output to a specified file. Building the program requires creating child processes using fork(), establishing communication with the parent process through pipe(), manipulating environment variables, and performing checks such as verifying command existence or execution permission. Additionally, error messages are printed to STDERR when necessary.