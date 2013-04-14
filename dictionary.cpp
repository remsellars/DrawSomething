void Dictionary::getWord(int index)const
{
    if(index<=m_Words.size())
    {
        return m_Words[index];
    }
};

void Dictionary::fillDictionary(){
	m_Words.resize(NUMBER_OF_WORDS);
	m_Words[0] = "stuff";
	m_Words [1] = "spaghetti";


	
}
