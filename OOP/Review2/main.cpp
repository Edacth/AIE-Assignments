#include <iostream>
#include "review2.h"

int main()
{
	std::string string1 = "I want to go to the CGDC next year.";

	std::string bible = "1:1 In the beginning God created the heaven and the earth. 1:2 And the earth was without form, and void and darkness was upon the face of the deep. And the Spirit of God moved upon the face of the waters.";
	//wordCount(string1);
	wordWrap(bible);
	return 0;
}