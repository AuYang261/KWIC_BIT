#ifndef _ROW_H_
#define _ROW_H_
// Row.h
#include <algorithm>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Word.h"
class Row
{public:
    std::list<Word *>::iterator pos;//����operator�鷳��ȫ��д��public
    bool operator<(Row&a);//����const ��ΪҪ���� 
    std::string toStr();
};
#endif
