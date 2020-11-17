
void createHTML(string ResultPath, vector<TOKENIZER> Folder_Files, vector<MATCHER> ALL_MATCHES)
{

    for (unsigned int All_MATCHES_INDEX = 0; All_MATCHES_INDEX < ALL_MATCHES.size(); All_MATCHES_INDEX++)
    {

        string file1_name = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_1()].getSource_File_Name();
        string file1_code = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_1()].getOriginal_Source_File_Code();
        unordered_map<string, unsigned int> line_file1 = ALL_MATCHES[All_MATCHES_INDEX].getline_file1();
        float percent_1 = ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_1();
        unsigned int linecounter1 = 1;

        string file2_name = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_2()].getSource_File_Name();
        string file2_code = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_2()].getOriginal_Source_File_Code();
        unordered_map<string, unsigned int> line_file2 = ALL_MATCHES[All_MATCHES_INDEX].getline_file2();
        float percent_2 = ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_2();
        unsigned int linecounter2 = 1;

        file1_code = regex_replace(file1_code, regex("<"), "&lt;");
        file1_code = regex_replace(file1_code, regex(">"), "&gt;");
        file2_code = regex_replace(file2_code, regex("<"), "&lt;");
        file2_code = regex_replace(file2_code, regex(">"), "&gt;");

        ofstream outStream;

        //TO COLOR FILE 1 CODE
        istringstream file1_code_stream(file1_code);
        string line1;

        outStream.open(ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-0" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file1_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>"
                  << "<center> <h2>" << file1_name << "</h2> </center>"
                  << "<hr>"
                  << "<pre>";

        while (getline(file1_code_stream, line1))
        {

            if (line_file1.find(to_string(linecounter1)) != line_file1.end())
            {

                outStream << "<a style = \" color: " << Color[line_file1[to_string(linecounter1)] % Color.size()] << "; font-weight: bold; font-size: 13px;"
                          << "text-decoration: none \" name = \"" << line_file1[to_string(linecounter1)] << "\" href = "
                          << ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-1" + ".html#" << line_file1[to_string(linecounter1)] << " \" "
                          << "target = \"iframe_2\" >"
                          << line1 << "\n"
                          << "</a>";
            }

            else
            {
                outStream << line1 << "\n";
            }
            linecounter1++;
        }

        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();

        //TO COLOR FILE 2 CODE
        istringstream file2_code_stream(file2_code);
        string line2;

        outStream.open(ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-1" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file2_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>"
                  << "<center> <h2>" << file2_name << "</h2> </center>"
                  << "<hr>"
                  << "<pre>";

        while (getline(file2_code_stream, line2))
        {
            if (line_file2.find(to_string(linecounter2)) != line_file2.end())
            {
                outStream << "<a style = \" color: " << Color[line_file2[to_string(linecounter2)] % Color.size()] << "; font-weight: bold; font-size: 13px; "
                          << "text-decoration: none \" name = \"" << line_file2[to_string(linecounter2)] << "\" href = "
                          << ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-0" + ".html#" << line_file2[to_string(linecounter2)] << " \" "
                          << "target = \"iframe_1\" >"
                          << line2 << "\n"
                          << "</a>";
            }
            else
            {
                outStream << line2 << "\n";
            }
            linecounter2++;
        }

        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();

        //IFRAME CODE
        string match_iframe = ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + ".html";
        outStream.open(match_iframe);
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<body>\n"
                  << "<head><title>" << file1_name << "-" << file2_name << "</title>"
                  << "</head>\n"
                  << "<hr>"
                  << "<center> <h3 style=\"font-family:verdana\"><u> RESULTS "
                  << "</u></h3> </center>"
                  << "\n"
                  << "<center> <h4 style=\"font-family:verdana\"> "
                  << file1_name << " - "
                  << "<b><u>"
                  << "<font color=\"red\">" << percent_1 << "%"
                  << "</font>"
                  << "</b></u>"
                  << " & "
                  << file2_name << " - "
                  << "<b><u>"
                  << "<font color=\"red\">" << percent_2 << "%"
                  << "</font>"
                  << "</b></u>"
                  << "</h4> </center>"
                  << "<hr>\n"
                  << "<iframe height=\"500\" width=\"660\" src=\"match" + to_string(All_MATCHES_INDEX) + "-0" + ".html"
                  << " \" name = \"iframe_1\" >\n</iframe>\n"
                  << "<iframe height=\"500\" width=\"660\" src=\"match" + to_string(All_MATCHES_INDEX) + "-1" + ".html"
                  << " \" name = \"iframe_2\" >\n</iframe>\n"
                  << "</body>\n"
                  << "</html>";
        outStream.close();
    }

    return;
}

void createTokensHTML(string ResultPath, vector<TOKENIZER> Folder_Files, vector<MATCHER> ALL_MATCHES)
{
    for (unsigned int All_MATCHES_INDEX = 0; All_MATCHES_INDEX < ALL_MATCHES.size(); All_MATCHES_INDEX++)
    {
        vector<TOKEN> file_1_token_vector = ALL_MATCHES[All_MATCHES_INDEX].getfile_1_token_vector();
        string file1_name = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_1()].getSource_File_Name();
        unsigned int counter1 = 0;
        unordered_map<unsigned int, unsigned int> index_file1;

        vector<TOKEN> file_2_token_vector = ALL_MATCHES[All_MATCHES_INDEX].getfile_2_token_vector();
        string file2_name = Folder_Files[ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_2()].getSource_File_Name();
        unsigned int counter2 = 0;
        unordered_map<unsigned int, unsigned int> index_file2;

        vector<MATCH> Tiles = ALL_MATCHES[All_MATCHES_INDEX].getTiles();

        for (unsigned int tiles_iterator = 0; tiles_iterator < Tiles.size(); tiles_iterator++)
        {
            for (unsigned int match_iterator = 0; match_iterator < Tiles[tiles_iterator].getToken_Matched_Length(); match_iterator++)
            {
                index_file1.insert({Tiles[tiles_iterator].getIndex_Pattern() + match_iterator, tiles_iterator});
                index_file2.insert({Tiles[tiles_iterator].getIndex_Text() + match_iterator, tiles_iterator});
            }
        }

        ofstream outStream;

        //FOR FILE 1 TOKENS
        outStream.open(ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-0_tokens" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file1_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>"
                  << "<center> <h2>" << file1_name << "</h2> </center>"
                  << "<hr>"
                  << "<pre>";

        for (auto Tokenized_File_Iterator = file_1_token_vector.begin(); Tokenized_File_Iterator != file_1_token_vector.end(); Tokenized_File_Iterator++, counter1++)
        {

            if (index_file1.find(counter1) != index_file1.end())
            {
                outStream << "<a style = \" color: " << Color[index_file1[counter1] % Color.size()] << "; font-weight: bold; font-size: 13px; "
                          << "text-decoration: none\" name = \"" << index_file1[counter1] << "\" href = "
                          << ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-1_tokens" + ".html#" << index_file1[counter1] << " \" >"
                          << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                          << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                          << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                          << "Content: " << Tokenized_File_Iterator->getToken_Content() << "\n"
                          << "Token Index: " << counter1 << "\n"
                          << "Color Index: " << index_file1[counter1] % Color.size() << "\n"
                          << "</a>"
                          << "-----------------------------------------------------------------------\n";
            }
            else
            {
                outStream << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                          << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                          << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                          << "Content: " << Tokenized_File_Iterator->getToken_Content() << "\n"
                          << "Token Index: " << counter1 << "\n"
                          << "-----------------------------------------------------------------------\n";
            }
        }
        outStream << "Total Tokens: " << counter1 << endl;
        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();

        //FOR FILE 2 TOKENS
        outStream.open(ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-1_tokens" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file2_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>"
                  << "<center> <h2>" << file2_name << "</h2> </center>"
                  << "<hr>"
                  << "<pre>";

        for (auto Tokenized_File_Iterator = file_2_token_vector.begin(); Tokenized_File_Iterator != file_2_token_vector.end(); Tokenized_File_Iterator++, counter2++)
        {

            if (index_file2.find(counter2) != index_file2.end())
            {
                outStream << "<a style = \" color: " << Color[index_file2[counter2] % Color.size()] << ";  font-weight: bold; font-size: 13px;"
                          << "text-decoration: none\" name = \"" << index_file2[counter2] << "\" href = "
                          << ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + "-0_tokens" + ".html#" << index_file2[counter2] << " \" >"
                          << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                          << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                          << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                          << "Content: " << Tokenized_File_Iterator->getToken_Content() << "\n"
                          << "Token Index: " << counter2 << "\n"
                          << "Color Index: " << index_file2[counter2] % Color.size() << "\n"
                          << "</a>"
                          << "-----------------------------------------------------------------------\n";
            }
            else
            {
                outStream << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                          << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                          << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                          << "Content: " << Tokenized_File_Iterator->getToken_Content() << "\n"
                          << "Token Index: " << counter2 << "\n"
                          << "-----------------------------------------------------------------------\n";
            }
        }
        outStream << "Total Tokens: " << counter2 << endl;
        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();

        return;
    }
}

/*void createHTML( unsigned long int matchno, string ResultPath, vector < MATCH > tiles, TOKENIZER file1, TOKENIZER file2 )
{

    vector <TOKEN> file_1_token_vector = file1.getTokenized_File_Vector();
    string file1_name = file1.getSource_File_Name();
    string file1_code = file1.getOriginal_Source_File_Code();
    file1_code = regex_replace(file1_code, regex("<"), "&lt;");
    file1_code = regex_replace(file1_code, regex(">"), "&gt;");
    unordered_map < unsigned long int, unsigned long int > index_file1;
    unsigned long int counter1 = 0;
    unsigned long int linecounter1 = 1;
    unordered_map < unsigned long int, unsigned long int > line_file1;


    vector <TOKEN> file_2_token_vector = file2.getTokenized_File_Vector();
    string file2_name = file2.getSource_File_Name();
    string file2_code = file2.getOriginal_Source_File_Code();
    file2_code = regex_replace(file2_code, regex("<"), "&lt;");
    file2_code = regex_replace(file2_code, regex(">"), "&gt;");
    unordered_map < unsigned long int, unsigned long int > index_file2;
    unsigned long int counter2 = 0;
    unsigned long int linecounter2 = 1;
    unordered_map < unsigned long int, unsigned long int > line_file2;


    for(unsigned long int tiles_iterator = 0; tiles_iterator< tiles.size(); tiles_iterator++)
    {
        for(unsigned long int match_iterator = 0;  match_iterator < tiles[tiles_iterator].getToken_Matched_Length()  ; match_iterator++)
        {
            index_file1.insert( {tiles[tiles_iterator].getIndex_Pattern() + match_iterator, tiles_iterator} );
            index_file2.insert( {tiles[tiles_iterator].getIndex_Text() + match_iterator, tiles_iterator} );


            for( unsigned long int line_iterator_file_1 = file_1_token_vector[tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_Start_Line_no();
                    line_iterator_file_1 <= file_1_token_vector[tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_End_Line_no(); line_iterator_file_1++ )
            {
                line_file1.insert( { line_iterator_file_1, tiles_iterator } );
            }

            for( unsigned long int line_iterator_file_2 = file_2_token_vector[tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_Start_Line_no();
                    line_iterator_file_2 <= file_2_token_vector[tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_End_Line_no(); line_iterator_file_2++ )
            {
                line_file2.insert( { line_iterator_file_2, tiles_iterator } );
            }
        }
    }

    ofstream outStream;

    //FOR FILE 1 TOKENS
    outStream.open(ResultPath + "/" + "match" +  to_string(matchno) + "-0_tokens" + ".html");
    outStream << "<!DOCTYPE html>\n"
              << "<html>"
              << "<head><title>" << file1_name << "</title></head>\n"
              << "<body BGCOLOR=\"#ffffff\">\n"
              << "<hr>" << "<center> <h2>" << file1_name << "</h2> </center>" << "<hr>"
              << "<pre>";

    for ( auto Tokenized_File_Iterator = file_1_token_vector.begin(); Tokenized_File_Iterator != file_1_token_vector.end(); Tokenized_File_Iterator++, counter1++)
    {

        if( index_file1.find(counter1)  !=  index_file1.end())
        {
            outStream << "<a style = \" color: " << Color[index_file1[counter1] % Color.size()] << "; font-weight: bold; font-size: 13px; "
                      << "text-decoration: none\" name = \""  <<index_file1[counter1] << "\" href = "
                      << ResultPath + "/" + "match" +  to_string(matchno) + "-1_tokens" + ".html#" << index_file1[counter1]  << " \" >"
                      << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                      << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                      << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                      << "Content: " << Tokenized_File_Iterator->getToken_Content()<< "\n"
                      << "Token Index: " << counter1 << "\n"
                      << "Color Index: " << index_file1[counter1] % Color.size() << "\n"
                      << "</a>"
                      << "-----------------------------------------------------------------------\n";
        }
        else
        {
            outStream << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                      << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                      << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                      << "Content: " << Tokenized_File_Iterator->getToken_Content()<< "\n"
                      <<"Token Index: " << counter1 << "\n"
                      << "-----------------------------------------------------------------------\n";

        }
    }
    outStream <<"Total Tokens: "<< counter1 << endl;
    outStream << "</pre>"
              << "</body>"
              << "</html>";
    outStream.close();




    //FOR FILE 2 TOKENS
    outStream.open(ResultPath + "/" + "match" +  to_string(matchno) + "-1_tokens" + ".html");
    outStream << "<!DOCTYPE html>\n"
              << "<html>"
              << "<head><title>" << file2_name << "</title></head>\n"
              << "<body BGCOLOR=\"#ffffff\">\n"
              << "<hr>" << "<center> <h2>" << file2_name << "</h2> </center>" << "<hr>"
              << "<pre>";

    for ( auto Tokenized_File_Iterator = file_2_token_vector.begin(); Tokenized_File_Iterator != file_2_token_vector.end(); Tokenized_File_Iterator++, counter2++)
    {

        if( index_file2.find(counter2)  !=  index_file2.end())
        {
            outStream << "<a style = \" color: " << Color[index_file2[counter2] % Color.size()] << ";  font-weight: bold; font-size: 13px;"
                      << "text-decoration: none\" name = \""  << index_file2[counter2] << "\" href = "
                      << ResultPath + "/" + "match" +  to_string(matchno) + "-0_tokens" + ".html#" << index_file2[counter2]  << " \" >"
                      << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                      << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                      << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                      << "Content: " << Tokenized_File_Iterator->getToken_Content()<< "\n"
                      <<"Token Index: " << counter2 << "\n"
                      << "Color Index: " << index_file2[counter2] % Color.size() << "\n"
                      << "</a>"
                      << "-----------------------------------------------------------------------\n";


        }
        else
        {
            outStream << "Start line no: " << Tokenized_File_Iterator->getToken_Start_Line_no() << "\n"
                      << "Token ID: " << Tokenized_File_Iterator->getToken_Type() << "\n"
                      << "End line no: " << Tokenized_File_Iterator->getToken_End_Line_no() << "\n"
                      << "Content: " << Tokenized_File_Iterator->getToken_Content()<< "\n"
                      <<"Token Index: " << counter2 << "\n"
                      << "-----------------------------------------------------------------------\n";
        }
    }
    outStream << "Total Tokens: " << counter2 << endl;
    outStream << "</pre>"
              << "</body>"
              << "</html>";
    outStream.close();




    //TO COLOR FILE 1 CODE
    istringstream file1_code_stream(file1_code);
    string line1;

    outStream.open(ResultPath + "/" + "match" +  to_string(matchno) + "-0" + ".html");
    outStream << "<!DOCTYPE html>\n"
              << "<html>"
              << "<head><title>" << file1_name << "</title></head>\n"
              << "<body BGCOLOR=\"#ffffff\">\n"
              << "<hr>" << "<center> <h2>" << file1_name << "</h2> </center>" << "<hr>"
              << "<pre>";

    while(getline(file1_code_stream, line1))
    {

        if(line_file1.find(linecounter1) != line_file1.end())
        {

            outStream << "<a style = \" color: " << Color[line_file1[linecounter1] % Color.size()] << "; font-weight: bold; font-size: 13px;"
                      << "text-decoration: none \" name = \""  << line_file1[linecounter1] << "\" href = "
                      << ResultPath + "/" + "match" +  to_string(matchno) + "-1" + ".html#" << line_file1[linecounter1]  << " \" "
                      << "target = \"iframe_2\" >"
                      << line1 << "\n"
                      << "</a>";
        }

        else
        {
            outStream << line1 << "\n";
        }
        linecounter1++;
    }

    outStream << "</pre>"
              << "</body>"
              << "</html>";
    outStream.close();




    //TO COLOR FILE 2 CODE
    istringstream file2_code_stream(file2_code);
    string line2;

    outStream.open(ResultPath + "/" + "match" +  to_string(matchno) + "-1" + ".html");
    outStream << "<!DOCTYPE html>\n"
              << "<html>"
              << "<head><title>" << file2_name << "</title></head>\n"
              << "<body BGCOLOR=\"#ffffff\">\n"
              << "<hr>" << "<center> <h2>" << file2_name << "</h2> </center>" << "<hr>"
              << "<pre>";

    while(getline(file2_code_stream, line2))
    {
        if(line_file2.find(linecounter2) != line_file2.end())
        {
            outStream << "<a style = \" color: " << Color[line_file2[linecounter2] % Color.size()] << "; font-weight: bold; font-size: 13px; "
                      << "text-decoration: none \" name = \""  << line_file2[linecounter2] << "\" href = "
                      << ResultPath + "/" + "match" +  to_string(matchno) + "-0" + ".html#" << line_file2[linecounter2]  << " \" "
                      << "target = \"iframe_1\" >"
                      << line2 << "\n"
                      << "</a>";
        }
        else
        {
            outStream << line2 << "\n";
        }
        linecounter2++;
    }

    outStream << "</pre>"
              << "</body>"
              << "</html>";
    outStream.close();


    //IFRAME CODE
    string match_iframe = ResultPath + "/" + "match" + to_string(matchno) + ".html";
    outStream.open(match_iframe);
    outStream << "<!DOCTYPE html>\n"
              << "<html>"
              << "<head><title>" << file1_name << "=====" << file2_name << "</title>"
              << "<META http-equiv = \"Content-Type\" content=\"text/html; charset=iso-8859-1\" > \n"
              << "</head>\n"
              //<< "<hr>" << "<center> <h2>" << file1_name << "=====" << file2_name  << "</h2> </center>" << "<hr>\n"
              << "<FRAMESET COLS = \"50%,50%\" > \n "
              << "<FRAME SRC=\""<<  "match" +  to_string(matchno) + "-0" + ".html" << " \" name = \"iframe_1\" >\n"
              << "<FRAME SRC=\""<<  "match" +  to_string(matchno) + "-1" + ".html" << " \" name = \"iframe_2\" >\n"
              << "</FRAMESET>\n"
              << "</html>";
    outStream.close();

    return;
}*/

/*
void createHTML_New( string ResultPath, vector <MATCHER> ALL_MATCHES )
{

    for(unsigned long int All_MATCHES_INDEX = 0; All_MATCHES_INDEX < ALL_MATCHES.size() ; All_MATCHES_INDEX++ )
    {

        vector <TOKEN> file_1_token_vector = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_1().getTokenized_File_Vector();
        string file1_name = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_1().getSource_File_Name();
        string file1_code = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_1().getOriginal_Source_File_Code();
        file1_code = regex_replace(file1_code, regex("<"), "&lt;");
        file1_code = regex_replace(file1_code, regex(">"), "&gt;");
        unordered_map < unsigned long int, unsigned long int > index_file1;
        unsigned long int counter1 = 0;
        unsigned long int linecounter1 = 1;
        unordered_map < unsigned long int, unsigned long int > line_file1;
        float percent_1 = ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_1();

        vector <TOKEN> file_2_token_vector = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_2().getTokenized_File_Vector();
        string file2_name = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_2().getSource_File_Name();
        string file2_code = ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_2().getOriginal_Source_File_Code();
        file2_code = regex_replace(file2_code, regex("<"), "&lt;");
        file2_code = regex_replace(file2_code, regex(">"), "&gt;");
        unordered_map < unsigned long int, unsigned long int > index_file2;
        unsigned long int counter2 = 0;
        unsigned long int linecounter2 = 1;
        unordered_map < unsigned long int, unsigned long int > line_file2;
         float percent_2 = ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_2();

        vector < MATCH > tiles = ALL_MATCHES[All_MATCHES_INDEX].getTiles();




        for(unsigned long int tiles_iterator = 0; tiles_iterator< tiles.size(); tiles_iterator++)
        {
            for(unsigned long int match_iterator = 0;  match_iterator < tiles[tiles_iterator].getToken_Matched_Length()  ; match_iterator++)
            {
                index_file1.insert( {tiles[tiles_iterator].getIndex_Pattern() + match_iterator, tiles_iterator} );
                index_file2.insert( {tiles[tiles_iterator].getIndex_Text() + match_iterator, tiles_iterator} );


                for( unsigned long int line_iterator_file_1 = file_1_token_vector[tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_Start_Line_no();
                        line_iterator_file_1 <= file_1_token_vector[tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_End_Line_no(); line_iterator_file_1++ )
                {
                    line_file1.insert( { line_iterator_file_1, tiles_iterator } );
                }

                for( unsigned long int line_iterator_file_2 = file_2_token_vector[tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_Start_Line_no();
                        line_iterator_file_2 <= file_2_token_vector[tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_End_Line_no(); line_iterator_file_2++ )
                {
                    line_file2.insert( { line_iterator_file_2, tiles_iterator } );
                }
            }
        }




        ofstream outStream;

        //TO COLOR FILE 1 CODE
        istringstream file1_code_stream(file1_code);
        string line1;

        outStream.open(ResultPath + "/" + "match" +  to_string(All_MATCHES_INDEX) + "-0" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file1_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>" << "<center> <h2>" << file1_name << "</h2> </center>" << "<hr>"
                  << "<pre>";

        while(getline(file1_code_stream, line1))
        {

            if(line_file1.find(linecounter1) != line_file1.end())
            {

                outStream << "<a style = \" color: " << Color[line_file1[linecounter1] % Color.size()] << "; font-weight: bold; font-size: 13px;"
                          << "text-decoration: none \" name = \""  << line_file1[linecounter1] << "\" href = "
                          << ResultPath + "/" + "match" +  to_string(All_MATCHES_INDEX) + "-1" + ".html#" << line_file1[linecounter1]  << " \" "
                          << "target = \"iframe_2\" >"
                          << line1 << "\n"
                          << "</a>";
            }

            else
            {
                outStream << line1 << "\n";
            }
            linecounter1++;
        }

        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();




        //TO COLOR FILE 2 CODE
        istringstream file2_code_stream(file2_code);
        string line2;

        outStream.open(ResultPath + "/" + "match" +  to_string(All_MATCHES_INDEX) + "-1" + ".html");
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file2_name << "</title></head>\n"
                  << "<body BGCOLOR=\"#ffffff\">\n"
                  << "<hr>" << "<center> <h2>" << file2_name << "</h2> </center>" << "<hr>"
                  << "<pre>";

        while(getline(file2_code_stream, line2))
        {
            if(line_file2.find(linecounter2) != line_file2.end())
            {
                outStream << "<a style = \" color: " << Color[line_file2[linecounter2] % Color.size()] << "; font-weight: bold; font-size: 13px; "
                          << "text-decoration: none \" name = \""  << line_file2[linecounter2] << "\" href = "
                          << ResultPath + "/" + "match" +  to_string(All_MATCHES_INDEX) + "-0" + ".html#" << line_file2[linecounter2]  << " \" "
                          << "target = \"iframe_1\" >"
                          << line2 << "\n"
                          << "</a>";
            }
            else
            {
                outStream << line2 << "\n";
            }
            linecounter2++;
        }

        outStream << "</pre>"
                  << "</body>"
                  << "</html>";
        outStream.close();


        //IFRAME CODE
        string match_iframe = ResultPath + "/" + "match" + to_string(All_MATCHES_INDEX) + ".html";
        outStream.open(match_iframe);
        outStream << "<!DOCTYPE html>\n"
                  << "<html>"
                  << "<head><title>" << file1_name << "=====" << file2_name << "</title>"
                  << "<META http-equiv = \"Content-Type\" content=\"text/html; charset=iso-8859-1\" > \n"
                  << "</head>\n"
                  //<< "<hr>" << "<center> <h2>" << file1_name << "=====" << file2_name  << "</h2> </center>" << "<hr>\n"
                  << "<FRAMESET COLS = \"50%,50%\" > \n "
                  << "<FRAME SRC=\""<<  "match" +  to_string(All_MATCHES_INDEX) + "-0" + ".html" << " \" name = \"iframe_1\" >\n"
                  << "<FRAME SRC=\""<<  "match" +  to_string(All_MATCHES_INDEX) + "-1" + ".html" << " \" name = \"iframe_2\" >\n"
                  << "</FRAMESET>\n"
                  << "</html>";
        outStream.close();
    }

    return;
}


*/
