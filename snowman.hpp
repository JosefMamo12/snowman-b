#ifndef SNOWMAN_HPP
#define SNOWMAN_HPP

#include <string>

using namespace std;

const int TEN = 10;
const int UNVALID_RANGE_UP = 4;
const int UNVALID_RANGE_DOWN = 1;
const int VALID_LENGTH = 8;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;

const string STREW_HAT = "     \n _===_\n";
const string MEXICAN_HAT = "  ___\n .....\n";
const string FEZ = "   _\n  /_\\ \n";
const string RUSSIAN_HAT = "  ___\n (_*_)\n";

const string CLOSED_EYE = "-";
const string DOT = ".";
const string BIGGER_DOT = "o";
const string BIGGEST_DOT = "O";

const string NORMAL = ",";
const string DOTN = ".";
const string LINE = "_";
const string NONE_N = " ";

const string NORMAL_ARM = "<";
const string UPWARDS_ARM = "\\";
const string DOWNARDS_ARM = "/";
const string NONE_L = " ";

const string NORMAL_ARMR = ">";
const string UPWARDS_ARMR = "/";
const string DOWNARDS_ARMR = "\\";
const string NONE_R = " ";

const string STARTING_BRACKKATES = "(";
const string CLOSING_BRACKKATES = ")";

const string BUTTONS_T = " : ";
const string VEST = "] [";
const string INWARDS_ARMS = "> <";
const string NONE_T = "   ";

const string BUTTONS_B = " : ";
const string FEET = "\" \"";
const string FLAT = "___";
const string NONE_B = "   ";

int returnMod10(int x);
bool checkIfValidInput(int x);
string leftArm(int digit);
string rightEye(int digit);
string leftEye(int digit);
string nose(int digit);
string hat(int digit);
string rightArm(int digit);
string torso(int digit);
string base(int digit);
void hard_part(string &buildSnowman, string &n, string &le, string &re, string &la, string &ra, string &t);

namespace ariel
{
    string snowman(int x);
}

#endif