#include "Text.h"

// construct text object, generate words
Text::Text(std::string text)
{
	match = false;
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

Text::~Text()
{
	for (auto i = words.begin(); i != words.end(); i++)
		delete *i;
}

void Text::find(std::string patternStr)
{
	std::vector<std::string> patterns;
	match = true;
	
	// split the patterns
	size_t last = 0;
	for (size_t index = patternStr.find_first_of(" "); index != std::string::npos;)
	{
		if (index - last > 0)
			patterns.push_back(patternStr.substr(last, index - last));
		last = index + 1;
		index = patternStr.find_first_of(" ", last);
	}
	patterns.push_back(patternStr.substr(last));

	// find
	// refresh flagFound
	for (auto word:words)
		word->setFound(false);

	for (auto pattern:patterns)
	{
		bool singleMatch = false;
		for (auto word:words)
		{
			if (pattern ==  word->getContent())
			{
				singleMatch = true;
				word->setFound(true);
			}
		}
		if (!singleMatch)
		{
			match = false;
			return;
		}
	}
}

bool Text::isMatch()
{
	return match;
}