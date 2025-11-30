#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void dec(int n) {
    for (int i = 0; i != n; i++) {
        printf("-");
    }
    printf("\n");
}
int main()
{   
    dec (30);
    bool running = true;
    char arr[MAX_SIZE][MAX_SIZE];
    while (running)
    {   
        printf("a. Create a text file\nb. Output file contents\nc. Count the number of words in each line\nd. Write the line with the most words to another file\ne. Exit\n");
        printf ("Enter command: ");
        char answer;
        scanf("%c", &answer);
        if (answer == 'e') {
            running = false;
            dec(30);
        }
        if (answer == 'a') {
            int n;    
            printf ("Enter n: ");
            scanf ("%d", &n);
            printf("Enter str: \n");
            FILE *fw = fopen("string.txt", "w");
            if (!fw) {
                printf("Error opening file!\n");
                continue;
            }
            for (int i = 0; i < n; i++) {
                printf("Enter line %d: ", i + 1);
                fgets(arr[i], MAX_SIZE, stdin);
                arr[i][strcspn(arr[i], "\n")] = 0;
                fprintf(fw, "%s\n", arr[i]);
            }
            fclose(fw);
            printf("File created successfully.\n");
            dec(30);
        } 
        if (answer == 'b') {
            FILE *fr = fopen("string.txt", "r");
            if (!fr) {
                printf("File not found! Create it first.\n");
                continue;
            }
            int m = 0;
            while (fgets(arr[m], MAX_SIZE, fr)) {
                arr[m][strcspn(arr[m], "\n")] = 0;
                m++;
            }
            fclose(fr);
            printf("Your str: ");
            for (int i = 0; i < m; i++) {
                printf("%s\n", arr[i]);
            }
            dec(30);
        }
        if (answer == 'c') {
            
        }
        if (answer == 'd') {

        }
    }
    return 0;
}