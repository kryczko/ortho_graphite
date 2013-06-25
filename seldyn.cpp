
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

int layers, noa;
double a,b,c,d;
string infile;

cout << "How many layers would you like to hold constant: ";
cin >> layers;
cout << "Please enter the inputfile: ";
cin >> infile;
cout << "Please enter the number of atoms: ";
cin >> noa;

ifstream input;
ofstream output;

input.open(infile.c_str());
output.open("seldyn.dat");

double xyz[noa][3];
int counter = 0;


while (!input.eof())
{
        input >> xyz[counter][0] >> xyz[counter][1] >> xyz[counter][2];
        counter ++;
}



if (layers == 2)
{

cout << "What are the z-values for the fixed layers: ";
cin >> a >> b;

for (int i = 0; i < noa; i ++)
{
        if (xyz[i][2] == a || xyz[i][2] == b)
        {
                output << xyz[i][0] << "\t" << xyz[i][1] << "\t" << xyz[i][2] << "\tT" << "\tT" << "\tF" << endl;
        }
        else
        {
                output << xyz[i][0] << "\t" << xyz[i][1] << "\t" << xyz[i][2] << "\tT" << "\tT" << "\tT" << endl;
        }
}

}
if (layers == 4)
{

cout << "what are the z-values for the fixed layers: ";
cin >> a >> b >> c >> d;

for (int i = 0; i < noa; i ++)
{
        if (xyz[i][2] == a || xyz[i][2] == b || xyz[i][2] == c || xyz[i][2] == d)
        {
                output << xyz[i][0] << "\t" << xyz[i][1] << "\t" << xyz[i][2] << "\tT" << "\tT" << "\tF" << endl;
        }
        else
        {
                output << xyz[i][0] << "\t" << xyz[i][1] << "\t" << xyz[i][2] << "\tT" << "\tT" << "\tT" << endl;
        }
}

}

return 0;
}






