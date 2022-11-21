#include "../include/Table.h"

/* Sets map of playable fields.
Playable field is the field where player can put either X or O */
void Table::setPlayableFields()
{
    for(int i = 1; i < 10; i++)
    {
        playableFields.insert({i, "   "});
    }
}
/* Updates table at given field with given sign */
void Table::updateTable(Table& t, const unsigned short field, const string value)
{
    t.playableFields.insert_or_assign(field, value);
}

/*Translates sign given by user (X or O) to value ready for inserting into playableFields container.
    X -> " X "
    O -> " O "
*/
string Table::translateSignForPlayableFields(const string sign)
{
    if(sign == "X")
        return " X ";
    else
        return " O ";
}

/* Returns empty table as a vector<string> */
vector<string> Table::getEmptyTable()
{
    return {
        this->emptyField, // 1
        this->verticalSeparator,
        this->emptyField, // 2
        this->verticalSeparator,
        this->emptyField, // 3
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        this->emptyField, // 4
        this->verticalSeparator,
        this->emptyField, // 5
        this->verticalSeparator,
        this->emptyField, // 6
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        this->emptyField, // 7
        this->verticalSeparator,
        this->emptyField, // 8
        this->verticalSeparator,
        this->emptyField, // 9
        this->newLine
    };
}

/* Returns table with field numbers as a vector<string> */
vector<string> Table::getTableWithFieldNumbers()
{
    return {
        " 1 ",
        this->verticalSeparator,
        " 2 ",
        this->verticalSeparator,
        " 3 ",
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        " 4 ",
        this->verticalSeparator,
        " 5 ",
        this->verticalSeparator,
        " 6 ",
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        " 7 ",
        this->verticalSeparator,
        " 8 ",
        this->verticalSeparator,
        " 9 ",
        this->newLine
    };
}

/* Returns table as a vector<string> includinf playable fields with their values */
vector<string> Table::getTable()
{
        return {
        this->playableFields[1],
        this->verticalSeparator,
        this->playableFields[2],
        this->verticalSeparator,
        this->playableFields[3],
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        this->playableFields[4],
        this->verticalSeparator,
        this->playableFields[5],
        this->verticalSeparator,
        this->playableFields[6],
        this->newLine,
        this->horizontalSeparator,
        this->newLine,
        // ---
        this->playableFields[7],
        this->verticalSeparator,
        this->playableFields[8],
        this->verticalSeparator,
        this->playableFields[9],
        this->newLine
        };
}