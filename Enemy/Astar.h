#pragma once
#include <iostream>
#include "NodeData.h"
#include "../Wall.h"
#include <list>
#include <vector>

struct Coordinate
{
	int x;
	int y;
};
class Astar
{
	NodeData** node;
	Wall* pStage;
	std::list<NodeData*> openList;
	std::vector<Coordinate> route;
public:
	Astar(Wall* stage);
	void InitAstar();
	void InitSearch(int x, int y, int tx, int ty);
	void SearchRoute(int x, int y, int tx, int ty, int trueCost);
	void ReturnRoute(int tx, int ty);
	void Open(int x, int y, int tx, int ty, int trueCost, NodeData* pParent);
	NodeData* NextNode();
	std::vector<Coordinate> GetRoute() { return route; }
};