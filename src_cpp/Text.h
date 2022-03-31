#ifndef __Text_h__
#define __Text_h__

#include <list>
#include <string>

#include "Word.h"

class Row;

class Text {
   private:
    std::list<Word *> words;

   public:
    Text(std::list<std::string> words);  // need args
    ~Text();

    void notify();
    void find(std::string pattern);
    std::list<Row *> shift();
    const std::list<Word *> &getWordsList() const { return words; }
};

#endif