#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
using namespace std;

template<class T>

struct NodeType{
    T data;
   struct  NodeType<T> *next;
   struct  NodeType<T> *back;
};

template<class T>
class DoublyLinkedList{

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &item);
    void deleteItem(T &item);
    int lengthIs();
    void print();
    void printReverse();
    void initialize(T number);

    //check return type
    void deleteSubsection(int lowerBound, int upperBound);
    void mode();
    void swapAlternate();

private:
    int length;
    T value;
    NodeType<T> *head;
    NodeType<T> *tail;
    NodeType<T> *item;

    int lowerBound;
    int upperBound;
};
#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
