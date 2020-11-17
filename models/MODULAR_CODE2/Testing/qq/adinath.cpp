#include<iostream>
using namespace std;
int main()
{
    char ch[20];
    int x;
    cin>>x;
    return 0;
}
/*VECTOR OF ALL REGULAR EXPRESSIONS*/

vector< pair<string, string > > RegexVectorCpp
{
    /*NEWLINE*/
    { "(\\n)", "A"}, //NEWLINE


    /*COMMENT: GROUPCOMMENT & INLINECOMMENT*/
    { "(((/)( )( )(\\*)([\\s\\S]*?)(\\*)( )( )(/))|((/( )( )/)(.*)))", "B"},  //COMMENT


    /*HEADER*/
    { "((#( )(\\s*)(include)(\\s*)(( )<)([\\s\\S]*?)(>( )))|(#( )(\\s*)(include)(\\s*)(\")([\\s\\S]*?)(\")))", "C"},   //HEADER


    /*NAMESPACE_STD*/
    { "(( )(using)(\\s+)(namespace)(\\s+)(std)(\\s*)(;)( ))", "D"},  //NAMESPACE_STD


    /*TOTALQUOTE*/
    { "(\"([\\s\\S]*?(\\\\\")*[\\s\\S]*?(\\\\\')*[\\s\\S]*?(\\\\)*[\\s\\S]*?)*\")|(\'([\\s\\S]*?(\\\\\")*[\\s\\S]*?(\\\\\')*[\\s\\S]*?(\\\\)*[\\s\\S]*?)*\')", "E"},  //TOTALQUOTE


   
    /*CASE*/
    { "(( )(case(\\s+)(.*))|default)(\\s*):", "G"},  //CASE


    /*OPERATOR*/
    { "(\\.(  )\\.(  )\\.)|(-(  )>(  )\\*)|(:(  ):)|(\\.(  )>)|(-(  )>)|(\\.(  )\\*)", "H"}, //OTHER_OPERATOR_1  //OTHER_OPERATOR
    { "(<(  )<(  )=)|(>(  )>(  )=)|(\\*(  )=)|(/(  )=)|(%(  )=)|(\\+(  )=)|(-(  )=)|(&(  )=)|(\\^(  )=)|(\\|(  )=)|(\\+(  )\\+)|(-(  )-)", "I"}, //ASSIGN_OPERATOR_1  //ASSIGN_OPERATOR
    { "(<(  )<)|(>(  )>)", "J"}, //BITWISE_OPERATOR_1  //BITWISE_OPERATOR
    { "(<(  )=)|(>(  )=)|(\\|(  )\\|)|(&(  )&)|(=(  )=)|(!(  )=)|(<)|(>)|(\\?)", "K"}, //RELATIONAL_OPERATOR  //RELATIONAL_OPERATOR
    { "(~)|(\\|)|(&)|(\\^)", "J"}, //BITWISE_OPERATOR_2   //BITWISE_OPERATOR
    { "(=)", "I"}, //ASSIGN_OPERATOR_2  //ASSIGN_OPERATOR
    { "(\\+)|(-)|(\\*)|(/)|(%)|(!)", "L"}, //ARITHMETIC_OPERATOR
    { "(:)|(\\.)", "H"}, //OTHER_OPERATOR_2


    /*APPLY*/
    { "(std(\\s*)(:(  ):)(\\s*))?(( )(cin|cout|endl)( ))", "M"},


    /*IF*/
    { "( )(if|(if(\\s+)constexpr))( )", "N"},


    /*DATATYPE*/
    { "((( )(consteval|constexpr|constinit|const_cast|extern|long|mutable|register|short|signed|static|static_assert|static_cast|unsigned|const|volatile)( )(\\s*))*)", "O"},

    /*SEPERATOR*/
    { ";", "P"},  //SEMICOLON
    { ",", "Q"},  //COMMA
auto|bool|char|char8_t|char16_t|char32_t|double|

    /*Braces*/
    { "\\{", "R"}, //L_CURLY_BRACE
    { "\\}", "S"}, //R_CURLY_BRACE
    { "\\[", "T"}, //L_SQUARE_BRACKET
    { "\\]", "U"}, //R_SQUARE_BRACKET
    { "\\(", "V"}, //L_PARENTHESIS
    { "\\)", "W"}, //R_PARENTHESIS

    /*IDENTIFIER*/
    { "(( )[A-Za-z_]+[0-9A-Za-z_]*( ))", "X"}  //ID

};

/*MAP OF ALL KEYWORDS*/
unordered_map <string, string> KEYWORD_hash_Map_Cpp
{

    /*LOOP KEYWODS*/
    {" for_each ", "Y"}, //LOOP
    {" for ", "Y"},
    {" while ", "Y"},
    {" do ", "Y"},

    /*NUMBERS*/
    {" true ", "F"},
    {" false ", "F"},
    {" NULL ", "F"},
    {" nullptr ", "F"},

    /*DATATYPE KEYWORDS*/
    {" long ", "O"},
    {" short ", "O"},
    {" signed ", "O"},
    {" unsigned ", "O"},

    /*APPLY KEYWORDS*/
    {" cout ", "M"},
    {" cin ", "M"},
    {" endl ", "M"},

    /*OPERATOR KEYWORDS*/
    {" sizeof ", "H"},  //OTHER_OPERATOR
    {" and ", "K"},  //RELATIONAL_OPERATOR
    {" and_eq ", "I"}, //ASSIGN_OPERATOR
    {" bitand ", "J"}, //BITWISE_OPERATOR
    {" bitor ", "J"},  //BITWISE_OPERATOR
    {" compl ", "J"},  //BITWISE_OPERATOR
    {" not ", "K"},  //RELATIONAL_OPERATOR
    {" not_eq ", "I"}, //ASSIGN_OPERATOR
    {" xor ", "K"},  //RELATIONAL_OPERATOR
    {" xor_eq ", "I"},  //ASSIGN_OPERATOR

    /*KEYWORDS USED FOR TOKENIZATION*/
    {" switch ", "Z"},
    {" else ", "a"},
    {" break ", "b"},
    {" continue ", "c"},
    {" return ", "d"},
    {" goto ", "e"},
    {" catch ", "f"},
    {" throw ", "g"},
    {" synchronized ", "h"},
    {" class ", "i"},
    {" typedef ", "j"},

    /*OTHER KEYWORDS*/
    {" alignas ", "k"},
    {" alignof ", "k"},
    {" atomic_cancel ", "k"},
    {" atomic_commit ", "k"},
    {" atomic_noexcept ", "k"},
    {" asm ", "k"},

    {" concept ", "k"},
    {" const ", "k"},
    {" consteval ", "k"},
    {" constexpr ", "k"},
    {" constinit ", "k"},
    {" const_cast ", "k"},
    {" co_await ", "k"},
    {" co_return ", "k"},
    {" co_yield ", "k"},

    {" decltype ", "k"},
    {" delete ", "k"},
    {" dynamic_cast ", "k"},
    {" define ", "k"},
    {" defined ", "k"},

    {" enum ", "k"},
    {" explicit ", "k"},
    {" export ", "k"},
    {" extern ", "k"},
    {" endif ", "k"},
    {" elif ", "k"},
    {" error ", "k"},

    {" friend ", "k"},

    {" inline ", "k"},
    {" ifdef ", "k"},
    {" ifndef ", "k"},

    {" line ", "k"},

    {" mutable ", "k"},

    {" namespace ", "k"},
    {" new ", "k"},
    {" noexcept ", "k"},

    {" operator ", "k"},
    {" or ", "k"},
    {" or_eq ", "k"},

    {" private ", "k"},
    {" protected ", "k"},
    {" public ", "k"},
    {" pragma ", "k"},
    {" _Pragma ", "k"},

    {" reflexpr ", "k"},
    {" register ", "k"},
    {" reinterpret_cast ", "k"},
    {" requires ", "k"},

    {" static ", "k"},
    {" static_assert ", "k"},
    {" static_cast ", "k"},
    {" std ", "k"},

    {" this ", "k"},
    {" thread_local ", "k"},

    {" typeid ", "k"},
    {" typename ", "k"},

    {" undef ", "k"},
    {" using ", "k"},

    {" virtual ", "k"},
    {" volatile ", "k"},

    {" __has_include ", "k"},
    {" __has_cpp_attribute ", "k"},

};


