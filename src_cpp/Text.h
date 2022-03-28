#include <list>
#include <vector>
#include <string>

class Word;
class Row;

class Text
{
private:
	std::list<Word *> words;

public:
	Text(/* args */);	// need args
	~Text();

	void notify();
	void find(std::string pattern);
	std::vector<Row *> shift();
};