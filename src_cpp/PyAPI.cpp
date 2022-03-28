#include "PyAPI.h"

PyAPI &PyAPI::Singleton() {
    if (!_singletonPtr) {
        _singletonPtr = new PyAPI();
    }
    return *_singletonPtr;
}

std::string PyAPI::getPassage() {
    //  return _passage->toStr();
}

void PyAPI::findWord(std::string s) {
    //
}

void PyAPI::sortPassage() {
    // _passage.sort()
}