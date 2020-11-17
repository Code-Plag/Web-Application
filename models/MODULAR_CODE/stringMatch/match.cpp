
MATCH ::MATCH() {}

MATCH ::MATCH(unsigned int Index_Pattern, unsigned int Index_Text, unsigned int Token_Matched_Length)
{
	this->Index_Pattern = Index_Pattern;
	this->Index_Text = Index_Text;
	this->Token_Matched_Length = Token_Matched_Length;
}

unsigned int MATCH ::getIndex_Pattern()
{
	return Index_Pattern;
}

unsigned int MATCH ::getIndex_Text()
{
	return Index_Text;
}

unsigned int MATCH ::getToken_Matched_Length() const
{
	return Token_Matched_Length;
}

/*string MATCH :: getmatch(){
			return m;
		}*/
