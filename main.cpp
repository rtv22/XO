#include <iostream>
#include <time.h>
#include <conio.h>


using namespace std;

class XO
{
private:
	char name[30];
	char name_[30];
	char table[3][3];
	bool step;
	int count;
public:
	XO();
	bool turn();
	bool win();
	bool game();
};

XO::XO() : count(0)
{
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		cout <<'|' << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << n + 1 << ' ';
			table[i][j] = char(49 + n);
			n++;	
		}
	}
	cout << '|' << endl;
}

bool XO::turn()
{
	for (int i = 0; i < 3; i++)
	{
		cout << '|' << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << "|" << table[i][j] << " ";
		}
	}
	cout << '|';
	if (step)
		cout << endl << "turn " << name << " : ";
	else cout << endl << "turn " << name_ << " : ";
	int n;
	cin >> n;
	if (n < 1 || n > 9)
		return false;
	int i, j;
	if (n % 3 == 0){                        //|1|2|3|
		i = n / 3 - 1;						//|4|5|6|
		j = 2;								//|7|8|9|
	}
	else{
		j = n % 3 - 1;
		i = n / 3;
	}
	if (table[i][j] == 'O' || table[i][j] == 'X')
		return false;

	if (step){
		table[i][j] = 'X';
		step = false;
		count++;
	}
	else{
		table[i][j] = 'O';
		step = true;
		count++;
	}
	return true;
}

bool XO::win(){
	for (int i = 0; i < 3; i++)
	{
		if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
			return true;													
		else
		if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
			return true;
		else
		if (((table[0][0] == table[1][1]) && (table[1][1] == table[2][2])) || ((table[0][2] == table[1][1]) && (table[1][1] == table[2][0])))
			return true;
		else
		if (count == 9)
			return false;
	}
	return false;
}

bool XO::game()
{
	cout << "Player 1:";
	cin.getline(name, 30);
	cout << "player 2:";
	cin.getline(name_, 30);
	
	srand(time(NULL));
	if (rand() & 1)
		step = true;
	else step = false;

	while (win() == false){
		system("cls");
		if (!turn())
		{
			cout << "error";
			_getch();
		}
		if ((count == 9) && (win() == false)){
			cout << "Draw" << endl;
			break;
		}
	}
	if (win() == true){
		if (step)
			cout << "Win " << name_ << endl;
		else
			cout << "Win " << name << endl;
	}
	return 0;
}

void main(){
	XO test;
	test.game();
}
