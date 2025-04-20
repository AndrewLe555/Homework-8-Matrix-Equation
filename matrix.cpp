#include <iostream>

using namespace std;

class Matrix {
    public:
        // Member variables
        int m_rows;
        int m_cols;
        int ** m_matrix;

        Matrix(int rows, int cols) {
            // Assign member variables
            m_rows = rows;
            m_cols = cols;
        }

        ~Matrix() {
            deleteMatrix();
        }

        void deleteMatrix() {
            // Delete the pointers
            for (int i = 0; i < m_rows; i++) {
                delete m_matrix[i];
            }
            delete m_matrix;
        }

        void createMatrix(int * matrix) {
            // Dynamically allocate the matrix
            m_matrix = new int * [m_rows];
            for (int i = 0; i < m_rows; i++) {
                m_matrix[i] = new int [m_cols];
            }
            // Assign the values based on the given matrix
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    m_matrix[i][j] = matrix[i * m_cols + j];
                }
            }
        }

        void matrixTimesConstant(int constant) {
            // Loops through the rows and columns to multiply each number by the constant
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    m_matrix[i][j] = m_matrix[i][j] * constant;
                }
            }
        }

        void transposeMatrix() {
            // Dynamically allocate the transposed matrix
            int ** transposedMatrix = new int * [m_cols];
            for (int i = 0; i < m_cols; i++) {
                transposedMatrix[i] = new int [m_rows];
            }
            // Assign the values based on the matrix
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    transposedMatrix[j][i] = m_matrix[i][j];
                }
            }
            // Delete old matrix
            deleteMatrix();
            m_matrix = transposedMatrix;
            // Swap rows and columns
            int swap = m_rows;
            m_rows = m_cols;
            m_cols = swap;
        }

        void multiplyMatrix(int ** secondMatrix, int secondRows, int secondCols) {
            // Dynamically allocate the resulting matrix
            int ** resultingMatrix = new int * [m_rows];
            for (int i = 0; i < m_rows; i++) {
                resultingMatrix[i] = new int [secondCols];
            }
            int total;
            // Loops through matrix one's rows
            for (int i = 0; i < m_rows; i++) {
                // Loops through matrix two's columns
                for (int j = 0; j < secondCols; j++) {
                    total = 0;
                    // Calculates the matrix multiplication, then puts it into the resulting matrix
                    for (int k = 0; k < secondRows; k++) {
                        total += m_matrix[i][k] * secondMatrix[k][j];
                    }
                    resultingMatrix[i][j] = total;
                }
            }
            // Deletes old matrix
            deleteMatrix();
            // Assigns variables for new matrix
            m_cols = secondCols;
            m_matrix = resultingMatrix;
        }

        void addMatrix(int ** secondMatrix) {
            // Adds the numbers that are in the same location of the matrices and puts them in the result vector
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    m_matrix[i][j] += secondMatrix[i][j];
                }
            }
        }

        void printMatrix() {
            // Loops through the matrix to print each number
            for (int i = 0; i < m_rows; i++) {
                for (int j = 0; j < m_cols; j++) {
                    cout << m_matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

};

int main() {
    // Create the given matrices
    Matrix A(2, 2);
    int matrixA[A.m_rows][A.m_cols] = {{6, 4}, {8, 3}};
    A.createMatrix(&matrixA[0][0]);
    Matrix B(2, 3);
    int matrixB[B.m_rows][B.m_cols] = {{1, 2, 3}, {4, 5, 6}};
    B.createMatrix(&matrixB[0][0]);
    Matrix C(2, 3);
    int matrixC[C.m_rows][C.m_cols] = {{2, 4, 6}, {1, 3, 5}};
    C.createMatrix(&matrixC[0][0]);

    // Use PEMDAS to get final answer and print it
    B.matrixTimesConstant(3);
    C.transposeMatrix();
    B.multiplyMatrix(C.m_matrix, C.m_rows, C.m_cols);
    A.addMatrix(B.m_matrix);
    A.printMatrix();

    return 0;
}