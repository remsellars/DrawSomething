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
		int getSize(){m_Words.size();};
};

class TwoCharDictionary : public Dictionary{
	public:
		TwoCharDictionary(){};	
		~TwoCharDictionary(){};
		void fillDictionary();
};

class ThreeCharDictionary : public Dictionary{
	public:
		ThreeCharDictionary(){};	
		~ThreeCharDictionary(){};
		void fillDictionary();
};

class FourCharDictionary : public Dictionary{
	public:
		FourCharDictionary(){};	
		~FourCharDictionary(){};
		void fillDictionary();
};


class FiveCharDictionary : public Dictionary{
	public:
		FiveCharDictionary(){};	
		~FiveCharDictionary(){};
		void fillDictionary();
};

class SixCharDictionary : public Dictionary{
	public:
		SixCharDictionary(){};	
		~SixCharDictionary(){};
		void fillDictionary();
};

class SevenCharDictionary : public Dictionary{
	public:
		SevenCharDictionary(){};	
		~SevenCharDictionary(){};
		void fillDictionary();
};

class EightCharDictionary : public Dictionary{
	public:
		EightCharDictionary(){};	
		~EightCharDictionary(){};
		void fillDictionary();
};







