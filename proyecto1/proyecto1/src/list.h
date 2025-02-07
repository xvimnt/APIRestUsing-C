#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <string>
#include <list>

class BinaryTree
{

private:
  Professor *root;
  std::list<Data> param;

public:
  void add(Data data);
  BinaryTree();
  Professor *getRoot();
  void setRoot(Professor *professor);
  void Insert(Professor *professor, Professor *pointer);
  std::list<Data> getList();
  std::string getGraphic();
  std::string getGraphic2(Professor* node);
  Professor *get(std::string id);
  Professor *getParent(Professor* node);
  Professor *getSucesor(Professor* node);
  Professor *getPredecesor(Professor* node);
  void cleanParentPointer(Professor* node);
  void unlink(Professor* node);
  void modify(Professor *node, std::string newId, std::string newName);
  void Delete(Professor *node);
  void inOrden(Professor *node);
  void visita(Professor *node);
};

class CircularList
{
private:
  Course *first;
  Course *last;
  void Insert(Course *node);

public:
  void add(Data data);
  CircularList();
  Course *getFirst();
  Course *getLast();
  void setFirst(Course *node);
  void setLast(Course *node);
  std::list<Data> getList();
  std::string getGraphic();
  Course *get(std::string id);
  void modify(Course *node, std::string newId, std::string newName);
  void Delete(Course *node);
};

class doubleLinkedList
{
private:
  Build *first;
  Build *last;

public:
  Build *getFirst();
  Build *getLast();
  void setFirst(Build *node);
  void setLast(Build *node);
  void add(deuxData data);
  std::list<deuxData> getList();
  void Insert(Build *node);
  Build *get(std::string name);
  void modify(Build *node, std::string newName);
  void Delete(Build *node);
  std::string getGraphic();
  
};

class arrayList
{
private:
  Day *head;

public:
  Day *getHead();
  arrayList();
  void setHead(Day *node);
  void add(deuxData data);
  int getOrder(std::string dayName);
   std::string getGraphic();
};


class Salones{
  private:
    Salon* head;
  
  public:
    Salones();
    std::list<Data> getList();
    Salon* get(std::string id);
    void add(Data data);
    std::string getGraphic();
};

class Horarios
{
private:
  schedule *first;
  schedule *last;

public:
  schedule *getFirst();
  schedule *getLast();
  void setFirst(schedule *node);
  void setLast(schedule *node);
  void add(deuxData node);
  void Insert(schedule *node);
   std::string getGraphic();
};

#endif // LIST_H
