#pragma once

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <iostream>

namespace LinearAlgebra {

    template<typename T>
    class Matrix {
    private:
        T *_matrix;
        unsigned int _rows, _cols; // First, second and third dimensions

    public:
        Matrix(); // Constructor
        Matrix(unsigned int m, unsigned int n); // Constructor
        Matrix(unsigned int m, unsigned int n, T num); // Constructor
        Matrix(const Matrix<T> &mat); // Copy constructor
        virtual ~Matrix(); // Destructor

        T &operator()(unsigned int i, unsigned int j);

        T operator()(unsigned int i, unsigned int j) const;

        Matrix<T> &operator=(const Matrix<T> &mat); // Assigment operator;

        Matrix<T> &operator+(const Matrix<T> &mat); // Addition operator
        Matrix<T> &operator-(const Matrix<T> &mat); // soustraction operator
        Matrix<T> &operator*(const Matrix<T> &mat); // matrix multiplication operator

        void transpose();

        T det() throw(int);

        void inverse();

        void print() const;

        unsigned int *size() const;

    };
}

#include "Matrix.cpp"
#endif //MATH_MATRIX_H
