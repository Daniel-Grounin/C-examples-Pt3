/* Assignment3: Author- Daniel Grounin*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int subArray(int, int, int, int);
int LongestSeries(int, int);

int main(){
	printf("Q1\n");//Question1 - function checks if the smaller array is sub-array of the other (ascending)
	int size1 = 10, size2 = 9;
	int ar1[10] = { -3,8,23,-60,-5,46,87,-43,12,-7 };
	printf("Anount of series is: %d\n", LongestSeries(ar1, size1));
	printf("\n");
	printf("Q2\n");//Question2 - function checks for longest series and how many of them exist 
	int arr1[10] = { 1,1,1,2,5,7,4,9,5,3 }; 
	int arr2[9] = { 1,1,2,5,7,4,9,5,3 };
	printf("The sub-array starts at index %d\n", subArray(size2, arr2, size1, arr1));
}

int subArray(int size1, int arr1[], int size2, int arr2[]){
	int tempSize = 0;
	int counter = 0;
	if (size1 < size2){ //check which array is bigger
		for (int i = 0; i < size2; i++){
			if (arr2[i] == arr1[0]){ //if arr elements is equal to first element in array 
				if (i + size1 > size2) //if there is no existance
					return -1;
				else
					for (int j = 0; j < size1; j++){
						if (arr1[j] == arr2[i + j]) //run on the second array and check if we got equal elements ,if so counter will run
							counter++;
						if (counter == size1) //if the array is fully equal
							return i;
					}
			}
			counter = 0;
		}
	}
	else{ //vice verca
		for (int i = 0; i < size1; i++) {
			if (arr1[i] == arr2[0]){
				if (i + size2 > size1)
					return -1;
				else
					for (int j = 0; j < size2; j++){
						if (arr2[j] == arr1[i + j])
							counter++;
						if (counter == size2)
							return i;
					}
			}
			counter = 0;
		}
	}
	return -1;
}

int LongestSeries(int arr[], int size){
	int amount = 0;
	int counter = 1;
	int biggest = 0;
	int indexOfBiggest = 0;
	for (int i = 0; i < size - 1; i++){
		if (arr[i] < arr[i + 1]){ //checks the amount of series that we need
			amount++;
			for (int j = i; j < size - 1; j++){
				if (arr[j] < arr[j + 1]) //if the last index value is smaller then the following element in array 
					counter++; 
				else{
					if (biggest < counter){ //find what is index of the first element
						biggest = counter; 
						indexOfBiggest = i;
					}
					counter = 1;
					i = j;
					break;
				}

			}
		}
	}
	printf("Longest series:");
	for (int i = indexOfBiggest; i < indexOfBiggest + biggest; i++) {
		printf(" %d", arr[i]); // print the elements of longest series
	}
	printf("\n");
	return amount; //return the amount of series
}

