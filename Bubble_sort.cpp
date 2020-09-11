#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void bubbleSort(double *array, int size);

int main() {
    int N;
    std::cout << "Please enter amount of elements" << std::endl;
    std::cin >> N;
    double* massive = (double*)malloc(N * sizeof(double));
    std::cout << "Please enter elements" << std::endl;
	for (int i = 0; i < N; i++) 
	    std::cin >> massive[i];
    std::cout << "Sorting..." << std::endl;
    bubbleSort(massive, N);
    for (int i = 0; i < N; i++)
        std::cout << massive[i] << " ";
    std::cout << std::endl;
	return 0;
}

void bubbleSort(double *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--){
            if (array[j - 1] > array[j]){
                double temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}