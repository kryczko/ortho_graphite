#include <iostream>  // For input/output 
#include <fstream> // For streaming data to the output file
#include <string> // For strings
#include <cmath> // for sine and cosine

const double PI = 3.14159265359;

using namespace std;

int main()
{


int rows, columns, stacks; // define variables to be used
string outputfile;
//main menu

cout << "\nWelcome to the Graphite Lattice Generator. The coordinates generated will be placed in a file specified by you and can easily be plotted in vmd.\n\n";
cout << "How many rows of carbon atoms would you like: ";
cin >> rows;
cout << "How many columns of carbon atoms would you like: ";
cin >> columns;
cout << "How many stacks of carbon sheets would you like: ";
cin >> stacks;
cout << "What is the name of the output file (e.g. data.xyz): ";
cin >> outputfile;

ofstream out;
out.open(outputfile.c_str());

out << 8*rows*columns*stacks << "\n\n";

double bl = 1.42;

double x0 = 0.0, x1 = sin(PI/3)*bl;

double y0 = 0.0, y1 = cos(PI/3)*bl, y2 = bl, y3 = cos(PI/3)*bl + bl, y4 = 2*bl, y5 = cos(PI/3)*bl + 2*bl ;

double layer_distance = 3.35;

double  z0 = -2*layer_distance, z1 = -layer_distance;

double x0_values[columns], x1_values[columns];

double y0_values[rows], y1_values[rows], y2_values[rows], y3_values[rows], y4_values[rows], y5_values[rows];

double z0_values[stacks], z1_values[stacks];

for (int i = 0; i < stacks; i ++)
{
	z0 += 2*layer_distance;
	z1 += 2*layer_distance;
	z0_values[i] = z0;
	z1_values[i] = z1;

	x0 = 0.0, x1 = sin(PI/3)*bl;

	for (int j = 0; j < columns; j ++)
	{
		x0 += sin(PI/3)*bl*2;
		x1 += sin(PI/3)*bl*2;
		
		x0_values[j] = x0;
		x1_values[j] = x1;		

		y0 = 0.0, y1 = cos(PI/3)*bl, y2 = bl, y3 = cos(PI/3)*bl + bl, y4 = 2*bl, y5 = cos(PI/3)*bl + 2*bl;

		for (int k = 0; k < rows; k ++)
		{
			y0 += 3*bl;
			y1 += 3*bl;
			y2 += 3*bl;
			y3 += 3*bl;
			y4 += 3*bl;	
			y5 += 3*bl;
			
			y0_values[k] = y0;
			y1_values[k] = y1;
			y2_values[k] = y2;
			y3_values[k] = y3;
			y4_values[k] = y4;
			y5_values[k] = y5;

			out << "C\t" << x0_values[j] << "\t" << y0_values[k] << "\t" << z0_values[i] << endl;
			out << "C\t" << x0_values[j] << "\t" << y0_values[k] << "\t" << z1_values[i] << endl;
			out << "C\t" << x1_values[j] << "\t" << y1_values[k] << "\t" << z0_values[i] << endl;
			out << "C\t" << x1_values[j] << "\t" << y3_values[k] << "\t" << z0_values[i] << endl;
			out << "C\t" << x1_values[j] << "\t" << y3_values[k] << "\t" << z1_values[i] << endl;
			out << "C\t" << x0_values[j] << "\t" << y2_values[k] << "\t" << z1_values[i] << endl;
			out << "C\t" << x1_values[j] << "\t" << y5_values[k] << "\t" << z1_values[i] << endl;
			out << "C\t" << x0_values[j] << "\t" << y4_values[k] << "\t" << z0_values[i] << endl;
		}
	}
}

cout << "The pbc's are {" << columns*sin(3.14/3)*bl*2 << " " << rows*1.42 + rows*2.84 << " " << 6.70*stacks << "}" << endl;

out.close();
return 0;
}
