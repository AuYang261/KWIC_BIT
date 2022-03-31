#ifndef PASSAGE_H
#define PASSAGE_H
#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Text.h"

class Passage
{
public:
    std::list<Text *> texts;
    std::vector<Row *> rows;
    void sortRow();
    void input(std::string filename);
    std::string toStr();
};

#endif
