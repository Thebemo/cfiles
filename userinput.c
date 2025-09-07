#include <stdio.h>

int main(){


char name[25];//bytes
int age;


printf("Wat ur name bruv: ");
//scanf("%s", name);
fgets(name, 25, stdin);

printf("How old are you: ");
scanf("%d", &age);

printf("Hello %s, you are %d years old \n",name, age);


return 0;
}
