#include "matrix_library.h"
#include <iostream>
#include <cmath>

using namespace std;

void printHeader(const char* title) {
    cout << "\n========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;
}

void demonstrateMatrixOperations() {
    printHeader("matrice operatins test");
    
    // --- 1. جمع ماتریس‌ها ---
    cout << "\n--- 1. matrice addition---" << endl;
    
    Matrix A = createMatrix(3, 3);
    A.data[0][0] = 1; A.data[0][1] = 2; A.data[0][2] = 3;
    A.data[1][0] = 4; A.data[1][1] = 5; A.data[1][2] = 6;
    A.data[2][0] = 7; A.data[2][1] = 8; A.data[2][2] = 9;
    
    Matrix B = createMatrix(3, 3);
    B.data[0][0] = 9; B.data[0][1] = 8; B.data[0][2] = 7;
    B.data[1][0] = 6; B.data[1][1] = 5; B.data[1][2] = 4;
    B.data[2][0] = 3; B.data[2][1] = 2; B.data[2][2] = 1;
    
    cout << "matrice A:" << endl;
    printMatrix(A);
    cout << "\nmatrice B:" << endl;
    printMatrix(B);
    
    Matrix sumAB = addMatrices(A, B);
    cout << "\nA + B = " << endl;
    printMatrix(sumAB);
    
    // --- 2. ضرب ماتریس‌ها ---
    cout << "\n--- 2. matrice multiplication---" << endl;
    
    Matrix C = createMatrix(3, 2);
    C.data[0][0] = 1; C.data[0][1] = 2;
    C.data[1][0] = 3; C.data[1][1] = 4;
    C.data[2][0] = 5; C.data[2][1] = 6;
    
    Matrix D = createMatrix(2, 3);
    D.data[0][0] = 7;  D.data[0][1] = 8;  D.data[0][2] = 9;
    D.data[1][0] = 10; D.data[1][1] = 11; D.data[1][2] = 12;
    
    cout << "matrice C:" << endl;
    printMatrix(C);
    cout << "\nmatrice D:" << endl;
    printMatrix(D);
    
    Matrix productCD = multiplyMatrices(C, D);
    cout << "\nC * D = " << endl;
    printMatrix(productCD);
    
    // --- 3. ضرب اسکالر در ماتریس ---
    cout << "\n--- 3. scalar multiplication---" << endl;
    
    Matrix E = createMatrix(2, 2);
    E.data[0][0] = 1; E.data[0][1] = 2;
    E.data[1][0] = 3; E.data[1][1] = 4;
    
    int scalar = 2; 
    
    cout << "matrice E:" << endl;
    printMatrix(E);
    cout << "\nscalar = " << scalar << endl;
    
    Matrix scalarProduct = scalarMultiplyMatrix(E, scalar);
    cout << "\n" << scalar << " * E = " << endl;
    printMatrix(scalarProduct);
    
    // --- 4. تفریق ماتریس‌ها ---
    cout << "\n--- 4. matrice subtraction---" << endl;
    
    Matrix F = createMatrix(2, 2);
    F.data[0][0] = 10; F.data[0][1] = 20;
    F.data[1][0] = 30; F.data[1][1] = 40;
    
    Matrix G = createMatrix(2, 2);
    G.data[0][0] = 5;  G.data[0][1] = 10;
    G.data[1][0] = 15; G.data[1][1] = 20;
    
    cout << "matrice F:" << endl;
    printMatrix(F);
    cout << "\nmatrice G:" << endl;
    printMatrix(G);
    
    Matrix diffFG = subtractMatrices(F, G);
    cout << "\nF - G = " << endl;
    printMatrix(diffFG);
    
    // --- 5. ترانهاده ماتریس ---
    cout << "\n--- 5. matrice transpose---" << endl;
    
    Matrix H = createMatrix(2, 3);
    H.data[0][0] = 1; H.data[0][1] = 2; H.data[0][2] = 3;
    H.data[1][0] = 4; H.data[1][1] = 5; H.data[1][2] = 6;
    
    cout << "matrice H:" << endl;
    printMatrix(H);
    
    Matrix transposeH = transposeMatrix(H);
    cout << "\ntranspose H= " << endl;
    printMatrix(transposeH);
    
    // --- 6. محاسبه دترمینان ---
    cout << "\n--- 6. determinant calculation---" << endl;
    
    // ماتریس 2×2
    Matrix I2 = createMatrix(2, 2);
    I2.data[0][0] = 3; I2.data[0][1] = 8;
    I2.data[1][0] = 4; I2.data[1][1] = 6;
    
    cout << "matrice I2 (2*2):" << endl;
    printMatrix(I2);
    double detI2 = determinant(I2);
    cout << "determinant = " << detI2 << endl;
    
    // ماتریس 3×3
    Matrix I3 = createMatrix(3, 3);
    I3.data[0][0] = 6; I3.data[0][1] = 1;  I3.data[0][2] = 1;
    I3.data[1][0] = 4; I3.data[1][1] = -2; I3.data[1][2] = 5;
    I3.data[2][0] = 2; I3.data[2][1] = 8;  I3.data[2][2] = 7;
    
    cout << "\nmatrice I3 (3*3):" << endl;
    printMatrix(I3);
    double detI3 = determinant(I3);
    cout << "determinant = " << detI3 << endl;
    
    // --- 7. محاسبه ماتریس معکوس ---
    cout << "\n--- 7. inverse matrice calculation---" << endl;
    
    Matrix J = createMatrix(2, 2);
    J.data[0][0] = 4; J.data[0][1] = 7;
    J.data[1][0] = 2; J.data[1][1] = 6;
    
    cout << "matrice J:" << endl;
    printMatrix(J);
    cout << "determinant J = " << determinant(J) << endl;
    
    Matrix inverseJ = inverseMatrix(J);
    cout << "\ninverse J = " << endl;
    printMatrix(inverseJ);
    
    // بررسی صحت معکوس
    Matrix identity = multiplyMatrices(J, inverseJ);
    cout << "\nJ * J⁻¹ (matrice must be identity) = " << endl;
    printMatrix(identity);
    
    // ماتریس معکوس 3×3
    cout << "\n--- inverse matrice 3*3 ---" << endl;
    
    Matrix K = createMatrix(3, 3);
    K.data[0][0] = 1; K.data[0][1] = 2; K.data[0][2] = 3;
    K.data[1][0] = 0; K.data[1][1] = 1; K.data[1][2] = 4;
    K.data[2][0] = 5; K.data[2][1] = 6; K.data[2][2] = 0;
    
    cout << "matrice K:" << endl;
    printMatrix(K);
    cout << "determinant K = " << determinant(K) << endl;
    
    Matrix inverseK = inverseMatrix(K);
    cout << "\ninverseل K = " << endl;
    printMatrix(inverseK);
    
    Matrix identityK = multiplyMatrices(K, inverseK);
    cout << "\nK * K⁻¹ (matrice must be identity) = " << endl;
    printMatrix(identityK);
}

void demonstrateVectorOperations() {
    printHeader("vector operation test");
    
    // --- 1. جمع بردارها ---
    cout << "\n--- 1. vector multiplication ---" << endl;
    
    Vector v1 = createVector(3);
    v1.data[0] = 1; v1.data[1] = 2; v1.data[2] = 3;
    
    Vector v2 = createVector(3);
    v2.data[0] = 4; v2.data[1] = 5; v2.data[2] = 6;
    
    cout << "vector v1: ";
    printVector(v1);
    cout << "vector v2: ";
    printVector(v2);
    
    Vector sumV = addVectors(v1, v2);
    cout << "v1 + v2 = ";
    printVector(sumV);
    
    // --- 2. تفریق بردارها ---
    cout << "\n--- 2. vector subtraction---" << endl;
    
    Vector v3 = createVector(3);
    v3.data[0] = 10; v3.data[1] = 20; v3.data[2] = 30;
    
    Vector v4 = createVector(3);
    v4.data[0] = 5; v4.data[1] = 10; v4.data[2] = 15;
    
    cout << "vector v3: ";
    printVector(v3);
    cout << "vector v4: ";
    printVector(v4);
    
    Vector diffV = subtractVectors(v3, v4);
    cout << "v3 - v4 = ";
    printVector(diffV);
    
    // --- 3. ضرب اسکالر در بردار ---
    cout << "\n--- 3. scalar multiplication---" << endl;
    
    Vector v5 = createVector(3);
    v5.data[0] = 2; v5.data[1] = 4; v5.data[2] = 6;
    
    double scalar = 3.5;
    
    cout << "vector v5: ";
    printVector(v5);
    cout << "scalar = " << scalar << endl;
    
    Vector scalarV = scalarMultiplyVector(v5, scalar);
    cout << scalar << " * v5 = ";
    printVector(scalarV);
    
    // --- 4. ضرب داخلی بردارها ---
    cout << "\n--- 4. dot product---" << endl;
    
    Vector v6 = createVector(3);
    v6.data[0] = 1; v6.data[1] = 2; v6.data[2] = 3;
    
    Vector v7 = createVector(3);
    v7.data[0] = 4; v7.data[1] = 5; v7.data[2] = 6;
    
    cout << "vector v6: ";
    printVector(v6);
    cout << "vector v7: ";
    printVector(v7);
    
    double dotProd = dotProduct(v6, v7);
    cout << "v6 · v7 = " << dotProd << endl;
    
    // --- 5. تست عمود بودن بردارها ---
    cout << "\n--- 5. vector orthogonality text---" << endl;
    
    Vector v8 = createVector(3);
    v8.data[0] = 3; v8.data[1] = -2; v8.data[2] = 1;
    
    Vector v9 = createVector(3);
    v9.data[0] = 1; v9.data[1] = 3; v9.data[2] = 3;
    
    cout << "vector v8: ";
    printVector(v8);
    cout << "vector v9: ";
    printVector(v9);
    
    double dotProd2 = dotProduct(v8, v9);
    cout << "v8 · v9 = " << dotProd2;
    if (fabs(dotProd2) < 1e-10) {
        cout << " (vectors are orthogonal)" << endl;
    } else {
        cout << " (vectors are not orthogonal)" << endl;
    }
    
    // --- 6. اندازه بردار ---
    cout << "\n--- 6. vector magnitude---" << endl;
    
    Vector v10 = createVector(2);
    v10.data[0] = 3; v10.data[1] = 4;
    
    Vector v11 = createVector(3);
    v11.data[0] = 1; v11.data[1] = 2; v11.data[2] = 2;
    
    cout << "vector v10: ";
    printVector(v10);
    double mag10 = vectorMagnitude(v10);
    cout << "|v10| = " << mag10 << endl;
    
    cout << "\nvector v11: ";
    printVector(v11);
    double mag11 = vectorMagnitude(v11);
    cout << "|v11| = " << mag11 << endl;
    
    // --- 7. نرمال‌سازی بردار ---
    cout << "\n--- 7. vector normalize---" << endl;
    
    Vector v12 = createVector(3);
    v12.data[0] = 3; v12.data[1] = 4; v12.data[2] = 0;
    
    cout << "vector v12: ";
    printVector(v12);
    cout << "vector v12 = " << vectorMagnitude(v12) << endl;
    
    Vector normalizedV12 = normalizeVector(v12);
    cout << "normalized vector:";
    printVector(normalizedV12);
    cout << "normalized vector magnitude= " << vectorMagnitude(normalizedV12) << endl;
}

void demonstrateErrorHandling() {
    printHeader("errors managing test");
    
    cout << "\n--- test 1 : add matrices with different dimensions---" << endl;
    Matrix A1 = createMatrix(2, 2);
    Matrix B1 = createMatrix(2, 3);
    addMatrices(A1, B1);
    
    cout << "\n--- test 2 : incompatible dimensions multiplication---" << endl;
    Matrix A2 = createMatrix(2, 3);
    Matrix B2 = createMatrix(2, 2);
    multiplyMatrices(A2, B2);
    
    cout << "\n--- test 3 : not square matrice determinant---" << endl;
    Matrix A3 = createMatrix(2, 3);
    determinant(A3);
    
    cout << "\n--- test 4 : zero-determinant matrice transpose---" << endl;
    Matrix A4 = createMatrix(3, 3);
    A4.data[0][0] = 1; A4.data[0][1] = 2; A4.data[0][2] = 3;
    A4.data[1][0] = 2; A4.data[1][1] = 4; A4.data[1][2] = 6;
    A4.data[2][0] = 3; A4.data[2][1] = 6; A4.data[2][2] = 9;
    
    cout << "matrice A:" << endl;
    printMatrix(A4);
    cout << "determinant A = " << determinant(A4) << endl;
    inverseMatrix(A4);
    
    cout << "\n--- test 5 : add vectors with different dimensions---" << endl;
    Vector v1 = createVector(3);
    Vector v2 = createVector(2);
    addVectors(v1, v2);
    
    cout << "\n--- test 6 : normalize zero vector---" << endl;
    Vector v3 = createVector(3);
    v3.data[0] = 0; v3.data[1] = 0; v3.data[2] = 0;
    normalizeVector(v3);
}

int main() {
    cout << "in the name of god" << endl;
    cout << "final project for fundamentals of computer and programming course" << endl;
    cout << "matrice and vector operations library" << endl;
    cout << "==========================================\n" << endl;
    
    // نمایش عملیات ماتریسی
    demonstrateMatrixOperations();
    
    // نمایش عملیات برداری
    demonstrateVectorOperations();
    
    // نمایش مدیریت خطاها
    demonstrateErrorHandling();
    
    cout << "\n==========================================" << endl;
    cout << "test finished successfullu !" << endl;
    cout << "==========================================" << endl;
    
    return 0;
}
