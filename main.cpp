#include "tasks_rk1.h"

void task_1(){
  WorkWithFile a("sourceFile_task1.txt");
  a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
  writeToFile("result_task2.txt", ConvertDecToBin(20));
}

void task_4(){
  buildTree(10);
}

int main(){
  task_1();
  task_2();
  task_4();
  return 0;
}