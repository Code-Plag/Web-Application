/*VECTOR OF ALL REGULAR EXPRESSIONS*/

vector<pair<string, string>> RegexVectorJava{
    /*NEWLINE*/
    {"(\\n)", "A"}, //NEWLINE

    /*COMMENT: GROUPCOMMENT & INLINECOMMENT*/
    // { "(((?:/  \\*(?:[^*]|(?:\\*+[^*/]))*\\*+  /)|(?://.*))|((/( )( )/)(.*)))", "B"},  //COMMENT
    //    { "((/( )( )(\\*)(\\s|\\S)*(\\*)( )( )/)|((/( )( )/)(.*)))", "B"},  //COMMENT
    {"((/( )( )\\*(?:.|[\\n\\r])*?\\*( )( )/)|((/( )( )/)(.*)))", "B"}, //COMMENT

    /*HEADER*/
    {"(( )(\\s*)(import)(\\s*)(( ))([\\s\\S]*?)(;( ))", "C"}, //HEADER
    {"(( )(\\s*)(package)(\\s*)(( ))([\\s\\S]*?)(;( ))", "C"},

    /*TOTALQUOTE*/
    {"(\"[^\"^\\n]*(\"|\\n))|(\'[^\'^\\n]*(\'|\\n))", "E"}, //TOTALQUOTE

    /*NUMBER*/
    {"(( )(0([0-7]*(UL|ul|LU|lu|L|l|U|u)?))( ))|(( )(0(x|X)[0-9a-fA-F]+(UL|ul|LU|lu|L|l|U|u)?)( ))|(( )(((([0-9]+(( )\\.( ))[0-9]*)|([0-9]*(( )\\.( ))[0-9]+))([eE](( )[-+]( ))?[0-9]+[flFLdD]?)?)|([0-9]+(e|E)(( )[-+]( ))?[0-9]+[flFLdD]?))( ))|(( )([1-9][0-9]*(UL|ul|LU|lu|L|l|U|u)?)( ))", "F"}, //NUMBER

    /*CASE*/
    {"(( )(case(\\s+)(.*))|default)(\\s*):", "G"}, //CASE

    /* APPLY */
    {"(( )System( )\\.( )Out( )\\.( )Println( )", "M"},
    {"(( )System( )\\.( )Out( )\\.( )Print( ))", "M"},

    /*OPERATOR*/
    {"(\\.(  )\\.(  )\\.)|(-(  )>(  )\\*)|(:(  ):)|(\\.(  )>)|(-(  )>)|(\\.(  )\\*)", "H"},                                                     //OTHER_OPERATOR_1  //OTHER_OPERATOR
    {"(<(  )<(  )=)|(>(  )>(  )=)|(\\*(  )=)|(/(  )=)|(%(  )=)|(\\+(  )=)|(-(  )=)|(&(  )=)|(\\^(  )=)|(\\|(  )=)|(\\+(  )\\+)|(-(  )-)", "I"}, //ASSIGN_OPERATOR_1  //ASSIGN_OPERATOR
    {"(<(  )<)|(>(  )>)", "J"},                                                                                                                 //BITWISE_OPERATOR_1  //BITWISE_OPERATOR
    {"(<(  )=)|(>(  )=)|(\\|(  )\\|)|(&(  )&)|(=(  )=)|(!(  )=)|(<)|(>)|(\\?)", "K"},                                                           //RELATIONAL_OPERATOR  //RELATIONAL_OPERATOR
    {"(~)|(\\|)|(&)|(\\^)", "J"},                                                                                                               //BITWISE_OPERATOR_2   //BITWISE_OPERATOR
    {"(=)", "I"},                                                                                                                               //ASSIGN_OPERATOR_2  //ASSIGN_OPERATOR
    {"(\\+)|(-)|(\\*)|(/)|(%)|(!)", "L"},                                                                                                       //ARITHMETIC_OPERATOR
    {"(:)|(\\.)", "H"},                                                                                                                         //OTHER_OPERATOR_2

    /*IF*/
    {"( )(if|(if(\\s+)constexpr))( )", "N"},

    /*DATATYPE*/
    {"((( )(consteval|constexpr|constinit|const_cast|extern|long|mutable|register|short|signed|static|static_assert|static_cast|unsigned|const|volatile|byte|varJDK)( )(\\s*))*(( )(auto|bool|boolean|Boolean|char|char8_t|char16_t|char32_t|double|float|int|Byte|byte|Long|Float|Integer|Double|Character|wchar_t|void|struct|union|enum|typedef|string|vector|map|pair|template)( )))", "O"},

    /*SEPERATOR*/
    {";", "P"}, //SEMICOLON
    {",", "Q"}, //COMMA

    /*Braces*/
    {"\\{", "R"}, //L_CURLY_BRACE
    {"\\}", "S"}, //R_CURLY_BRACE
    {"\\[", "T"}, //L_SQUARE_BRACKET
    {"\\]", "U"}, //R_SQUARE_BRACKET
    {"\\(", "V"}, //L_PARENTHESIS
    {"\\)", "W"}, //R_PARENTHESIS

    /*  @keyword  */
    {"(( )@( )[A-Za-z_]+( ))", "o"},

    /*IDENTIFIER*/
    {"(( )[A-Za-z_]+[0-9A-Za-z_]*( ))", "X"} //ID

};

/*MAP OF ALL KEYWORDS*/
unordered_map<string, string> KEYWORD_hash_Map_Java{

    /*LOOP KEYWODS*/
    {" for ", "Y"},
    {" while ", "Y"},
    {" do ", "Y"},

    /*NUMBERS*/
    {" true ", "F"},
    {" false ", "F"},
    {" NULL ", "F"},
    {" null ", "F"},

    /*DATATYPE KEYWORDS*/
    {" long ", "O"},
    {" short ", "O"},
    {" signed ", "O"},
    {" unsigned ", "O"},
    {" boolean ", "O"},
    {" byte ", "O"},
    {" char ", "O"},
    {" double ", "O"},
    {" float ", "O"},
    {" int ", "O"},
    {" enum ", "O"},
    {" var ", "O"},
    {" varJDK ", "O"},
    {" String ", "O"},
    {" StringBuffer ", "O"},

    /*APPLY KEYWORDS*/
    // {" System . Out . Println ", "M"},
    // {" System . Out . Print ", "M"},
    {" Scanner ", "M"},

    /*OPERATOR KEYWORDS*/
    {" sizeof ", "H"}, //OTHER_OPERATOR
    {" and ", "K"},    //RELATIONAL_OPERATOR
    {" xor ", "K"},    //RELATIONAL_OPERATOR
    {" not ", "K"},    //RELATIONAL_OPERATOR
    {" bitand ", "J"}, //BITWISE_OPERATOR
    {" bitor ", "J"},  //BITWISE_OPERATOR
    {" compl ", "J"},  //BITWISE_OPERATOR
    {" and_eq ", "I"}, //ASSIGN_OPERATOR
    {" not_eq ", "I"}, //ASSIGN_OPERATOR
    {" xor_eq ", "I"}, //ASSIGN_OPERATOR

    /*KEYWORDS USED FOR TOKENIZATION*/
    {" switch ", "Z"},
    {" case ", "D"},
    {" else ", "a"},
    {" break ", "b"},
    {" continue ", "c"},
    {" return ", "d"},
    {" catch ", "f"},
    {" throw ", "g"},
    {" throws ", "e"},
    {" synchronized ", "h"},
    {" class ", "i"},
    {" typedef ", "j"},
    {" default ", "D"},
    {" try ", "n"},

    /* COLLECTION  */
    {" Collection ", "l"},
    {" PriorityQueue ", "l"},
    {" Comparable ", "l"},
    {" Comparator ", "l"},
    {" Enumeration ", "l"},
    {" Iterator ", "l"},
    {" ListIterator ", "l"},
    {" Collections ", "l"},
    {" Array ", "l"},
    {" Queue ", "l"},
    {" Deque ", "l"},
    {" Set ", "l"},
    {" HashSet ", "l"},
    {" LinkedHashSet ", "l"},
    {" SortedSet ", "l"},
    {" NavigableSet ", "l"},
    {" TreeSet ", "l"},
    {" List ", "l"},
    {" ArrayList ", "l"},
    {" LinkedList ", "l"},
    {" Vector ", "l"},
    {" Stack ", "l"},

    /* MAP */
    {" Map ", "m"},
    {" HashMap ", "m"},
    {" LinkedHashMap ", "m"},
    {" WeakHashMap ", "m"},
    {" IdentityHashMap ", "m"},
    {" Hashtable ", "m"},
    {" Properties ", "m"},
    {" SortedMap ", "m"},
    {" NavigableMap ", "m"},
    {" TreeMap ", "m"},

    /* HEADER */
    {" package ", "C"},
    {" import ", "C"},

    /*OTHER KEYWORDS*/
    {" abstract ", "k"},
    {" alignas ", "k"},
    {" alignof ", "k"},
    {" assert ", "k"},
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

    {" explicit ", "k"},
    {" export ", "k"},
    {" extern ", "k"},
    {" extends ", "k"},
    {" endif ", "k"},
    {" elif ", "k"},
    {" error ", "k"},

    {" friend ", "k"},
    {" final ", "k"},
    {" finally ", "k"},
    {" finalize ", "k"},

    {" inline ", "k"},
    {" ifdef ", "k"},
    {" ifndef ", "k"},
    {" if ", "N"},
    {" implements ", "k"},
    {" instanceof ", "k"},
    {" interface ", "k"},

    {" line ", "k"},

    {" mutable ", "k"},

    {" native ", "k"},
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
    {" strictfp ", "k"},
    {" super ", "k"},

    {" this ", "k"},
    {" thread_local ", "k"},
    {" transient ", "k"},

    {" typeid ", "k"},
    {" typename ", "k"},

    {" undef ", "k"},
    {" using ", "k"},

    {" virtual ", "k"},
    {" volatile ", "k"},
    {" void ", "k"},

    {" __has_include ", "k"},
    {" __has_cpp_attribute ", "k"},

    /*  @keyword  */
    {" @Override ", "o"},
    {" @Deprecated ", "o"},
    {" @SuppressWarnings ", "o"},
    {" @Retention ", "o"},
    {" @Documented ", "o"},
    {" @Target ", "o"},
    {" @Inherited ", "o"},
    {" @SafeVarargs ", "o"},
    {" @FunctionalInterface ", "o"},
    {" @Repeatable ", "o"},

    {" @UnderConstruction ", "o"},
    {" @interface ", "o"},
    {" @Entity ", "o"},
    {" @Table ", "o"},
    {" @Id ", "o"},
    {" @GeneratedValue ", "o"},
    {" @Column ", "o"}

};
