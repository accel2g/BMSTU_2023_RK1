#include <cstring>
#include <fstream>
#include "tasks_rk1.h"

char* NewC1(const char* x){
  char* NewS1 = new char[20];
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

void WorkWithFile::readFromFile(const char *fileName){
  FILE* pFile;
  pFile = fopen(fileName, "r");
  fscanf(pFile, "%s", dataOfFile);
  fclose(pFile);
}

void WorkWithFile::prepareTestFile(const char *fileName){
  FILE* pFile;
  pFile = fopen(fileName, "w");
  int l = 20;
  int i;
  srand(time(nullptr));
  char b;
  for(i = 0; i < l; ++i){
    b = (rand() % ('z' - 'a' + 1)) + 'a';
    if(b < 'a')
      b = ' ';
    fwrite(&b, 1, sizeof(b), pFile);
  }
  fclose(pFile);
}

WorkWithFile::WorkWithFile(const char *fileName){
  prepareTestFile(fileName);
  readFromFile(fileName);
}

WorkWithFile::~WorkWithFile(){
  delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char *outFile){
  char* c = NewC1(dataOfFile);
  int* count = new int[strlen(c)];
  for(int i = 0; i < strlen(c); ++i){
    count[i] = 0;
  }
  for(int i = 0; c[i] != '\0'; ++i){
    for(int j = 0; j < strlen(dataOfFile); ++j){
      if(c[i] == dataOfFile[j])
        count[i]++;
    }
  }
  FILE* pFile = fopen(outFile, "w");
  for(int i = 0; i < strlen(c); ++i){
    fprintf(pFile, "%c\t%d\n", c[i], count[i]);
  }
  fclose(pFile);
  delete[] c;
  delete[] count;
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

char* convertDecToBin(int number){
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

char* convertBinToHex(const char* binNum){
  int len = strlen(binNum);
  char* hexNum = new char[(len+3)/4 + 1];
  int i = len - 1;
  int j = 0;
  while(i >= 0){
    int sum = 0, base = 1;
    for(int k = 0; k < 4; ++k){
      if(i >= 0){
        sum += (binNum[i] - '0') * base;
        base *= 2;
        --i;
      }
    }
    if(sum < 10) hexNum[j] = sum + '0';
    else hexNum[j] = sum - 10 + 'A';
    ++j;
  }
  hexNum[j] = '\0';
  int hexLen = strlen(hexNum);
  for(int k = 0; k < hexLen/2; ++k)
    std::swap(hexNum[k], hexNum[hexLen - k - 1]);
  return hexNum;
}

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum){
  FILE* pFile = fopen(fileName, "w");
  fprintf(pFile, "%s\t%s", binNum, hexNum);
  fclose(pFile);
}

void randFill(float* ar, int N){
  for(int i = 0; i < N; i++){
    ar[i] = static_cast<float>(rand())/RAND_MAX;
  }
}

std::vector<std::pair<int,float>> averStr2DArray(const float* ar, int colCount, int rowCount){
  std::vector<std::pair<int,float>> res(rowCount);
  for(int i = 0; i < rowCount; i++){
    float sum = 0;
    for(int j = 0; j < colCount; j++){
      sum += ar[i * colCount + j];
    }
    res[i] = std::make_pair(i,sum/colCount);
  }
  return res;
}

int Node::countNodes = 0;

LinkedList::LinkedList(){
  Head = nullptr;
  Tail = nullptr;
}

LinkedList::~LinkedList(){
  Node* current = Head;
  while(current != nullptr){
    Node* next = current->next;
    delete current;
    current = next;
  }
  Head = nullptr;
  Tail = nullptr;
}

void LinkedList::push_back(int nameNode){
  Node* node = new Node;
  node->prev = Tail;
  node->next = nullptr;
  node->nameNode = nameNode;
  if(Tail != nullptr)
    Tail->next = node;
  else
    Head = node;
  Tail = node;
  Node::countNodes++;
}

void LinkedList::writeToFileFromHead(){
  std::ofstream pFile("result_task6_7.txt");
  Node* current = Head;
  while(current != nullptr){
    writeNodeToFile(current, pFile);
    current = current->next;
  }
  pFile.close();
}

void LinkedList::writeToFileFromTail(){
  std::ofstream pFile("result_task6_7.txt");
  Node* current = Tail;
  while(current != nullptr){
    writeNodeToFile(current, pFile);
    current = current->prev;
  }
  pFile.close();
}

void LinkedList::insert(int nameNode, int position){
  if(position <= 0 || position > Node::countNodes + 1)
    return;
  Node* node = new Node;
  node->nameNode = nameNode;
  if(position == 1){
    node->prev = nullptr;
    node->next = Head;
    if(Head != nullptr)
      Head->prev = node;
    else
      Tail = node;
    Head = node;
  }
  else if(position == Node::countNodes + 1){
    node->prev = Tail;
    node->next = nullptr;
    if(Tail != nullptr)
      Tail->next = node;
    else
      Head = node;
    Tail = node;
  }
  else{
    Node* current = Head;
    for(int i = 1; i < position; i++)
      current = current->next;
    node->prev = current->prev;
    node->next = current;
    current->prev->next = node;
    current->prev = node;
  }
  Node::countNodes++;
}

void LinkedList::writeNodeToFile(Node* node, std::ofstream& pFile){
  pFile << "Node" << node->nameNode << ";";
}
