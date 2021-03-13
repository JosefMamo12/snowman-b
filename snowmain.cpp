#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "snowman.hpp"

using namespace std;
using namespace ariel;

int main(int argc, char const *argv[])

{
    ofstream snowmanFile;
    snowmanFile.open("snowman.txt");
    int counter = 0;
    string snow;
    int num = 11111111;
    for (int b = 0; b < 4; b++)
    {
        for (int t = 0; t < 4; t++)
        {
            for (int ra = 0; ra < 4; ra++)
            {
                for (int la = 0; la < 4; la++)
                {
                    for (int re = 0; re < 4; re++)
                    {
                        for (int le = 0; le < 4; le++)
                        {
                            for (int n = 0; n < 4; n++)
                            {
                                for (int h = 0; h < 4; h++)
                                {
                                    snowmanFile << snowman(num + h) << endl; 
                                    snowmanFile << num + h << endl;
                                    counter++;
                                    cout << num + h << endl;
                                }
                                num += 10;
                            }
                            num += 60;
                        }
                        num += 600;
                    }
                    num += 6000;
                }
                num += 60000;
            }
            num += 600000;
        }
        num += 6000000;
    }
    cout << counter << endl;
    return 0;
}
