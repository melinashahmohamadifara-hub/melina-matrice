#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

#include <iostream>

// حداکثر اندازه ماتریس و بردار
const int MAX_SIZE = 10;

// ساختار ماتریس
struct Matrix {
    double data[MAX_SIZE][MAX_SIZE];
    int rows;
    int cols;
};

// ساختار بردار
struct Vector {
    double data[MAX_SIZE];
    int size;
};

// عملیات پایه‌ای ماتریس
Matrix addMatrices(Matrix A, Matrix B);
Matrix multiplyMatrices(Matrix A, Matrix B);
Matrix scalarMultiplyMatrix(Matrix A, double scalar);
Matrix subtractMatrices(Matrix A, Matrix B);
Matrix transposeMatrix(Matrix A);
double determinant(Matrix A);
Matrix inverseMatrix(Matrix A);

// عملیات پایه‌ای بردار
Vector addVectors(Vector v1, Vector v2);
Vector subtractVectors(Vector v1, Vector v2);
Vector scalarMultiplyVector(Vector v, double scalar);
double dotProduct(Vector v1, Vector v2);
double vectorMagnitude(Vector v);
Vector normalizeVector(Vector v);

// توابع کمکی
void printMatrix(Matrix A);
void printVector(Vector v);
Matrix createMatrix(int rows, int cols);
Vector createVector(int size);

#endif
