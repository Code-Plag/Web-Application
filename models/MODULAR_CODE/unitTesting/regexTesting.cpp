
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
#include <cmath>
using namespace std;

int main()
{
    ifstream inFile("/home/yash/CODE_PLAG/Core-Engine/python_tokens/test.txt");

    string inFileCode((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));

    string Normalized_Source_File_Code = inFileCode;

    /*SINGLE SPACE NEEDED AT START*/
    Normalized_Source_File_Code = " " + Normalized_Source_File_Code + " ";

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
    // cout << Normalized_Source_File_Code << endl;

    // regex RegexExp("((\"\"\"[\\s\\S]*?\"\"\")|(\'\'\'[\\s\\S]*?\'\'\'))|(\"[^\"^\\n]*(\"|\\n))|(\'[^\'^\\n]*(\'|\\n))");
    //regex RegexExp("([-+]{1}[\\s]*)?((((( )([0-9]*(( )\\.( ))[0-9]*((e|E)(( )(-|\\+)( ))[0-9]*)*?))|(( )([0-9]*(( )\\.( ))[0-9]*((e|E)[0-9]*)*?)))|((( )([0-9]+((e|E)(( )(-|\\+)( ))[0-9]*)*?))|(( )([0-9]+((e|E)[0-9]*)*?))))(j|J))");

    // regex RegexExp("( )random(( )\\.( ))randrange(( )\\(( )).*(( )\\))");
    regex RegexExp("(( )def( ))([\\s]*?)(( )[A-Za-z_]+[0-9A-Za-z_]*( ))([\\s]*?)(\\([\\s\\S]*?\\))([\\s]*?):");
    auto word_Begin = sregex_iterator(Normalized_Source_File_Code.begin(), Normalized_Source_File_Code.end(), RegexExp);
    auto word_End = sregex_iterator();
    int w = 0;
    for (auto token_iterator = word_Begin; token_iterator != word_End; token_iterator++)
    {
        w++;
        cout << token_iterator->str() << "\ncountr: " << w << "\n****************\n";
    }

    return 0;
}
