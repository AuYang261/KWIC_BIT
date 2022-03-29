#include "Text.h"

Text::Text(std::string text)
{
	size_t last = 0;
	for (size_t index = text.find_first_of(" "); index != std::string::npos;)
	{
		if (index - last > 0)
			words.push_back(new Word(text.substr(last, index - last)));
		last = index + 1;
		index = text.find_first_of(" ", last);
	}
	words.push_back(new Word(text.substr(last)));
}

// possibly need completion
Text::~Text()
{
	for (WordIter i = words.begin(); i != words.end(); i++)
		delete *i;
}

// return a list of rotated rows
std::list<Row *> Text::shift()
{
	
}