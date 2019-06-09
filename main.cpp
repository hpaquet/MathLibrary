
#include <iostream>

#include "Matrix.h"
#include "LinearAlgebra.h"

using  namespace LinearAlgebra;

int main() {

    try {

        Matrix<int> mat1(3, 3);
        Matrix<int> mat4(4, 4);
        Matrix<int> mat2(1, 4);
        //Matrix<int> mat3;

        mat1(1, 1) = 1;
        mat1(1, 2) = 0;
        mat1(1, 3) = 2;
        mat1(2, 1) = 0;
        mat1(2, 2) = 2;
        mat1(2, 3) = 0;
        mat1(3, 1) = 2;
        mat1(3, 2) = 0;
        mat1(3, 3) = 4;


        mat1.print();

        mat2(1, 1) = 2;
        mat2(1, 2) = 4;
        mat2(1, 3) = 6;
        mat2(1, 4) = 8;

        std::cout << "Determinant = " << mat2.det() << std::endl;

        //mat4 = diag(mat2);

        //mat4.print();

    }
    catch(const int err){
        std::cerr << "Error " << err << " ...";
    }

    return 0;
}