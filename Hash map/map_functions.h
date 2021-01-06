#include <sstream>
#include <map>
#include <optional>
#include <vector>

namespace mapf
{
    std::vector<std::string> uniqueWords(const std::string& t)
    {
        std::vector<std::string> unWords;
        std::map<std::string, bool> tmap;

        std::stringstream input(t);

        std::string currWord;
        while(input >> currWord)
        {
            if(currWord[currWord.size()-1] == ',' || currWord[currWord.size()-1] == '.')
            {
                currWord.pop_back();
            }

            if(tmap.count(currWord) == 0)
            {
                tmap[currWord] = true;
                unWords.push_back(currWord);;
            }
        }

        return unWords;
    }

    void textSection (const std::string& t1, const std::string& t2)
    {
        if(t1.size() == 0 || t2.size() == 0) return;

        std::vector<std::string> str1 = uniqueWords(t1);
        std::vector<std::string> str2 = uniqueWords(t2);

        for(std::string word1 : str1)
        {
            for(std::string word2 : str2)
            {
                if(word1 == word2) 
                {
                    std::cout << word1 << " ";
                    break;
                }
            }
        }
    }

    void histogram (const std::string& t)
    {
        std::stringstream input(t);
        std::map<std::string, int> tmap;

        std::string currWord;
        while (input >> currWord)
        {
            if(currWord[currWord.size()-1] == ',' || currWord[currWord.size()-1] == '.')
            {
                currWord.pop_back();
            }

            if(tmap.count(currWord) == 0) tmap[currWord] = 1;
            else tmap[currWord]++;
        }

        for(auto& wordNum : tmap)
        {
            std::cout << wordNum.first << ": " << wordNum.second << std::endl;
        }
    }

    void commonWord (const std::string& t)
    {
        std::stringstream input(t);
        std::map<std::string, int> tmap;

        std::string currWord, common;
        int max = 0;
        while(input >> currWord)
        {
            if(currWord[currWord.size()-1] == ',' || currWord[currWord.size()-1] == '.')
            {
                currWord.pop_back();
            }

            if(currWord.size() > 3)
            {
                if(tmap.count(currWord) == 0) tmap[currWord] = 1;
                else tmap[currWord]++;

                if(tmap[currWord] > max) 
                {
                    max = tmap[currWord];
                    common = currWord;
                }
            }
        }

        std::cout << common << ": " << max << std::endl;
    }
}