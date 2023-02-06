#include "Astar.h"

Astar::Astar(Wall* stage)
{
	pStage = stage;
	node = new NodeData * [MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
	{
		node[i] = new NodeData[MAP_SIZE];
	}
	InitAstar();
}

void Astar::InitAstar()
{
	openList.clear();
	route.clear();

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (pStage->IsWall(i, j))
			{
				node[i][j].SetNode(i, j, "Ban", 0, 0, nullptr, 0);
			}
			else
			{
				node[i][j].SetNode(i, j, "Nown", 0, 0, nullptr, 0);
			}

		}
	}
}

void Astar::InitSearch(int x, int y, int tx, int ty)
{
	InitAstar();
	Open(x, y, tx, ty, 0, nullptr);
	SearchRoute(x, y, tx, ty, 1);
	ReturnRoute(tx, ty);
}

void Astar::ReturnRoute(int tx, int ty)
{
	NodeData* pParent = node[tx][ty].parent_;
	route.push_back({ node[tx][ty].x_,node[tx][ty].y_ });
	while (pParent != nullptr)
	{
		int x = pParent->x_;
		int y = pParent->y_;
		route.push_back({ x,y });
		pParent = pParent->parent_;
	}
}

void Astar::SearchRoute(int x, int y, int tx, int ty, int trueCost)
{
	if (x == tx && y == ty)
	{
		return;
	}
	NodeData* pParent = &node[x][y];
	if (node[x - 1][y].status_ == "Nown")
	{
		Open(x - 1, y, tx, ty, trueCost, pParent);
		openList.push_back(&node[x - 1][y]);
	}
	if (node[x + 1][y].status_ == "Nown")
	{
		Open(x + 1, y, tx, ty, trueCost, pParent);
		openList.push_back(&node[x + 1][y]);
	}
	if (node[x][y - 1].status_ == "Nown")
	{
		Open(x, y - 1, tx, ty, trueCost, pParent);
		openList.push_back(&node[x][y - 1]);
	}
	if (node[x][y + 1].status_ == "Nown")
	{
		Open(x, y + 1, tx, ty, trueCost, pParent);
		openList.push_back(&node[x][y + 1]);
	}
	node[x][y].status_ = "Close";
	NodeData* next = NextNode();
	if (next->status_ == "Close")
	{
		return;
	}
	int tCost = trueCost + 1;
	SearchRoute(next->x_, next->y_, tx, ty, tCost);
}

void Astar::Open(int x, int y, int tx, int ty, int trueCost, NodeData* pParent)
{
	node[x][y].trueCost_ = trueCost;
	int dx = tx - x;
	int dy = ty - y;
	node[x][y].estimateCost_ = dx + dy;
	node[x][y].score_ = (dx + dy) + trueCost;
	node[x][y].status_ = "Open";
	node[x][y].parent_ = pParent;
}

NodeData* Astar::NextNode()
{
	auto itr = openList.begin();
	while (itr != openList.end())
	{
		if ((*itr)->status_ != "Open")
		{
			itr++;
		}
		else
		{
			break;
		}
	}
	NodeData* node = (*itr);
	while (itr != openList.end())
	{
		if ((*itr)->status_ == "Open")
		{
			if (node->score_ > (*itr)->score_)
			{
				node = (*itr);
			}
		}
		itr++;
	}
	return node;
}