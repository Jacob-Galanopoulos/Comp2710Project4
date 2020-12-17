//Jacob Galanopoulos
//JDG0058
//hw4_jdg0058.cpp
//The program combines two files information into one file.
//I received help from Karl Sprayberry with properly writing to a file.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;

const int MAX_SIZE = 100;
const int OUT_MAX_SIZE = 200;

int readfile(int inputArray[], ifstream& inStream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);

int main() {
	ifstream inStream;
	int iArray1[MAX_SIZE];
	int iArray1_size;
	int iArray2[MAX_SIZE];
	int iArray2_size;
	int oArray[OUT_MAX_SIZE];
	int oArray_size;
	string filename1;
	string filename2;

	cout << "*** Welcome to Jake Galanopoulos’s sorting program ***" << endl;
	cout << "Enter the first input file name:";
	cin >> filename1;
	inStream.open((char*)filename1.c_str());
	if (inStream.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}
	iArray1_size = readfile(iArray1, inStream);
	cout << "The list of " << iArray1_size << " numbers in " << filename1 << " is:" << endl;
	for (int x = 0; x < iArray1_size; x++) {
		cout << iArray1[x] << endl;
	}
	inStream.close();

	cout << "\nEnter the second input file name:";
	cin >> filename2;
	inStream.open((char*)filename2.c_str());
	if (inStream.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}
	iArray2_size = readfile(iArray2, inStream);
	cout << "The list of " << iArray2_size << " numbers in " << filename2 << " is:" << endl;
	for (int y = 0; y < iArray2_size; y++) {
		cout << iArray2[y] << endl;
	}
	inStream.close();

	oArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, oArray);
	cout << "\nThe sorted list of " << oArray_size << " numbers is: ";
	for (int z = 0; z < oArray_size; z++) {
		cout << oArray[z] << " ";
	}
	writefile(oArray, oArray_size);
}

int readfile(int inputArray[], ifstream& inStream) {
	int index = 0;
	inStream >> inputArray[index];
	while (!inStream.eof()) {
		index++;
		inStream >> inputArray[index];
	}
	index++;
	return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
	int temp = 0;
	for (int i = 0; i < inputArray1_size; i++) {
		outputArray[i] = inputArray1[i];
	}
	for (int j = 0; j < inputArray2_size; j++) {
		outputArray[j + inputArray1_size] = inputArray2[j];
	}
	for (int k = 0; k < (inputArray1_size + inputArray2_size); k++) {
		for (int l = k + 1; l < (inputArray1_size + inputArray2_size); l++) {
			if (outputArray[l] < outputArray[k]) {
				temp = outputArray[k];
				outputArray[k] = outputArray[l];
				outputArray[l] = temp;
			}
		}
	}
	return (inputArray1_size + inputArray2_size);
}

void writefile(int outputArray[], int outputArray_size) {
	ofstream outputFile;
	outputFile.open("output.txt");
	int index = 0;
	while (index < outputArray_size) {
		outputFile << outputArray[index] << endl;
		index++;
	}
	outputFile.close();
}