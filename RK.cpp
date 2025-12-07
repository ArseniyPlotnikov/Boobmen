#include <stdio.h> 
#include <stdlib.h>
void dec(int n) {
    for (int i = 0; i != n; i++) {
        printf("-");
    }
    printf("\n");
}

struct worker
{
    char lastname[20];
    char firstname[20];
    char patronymic[20];
    char job_title[20];
    char gender[20];
    int year;
};

void cin_worker (struct worker arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите фамилию %d работника: ", i+1);
         scanf("%s", arr[i].lastname);
        printf("Введите имя %d работника: ", i+1);
         scanf("%s", arr[i].firstname);
        printf("Введите отчество %d работника: ", i+1);
         scanf("%s", arr[i].patronymic);
        printf("Введите должность: ");
         scanf("%s", arr[i].job_title);
        printf("Введите пол работника: ");
         scanf("%s", arr[i].gender);
        printf("Введите год найма: ");
         scanf("%d", &arr[i].year);
        printf("\n\n");
    }
}
void cout_worker (struct worker arr[], int i) {
    printf("Данные %d сотрудника: \n", i+1);
    printf(" Имя: %s\n", arr[i].firstname);
    printf(" Фамилия: %s\n", arr[i].lastname);
    printf(" Отчество: %s\n", arr[i].patronymic);
    printf(" Должность: %s\n", arr[i].job_title);
    printf(" Пол: %s\n", arr[i].gender);
    printf(" Год найма: %d", arr[i].year);
    printf("\n\n");
}  
int main()
{   

    system("chcp 65001");
    system("cls");
    dec(30);
    const int size = 5;
    struct worker arr[size];
    cin_worker(arr, size);
    float sr;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += 2025 - arr[i].year;
    } 
    sr = sum / size;
    printf("Работники чей стаж меньше среднего: \n");
    for (int i = 0; i < size; i++) {
        if ((2025 - arr[i].year) < sr) {
            cout_worker(arr, i);
        } 
    }
    dec(30);
    return 0;
}
