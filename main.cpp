#include<iostream>
#include<conio.h> //Mvement
#include<Windows.h> //Color
#include<stdlib.h> //Clear screen
#include <ctime> //Rand
#include <chrono> //Time
#include <fstream> 
using namespace std;

const char* ch1 = "\033[31m#\033[0m";  // Red color
const char* ch2 = "\033[34m%\033[0m";  // Blue color
const char* ch3 = "\033[32m$\033[0m";  // Green color
const char* ch4 = "\033[35m@\033[0m";  // Purple color
const char* ch5 = "\033[33m&\033[0m";  // Yellow color
const char* ch6 = "\033[36m*\033[0m";  // Cyan color
const char* ch7 = "\033[37m!\033[0m";  // White color

//string array for 5 characters easy mode
char arre[5] = { '#', '@', '&', '%', '$' };

//string array for 7 character hard mode
char arrh[7] = { '#', '@', '&', '%', '$','*','!' };
void initializeArray(char arr2[10][10]);
void initializeArray1(char arr1[8][8]);
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_LEFT 75
#define KEY_RIGHT 77
const int row0 = 8, col0 = 8;
const int row1 = 10, col1 = 10;
char arr[5] = { '@', '#', '$', '%', '&' };
int score = 0;
int moves = 15;


char c_hard(char candy) { // creates random key in 2D-array easy mode
	int c;
	c = (rand() % 7) + 1;
	switch (c) {
	case 1:
		candy = '#';
		break;
	case 2:
		candy = '@';
		break;
	case 3:
		candy = '&';
		break;
	case 4:
		candy = '%';
		break;
	case 5:
		candy = '$';
		break;
	case 6:
		candy = '*';
		break;
	case 7:
		candy = '!';
		break;
	}
	return candy;
}

char  c_easy(char candy) {  // creates random key in 2D-array easy mode
	int c;
	c = rand() % 5 + 1;
	switch (c) {
	case 1:
		candy = '#';
		break;
	case 2:
		candy = '@';
		break;
	case 3:
		candy = '&';
		break;
	case 4:
		candy = '%';
		break;
	case 5:
		candy = '$';
		break;
		
	}
	return candy;
}



bool side_cand(int selectedRow, int selectedCol, int currentRow, int currentCol) {
	// Check if the candies are side_cands (up, down, left, or right)
	int rowDiff = abs(selectedRow - currentRow);
	int colDiff = abs(selectedCol - currentCol);
	return (rowDiff == 1 && colDiff == 0) || (rowDiff == 0 && colDiff == 1);
}

void swap_easy(char arr[8][8]) //swap spaces to top in easy mode
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == ' ')
			{
				int l = i, m = j;
				while (l > 0)
				{
					arr[l][m] = arr[l - 1][m];
					l--;
				}
			}
		}
	}
}

void Fill_array_easy(char arr[8][8]) // check if array element has space value and replace with random candyy it is executed after swap_easy function
{
	char candy = ' ';
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = c_easy(candy);
				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||//column wise horizontal
					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] || // row wise vertical
					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || //forward diagonal
					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])  //backward diagonal
				{
					char c = ' ';
					arr[x][y] = c_easy(candy);
				}
			}
		}
	}
}


void swap_hard(char arr[][10])//swap spaces to top in hard mode 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == ' ')
			{
				int l = i, m = j;
				while (l > 0)
				{
					arr[l][m] = arr[l - 1][m];
					l--;
				}
			}
		}
	}
}

void Fill_array_hard(char arr[10][10]) // check if array element has space value and replace with random candy it is executed after swap_hard function
{
	char candy = ' ';
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = c_hard(candy);
				if (arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2] ||//column wise horizontal
					arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y] || // row wise vertical
					arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y - 1] || //forward diagonal
					arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])  //backward diagonal
				{
					arr[x][y] = c_hard(candy);
				}
			}
		}
	}
}

void check_easy(char arr[][8], int i, int j) {
	int move = 15;
	while (move != 0)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = ' ';
					arr[i + 2][j] = ' ';
					arr[i][j + 1] = ' ';
					arr[i][j + 2] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(2);
					system("CLS");

				}
				else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] )// vertical condition check 
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = ' ';
					arr[i + 2][j] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(1);
					system("CLS");

				}
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
				{
					arr[i][j] = ' ';
					arr[i][j + 1] = ' ';
					arr[i][j + 2] = ' ';
					score += 5;

					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
				else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
				{
					arr[i][j] = ' ';
					arr[i - 1][j + 1] = ' ';
					arr[i + 1][j - 1] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
				else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])// backward diagonal condition
				{
					arr[i][j] = ' ';
					arr[i - 1][j - 1] = ' ';
					arr[i + 1][j + 1] = ' ';
					score += 5;

					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
			}
		}
		swap_easy;
		Fill_array_easy(arr);
		move--;
		if (move == 0)
		{
			break;
		}
	}
}

void check_hard(char arr[][10], int i, int j) {
	int move = 15;
	while (move != 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 2][j + 1] && arr[i][j] == arr[i + 2][j + 2])//L shape Condition spaces
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = ' ';
					arr[i + 2][j] = ' ';
					arr[i][j + 1] = ' ';
					arr[i][j + 2] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(2);
					system("CLS");

				}
				else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])// vertical condition check 
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = ' ';
					arr[i + 2][j] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(1);
					system("CLS");

				}
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])  // horizontal condition
				{
					arr[i][j] = ' ';
					arr[i][j + 1] = ' ';
					arr[i][j + 2] = ' ';
					score += 5;

					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
				else if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i + 1][j - 1]) // forward diaginal condition
				{
					arr[i][j] = ' ';
					arr[i - 1][j + 1] = ' ';
					arr[i + 1][j - 1] = ' ';
					score += 5;
					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
				else if (arr[i][j] == arr[i - 1][j - 1] && arr[i][j] == arr[i + 1][j + 1])// backward diagonal condition
				{
					arr[i][j] = ' ';
					arr[i - 1][j - 1] = ' ';
					arr[i + 1][j + 1] = ' ';
					score += 5;

					system("CLS");

					cout << "\n\n\n\t\t\t\t\t\t  \033[34mSweet\033[0m" << endl;
					Sleep(0);
					system("CLS");

				}
			}
		}
		swap_hard(arr);
		Fill_array_hard(arr);
		move--;
		if (move == 0)
		{
			break;
		}
	}
}

void initializeArray1(char arr1[8][8]) {
	// Seed for random number generation
	srand(time(0));

	// Loop through each cell in the 2D array
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			// Randomly select a character from arr
			char randomChar = arre[rand() % 5];

			// Check if the selected character doesn't exceed the limit
			while ((i > 1 && arr1[i - 1][j] == randomChar && arr1[i - 2][j] == randomChar) ||
				(j > 1 && arr1[i][j - 1] == randomChar && arr1[i][j - 2] == randomChar)) {
				randomChar = arr[rand() % 5];
			}

			// Assign the selected character to the current cell
			arr1[i][j] = randomChar;
		}
	}
}

void initializeArray(char arr2[10][10]) {
	// Seed for random number generation
	srand(time(0));

	// Loop through each cell in the 2D array
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			// Randomly select a character from arr
			char randomChar = arrh[rand() % 7];

			// Check if the selected character doesn't exceed the limit
			while ((i > 1 && arr2[i - 1][j] == randomChar && arr2[i - 2][j] == randomChar) ||
				(j > 1 && arr2[i][j - 1] == randomChar && arr2[i][j - 2] == randomChar)) {
				randomChar = arr[rand() % 5];
			}
			// Assign the selected character to the current cell
			arr2[i][j] = randomChar;
		}
	}
}

void displayArray0(const char array[][col0], int selectedRow, int selectedCol) {
	system("cls");
	cout << "\n\n\n\n\n" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "\t\t\t\t ";
		for (int y = 0; y < 8; y++)
		{
			if (i == selectedRow && y == selectedCol) {
				cout << " [ " << array[i][y] << " ] ";
			}
			else
			{
				switch (array[i][y]) {
				case '#':
					cout << " | " << ch1 << " | ";
					break;
				case '@':
					cout << " | " << ch2 << " | ";
					break;
				case '&':
					cout << " | " << ch3 << " | ";
					break;
				case '%':
					cout << " | " << ch4 << " | ";
					break;
				case '$':
					cout << " | " << ch5 << " | ";
					break;
				case'*':
					cout << " | " << ch6 << " | ";
					break;
				case'!':
					cout << " | " << ch7 << " | ";
					break;
				}
			}
		}
		cout << " \n" << endl;
	}
	cout << " \n\n\n\n\n\n\n\n\n\n\n\nSCORE : " << score << "\t\t\t\t\t\MOVES :"<<moves;
}

void displayArray1(const char array[][col1], int selectedRow, int selectedCol) {
	system("cls");
	cout << "\n\n\n\n\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t\t ";
		for (int y = 0; y < 10; y++)
		{
			if (i == selectedRow && y == selectedCol) {
				cout << " [ " << array[i][y] << " ] ";
			}
			else
			{
				switch (array[i][y]) {
				case '#':
					cout << " | " << ch1 << " | ";
					break;
				case '@':
					cout << " | " << ch2 << " | ";
					break;
				case '&':
					cout << " | " << ch3 << " | ";
					break;
				case '%':
					cout << " | " << ch4 << " | ";
					break;
				case '$':
					cout << " | " << ch5 << " | ";
					break;
				case'*':
					cout << " | " << ch6 << " | ";
					break;
				case'!':
					cout << " | " << ch7 << " | ";
					break;
				}
			}
		}
		cout << "\n" << endl;
	}
	cout << "\033[33m\n\n\n\n\n\n\n\n\n\n\n\nn\SCORE : \033[0m" << score << "\033[33m\t\t\t\t\t\MOVES :\033[0m"<<moves;
}

//Display credits of Game
void credits() {
	cout <<"\n\n\n\n\n\n\n" << endl;
	cout << "\033[31m\t\t\t\t\t\t\t\t\t\t ======\033[0m\n";
	cout << "\033[33m\t\t\t\t\t\t\t\t\t\t Credit\033[0m\n";
	cout << "\033[31m\t\t\t\t\t\t\t\t\t\t ======\033[0m\n";
	cout << "\n " << endl;
	cout << "\033[1m";
	cout << "\033[34m\t\t\t\t\t\t\t\t The Creators of This Game Goes To :\n\n"
		<< "\t\t\t\t\t\t\t   JAWAD JAMEEL and MOHAMMAD RAYYAN ASIM Students Of BS\n\n"
		<< "\t\t\t\t\t\t  Students Of BS Computer Science in FAST Nuces CFD Campus of Batch 23.\n\n";
}

void displayTimer(int remainingTime) {
	cout << "\033[33m\n\n\t\t\t\t\t\t\t\t\t\t|| TIME LEFT: " << remainingTime << "s ||\033[0m";
}
int main(){

	cout << "\033[34m\n\n\n\t\t\t\t\t\t\t\t\t=======================\033[0m\n";
	cout << "\033[31m\n\t\t\t\t\t\t\t\t\tWELCOME TO CANDY CRUSH\033[0m\n";
	cout << "\033[34m\n\t\t\t\t\t\t\t\t\t=======================\033[0m\n";
	cout << "\033[33m\n\n\n\n\t\t\t\t\t\t\t\tMade by :\033[0m\n\t\t\t\t\t\t\t\033[35m\t\t\tJawad Jameel \n\t\t\t\t\t\t\t\t\t\t\t\t Rayyan Asim \033[0m" << endl;
	cout << "\033[32m\n\n\t\t\t\t\t\t\t\t\t\t|| START || \033[0m";
	while (_getch() != 13) {}

	system("cls");

	char arr1[8][8];
	char arr2[10][10];
	int mode = 0, play_game = 0;

	cout <<"\n\n\n" << endl;
	cout << "\033[31m\t\t\t\t\t\t\t\t\t 1. Play Game\n";
	cout << "\t\t\t\t\t\t\t\t\t 2. Credits\n";
	cout << "\t\t\t\t\t\t\t\t\t 3. Instructions\n";
	cout << "\t\t\t\t\t\t\t\t\t 4. Score section\n";
	cout << "\t\t\t\t\t\t\t\t\t 5. Exit\033[0m\n";

	cin >> play_game;
	if (play_game == 1) 
	{
		system("cls");

		string name;
		ifstream file;
		
		file.open("score.txt");

		cout << "ENTER YOUR NAME: ";
		cin >> name;
		file >> name;

		cout << endl;
		cout << "\033[1m";   //to bold output on console
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t ==============\n";
		cout << "\033[31m\t\t\t\t\t\t\t\t\t 1. Easy Mode\033[0m\n";
		cout << "\033[31m\t\t\t\t\t\t\t\t\t 2. Hard Mode\033[0m\n";
		cout << "\t\t\t\t\t\t\t\t\t ==============\n";
		cin >> mode;
		if (mode == 1)
		{
		    // Initialize the 2D array
			initializeArray1(arr1);

			int currentRow = 0;
			int currentCol = 0;

			int selectedRow = 0;
			int selectedCol = 0;
			bool candySelected = false;
			char key;
			int time_limit = 60; // Set time limit for easy mode
			chrono::seconds duration(time_limit); // TIME LIMIT
			auto startTime = chrono::high_resolution_clock::now();
			do {
				displayArray0(arr1, currentRow, currentCol);

				key = _getch();
				switch (key) {
				
				case KEY_UP:
					if (currentRow > 0) {
						--currentRow;
					}
					break;
				case KEY_DOWN:
					if (currentRow < row0 - 1) {
						++currentRow;
					}
					break;
				case KEY_LEFT:
					if (currentCol > 0) {
						--currentCol;
					}
					break;
				case KEY_RIGHT:
					if (currentCol < col0 - 1) {
						++currentCol;
					}
					break;
				case KEY_ENTER: // Select or swap candy
					if (!candySelected) {
						// First press of ENTER - select candy
						selectedRow = currentRow;
						selectedCol = currentCol;
						candySelected = true;
					}
					break;
				case 's': // Swap candy when 's' key is pressed
					if (candySelected && side_cand(selectedRow, selectedCol, currentRow, currentCol)) {
						// Swap only if the selected candy and the current candy are side_cands
						swap(arr1[selectedRow][selectedCol], arr1[currentRow][currentCol]);
						check_easy(arr1, currentRow, currentCol);
						moves--;

					}
					candySelected = false;
					break;
				}
				auto currentTime = chrono::high_resolution_clock::now();
				auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);

				// Check if the time limit is reached
				if (elapsedTime >= duration) {
					system("cls");
					cout << "\033[31m\t\t\t\t\t\t\t\tTimes Up!!\033[0m" << endl;
					cout << "\033[31m\t\t\t\t\t\t\t\tYour score: \033[0m" << score << endl;
					cout << "\033[31m\t\t\t\t\t\t\t\tPlayer Name\033[0m" << name << endl;
					Sleep(5000);
					system("cls");
					cout << "Program is exiting." << endl;
					exit(5);
				}
				displayTimer(chrono::duration_cast<chrono::seconds>(duration - elapsedTime).count());
			} while (key != 'x' && (moves>=0));
			cout << "\033[33m\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t You Exit Game!!\033[0m" << endl;
		}
		else if (mode == 2)
		{
			// Initialize the 2D array
			initializeArray(arr2);

			int currentRow = 0;
			int currentCol = 0;
			int selectedRow = 0;
			int selectedCol = 0;
			bool candySelected = false;
			char key;
			int time_limit = 40; // Set time limit for hard mode
			chrono::seconds duration(time_limit); // TIME LIMIT
			auto startTime = chrono::high_resolution_clock::now();

			do {
				displayArray1(arr2, currentRow, currentCol);

				key = _getch();
				switch (key) {
				case KEY_UP:
					if (currentRow > 0) {
						--currentRow;
					}
					break;
				case KEY_DOWN:
					if (currentRow < row1 - 1) {
						++currentRow;
					}
					break;
				case KEY_LEFT:
					if (currentCol > 0) {
						--currentCol;
					}
					break;
				case KEY_RIGHT:
					if (currentCol < col1 - 1) {
						++currentCol;
					}
			    	break;
				case KEY_ENTER: // Select or swap candy
					if (!candySelected) {
						// First press of ENTER - select candy
						selectedRow = currentRow;
						selectedCol = currentCol;
						candySelected = true;
					}
					break;
				case 's': // Swap candy when 's' key is pressed
					if (candySelected && side_cand(selectedRow, selectedCol, currentRow, currentCol)) {
						// Swap only if the selected candy and the current candy are side_cands
						swap(arr2[selectedRow][selectedCol], arr2[currentRow][currentCol]);

						check_hard(arr2, currentRow, currentCol);
						moves--;
					}
					candySelected = false;
					break;
				}
				auto currentTime = chrono::high_resolution_clock::now();
				auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);

				// Check if the time limit is reached
				if (elapsedTime >= duration) {
					system("cls");
					cout << "\033[31m\t\t\t\t\t\t\t\tTimes Up!!\033[0m" << endl;
					cout << "\033[31m\t\t\t\t\t\t\t\tYour score: \033[0m" << score << endl;
					cout << "\033[31m\t\t\t\t\t\t\t\tPlayer Name\033[0m" << name << endl;
					Sleep(5000);
					system("cls");
					cout << "Program is exiting." << endl;
					exit(5);
				}
				displayTimer(chrono::duration_cast<chrono::seconds>(duration - elapsedTime).count());
			} while (key != 'x' && moves>=0);
			cout << "\033[33m\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t You Exit Game!!\033[0m" << endl;
		}
		else
		{
			cout << " You entered wrong number ";
		}
	}

	// 2 will show credit of game
	else if (play_game == 2)
	{
		system("cls");
		credits();
	}
	// 3 will show instruction by file reading
	else if (play_game == 3) {
	   system("cls");
	   ifstream my_input_file;
	   my_input_file.open("help.txt");

	   if (!(my_input_file.is_open()))
	   {
		  cout << "File cannot be opened.";
		  return 0;
	   }
	   char ch;

	   while (!my_input_file.eof())
	   {
		   my_input_file.get(ch); // using get() function
		   if (!my_input_file.eof())
			   cout << ch;
	   }
	   cout << endl;
	   my_input_file.close();
	} 

	else if (play_game==4)
	{

	}

	// 5 will exit the game simply by using exit keyword
	else if (play_game == 5)
    {
	   system("cls");
	   exit;
	   cout << "\033[33m\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t You Exit Game!!\033[0m" << endl;
    }

	cout << "\033[0m ";   //to bold output on console 
	
	system("pause");
	return 0;
}
