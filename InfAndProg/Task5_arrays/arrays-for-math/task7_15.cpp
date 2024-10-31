#include<iostream>

int** GetPascalTriangle(int *size) {
    std::cout <<"n = ";
    std::cin >> *size; // кол-во строк треугольника
    if (!std::cin or *size < 1) {
        std::cerr << "Invalid size" << std::endl;
        return nullptr;
    }

    int **myArray = new int *[*size + 1];
    for (int i = 0; i <= *size; i++)
        myArray[i] = new int [i + 1]; //выделяем память под i-ую строку

    myArray[0][0] = 1;
    myArray[1][0] = myArray[1][1] = 1;
    for (int i = 2; i <= *size; i++){
        myArray[i][0] = 1;
        for (int j = 1; j < i; j++)
            myArray[i][j] = myArray[i-1][j-1] + myArray[i-1][j];
        myArray[i][i] = 1;
    }

    return myArray;
}

void PrintFractal(int **array, const int *size) {
    char term;
    for (int i = 0; i <= *size; i++, std::cout << std::endl) {
        for (int j = 0; j <=i; j++) {
            term = array[i][j]%2 ? 'A' : ' ';
            std::cout << term << " ";
        }
    }
}

int main(){
    int size;
    int **myArray = GetPascalTriangle(&size);

    PrintFractal(myArray, &size);

    for (int i = 0; i < size; i++) {
        delete [] myArray[i];
    }
    delete [] myArray;
    return 0;
}