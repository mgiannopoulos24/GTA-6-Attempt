#include <iostream>
#include <string>

// Synexiste to, theloume na kanei synexeia evolve.

class Weapon {
	enum Type{ Gun, Melee, Misc };
	Type _type;
	double _dmg;
	
	public:
		Weapon(Type type, double dmg);
		~Weapon();
};	

class Player {
	double health;
	string name;
	
	public:
		Player();
		~Player();
};

int main(int arg, char **argv) {
	std::cout << "Why did I come here? I guess it was the weather." << std::endl;
	return 0;
}
