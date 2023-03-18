#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#ifndef TASKS_RK1_H
#define TASKS_RK1_H

char* NewC1(const char* x);

class WorkWithFile{
private :
    char* NewD1 = new char[30];
    void readFromFile(const char* fileName){
        FILE* pFile;
        pFile = fopen(fileName, "r");
        fscanf(pFile, "%s", NewD1);
        fclose(pFile);
    }
    void prepareTestFile(const char* fileName){
        FILE* pFile;
        pFile = fopen(fileName, "w");
        int a = 20;
        int i;
        srand(time(nullptr));
        char b;
        for(i = 0; i < a; ++i){
          b=(rand() % ('z' - 'a' + 1)) + 'a';
          //if(b < 'a') b = ' ';
          fwrite(&b, 1, sizeof(b), pFile);
        }
        fclose(pFile);
    }
    
public :
    WorkWithFile(const char* fileName){
        prepareTestFile(fileName);
        readFromFile(fileName);
    }
    ~WorkWithFile(){
        delete[] NewD1;
    }
    
    void writeStatInfoToFile(const char* NewOut1){
        char* Sim1 = NewC1(NewD1);
        int* Arr1 = new int[strlen(Sim1)];
        for(int i = 0; i < strlen(Sim1); ++i){
          Arr1[i] = 0;
        }
        for(int i = 0; Sim1[i] != '\0'; ++i){
          for(int j = 0; j < strlen(NewD1); ++j){
            if(Sim1[i] == NewD1[j])
              Arr1[i]++;
          }
        }
        FILE* pFile = fopen(NewOut1, "w");
        for(int i = 0; i < strlen(Sim1); ++i){
          fprintf(pFile, "%c\t%d\n", Sim1[i], Arr1[i]);
        }
        fclose(pFile);
        delete[] Sim1;
        delete[] Arr1;
    }
};

char* ConvertDecToBin(int number);

void writeToFile(const char* fileName, const char* strNum);

void buildTree(int height);

#endif