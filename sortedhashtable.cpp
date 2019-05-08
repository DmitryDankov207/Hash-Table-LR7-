#include "sortedhashtable.h"

SortedHashTable::SortedHashTable(int capacity) : HashTable(capacity)
{

}

QStringList SortedHashTable::TableToString() {
    QStringList out;
    for (int var = 0; var < this->capacity; ++var) {
        if(Table[var] != NULL){
            Sort(var);
            out.push_back(StackToString(Table[var]));
        }
    }
    return out;
}

void SortedHashTable::Insert(double value_1) {
    if (Table[Hash(value_1)]) {
        double value_2 = Table[Hash(value_1)]->key;
        if (value_1 > value_2) {
            Pop(Hash(value_1));
            Insert(value_1);
            Push(value_2);
        }
        else if (value_1 == value_2);
        else
            Push(value_1);
    }
    else
        Push(value_1);
}

void SortedHashTable::Sort(int i) {
    if (Table[i]) {
        double value = Pop(i);
        Sort(i);
        Insert(value);
    }
}
