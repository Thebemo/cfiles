#include <stdio.h>
#include <string.h>

int fileProcessor();
const char* passOrFail(float avg);

int main(){

    fileProcessor();

    return 0;
}

const char* passOrFail(float avg){

    if(avg >= 50) return "PASS";

    return "FAIL";
}

int fileProcessor(){

    char fileName[50];
    char name[50];
    int t1,t2;
    float avg;

    FILE *infile, *outfile;


    printf("Enter a file name: ");
    fgets(fileName, sizeof(fileName), stdin);

    fileName[strcspn(fileName, "\n")] = '\0';



    infile = fopen(fileName, "r");
    if(infile == NULL ){
        printf("Unable to open %s for reading ", fileName);
        return 1;
    }

    outfile = fopen("status.txt", "w");
    if(outfile == NULL){
        printf("Unable to create status.txt for writing");
        return 1;
    }

    while(fscanf(infile, "%s %d %d", name, &t1 , &t2) == 3){

        avg = (t1 + t2) / 2.0;

        fprintf(outfile, "%s %s \n" , name, passOrFail(avg));
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
