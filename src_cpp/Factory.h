#ifndef __Factory_h__
#define __Factory_h__

#include <list>
// #include <map>

#include "Row.h"
#include "Sortor.h"
#include "Text.h"

class RowFactory {
   private:
    inline static RowFactory* _singletonPtr;

    RowFactory() {}

   public:
    ~RowFactory() {}
    static RowFactory& Singleton();
    std::list<Row*> shift(Text* _text);
};

class SortorFactory {
   private:
    inline static SortorFactory* _singletonPtr;
    // std::map<std::string, Sortor*> Sortors;
    SortorFactory() {}

   public:
    virtual ~SortorFactory() {}
    static SortorFactory& Singleton();
    Sortor* create(std::string strategy);
};

#endif