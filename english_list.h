#ifndef _ENGLISH_LIST_H_
#define _ENGLISH_LIST_H_

#include <vector>
#include <fstream>
#include <string>

#define MAX_WORD_LEN 1024

#define LIST_FILE_NAME ("EnglishWords.txt")

using namespace std;

class EnglishList
{
public:
    static EnglishList& getInstance()
    {
        static EnglishList instance;
        return instance;
    }

    /** \brief Searches the list for a word
     *
     * \param tword: The std::string word to test
     * \param len: The length of tword
     * \return True if the word exists in the English file, false otherwise
     *
     */
    static bool search(string tword)
    {
        return getInstance().p_search(tword.c_str(), tword.size());
    }

    /** \brief Searches the list for a word
    *
    * \param tword: The cstring word to test
    * \param len: The length of tword
    * \return True if the word exists in the English file, false otherwise
    *
    */
    static bool search(const char* tword, size_t len)
    {
        return getInstance().p_search(tword, len);
    }
private:
    ifstream englishWordsFs;
    vector<char*> englishList;
    bool p_search(const char* tword, size_t len);
    EnglishList();
    EnglishList(EnglishList const&);
    void operator=(EnglishList const&);
};

#endif // _ENGLISH_LIST_H_

