#pragma once
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