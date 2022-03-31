#ifndef _ROW_H_
#define _ROW_H_
// Row.h
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

#include "Text.h"
#include "Word.h"
class Row {
   public:
    Row(std::list<Word *>::const_iterator i, Text &t) : pos(i), _text(t) {}
    std::list<Word *>::const_iterator pos;  //����operator�鷳��ȫ��д��public
    Text &_text;
    bool operator<(Row &a);  //����const ��ΪҪ����
    std::string toStr();
};
#endif
