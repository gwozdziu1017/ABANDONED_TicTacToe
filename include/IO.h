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
    static void print(const T& input);
    template <typename container>
    static void printContainer(const container& input);
    template <typename container>
    static void printContainer_pretty(const container& input);
    template <typename T>
    static T get();
};

/* Prints given argument to standard output */
template <typename T>
inline void IO::print(const T& input)
{
    std::cout << input;
}

/* Prints elements from given container without spaces*/
template <typename container>
inline void IO::printContainer(const container& input)
{
    for(auto elem : input)
        IO::print(elem);
}

/* Prints elements from given container with spaces between elements*/
template <typename container>
inline void IO::printContainer_pretty(const container& input)
{
    for(auto elem : input)
    {
        IO::print(elem);
        IO::print(" ");
    }
}

/* Returns from standard input */
template <typename T>
inline T IO::get()
{
    T temp;
    std::cin >> temp;
    return temp;
}
