
GREEDY ::GREEDY() {}

GREEDY::GREEDY(string Pattern_Code, string Text_Code, unsigned int Minimum_Matching_length)
{
    this->Pattern_Code = Pattern_Code;
    this->Text_Code = Text_Code;
    //Visited_Pattern = new unsigned long int[Pattern_Code.length()];
    //Visited_Text = new unsigned long int[Text_Code.length()];

    this->Minimum_Matching_length = Minimum_Matching_length; //sensitivity

    Visited_Pattern.assign(Pattern_Code.length(), false);
    Visited_Text.assign(Text_Code.length(), false);
    //initialising visited arrays
    /* for(unsigned long int i = 0 ; i < Pattern_Code.length() ; i++)
        Visited_Pattern.push_back(false) ;
    for(unsigned long int i = 0; i < Text_Code.length() ; i++)
        Visited_Text.push_back(false);*/
}
/*GREEDY::~GREEDY(){
    delete[] Visited_Pattern;
    delete[] Visited_Text;
    cout << "Destructor Called" << endl;
}*/

unsigned int GREEDY::Dist_To_Next_Tile(unsigned int pos, vector<bool> &vis, unsigned int Search_Length, string Code)
{
    unsigned int Dist = 0;
    if (pos + 1 == Code.length())
    {
        return Dist;
    }
    for (Dist = 0; Dist + pos + 1 < Code.length() && vis[Dist + pos + 1] == false; Dist++) //5 6 7 8 9
    {
        if (Dist + 1 == Search_Length)
        {
            return Dist + 1;
        }
    }
    if (pos + Dist + 1 == Text_Code.length())
    {
        return 0;
    }
    return Dist + 1;
}

bool GREEDY::isoccluded(MATCH match)
{
    bool flag = false;
    for (unsigned int i = match.getIndex_Pattern(); i < match.getIndex_Pattern() + match.getToken_Matched_Length(); i++)
    {
        if (Visited_Pattern[i] == true)
        {
            flag = true;
        }
    }
    for (unsigned int i = match.getIndex_Text(); i < match.getIndex_Text() + match.getToken_Matched_Length(); i++)
    {
        if (Visited_Text[i] == true)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        return true;
    }
    else
        return false;
}

unsigned int GREEDY::Jump_To_Next_Unmarked_Token(unsigned int pos, vector<bool> &vis, unsigned int Search_Length, string Text_Code)
{
    unsigned int Dist = Dist_To_Next_Tile(pos, vis, Search_Length, Text_Code);
    if (pos + 1 == Text_Code.length())
    {
        return 0;
    }
    for (pos += Dist; pos + 1 < Text_Code.length() && vis[pos + 1] == true; pos++)
    {
    }
    if (pos + 1 > Text_Code.length() - 1)
    {
        return 0;
    }
    return pos + 1;
}

unsigned long int GREEDY::String_To_Hashvalue(string s)
{
    try
    {
        unsigned long int n = s.length();
        const unsigned long int a = pow(10, 7);
        unsigned long int val = 0;
        const unsigned long int fval = 7;
        unsigned long int power = 1;
        char c = '@';
        unsigned long int e = n - 1;
        for (unsigned long int i = 0; i < n; i++) //85-65
        {
            val = (val + (((unsigned long int)(s[i]) - (unsigned long int)(c)) * power)) % (a + 7);
            power = (power * fval) % (a + 7);
        }
        return val;
    }
    catch (...)
    {
        cout << "Hash Error" << endl;
    }
    return 0;
}

unsigned int GREEDY::Scan_Pattern(unsigned int Initial_Search_Length)
{
    multimap<unsigned long int, unsigned int> Hashmap; //hashtable for storing multiple hash-values
    unsigned int Maxmatch_Found = 0;
    unsigned int Search_Length = Initial_Search_Length;
    unsigned int Text_Position = 0;
    priority_queue<MATCH> Prior_queue;
    bool No_Next_Tile = false;
    while (Text_Position < Text_Code.length())
    {
        if (Is_Text_Marked(Text_Position))
        {
            Text_Position++;
        }
        else
        {
            unsigned int Dist = Dist_To_Next_Tile(Text_Position, Visited_Text, Search_Length, Text_Code);
            if (Dist == 0)
            {
                No_Next_Tile = true;
                Dist = Text_Code.length() - Text_Position;
            }
            if (Dist < Search_Length)
            {
                if (No_Next_Tile)
                {
                    Text_Position = Text_Code.length();
                }
                else
                {
                    Text_Position = Jump_To_Next_Unmarked_Token(Text_Position, Visited_Text, Search_Length, Text_Code);
                    if (Text_Position == 0)
                    {
                        Text_Position = Text_Code.length();
                    }
                }
            }
            else
            {
                string Substring = "";
                for (unsigned int i = Text_Position; i <= Text_Position + Search_Length - 1; i++)
                {
                    Substring = Substring + Text_Code[i];
                }
                Hashmap.insert({String_To_Hashvalue(Substring), Text_Position});

                Text_Position++;
            }
        }
    }

    unsigned int Pattern_Position = 0;
    No_Next_Tile = false;

    while (Pattern_Position < Pattern_Code.length())
    {
        if (Is_Pattern_Marked(Pattern_Position))
        {
            Pattern_Position++;
        }
        else
        {
            unsigned int Dist = Dist_To_Next_Tile(Pattern_Position, Visited_Pattern, Search_Length, Pattern_Code);
            if (Dist == 0)
            {
                No_Next_Tile = true;
                Dist = Pattern_Code.length() - Pattern_Position;
            }
            if (Dist < Search_Length)
            {
                if (No_Next_Tile)
                {
                    Pattern_Position = Pattern_Code.length();
                }
                else
                {
                    Pattern_Position = Jump_To_Next_Unmarked_Token(Pattern_Position, Visited_Pattern, Search_Length, Pattern_Code);
                    if (Pattern_Position == 0)
                    {
                        Pattern_Position = Pattern_Code.length();
                    }
                }
            }
            else
            {
                string Substring = "";
                for (unsigned int i = Pattern_Position; i <= Pattern_Position + Search_Length - 1; i++)
                {
                    Substring = Substring + Pattern_Code[i];
                }
                unsigned long int hash1 = String_To_Hashvalue(Substring);
                auto Index_Text = Hashmap.equal_range(hash1);
                vector<unsigned int> Occurance;
                for (auto itr = Index_Text.first; itr != Index_Text.second; itr++)
                {
                    Occurance.push_back(itr->second);
                }
                if (Occurance.size() != 0)
                {
                    for (unsigned int j = 0; j < Occurance.size(); j++)
                    {
                        unsigned int Text_Match_Start = Occurance[j];
                        unsigned int Match_Length = 0;
                        // string temp="";
                        while ((((Pattern_Position + Match_Length) < Pattern_Code.length()) && ((Text_Match_Start + Match_Length) < Text_Code.length())) && Visited_Pattern[Pattern_Position + Match_Length] == false && Visited_Text[Text_Match_Start + Match_Length] == false && Pattern_Code[Pattern_Position + Match_Length] == Text_Code[Text_Match_Start + Match_Length])
                        {
                            // temp = temp + Pattern_Code[Pattern_Position + Match_Length];
                            Match_Length++;
                        }
                        if (Match_Length > 2 * Search_Length)
                        {
                            Search_Length = Match_Length;
                            //temp = "";
                            return Match_Length;
                        }
                        if (Maxmatch_Found < Search_Length)
                        {
                            Maxmatch_Found = Search_Length;
                        }
                        if (Maxmatch_Found < Match_Length)
                        {
                            Maxmatch_Found = Match_Length;
                        }
                        if (Match_Length >= Minimum_Matching_length)
                            Prior_queue.push(MATCH(Pattern_Position, Text_Match_Start, Match_Length));
                    }
                }
            }
            Pattern_Position++;
        }
    }
    if (!Prior_queue.empty())
    {
        Matches_Found.push_back(Prior_queue);
    }
    return Maxmatch_Found;
}

void GREEDY::Mark_String_Matches()
{
    for (priority_queue<MATCH> Prior_queue : Matches_Found)
    {
        while (!Prior_queue.empty())
        {
            MATCH m1 = Prior_queue.top();
            Prior_queue.pop();
            if (!isoccluded(m1))
            {
                for (unsigned int i = 0; i < m1.getToken_Matched_Length(); i++)
                {
                    Visited_Pattern[m1.getIndex_Pattern() + i] = true;
                    Visited_Text[m1.getIndex_Text() + i] = true;
                }
                Tiles.push_back(m1);
            }
        }
    }
    Matches_Found.clear();
}

void GREEDY::Greedy_Rabin_Karp_Driver()
{
    unsigned int initsearchSize = 20;
    if (Minimum_Matching_length < 4)
    {
        Minimum_Matching_length = 4;
    }
    bool stop = false;
    unsigned int Search_Length = initsearchSize;
    if (1) // gggggggggggggggggg  && !Need_Switching()
    {
        cout << "   rabin carp"
             << " " << Pattern_Code.length() << "  " << Text_Code.length() << endl;

        while (!stop)
        {
            unsigned int Lmax = Scan_Pattern(Search_Length);
            if (Lmax > 2 * Search_Length)
            {
                Search_Length = Lmax;
            }
            else
            {
                Mark_String_Matches();
                if (Search_Length > 2 * Minimum_Matching_length)
                {
                    Search_Length /= 2;
                }
                else if (Search_Length > Minimum_Matching_length)
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
    else
    {
        //cout << "Simple string tilling start" << endl;
        cout << "string tilling" << Pattern_Code.length() << "  " << Text_Code.length() << endl;
        Greedy_string_tiling();
    }
}

bool GREEDY::Is_Pattern_Marked(unsigned int pos)
{
    if (Visited_Pattern[pos] == true)
    {
        return true;
    }
    else
        return false;
}

bool GREEDY::Is_Text_Marked(unsigned int pos)
{
    if (Visited_Text[pos] == true)
    {
        return true;
    }
    else
        return false;
}

vector<MATCH> GREEDY::getTiles()
{
    return this->Tiles;
}

void GREEDY ::tiling()
{
    for (unsigned int i = 0; i < Tiles.size(); i++)
    {
        cout << "Tiles = "
             << " "
             << "Index_Pattern  = " << Tiles[i].getIndex_Pattern() << " Index_Text = " << Tiles[i].getIndex_Text() << " length = " << Tiles[i].getToken_Matched_Length() << endl;
    }
}

// SWITCHING MECHANISM
bool GREEDY::Need_Switching()
{
    //	cout<<"NEED_SWItching"<<endl;
    unsigned int Pattern_Length = Pattern_Code.length();
    unsigned int Text_Length = Text_Code.length();
    unsigned int Check_interval = 0;
    std::vector<bool> flag;
    if (Pattern_Length == Text_Length && Pattern_Length >= 300)
    {

        Check_interval = (Pattern_Length / 2) - 25;
        //std::vector<bool>flag;
        for (unsigned int i = 0; i < Pattern_Length - Minimum_Matching_length; i += Check_interval)
        {
            //cout<<"i am inside for loop"<<i<<endl;
            string Pat_check = Pattern_Code.substr(i, Minimum_Matching_length);
            string Txt_check = Text_Code.substr(i, Minimum_Matching_length);
            if (Pat_check == Txt_check)
            {
                flag.push_back(true);
            }
        }
    }
    if (Pattern_Length == Text_Length && Pattern_Length >= 300 && flag.size() == 3)
    {
        //cout<<"INSIDE FLAGGED POSITION"<<endl;
        return true;
    }
    else
        return false;
}

void GREEDY ::Greedy_string_tiling()
{
    unsigned int length_oftoken = 0;
    unsigned int maxmatch = 0;
    unsigned int Pattern_Length = Pattern_Code.length();
    unsigned int Text_Length = Text_Code.length();
    do
    {
        maxmatch = Minimum_Matching_length;
        for (unsigned int i = 0; i < Pattern_Length /*&& Visited_Pattern[i]==0*/; i++)
        { //a b g h h h g
            for (unsigned int j = 0; j < Text_Length /*&& Visited_Text[j]==0*/; j++)
            { // a f b g h g
                unsigned int currentlen = 0;
                string temp = "";
                while (Visited_Pattern[i + currentlen] == false && Visited_Text[j + currentlen] == false && Pattern_Code[i + currentlen] == Text_Code[j + currentlen])
                {
                    temp = temp + Pattern_Code[i + currentlen];
                    currentlen++;
                }
                if (currentlen == maxmatch)
                {
                    matches_switch.push_back(MATCH(i, j, currentlen));
                    temp = "";
                }
                else if (currentlen > maxmatch)
                { // 8 9 10 11
                    matches_switch.clear();
                    matches_switch.push_back(MATCH(i, j, currentlen));
                    temp = "";
                    maxmatch = currentlen;
                }
            }
        }
        for (unsigned int i = 0; i < matches_switch.size(); i++)
        {
            //cout<<"match= "<<matches_switch[i].getmatch()<<" | ip = "<<matches_switch[i].getIndex_Pattern()<<" | it = "<<matches_switch[i].getIndex_Text()<<" | length = " <<matches_switch[i].getToken_Matched_Length()<<endl;
            if (isoccluded_Switch(matches_switch[i]))
            {
                for (unsigned int j = 0; j < matches_switch[i].getToken_Matched_Length() - 1; j++)
                {
                    Visited_Pattern[matches_switch[i].getIndex_Pattern() + j] = true;
                    Visited_Text[matches_switch[i].getIndex_Text() + j] = true;
                }
                Tiles.push_back(matches_switch[i]);
                length_oftoken = length_oftoken + maxmatch;
            }
        }
    } while (maxmatch > Minimum_Matching_length);
}

bool GREEDY::isoccluded_Switch(MATCH m)
{
    bool flag = false;
    for (unsigned int i = m.getIndex_Pattern(); i < (m.getIndex_Pattern() + m.getToken_Matched_Length()); i++)
    {
        if (Visited_Pattern[i] == true)
        {
            flag = true;
        }
    }
    if (flag == false)
    {
        for (unsigned int i = m.getIndex_Text(); i < (m.getIndex_Text() + m.getToken_Matched_Length()); i++)
        {
            if (Visited_Text[i] == true)
            {
                flag = true;
            }
        }
    }
    if (flag == true)
        return false;
    else
        return true;
}
