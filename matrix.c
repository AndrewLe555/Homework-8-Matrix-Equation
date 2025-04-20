#include <stdio.h>
#include <stdlib.h>

// Create a struct for the matrices
typedef struct {
    int m_rows;
    int m_cols;
    int ** m_matrix;
} Matrix;

// Define the starting sizes
#define STARTINGROWSA 2;
#define STARTINGCOLSA 2;
#define STARTINGROWSB 2;
#define STARTINGCOLSB 3;
#define STARTINGROWSC 2;
#define STARTINGCOLSC 3;

int ** createMatrix(int rows, int cols) {
    // Dynamically allocate the matrix using malloc()
    int ** matrix = (int ** )malloc(rows * sizeof(int * ));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int * )malloc(cols * sizeof(int));
    }
    return matrix;
}

void initializeMatrix(int ** matrix, int rows, int cols, int * values) {
    // Assign the values based on the given matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[i * cols + j];
        }
    }
}

void deleteMatrix(int ** matrix, int rows) {
    // Free all dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void matrixTimesConstant(int ** matrix, int rows, int cols, int constant) {
    // Loops through the rows and columns to multiply each number by the constant
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = matrix[i][j] * constant;
        }
    }
}

int ** transposeMatrix(int ** matrix, int rows, int cols) {
    // Dynamically allocate the transposed matrix
    int ** transposedMatrix = createMatrix(cols, rows);
    // Assign the values based on the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    // Delete old matrix
    deleteMatrix(matrix, rows);
    return transposedMatrix;
}

void swapRowsAndCols(int * rows, int * cols) {
    // Swaps the number of rows and columns after a transpose
    int swap = *rows;
    *rows = *cols;
    *cols = swap;
}

int ** matrixTimesMatrix(int ** matrixOne, int rowsOne, int colsOne, int ** matrixTwo, int rowsTwo, int colsTwo) {
    int ** resultingMatrix = createMatrix(rowsOne, colsTwo);
    int total;
    // Loops through matrix one's rows
    for (int i = 0; i < rowsOne; i++) {
        // Loops through matrix two's columns
        for (int j = 0; j < colsTwo; j++) {
            total = 0;
            // Calculates the matrix multiplication, then puts it into the resulting matrix
            for (int k = 0; k < rowsTwo; k++) {
                total += matrixOne[i][k] * matrixTwo[k][j];
            }
            resultingMatrix[i][j] = total;
        }
    }
    // Deletes old matrix
    deleteMatrix(matrixOne, rowsOne);
    // Assigns variables for new matrix
    return resultingMatrix;
}

void updateCol(int * colsOne, int colsTwo) {
    // Updates the columns after matrix multiplication
    *colsOne = colsTwo;
}

void addMatrices(int ** matrixOne, int ** matrixTwo, int rows, int cols) {
    // Adds the two numbers in the same position
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixOne[i][j] += matrixTwo[i][j];
        }
    }
}

void printMatrix(int ** matrix, int rows, int cols) {
    // Loops through the matrix to print each number
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create the Matrix A
    Matrix A;
    A.m_rows = STARTINGROWSA;
    A.m_cols = STARTINGCOLSA;
    int matrixA[4] = {6, 4, 8, 3};
    A.m_matrix = createMatrix(A.m_rows, A.m_cols);
    initializeMatrix(A.m_matrix, A.m_rows, A.m_cols, matrixA);

    // Create the Matrix B
    Matrix B;
    B.m_rows = STARTINGROWSB;
    B.m_cols = STARTINGCOLSB;
    int matrixB[6] = {1, 2, 3, 4, 5, 6};
    B.m_matrix = createMatrix(B.m_rows, B.m_cols);
    initializeMatrix(B.m_matrix, B.m_rows, B.m_cols, matrixB);

    // Create the Matrix C
    Matrix C;
    C.m_rows = STARTINGROWSC;
    C.m_cols = STARTINGCOLSC;
    int matrixC[6] = {2, 4, 6, 1, 3, 5};
    C.m_matrix = createMatrix(C.m_rows, C.m_cols);
    initializeMatrix(C.m_matrix, C.m_rows, C.m_cols, matrixC);

    // Multiply B times a constant
    matrixTimesConstant(B.m_matrix, B.m_rows, B.m_cols, 3);

    // Transpose Matrix C
    C.m_matrix = transposeMatrix(C.m_matrix, C.m_rows, C.m_cols);
    swapRowsAndCols(&C.m_rows, &C.m_cols);

    // Multiplies Matrix B by Matrix C
    B.m_matrix = matrixTimesMatrix(B.m_matrix, B.m_rows, B.m_cols, C.m_matrix, C.m_rows, C.m_cols);
    updateCol(&B.m_cols, C.m_cols);

    // Adds Matrix A and Matrix B
    addMatrices(A.m_matrix, B.m_matrix, A.m_rows, A.m_cols);

    // Print the final result
    printMatrix(A.m_matrix, A.m_rows, A.m_cols);

    // Deallocate memory
    deleteMatrix(A.m_matrix, A.m_rows);
    deleteMatrix(B.m_matrix, B.m_rows);
    deleteMatrix(C.m_matrix, C.m_rows);

    return 0;
}