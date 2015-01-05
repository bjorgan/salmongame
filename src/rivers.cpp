
enum Direction{DIRECTION_UP, DIRECTION_LEFT, DIRECTION_RIGHT, DIRECTION_DOWN};
const int NUM_DIRECTIONS = 4;


struct River{
	int width;
	int direction;
	int x, y;
};



int main(){
	int map_x = 100;
	int map_y = 100;
	float *map = new float[map_x*map_y]();
	
	int initial_river_width = 50;


	vector<River> rivers;
	River river;
	rivers.push_back(river);
	rivers[0].width = initial_river_width;
	rivers[0].direction = DIRECTION_UP;
	rivers[0].x = map_x/2;
	rivers[0].y = map_y/2;
	int num_steps = 20;

	float branch_chance = 0.3; //branching chance
	float continue_direction_chance = 0.5; //chance of continuing in the same direction
	for (int i=0; i < num_steps; i++){
		for (int j=0; j < rivers.size(); j++){
			int offset = 0;

			//draw river along its width
			for (int k=0; k < rivers[j].width; k++){
				switch (rivers[j].direction){
					case DIRECTION_UP:
						offset = k;
					break;
					case DIRECTION_LEFT:
						offset = k*map_x;
					break;
					case DIRECTION_RIGHT:
						offset = -k*map_x;
					break;
					case DIRECTION_DOWN:
						offset = -k;
					break;
				}
				int ind = rivers[j].y*map_x + rivers[j].x + offset;
				if ((ind < map_x*map_y) && (ind >= 0)){
					map[ind] = 1;
				}
			}

			//choose new direction for river
			float randNum = rand()/RAND_MAX;
			if (randNum < continue_direction_chance){
				rivers[j].direction = rand() % NUM_DIRECTIONS;
			}

			//choose new x,y in the new direction
			switch(rivers[j].direction){
				case DIRECTION_UP:
					rivers[j].y++;
				break;
				case DIRECTION_LEFT:
					rivers[j].x--;
				break;
				case DIRECTION_RIGHT:
					rivers[j].x++;
				break;
				case DIRECTION_DOWN:
					rivers[j].y--;
				break;
			}
		}

		//branch rivers
		int num_rivers = rivers.size();
		vector<River> branched_rivers;
		for (int j=0; j < num_rivers; j++){
			float randNum = rand()/RAND_MAX;

			//branch river
			if (randNum < branch_chance){
				River river;
				branched_rivers.push_back(river);
				branched_rivers[branched_rivers.size()-1].x = rivers[j].x;
				branched_rivers[branched_rivers.size()-1].y = rivers[j].y;
				branched_rivers[branched_rivers.size()-1].direction = rand() % NUM_DIRECTIONS;
				branched_rivers[branched_rivers.size()-1].width = ceil(rivers[j].width/2);
				rivers[j].width = ceil(rivers[j].width/2);
			}
		}

		//add branched rivers to main rivers
		for (int j=0; j < branched_rivers.size(); j++){
			rivers.push_back(branched_rivers[j]);
		}
	}

	for (int i=0; i < map_x; i++){
		for (int j=0; j < map_y; j++){
			cout << map[j*map_x + i] << " ";
		}
		cout << endl;
	}


}
