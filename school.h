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
private:
    int math;
    int history;
    int russian;
    float avg;

public:
    Attestat() {
        math = 0;
        history = 0;
        russian = 0;
        avg = 0;
    }
    void setMath(int nMath) {
        math = nMath;
    }
    void setHistory(int nHistory) {
        history = nHistory;
    }
    void setRussian(int nRussian) {
        russian = nRussian;
    }
    void setAvg() {
        avg = (float(math) + float(history) + float(russian)) / 3.;
    }
    int getMath() {
        return math;
    }
    int getHistory() {
        return history;
    }
    int getRussian() {
        return russian;
    }
    float getAvg() {
        return avg;
    }
};

class Student {
private:
    char fio[25];
    
public:
    Attestat att;
    Student() {}
    void setFio(char nFio[25]){
        strcpy(fio, nFio);
    }
    char* getFio() {
        return fio;
    }
    
};

class Clas {
private:
    int num;
    char b[2];
    int count;
    float avg;
    
public:    Student stt[30];
    Clas() {}
    void setNum(int nNum) {
        num = nNum;
    }
    void setB(char nB[2]) {
        strcpy(b, nB);
    }
    void setCount(int nCount) {
        count = nCount;
    }
    void setAvg(float nAvg) {
        avg = nAvg;
    }
    int getNum() {
        return num;
    }
    char* getB() {
        return b;
    }
    int getCount() {
        return count;
    }
    float getAvg() {
        return avg;
    }

};
class School {
private:
    int n_cl;
    
public:
    Clas cls[5];
    School() {
        n_cl = 0;
    }
    void setN_cl(int nN_cl) {
        n_cl = nN_cl;
    }
    int getN_cl() {
        return n_cl;
    }
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
    (*scl).cls[n].stt[i].att.setAvg();
    for (int j = 0; j < (*scl).cls[n].getCount(); j++) {
        s += float((*scl).cls[n].stt[j].att.getAvg());
    }
    (*scl).cls[n].setAvg(s / float((*scl).cls[n].getCount()));
}

void vivod_scl(School* scl, int n_class) {
    cl_ogl();
    for (int i = 0; i < n_class; i++) {
        printf("%4d%s %24d %24.2f\n", (*scl).cls[i].getNum(), (*scl).cls[i].getB(), (*scl).cls[i].getCount(), (*scl).cls[i].getAvg());
    }
}
void vivod_cls(School* scl, int i) {
    st_ogl();

    for (int j = 0; j < (*scl).cls[i].getCount(); j++)
        printf("%d)%24s %24d %24d %24d %22.2f\n", j + 1, (*scl).cls[i].stt[j].getFio(), (*scl).cls[i].stt[j].att.getMath(), (*scl).cls[i].stt[j].att.getHistory(), (*scl).cls[i].stt[j].att.getRussian(), (*scl).cls[i].stt[j].att.getAvg());

}
void vivod(School* scl) {
    if ((*scl).getN_cl() > 0) {
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
            for (int i = 0; i < (*scl).getN_cl(); i++) {
                if ((*(*scl).cls[i].getB()) == b[0] && num == (*scl).cls[i].getNum()) {
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
            vivod_scl(scl, (*scl).getN_cl());
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
    int st, s = 0, n = (*scl).getN_cl(), c, num, v;
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
        if (n == 5) {
            printf("Места под классы больше нет");
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



        do {
            printf("Введите, сколько учеников хотите добавить: ");
            v = scanf("%d", &st);
            while (getchar() != '\n');
        } while (st < 1 || v < 1 || st > 30);
        (*scl).cls[n].setB(b);
        (*scl).cls[n].setNum(num);
        (*scl).cls[n].setCount(st);
        (*scl).setN_cl((*scl).getN_cl() + 1);
        for (int i = 0; i < st; i++) {
            printf("Ученик %d:\n", i + 1);
            printf("Введите ФИО: ");
            fgets(f, 26, stdin);
            if (strlen(f) != 25)
                f[strlen(f) - 1] = '\0';
            if (f[strlen(f) - 1] == '\n' || strlen(f) == 25)
                while (getchar() != '\n');
            (*scl).cls[n].stt[i].setFio(f);

            do {
                printf("Введите аттестацию за математику (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setMath(num);
            s += num;

            do {
                printf("Введите аттестацию за историю (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setHistory(num);
            s += num;
            do {
                printf("Введите аттестацию за русский (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setRussian(num);
            s += num;
            (*scl).cls[n].stt[i].att.setAvg();
        }
        (*scl).cls[n].setAvg(float(s) / (float((*scl).cls[n].getCount()) * 3.f));
        cl();
        break;
    }
    case 2: {
        c = 0;
        if (n < 1) {
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
            if (*(*scl).cls[i].getB() == b[0] && num == (*scl).cls[i].getNum()) {
                if ((*scl).cls[i].getCount() == 30) {
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
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].setFio(f);

                do {
                    printf("Введите аттестацию за математику (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setMath(num);


                do {
                    printf("Введите аттестацию за историю (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setHistory(num);

                do {
                    printf("Введите аттестацию за русский (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setRussian(num);

                (*scl).cls[i].setCount((*scl).cls[i].getCount() + 1);
                red_avg(scl, i, (*scl).cls[i].getCount() - 1);
                
                c = 1;
            }
        }
        if (c == 0)
            printf("Такого класса нет");
        cl();
        break;
        
    }
    default:
        break;
    }
}


void red_class(School* scl) {
    char b[2], f[25];
    int v, num, n = (*scl).getN_cl(), p = 0, att;

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
        if (*(*scl).cls[i].getB() == b[0] && num == (*scl).cls[i].getNum()) {

            do {
                vivod_cls(scl, i);
                printf("Введите номер ученика, информацию которого хотите отредактировать: ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
                system("cls");
            } while (num - 1 > (*scl).cls[i].getCount() || num < 1 || v < 1);

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
                (*scl).cls[i].stt[num - 1].setFio(f);
                break;
            }
            case 2: {
                do {
                    printf("Введите новую аттестацию за математику (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setMath(att);
                red_avg(scl, i, num - 1);
                break;
            }
            case 3: {
                do {
                    printf("Введите новую аттестацию за историю (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setHistory(att);
                red_avg(scl, i, num - 1);
                break;
            }
            case 4: {
                do {
                    printf("Введите новую аттестацию за русский (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setRussian(att);
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
    int v, num, n = (*scl).getN_cl(), p = 0, att;
    do {

        printf("1)удалить класс\n2)Удалить ученика\nВведите номер пункта, по которому будет происходить удаление: ");
        v = scanf("%d", &p);
        while (getchar() != '\n');
        system("cls");
    } while (p > 2 || p < 1 || v < 1);

    switch (p) {
        
    case 1: {
        p = 0;
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

        for (int i = 0; i < n; i++) { // через деструктор?
            if (*(*scl).cls[i].getB() == b[0] && num == (*scl).cls[i].getNum()) {
                for (int j = i; j < n; j++) {
                    (*scl).cls[j] = (*scl).cls[j + 1];
                }
                (*scl).setN_cl((*scl).getN_cl()-1);
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("Такого класса нет");
            cl();
        }
        break;
    }
    case 2: {
        p = 0;
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
            if (*(*scl).cls[i].getB() == b[0] && num == (*scl).cls[i].getNum()) {
                do {
                    vivod_cls(scl, i);
                    printf("Введите номер ученика, информацию которого хотите удалить: ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                    system("cls");
                } while (num - 1 > (*scl).cls[i].getCount() || num < 1 || v < 1);
                for (int j = num - 1; j < (*scl).cls[i].getCount(); j++) {
                    (*scl).cls[i].stt[j] = (*scl).cls[i].stt[j + 1];
                }
                (*scl).cls[i].setCount((*scl).cls[i].getCount() - 1);
                if ((*scl).cls[i].getCount() == 0) {
                    for (int j = i; j < n; j++) {
                        (*scl).cls[j] = (*scl).cls[j + 1];
                    }
                    (*scl).setN_cl((*scl).getN_cl() - 1);
                }
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("Такого класса нет");
            cl();
        }
        break;
    }
    default:
        break;
    }
}