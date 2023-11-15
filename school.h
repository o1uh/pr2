#pragma once




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


