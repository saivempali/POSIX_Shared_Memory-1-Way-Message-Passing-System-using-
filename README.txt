						README

DETAILS:

Name : Sai Vishnu Teja Vempali
UFID : 1614e1381
email :  vishnu24@ufl.edu

INTRODUCTION :

The assignment consists of 2 C++ programs, 1 C program and two header files.

The two C++ programs are reader.cpp which reads from the shared buffer and writer.cpp which writes to it. The C program sharedLib.c implements the read-write functionalities and the mapping of the shared library so that it is accessible to both the processes that are communicating through it. The header file sharedLib.h declares the shared library functionalities.
Limitations :The buffer has been assumed a static size.				


HOW TO RUN:

1. Download the tar file containing all the required files.

2. Extract the files.

3. Copy the RA_Assignment directory to home.

4. Run using the following commands

>  make

> export LD_LIBRARY_PATH=/home/RA_Assignment:$LD_LIBRARY_PATH make

> ./writer and ./reader on separate terminals

> Enter “quit” to terminate the writer. It automatically terminates the reader program,

