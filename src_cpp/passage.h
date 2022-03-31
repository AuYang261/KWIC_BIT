#ifndef PASSAGE_H
#define PASSAGE_H
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "Text.h"
#include "row.h"

class Passage {
   public:
    std::list<Text *> texts;
    std::list<Row *> rows;
    void sortRow();
    void input(std::string filename);
    std::string toStr();
};

#endif
