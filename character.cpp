#include "character.h"

void Character::move(Direction direction){
	if (!dead){
		switch direction{
			case MOVE_UP:
				y += step;
			break;
			case MOVE_DOWN:
				y -= step;
			break;
			case MOVE_LEFT:
				x -= step;
			break;
			case MOVE_RIGHT:
				x += step;
			break;
		}
	}
}
void Character::getCoordinates(int *x, int *y){
	*x = this->x;
	*y = this->y;
}
void Character::increaseHealth(int inc){
	health += inc;
	if (health > MAX_HEALTH){
		health = MAX_HEALTH;
	}
}
void Character::decreaseHealth(int dec){
	health -= dec;
	if (health <= MIN_HEALTH){
		health = MIN_HEALTH;
		this->die();
	}
}
void Character::die(){
	dead = true;
}


void Bear::move(Direction direction){
	Character::move(direction);
}
void Bear::smashAttack(){
}
void Bear::die(){
	Character::die();
}


void Laks::move(Direction direction){
	Character::move(direction);
}
void Laks::smashAttack(){
	
}
void Laks::die(){
	Character::die();
}
