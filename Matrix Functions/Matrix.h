#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class Matrix {
public:
    unsigned int r, c;   
    int** data;          
    Matrix(unsigned int m, unsigned int n); // Matrix size m x n and all elements=0
    Matrix(const Matrix &mat);// Copy
    Matrix(int** array, unsigned int m, unsigned int n);// Initialize matrix from a 2D array
    ~Matrix();// Destructor
    unsigned int rows() const;// Returns the num of rows
    unsigned int columns() const;// Returns the num of columns
    int get(unsigned int i, unsigned int j) const; // Returns element (i, j)
    void set(unsigned int i, unsigned int j, int value); // Sets element (i, j) to value
    Matrix operator+(const Matrix &mat) const; // Add
    Matrix operator-(const Matrix &mat) const; // Minus
    Matrix operator*(const Matrix &mat) const; // Multiply
    Matrix operator~() const; // Transpose
    bool operator==(const Matrix &mat) const; // Equal
    void print(ostream &os) const;// Print matrix
    string toStr() const;
};

#endif
