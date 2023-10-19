#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

// Function prototypes



// Function to read matrix data from a file
void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream file(filename);
    if (file) {
        /* `file >> size;` is reading the value of `size` from the input file. It is using the input
        stream operator `>>` to extract the value from the file and store it in the variable `size`. */
        file >> size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix1[i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file >> matrix2[i][j];
            }
        }
        // file.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
        exit(1);
    }
}

// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;
    
    // Read the matrices from the file
    readMatrixFromFile(matrix1, matrix2, size, "matrix_input.txt");
    
    
    printMatrix(matrix1, size);
    printMatrix(matrix2, size);
    // Add matrices and display the result
    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix1 + Matrix2:\n";
    printMatrix(result, size);

    // Multiply matrices and display the result
    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix1 * Matrix2:\n";
    printMatrix(result, size);

    // Subtract matrices and display the result
    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix1 - Matrix2:\n";
    printMatrix(result, size);

    return 0;
}