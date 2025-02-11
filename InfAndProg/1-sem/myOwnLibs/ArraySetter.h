#pragma once
#include <iostream>

class SetArray {
    public:
        SetArray();

        int* oneDim(int *size);

        int** twoDim(int *size);

        int** twoDim(int *rows, int *cols);
};