
/*CLASS TO STORE DATA OF INDIVITUAL FILE*/

/*ZERO PARAMETER CONSTRUCTOR*/
TOKENIZER::TOKENIZER() {}

/*Tokenize File Function*/
bool TOKENIZER::TOKENIZE_FILE(string Source_File_Language, string Source_File_Path, string Source_File_Name)
{

    this->Source_File_Language = Source_File_Language;
    this->Source_File_Name = Source_File_Name;
    this->Source_File_Path = Source_File_Path;
    this->Source_File_Token = "";
    this->Normalized_Source_File_Code = "";
    this->Original_Source_File_Code = "";
    ifstream inFile(this->Source_File_Path + "/" + this->Source_File_Name);

    string inFileCode((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));

    this->Normalized_Source_File_Code = inFileCode;
    this->Original_Source_File_Code = inFileCode;

    /*SINGLE SPACE NEEDED AT START*/
    Normalized_Source_File_Code = " " + Normalized_Source_File_Code + " ";

    /*NORMALIZATION OF CODE*/
    try
    {

        //Replace escape sequence
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\\\\""), "   ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\\\'"), "   ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\\\\\\\"), "   ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\\\\\?"), "   ");

        //replace diagraphs
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("<%|\\?\\?<"), "{");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("%>|\\?\\?>"), "}");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("<:|\\?\\?\\("), "[");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex(":>|\\?\\?\\)"), "]");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("%:|\\?\\?="), "#");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\?\\?/"), "\\");

        //normalization of code
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("( )+"), "     ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("(\\t)+"), "  \t  ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\n"), "   \n   ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\{"), " { ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\}"), " } ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\("), " ( ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\)"), " ) ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\["), " [ ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\]"), " ] ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex(">"), " > ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("<"), " < ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\|"), " | ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex(":"), " : ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\*"), " * ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("&"), " & ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\+"), " + ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("="), " = ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("!"), " ! ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("@"), " @ ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\$"), " $ ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("%"), " % ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\^"), " ^ ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("-"), " - ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("`"), " ` ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("~"), " ~ ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\?"), " ? ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("/"), " / ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("#"), " # ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex(";"), " ; ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex(","), " , ");
        Normalized_Source_File_Code = regex_replace(Normalized_Source_File_Code, regex("\\."), " . ");
    }
    catch (...)
    {
        return false;
    }

    /*START OF TOKENIZATION PROGRAM*/
    map<unsigned int, TOKEN> Tokenized_File; // TOKENIZED FILE MAP TO SAVE ALL DATA OF GENERATED TOKENS
    unordered_set<unsigned int> visited;     //VISITED SET TO TRACK POSITIONS VISITED IN THE STRING
    vector<pair<string, string>> RegexVector;
    unordered_map<string, string> KEYWORD_hash_Map;

    /*CHECK LANGUAGE */
    if (Source_File_Language == "c/c++")
    {
        RegexVector = RegexVectorCpp;
        KEYWORD_hash_Map = KEYWORD_hash_Map_Cpp;
    }
    else if (Source_File_Language == "java")
    {
        RegexVector = RegexVectorJava;
        KEYWORD_hash_Map = KEYWORD_hash_Map_Java;
    }
    else if (Source_File_Language == "python")
    {
        RegexVector = RegexVectorPython;
        KEYWORD_hash_Map = KEYWORD_hash_Map_Python;
    }

    /*ITERATION OVER EACH REGEX IN RegexVector START*/
    for (auto Token_Type_Iterator = RegexVector.begin(); Token_Type_Iterator != RegexVector.end(); Token_Type_Iterator++)
    {
        try
        {
            regex RegexExp(Token_Type_Iterator->first); //REGEX EXPRESSION CREATED

            /*ITERATOR INITIALIZATION ON STRING OF CODE I.E. ON Normalized_Source_File_Code*/
            auto word_Begin = sregex_iterator(Normalized_Source_File_Code.begin(), Normalized_Source_File_Code.end(), RegexExp);
            auto word_End = sregex_iterator();
            /*ITERATIONS OVER THE CODE STRING START*/

            for (auto token_iterator = word_Begin; token_iterator != word_End; token_iterator++)
            {
                try
                {
                    auto token_start_position = token_iterator->position();                            //SAVES FIRST POSITION OF THE MATCHED SUBSTRING
                    auto token_end_position = (token_iterator->str().length()) + token_start_position; //SAVES END POSITION OF MATCHED SUBSTRING

                    /*CHECK IF TOKEN IS ALREADY FORMED START*/
                    if (visited.find(token_start_position) == visited.end())
                    {
                        TOKEN actualToken; //TEMPORARY TOKEN TO INSERT IN THE TOKENIZED_FILE MAP

                        /*SAVING DATA IN TEMPORARY TOKEN*/
                        actualToken.setToken_Type(Token_Type_Iterator->second);
                        actualToken.setToken_Content(token_iterator->str());
                        actualToken.setTokenPos(token_start_position, token_end_position);

                        /*CHECK TOKEN TYPE AND CHANGE IT FOR KEYWORDS AND IDENTIFIERS*/
                        if (actualToken.getToken_Type() == "X")
                        {
                            string searchterm = "";
                            if (KEYWORD_hash_Map[token_iterator->str()] != searchterm)
                                actualToken.setToken_Type(KEYWORD_hash_Map[token_iterator->str()]);
                        }

                        /*MARK VISITED ARRAY POSITIONS AT END OF LOOP*/
                        for (unsigned int visited_iterator = token_start_position; visited_iterator < token_end_position; visited_iterator++)
                            visited.insert(visited_iterator);

                        /*INSERT TOKEN IN THE MAP*/
                        Tokenized_File.insert({token_start_position, actualToken});
                    } //CHECK IF TOKEN IS ALREADY FORMED END
                }
                catch (...)
                {
                    continue;
                }
            } //ITERATIONS OVER THE CODE STRING EnD
        }
        catch (...)
        {
            continue;
        }
    } //ITERATION OVER EACH REGEX IN RegexVector END

    /*CODE TO COUNT NEWLINES AND ENTER START AND END NEWLINE FOR TOKENS*/

    //  vector<unsigned long int> newlineIndex; // TEMPORARY VECTOR TO STORE INDEX OF  ALL NEWLINES
    unsigned int lineCounter = 1; // COUNTER TO TRACK LINE NUMBER

    /*ITERATOR OVER TO TOKENIZED MAP START*/
    for (auto tokenizedFileIterator = Tokenized_File.begin(), previousPos = Tokenized_File.begin(); tokenizedFileIterator != Tokenized_File.end(); tokenizedFileIterator++)
    {

        if (tokenizedFileIterator->second.getToken_Type() == "A")
        {
            //newlineIndex.push_back(tokenizedFileIterator->first); //NEWLINE INDICES STORED IN VECTOR FOR EARISING
            lineCounter++;                                                     //COUNTER INCREMENT
            tokenizedFileIterator->second.setToken_Start_Line_no(lineCounter); //START LINE NUMBER SET
            tokenizedFileIterator->second.setToken_End_Line_no(lineCounter);   //END LINE NUMBER SET

            /*CODE TO CHECK IF LINE ALREADY PRESENT IN A TOKEN OR NOT BASED ON START POSITION*/
            if ((previousPos->second.getToken_End_Pos() > tokenizedFileIterator->second.getToken_Start_Pos()) && (previousPos->second.getToken_End_Line_no() != (lineCounter)))
                previousPos->second.setToken_End_Line_no(lineCounter);
        }
        else
        {
            tokenizedFileIterator->second.setToken_Start_Line_no(lineCounter); //START LINE NUMBER SET
            tokenizedFileIterator->second.setToken_End_Line_no(lineCounter);   //END LINE NUMBER SET
            previousPos = tokenizedFileIterator;
        }
    } //ITERATOR OVER TO TOKENIZED MAP END

    /*LOOP FOR EARISING NEWLINE FROM THE VECTOR*/
    /* for(auto newLineEraseIterator=newlineIndex.begin(); newLineEraseIterator!=newlineIndex.end(); newLineEraseIterator++)
         Tokenized_File.erase(*newLineEraseIterator);*/

    for (auto Tokenized_File_Iterator = Tokenized_File.begin(); Tokenized_File_Iterator != Tokenized_File.end(); Tokenized_File_Iterator++)
    {

        if (Tokenized_File_Iterator->second.getToken_Type() == "A" || Tokenized_File_Iterator->second.getToken_Type() == "B" || Tokenized_File_Iterator->second.getToken_Type() == "C" || Tokenized_File_Iterator->second.getToken_Type() == "D")
        {
            continue;
        }
        else
        {
            Source_File_Token += Tokenized_File_Iterator->second.getToken_Type();
            Tokenized_File_Vector.push_back(Tokenized_File_Iterator->second);
        }
    }
    return true;
} //VOID TOKENIZE_FILE FUNCTION END

/*Getter Functions*/
string TOKENIZER::getSource_File_Name()
{
    return this->Source_File_Name;
}

string TOKENIZER::getOriginal_Source_File_Code()
{
    return this->Original_Source_File_Code;
}

string TOKENIZER::getNormalized_Source_File_Code()
{
    return this->Normalized_Source_File_Code;
}

string TOKENIZER::getSource_File_Path()
{
    return this->Source_File_Path;
}

string TOKENIZER::getSource_File_Language()
{
    return this->Source_File_Language;
}

TOKEN TOKENIZER::getTokenized_File_Vector(unsigned int index)
{
    if (index < Tokenized_File_Vector.size())
        return Tokenized_File_Vector[index];
    else
        throw "Unauthorized Access";
}

vector<TOKEN> TOKENIZER::getTokenized_File_Vector()
{
    return Tokenized_File_Vector;
}

void TOKENIZER::getData()
{
    unsigned int counter1 = 0;
    cout << "  FILE NAME: " << getSource_File_Name() << endl
         << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    for (auto Tokenized_File_Iterator = Tokenized_File_Vector.begin(); Tokenized_File_Iterator != Tokenized_File_Vector.end(); Tokenized_File_Iterator++)
    {

        cout << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
             << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
             << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
             << "Content: " << Tokenized_File_Iterator->getToken_Content() << "\n"
             << "Token Index: " << counter1 << "\n"
             << "-----------------------------------------------------------------------\n";
        counter1++;
    }
    cout << "Total Tokens: " << counter1 << endl;
}
string TOKENIZER::getSource_File_Token()
{
    return Source_File_Token;
}
