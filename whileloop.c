#include <stdio.h>

//#define SIZE 10

// Function to display the array contents
void displayArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the average of array elements
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    int numbers[SIZE];
    int num = 10;
    int i = 0;

    // Storing numbers in reverse order using a while loop
    while (i < SIZE) {
        numbers[i] = num;
        num--;
        i++;
    }

    // Display array contents
    displayArray(numbers, SIZE);

    // Calculate and display the average
    printf("Average: %.2f\n", calculateAverage(numbers, SIZE));

    return 0;
}
