#ifndef CHARACTER_H_DEFINED
#define CHARACTER_H_DEFINED



#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

class Character{
	public:
		Character(int x, int y);
		virtual void drawSprite(SDL_Surface *screen) = 0; //draw character sprite on screen

		int get_x(){return x;};
		int get_y(){return y;};
		void set_x(int x){this->x = x;};
		void set_y(int y){this->y = y;};
	private:
		int x, y;	
};

class Bear : public Character{
	public:
		Bear(int x, int y);
		virtual void drawSprite(SDL_Surface *screen);
	private:	
		int width;
		int height;
		
		int eye_width;
		int eye_height;
		int curr_eye_height;
		int eye_dist;

		int eye_y_diff;
		int eye_x_diff;
};

class Salmon : public Character{
	public:
		Salmon(int x, int y);
		virtual void drawSprite(SDL_Surface *screen);
	private:
		int width;
		int height;
};






/*		virtual void move(Direction direction); //move one step in specified direction
		virtual void smashAttack() = {}; //special attack
		void getCoordinates(int *x, int *y); //get current coordinates
		void increaseHealth(int inc); //increase healthbar
		void decreaseHealth(int dec); //decrease healthbar
		virtual void die(); //die
	private:
		int x, y; //current coordinates of character
		int health; //health bar
};
enum Direction{MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};

int MAX_HEALTH = 100;
int MIN_HEALTH = 0;


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
};*/


#endif
