#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>

#ifndef TASKS_RK1_H
#define TASKS_RK1_H

char* NewC1(const char* x);

class WorkWithFile{
private :
    char* dataOfFile = new char[20];

    void readFromFile(const char* fileName);

    void prepareTestFile(const char* fileName);

public :
    WorkWithFile(const char* fileName);

    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);

};

char* convertDecToBin(int number);

void writeToFile(const char* fileName, const char* strNum);

char* convertBinToHex(const char* binNum);

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum);

void buildTree(int height);

std::vector<std::pair<int,float>> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

struct Node{
  Node* next;
  Node* prev;
  int nameNode;
  static int countNodes;
};

class LinkedList{
  private:
    Node* Head;
    Node* Tail;
  public:
    LinkedList();
    ~LinkedList();
    void push_back(int nameNode);
    void writeToFileFromHead();
    void writeToFileFromTail();
    void insert(int nameNode, int position);
    static void writeNodeToFile(Node* node, std::ofstream& pFile);
};

#endif
