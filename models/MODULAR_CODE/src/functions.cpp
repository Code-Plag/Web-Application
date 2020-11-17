
//file Argument Path check
bool isLanguageValid(string Language, set<string> &All_Languages)
{

    if (All_Languages.find(Language) != All_Languages.end())
        return true;
    else
        return false;
}

bool isPathValid(string FolderPath)
{
    const char *pathName = FolderPath.c_str(); // REPLACE PATH WITH argv[1] TO GIVE PATH IN COMMAND PROMPT
    DIR *dir;                                  // POINTER TO AN OPEN DIRECTORY
    struct dirent *entry;                      // STUFF IN THE DIRECTORY
    if ((dir = opendir(pathName)) != NULL)
        return true;
    return false;
}

bool CreateTokens(string Language, string FolderPath, vector<TOKENIZER> &Folder_Files)
{
    const char *pathName = FolderPath.c_str(); // REPLACE PATH WITH argv[1] TO GIVE PATH IN COMMAND PROMPT
    DIR *dir;                                  // POINTER TO AN OPEN DIRECTORY
    struct dirent *entry;                      // STUFF IN THE DIRECTORY
    dir = opendir(pathName);                   // OPEN DIRECTORY
    vector<string> Valid_File_Name;
    while ((entry = readdir(dir)) != NULL) // READ DIRECTORY
    {
        string Source_File_Name = entry->d_name; // STORE FILE NAME FOR VERIFICATION
        if (Language == "c/c++")
        {

            if (Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "cpp" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "CPP" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "cxx" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "CXX" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "c++" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "C++" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "c" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "C" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "cc" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "CC" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "h" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "H" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "hpp" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "HPP" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "hh" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "HH")
            {
                if (isEmpty_Dir_File(FolderPath, Source_File_Name))
                {
                    cout << Source_File_Name << " is Empty!" << endl;
                    continue;
                }
                else
                {
                    Valid_File_Name.push_back(Source_File_Name);
                }
            }
        }
        else if (Language == "java")
        {
            if (Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "java" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "JAVA" ||
                Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "jav" || Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "JAV")
            {
                if (isEmpty_Dir_File(FolderPath, Source_File_Name))
                {
                    cout << Source_File_Name << " is Empty!" << endl;
                    continue;
                }
                else
                {
                    Valid_File_Name.push_back(Source_File_Name);
                }
            }
        }
        else if (Language == "python")
        {
            if (Source_File_Name.substr(Source_File_Name.find_last_of(".") + 1) == "py")
            {
                if (isEmpty_Dir_File(FolderPath, Source_File_Name))
                {
                    cout << Source_File_Name << " is Empty!" << endl;

                    continue;
                }
                else
                {
                    Valid_File_Name.push_back(Source_File_Name);
                }
            }
        }

    } // CLOSE WHILE
    if (Valid_File_Name.size() <= 1)
    {
        cout << "Error: Not enough valid submissions!" << endl
             << endl;
        closedir(dir);
        return false;
    }

    cout << "Initialize ok..." << endl;
    cout << Valid_File_Name.size() << " Submissions " << endl;

    sort(Valid_File_Name.begin(), Valid_File_Name.end());
    for (auto Valid_File_Name_Iterator = Valid_File_Name.begin(); Valid_File_Name_Iterator != Valid_File_Name.end(); Valid_File_Name_Iterator++)
    {
        try
        {
            TOKENIZER Source_File;
            if (!Source_File.TOKENIZE_FILE(Language, FolderPath, *Valid_File_Name_Iterator)) // TEMPERORY VARIABLE TO PUSH IN THE VECTOR
                throw *Valid_File_Name_Iterator;
            // Source_File.getMap();
            Folder_Files.push_back(Source_File); // PUSH ALL DATA IN VECTOR
        }
        catch (...)
        {
            cerr << "Error: Could not parse file " << *Valid_File_Name_Iterator << endl;
        }
    }

    closedir(dir); // CLOSE DIRECTORY
    cout << "Tokenization Done!!" << endl;

    /*offstream can be done here*/
    return true;
}

bool isEmpty_Dir_File(string FolderPath, string Source_File_Name)
{
    ifstream file;
    file.open(FolderPath + "/" + Source_File_Name);
    string line;
    int flag = 0;
    int count = 0;
    while (file >> line)
    {
        flag = 1;
        break;
    }
    if (flag == 0)
        return true;
    else
        return false;
}

bool operator<(const MATCH &match1, const MATCH &match2)
{
    return match1.getToken_Matched_Length() < match2.getToken_Matched_Length();
}

bool compare_Matches_percentage(MATCHER match_1, MATCHER match_2)
{
    float match_1_percent = match_1.getMatch_Percent_1();

    if (match_1_percent < match_1.getMatch_Percent_2())
        match_1_percent = match_1.getMatch_Percent_2();

    float match_2_percent = match_2.getMatch_Percent_1();

    if (match_2_percent < match_2.getMatch_Percent_2())
        match_2_percent = match_2.getMatch_Percent_2();

    if (match_1_percent > match_2_percent)
        return true;
    else
        return false;
}

bool compare_Matches_percentage1(MATCHER match_1, MATCHER match_2)
{
    float match_1_percent = (float)(match_1.getMatch_Percent_1() + match_1.getMatch_Percent_2()) / 2;

    float match_2_percent = (float)(match_2.getMatch_Percent_1() + match_2.getMatch_Percent_2()) / 2;

    if (match_1_percent < match_2_percent)
        return true;
    else
        return false;
}

bool compare_Matches_percentage2(MATCHER match_1, MATCHER match_2)
{
    float match_1_percent = match_1.getMatch_Percent_1();

    if (match_1_percent < match_1.getMatch_Percent_2())
        match_1_percent = match_1.getMatch_Percent_2();

    float match_2_percent = match_2.getMatch_Percent_1();

    if (match_2_percent < match_2.getMatch_Percent_2())
        match_2_percent = match_2.getMatch_Percent_2();

    if (match_1_percent < match_2_percent)
        return true;
    else
        return false;
}

bool compare_Matches_percentage3(MATCHER match_1, MATCHER match_2)
{
    float match_1_percent = match_1.getMatch_Percent_1();

    if (match_1_percent > match_1.getMatch_Percent_2())
        match_1_percent = match_1.getMatch_Percent_2();

    float match_2_percent = match_2.getMatch_Percent_1();

    if (match_2_percent > match_2.getMatch_Percent_2())
        match_2_percent = match_2.getMatch_Percent_2();

    if (match_1_percent < match_2_percent)
        return true;
    else
        return false;
}
