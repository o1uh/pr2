#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141593
#include <stdio.h>
#include <locale.h> 
#include <iostream>
#include <conio.h> 
#include <math.h> 
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>


class Attestat {
public:
    int math = 0;
    int history = 0;
    int russian = 0;
    float avg = 0;
    
};
class Student {
public:
    char fio[25];
    Attestat att;
   
};

class Clas {
public:
    int num;
    char b[2];
    int count;
    Student stt[30];
    float avg;
    
};
class School {
public:
    int n_cl = 0;
    Clas cls[5];
    
};

void cl() { // ф-я очистки, только после нажатия
    printf("\n\nНажмите любую клавишу, чтобы продолжить...");
    _getch();
    system("cls");
}

void cl_ogl() { //ф-я вывода оглавления
    char ogl[][45] = {
        "Класс",
        "Количество учеников",
        "Средний балл аттестации"
    };
    printf("\n%s", ogl[0]);
    for (int i = 1; i < 3; i++)
        printf("%25s", ogl[i]);
    printf("\n");
}

void st_ogl() { //ф-я вывода оглавления
    char ogl[][45] = {
        "ФИО",
        "Математика",
        "История",
        "Русский язык",
        "Средний балл аттестации"
    };
    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("%25s", ogl[i]);
    printf("\n");
}

void menu() {
    char razdel[][35] = {
        "Вывод",
        "Добавление",
        "Удаление",
        "Редактирование",
        "Выход из программы"
    };
    for (int i = 0; i < 5; i++)
        printf("%d) %s\n", i + 1, razdel[i]);
    printf("\n");
}

void red_avg(School* scl, int n, int i) {
    float s = 0;
    (*scl).cls[n].stt[i].att.avg = ((*scl).cls[n].stt[i].att.math + (*scl).cls[n].stt[i].att.history + (*scl).cls[n].stt[i].att.russian) / 3.;
    for (int j = 0; j < (*scl).cls[n].count; j++) {
        s += (*scl).cls[n].stt[j].att.avg;
    }
    (*scl).cls[n].avg = s / float((*scl).cls[n].count);
}

void vivod_scl(School* scl, int n_class) {
    cl_ogl();
    for (int i = 0; i < n_class; i++) {
        printf("%4d%s %24d %24.2f\n", (*scl).cls[i].num, (*scl).cls[i].b, (*scl).cls[i].count, (*scl).cls[i].avg);
    }
}
void vivod_cls(School* scl, int i) {
    st_ogl();

    for (int j = 0; j < (*scl).cls[i].count; j++)
        printf("%d)%24s %24d %24d %24d %22.2f\n", j + 1, (*scl).cls[i].stt[j].fio, (*scl).cls[i].stt[j].att.math, (*scl).cls[i].stt[j].att.history, (*scl).cls[i].stt[j].att.russian, (*scl).cls[i].stt[j].att.avg);

}
void vivod(School* scl) {
    if ((*scl).n_cl > 0) {
        int v, c;
        do {
            printf("1)Вывод всех классов\n2)Вывод состава отдельного класса\n");
            printf("Введите пункт меню: ");
            v = scanf("%d", &c);
            while (getchar() != '\n');
            system("cls");
        } while (c > 2 || c < 1 || v < 1);
        switch (c)
        {
        case 2: {
            int num, p = 0;
            char b[2];
            do {
                printf("Введите номер класса (1-11): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
                system("cls");
            } while (num > 11 || num < 1 || v < 1);

            printf("Введите букву класса: ");
            fgets(b, 2, stdin);
            if (strlen(b) != 1)
                b[strlen(b) - 1] = '\0';
            if (b[strlen(b) - 1] == '\n' || strlen(b) == 1)
                while (getchar() != '\n');
            for (int i = 0; i < (*scl).n_cl; i++) {
                if (strcmp((*scl).cls[i].b, b) == 0 && num == (*scl).cls[i].num) {
                    vivod_cls(scl, i);
                    p = 1;
                    break;
                }
            }
            if (p == 0) {
                printf("Такого класса нет");

            }
            break;
        }
        case 1: {
            vivod_scl(scl, (*scl).n_cl);
            break;
        }

        default:
            break;
        }
    }
    else
        printf("База классов пуста.\n");
    cl();

}


int create_class(School* scl) {
    int st, summ = 0, s, n = (*scl).n_cl, c, num, v;
    char b[2], f[25];
    do {
        printf("1)Добавить класс\n2)Добавить ученика в класс\n");
        printf("Введите пункт меню: ");
        v = scanf("%d", &c);
        while (getchar() != '\n');
        system("cls");
    } while (c > 2 || c < 1 || v < 1);

    switch (c) {
    case 1: {
        if ((*scl).n_cl == 5) {
            printf("Места под классы больше нет");
            cl();
            return 0;
        }
        char;
        int;

        do {
            printf("Введите номер класса (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("Введите букву класса: ");
        fgets(b, 2, stdin);
        if (strlen(b) != 1)
            b[strlen(b) - 1] = '\0';
        if (b[strlen(b) - 1] == '\n' || strlen(b) == 1)
            while (getchar() != '\n');



        do {
            printf("Введите, сколько учеников хотите добавить: ");
            v = scanf("%d", &st);
            while (getchar() != '\n');
        } while (st < 1 || v < 1 || st > 30);
        strcpy((*scl).cls[n].b, b);
        (*scl).cls[n].num = num;
        (*scl).cls[n].count = st;
        (*scl).n_cl += 1;
        for (int i = 0; i < st; i++) {
            s = 0;
            printf("Ученик %d:\n", i + 1);
            printf("Введите ФИО: ");
            fgets(f, 26, stdin);
            if (strlen(f) != 25)
                f[strlen(f) - 1] = '\0';
            if (f[strlen(f) - 1] == '\n' || strlen(f) == 25)
                while (getchar() != '\n');
            strcpy((*scl).cls[n].stt[i].fio, f);

            do {
                printf("Введите аттестацию за математику (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.math = num;
            s += num;

            do {
                printf("Введите аттестацию за историю (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.history = num;
            s += num;
            do {
                printf("Введите аттестацию за русский (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.russian = num;
            s += num;
            (*scl).cls[n].stt[i].att.avg = float(s) / 3.f;
            summ += s;
        }

        (*scl).cls[n].avg = float(summ) / (float((*scl).cls[n].count) * 3.f);
        cl();
        break;
    }
    case 2: {
        if ((*scl).n_cl < 1) {
            printf("База классов пуста.\n");
            cl();
            return 0;
        }
        do {
            printf("Введите номер класса (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("Введите букву класса: ");
        fgets(b, 2, stdin);
        if (strlen(b) != 1)
            b[strlen(b) - 1] = '\0';
        if (b[strlen(b) - 1] == '\n' || strlen(b) == 1)
            while (getchar() != '\n');
        for (int i = 0; i < n; i++) {
            if (strcmp((*scl).cls[i].b, b) == 0 && num == (*scl).cls[i].num) {
                if ((*scl).cls[i].count == 30) {
                    printf("Места под учащихся больше нет");
                    cl();
                    return 0;
                }
                printf("Введите ФИО: ");
                fgets(f, 26, stdin);
                if (strlen(f) != 25)
                    f[strlen(f) - 1] = '\0';
                if (f[strlen(f) - 1] == '\n' || strlen(f) == 25)
                    while (getchar() != '\n');
                strcpy((*scl).cls[i].stt[(*scl).cls[i].count].fio, f);

                do {
                    printf("Введите аттестацию за математику (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].count].att.math = num;


                do {
                    printf("Введите аттестацию за историю (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].count].att.history = num;

                do {
                    printf("Введите аттестацию за русский (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].count].att.russian = num;

                (*scl).cls[i].count++;
                red_avg(scl, i, (*scl).cls[i].count - 1);
                cl();
            }
        }
        break;
    }
    default:
        break;
    }
}

void red_class(School* scl) {
    char b[2], f[25];
    int v, num, n = (*scl).n_cl, p = 0, att;

    do {
        printf("Введите номер класса (1-11): ");
        v = scanf("%d", &num);
        while (getchar() != '\n');
        system("cls");
    } while (num > 11 || num < 1 || v < 1);

    printf("Введите букву класса: ");
    fgets(b, 2, stdin);
    if (strlen(b) != 1)
        b[strlen(b) - 1] = '\0';
    if (b[strlen(b) - 1] == '\n' || strlen(b) == 1)
        while (getchar() != '\n');

    for (int i = 0; i < n; i++) {
        if (strcmp((*scl).cls[i].b, b) == 0 && num == (*scl).cls[i].num) {

            do {
                vivod_cls(scl, i);
                printf("Введите номер ученика, информацию которого хотите отредактировать: ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
                system("cls");
            } while (num - 1 > (*scl).cls[i].count || num < 1 || v < 1);

            do {
                vivod_cls(scl, i);
                printf("Введите номер пункта, который хотите отредактировать: ");
                v = scanf("%d", &p);
                while (getchar() != '\n');
                system("cls");
            } while (p > 4 || p < 1 || v < 1);

            switch (p) {
            case 1: {
                printf("Введите новое ФИО: ");
                fgets(f, 26, stdin);
                if (strlen(f) != 25)
                    f[strlen(f) - 1] = '\0';
                if (f[strlen(f) - 1] == '\n' || strlen(f) == 25)
                    while (getchar() != '\n');
                strcpy((*scl).cls[i].stt[num - 1].fio, f);
                break;
            }
            case 2: {
                do {
                    printf("Введите новую аттестацию за математику (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.math = att;
                red_avg(scl, i, num - 1);
                break;
            }
            case 3: {
                do {
                    printf("Введите новую аттестацию за историю (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.history = att;
                red_avg(scl, i, num - 1);
                break;
            }
            case 4: {
                do {
                    printf("Введите новую аттестацию за русский (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.russian = att;
                red_avg(scl, i, num - 1);
                break;
            }
            default:
                break;
            }

            p = 1;
            break;
        }

    }
    if (p == 0) {
        printf("Такого класса нет");
        cl();
    }

}
void del(School* scl) {
    char b[2], f[25];
    int v, num, n = (*scl).n_cl, p = 0, att;
    do {

        printf("1)удалить класс\n2)Удалить ученика\nВведите номер пункта, по которому будет происходить удаление: ");
        v = scanf("%d", &p);
        while (getchar() != '\n');
        system("cls");
    } while (p > 2 || p < 1 || v < 1);

    switch (p) {
        p = 0;
    case 1: {
        do {
            printf("Введите номер класса (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("Введите букву класса: ");
        fgets(b, 2, stdin);
        if (strlen(b) != 1)
            b[strlen(b) - 1] = '\0';
        if (b[strlen(b) - 1] == '\n' || strlen(b) == 1)
            while (getchar() != '\n');

        for (int i = 0; i < n; i++) {
            if (strcmp((*scl).cls[i].b, b) == 0 && num == (*scl).cls[i].num) {
                for (int j = i; j < n; j++) {
                    (*scl).cls[j] = (*scl).cls[j + 1];
                }
                (*scl).n_cl -= 1;
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("Такого класса нет");
        }
        break;
    }
    case 2: {
        do {
            printf("Введите номер класса (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("Введите букву класса: ");
        fgets(b, 2, stdin);
        if (strlen(b) != 2)
            b[strlen(b) - 1] = '\0';
        if (b[strlen(b) - 1] == '\n' || strlen(b) == 2)
            while (getchar() != '\n');

        for (int i = 0; i < n; i++) {
            if (strcmp((*scl).cls[i].b, b) == 0 && num == (*scl).cls[i].num) {
                do {
                    vivod_cls(scl, i);
                    printf("Введите номер ученика, информацию которого хотите отредактировать: ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                    system("cls");
                } while (num - 1 > (*scl).cls[i].count || num < 1 || v < 1);
                for (int j = num - 1; j < (*scl).cls[i].count; j++) {
                    (*scl).cls[i].stt[j] = (*scl).cls[i].stt[j + 1];
                }
                (*scl).cls[i].count -= 1;
                if ((*scl).cls[i].count == 0) {
                    for (int j = i; j < n; j++) {
                        (*scl).cls[j] = (*scl).cls[j + 1];
                    }
                    (*scl).n_cl -= 1;
                }
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("Такого класса нет");
        }
        break;
    }
    default:
        break;
    }
}