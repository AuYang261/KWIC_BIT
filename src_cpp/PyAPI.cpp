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

std::string PyAPI::getPassage() {
    std::string s = _passage->toStr();
    std::ofstream o("../output.txt");
    o << s;
    return s;
    // return _passage->toStr();
}

void PyAPI::findWords(std::string words) { _passage->findWords(words); }

void PyAPI::sortPassage(std::string strategy) { _passage->sortRow(strategy); }