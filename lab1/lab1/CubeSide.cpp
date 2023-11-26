#include "CubeSide.h"

const int CubeSide::SIZE = 3;

CubeSide::CubeSide()
{
	side = new char* [SIZE];
	charBuff = new char[SIZE];
	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;
	for (int i = 0; i < SIZE; i++) {
		side[i] = new char[SIZE];
		for (int j = 0; j < SIZE; side[i][j++] = '0');
	}
}

CubeSide::~CubeSide()
{
	for (int i = 0; i < SIZE; delete[] side[i++]);
	delete[] side;
	delete[] charBuff;
}

void CubeSide::setSide(const vector<char>& vec)
{
	int vecCounter = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; side[i][j++] = vec[vecCounter++]);
}

void CubeSide::showLine(const int& n) const
{
	for (int i = 0; i < SIZE; cout << side[n][i++] << " ");
	cout << "\t";
}

void CubeSide::showSide() const
{
	for (int i = 0; i < SIZE; i++) {
		showLine(i);
		cout << endl;
	}
	cout << "\n";
}

char* CubeSide::getLine(const int& n) const
{
	for (int i = 0; i < SIZE; i++)
		charBuff[i] = side[n][i];
	return charBuff;
}

char* CubeSide::getColumn(const int& n) const
{
	for (int i = 0; i < SIZE; i++)
		charBuff[i] = side[i][n];
	return charBuff;
}

void CubeSide::setLine(const int& n, const char* l)
{
	for (int i = 0; i < SIZE; side[n][i] = l[i++]);
}

void CubeSide::setColumn(const int& n, const char* c)
{
	for (int i = 0; i < SIZE; side[i][n] = c[i++]);
}

char* CubeSide::getReverseChar(char* mas)
{
	for (int i = 0; i <= SIZE / 2; i++)
		swap(mas[i], mas[SIZE - 1 - i]);
	return mas;
}

void CubeSide::rotateSide()
{
	CubeSide* buff = new CubeSide;
	for (int i = 0; i < SIZE; i++)
		buff->setColumn((SIZE - 1 - i), getLine(i));
	for (int i = 0; i < SIZE; i++)
		setLine(i, buff->getLine(i));
	delete buff;
}

void CubeSide::backRotateSide()
{
	CubeSide* buff = new CubeSide;
	for (int i = 0; i < SIZE; i++)
		buff->setColumn(i, getReverseChar(getLine(i)));
	for (int i = 0; i < SIZE; i++)
		setLine(i, buff->getLine(i));
	delete buff;
}

void CubeSide::chekColors(int& red, int& blue, int& orange, int& green, int& yellow, int& white) const
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			switch (side[i][j])
			{
			case('r'):
				red++;
				break;
			case('b'):
				blue++;
				break;
			case('o'):
				orange++;
				break;
			case('g'):
				green++;
				break;
			case('y'):
				yellow++;
				break;
			case('w'):
				white++;
				break;
			};
}

char CubeSide::getChar(const int& i, const int& j) const
{
	return side[i][j];
}

bool CubeSide::operator==(CubeSide& other)
{
	bool buff = true;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			buff *= (side[i][j] == other.getChar(i,j));
	return buff;
}
