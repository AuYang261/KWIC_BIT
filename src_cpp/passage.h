#ifndef PASSAGE_H
#define PASSAGE_H
#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "Row.h"
#include "Sortor.h"
#include "Text.h"

class Passage {
   private:
    std::list<Text *> texts;
    std::list<Row *> rows;
    Sortor *sortor;
    bool findMode;  // 查找模式，不显示不含查找词的行
    void setSortor(Sortor *newSortor) {
        delete sortor;
        sortor = newSortor;
    }

   public:
    Passage() : texts(), rows(), sortor(new Sortor1()), findMode(false) {}
    virtual ~Passage() { delete sortor; }
    void sortRow(std::string strategy);
    std::string input(std::string filename);
    std::string toStr();
    void findWords(std::string words);
};

#endif
