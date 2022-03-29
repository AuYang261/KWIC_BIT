#ifndef __Text_h__
#define __Text_h__

#include <list>
#include <string>
#include <vector>

#include "Word.h"

using std::size_t;

class Row;

class Text {
   private:
    std::list<Word *> words;
    bool match;

public:
    Text(std::string text);
    ~Text();

    void find(std::vector<std::string> patterns);
    // std::list<Row *> shift();
    bool isMatch();
    const std::list<Word *> &getWordsList() const { return words; }
};

#endif