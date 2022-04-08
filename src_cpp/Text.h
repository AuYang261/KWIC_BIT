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
    virtual ~Text();

    void find(std::string patternStr);
    std::list<Row *> shift();
    bool isMatch();
    const std::list<Word *> &getWordsList() const { return words; }
    void cleanFound() {
        for (auto &w : words) w->setFound(false);
    }
};

#endif