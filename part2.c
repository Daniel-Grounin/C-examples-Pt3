/* Assignment3: Author- Daniel Grounin*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int symetric_SubMat();
int c_Matrix(int);

int main(){  //Question3 - function checks the multiples and divisors 
    int size = 8;
    int matrix[5][8] = { {1,2,0,3,2,1,0,7}, {2,3,4,1,2,3,4,5}, {3,4,6,2,5,6,7,6}, {4,5,7,3,6,8,9,8}, {6,7,1,4,7,9,0,9} };
    printf("Q3\n"); 
    printf("The Max symmetric sub-matrix starts at indexes [%d][%d] and its size is: %d\n", c_Matrix(matrix, size), c_Matrix(matrix, size), c_Matrix(matrix, size));
    //Question4 - function checks for MAX symmetric sub-matrix 
    printf("Q4\n");
    symetric_SubMat();
}

int symetric_SubMat(){
    int matrix[4][4] = { {250,90,1100,45}, {5,10,400,81}, {21,34,55,67}, {50,67,3,245} };
    int input, mult_counter = 0, Div_counter = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){ //scan our matrix
            matrix[i][j]; 
        }
           input = matrix[3][0]; //save input
    printf("%d is Selected\n\n", input);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
            if ((matrix[i][j] % input == 0) && (input < matrix[i][j])){ //if any element of the matrix divides by the input and without remainder and also need to be bigger then the input 
                mult_counter++;
                printf("the multiples are %d\n", matrix[i][j]);
            }
    }
    printf("\nNumber of multiples : %d\n\n", mult_counter);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
            if ((input % matrix[i][j] == 0) && (input > matrix[i][j])){ //if input divides by any elemnt of the matrix without remainder and also input needs to be bigger then the divisors
                Div_counter++;
                printf("the divisors are %d\n", matrix[i][j]); 
            }
    }
    printf("\nNumber of divisors : %d\n\n", Div_counter);
}

int c_Matrix(int size){
    int matrix[5][8] = { {1,2,0,3,2,1,0,7}, {2,3,4,1,2,3,4,5}, {3,4,6,2,5,6,7,6}, {4,5,7,3,6,8,9,8}, {6,7,1,4,7,9,0,9} };
    int counterR = 0, counterC = 0;
    int counter = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 8; j++){
            if ((matrix[i][j] == matrix[j][i]) && (matrix[i + 1][j] == matrix[j][i + 1])){ //check if elements on row and coumn are equal , and also the following elements is equal also
                counter++;
            }
        }
    }
    return counter;
}
