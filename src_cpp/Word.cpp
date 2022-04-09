#include "Word.h"

Word::Word(std::string initContent) {
    content = initContent;
    flagFound = false;
}

Word::~Word() {}

std::string Word::getContent() { return content; }

void Word::updateContent(std::string newContent) {
    content = newContent;
    flagFound = false;
}

// return if the word match the pattern, 1=matches
bool Word::isFound() { return flagFound; }

// set flagFound, 1=matches
void Word::setFound(bool found) { flagFound = found; }