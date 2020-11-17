

MATCH :: MATCH(){}


MATCH :: MATCH(unsigned long int Index_Pattern,unsigned long int Index_Text,unsigned long int Token_Matched_Length,string m){
			this->Index_Pattern=Index_Pattern;
			this->Index_Text=Index_Text;
			this->Token_Matched_Length=Token_Matched_Length;
			this->m=m;
		}

unsigned long int MATCH :: getIndex_Pattern(){
			return Index_Pattern;
		}

unsigned long int MATCH :: getIndex_Text(){
			return Index_Text;
		}

unsigned long int MATCH :: getToken_Matched_Length()const{
			return Token_Matched_Length;
		}

string MATCH :: getmatch(){
			return m;
		}











