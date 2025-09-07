#include <stdio.h>

int main(){

    int x = 0;
    int sum;

    do {

        printf("Enter a positive number: ");
        scanf("%d", &x);

    } while ( x < 0);

    printf("You entered: %d \n", x);


    for ( int i = x; i > 0; i--){
        if(i % 2 == 1) sum += i;
    }
    
    printf("sum of all odd integers <= %d : %d \n", x, sum);

   return 0;
}