#ifndef __Factory_hpp__
#define __Factory_hpp__

#include <list>

#include "Row.h"
#include "Text.h"

class RowFactory {
   private:
    inline static RowFactory* _singletonPtr;

   public:
    RowFactory(/* args */);
    ~RowFactory();
    static RowFactory& Singleton();
    std::list<Row*> shift(Text* _text);
};

RowFactory::RowFactory(/* args */) {}

RowFactory::~RowFactory() {}

RowFactory& RowFactory::Singleton() {
    if (!_singletonPtr) {
        _singletonPtr = new RowFactory();
    }
    return *_singletonPtr;
}

std::list<Row*> RowFactory::shift(Text* _text) {
    auto ret = new std::list<Row*>;
    for (auto i = _text->getWordsList().begin();
         i != _text->getWordsList().end(); i++) {
        ret->push_back(new Row(i, *_text));
    }
    return *ret;
}

#endif