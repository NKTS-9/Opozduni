#pragma once
#include <string>

using namespace std;

class Printer
{
    public:
        Printer();
        Printer(string st, string ctp, string f, int aoc, int bl, int r, int g, int b);

        string get_State();
        void set_State(string val);

        string get_CTP();
        void set_CTP(string val);

        string get_Format();
        void set_Format(string val);

        int get_AOC();
        void set_AOC(int val);

        int get_BLACK();
        void set_BLACK(int val);

        int get_RED();
        void set_RED(int val);

        int get_GREEN();
        void set_GREEN(int val);

        int get_BLUE();
        void set_BLUE(int val);

    private:
        string state;
        string ctp;
        string format;
        int aoc;
        int black;
        int red;
        int green;
        int blue;
};
