// Row.h
#ifndef __Row_h__
#define __Row_h__

#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Text.h"
#include "Word.h"

class Row {
   public:
    Row(std::list<Word *>::const_iterator i, Text &_text)
        : pos(i), _text(_text) {}
    bool operator<(Row *a) const;
    std::string toStr();

   private:
    std::list<Word *>::const_iterator pos;
    Text &_text;
};

#endif