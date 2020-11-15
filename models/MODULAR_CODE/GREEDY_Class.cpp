
GREEDY :: GREEDY(){}

GREEDY:: GREEDY(string Pattern_Code,string Text_Code, unsigned long int Minimum_Matching_length)
{
    this -> Pattern_Code = Pattern_Code;
    this -> Text_Code = Text_Code;
    Visited_Pattern = new unsigned long int[Pattern_Code.length()];
    Visited_Text = new unsigned long int[Text_Code.length()];
    this -> Minimum_Matching_length = Minimum_Matching_length;//sensitivity

    //initialising visited arrays
    for(unsigned long int i = 0 ; i < Pattern_Code.length() ; i++)
        Visited_Pattern[i] = 0 ;
    for(unsigned long int i = 0; i < Text_Code.length() ; i++)
        Visited_Text[i] = 0;
}

unsigned long int GREEDY::Dist_To_Next_Tile(unsigned long int pos, unsigned long int *vis, unsigned long int Search_Length, string Code)
{
    unsigned long int Dist = 0;
    if(pos + 1 == Code.length())
    {
        return  Dist;
    }
    for(Dist = 0; Dist + pos + 1 < Code.length() && vis[Dist + pos + 1] == 0 ; Dist++) //5 6 7 8 9
    {
        if(Dist + 1 == Search_Length)
        {
            return Dist + 1;
        }
    }
    if(pos + Dist + 1 == Text_Code.length())
    {
        return 0;
    }
    return Dist + 1;
}

bool GREEDY:: isoccluded (MATCH match)
{
    unsigned long int flag = 0;
    for(unsigned long int i = match.getIndex_Pattern() ; i < match.getIndex_Pattern() + match.getToken_Matched_Length() ; i++)
    {
        if(Visited_Pattern[i] == 1)
        {
            flag = 1;
        }
    }
    for(unsigned long int i = match.getIndex_Text() ; i < match.getIndex_Text() + match.getToken_Matched_Length() ; i++)
    {
        if(Visited_Text[i] == 1)
        {
            flag = 1;
        }
    }
    if(flag == 1)
    {
        return true;
    }
    else
        return false;
}

unsigned long int GREEDY:: Jump_To_Next_Unmarked_Token(unsigned long int pos,unsigned long int* vis,unsigned long int Search_Length,string Text_Code)
{
    unsigned long int Dist = Dist_To_Next_Tile (pos,vis,Search_Length,Text_Code);
    if( pos + 1 == Text_Code.length())
    {
        return  0;
    }
    for(pos += Dist ; pos + 1 < Text_Code.length() && vis[ pos + 1] == 1 ; pos++) {}
    if(pos + 1 > Text_Code.length() - 1)
    {
        return 0;
    }
    return pos + 1;
}

unsigned long long int GREEDY::  String_To_Hashvalue(string s )
{
    unsigned long long int n = s.length();
    const unsigned long long int a = pow(10,9);
    unsigned long long int val = 0;
    const unsigned long long int fval = 31;
    unsigned long long int power = 1;
    char c ='@';
    unsigned long long int e = n - 1;
    for(unsigned long long int i = 0 ; i < n ; i++) //85-65
    {
        val = ( val + ( ( (unsigned long long int)(s[i]) - (unsigned long long int)(c) ) *power ) )%(a+9);
        power = ( power * fval ) % (a + 9);
    }
    return val;
}

unsigned long int GREEDY:: Scan_Pattern (unsigned long int Initial_Search_Length)
{
    unsigned long int Maxmatch_Found = 0;
    unsigned long int Search_Length = Initial_Search_Length;
    unsigned long int Text_Position = 0;
    priority_queue < MATCH > Prior_queue;
    bool No_Next_Tile = false;
    while(Text_Position < Text_Code.length())
    {
        if(Is_Text_Marked( Text_Position ) )
        {
            Text_Position++;
        }
        else
        {
            unsigned long int Dist = Dist_To_Next_Tile(Text_Position,Visited_Text,Search_Length,Text_Code);
            if(Dist == 0)
            {
                No_Next_Tile = true;
                Dist=Text_Code.length() - Text_Position;
            }
            if(Dist < Search_Length)
            {
                if(No_Next_Tile)
                {
                    Text_Position = Text_Code.length();
                }
                else
                {
                    Text_Position = Jump_To_Next_Unmarked_Token(Text_Position,Visited_Text,Search_Length,Text_Code);
                    if(Text_Position == 0)
                    {
                        Text_Position = Text_Code.length();
                    }
                }
            }
            else
            {
                string Substring = "";
                for(unsigned long int i = Text_Position ; i <= Text_Position+Search_Length-1 ; i++)
                {
                    Substring = Substring + Text_Code[i];
                    Hashmap.insert({String_To_Hashvalue(Substring),Text_Position});
                }
                Text_Position++;
            }
        }
    }

    unsigned long int Pattern_Position = 0;
    No_Next_Tile = false;

    while(Pattern_Position < Pattern_Code.length())
    {
        if(Is_Pattern_Marked(Pattern_Position))
        {
            Pattern_Position++;
        }
        else
        {
            unsigned long int Dist = Dist_To_Next_Tile(Pattern_Position,Visited_Pattern,Search_Length,Pattern_Code);
            if(Dist == 0)
            {
                No_Next_Tile = true;
                Dist = Pattern_Code.length() - Pattern_Position;
            }
            if(Dist < Search_Length)
            {
                if(No_Next_Tile)
                {
                    Pattern_Position = Pattern_Code.length();
                }
                else
                {
                    Pattern_Position = Jump_To_Next_Unmarked_Token(Pattern_Position,Visited_Pattern,Search_Length,Pattern_Code);
                    if(Pattern_Position == 0)
                    {
                        Pattern_Position = Pattern_Code.length();
                    }
                }
            }
            else
            {
                string Substring = "";
                for(unsigned long int i = Pattern_Position ; i <= Pattern_Position+Search_Length-1 ; i++)
                {
                    Substring = Substring + Pattern_Code[i];
                }
                unsigned long long int hash1 = String_To_Hashvalue(Substring);
                auto Index_Text = Hashmap.equal_range(hash1);
                vector < unsigned long int > Occurance;
                for(auto itr = Index_Text.first ; itr!=Index_Text.second ; itr++)
                {
                    Occurance.push_back(itr->second);
                }
                if(Occurance.size() != 0)
                {
                    for(unsigned long int j = 0 ; j < Occurance.size() ; j++ )
                    {
                        unsigned long int Text_Match_Start = Occurance[j];
                        unsigned long int Match_Length = 0;
                        string temp="";
                        while(Pattern_Code[Pattern_Position + Match_Length] == Text_Code[Text_Match_Start+Match_Length] && Visited_Pattern[Pattern_Position + Match_Length] == 0 && Visited_Text[Text_Match_Start + Match_Length] == 0)
                        {
                            temp = temp + Pattern_Code[Pattern_Position + Match_Length];
                            Match_Length++;
                        }
                        if(Match_Length > 2 * Search_Length)
                        {
                            Search_Length = Match_Length;
                            temp = "";
                            return Match_Length;
                        }
                        if(Maxmatch_Found < Search_Length)
                        {
                            Maxmatch_Found = Search_Length;
                        }
                        if(Maxmatch_Found < Match_Length)
                        {
                            Maxmatch_Found = Match_Length;
                        }
                        if(Match_Length >= Minimum_Matching_length)
                            Prior_queue.push(MATCH(Pattern_Position,Text_Match_Start,Match_Length,temp));
                    }
                }
            }
            Pattern_Position++;
        }
    }
    if(!Prior_queue.empty())
    {
        Matches_Found.push_back(Prior_queue);
    }
    return Maxmatch_Found;
}

void GREEDY:: Mark_String_Matches ()
{
    for(priority_queue<MATCH > Prior_queue:Matches_Found)
    {
        while(!Prior_queue.empty())
        {
            MATCH m1 = Prior_queue.top();
            Prior_queue.pop();
            if(!isoccluded(m1))
            {
                for(unsigned long int i = 0 ; i < m1.getToken_Matched_Length() ; i++)
                {
                    Visited_Pattern[m1.getIndex_Pattern() + i ] = 1 ;
                    Visited_Text[m1.getIndex_Text() + i ]= 1 ;
                }
                Tiles.push_back(m1);
            }
        }
    }
    Matches_Found.clear();
}

void GREEDY:: Greedy_Rabin_Karp_Driver()
{
    unsigned long int initsearchSize = 20 ;
    if(Minimum_Matching_length < 3)
    {
        Minimum_Matching_length = 3;
    }
    bool stop = false;
    unsigned long int Search_Length = initsearchSize;
    while(!stop)
    {
        unsigned long int Lmax = Scan_Pattern(Search_Length);
        if(Lmax > 2 * Search_Length)
        {
            Search_Length = Lmax;
        }
        else
        {
            Mark_String_Matches();
            if(Search_Length > 2* Minimum_Matching_length)
            {
                Search_Length /= 2;
            }
            else if(Search_Length   > Minimum_Matching_length)
            {
                Search_Length = Minimum_Matching_length;
            }
            else
            {
                stop = true;
            }
        }
    }
}


bool GREEDY::  Is_Pattern_Marked(unsigned long int pos)
{
    if(Visited_Pattern[pos] == 1)
    {
        return true;
    }
    else
        return false;
}

bool GREEDY::  Is_Text_Marked(unsigned long int pos)
{
    if(Visited_Text[pos] == 1)
    {
        return true;
    }
    else
        return false;
}

vector < MATCH > GREEDY::  getTiles()
{
    return this->Tiles;
}



void GREEDY :: tiling()
{
    for(unsigned long int i = 0 ; i < Tiles.size() ; i++)
    {
        cout << "Tiles = " << Tiles[i].getmatch() << " " << "Index_Pattern  = " << Tiles[i].getIndex_Pattern() << " Index_Text = " << Tiles[i].getIndex_Text() << " length = " << Tiles[i].getToken_Matched_Length() << endl ;
    }
}




