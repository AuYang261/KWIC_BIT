#ifndef __Text_h__
#define __Text_h__

#include <list>
#include <string>
#include <vector>

#include "Word.h"

using std::size_t;
typedef std::list<Word *>::iterator WordIter;

class Row;

class Text {
   private:
    std::list<Word *> words;

   public:
    Text(std::string text);
    ~Text();

    void notify();
    void find(std::string pattern);
    std::list<Row *> shift();
    const std::list<Word *> &getWordsList() const { return words; }
};

#endif