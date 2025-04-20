# Homework-8-Matrix-Equation
AUTHOR: Amdrew Lentz UMBC CMSC313 2:30 section 4/19/2025
PURPOSE OF SOFTWARE: Solve basic matrix equations that multiply by constants, multiply by other matrices, transpose matrices and add matrices.
FILES: 
matrix.cpp: The C++ file that uses a matrix class to solve basic matrix problems
matrix.c: The C file that uses a matrix struct to solve basic matrix problems
makefile: Makes it easier to run c and cpp programs
BUILDING INSTRUCTIONS: Create a main function to handle the main operations. Then create a matrix class to house your data for each matrix. Then craete functions to handle the necessary operations for the matrices.
TESTING METHODOLOGY: After creating each function run your program to test the individual function, and print out your result. If the result is expected, then move onto the next function. If not, test other ways to see what is wrong with the function.
ADDITIONAL INFORMATION: Some of my functions like the add matrices and multiply matrices will put the result into the matrix that used the function. So for example, A.addMatrix(B) would add the A and B matrices, then put the result into A.
To run the CPP file using the MAKEFILE, use runCpp
To run the C file using the MAKEFILE, use runC
