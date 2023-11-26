#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "CubeSide.h"

using namespace std;

//	4
//0 1 2 3 scheme of sides lineup 
//	5
class RubiksCube
{
private:								
	CubeSide* cube;						
	void setDependencyToLeftSide();
	void setDependencyToFrontSide();
	void setDependencyToRightSide();
	void setDependencyToBackSide();
	void setDependencyToUpSide();
	void setDependencyToDownSide();
	void setDependency();		
	void setCube(const vector<char>&);
	bool chekColors() const;
	int random(const int&, const int&) const;
	void showFirstLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide&) const;
	void showSecondLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide&) const;
	void showThirdLayerForCubeCrossForSideWithoutRotationNeighbourSides(CubeSide&) const;
	void showCubeCrossForSideWithoutRotationNeighbourSides(CubeSide&) const;
	void setNeighboursForSideVisionUp(CubeSide*, int&);
	void setNeighboursForSideVisionDown(CubeSide*, int&);
	void setNeighboursForSideVisionLeft(CubeSide*, int&);
	void setNeighboursForSideVisionRight(CubeSide*, int&);
	void setNeighboursForSideVision(CubeSide*, int&, int&, int&, int&);
	void setNeighboursBack(CubeSide*, int&, int&, int&, int&);
	void rotateFaceWithoutSetNeighboursForSideVision(CubeSide*);
	void rotateFace(CubeSide*);
	void backRotateFaceWithoutSetNeighboursForSideVision(CubeSide*);
	void backRotateFace(CubeSide*);
	void showCubeCrossForSide(CubeSide*);
public:
	RubiksCube();
	RubiksCube(const string&);
	~RubiksCube();
	void setRandom();
	void setFromFile(const string&);
	CubeSide* getCube() const;
	void showCube() const;
	void showCubeCrossForSide(const int&);
	void rotateFace(const int&);		//in professional terminology rotation of the right side of the cube by clockwise called (R), but rotation by counterclockwise called (R')
	void backRotateFace(const int&);	//so for this reason (') replased by (back...)
	bool operator==(RubiksCube&);
};

