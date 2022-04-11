#ifndef _ROW_H_
#define _ROW_H_
// Row.h
#include <stdlib.h>

#include <iostream>
#include <list>
#include <string>

#include "Text.h"

class Word;

class Row {
   private:
    std::list<Word *>::const_iterator pos;  //����operator�鷳��ȫ��д��public
    Text &_text;

   public:
    Row(std::list<Word *>::const_iterator i, Text &t) : pos(i), _text(t) {}
    virtual ~Row() {}
    bool operator<(Row &a);  //����const ��ΪҪ����
    std::string toStr(bool format = false);
    bool isMatch() { return _text.isMatch(); }
};
#endif
