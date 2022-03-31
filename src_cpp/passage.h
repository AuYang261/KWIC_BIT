#ifndef PASSAGE_H
#define PASSAGE_H
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "Row.h"
#include "Text.h"

class Passage {
   private:
    std::list<Text *> texts;
    std::list<Row *> rows;

   public:
    Passage() : texts(), rows() {}
    virtual ~Passage() {}
    void sortRow();
    void input(std::string filename);
    std::string toStr();
    void findWords(std::string words);
};

#endif
