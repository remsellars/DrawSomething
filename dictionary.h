#include <vector>
#include <string>

class Dictionary{
	private:
		std::vector<std::string> m_Words;
	public:
		Dictionary(){};	
		~Dictionary(){};
		virtual std::string getWord(int index)const;
		virtual void addWord();
		virtual void fillDictionary()=0;
};

class TwoCharDictionary : public Dictionary{
	public:
		TwoCharDictionary(){};	
		~TwoCharDictionary(){};
		void fillDictionary();
};









