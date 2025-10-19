#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
/*Функция вывода массива с заданным через переменную размером*/
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std :: cout << " " << arr[i];
    }
}
void scanf_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std :: cin >> arr[i];
    }
}
/*Функция декорации*/
void dec(int t) {
    for (int i = 0; i <= t; i++) {
        cout << "-";
    }
    cout << "\n\n";
}
int main()
{
    int n = 12, arr[n];
    dec(30);
    int at;
    cout << "Введите 1 для создания матрицы со случайными значениями: ";
    cin >> at;
    srand(time(NULL));
    if (at == 1) {
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10;
        }
    }
    else {
        scanf_arr(arr, n);
    }
    cout << "Входные данные: ";
    print_arr (arr, n);
    cout << "\n\n";
    printf ("|%d\t%d\t%d\t%d|\n", arr[0], arr[1], arr[2], arr[3]); //Первая строка массива
    printf ("|%d\t%d\t%d\t%d|\n", arr[4], arr[5], arr[6], arr[7]); //Вторая строка
    printf ("|%d\t%d\t%d\t%d|\n", arr[8], arr[9], arr[10], arr[11]); //Третья
    dec(30);

    int sum = 0;
    int sr; //Среднее значение
    int arr2[n];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    sr = sum / n;
    // cout << sr;
    for (int i = 0; i < n; i++) {
        if (arr[i] > sr) {
            arr2[i] = arr[i] - sr;
        }
        if (arr[i] <= sr) {
            arr2[i] = sr - arr[i];
        }
    }
    // cout << "\nРазница: ";
    // print_arr (arr2, n);
    /*Определение мин элемента*/
    int minIndex = 0, minValue = arr2[0];
    for (int i = 0; i < n; i++) {
        if (arr2[i] < minValue) {
            minValue = arr2[i];
            minIndex = i; 
        }
    }
    // cout << "\n" << minIndex << endl;
    
    if (minIndex == 0 || minIndex == 4 || minIndex == 8) {
        cout << "n = 1" << endl;
    }
    if (minIndex == 1 || minIndex == 5 || minIndex == 9) {
        cout << "n = 2" << endl;
    }
    if (minIndex == 2 || minIndex == 6 || minIndex == 10) {
        cout << "n = 3" << endl;
    }
    if (minIndex == 3 || minIndex == 7 || minIndex == 11) {
        cout << "n = 4" << endl;
    }

    /*Определяем строчку*/
    if (minIndex == 0 || minIndex == 1|| minIndex == 2|| minIndex == 3) {
        cout << "m = 1" << endl;
    }
    if (minIndex == 4 || minIndex == 5|| minIndex == 6|| minIndex == 7) {
        cout << "m = 2" << endl;
    }
    if (minIndex == 8 || minIndex == 9|| minIndex == 10|| minIndex == 11) {
        cout << "m = 3" << endl;
    }
    dec(30);
    return 0;
}
