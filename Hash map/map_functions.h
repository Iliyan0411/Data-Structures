#include <sstream>
#include <map>
#include <optional>
#include <vector>
#include <unordered_map>
#include <sstream>

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

    // Given an array of numbers check if there is a combinnation of 2 numbers that add up to a sum of X
    bool check2Sum(const std::vector<int>& vector, int sum) {
    std::unordered_map<int,int>m;
        
    for(const int & elem : vector){
        if(m.count(sum - elem)){
            return true;
        }

        m[elem] = elem;
    }
    return false;
    }

    bool check3Sum(std::vector<int> vector, int sum) {
    for(int i = 0; i < vector.size(); ++i){
        int elem = vector[i];
        vector.erase(vector.begin()+i);

        if(check2Sum(vector, sum - elem)) {     
        return true;
        }
        vector.insert(vector.begin()+i, elem);
    }
    
    return false;
    }

    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, std::string> m;
        std::stringstream input(s);
        std::unordered_map<std::string, char> uniqueWords;

        std::string currWord;
        for(char c : pattern)
        {
            input >> currWord;
            if(!uniqueWords.count(currWord) && !m.count(c)){
            uniqueWords[currWord] = c;
            m[c] = currWord;
            continue;
            }

            if(uniqueWords[currWord] != c){
            return false;
            }
        }
        return !(bool)(input >> currWord);
    }
}