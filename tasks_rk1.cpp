#include <cstring>
#include "tasks_rk1.h"

char* NewC1(const char* x){
  char* NewS1 = new char[30];
  int count = 0;
  for(int i = 0; i < strlen(x); ++i){
    int k = 0;
    for(int j = i; j > 0; j--){
      if(x[i] == x[j-1]){
        count++;
        k++;
        break;
      }
    }
    if(k == 0){
      NewS1[i - count] = x[i];
      NewS1[i - count + 1] = '\0';
    }
  }
  return NewS1;
}

char* ConvertDecToBin(int number){
  char* S2 = new char[33];
  int count = 0;
  for(int i = 32; number > 0; i--){
    S2[i] = number%2 + '0';
    number /= 2;
    count++;
  }
  char* NewS2 = new char[count];
  int k = 33 - count;
  for(int i = 0; i < count; ++i){
    NewS2[i] = S2[k++];
    NewS2[i+1] = '\0';
  }
  delete[] S2;
  return NewS2;
}

void writeToFile(const char* fileName, const char* strNum){
  FILE* pFile = fopen(fileName, "w");
  fprintf(pFile, "%s", strNum);
  fclose(pFile);
}

void buildTree(int height){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < height - 1 -i; j++){
      std::cout << ' ';
    }
    for(int k = 0; k < (2 * i + 1); k++){
      std::cout << '*';
    }
    std::cout << '\n';
  }
}