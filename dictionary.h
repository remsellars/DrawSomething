#include <vector>
#include <string>

class Dictionary{
    private:
        std::vector<std::string> m_Words;
    public:
        virtual std::string getWord(int index)const;
        virtual void addWord();

};











