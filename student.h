#pragma once
class Student {
private:
    char fio[25];

public:
    Attestat att;
    Student() {}
    void setFio(char nFio[25]) {
        strcpy(fio, nFio);
    }
    char* getFio() {
        return fio;
    }

};