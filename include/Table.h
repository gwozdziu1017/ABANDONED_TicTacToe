#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Table
{
//public:
    string getTable();

    void buildTable();
    bool updateTable(const unsigned short field, const string value);
private:
    vector<string> table;
    string emptyField; // "   "
    string horizontalSeparator; // "---|---|---"
    string verticalSeparator; // "|"
    string newLine;
};