#include <iostream>
#include <regex>
#include <unordered_set>
#include<set>
#include<cmath>
#include<map>
#include<bits/stdc++.h>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <dirent.h>
#include <iterator>
#include <string>


using namespace std;


class TOKEN
{
    string Token_Type; //TPYE OF TOKEN
    string Token_Content; //CONTENT OF TOKEN
    unsigned long int Token_Start_Line_no; // START LINE NO OF THE TOKEN IN THE CODE
    unsigned long int Token_End_Line_no; //END LINE NO OF THE CODE
    unsigned long int Token_Start_Pos; //START POSITION OF THE TOKEN IN THE CODE STRING
    unsigned long int Token_End_Pos; //END POSITION OF THE TOKEN IN THE CODE STRING

public:
    TOKEN();
    void setToken_Type(string Token_Type);
    void setToken_Content(string Token_Content);
    void setToken_Start_Line_no(unsigned long int Token_Start_Line_no);
    void setToken_End_Line_no(unsigned long int Token_End_Line_no);
    void setTokenPos(unsigned long int Token_Start_Pos, unsigned long int Token_End_Pos);
    void setToken_Line_no(unsigned long int Token_Start_Line_no, unsigned long int Token_End_Line_no);

    string getToken_Type();
    string getToken_Content();
    unsigned long int getToken_Start_Line_no();
    unsigned long int getToken_End_Line_no();
    unsigned long int getToken_Start_Pos();
    unsigned long int getToken_End_Pos();

};




class TOKENIZER
{
    string Source_File_Name; // SOURCE CODE FILE NAME
    string Normalized_Source_File_Code; // NORMALIZED SOURCE CODE FILE
    string Original_Source_File_Code; // ORIGINAL SOURCE CODE FILE
    string Source_File_Path; // PATH OF THE SOURCE FILE
    string Source_File_Language;
    map <unsigned long int, TOKEN> Tokenized_File; // TOKENIZED FILE MAP TO SAVE ALL DATA OF GENERATED TOKENS
    vector<TOKEN> Tokenized_File_Vector;
    string Source_File_Token;

public:

    TOKENIZER();
    bool TOKENIZE_FILE( string Source_File_Language, string Source_File_Path, string Source_File_Name );
    string getSource_File_Name();
    string getSource_File_Language();
    string getOriginal_Source_File_Code();
    string getNormalized_Source_File_Code();
    string getSource_File_Path();
    void getData();
    TOKEN getTokenized_File_Vector(unsigned long int index);
    vector <TOKEN> getTokenized_File_Vector();
    string getSource_File_Token();

};

bool isPathValid(string FolderPath);
bool isEmpty_Dir_File(string FolderPath, string Source_File_Name);
bool CreateTokens( string FolderPath, vector <TOKENIZER> & Folder_Files);


#include "REGEX_DEFN.cpp"
#include "TOKEN_Class.cpp"
#include "TOKENIZER_Class.cpp"

/*Greedy String Algorithm */

class MATCH
{
    unsigned long int Index_Pattern;
    unsigned long int Index_Text;
    unsigned long int Token_Matched_Length;
    string m;
public:
    MATCH();
    MATCH(unsigned long int Index_Pattern, unsigned long int Index_Text, unsigned long int Token_Matched_Length, string m);
    unsigned long int getIndex_Pattern();
    unsigned long int getIndex_Text();
    unsigned long int getToken_Matched_Length()const;
    string getmatch();
};

bool operator < (const MATCH &match1, const MATCH &match2);

class GREEDY
{
    string Pattern_Code;
    string Text_Code;
    unsigned long int Minimum_Matching_length;
    unsigned long int *Visited_Pattern;
    unsigned long int *Visited_Text;
    vector < MATCH > Tiles;
    vector < priority_queue< MATCH > > Matches_Found;
    multimap < unsigned long long int, unsigned long int > Hashmap;//hashtable for storing multiple hash-values
public:
    GREEDY();
    GREEDY(string Pattern_Code,string Text_Code, unsigned long int Minimum_Matching_length);
    unsigned long int Dist_To_Next_Tile(unsigned long int pos, unsigned long int *vis, unsigned long int Search_Length, string Code);
    bool isoccluded(MATCH match);
    unsigned long int Jump_To_Next_Unmarked_Token(unsigned long int pos,unsigned long int * vis,unsigned long int Search_Length,string Text_Code);
    unsigned long long int String_To_Hashvalue(string s );
    unsigned long int Scan_Pattern (unsigned long int Initial_Search_Length);
    void Mark_String_Matches ();
    void Greedy_Rabin_Karp_Driver();
    bool Is_Pattern_Marked(unsigned long int pos);
    bool Is_Text_Marked(unsigned long int pos);
    vector < MATCH > getTiles();
    void tiling();

};


#include "MATCH_Class.cpp"
#include "GREEDY_Class.cpp"

class MATCHER
{

    unsigned long int Folder_Files_Index_1;
    unsigned long int Folder_Files_Index_2;
    vector <TOKEN> file_1_token_vector;
    vector <TOKEN> file_2_token_vector;
    vector < MATCH > Tiles;
    float Match_Percent_1;
    float Match_Percent_2;
    unordered_map < string, unsigned long int > line_file1;
    unordered_map < string, unsigned long int > line_file2;




public:
    MATCHER();
    MATCHER(unsigned long int Folder_Files_Index_1, unsigned long int Folder_Files_Index_2, vector <TOKEN> file_1_token_vector, vector <TOKEN> file_2_token_vector, vector < MATCH > Tiles);
    MATCH getTiles_Match(unsigned long int index);
    vector < MATCH > getTiles();
    unsigned long int getFolder_Files_Index_1();
    unsigned long int getFolder_Files_Index_2();
    unsigned long int getTotal_Match_Token_Count();
    float getMatch_Percent_1();
    float getMatch_Percent_2();
    vector <TOKEN> getfile_1_token_vector();
    vector <TOKEN> getfile_2_token_vector();
    unordered_map < string, unsigned long int > getline_file1();
    unordered_map < string, unsigned long int > getline_file2();



};

#include "MATCHER_Class.cpp"
#include "COLOR_vector.cpp"
#include "Functions.cpp"
#include "printHTML.cpp"
#include "json.hpp"
#include "JSON.cpp"

