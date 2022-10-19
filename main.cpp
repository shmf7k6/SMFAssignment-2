//Sadam Farah
//CS303
//Assignment 2
//10-18-2022
//Update code of Assignment 1 

#include "functions.h"
#include<iostream>
#include<fstream>

using namespace std;

//this will read contents from the file data.txt and store them in a 2D array and return
int** read_numbers()
{
	int** numbers = new int*[10];
	for (int i = 0; i < 10; i++)
		numbers[i] = new int[10];
	ifstream ifile("data.txt");
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			ifile >> numbers[i][j];
		}
	}

	return numbers;
}

//This function will search a number in the array and return its row and column
int* search_number(int** numbers)
{
	int number;
	cout << "Input number to search= ";
	cin >> number;

	int index1 = -1, index2 = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (numbers[i][j] == number)
			{
				index1 = i;
				index2 = j;

				static int indexes[]{ index1,index2 };
				return indexes;
			}
	}
	
	int ans[]{-1,-1};
	return  ans;
	
}

//this function will get a row index and an column index and will replace it with a new value
int* replace_number(int** numbers)
{
	int row, col;
	cout << "Input row index to change= ";
	cin >> row;
	cout << "Input column index to change= ";
	cin >> col;

	if ((row < 0 || row > 9) || (col < 0 || col > 9))
	{
		throw -1;
	}
	int new_number;
	cout << "Input the new number= ";
	cin >> new_number;

	int old_number = numbers[row][col];
	numbers[row][col] = new_number;

	static int nums[]{ old_number,new_number };
	return nums;
}

//A function that will add a new value to end of the array
int** add_number(int** numbers)
{
	int new_number;
	cout << "Input the new number to add= ";
	cin >> new_number;

	
	if (new_number > 1000)
		throw - 1;
	int* new_numbers = new int[11];
	for (int i = 0; i < 10; i++)
	{
		new_numbers[i] = numbers[9][i];
	}
	new_numbers[10] = new_number;

	numbers[9] = new_numbers;
	
	return numbers;
}

//A simple function that will delete the value at the indexes
int** delete_number(int** numbers, int row, int col)
{
	int* newData = new int[10];
	for (int i = 0, j = 0; i < 11; i++, j++)
	{
		if (i == col)
		{
			j--;
			continue;
		}
		newData[j] = numbers[row][i];
	}

	numbers[row] = newData;
	return numbers;
}

/*Main Function*/
int main()
{
	int len = 10;
	//Reading the content of file in data array
	int **numbers = read_numbers();
	//Printing the contents of initial array
	cout << "Array is=\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << numbers[i][j] << " ";

		cout << endl;
	}
	cout << endl;
	//Checking if the number user tried to find existed or not
	int* ind = search_number(numbers);
	if (ind[1] == -1 || ind[0] == -1)
		cout << "There is no number in array" << endl;
	else
		cout << "Number found at index= " << ind[0] << " " << ind[1] << endl;

	//Asking user for the index at which value wanted to be changed and printing old and new value
	int rind,cind;

	try
	{
		int* nums = replace_number(numbers);
		cout << "Old Value: " << nums[0] << "\t" << "New Value: " << nums[1] << endl;
	}
	catch (int x)
	{
		cout << "The index of row or column are out of bound" << endl;
	}

	try
	{
		numbers = add_number(numbers);
	}
	catch (int x)
	{
		cout << "The new number should be less than 1000\n";
		len--;
	}

	cout << "Input row index to delete= ";
	cin >> rind;
	cout << "Input row column to delete= ";
	cin >> cind;
	numbers = delete_number(numbers, rind, cind);

	
	

	//Printing content of final array 
	cout << "\nArray is=\n";
	for (int i = 0; i < 10; i++)
	{
		if(i == rind)
			for (int j = 0; j < 9; j++)
				cout << numbers[i][j] << " ";
		else
			for (int j = 0; j < 10; j++)
				cout << numbers[i][j] << " ";

		if (i == 9 && len == 10)
			cout << numbers[i][10];
		cout << endl;
	}
}
