enum Direction{MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};

int MAX_HEALTH = 100;
int MIN_HEALTH = 0;

class Character{
	public:
		virtual void move(Direction direction); //move one step in specified direction
		virtual void smashAttack() = {}; //special attack
		void getCoordinates(int *x, int *y); //get current coordinates
		void increaseHealth(int inc); //increase healthbar
		void decreaseHealth(int dec); //decrease healthbar
		virtual void die(); //die
	private:
		int x, y; //current coordinates of character
		int health; //health bar
};


class Bear : public Character{
	public:
		virtual void move(Direction direction);
		virtual void smashAttack();
		virtual void die();
};


class Laks : public Character{
	public:
		virtual void move(Direction direction);
		virtual void smashAttack();
		virtual void die();
};
