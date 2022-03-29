#indef ROW_H
#define ROW_H
// Row.h
#include <algorithm>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>
class Row
{
public:
    std::list<Word *>::iterator pos;
    bool operator<(Row *a) const;
    string toStr();
};
#endif