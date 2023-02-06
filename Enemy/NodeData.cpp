#include "NodeData.h"

NodeData::NodeData()
	: x_(-1), y_(-1), status_("NULL"), trueCost_(-1), estimateCost_(-1), parent_(nullptr), score_(-1)
{
}

void NodeData::SetNode(int x, int y, std::string status, int trueCost, int estimateCost, NodeData* parent, int score)
{
	x_ = x; y_ = y; status_ = status; trueCost_ = trueCost; estimateCost_ = estimateCost; parent_ = parent; score_ = score;
}