#include "header.cpp"

//ADD FOLLOWING LINES AS ARGUMENTS OF MAIN IF PATH IS TO BE GIVEN FROM COMMAND PROMPT
//*int argc, char* argv[]
int main(int argc, char* argv[])
{       //C:\\Users\\Admin\\Desktop\\code-palag\\models\\MODULAR_CODE\\Testing\\cpp
    string FolderPath =  argv[1];   //   E:\Plagirism_Project\MODULAR_CODE\Testing\DS-EXAM 1 TREE REPLACE with argv[2];E:\Plagirism_Project\MODULAR_CODE\Testing
    string ResultPath =  argv[2];
    vector <TOKENIZER> Folder_Files; // VECTOR TO STORE ALL DATA OF FILES //Folder_Files[0].;
    string Language = "c/c++" ;  // REPLACE with argv[1];
    vector <MATCHER> ALL_MATCHES;
    set<string> All_Languages { "c/c++", "java", "python" };
    int  Minimum_Matching_length = 20;
    cout<<"***Measure of Software Plagiarism***" << endl << endl;
    try
    {
        if(!isLanguageValid(Language, All_Languages))
            throw  "Error: Invalid Language!";

        if(!isPathValid(FolderPath))
            throw  "Error: Source Directory Not Found!";

        if(!isPathValid(ResultPath))
            throw  "Error: Result Directory Not Found!";

        if(!CreateTokens(Language, FolderPath, Folder_Files))
            throw  "Error: Directory does not have enough valid files to compare!";
    }

    catch(const char* Error)
    {
        cout<<Error<<endl;
        string  sERROR = Error;
        if(sERROR == "Error: Invalid Language!")
        {
            cout<<"Languages should be one of these: ";
            for (auto itarg = All_Languages.begin(); itarg != All_Languages.end(); itarg++)
                cout << *itarg << ",   ";
            cout << endl;
        }

        return 0;
    }


    cout <<"sensitivity:  " << Minimum_Matching_length << endl;
    int counter =0;
    if(Folder_Files.size() <=1)
        return 0;

    for (unsigned long int i = 0; i < Folder_Files.size()-1 ; i++ )
    {
        for( unsigned long int j = i+1; j < Folder_Files.size(); j++)
        {
            GREEDY g1(Folder_Files[i].getSource_File_Token(), Folder_Files[j].getSource_File_Token(), Minimum_Matching_length);
            g1.Greedy_Rabin_Karp_Driver();
            //g1.tiling();

            MATCHER m1(i, j, Folder_Files[i].getTokenized_File_Vector(), Folder_Files[j].getTokenized_File_Vector(), g1.getTiles());
            ALL_MATCHES.push_back(m1);
             //cout << endl << endl;
            counter++;
            cout << counter << endl;
        }
    }
    cout << endl << "Total Compared Pairs:  " << ALL_MATCHES.size() << endl << endl;
    sort(ALL_MATCHES.begin(), ALL_MATCHES.end(), compare_Matches_percentage );

    for(unsigned long int i = 0; i < ALL_MATCHES.size(); i++)
    {
        cout << Folder_Files[ALL_MATCHES[i].getFolder_Files_Index_1()].getSource_File_Name()
             << "   "
             << Folder_Files[ALL_MATCHES[i].getFolder_Files_Index_2()].getSource_File_Name();
        cout << "   Percent 1: ";
        printf("%.2f %%", ALL_MATCHES[i].getMatch_Percent_1());
        cout << "   Percent 2: ";
        printf("%.2f %%", ALL_MATCHES[i].getMatch_Percent_2());
        cout << endl;
    }


    createJSON(ResultPath, Folder_Files, ALL_MATCHES);
    //createHTML(ResultPath, Folder_Files, ALL_MATCHES);
    //createTokensHTML(ResultPath, Folder_Files, ALL_MATCHES);

    return 0;
}
