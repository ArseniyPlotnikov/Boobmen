#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{   
    int arr[20];
    int n;
    printf ("Введите кол-во элементов массива: ");
    scanf ("%d", &n);
    if (n>20 || n <= 0) {
        printf ("Ошибка ввода n");
        return 1;
    }
    /*at - переменная для автоматического содания массива arr[20] = {1, 2 ,3, ...20}*/
    int at;
    printf ("Создать массив автоматически от 1 до %d?", n);
    printf (" Введите цифру 1, если да: ");
    scanf ("%d", &at);
    if (at == 1) {
        printf ("Ваш массив: ");
        printf ("\n");
        for (int i = 0; i < n; i++) {
            arr [i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    }
    else {
        if (n == 1) {
            printf ("Введите %d число: ", n);
        }
        if (n ==2 || n == 3 ||n == 4) {
            printf ("Введите %d числа: ", n);
        }
        if (n != 1 && n != 2 && n != 3 && n !=4) {
            printf ("Введите %d чисел: ", n);
        }
        for (int i = 0; i < n; i++) {
            printf ("Введите %d элемент: ", i+1);
            scanf ("%d", &arr[i]);
        }
        printf ("\nВаш массив: ");
        for (int i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    }
    printf ("\n\n");
    int minValue = arr[0], maxValue = arr[0], minIndex, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= minValue) {
            minValue = arr[i];
            minIndex = i;
        } 
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
    arr[minIndex] = maxValue;
    arr[maxIndex] = minValue;

    printf ("Ваш массив, если поменять самый большой и самый маленький элемент местами: ");
    for (int i = 0; i < n; i++) {
       printf ("%d ", arr[i]);
    }
    /*Массив состоящий из элементов, которые делятся на 3 или 5*/
    int arr2[20], j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0) {
            arr2[j] = arr[i];
            j++;
        }
    }
    if (j == 0) {
        printf ("\nВ вашем массиве нет элементов, которые делятся на 3 или 5");
    }
    else {
        printf ("\nНовый массив, состоящий из элементов массива 1, которые делятся на 3 или 5: ");
        for (int i = 0; i < j; i ++) {
            printf ("%d ", arr2[i]);
        }   
     }
    printf ("\n\n");
    /*Сортировка 1 массива по возрастанию*/
    printf ("\nСортировка массива 1 по возрастанию: ");
    int temp; //Временная переменная
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    /*Сортировка массива по убыванию*/
    printf ("\nСортировка массива 1 по убыванию: ");
    int tic;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j <n-1; j++) {
            if (arr[j] < arr[j+1]) {
                tic = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tic;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    return 0;
}