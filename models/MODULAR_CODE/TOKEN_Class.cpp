

/*TOKEN INITIALIZATION CONSTRUCTOR*/
    TOKEN:: TOKEN()
    {
        Token_Type = "";
        Token_Content = "";
        Token_Start_Line_no = 0;
        Token_End_Line_no = 0;
        Token_Start_Pos =0;
        Token_End_Pos = 0;
    }
/*SETTER FUNCTIONS*/

void TOKEN::setToken_Type(string Token_Type)
{
    this->Token_Type = Token_Type;
}

void TOKEN::setToken_Content(string Token_Content)
{
    this->Token_Content = Token_Content;
}

void TOKEN::setToken_Start_Line_no(unsigned long int Token_Start_Line_no)
{
    this->Token_Start_Line_no = Token_Start_Line_no;
}

void TOKEN::setToken_End_Line_no(unsigned long int Token_End_Line_no)
{
    this->Token_End_Line_no = Token_End_Line_no;
}

void TOKEN::setTokenPos(unsigned long int Token_Start_Pos, unsigned long int Token_End_Pos)
{
    this->Token_Start_Pos = Token_Start_Pos;
    this->Token_End_Pos = Token_End_Pos;
}

void TOKEN::setToken_Line_no(unsigned long int Token_Start_Line_no, unsigned long int Token_End_Line_no)
{
    this->Token_Start_Line_no = Token_Start_Line_no;
    this->Token_End_Line_no = Token_End_Line_no;
}

/*GETTER FUNCTIONS*/
string TOKEN::getToken_Type()
{
    return this->Token_Type;
}

string TOKEN::getToken_Content()
{
    return this->Token_Content;
}

unsigned long int TOKEN::getToken_Start_Line_no()
{
    return this->Token_Start_Line_no;
}

unsigned long int TOKEN::getToken_End_Line_no()
{
    return this->Token_End_Line_no;
}

unsigned long int TOKEN::getToken_Start_Pos()
{
    return this->Token_Start_Pos;
}

unsigned long int TOKEN::getToken_End_Pos()
{
    return this->Token_End_Pos;
}
