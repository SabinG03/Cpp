#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;

////////////////////////////////////////////////////////////////
// Matrix Test Cases
////////////////////////////////////////////////////////////////

void Test_Case_Constructor_Zero() {
    cout << "=======================================" << endl;
    cout << "Test Case 1 : Constructor (0's)" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(3, 3);
    string expected = "0 0 0 \n0 0 0 \n0 0 0 \n";
    if (mat1.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        mat1.print(cout);
    }
    cout << endl;
}

void Test_Case_Copy_Constructor() {
    cout << "=======================================" << endl;
    cout << "Test Case 2 : Copy Constructor" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(mat1);
    if (mat1.toStr() == mat2.toStr()) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        cout << "Matrix 1:" << endl;
        mat1.print(cout);
        cout << "Matrix 2:" << endl;
        mat2.print(cout);
    }
    cout << endl;
}

void Test_Case_2D_Array_Constructor() {
    cout << "=======================================" << endl;
    cout << "Test Case 3 : Constructor (int ** array)" << endl;
    cout << "=======================================" << endl;
    int rows = 2;
    int cols = 2;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    Matrix mat(arr, rows, cols);
    string expected = "1 2 \n3 4 \n";
    if (mat.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        mat.print(cout);
    }
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    cout << endl;
}

void Test_Case_Rows() {
    cout << "=======================================" << endl;
    cout << "Test Case 4 : Rows" << endl;
    cout << "=======================================" << endl;
    Matrix mat(4, 5);
    if (mat.rows() == 4) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;
}

void Test_Case_Columns() {
    cout << "=======================================" << endl;
    cout << "Test Case 5 : Columns" << endl;
    cout << "=======================================" << endl;
    Matrix mat(3, 6);
    if (mat.columns() == 6) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;
}

void Test_Case_Get() {
    cout << "=======================================" << endl;
    cout << "Test Case 6 : Get (Element at i,j)" << endl;
    cout << "=======================================" << endl;
    Matrix mat(3, 3);
    mat.set(1, 1, 5);
    if (mat.get(1, 1) == 5) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;
}

void Test_Case_Set() {
    cout << "=======================================" << endl;
    cout << "Test Case 7 : Set (Update Element)" << endl;
    cout << "=======================================" << endl;
    Matrix mat(2, 2);
    mat.set(0, 0, 10);
    mat.set(0, 1, 20);
    mat.set(1, 0, 30);
    mat.set(1, 1, 40);
    string expected = "10 20 \n30 40 \n";
    if (mat.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        mat.print(cout);
    }
    cout << endl;
}

void Test_Case_Addition() {
    cout << "=======================================" << endl;
    cout << "Test Case 8 : Matrix Addition" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 4);
    mat2.set(0, 1, 3);
    mat2.set(1, 0, 2);
    mat2.set(1, 1, 1);

    Matrix result = mat1 + mat2;
    string expected = "5 5 \n5 5 \n";
    if (result.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        result.print(cout);
    }
    cout << endl;
}

void Test_Case_Subtraction() {
    cout << "=======================================" << endl;
    cout << "Test Case 9 : Matrix Subtraction" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 5);
    mat1.set(0, 1, 6);
    mat1.set(1, 0, 7);
    mat1.set(1, 1, 8);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 0, 3);
    mat2.set(1, 1, 4);

    Matrix result = mat1 - mat2;
    string expected = "4 4 \n4 4 \n";
    if (result.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        result.print(cout);
    }
    cout << endl;
}

void Test_Case_Multiplication() {
    cout << "=======================================" << endl;
    cout << "Test Case 10 : Matrix Multiplication" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(2, 3);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(0, 2, 3);
    mat1.set(1, 0, 4);
    mat1.set(1, 1, 5);
    mat1.set(1, 2, 6);

    Matrix mat2(3, 2);
    mat2.set(0, 0, 7);
    mat2.set(0, 1, 8);
    mat2.set(1, 0, 9);
    mat2.set(1, 1, 10);
    mat2.set(2, 0, 11);
    mat2.set(2, 1, 12);

    Matrix result = mat1 * mat2;
    string expected = "58 64 \n139 154 \n";
    if (result.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        result.print(cout);
    }
    cout << endl;
}

void Test_Case_Transpose() {
    cout << "=======================================" << endl;
    cout << "Test Case 11 : Matrix Transpose" << endl;
    cout << "=======================================" << endl;
    Matrix mat(2, 3);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(0, 2, 3);
    mat.set(1, 0, 4);
    mat.set(1, 1, 5);
    mat.set(1, 2, 6);

    Matrix transposed = ~mat;
    string expected = "1 4 \n2 5 \n3 6 \n";
    if (transposed.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        transposed.print(cout);
    }
    cout << endl;
}

void Test_Case_Equality() {
    cout << "=======================================" << endl;
    cout << "Test Case 12 : Matrix Equality" << endl;
    cout << "=======================================" << endl;
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 1);
    mat2.set(0, 1, 2);
    mat2.set(1, 0, 3);
    mat2.set(1, 1, 4);

    if (mat1 == mat2) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    cout << endl;
}

void Test_Case_ToStr() {
    cout << "=======================================" << endl;
    cout << "Test Case 13 :String Representation" << endl;
    cout << "=======================================" << endl;
    Matrix mat(2, 2);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(1, 0, 3);
    mat.set(1, 1, 4);

    string expected = "1 2 \n3 4 \n";
    if (mat.toStr() == expected) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
        mat.print(cout);
    }
    cout << endl;
}

int main() {
    Test_Case_Constructor_Zero();
    Test_Case_Copy_Constructor();
    Test_Case_2D_Array_Constructor();
    Test_Case_Rows();
    Test_Case_Columns();
    Test_Case_Get();
    Test_Case_Set();
    Test_Case_Addition();
    Test_Case_Subtraction();
    Test_Case_Multiplication();
    Test_Case_Transpose();
    Test_Case_Equality();
    Test_Case_ToStr();
    return 0;
}
