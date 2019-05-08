#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QString>
#include<QStringList>

class HashTable
{
protected:
    int capacity;    
    void InitTable();
    double Pop(int); 
public:
    struct Node{
        double key;
        Node *next;
    };
    QString StackToString(const Node *head);
    Node ** Table;
    HashTable(int capacity = 31);
    int Hash(double);
    void Push(double);
};

#endif // HASHTABLE_H
