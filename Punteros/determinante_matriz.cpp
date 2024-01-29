#include <iostream>
using namespace std;

int **matrizEnteros, numFilas, numColumnas;

/**
 * Function to read input data for a matrix.
 * Prompts the user to enter the number of rows and columns,
 * dynamically allocates memory for the matrix,
 * and reads the values for each element of the matrix.
 */
void leerDatosMatriz() {
  cout << "Ingrese el numero de filas: ";
  cin >> numFilas;
  cout << "Ingrese el numero de columnas: ";
  cin >> numColumnas;

  matrizEnteros = new int *[numFilas];
  for (int i = 0; i < numFilas; i++) {
    matrizEnteros[i] = new int[numColumnas];
  }

  for (int i = 0; i < numFilas; i++) {
    for (int j = 0; j < numColumnas; j++) {
      cout << "Matriz[" << i << "," << j << "]: ";
      cin >> matrizEnteros[i][j];
    }
  }
}

/**
 * Prints the elements of a matrix.
 * 
 * @param matrizEnteros The matrix of integers.
 * @param numFilas The number of rows in the matrix.
 * @param numColumnas The number of columns in the matrix.
 */
void imprimirMatriz(int **matrizEnteros, int numFilas, int numColumnas) {
  for (int i = 0; i < numFilas; i++) {
    for (int j = 0; j < numColumnas; j++) {
      cout << matrizEnteros[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 * Calculates the determinant of a square matrix.
 * 
 * @param matrizEnteros The input matrix as a 2D array of integers.
 * @param numFilas The number of rows in the matrix.
 * @param numColumnas The number of columns in the matrix.
 * @return The determinant of the matrix as a float value.
 */
float determinante(int **matrizEnteros, int numFilas, int numColumnas) {
  float det = 1, aux;
  float pivote, pivote1;
  int n;

  if (numFilas == numColumnas) {
    n = numFilas;
  }
  // Convertimos la matriz de enteros a una de floats
  float **matrizAux = new float *[numFilas];
  for (int i = 0; i < numFilas; i++) {
    matrizAux[i] = new float[numColumnas];
    for (int j = 0; j < numColumnas; j++) {
      matrizAux[i][j] = matrizEnteros[i][j] * 1.0;
    }
  }

  // Reducción por renglones
  for (int i = 0; i < n; i++) {
    pivote = matrizAux[i][i];
    for (int j = i + 1; j < n; j++) {
      pivote1 = matrizAux[j][i];
      aux = (pivote1 * 1.0) / pivote;
      for (int k = 0; k < n; k++) {
        matrizAux[j][k] = matrizAux[j][k] - aux * matrizAux[i][k];
      }
    }
  }

  // Calculamos del determinante
  for (int i = 0; i < n; i++) {
    det *= matrizAux[i][i];
  }
  return det;
}

int main() {
  cout << "*****OPERACIONES CON MATRICES*****" << endl;
  leerDatosMatriz();
  cout << "Matriz Ingresada:" << endl;
  imprimirMatriz(matrizEnteros, numFilas, numColumnas);

  if (numFilas == numColumnas) {
    cout << endl
         << "Determinante:   "
         << determinante(matrizEnteros, numFilas, numColumnas);
  } else {
    cout << endl
         << "Solo se pueden calcular el determinante en matrices cuadradas";
  }
}