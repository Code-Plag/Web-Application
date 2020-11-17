
MATCHER::MATCHER(unsigned long int Folder_Files_Index_1, unsigned long int Folder_Files_Index_2, vector <TOKEN> file_1_token_vector, vector <TOKEN> file_2_token_vector, vector < MATCH > Tiles)

{
    this->Folder_Files_Index_1 = Folder_Files_Index_1;
    this->Folder_Files_Index_2 = Folder_Files_Index_2;
    this->file_1_token_vector = file_1_token_vector;
    this->file_2_token_vector = file_2_token_vector;
    this->Tiles = Tiles;

    this->Match_Percent_1 = (getTotal_Match_Token_Count() * 100.00F) / file_1_token_vector.size();
    this->Match_Percent_2 = (getTotal_Match_Token_Count() * 100.00F) / file_2_token_vector.size();

    if( this->Match_Percent_1 > 100.00F)
        this->Match_Percent_1 = 100.00F;

    if( this->Match_Percent_2 > 100.00F)
        this->Match_Percent_2 = 100.00F;


    for(unsigned long int tiles_iterator = 0; tiles_iterator< Tiles.size(); tiles_iterator++)
    {
        for(unsigned long int match_iterator = 0;  match_iterator < Tiles[tiles_iterator].getToken_Matched_Length()  ; match_iterator++)
        {
            for( unsigned long int line_iterator_file_1 = file_1_token_vector[Tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_Start_Line_no();
                    line_iterator_file_1 <= file_1_token_vector[Tiles[tiles_iterator].getIndex_Pattern() + match_iterator].getToken_End_Line_no(); line_iterator_file_1++ )
            {
                line_file1.insert( { to_string(line_iterator_file_1), tiles_iterator } );
            }

            for( unsigned long int line_iterator_file_2 = file_2_token_vector[Tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_Start_Line_no();
                    line_iterator_file_2 <= file_2_token_vector[Tiles[tiles_iterator].getIndex_Text() + match_iterator].getToken_End_Line_no(); line_iterator_file_2++ )
            {
                line_file2.insert( { to_string(line_iterator_file_2), tiles_iterator } );
            }
        }
    }

}


MATCH MATCHER:: getTiles_Match(unsigned long int index)
{
    if ( index < Tiles.size() )
        return Tiles[index];
    else
        throw "Unauthorized Access";
}

vector < MATCH > MATCHER:: getTiles()
{
    return this->Tiles;
}



unsigned long int MATCHER:: getFolder_Files_Index_1()
{
    return Folder_Files_Index_1;
}

unsigned long int MATCHER:: getFolder_Files_Index_2()
{
    return Folder_Files_Index_2;
}

unsigned long int MATCHER:: getTotal_Match_Token_Count()
{
    unsigned long int Count = 0;
    for(auto Tiles_Iterator = Tiles.begin(); Tiles_Iterator != Tiles.end(); Tiles_Iterator++)
    {
        Count += Tiles_Iterator->getToken_Matched_Length();
    }
    return Count;
}

float MATCHER:: getMatch_Percent_1()
{
    return Match_Percent_1;
}

float MATCHER:: getMatch_Percent_2()
{
    return Match_Percent_2;
}

vector <TOKEN> MATCHER:: getfile_1_token_vector()
{
    return file_1_token_vector;
}

vector <TOKEN> MATCHER:: getfile_2_token_vector()
{
    return file_2_token_vector;
}
unordered_map < string, unsigned long int > MATCHER:: getline_file1()
{
    return line_file1;
}
unordered_map < string, unsigned long int > MATCHER::getline_file2()
{
    return line_file2;
}


