#include "PyAPI.h"

PyAPI &PyAPI::Singleton() {
    if (!_singletonPtr) {
        _singletonPtr = new PyAPI();
    }
    return *_singletonPtr;
}

std::string PyAPI::readFile(std::string filePath) {
    return _passage->input(filePath);
}

std::string PyAPI::getPassage() { return _passage->toStr(); }

void PyAPI::findWords(std::string words) { _passage->findWords(words); }

void PyAPI::sortPassage() { _passage->sortRow(); }