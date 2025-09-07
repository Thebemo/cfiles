#include <stdio.h>
#include <ctype.h>
#include <string.h>

void menu();
int fileProcessor();
void stringProcessor();

int main(){

char ch;

while(1){
 menu();
ch = getchar();

while(getchar() != '\n'); // consume the newline character

if (toupper(ch) == 'F') { fileProcessor();}
else if (toupper(ch) == 'S') { stringProcessor();}
else if (toupper(ch) == 'Q') { return 0;}
else {printf("Invalid input!! ");}
}


return 0;
}

void menu(){
 printf("\nChoose an option below \n");
 printf("F for file processing \n");
 printf("S for string processing \n");
 printf("Q for program termination \n");
}

void stringProcessor(){
char arr[100];

printf("Enter a string: ");
fgets(arr, sizeof(arr), stdin);

arr[strcspn(arr, "\n")] = '\0';

printf("You entered: %s \n", arr);
printf("Length: %lu \n ", strlen(arr));
}

int fileProcessor(){

//char fileName[100];
char studID[9];
int t1,t2;
float avg;

FILE *infile, *outfile;

//printf("Enter file name: ");
//fgets(fileName, 100, stdin);

//fileName[strcspn(fileName, "\n")] = '\0';

infile = fopen("students.txt", "r");
if( infile == NULL ) {
 printf("Couldnt open file for reading \n");
 return 1;
}

outfile = fopen ("results.txt" , "w");
if( outfile == NULL ) {
 printf("Couldnt create file for writing \n");
 return 1;
}

while(fscanf(infile, "%s %d %d ", studID, &t1, &t2) == 3){

avg = (t1 + t2) / 2.0;

fprintf(outfile, "%s %.1f%% \n", studID, avg);

}

fclose(infile);
fclose(outfile);
return 0;
}
