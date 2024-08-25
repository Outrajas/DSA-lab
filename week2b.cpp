#include <iostream>
using namespace std;

void createSparseArray(int sparseMatrix[][3], int rows, int cols, int sparseArray[], int &size) {
    size = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                sparseArray[size++] = i;         
                sparseArray[size++] = j;         
                sparseArray[size++] = sparseMatrix[i][j]; 
            }
        }
    }
}

void reconstructMatrix(int sparseArray[], int size, int rows, int cols, int originalMatrix[][3]) {
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            originalMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i += 3) {
        int row = sparseArray[i];
        int col = sparseArray[i + 1];
        int value = sparseArray[i + 2];
        originalMatrix[row][col] = value;
    }
}

int main() {
    int rows = 3, cols = 3;

    int sparseMatrix[3][3] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };

    int sparseArray[9];
    int size; 
    cout << "Original sparse Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    createSparseArray(sparseMatrix, rows, cols, sparseArray, size);

    int originalMatrix[3][3];

    reconstructMatrix(sparseArray, size, rows, cols, originalMatrix);

    cout << "Reconstructed Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << originalMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

