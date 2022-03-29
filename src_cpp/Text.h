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
};
