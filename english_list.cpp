#include <cstring>
#include "english_list.h"

bool EnglishList::p_search(const char* tword, size_t len)
{
    for(vector<char*>::iterator fiter = englishList.begin(); fiter != englishList.end(); fiter++)
    {
        if(strncmp(*fiter, tword, len) == 0)
        {
            return true;
        }
    }

    return false;
}

EnglishList::EnglishList()
{
    char temp[MAX_WORD_LEN];

    englishWordsFs.open(LIST_FILE_NAME, ifstream::binary);

    englishWordsFs.seekg(0, ifstream::end);
    unsigned long long flength = englishWordsFs.tellg();
    englishWordsFs.seekg(0, ifstream::beg);

    while(englishWordsFs.tellg() != flength)
    {
        englishWordsFs.getline(temp, MAX_WORD_LEN);

        size_t wordlen = strlen(temp);
        char* wordstr = new char[wordlen + 1];
        memcpy(wordstr, temp, wordlen + 1);

        englishList.push_back(wordstr);
    }
}
