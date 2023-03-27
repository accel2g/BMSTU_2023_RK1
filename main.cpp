#include "tasks_rk1.h"

void task_1(){
  WorkWithFile a("sourceFile_task1.txt");
  a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
  srand(time(nullptr));
  int num = rand() % 1000;
  printf("Number to convert in second task: %d\n", num);
  char* NewS2 = convertDecToBin(num);
  writeToFile("result_task2.txt", NewS2);
  delete[] NewS2;
}

void task_3(){
  srand(time(nullptr));
  char binNum[65] = "";
  int j = rand() % 64;
  for(int i = 0; i < j; ++i)
    binNum[i] = rand() % 2 + '0';
  char* hexNum = convertBinToHex(binNum);
  writeToFile("result_task3.txt", true, hexNum, binNum);
  delete[] hexNum;
}

void task_4(){
  buildTree(10);
}

void task_5(){
  const int N = 5;
  const int M = 3;
  float ar[N][M];
  randFill(&ar[0][0], N*M);
  std::vector<std::pair<int,float>> res = averStr2DArray(&ar[0][0],M,N);
  FILE* pFile = fopen("result_task5.txt", "w");
  for(std::pair<int,float> p:res)
    fprintf(pFile, "%d\t%c\t%f\n", p.first, ':', p.second);
  fclose(pFile);
}

void task_6(){
  LinkedList list;
  for(int i = 1; i <= 10; i++)
    list.push_back(i);
  list.writeToFileFromHead();
  list.writeToFileFromTail();
}

void task_7(){
  LinkedList list;
  for(int i = 1; i <= 10; i++)
    list.push_back(i);
  list.insert(11,1);
  list.insert(12,5);
  list.insert(13,12);
  list.writeToFileFromHead();
}

int main(){
  task_1();
  task_2();
  task_3();
  task_4();
  task_5();
  task_6();
  task_7();
  return 0;
}
