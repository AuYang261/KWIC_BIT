/* @brief: 排序策略类基类及各子类
 */

#ifndef __Sortor_h__
#define __Sortor_h__

#include <algorithm>
#include <list>
#include <string>

#include "Row.h"

class Sortor {
   protected:
    Sortor() {}

   public:
    virtual void sort(std::list<Row *> &rows) = 0;
    virtual ~Sortor() {}
    virtual bool isMe(std::string name) = 0;
};

class Sortor1 : public Sortor {
   protected:
   public:
    Sortor1() {}
    virtual ~Sortor1() {}

    virtual void sort(std::list<Row *> &rows);
    virtual bool isMe(std::string name) { return name == "Sortor1"; }
};

class Sortor2 : public Sortor {
   protected:
   public:
    Sortor2() {}
    virtual ~Sortor2() {}

    virtual void sort(std::list<Row *> &rows);
    virtual bool isMe(std::string name) { return name == "Sortor2"; }
};

#endif
