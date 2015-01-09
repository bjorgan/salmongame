#include "character.h"
#include <sys/time.h>

Character::Character(int x, int y) : x(x), y(y){
}

Bear::Bear(int x, int y) : Character(x, y){
	width = 100;
	height = 200;
	
	//properties of the bear's eyes
	eye_width = 10;
	eye_height = 15;
	eye_dist = 10;

	eye_y_diff = -60;
	eye_x_diff = 0;
}

void Bear::drawSprite(SDL_Surface *screen){
	int eye_y = get_y() + eye_y_diff;
	int eye_x = get_x() + eye_x_diff;
	int x = get_x();
	int y = get_y();

	//body
	boxRGBA(screen, x - width/2, y - height/2, x + width/2, y + height/2, 255, 0, 0, 150);

	//left eye
	boxRGBA(screen, eye_x - eye_dist/2 - eye_width , eye_y, x - eye_dist/2, eye_y - eye_height, 255, 255, 0, 255);

	//right eye
	boxRGBA(screen, eye_x + eye_dist/2 , eye_y, x + eye_dist/2 + eye_width, eye_y - eye_height, 255, 255, 0, 255);
}

Salmon::Salmon(int x, int y) : Character(x, y){
	width = 200;
	height = 100;
}

void Salmon::drawSprite(SDL_Surface *screen){
	int eye_y = get_y() + eye_y_diff;
	int eye_x = get_x() + eye_x_diff;
	int x = get_x();
	int y = get_y();

	//body
	boxRGBA(screen, x - width/2, y - height/2, x + width/2, y + height/2, 200, 200, 200, 255);
}

//void Character::move(Direction direction){
//	if (!dead){
//		switch direction{
//			case MOVE_UP:
//				y += step;
//			break;
//			case MOVE_DOWN:
//				y -= step;
//			break;
//			case MOVE_LEFT:
//				x -= step;
//			break;
//			case MOVE_RIGHT:
//				x += step;
//			break;
//		}
//	}
//}
//void Character::getCoordinates(int *x, int *y){
//	*x = this->x;
//	*y = this->y;
//}
//void Character::increaseHealth(int inc){
//	health += inc;
//	if (health > MAX_HEALTH){
//		health = MAX_HEALTH;
//	}
//}
//void Character::decreaseHealth(int dec){
//	health -= dec;
//	if (health <= MIN_HEALTH){
//		health = MIN_HEALTH;
//		this->die();
//	}
//}
//void Character::die(){
//	dead = true;
//}
//
//
//void Bear::move(Direction direction){
//	Character::move(direction);
//}
//void Bear::smashAttack(){
//}
//void Bear::die(){
//	Character::die();
//}
//
//
//void Laks::move(Direction direction){
//	Character::move(direction);
//}
//void Laks::smashAttack(){
//	
//}
//void Laks::die(){
//	Character::die();
//}
