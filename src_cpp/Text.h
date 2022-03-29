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
};
