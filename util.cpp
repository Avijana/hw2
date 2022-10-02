#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set <string> s;
    //int len = 0;
    //int pos = 0;
		rawWords = convToLower(rawWords);
    for (unsigned int i = 0; i < rawWords.length(); i++) //for loop changes all punctuation to space character
  	{
  		if(ispunct(rawWords[i]) != 0)
			{
				rawWords[i] = ' ';
			}
			stringstream ss(rawWords);
			std::string word;
			while(ss >> word) //stringstream ignores the spaces and inserts them if they pass requirments 
			{
				if(word.length() > 1)
				{
					s.insert(word);
				}
			}
  	}
		return s;
}

    // for(unsigned int i = 0; i< rawWords.length(); i++)
    // {
    //     if((int(rawWords[i]) >= 16 && int(rawWords[i]) <= 25) || (int(rawWords[i])>=65 && int(rawWords[i]) <= 90) || (int(rawWords[i]) >= 97 && int(rawWords[i]) <= 122))
    //     {
    //         len++;
    //         pos++;
    //     }
    //     else if(len <= 2)
    //     {
    //         len = 0;
    //     }
    //     else
    //     {
    //         s.insert(rawWords.substr(pos, len));
    //     }
    // }
		// return s;


/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
