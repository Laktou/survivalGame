#include <iostream>
#include <string>

using namespace std;

class Character{
public:
	Character(){
		Character::health = 50;
		Character::hunger = 0;
		Character::energy = 50;
	}

	Character(string name){
		Character::name = name;
		Character::health = 50;
		Character::hunger = 0;
		Character::energy = 50;
	}

	/* Here are the set and get methods for the members that
	require it.*/
	void setName(string name){			// sets character name
		Character::name = name;
	}

	string getName(){					// returns character name
		return Character::name;
	}

	void setHealth(int health){			// sets character health
		Character::health = health;
	}

	int getHealth(){					// returns character health
		return Character::health;
	}

	void setHunger(int hunger){			// sets character hunger
		Character::hunger = hunger;
	}

	int getHunger(){					// returns character hunger
		return Character::hunger;
	}

	void setEnergy(int energy){			// sets character energy
		Character::energy = energy;
	}
	
	int getEnergy(){					// returns character energy
		return Character::energy;
	}

	/* Here are the methods that increase and reduce character stats.*/

	void reduceHealth(int amount){
		setHealth(Character::health - amount);
		cout << Character::getName() << "'s health was reduced by " << amount << "!" << endl;
	}

	void increaseHealth(int amount){
		setHealth(Character::health + amount);
	}

	void reduceHunger(int amount){
		setHunger(Character::hunger - amount);
	}

	void increaseHunger(int amount){
		setHunger(Character::hunger + amount);
	}

	void reduceEnergy(int amount){
		setEnergy(Character::energy - amount);
	}

	void increaseEnergy(int amount){
		setEnergy(Character::energy + amount);
	}

	/* Here are methods used to simulate combat.*/

	void attack(int damage, Character enemy){
		cout << Character::getName() << " attacked " << enemy.getName() << "!" << endl;
		enemy.reduceHealth(damage);
	}

private:
	string name = "Defaulty McGee";		// character's name
	string equipment[11];				// array of equipped items (head, neck, shoulders, wrists, hands(armor), hands(weapons), chest, waist, legs, feet)
	int health;							// character's max health
	int hunger;							// character's hunger level
	int energy;						    // character's maximum energy
};

class PlayerCharacter : public Character{
public:
	PlayerCharacter(int carryingCap, string name){					// basic player character initialization
		PlayerCharacter::setName(name);								// set character name
		PlayerCharacter::carryingCapacity = carryingCap;			// set carrying capacity
		PlayerCharacter::inventory = new string[carryingCap];		// initialize inventory with capacity
		PlayerCharacter::setHealth(50);
		PlayerCharacter::setHunger(0);
		PlayerCharacter::setEnergy(50);
	}

	~PlayerCharacter(){
		delete [] PlayerCharacter::inventory;	// reallocate dynamic memory array when deconstructing
	}
private:
	int carryingCapacity;				// how many items a character can have in inventory
	string *inventory;					// array of items in inventory
};