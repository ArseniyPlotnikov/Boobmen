#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIN_FILE "books.dat"
#define TXT_FILE "books.txt"

struct Book
{
    char title[100];
    char author[100];
    int pages;
};

void inputBooks(Book* books, int n) {
    for (int i = 0; i < n; i++) {
        printf_s("\nКнига %d\n", i + 1);
        printf_s("Название: ");
        getchar();
        fgets(books[i].title, 100, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0';

        printf_s("Автор: ");
        fgets(books[i].author, 100, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf_s("Количество страниц: ");
        scanf_s("%d", &books[i].pages);
    }
}

void printBooks(Book* books, int n) {
    for (int i = 0; i < n; i++) {
        printf_s("\nНазвание: %s\nАвтор: %s\nСтраниц: %d\n",
            books[i].title, books[i].author, books[i].pages);
    }
}

void writeBinary(Book* books, int n) {
    FILE* f;
    fopen_s(&f, BIN_FILE, "wb");
    if (!f) return;

    fwrite(books, sizeof(Book), n, f);
    fclose(f);
}

int readBinary(Book** books) {
    FILE* f;
    fopen_s(&f, BIN_FILE, "rb");
    if (!f) return 0;

    fseek(f, 0, SEEK_END);
    int n = ftell(f) / sizeof(Book);
    rewind(f);

    *books = (Book*)malloc(n * sizeof(Book));
    fread(*books, sizeof(Book), n, f);
    fclose(f);

    return n;
}

void searchByTitle() {
    Book* books;
    int n = readBinary(&books);
    if (n == 0) return;

    char title[100];
    printf_s("Введите название: ");
    getchar();
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf_s("\nНайдено:\nАвтор: %s\nСтраниц: %d\n",
                books[i].author, books[i].pages);
            free(books);
            return;
        }
    }

    printf_s("Книга не найдена\n");
    free(books);
}

void addBookToFile() {
    FILE* f;
    fopen_s(&f, BIN_FILE, "ab");
    if (!f) return;

    Book b;
    getchar();

    printf_s("Название: ");
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf_s("Автор: ");
    fgets(b.author, 100, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf_s("Количество страниц: ");
    scanf_s("%d", &b.pages);

    fwrite(&b, sizeof(Book), 1, f);
    fclose(f);
}

void sortByTitle() {
    Book* books;
    int n = readBinary(&books);

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(books[i].title, books[j].title) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }

    writeBinary(books, n);
    free(books);
}

void writeTextAll() {
    Book* books;
    int n = readBinary(&books);
    FILE* f;
    fopen_s(&f, TXT_FILE, "w");
    if (!f) return;

    for (int i = 0; i < n; i++)
        fprintf(f, "%s | %s | %d\n",
            books[i].title, books[i].author, books[i].pages);

    fclose(f);
    free(books);
}

void writeTextByPages() {
    int limit;
    printf_s("Введите минимальное количество страниц: ");
    scanf_s("%d", &limit);

    Book* books;
    int n = readBinary(&books);
    FILE* f;
    fopen_s(&f, TXT_FILE, "w");
    if (!f) return;

    for (int i = 0; i < n; i++)
        if (books[i].pages > limit)
            fprintf(f, "%s | %s | %d\n",
                books[i].title, books[i].author, books[i].pages);

    fclose(f);
    free(books);
}

void printTextFile() {
    FILE* f;
    fopen_s(&f, TXT_FILE, "r");
    if (!f) return;

    char line[256];
    while (fgets(line, 256, f))
        printf_s("%s", line);

    fclose(f);
}

int main() {
    int choice, n = 0;
    Book* books = NULL;

    while (running)
    {
        printf_s("\n--- МЕНЮ ---\n");
        printf_s("1. Создать массив книг\n");
        printf_s("2. Вывести массив\n");
        printf_s("3. Записать в бинарный файл\n");
        printf_s("4. Поиск по названию\n");
        printf_s("5. Добавить книгу в файл\n");
        printf_s("6. Сортировать по названию\n");
        printf_s("7. Записать все книги в текстовый файл\n");
        printf_s("8. Записать книги по количеству страниц\n");
        printf_s("9. Вывести текстовый файл\n");
        printf_s("0. Выход\n");
        printf_s("Выбор: ");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf_s("Количество книг: ");
            scanf_s("%d", &n);
            books = (Book*)malloc(n * sizeof(Book));
            inputBooks(books, n);
            break;
        case 2:
            printBooks(books, n);
            break;
        case 3:
            writeBinary(books, n);
            break;
        case 4:
            searchByTitle();
            break;
        case 5:
            addBookToFile();
            break;
        case 6:
            sortByTitle();
            break;
        case 7:
            writeTextAll();
            break;
        case 8:
            writeTextByPages();
            break;
        case 9:
            printTextFile();
            break;
        }
    }
    free(books);
    return 0;
}

