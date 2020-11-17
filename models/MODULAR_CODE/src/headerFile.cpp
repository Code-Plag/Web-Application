#include <iostream>
#include <regex>
#include <unordered_set>
#include <set>
#include <cmath>
#include <map>
#include <bits/stdc++.h>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <dirent.h>
#include <iterator>
#include <string>

using namespace std;

class TOKEN
{
    string Token_Type;                //TPYE OF TOKEN
    string Token_Content;             //CONTENT OF TOKEN
    unsigned int Token_Start_Line_no; // START LINE NO OF THE TOKEN IN THE CODE
    unsigned int Token_End_Line_no;   //END LINE NO OF THE CODE
    unsigned int Token_Start_Pos;     //START POSITION OF THE TOKEN IN THE CODE STRING
    unsigned int Token_End_Pos;       //END POSITION OF THE TOKEN IN THE CODE STRING

public:
    TOKEN();
    void setToken_Type(string Token_Type);
    void setToken_Content(string Token_Content);
    void setToken_Start_Line_no(unsigned int Token_Start_Line_no);
    void setToken_End_Line_no(unsigned int Token_End_Line_no);
    void setTokenPos(unsigned int Token_Start_Pos, unsigned int Token_End_Pos);
    void setToken_Line_no(unsigned int Token_Start_Line_no, unsigned int Token_End_Line_no);

    string getToken_Type();
    string getToken_Content();
    unsigned int getToken_Start_Line_no();
    unsigned int getToken_End_Line_no();
    unsigned int getToken_Start_Pos();
    unsigned int getToken_End_Pos();
};

class TOKENIZER
{
    string Source_File_Name;            // SOURCE CODE FILE NAME
    string Normalized_Source_File_Code; // NORMALIZED SOURCE CODE FILE
    string Original_Source_File_Code;   // ORIGINAL SOURCE CODE FILE
    string Source_File_Path;            // PATH OF THE SOURCE FILE
    string Source_File_Language;

    vector<TOKEN> Tokenized_File_Vector;
    string Source_File_Token;

public:
    TOKENIZER();
    bool TOKENIZE_FILE(string Source_File_Language, string Source_File_Path, string Source_File_Name);
    string getSource_File_Name();
    string getSource_File_Language();
    string getOriginal_Source_File_Code();
    string getNormalized_Source_File_Code();
    string getSource_File_Path();
    void getData();
    TOKEN getTokenized_File_Vector(unsigned int index);
    vector<TOKEN> getTokenized_File_Vector();
    string getSource_File_Token();
};

bool isPathValid(string FolderPath);
bool isEmpty_Dir_File(string FolderPath, string Source_File_Name);
bool CreateTokens(string FolderPath, vector<TOKENIZER> &Folder_Files);

/*Greedy String Algorithm */

class MATCH
{
    unsigned int Index_Pattern;
    unsigned int Index_Text;
    unsigned int Token_Matched_Length;
    // string m;
public:
    MATCH();
    MATCH(unsigned int Index_Pattern, unsigned int Index_Text, unsigned int Token_Matched_Length);
    unsigned int getIndex_Pattern();
    unsigned int getIndex_Text();
    unsigned int getToken_Matched_Length() const;
    // string getmatch();
};

bool operator<(const MATCH &match1, const MATCH &match2);

class GREEDY
{
    string Pattern_Code;
    string Text_Code;
    unsigned int Minimum_Matching_length;
    vector<bool> Visited_Pattern;
    vector<bool> Visited_Text;
    //unsigned long int *Visited_Pattern;
    //unsigned long int *Visited_Text;
    vector<MATCH> Tiles;
    vector<MATCH> matches_switch;
    vector<priority_queue<MATCH>> Matches_Found;

public:
    GREEDY();
    // ~GREEDY();
    GREEDY(string Pattern_Code, string Text_Code, unsigned int Minimum_Matching_length);
    unsigned int Dist_To_Next_Tile(unsigned int pos, vector<bool> &vis, unsigned int Search_Length, string Code);
    bool isoccluded(MATCH match);
    unsigned int Jump_To_Next_Unmarked_Token(unsigned int pos, vector<bool> &vis, unsigned int Search_Length, string Text_Code);
    unsigned long int String_To_Hashvalue(string s);
    unsigned int Scan_Pattern(unsigned int Initial_Search_Length);
    void Mark_String_Matches();
    void Greedy_Rabin_Karp_Driver();
    bool Is_Pattern_Marked(unsigned int pos);
    bool Is_Text_Marked(unsigned int pos);
    vector<MATCH> getTiles();
    void tiling();
    bool Need_Switching();
    void Greedy_string_tiling();
    bool isoccluded_Switch(MATCH m);
};

class MATCHER
{
    unsigned int Folder_Files_Index_1;
    unsigned int Folder_Files_Index_2;
    vector<TOKEN> file_1_token_vector;
    vector<TOKEN> file_2_token_vector;
    vector<MATCH> Tiles;
    float Match_Percent_1;
    float Match_Percent_2;
    unordered_map<string, unsigned int> line_file1;
    unordered_map<string, unsigned int> line_file2;

public:
    MATCHER();
    MATCHER(unsigned int Folder_Files_Index_1, unsigned int Folder_Files_Index_2, vector<TOKEN> file_1_token_vector, vector<TOKEN> file_2_token_vector, vector<MATCH> Tiles);
    MATCH getTiles_Match(unsigned int index);
    vector<MATCH> getTiles();
    unsigned int getFolder_Files_Index_1();
    unsigned int getFolder_Files_Index_2();
    unsigned int getTotal_Match_Token_Count();
    float getMatch_Percent_1();
    float getMatch_Percent_2();
    vector<TOKEN> getfile_1_token_vector();
    vector<TOKEN> getfile_2_token_vector();
    unordered_map<string, unsigned int> getline_file1();
    unordered_map<string, unsigned int> getline_file2();
};

/*RegexLibrary*/
#include "../regex/cppRegex/cppRegex.cpp"
#include "../regex/javaRegex/javaRegex.cpp"
#include "../regex/pythonRegex/pythonRegex.cpp"

/*token*/
#include "../token/token.cpp"
#include "../token/tokenizer.cpp"

/*stringMatch*/
#include "../stringMatch/match.cpp"
#include "../stringMatch/matcher.cpp"
#include "../stringMatch/stringMatch.cpp"

/*function*/
#include "functions.cpp"

/*Output HTML*/
#include "../outputHTML/colorVector.cpp"
#include "../outputHTML/outputHTML.cpp"

/*JSON Parse Library*/
#include "../outputJSON/json.hpp"
#include "../outputJSON/outputJSON.cpp"