#pragma once
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Table
{
public:
    Table() : emptyField("   "), horizontalSeparator("---|---|---"), verticalSeparator("|"), newLine("\n") { setPlayableFields(); };
    void setPlayableFields();
    vector<string> getTable();
    vector<string> getEmptyTable();
    vector<string> getTableWithFieldNumbers();
    void updateTable(Table& t, const unsigned short field, const string value);
private:
    map<int, string> playableFields;
    string emptyField; // "   "
    string horizontalSeparator; // "---|---|---"
    string verticalSeparator; // "|"
    string newLine;
};