/*VECTOR OF ALL REGULAR EXPRESSIONS*/

vector<pair<string, string>> RegexVectorPython{
    /*NEWLINE*/
    {"(\\n)", "A"}, //NEWLINE

    /*COMMENT: GROUPCOMMENT & INLINECOMMENT*/
    {"(( )#( ).*)", "B"}, // (\\n[\\s]*?)((\"\"\"[\\s\\S]*?\"\"\")|(\'\'\'[\\s\\S]*?\'\'\')) if needed for multiline

    /*HEADER*/
    {"((( )import( ))|(( )from( ).*?( )import( )))(.*)", "C"}, //HEADER

    /*BYTE BYTEARRAY*/
    {"(( )bytes(( )\\(( )).*(( )\\)( )))|(( )bytearray(( )\\(( )).*(( )\\)( )))", "D"},                                                         // Bytes BytesArray
    {"(([bB])|([bB][rR])|([rR][bB]))(((\"\"\"[\\s\\S]*?\"\"\")|(\'\'\'[\\s\\S]*?\'\'\'))|(\"[^\"^\\n]*(\"|\\n))|(\'[^\'^\\n]*(\'|\\n)))", "D"}, //TOTALQUOTE

    /*TOTALQUOTE*/                                                                                                                                     /*multiline totalquote*/
    {"([rR]|[uU]|[fF]|([fF][rR])|([rR][fF]))?((\"\"\"[\\s\\S]*?\"\"\")|(\'\'\'[\\s\\S]*?\'\'\'))|(\"[^\"^\\n]*(\"|\\n))|(\'[^\'^\\n]*(\'|\\n))", "E"}, //TOTALQUOTE

    /*NUMBER*/
    {"([-+]{1}[\\s]*)?((((( )([0-9]*(( )\\.( ))[0-9]*((e|E)(( )(-|\\+)( ))[0-9]*)*?))|(( )([0-9]*(( )\\.( ))[0-9]*((e|E)[0-9]*)*?)))|((( )([0-9]+((e|E)(( )(-|\\+)( ))[0-9]*)*?))|(( )([0-9]+((e|E)[0-9]*)*?))))(j|J))", "F"}, //Complex number
    {"([-+]{1}[\\s]*)?(( )0(b|B)[01]+( ))", "F"},                                                                                                                                                                              //Binary number
    {"([-+]{1}[\\s]*)?(( )0(o|O)[0-7]+( ))", "F"},                                                                                                                                                                             //Octal number
    {"([-+]{1}[\\s]*)?(( )0(x|X)[0-9a-fA-F]+( ))", "F"},                                                                                                                                                                       //HexaDecimal
    {"([-+]{1}[\\s]*)?((( )([0-9]*(( )\\.( ))[0-9]*((e|E)(( )(-|\\+)( ))[0-9]*)*?)( ))|(( )([0-9]*(( )\\.( ))[0-9]*((e|E)[0-9]*)*?)( )))", "F"},                                                                               //Decimal
    {"([-+]{1}[\\s]*)?((( )([0-9]+((e|E)(( )(-|\\+)( ))[0-9]*)*?)( ))|(( )([0-9]+((e|E)[0-9]*)*?)( )))", "F"},                                                                                                                 //Integer
    {"( )random(( )\\.( ))randrange(( )\\(( )).*(( )\\))", "F"},                                                                                                                                                               //Range Random

    /*OPERATOR*/
    {"(/(  )/(  )=)|(\\*(  )\\*(  )=)|(>(  )>(  )=)|(<(  )<(  )=)|(\\+(  )=)|(-(  )=)|(\\*(  )=)|(/(  )=)|(%(  )=)|(&(  )=)|(\\|(  )=)|(\\^(  )=)|(\\+(  )\\+)|(-(  )-)|(@(  )=)", "G"}, //ASSIGN_OPERATOR_1
    {"(\\*(  )\\*)|(/(  )/)", "H"},                                                                                                                                                      //ARITHMETIC_OPERATOR_1
    {"((<(  )>)|(!(  )=)|(( )is( )[\\s]*( )not( )))|((=(  )=)|( )is( ))|(>(  )=)|(<(  )=)", "I"},                                                                                        // RELATIONAL_OPERATOR_1
    {"(<(  )<)|(>(  )>)|(&|( )AND( ))|(\\||( )OR( ))|(\\^|( )XOR( ))|(~|( )NOT( ))", "J"},                                                                                               //BITWISE_OPERATOR
    {"-(  )>", "K"},                                                                                                                                                                     //OTHER_OPERATOR_1
    {"(>)|(<)", "I"},                                                                                                                                                                    // RELATIONAL_OPERATOR_2
    {"(=)", "G"},                                                                                                                                                                        //ASSIGN_OPERATOR_2
    {"(\\+)|(-)|(\\*)|(/)|(%)|(!)", "H"},                                                                                                                                                //ARITHMETIC_OPERATOR_2
    {"(( )not( )[\\S]*( )in( ))|(( )in( ))", "L"},                                                                                                                                       //MEMBERSHIP_OPERATOR
    // "M" Used for Logical Operators in Map
    {"(\\.\\.\\.)|(\\.)|(@)", "K"}, //OTHER_OPERATOR_2

    /*EXCEPTION*/
    {"(( )try( ):)", "N"},                             // Try
    {"((( )except( )).*:)|((( )finally( )).*:)", "O"}, // Exception
    {"(( )raise( )).*", "P"},                          // Raise

    /*Function Def*/
    {"(( )def( ))([\\s]*?)(( )[A-Za-z_]+[0-9A-Za-z_]*( ))([\\s]*?)(\\([\\s\\S]*?\\))([\\s]*?):", "Q"}, // function Definition

    /*SEPERATOR*/
    {";", "R"}, //SEMICOLON
    {",", "S"}, //COMMA
    {":", "T"}, //COLON

    /*Braces*/
    {"\\{", "U"}, //L_CURLY_BRACE
    {"\\}", "V"}, //R_CURLY_BRACE
    {"\\[", "U"}, //L_SQUARE_BRACKET
    {"\\]", "V"}, //R_SQUARE_BRACKET
    {"\\(", "U"}, //L_PARENTHESIS
    {"\\)", "V"}, //R_PARENTHESIS

    /*IDENTIFIER*/
    {"(( )[A-Za-z_]+[0-9A-Za-z_]*( ))", "W"} //ID

};

/*MAP OF ALL KEYWORDS*/
unordered_map<string, string> KEYWORD_hash_Map_Python{

    /*Operators*/
    {" and ", "M"}, //LOGICAL_OPERATOR
    {" or ", "M"},  //LOGICAL_OPERATOR
    {" not ", "M"}, //LOGICAL_OPERATOR

    /*Number*/
    {" True ", "F"},  //Boolean
    {" False ", "F"}, //Boolean
    {" None ", "F"},  //Boolean

    /*Input*/
    {" input ", "a"},
    {" raw_input ", "a"},
    {" print ", "a"},

    /*If else*/
    {" if ", "b"},
    {" elif ", "b"},
    {" else ", "b"},

    /*Break Continue*/
    {" continue ", "c"},
    {" break ", "c"},

    /*Pass*/
    {" pass ", "d"},

    /*Return*/
    {" return ", "e"},

    /*Loop*/
    {" for ", "f"},
    {" while ", "f"},

    /*Def*/
    {" def ", "g"},
    {" lambda ", "g"},

    /*Class*/
    {" class ", "h"},

    /*Del*/
    {" del ", "i"},

    /*Self*/
    {" self ", "j"},

    /*MemoryView*/
    {" memoryview ", "k"},

    /*Typecast*/
    {" bool ", "l"},
    {" str ", "l"},
    {" int ", "l"},
    {" float ", "l"},
    {" complex ", "l"},

    /*sequence*/
    {" set ", "m"},
    {" frozenset ", "m"},
    {" dict ", "m"},
    {" list ", "m"},
    {" tuple ", "m"},
    {" range ", "m"},

    /*Type*/
    {" type ", "n"},

    /*Other Keywords*/
    {" as ", "o"},
    {" async ", "o"},
    {" assert ", "o"},
    {" await ", "o"},
    {" from ", "o"},
    {" global ", "o"},
    {" is ", "o"},
    {" map ", "o"},
    {" nonlocal ", "o"},
    {" super ", "o"},
    {" with ", "o"},
    {" yield ", "o"},
};