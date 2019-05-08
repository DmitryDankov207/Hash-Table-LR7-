#ifndef SORTEDHASHTABLE_H
#define SORTEDHASHTABLE_H
#include <hashtable.h>

class SortedHashTable : public HashTable
{
    void Insert(double);
    void Sort(int);
public:
    SortedHashTable(int capacity = 31);
    QStringList TableToString();
};

#endif // SORTEDHASHTABLE_H
