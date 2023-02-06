#pragma once
#include <iostream>
class NodeData
{
public:
	NodeData();
	void SetNode(int x, int y, std::string status, int trueCost, int estimateCost, NodeData* parent, int score);
	int x_;
	int y_;
	std::string status_;
	int trueCost_;
	int estimateCost_;
	int score_;
	NodeData* parent_;
};

