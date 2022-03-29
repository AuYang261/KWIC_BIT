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
    std::list<Word *>::iterator pos;//我嫌operator麻烦，全部写成public
    bool operator<(Row&a);//不能const 因为要调用 
    std::string toStr();
};
#endif
