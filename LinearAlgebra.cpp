
#include "LinearAlgebra.h"
#include <iostream>

namespace LinearAlgebra {

    template<typename T>
    Matrix<T>& diag(const Matrix<T> &mat) {

        unsigned int lenght = mat.size()[1];

        Matrix<T> diagMatrix(lenght,lenght);

        for (int i = 1; i <= lenght; i++){
            for (int j = 1; j <= lenght; j++){
                if (i==j){
                    diagMatrix(i,j) = mat(1,i);
                }
                else {
                    diagMatrix(i, j) = 0;
                }
            }
        }


        return diagMatrix;
    }



}