#include "RubiksCube.h"

void RubiksCube::setDependencyToLeftSide()
{
	cube[0].left = &cube[3];
	cube[0].right = &cube[1];
	cube[0].up = &cube[4];
	cube[0].down = &cube[5];
}

void RubiksCube::setDependencyToFrontSide()
{
	cube[1].left = &cube[0];
	cube[1].right = &cube[2];
	cube[1].up = &cube[4];
	cube[1].down = &cube[5];
}

void RubiksCube::setDependencyToRightSide()
{
	cube[2].left = &cube[1];
	cube[2].right = &cube[3];
	cube[2].up = &cube[4];
	cube[2].down = &cube[5];
}

void RubiksCube::setDependencyToBackSide()
{
	cube[3].left = &cube[2];
	cube[3].right = &cube[0];
	cube[3].up = &cube[4];
	cube[3].down = &cube[5];
}

void RubiksCube::setDependencyToUpSide()
{
	cube[4].left = &cube[0];
	cube[4].right = &cube[2];
	cube[4].up = &cube[3];
	cube[4].down = &cube[1];
}

void RubiksCube::setDependencyToDownSide()
{
	cube[5].left = &cube[0];
	cube[5].right = &cube[2];
	cube[5].up = &cube[1];
	cube[5].down = &cube[3];
}

void RubiksCube::setDependency()
{
	setDependencyToLeftSide();
	setDependencyToFrontSide();
	setDependencyToRightSide();
	setDependencyToBackSide();
	setDependencyToUpSide();
	setDependencyToDownSide();
}

void RubiksCube::setCube(const vector<char>& vec)
{
	for (int i = 0; i < 6; i++) {
		vector<char> buf(vec.begin() + i * 9, vec.begin() + (i + 1) * 9);
		cube[i].setSide(buf);
	}
}
bool RubiksCube::chekColors() const
{
	int red(0), blue(0), orange(0), green(0), yellow(0), white(0), norm(CubeSide::SIZE * CubeSide::SIZE);

	for (int i = 0; i < 6; cube[i++].chekColors(red, blue, orange, green, yellow, white));
	return ((abs(red - norm) + abs(blue - norm) + abs(orange - norm) + abs(green - norm) + abs(yellow - norm) + abs(white - norm)) == 0);
}

int RubiksCube::random(const int& min, const int& max) const
{
	return rand() % (max - min + 1) + min;
}

void RubiksCube::showFirstLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide& forWhichSideWasUsed) const
{
	CubeSide spaceFilledSide;
	spaceFilledSide.setSide(vector<char>((CubeSide::SIZE * CubeSide::SIZE), ' '));

	for (int i = 0; i < CubeSide::SIZE; i++)
	{
		spaceFilledSide.showLine(i);
		forWhichSideWasUsed.up->showLine(i);
		cout << endl;
	}
	cout << "\n\n";
}

void RubiksCube::showSecondLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide& forWhichSideWasUsed) const
{
	for (int i = 0; i < CubeSide::SIZE; i++)
	{
		forWhichSideWasUsed.left->showLine(i);
		forWhichSideWasUsed.showLine(i);
		forWhichSideWasUsed.right->showLine(i);
		cout << endl;
	}
	cout << "\n\n";
}

void RubiksCube::showThirdLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide& forWhichSideWasUsed) const
{
	CubeSide spaceFilledSide;
	spaceFilledSide.setSide(vector<char>((CubeSide::SIZE * CubeSide::SIZE), ' '));

	for (int i = 0; i < CubeSide::CubeSide::SIZE; i++)
	{
		spaceFilledSide.showLine(i);
		forWhichSideWasUsed.down->showLine(i);
		cout << endl;
	}
	cout << "\n\n\n";
}


void RubiksCube::showCubeCrossForSideWithoutRotationNeighbourSides(CubeSide& forWhichSideWasUsed) const
{
	showFirstLayerForCubeCrossForSideWithoutRotationNeighbourSides(forWhichSideWasUsed);
	showSecondLayerForCubeCrossForSideWithoutRotationNeighbourSides(forWhichSideWasUsed);
	showThirdLayerForCubeCrossForSideWithoutRotationNeighbourSides(forWhichSideWasUsed);	
}
void RubiksCube::setNeighboursForSideVisionUp(CubeSide* forWhichSideWasUsed, int& upRotated)
{
	if (forWhichSideWasUsed->up->up == forWhichSideWasUsed) {
		upRotated = 2;
		forWhichSideWasUsed->up->rotateSide();
		forWhichSideWasUsed->up->rotateSide();
	}else
		if (forWhichSideWasUsed->up->right == forWhichSideWasUsed) {
			upRotated = 1;
			forWhichSideWasUsed->up->rotateSide();
		}
		else
			if (forWhichSideWasUsed->up->left == forWhichSideWasUsed) {
				upRotated = 3;
				forWhichSideWasUsed->up->backRotateSide();
			}
}
void RubiksCube::setNeighboursForSideVisionRight(CubeSide* forWhichSideWasUsed, int& rightRotated)
{
	if (forWhichSideWasUsed->right->up == forWhichSideWasUsed) {
		rightRotated = 3;
		forWhichSideWasUsed->right->backRotateSide();
	}
	else
		if (forWhichSideWasUsed->right->right == forWhichSideWasUsed) {
			rightRotated = 2;
			forWhichSideWasUsed->right->rotateSide();
			forWhichSideWasUsed->right->rotateSide();
		}
		else
			if (forWhichSideWasUsed->right->down == forWhichSideWasUsed) {
				rightRotated = 1;
				forWhichSideWasUsed->right->rotateSide();
			}
}
void RubiksCube::setNeighboursForSideVisionDown(CubeSide* forWhichSideWasUsed, int& downRotated)
{
	if (forWhichSideWasUsed->down->right == forWhichSideWasUsed) {
		downRotated = 3;
		forWhichSideWasUsed->down->backRotateSide();
	}
	else
		if (forWhichSideWasUsed->down->down == forWhichSideWasUsed) {
			downRotated = 2;
			forWhichSideWasUsed->down->rotateSide();
			forWhichSideWasUsed->down->rotateSide();
		}
		else
			if (forWhichSideWasUsed->down->left == forWhichSideWasUsed) {
				downRotated = 1;
				forWhichSideWasUsed->down->rotateSide();
			}
}
void RubiksCube::setNeighboursForSideVisionLeft(CubeSide* forWhichSideWasUsed, int& leftRotated)
{
	if (forWhichSideWasUsed->left->up == forWhichSideWasUsed) {
		leftRotated = 1;
		forWhichSideWasUsed->left->rotateSide();
	}
	else
		if (forWhichSideWasUsed->left->down == forWhichSideWasUsed) {
			leftRotated = 3;
			forWhichSideWasUsed->left->backRotateSide();
		}
		else
			if (forWhichSideWasUsed->left->left == forWhichSideWasUsed) {
				leftRotated = 2;
				forWhichSideWasUsed->left->rotateSide();
				forWhichSideWasUsed->left->rotateSide();
			}
}

void RubiksCube::setNeighboursForSideVision(CubeSide* forWhichSideWasUsed, int& upRotated, int& rightRotated, 
	int& downRotated, int& leftRotated)
{
	setNeighboursForSideVisionUp(forWhichSideWasUsed, upRotated);
	setNeighboursForSideVisionDown(forWhichSideWasUsed, downRotated);
	setNeighboursForSideVisionLeft(forWhichSideWasUsed, leftRotated);
	setNeighboursForSideVisionRight(forWhichSideWasUsed, rightRotated);	
}

void RubiksCube::setNeighboursBack(CubeSide* forWhichSideWasUsed, int& upRotated, int& rightRotated, int& downRotated, int& leftRotated)
{
	while (upRotated-- != 0)
		forWhichSideWasUsed->up->backRotateSide();
	while (rightRotated-- != 0)
		forWhichSideWasUsed->right->backRotateSide();
	while (downRotated-- != 0)
		forWhichSideWasUsed->down->backRotateSide();
	while (leftRotated-- != 0)
		forWhichSideWasUsed->left->backRotateSide();
}

void RubiksCube::rotateFaceWithoutSetNeighboursForSideVision(CubeSide* side)
{
	side->rotateSide();
	char* buff;
	buff = side->up->getLine(CubeSide::SIZE - 1);
	side->up->setLine(CubeSide::SIZE - 1, CubeSide::getReverseChar(side->left->getColumn(CubeSide::SIZE - 1)));
	side->left->setColumn(CubeSide::SIZE - 1, side->down->getLine(0));
	side->down->setLine(0, CubeSide::getReverseChar(side->right->getColumn(0)));
	side->right->setColumn(0, buff);
}

void RubiksCube::rotateFace(CubeSide* side)
{
	int upRotated(0), rightRotated(0), downRotated(0), leftRotated(0);

	setNeighboursForSideVision(side, upRotated, rightRotated, downRotated, leftRotated);
	rotateFaceWithoutSetNeighboursForSideVision(side);
	setNeighboursBack(side, upRotated, rightRotated, downRotated, leftRotated);
}

void RubiksCube::backRotateFaceWithoutSetNeighboursForSideVision(CubeSide* side)
{
	side->backRotateSide();
	char* buff;
	buff = side->up->getLine(CubeSide::SIZE - 1);
	side->up->setLine(CubeSide::SIZE - 1, side->right->getColumn(0));
	side->right->setColumn(0, CubeSide::getReverseChar(side->down->getLine(0)));
	side->down->setLine(0, side->left->getColumn(CubeSide::SIZE - 1));
	side->left->setColumn(CubeSide::SIZE - 1, CubeSide::getReverseChar(buff));
}

void RubiksCube::backRotateFace(CubeSide* side)
{
	int upRotated(0), rightRotated(0), downRotated(0), leftRotated(0);

	setNeighboursForSideVision(side, upRotated, rightRotated, downRotated, leftRotated);
	backRotateFaceWithoutSetNeighboursForSideVision(side);
	setNeighboursBack(side, upRotated, rightRotated, downRotated, leftRotated);
}

RubiksCube::RubiksCube()
{
	cube = new CubeSide[6];
	setDependency();
	setRandom();
}

RubiksCube::RubiksCube(const string& filePath)
{
	cube = new CubeSide[6];
	setDependency();
	setFromFile(filePath);
}

RubiksCube::~RubiksCube()
{
	delete[] cube;
}

void RubiksCube::setRandom()
{
	vector<char> vec;
	char c[] = { 'r','b','o','g','y','w' };	//make vector with correct amount of colors
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < CubeSide::SIZE * CubeSide::SIZE; j++)
			vec.push_back(c[i]);

	srand(time(0));
	for (int i = 0; i < (vec.size() / 2); i++)	//randomize vector of colors
		swap(vec[random(0, vec.size() - 1)], vec[random(0, vec.size() - 1)]);

	setCube(vec);
}

void RubiksCube::setFromFile(const string& filePath)
{
	ifstream file(filePath);
	vector<char> vec;

	if (!file.is_open())
		throw exception("There is no such file path");
	
	char c;
	while (file >> c && vec.size() < 6 * CubeSide::SIZE * CubeSide::SIZE)
		vec.push_back(c);

	if (vec.size() < 6 * CubeSide::SIZE * CubeSide::SIZE)
		throw exception("There is not enough data in file");

	setCube(vec);

	if (!chekColors()) 
		throw exception("There is uncorrect number of colors");
}

CubeSide* RubiksCube::getCube() const
{
	return cube;
}

void RubiksCube::showCube() const
{
	for (int i = 0; i < 6; cube[i++].showSide());
}

void RubiksCube::showCubeCrossForSide(CubeSide* forWhichSideWasUsed)
{
	int upRotated(0), rightRotated(0), downRotated(0), leftRotated(0);

	setNeighboursForSideVision(forWhichSideWasUsed, upRotated, rightRotated, downRotated, leftRotated);

	showCubeCrossForSideWithoutRotationNeighbourSides(*forWhichSideWasUsed);

	setNeighboursBack(forWhichSideWasUsed, upRotated, rightRotated, downRotated, leftRotated);
}

void RubiksCube::showCubeCrossForSide(const int& n)
{
	showCubeCrossForSide(&cube[n]);
}

void RubiksCube::rotateFace(const int& n)
{
	rotateFace(&cube[n]);
}

void RubiksCube::backRotateFace(const int& n)
{
	backRotateFace(&cube[n]);
}

bool RubiksCube::operator==(RubiksCube& other)
{
	bool buff = true;
	for (int i = 0; i < 6; i++)
		buff *= (cube[i] == other.getCube()[i]);
	return buff;
}
