#include <iostream>
#include <string>
#include "snowman.hpp"

using namespace std;

int reverseNum(int x)
{

    int ans = 0;
    int temp = 0;

    while (x > 0)
    {
        ans *= TEN;
        temp = returnMod10(x);
        ans += temp;
        x /= TEN;
    }
    return ans;
}

int returnMod10(int x)
{
    return x % TEN;
}

bool checkIfValidInput(int x)
{
    int counter = 0;
    while (x > 0)
    {
        if (returnMod10(x) > UNVALID_RANGE_UP && returnMod10(x) < UNVALID_RANGE_DOWN)
        {
            return false;
        }
        counter++;
        x = x / TEN;
    }
    return counter == VALID_LENGTH;
}
string hat(int digit)
{

    switch (digit)
    {
    case ONE:
        return STREW_HAT;
    case TWO:
        return MEXICAN_HAT;
    case THREE:
        return FEZ;
    case FOUR:
        return RUSSIAN_HAT;
    default:
        __throw_bad_exception();
    }
}
string nose(int digit)
{

    switch (digit)
    {
    case ONE:
        return NORMAL;
    case TWO:
        return DOTN;
    case THREE:
        return LINE;
    case FOUR:
        return NONE_N;
    default:
        __throw_bad_exception();
    }
}
string leftEye(int digit)
{
    switch (digit)
    {
    case ONE:
        return DOT;
    case TWO:
        return BIGGER_DOT;
    case THREE:
        return BIGGEST_DOT;
    case FOUR:
        return CLOSED_EYE;
    default:
        __throw_bad_exception();
    }
}
string rightEye(int digit)
{
    switch (digit)
    {
    case ONE:
        return DOT;
    case TWO:
        return BIGGER_DOT;
    case THREE:
        return BIGGEST_DOT;
    case FOUR:
        return CLOSED_EYE;
        break;
    default:
        __throw_bad_exception();
    }
}
string leftArm(int digit)
{
    switch (digit)
    {
    case ONE:
        return NORMAL_ARM;
    case TWO:
        return UPWARDS_ARM;
    case THREE:
        return DOWNARDS_ARM;
    case FOUR:
        return NONE_L;
    default:
        __throw_bad_exception();
    }
}

string rightArm(int digit)
{
    switch (digit)
    {
    case ONE:
        return NORMAL_ARMR;
    case TWO:
        return UPWARDS_ARMR;
    case THREE:
        return DOWNARDS_ARMR;
    case FOUR:
        return NONE_R;
    default:
        __throw_bad_exception();
    }
}
string torso(int digit)
{

    switch (digit)
    {
    case ONE:
        return BUTTONS_T;
    case TWO:
        return VEST;
    case THREE:
        return INWARDS_ARMS;
    case FOUR:
        return NONE_T;
    default:
        __throw_bad_exception();
    }
}

string base(int digit)
{

    switch (digit)
    {
    case ONE:
        return BUTTONS_B;
    case TWO:
        return FEET;
    case THREE:
        return FLAT;
    case FOUR:
        return NONE_B;
    default:
        __throw_bad_exception();
    }
}
void hard_part(string *buildSnowman, const string *n, const string *le, const string *re, const string *la, const string *ra, const string *t)
{
    string face = " ";
    string torso = " ";
    if (*la == UPWARDS_ARM)
    {
        face = *la + STARTING_BRACKKATES + *le + *n + *re + CLOSING_BRACKKATES;
        if (*ra == UPWARDS_ARMR)
        {
            face += *ra;
            torso = " " + STARTING_BRACKKATES + *t + CLOSING_BRACKKATES;
        }
        else
        {
            torso = " " + STARTING_BRACKKATES + *t + CLOSING_BRACKKATES + *ra;
        }
    }
    else
    {
        face = " " + STARTING_BRACKKATES + *le + *n + *re + CLOSING_BRACKKATES;
        torso = *la + STARTING_BRACKKATES + *t + CLOSING_BRACKKATES;
        if (*ra == UPWARDS_ARMR)
        {
            face += *ra;
        }
        else
        {
            torso += *ra;
        }
    }
    *buildSnowman += face + "\n" + torso + "\n";
}

namespace ariel
{
    string snowman(int x)
    {
        bool flag = checkIfValidInput(x) && checkIfValidInput(reverseNum(x));
        int temp = 0;
        int counter = 0;
        int digit = 0;
        string h = " ";
        string n = " ";
        string le = " ";
        string re = " ";
        string la = " ";
        string ra = " ";
        string t = " ";
        string b = " ";

        if (flag)
        {
            temp = reverseNum(x);
            string buildSnowman;

            while (temp > 0)
            {
                counter++;
                digit = returnMod10(temp);
                switch (counter)
                {
                case ONE:
                    h = hat(digit);
                    buildSnowman += h;
                    break;
                case TWO:
                    n = nose(digit);
                    break;
                case THREE:
                    le = leftEye(digit);
                    break;
                case FOUR:
                    re = rightEye(digit);
                    break;
                case FIVE:
                    la = leftArm(digit);
                    break;
                case SIX:
                    ra = rightArm(digit);
                    break;
                case SEVEN:
                    t = torso(digit);
                    hard_part(&buildSnowman, &n, &le, &re, &la, &ra, &t);
                    break;
                case EIGHT:
                    b = base(digit);
                    buildSnowman += " " + STARTING_BRACKKATES;
                    buildSnowman += b;
                    buildSnowman += CLOSING_BRACKKATES;
                    break;
                default:
                    __throw_bad_exception();
                }

                temp /= TEN;
            }
            return buildSnowman;
        }
        __throw_bad_exception();
    }
}
