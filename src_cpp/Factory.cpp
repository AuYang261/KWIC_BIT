#include "Factory.h"

std::list<Row*> RowFactory::shift(Text* _text) {
    auto ret = new std::list<Row*>;
    for (auto i = _text->getWordsList().begin();
         i != _text->getWordsList().end(); i++) {
        ret->push_back(new Row(i, *_text));
    }
    return *ret;
}

RowFactory& RowFactory::Singleton() {
    if (!_singletonPtr) {
        _singletonPtr = new RowFactory();
    }
    return *_singletonPtr;
}

SortorFactory& SortorFactory::Singleton() {
    if (!_singletonPtr) {
        _singletonPtr = new SortorFactory();
    }
    return *_singletonPtr;
}

Sortor* SortorFactory::create(std::string strategy) {
    if (strategy == "Sortor1") {
        return new Sortor1();
    } else if (strategy == "Sortor2") {
        return new Sortor2();
    }
    return new Sortor1();  // default
}