#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

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
    void updateTable(std::unique_ptr<Table>& t, const unsigned short field, const string value);
    string translateSignForPlayableFields(const string sign);
private:
    map<int, string> playableFields;
    string emptyField; // "   "
    string horizontalSeparator; // "---|---|---"
    string verticalSeparator; // "|"
    string newLine;
};