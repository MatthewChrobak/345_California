#pragma once

enum MapEditingActions : int
{
	SelectNode,
	AddNode,
	MakeNodeBlack,
	MakeNodeRed,
	MakeNodeYellow,
	MakeNodeBlue,
	ChangeNodeName,
	MakeDirectedEdge,
	MoveNode,
	RotateAngle,
	FinishedEditingMap,
	MapEditingActions_Length
};