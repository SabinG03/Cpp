#include "Matrix.h"

/* *
* 1. Constructor:
 * Creates a matrix of size m x n, all elements to 0
 * Allocates memory for the matrix
 * @param m number of rows
 * @param n number of columns
 */
Matrix::Matrix(unsigned int m, unsigned int n) : r(m), c(n) {
    data = new int*[r];
    for (unsigned int i = 0; i < r; ++i) {
        data[i] = new int[c]();
    }
}

/* *
* 2. Copy constructor:
 * Creates a new matrix copying the contents of a matrix
 * Allocates memory for the new matrix and copies each element
 * @param mat
 */
Matrix::Matrix(const Matrix &mat) : r(mat.r), c(mat.c) {
    data = new int*[r];
    for (unsigned int i = 0; i < r; ++i) {
        data[i] = new int[c];
        for (unsigned int j = 0; j < c; ++j) {
            data[i][j] = mat.data[i][j];
        }
    }
}

/* *
* 3. Constructor matrix from a 2D array size m x n
 * Creates a matrix from a 2D array of integers
 * Copies the data from the array into a newly made matrix
 * @param the 2D array to initialize the matrix from
 * @param m number of rows
 * @param n number of columns
 */
Matrix::Matrix(int** array, unsigned int m, unsigned int n) : r(m), c(n) {
    data = new int*[r];
    for (unsigned int i = 0; i < r; ++i) {
        data[i] = new int[c];
        for (unsigned int j = 0; j < c; ++j) {
            data[i][j] = array[i][j];
        }
    }
}

/* *
* 4. Returns the number of rows
 * @return the number of rows
 */
unsigned int Matrix::rows() const {
    return r;
}

/* *
* 5. Returns the number of columns
 * @return the number of columns
 */
unsigned int Matrix::columns() const {
    return c;
}

/* *
* 6. Returns the element at (i, j)
 * Gets the value at the set row and column
 * Checks for valid indices and throws an error if out of bounds
 * @param i row index
 * @param j column index
 * @return the value at position (i, j)
 */
int Matrix::get(unsigned int i, unsigned int j) const {
    if (i >= r || j >= c) throw out_of_range("Out of range");
    return data[i][j];
}

/* *
* 7. Sets the element at (i, j) 
 * Updates the value of the matrix at a set position
 * Throws an error if out of bounds
 * @param i row index
 * @param j column index
 * @param the value to set
 */
void Matrix::set(unsigned int i, unsigned int j, int value) {
    if (i >= r || j >= c) throw out_of_range("Out of range");
    data[i][j] = value;
}

/* *
* 8. Addition of two matrices
 * Adds two matrices 
 * Throws an error if the dimensions of the two matrices do not match
 * @param mat 
 * @return a matrix with results
 */
Matrix Matrix::operator+(const Matrix &mat) const {
    if (r != mat.r || c != mat.c) throw invalid_argument("Matrices dont match");
    Matrix result(r, c);
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            result.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return result;
}

/* *
* 9. Subtraction of two matrices
 * Subtracts one matrix from another 
 * Throws an error if the size of the two matrices do not match
 * @param mat 
 * @return a matrix with results
 */
Matrix Matrix::operator-(const Matrix &mat) const {
    if (r != mat.r || c != mat.c) throw invalid_argument("Matrices dont match");
    Matrix result(r, c);
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            result.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return result;
}

/* *
* 10. Multiplication
 * Multiplies two matrices
 * The column in the first matrix must equal the number of rows in the second matirx
 * Throws an error if the size dont match
 * @param mat 
 * @return a matrix with results
 */
Matrix Matrix::operator*(const Matrix &mat) const {
    if (c != mat.r) throw invalid_argument("Matrix Size Error");
    Matrix result(r, mat.c);
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < mat.c; ++j) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < c; ++k) {
                result.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }
    return result;
}

/* *
* 11. Transpose 
 * Creates the transpose of the matrix by flipping rows and columns
 * Allocates a new matrix for the transposed result
 * @return transposed matrix
 */
Matrix Matrix::operator~() const {
    Matrix transposed(c, r);
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
    return transposed;
}

/* *
* 12. Equality operator overload
 * Checks if two matrices are equal
 * @param mat
 * @return true if they are the same otherwise false
 */
bool Matrix::operator==(const Matrix &mat) const {
    if (r != mat.r || c != mat.c) return false;
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            if (data[i][j] != mat.data[i][j]) return false;
        }
    }
    return true;
}

/* *
* 13. Returns a string representation of the matrix
 * Turns the matrix into a string
 * Each row is separated by a newline character
 * @return string 
 */
string Matrix::toStr() const {
    stringstream ss;
    for (unsigned int i = 0; i < r; ++i) {
        for (unsigned int j = 0; j < c; ++j) {
            ss << data[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

/* *
* Destructor to release allocated memory
 * Frees the memory
 */
Matrix::~Matrix() {
    for (unsigned int i = 0; i < r; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

/* *
* Prints the matrix to the output stream
 * Prints the matrix
 * @param os
 */
void Matrix::print(ostream &os) const {
    os << toStr();
}
