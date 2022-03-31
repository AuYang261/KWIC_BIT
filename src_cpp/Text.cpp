#include "Text.h"

#include "Factory.hpp"

// !!!!!!!!!!!!!!!!
// need completion
// construct words
Text::Text(std::list<std::string> words) {}

// possibly need completion
Text::~Text() {}

void Text::find(std::string pattern) {}

// return a list of rotated rows
std::list<Row *> Text::shift() { return RowFactory::Singleton().shift(this); }