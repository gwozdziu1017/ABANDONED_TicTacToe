/*
*   Class responsible for handling input and output
*   DG 11.2022
*/
#pragma once
#include <iostream>

class IO
{
public:
    template <typename T>
    static void print(T input);
    template <typename T>
    static T get();
}
