
void createJSON(string ResultPath, vector<TOKENIZER> Folder_Files, vector<MATCHER> ALL_MATCHES)
{

    using json = nlohmann::json;
    json ALL_MATCHES_Json;
    json FOLDER_FILE_Json;

    for (auto Folder_Files_Iterator = Folder_Files.begin(); Folder_Files_Iterator != Folder_Files.end(); Folder_Files_Iterator++)
    {
        json File =
            {
                {"name", Folder_Files_Iterator->getSource_File_Name()},
                {"code", Folder_Files_Iterator->getOriginal_Source_File_Code()}

            };
        FOLDER_FILE_Json.push_back(File);
    }
    for (unsigned int All_MATCHES_INDEX = 0; All_MATCHES_INDEX < ALL_MATCHES.size(); All_MATCHES_INDEX++)
    {
        json line_match_map_1 = ALL_MATCHES[All_MATCHES_INDEX].getline_file1();
        json line_match_map_2 = ALL_MATCHES[All_MATCHES_INDEX].getline_file2();
        json Match =
            {
                {"file_1",
                 {{"index", ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_1()},
                  {"line_match_map", line_match_map_1},
                  {"percent", ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_1()}}},
                {"file_2",
                 {{"index", ALL_MATCHES[All_MATCHES_INDEX].getFolder_Files_Index_2()},
                  {"line_match_map", line_match_map_2},
                  {"percent", ALL_MATCHES[All_MATCHES_INDEX].getMatch_Percent_2()}}}

            };

        ALL_MATCHES_Json.push_back(Match);
    }
    ofstream json_match_stream(ResultPath + "/" + "match_data.json");
    json_match_stream << ALL_MATCHES_Json.dump(2);
    json_match_stream.close();
    ofstream json_file_stream(ResultPath + "/" + "file_data.json");
    json_file_stream << FOLDER_FILE_Json.dump(2);
    json_file_stream.close();
    return;
}
