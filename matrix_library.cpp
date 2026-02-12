#include "matrix_library.h"
#include <cmath>
#include <iomanip>

using namespace std;

// ایجاد ماتریس
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = 0.0;
        }
    }
    
    return m;
}

// ایجاد بردار
Vector createVector(int size) {
    Vector v;
    v.size = size;
    
    for (int i = 0; i < size; i++) {
        v.data[i] = 0.0;
    }
    
    return v;
}

// جمع ماتریس‌ها
Matrix addMatrices(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        cout << "error : matrice dimensions must be identical" << endl;
        return createMatrix(0, 0);
    }
    
    Matrix result = createMatrix(A.rows, A.cols);
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    
    return result;
}

// تفریق ماتریس‌ها
Matrix subtractMatrices(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        cout << "error : matrice dimensions must be identical" << endl;
        return createMatrix(0, 0);
    }
    
    Matrix result = createMatrix(A.rows, A.cols);
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    
    return result;
}

// ضرب ماتریس‌ها
Matrix multiplyMatrices(Matrix A, Matrix B) {
    if (A.cols != B.rows) {
        cout << "error : column count of A must be equal row count of B" << endl;
        return createMatrix(0, 0);
    }
    
    Matrix result = createMatrix(A.rows, B.cols);
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < A.cols; k++) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    
    return result;
}

// ضرب اسکالر در ماتریس
Matrix scalarMultiplyMatrix(Matrix A, double scalar) {
    Matrix result = createMatrix(A.rows, A.cols);
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.data[i][j] = A.data[i][j] * scalar;
        }
    }
    
    return result;
}

// ترانهاده ماتریس
Matrix transposeMatrix(Matrix A) {
    Matrix result = createMatrix(A.cols, A.rows);
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.data[j][i] = A.data[i][j];
        }
    }
    
    return result;
}

// محاسبه دترمینان (روش بازگشتی)
double determinant(Matrix A) {
    if (A.rows != A.cols) {
        cout << "error : matrice must be square" << endl;
        return 0.0;
    }
    
    int n = A.rows;
    
    // حالت پایه: ماتریس 1×1
    if (n == 1) {
        return A.data[0][0];
    }
    
    // حالت پایه: ماتریس 2×2
    if (n == 2) {
        return A.data[0][0] * A.data[1][1] - A.data[0][1] * A.data[1][0];
    }
    
    // روش بازگشتی برای ماتریس‌های بزرگتر
    double det = 0.0;
    
    for (int j = 0; j < n; j++) {
        // ایجاد ماتریس کوچکتر (Minor)
        Matrix minor = createMatrix(n - 1, n - 1);
        
        for (int row = 1; row < n; row++) {
            int colIndex = 0;
            for (int col = 0; col < n; col++) {
                if (col != j) {
                    minor.data[row - 1][colIndex] = A.data[row][col];
                    colIndex++;
                }
            }
        }
        
        // محاسبه دترمینان با استفاده از بسط لاپلاس
        double sign = (j % 2 == 0) ? 1.0 : -1.0;
        det += sign * A.data[0][j] * determinant(minor);
    }
    
    return det;
}

// محاسبه ماتریس معکوس (روش گاوس-جردن)
Matrix inverseMatrix(Matrix A) {
    if (A.rows != A.cols) {
        cout << "error : matrice must be square" << endl;
        return createMatrix(0, 0);
    }
    
    int n = A.rows;
    double det = determinant(A);
    
    if (fabs(det) < 1e-10) {
        cout << "error : matrice is singular (determinant is zero)" << endl;
        return createMatrix(0, 0);
    }
    
    // ایجاد ماتریس همراه [A|I]
    double augmented[MAX_SIZE][MAX_SIZE * 2];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = A.data[i][j];
        }
        for (int j = 0; j < n; j++) {
            augmented[i][n + j] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    // روش گاوس-جردن
    for (int i = 0; i < n; i++) {
        // پیدا کردن محور (pivot)
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(augmented[k][i]) > fabs(augmented[maxRow][i])) {
                maxRow = k;
            }
        }
        
        // تعویض سطرها
        for (int k = 0; k < 2 * n; k++) {
            double temp = augmented[i][k];
            augmented[i][k] = augmented[maxRow][k];
            augmented[maxRow][k] = temp;
        }
        
        // نرمال کردن سطر محور
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }
        
        // حذف سایر سطرها
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }
    
    // استخراج ماتریس معکوس
    Matrix inverse = createMatrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse.data[i][j] = augmented[i][n + j];
        }
    }
    
    return inverse;
}

// جمع بردارها
Vector addVectors(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        cout << "error : matrice dimensions must be identical" << endl;
        return createVector(0);
    }
    
    Vector result = createVector(v1.size);
    
    for (int i = 0; i < v1.size; i++) {
        result.data[i] = v1.data[i] + v2.data[i];
    }
    
    return result;
}

// تفریق بردارها
Vector subtractVectors(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        cout << "error : matrice dimensions must be identical" << endl;
        return createVector(0);
    }
    
    Vector result = createVector(v1.size);
    
    for (int i = 0; i < v1.size; i++) {
        result.data[i] = v1.data[i] - v2.data[i];
    }
    
    return result;
}

// ضرب اسکالر در بردار
Vector scalarMultiplyVector(Vector v, double scalar) {
    Vector result = createVector(v.size);
    
    for (int i = 0; i < v.size; i++) {
        result.data[i] = v.data[i] * scalar;
    }
    
    return result;
}

// ضرب داخلی بردارها
double dotProduct(Vector v1, Vector v2) {
    if (v1.size != v2.size) {
        cout << "error : matrice dimensions must be identical" << endl;
        return 0.0;
    }
    
    double result = 0.0;
    for (int i = 0; i < v1.size; i++) {
        result += v1.data[i] * v2.data[i];
    }
    
    return result;
}

// اندازه بردار
double vectorMagnitude(Vector v) {
    double sumSquares = 0.0;
    
    for (int i = 0; i < v.size; i++) {
        sumSquares += v.data[i] * v.data[i];
    }
    
    return sqrt(sumSquares);
}

// نرمال‌سازی بردار
Vector normalizeVector(Vector v) {
    double mag = vectorMagnitude(v);
    
    if (mag < 1e-10) {
        cout << "error : can not normalize a zero vector" << endl;
        return createVector(0);
    }
    
    Vector result = createVector(v.size);
    
    for (int i = 0; i < v.size; i++) {
        result.data[i] = v.data[i] / mag;
    }
    
    return result;
}

// چاپ ماتریس
void printMatrix(Matrix A) {
    if (A.rows == 0 || A.cols == 0) {
        cout << "empty matrice" << endl;
        return;
    }
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            cout << setw(10) << fixed << setprecision(4) << A.data[i][j] << " ";
        }
        cout << endl; 
    }
}

// چاپ بردار
void printVector(Vector v) {
    cout << "[ ";
    for (int i = 0; i < v.size; i++) {
        cout << fixed << setprecision(4) << v.data[i] << " ";
    }
    cout << "]" << endl;
}
