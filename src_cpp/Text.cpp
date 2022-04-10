#include "Text.h"

#include "Factory.h"
// construct text object, generate words
Text::Text(std::string text) {
    match = false;
    size_t last = 0;
    for (size_t index = text.find_first_of(" "); index != std::string::npos;) {
        if (index - last > 0)
            words.push_back(new Word(text.substr(last, index - last)));
        last = index + 1;
        index = text.find_first_of(" ", last);
    }
    words.push_back(new Word(text.substr(last)));
}

Text::~Text() {
    for (auto i = words.begin(); i != words.end(); i++) delete *i;
}

void Text::find(std::string patternStr) {
    for (auto &word : words) {
        if (patternStr == word->getContent()) {
            match = true;
            word->setFound(true);
        }
    }
}

std::list<Row *> Text::shift() { return RowFactory::Singleton().shift(this); }

bool Text::isMatch() { return match; }

void Text::cleanFound() {
    for (auto &w : words) w->setFound(false);
}