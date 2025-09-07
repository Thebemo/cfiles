#include <stdio.h>

void evenNums();
void minMax();

int main(){

evenNums();
minMax();

return 0;
}

void evenNums(){

int arr[10];
int x = 2;
int length = sizeof(arr) / sizeof(int);

for(int i = 0; i < length; i++){
 arr[i] = x;
 x+=2;
}

for(int i = 9; i >= 0; i-- ){
 printf("%d ", arr[i]);
}

printf("\n");

}

void minMax(){
 int arr[10];
 int num;
 int length = sizeof(arr) / sizeof(int);

 for(int i = 0; i < length; i++){
 printf("Enter a number: ");
 scanf("%d ", &num);
 arr[i] = num;

}

int min = arr[0];
int max = arr[0];
int sum = 0;
int avg = 0;

for(int i = 0; i < length; i++){
 printf("%d " , arr[i]);
 sum+=arr[i];

 if(arr[i] < min ) min = arr[i];
 if(arr[i] > max ) max = arr[i];
}
avg = sum / length;

printf("\n The max: %d , min: %d and average number: %d \n", max, min, avg);
}
