#pragma once
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