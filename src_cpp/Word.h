#include <string>

class Word
{
private:
	std::string content;
	bool flagFound;

public:
	Word(std::string initContent);
	~Word();
	// content
	std::string getContent();
	void updateContent(std::string newContent);

	// flagfound
	bool ifFound();
	bool setFound(bool found);
};