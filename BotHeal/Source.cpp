#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int WarriorHP;
	cout << "Warrior HP ";
	cin >> WarriorHP;
	if (WarriorHP < 30)
	{
		printf("!Heal!\n");
	}
}