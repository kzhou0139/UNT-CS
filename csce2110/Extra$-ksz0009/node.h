//Kelly Zhou
//ksz0009
//node.h

#ifndef NODEH
#define NODEH

class Node {
  public:
    int data;
    Node* next;
  
    Node();
    Node(int data);
    int getData();
    int setData(int d);
};

#endif
