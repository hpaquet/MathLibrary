#pragma once

#include "Matrix.h"

namespace LinearAlgebra {

    template<typename T>
    Matrix<T>::Matrix() {
        _matrix = new T[0];
    }

    template<typename T>
    Matrix<T>::Matrix(unsigned int m, unsigned int n) : _rows(m), _cols(n) {
        _matrix = new T[_rows * _cols];
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix <T> &mat) {
        _rows = mat._rows;
        _cols = mat._cols;
        _matrix = new T[_rows * _cols];

        for (int i = 0; i < _rows * _cols; i++) {
            _matrix[i] = mat._matrix[i];
        }
    }

    template<typename T>
    Matrix<T>::Matrix(unsigned int m, unsigned int n, T num) {

    }

    template<typename T>
    Matrix<T>::~Matrix() {
        delete[] this->_matrix;
    }

    template<typename T>
    T &Matrix<T>::operator()(unsigned int i, unsigned int j) {
        if (i - 1 > _rows || j - 1 > _cols) {
            std::cerr << "Invalid index ...\n";
        }
        return _matrix[j - 1 + _cols * (i - 1)];
    }

    template<typename T>
    T Matrix<T>::operator()(unsigned int i, unsigned int j) const {
        if (i - 1 > _rows || j - 1 > _cols) {
            std::cerr << "Invalid index ...\n";
        }
        return _matrix[j - 1 + _cols * (i - 1)];
    }

    template<typename T>
    Matrix <T> &Matrix<T>::operator=(const Matrix <T> &mat) {
        if (&mat == this)
            return *this;

        _rows = mat.size()[0];
        _cols = mat.size()[1];

        for (int i = 0; i < _rows * _cols; i++) {
            _matrix[i] = mat._matrix[i];
        }

        return *this;
    }

    template<typename T>
    Matrix <T> &Matrix<T>::operator+(const Matrix <T> &mat) {
        if (_cols == mat._cols && _rows == mat._rows) {
            for (int i = 0; i < _rows * _cols; i++) {
                _matrix[i] = _matrix[i] + mat._matrix[i];
            }
        }

        return *this;
    }

    template<typename T>
    Matrix <T> &Matrix<T>::operator-(const Matrix <T> &mat) {
        if (_cols == mat._cols && _rows == mat._rows) {
            for (int i = 0; i < _rows * _cols; i++) {
                _matrix[i] = _matrix[i] - mat._matrix[i];
            }
        }
        return *this;
    }

    template<typename T>
    Matrix <T> &Matrix<T>::operator*(const Matrix <T> &mat) {
        if (_cols == mat._rows) {
            Matrix newMatrix(_rows, mat._cols);
            T sum = 0;
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < mat._cols; j++) {
                    for (int k = 0; k < mat._cols; k++) {
                        sum += (*this)(i + 1, k + 1) * mat(k + 1, j + 1);
                    }

                    newMatrix(i + 1, j + 1) = sum;
                    sum = 0;
                }
            }
            *this = newMatrix;

            return *this;
        }
        std::cerr << "Matrix dimension missmatch";
    }

    template<typename T>
    void Matrix<T>::print() const {
        std::cout << "Matrix :" << std::endl;
        for (int i = 1; i <= _rows; i++) {
            for (int j = 1; j <= _cols; j++) {
                std::cout << _matrix[(_cols * (i - 1) + j) - 1] << " ";
            }
            std::cout << " " << std::endl;
        }
        std::cout << " " << std::endl << std::endl;
    }

    template<typename T>
    unsigned int *Matrix<T>::size() const {
        unsigned int size[2]{_rows, _cols};
        return size;
    }

    template<typename T>
    void Matrix<T>::transpose() {
        Matrix<int> mat(_cols, _rows);
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                mat(j + 1, i + 1) = (*this)(i + 1, j + 1);
            }
        }

        *this = mat;

    }

    template<typename T>
    void Matrix<T>::inverse() {

    }

    template<typename T>
    T Matrix<T>::det() throw(int){
        T _det = 0;
        if (_rows == _cols && _rows != 1) {
            int sign = 1;
            for (int i = 1; i <= _rows; i++) {

                Matrix<T> mat(_rows-1,_rows-1);

                for (int j=1; j<= _rows; j++){
                    for (int k = 1; k<= _cols; k++){
                        if (k < i && k != i && j != 1)
                            mat(j-1,k) = (*this)(j,k);
                        else if (k>i && k != i && j != 1 )
                            mat(j-1,k-1) = (*this)(j,k);
                    }
                }

                _det += (*this)(1,i)*sign*mat.det();

                sign *= -1;

            }

            return _det;

        }
        else if (_rows == _cols && _rows == 1){

            return (*this)(1,1);
        }
        else
            throw -1;

    }


}