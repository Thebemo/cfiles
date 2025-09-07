#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in, *out;
    char account[10], name[50], box[30], town[30], phone[15];
    float balance;
    int lineNum = 0;
    float total = 0;

    in = fopen("clients.txt", "r");
    out = fopen("debts.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Problem opening file.\n");
        return 1;
    }

    // Write header to debts.txt
    fprintf(out, "A list of Gaborone customers owing at least P500\n");
    fprintf(out, "===============================================\n");

    // Read one record at a time
    while (fscanf(in, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
                  account, name, box, town, phone, &balance) == 6) {
        if (strcmp(town, "Gaborone") == 0 && balance >= 500) {
            lineNum++;
            fprintf(out, "%d. %s | %s | %s | %.2f\n", lineNum, account, name, phone, balance);
            total += balance;
        }
    }

    // Final summary
    fprintf(out, "\nTotal of %d client(s) owing at least P500 from Gaborone.\n", lineNum);
    fprintf(out, "Total owed: P%.2f\n", total);

    fclose(in);
    fclose(out);
    return 0;
}
