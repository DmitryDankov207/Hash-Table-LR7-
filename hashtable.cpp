#include "hashtable.h"
#include <math.h>



HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    Table = new Node * [capacity];

    for(int i = 0; i < capacity; i++){
        Table[i] = new Node();
        Table[i] = nullptr;
    }
}

int HashTable::Hash(double value) {
    double mod;
    modf(value * (double)capacity, &mod);
    return (int)(0.13 * mod);
}

void HashTable::Push(double value) {
    Node * tmp = new Node;
    tmp->key = value;
    tmp->next = Table[Hash(value)];
    Table[Hash(value)] = tmp;
}

double HashTable::Pop(int i) {
    Node *out;
    double value;
    if (Table[i] == nullptr)
        perror("error");
    value = (Table[i])->key;
    out = Table[i];
    Table[i] =Table[i]->next;
    delete out;
    return value;
}

QString HashTable::StackToString(const Node *head) {
    QString out;
    while (head) {
        out.append(QString("%1").arg(head->key) + " ");
        head = head->next;
    }
    return out;
}


