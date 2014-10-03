#include "characterMeta.h"

int main(){
	PlayerCharacter trey(4, "Trey Cook");
	Character bear("a big, mean bear");

	int damage = 0;

	cout << trey.getName() << " and " << bear.getName() << " have entered combat!" << endl << endl;
	bear.attack(45, trey);

	return 0;
}