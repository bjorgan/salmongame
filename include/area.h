#include <vector>

class Area{
	public:
		Area(std::vector<int> riverXCorners, std::vector<int> riverYCorners);
		bool isInsideRiver(int x, int y); //whether given coordinate is within defined river
	private:
		//corners of path defining river
		std::vector<int> riverXCorners;
		std::vector<int> riverYCorners;
};
