
#ifndef MATH_LINEARALGEBRA_H
#define MATH_LINEARALGEBRA_H

#include "Matrix.h"

namespace LinearAlgebra {

    template<typename T>
    Matrix<T> &diag(const Matrix<T> &mat);

    template<typename T>
    Matrix<T> &ones(unsigned int dim);

    template<typename T>
    Matrix<T> &zeros(unsigned int rows, unsigned int cols);

}

#include "LinearAlgebra.cpp"

#endif //MATH_LINEARALGEBRA_H

