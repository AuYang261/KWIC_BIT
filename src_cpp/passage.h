#ifndef PASSAGE_H
#define PASSAGE_H
#include <algorithm>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>

class Passage
{
public:
    list<Text *> texts;
    vector<Row *> rows;
    sortRow();
    void input(FILE *fp);
    string toStr();
};

#endif