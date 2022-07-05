#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <chrono>
#include <vector>
#include <memory>
#include <iostream>
#include <random>
#include <cstdlib>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;
using namespace std;





//node---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



shared_ptr<Node> Item::SelectPointer(String^ NodeName)
{
	//0~はchildの配列からの参照値、-1はgroupへの移行を表す
	vector<int>navigater(0);
	int nav_num = 0;
	bool Gchecker = false;
	shared_ptr<Node> SelectPointer = RootPointer;
	for (int i = 0; i < (NodeName->ToCharArray()->Length); i++) {
		char a = NodeName->ToCharArray()[i];
		switch (a) {
		case 'R':
			nav_num = -1;
			break;
		case 'B':
			break;
		case 'b':navigater[nav_num] = -1;
			nav_num += 1;
			navigater.push_back(0);
			break;
		case 'T':
			break;
		case 't':navigater[nav_num] = -1;
			nav_num += 1;
			navigater.push_back(0);
			break;
		case 'F':
			break;
		case '-':
			nav_num += 1;
			navigater.push_back(0);
			break;
		default:navigater[nav_num] = navigater[nav_num] * 10 + a-'0';//char'0'=int 48
			break;
		}
	}
	for (int s = 0; s < navigater.size(); s++) {
		switch (navigater[s]) {
		case -1:
			Gchecker = true;
			break;
		default:
			if (Gchecker == true) {
				SelectPointer = SelectPointer->Group->at(navigater[s]);
			}
			else {
				SelectPointer = SelectPointer->Child->at(navigater[s]);
			}
			Gchecker = false;
			break;
		}
	}
	return SelectPointer;
}

int Item::SelectNodeNum(String^ NodeName)
{
	//0~はchildの配列からの参照値、-1はgroupへの移行を表す
	vector<int>navigater(0);
	int nav_num = 0;
	for (int i = 0; i < (NodeName->ToCharArray()->Length); i++) {
		char a = NodeName->ToCharArray()[i];
		switch (a) {
		case 'R':
			nav_num = -1;
			break;
		case 'B':
			break;
		case 'b':navigater[nav_num] = -1;
			nav_num += 1;
			navigater.push_back(0);
			break;
		case 'T':
			break;
		case 't':navigater[nav_num] = -1;
			nav_num += 1;
			navigater.push_back(0);
			break;
		case 'F':
			break;
		case '-':
			nav_num += 1;
			navigater.push_back(0);
			break;
		default:navigater[nav_num] = navigater[nav_num] * 10 + a - '0';//char'0'=int 48
			break;
		}
	}
	return navigater[navigater.size()-1];
}

void Item::NodeChildSearcher(shared_ptr<struct Node> Seacher)
{
	for (int i = 0; i < Seacher->Child->size(); i++) {
		if (Seacher->Child->at(i) != nullptr) {
			NodeChildSearcher(Seacher->Child->at(i));
		}
	}
	for (int i = 0; i < Seacher->Group->size(); i++) {
		NodeChildSearcher(Seacher->Group->at(i));
	}
	Seacher->Parent = nullptr;
}

	void Item::NodeDelete(String^ NodeName)
{
		shared_ptr<Node> selectPointer=SelectPointer(NodeName);
		int selectNodeNum = SelectNodeNum(NodeName);
		selectPointer->Parent->Child->at(selectNodeNum) = nullptr;
		NodeChildSearcher(selectPointer);
}

void Item::NodeBCreate(String^ NodeName)
{
	shared_ptr<Node> selectPointer = SelectPointer(NodeName);
	shared_ptr<vector<int>>newNodeProperty(new vector<int>{ 1,-1,3,2,2,0,0,10000,0,0,
			0,0,0,0,0,10000,0,0,2,0,
			10000,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,10000,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,2,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,10000,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0 });
	shared_ptr<vector<shared_ptr<Node>>>newNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newNodeGroup(new vector<shared_ptr<Node>>());
PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
	shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{ -1,3,2,2,0,10000,0,0,0,10000,
			0,2,0,10000,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,10000,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,2,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,10000,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0 });
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newNode(new Node{1 ,0,false,false,nullptr,selectPointer,newNodeProperty,newNodeChild,newNodeGroup});
	shared_ptr<Node> newGroupNode(new Node{2 ,0,true,true,newGroupNodePath,newNode,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
	newNode->Group->push_back(newGroupNode);
	selectPointer->NodeNum += 1;
	selectPointer->Child->push_back(newNode);
}
void Item::NodeTCreate(String^ NodeName)
{
	shared_ptr<Node> selectPointer = SelectPointer(NodeName);
	shared_ptr<vector<int>>newNodeProperty(new vector<int>{
		1,-1,0,0,10000,0,0,0,0,0,
		0,0
		});
	shared_ptr<vector<shared_ptr<Node>>>newNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newNodeGroup(new vector<shared_ptr<Node>>());
	PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
	shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{
		-1,0,10000,0,0,0
		});
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newNode(new Node{3,0,false,false,nullptr,selectPointer,newNodeProperty,newNodeChild,newNodeGroup });
	shared_ptr<Node> newGroupNode(new Node{4 ,0,true,true,newGroupNodePath,newNode,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
	newNode->Group->push_back(newGroupNode);
	selectPointer->NodeNum += 1;
	selectPointer->Child->push_back(newNode);
}
void Item::NodeFCreate(String^ NodeName)
{
	shared_ptr<Node> selectPointer = SelectPointer(NodeName);
	shared_ptr<vector<int>>newNodeProperty(new vector<int>{
		-1,1
		});
	shared_ptr<vector<shared_ptr<Node>>>newNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newNode(new Node{5,0,false,false,nullptr,selectPointer,newNodeProperty,newNodeChild,newNodeGroup });
	selectPointer->NodeNum += 1;
	selectPointer->Child->push_back(newNode);
}
void Item::NodeStartRoot()
{
	shared_ptr<vector<int>>rootNodeProperty(new vector<int>());
	shared_ptr<vector<shared_ptr<Node>>>rootNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>rootNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>rootNodeMC(new vector<shared_ptr<Node>>());
	vector< vector<double>> v;
	 vector<double> v2;
	shared_ptr < struct Node > rootNode(new Node{ 0,0,true,false,nullptr,nullptr,rootNodeProperty ,rootNodeChild ,rootNodeGroup,rootNodeMC,v ,v2,false ,0.01,10 });
	RootPointer= rootNode;
}

int Item::c_num(String^ NodeName)
{
	shared_ptr<Node> selectPointer = SelectPointer(NodeName);
	return selectPointer->NodeNum;
}



//graph--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



shared_ptr<vector<int>> Item::RenewGraph(int gnum) {
	shared_ptr<Node> selectPointer = PropNodeNamePointer;
	int gtypeteller = 0;
	if (selectPointer->NodeType == 1) {
		switch (gnum) {
		case 0:
			gtypeteller = 17;
			break;
		default:
			gtypeteller = 59;
			break;
		};
	}
	else {
		switch (gnum) {
		case 0:
			gtypeteller = 10;
			break;
		default:
			gtypeteller = 52;
			break;
		};
	}
	switch (selectPointer->Property->at(gtypeteller)) {
	case 0:
		return Rmaker(gnum, selectPointer);
		break;
	case 1:
		return Bmaker(gnum, selectPointer);
		break;
	default:
		return Dmaker(gnum, selectPointer);
	};
}

shared_ptr<vector<int>> Item::GetPoint(int gnum)
{
	int pointNumTeller= 0;
	int pbeginTeller = 0;
	shared_ptr<vector<int>>Point(new vector<int>());
	switch (PropNodeNamePointer->NodeType) {
	case 1:
		switch (gnum) {
		case 0:
			pointNumTeller = 18;
			pbeginTeller = 19;
			break;
		case 1:
			pointNumTeller = 61;
			pbeginTeller = 62;
			break;
		case 2:
			pointNumTeller = 61;
			pbeginTeller = 82;
			break;
		}
		break;
	case 2:
		switch (gnum) {
		case 0:
			pointNumTeller = 11;
			pbeginTeller = 12;
			break;
		case 1:
			pointNumTeller = 53;
			pbeginTeller = 54;
			break;
		case 2:
			pointNumTeller = 53;
			pbeginTeller = 74;
			break;
		}
		break;
	}
	Point->push_back(PropNodeNamePointer->Property->at(pointNumTeller));
	switch (PropNodeNamePointer->NodeType) {
	case 1:
		switch (gnum) {
		case 1:
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i+20));
			}
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i));
			}
			break;
		default:
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller+i));
			}
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i+20));
			}
		}
	case 2:
		switch (gnum) {
		case 1:
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i + 20));
			}
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i));
			}
			break;
		default:
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i));
			}
			for (int i = 0; i < PropNodeNamePointer->Property->at(pointNumTeller); i++) {
				Point->push_back(PropNodeNamePointer->Property->at(pbeginTeller + i + 20));
			}
		}
	}
	return Point;
}

int Item::GetExpansionCoefficientInt(int max, int num)
{
	int ec = 1;
	for (int i = 1; i < num+1;i++) {
		ec = ec * (max - i+1) / i;
	}
	return ec;
}

shared_ptr<vector<int>>Item::Rmaker(int gnum, shared_ptr<Node> selectPointer) {
		shared_ptr<vector<int>>curvePoints(new vector<int>());//curvePoints[0]は点の数,-1はエラーを表す(ベジェで発生するかも　ベジェは点のx逆転あり)
		int gnumteller = 0;
		int gpbeginteller = 0;
		int x[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int y[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gnumteller = 18;
				break;
			default:
				gnumteller = 61;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gnumteller = 11;
				break;
			default:
				gnumteller = 53;
				break;
			};
		}
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gpbeginteller = 19;
				break;
			case 1:
				gpbeginteller = 62;
				break;
			default:
				gpbeginteller = 82;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gpbeginteller = 12;
				break;
			case 1:
				gpbeginteller = 54;
				break;
			default:
				gpbeginteller = 74;
				break;
			};
		}
		int gpnum = selectPointer->Property->at(gnumteller);
		switch (gnum) {
		case 1:
			x[0] = selectPointer->Property->at(gpbeginteller + 20);
			x[1] = selectPointer->Property->at(gpbeginteller + 21);
			x[2] = selectPointer->Property->at(gpbeginteller + 22);
			x[3] = selectPointer->Property->at(gpbeginteller + 23);
			x[4] = selectPointer->Property->at(gpbeginteller + 24);
			x[5] = selectPointer->Property->at(gpbeginteller + 25);
			x[6] = selectPointer->Property->at(gpbeginteller + 26);
			x[7] = selectPointer->Property->at(gpbeginteller + 27);
			x[8] = selectPointer->Property->at(gpbeginteller + 28);
			x[9] = selectPointer->Property->at(gpbeginteller + 29);
			x[10] = selectPointer->Property->at(gpbeginteller + 30);
			x[11] = selectPointer->Property->at(gpbeginteller + 31);
			x[12] = selectPointer->Property->at(gpbeginteller + 32);
			x[13] = selectPointer->Property->at(gpbeginteller + 33);
			x[14] = selectPointer->Property->at(gpbeginteller + 34);
			x[15] = selectPointer->Property->at(gpbeginteller + 35);
			x[16] = selectPointer->Property->at(gpbeginteller + 36);
			x[17] = selectPointer->Property->at(gpbeginteller + 37);
			x[18] = selectPointer->Property->at(gpbeginteller + 38);
			x[19] = selectPointer->Property->at(gpbeginteller + 39);
			y[0] = selectPointer->Property->at(gpbeginteller);
			y[1] = selectPointer->Property->at(gpbeginteller + 1);
			y[2] = selectPointer->Property->at(gpbeginteller + 2);
			y[3] = selectPointer->Property->at(gpbeginteller + 3);
			y[4] = selectPointer->Property->at(gpbeginteller + 4);
			y[5] = selectPointer->Property->at(gpbeginteller + 5);
			y[6] = selectPointer->Property->at(gpbeginteller + 6);
			y[7] = selectPointer->Property->at(gpbeginteller + 7);
			y[8] = selectPointer->Property->at(gpbeginteller + 8);
			y[9] = selectPointer->Property->at(gpbeginteller + 9);
			y[10] = selectPointer->Property->at(gpbeginteller + 10);
			y[11] = selectPointer->Property->at(gpbeginteller + 11);
			y[12] = selectPointer->Property->at(gpbeginteller + 12);
			y[13] = selectPointer->Property->at(gpbeginteller + 13);
			y[14] = selectPointer->Property->at(gpbeginteller + 14);
			y[15] = selectPointer->Property->at(gpbeginteller + 15);
			y[16] = selectPointer->Property->at(gpbeginteller + 16);
			y[17] = selectPointer->Property->at(gpbeginteller + 17);
			y[18] = selectPointer->Property->at(gpbeginteller + 18);
			y[19] = selectPointer->Property->at(gpbeginteller + 19);
			break;
		default:
			x[0] = selectPointer->Property->at(gpbeginteller);
			x[1] = selectPointer->Property->at(gpbeginteller + 1);
			x[2] = selectPointer->Property->at(gpbeginteller + 2);
			x[3] = selectPointer->Property->at(gpbeginteller + 3);
			x[4] = selectPointer->Property->at(gpbeginteller + 4);
			x[5] = selectPointer->Property->at(gpbeginteller + 5);
			x[6] = selectPointer->Property->at(gpbeginteller + 6);
			x[7] = selectPointer->Property->at(gpbeginteller + 7);
			x[8] = selectPointer->Property->at(gpbeginteller + 8);
			x[9] = selectPointer->Property->at(gpbeginteller + 9);
			x[10] = selectPointer->Property->at(gpbeginteller + 10);
			x[11] = selectPointer->Property->at(gpbeginteller + 11);
			x[12] = selectPointer->Property->at(gpbeginteller + 12);
			x[13] = selectPointer->Property->at(gpbeginteller + 13);
			x[14] = selectPointer->Property->at(gpbeginteller + 14);
			x[15] = selectPointer->Property->at(gpbeginteller + 15);
			x[16] = selectPointer->Property->at(gpbeginteller + 16);
			x[17] = selectPointer->Property->at(gpbeginteller + 17);
			x[18] = selectPointer->Property->at(gpbeginteller + 18);
			x[19] = selectPointer->Property->at(gpbeginteller + 19);
			y[0] = selectPointer->Property->at(gpbeginteller + 20);
			y[1] = selectPointer->Property->at(gpbeginteller + 21);
			y[2] = selectPointer->Property->at(gpbeginteller + 22);
			y[3] = selectPointer->Property->at(gpbeginteller + 23);
			y[4] = selectPointer->Property->at(gpbeginteller + 24);
			y[5] = selectPointer->Property->at(gpbeginteller + 25);
			y[6] = selectPointer->Property->at(gpbeginteller + 26);
			y[7] = selectPointer->Property->at(gpbeginteller + 27);
			y[8] = selectPointer->Property->at(gpbeginteller + 28);
			y[9] = selectPointer->Property->at(gpbeginteller + 29);
			y[10] = selectPointer->Property->at(gpbeginteller + 30);
			y[11] = selectPointer->Property->at(gpbeginteller + 31);
			y[12] = selectPointer->Property->at(gpbeginteller + 32);
			y[13] = selectPointer->Property->at(gpbeginteller + 33);
			y[14] = selectPointer->Property->at(gpbeginteller + 34);
			y[15] = selectPointer->Property->at(gpbeginteller + 35);
			y[16] = selectPointer->Property->at(gpbeginteller + 36);
			y[17] = selectPointer->Property->at(gpbeginteller + 37);
			y[18] = selectPointer->Property->at(gpbeginteller + 38);
			y[19] = selectPointer->Property->at(gpbeginteller + 39);
			break;
		};
		x[20] = x[0] * 2 - x[1];//20~23は本来の枠外-,24~28は本来の枠外+を表す
		x[21]= x[20] * 2 - x[0];
		x[22] = x[21] * 2 - x[20];
		x[23] = x[22] * 2 - x[21];
		x[24] = x[gpnum-1] * 2 - x[gpnum-2];
		x[25] = x[24] * 2 - x[gpnum-1];
		x[26] = x[25] * 2 - x[24];
		x[27] = x[26] * 2 - x[25];
		y[20] = y[0] * 2 - y[1];
		y[21] = y[20] * 2 - y[0];
		y[22] = y[21] * 2 - y[20];
		y[23] = y[22] * 2 - y[21];
		y[24] = y[gpnum-1] * 2 - y[gpnum-2];
		y[25] = y[24] * 2 - y[gpnum-1];
		y[26] = y[25] * 2 - y[24];
		y[27] = y[26] * 2 - y[25];

		curvePoints->push_back(51);
		for (int i = 0; i < 10200; i+=200) {
			curvePoints->push_back(i);
		}
		for (int i = 0; i < 10200; i+=200) {
			double s = 0;
			for (int t = 0; t < gpnum; t++) {
				double n = y[t];
				for (int u = 0; u < t; u++) {
					n *= (i - x[u]);
					n	/= (x[t] - x[u]);
				}
				for (int u = t+1; u < gpnum; u++) {
					n *= (i - x[u]);
					n /= (x[t] - x[u]);
				}
				for (int v = 0; v < gpnum / 4; v++) {
					n *= (i - x[v + 20]);
					n *= (i - x[v + 24]);
					n/= (x[t] - x[v + 20]);
					n/=(x[t] - x[v+24]);
				}
				s += n;
			}
			for (int v = 0; v < gpnum / 4; v++) {
				double n = y[v+20];
				double j = y[v+24];
				for (int w = 0; w < gpnum; w++) {
					n *= (i - x[w]);
					n/= (x[v+20] - x[w]);
					j *= (i - x[w]);
					j/= (x[v + 24] - x[w]);
				}
				n *= (i - x[v + 24]);
				n	/= (x[v + 20] - x[v+24]);
				j *= (i - x[v + 20]);
				j	/= (x[v + 24] - x[v+20]);
				for (int m = 0; m < v; m++) {
					n *= (i - x[m + 20]);
					n *= (i - x[m + 24]);
					n  /= (x[v + 20] - x[m + 20]);
					n	/=(x[v+20] - x[m + 24]);
					j *= (i - x[m + 20]);
					j *= (i - x[m + 24]);
					j /= (x[v + 20] - x[m + 20]);
					j/=(x[v + 20] - x[m + 24]);
				}
				for (int m = v+1; m < gpnum/4; m++) {
					n*= (i - x[m + 20]);
					n*= (i - x[m + 24]);
					n /= (x[v + 20] - x[m + 20]);
					n	/=(x[v+20] - x[m + 24]);
					j *= (i - x[m + 20]);
					j*=(i - x[m + 24]);
					j/= (x[v + 20] - x[m + 20]);
					j/= (x[v + 20] - x[m + 24]);
				}
				s += n + j;
			}
			curvePoints->push_back((int)s);
		}
		return curvePoints;
	}

	shared_ptr<vector<int>>Item::Bmaker(int gnum, shared_ptr<Node> selectPointer) {
		shared_ptr<vector<int>>curvePoints(new vector<int>());
		int gnumteller = 0;
		int gpbeginteller = 0;
		int x[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int y[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gnumteller = 18;
				break;
			default:
				gnumteller = 61;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gnumteller = 11;
				break;
			default:
				gnumteller = 53;
				break;
			};
		}
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gpbeginteller = 19;
				break;
			case 1:
				gpbeginteller = 62;
				break;
			default:
				gpbeginteller = 82;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gpbeginteller = 12;
				break;
			case 1:
				gpbeginteller = 54;
				break;
			default:
				gpbeginteller = 74;
				break;
			};
		}
			int gpnum = selectPointer->Property->at(gnumteller);
			switch (gnum) {
			case 1:
				x[0] = selectPointer->Property->at(gpbeginteller + 20);
				x[1] = selectPointer->Property->at(gpbeginteller + 21);
				x[2] = selectPointer->Property->at(gpbeginteller + 22);
				x[3] = selectPointer->Property->at(gpbeginteller + 23);
				x[4] = selectPointer->Property->at(gpbeginteller + 24);
				x[5] = selectPointer->Property->at(gpbeginteller + 25);
				x[6] = selectPointer->Property->at(gpbeginteller + 26);
				x[7] = selectPointer->Property->at(gpbeginteller + 27);
				x[8] = selectPointer->Property->at(gpbeginteller + 28);
				x[9] = selectPointer->Property->at(gpbeginteller + 29);
				x[10] = selectPointer->Property->at(gpbeginteller + 30);
				x[11] = selectPointer->Property->at(gpbeginteller + 31);
				x[12] = selectPointer->Property->at(gpbeginteller + 32);
				x[13] = selectPointer->Property->at(gpbeginteller + 33);
				x[14] = selectPointer->Property->at(gpbeginteller + 34);
				x[15] = selectPointer->Property->at(gpbeginteller + 35);
				x[16] = selectPointer->Property->at(gpbeginteller + 36);
				x[17] = selectPointer->Property->at(gpbeginteller + 37);
				x[18] = selectPointer->Property->at(gpbeginteller + 38);
				x[19] = selectPointer->Property->at(gpbeginteller + 39);
				y[0] = selectPointer->Property->at(gpbeginteller);
				y[1] = selectPointer->Property->at(gpbeginteller + 1);
				y[2] = selectPointer->Property->at(gpbeginteller + 2);
				y[3] = selectPointer->Property->at(gpbeginteller + 3);
				y[4] = selectPointer->Property->at(gpbeginteller + 4);
				y[5] = selectPointer->Property->at(gpbeginteller + 5);
				y[6] = selectPointer->Property->at(gpbeginteller + 6);
				y[7] = selectPointer->Property->at(gpbeginteller + 7);
				y[8] = selectPointer->Property->at(gpbeginteller + 8);
				y[9] = selectPointer->Property->at(gpbeginteller + 9);
				y[10] = selectPointer->Property->at(gpbeginteller + 10);
				y[11] = selectPointer->Property->at(gpbeginteller + 11);
				y[12] = selectPointer->Property->at(gpbeginteller + 12);
				y[13] = selectPointer->Property->at(gpbeginteller + 13);
				y[14] = selectPointer->Property->at(gpbeginteller + 14);
				y[15] = selectPointer->Property->at(gpbeginteller + 15);
				y[16] = selectPointer->Property->at(gpbeginteller + 16);
				y[17] = selectPointer->Property->at(gpbeginteller + 17);
				y[18] = selectPointer->Property->at(gpbeginteller + 18);
				y[19] = selectPointer->Property->at(gpbeginteller + 19);
				break;
			default:
				x[0] = selectPointer->Property->at(gpbeginteller);
				x[1] = selectPointer->Property->at(gpbeginteller + 1);
				x[2] = selectPointer->Property->at(gpbeginteller + 2);
				x[3] = selectPointer->Property->at(gpbeginteller + 3);
				x[4] = selectPointer->Property->at(gpbeginteller + 4);
				x[5] = selectPointer->Property->at(gpbeginteller + 5);
				x[6] = selectPointer->Property->at(gpbeginteller + 6);
				x[7] = selectPointer->Property->at(gpbeginteller + 7);
				x[8] = selectPointer->Property->at(gpbeginteller + 8);
				x[9] = selectPointer->Property->at(gpbeginteller + 9);
				x[10] = selectPointer->Property->at(gpbeginteller + 10);
				x[11] = selectPointer->Property->at(gpbeginteller + 11);
				x[12] = selectPointer->Property->at(gpbeginteller + 12);
				x[13] = selectPointer->Property->at(gpbeginteller + 13);
				x[14] = selectPointer->Property->at(gpbeginteller + 14);
				x[15] = selectPointer->Property->at(gpbeginteller + 15);
				x[16] = selectPointer->Property->at(gpbeginteller + 16);
				x[17] = selectPointer->Property->at(gpbeginteller + 17);
				x[18] = selectPointer->Property->at(gpbeginteller + 18);
				x[19] = selectPointer->Property->at(gpbeginteller + 19);
				y[0] = selectPointer->Property->at(gpbeginteller + 20);
				y[1] = selectPointer->Property->at(gpbeginteller + 21);
				y[2] = selectPointer->Property->at(gpbeginteller + 22);
				y[3] = selectPointer->Property->at(gpbeginteller + 23);
				y[4] = selectPointer->Property->at(gpbeginteller + 24);
				y[5] = selectPointer->Property->at(gpbeginteller + 25);
				y[6] = selectPointer->Property->at(gpbeginteller + 26);
				y[7] = selectPointer->Property->at(gpbeginteller + 27);
				y[8] = selectPointer->Property->at(gpbeginteller + 28);
				y[9] = selectPointer->Property->at(gpbeginteller + 29);
				y[10] = selectPointer->Property->at(gpbeginteller + 30);
				y[11] = selectPointer->Property->at(gpbeginteller + 31);
				y[12] = selectPointer->Property->at(gpbeginteller + 32);
				y[13] = selectPointer->Property->at(gpbeginteller + 33);
				y[14] = selectPointer->Property->at(gpbeginteller + 34);
				y[15] = selectPointer->Property->at(gpbeginteller + 35);
				y[16] = selectPointer->Property->at(gpbeginteller + 36);
				y[17] = selectPointer->Property->at(gpbeginteller + 37);
				y[18] = selectPointer->Property->at(gpbeginteller + 38);
				y[19] = selectPointer->Property->at(gpbeginteller + 39);
				break;
			};
		curvePoints->push_back(51);
		for (double i = 0; i <1.02; i+=0.02) {
			double s=0;
			for (int t = 0; t < gpnum; t++) {
				s=s* (1 - i) + x[t]*GetExpansionCoefficientInt(gpnum-1,t)*pow(i,t);
			}
			curvePoints->push_back((int)s);
		}
		for (double i = 0; i <1.02; i += 0.02) {
			double s = 0;
			for (int t = 0; t < gpnum; t++) {
				s = s * (1 - i) + y[t] * GetExpansionCoefficientInt(gpnum - 1, t) * pow(i, t);
			}
			curvePoints->push_back((int)s);
		}
		return curvePoints;
	}
	shared_ptr<vector<int>>Item::Dmaker(int gnum, shared_ptr<Node> selectPointer) {
		shared_ptr<vector<int>>curvePoints(new vector<int>());
		int gnumteller = 0;
		int gpbeginteller = 0;
		int x[20] = { 0};
		int y[20] = { 0 };
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gnumteller = 18;
				break;
			default:
				gnumteller = 61;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gnumteller = 11;
				break;
			default:
				gnumteller = 53;
				break;
			};
		}
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gpbeginteller = 19;
				break;
			case 1:
				gpbeginteller = 62;
				break;
			default:
				gpbeginteller = 82;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gpbeginteller = 12;
				break;
			case 1:
				gpbeginteller = 54;
				break;
			default:
				gpbeginteller = 74;
				break;
			};
		}
			int gpnum = selectPointer->Property->at(gnumteller);
			switch (gnum) {
			case 1:
				x[0] = selectPointer->Property->at(gpbeginteller + 20);
				x[1] = selectPointer->Property->at(gpbeginteller + 21);
				x[2] = selectPointer->Property->at(gpbeginteller + 22);
				x[3] = selectPointer->Property->at(gpbeginteller + 23);
				x[4] = selectPointer->Property->at(gpbeginteller + 24);
				x[5] = selectPointer->Property->at(gpbeginteller + 25);
				x[6] = selectPointer->Property->at(gpbeginteller + 26);
				x[7] = selectPointer->Property->at(gpbeginteller + 27);
				x[8] = selectPointer->Property->at(gpbeginteller + 28);
				x[9] = selectPointer->Property->at(gpbeginteller + 29);
				x[10] = selectPointer->Property->at(gpbeginteller + 30);
				x[11] = selectPointer->Property->at(gpbeginteller + 31);
				x[12] = selectPointer->Property->at(gpbeginteller + 32);
				x[13] = selectPointer->Property->at(gpbeginteller + 33);
				x[14] = selectPointer->Property->at(gpbeginteller + 34);
				x[15] = selectPointer->Property->at(gpbeginteller + 35);
				x[16] = selectPointer->Property->at(gpbeginteller + 36);
				x[17] = selectPointer->Property->at(gpbeginteller + 37);
				x[18] = selectPointer->Property->at(gpbeginteller + 38);
				x[19] = selectPointer->Property->at(gpbeginteller + 39);
				y[0] = selectPointer->Property->at(gpbeginteller);
				y[1] = selectPointer->Property->at(gpbeginteller + 1);
				y[2] = selectPointer->Property->at(gpbeginteller + 2);
				y[3] = selectPointer->Property->at(gpbeginteller + 3);
				y[4] = selectPointer->Property->at(gpbeginteller + 4);
				y[5] = selectPointer->Property->at(gpbeginteller + 5);
				y[6] = selectPointer->Property->at(gpbeginteller + 6);
				y[7] = selectPointer->Property->at(gpbeginteller + 7);
				y[8] = selectPointer->Property->at(gpbeginteller + 8);
				y[9] = selectPointer->Property->at(gpbeginteller + 9);
				y[10] = selectPointer->Property->at(gpbeginteller + 10);
				y[11] = selectPointer->Property->at(gpbeginteller + 11);
				y[12] = selectPointer->Property->at(gpbeginteller + 12);
				y[13] = selectPointer->Property->at(gpbeginteller + 13);
				y[14] = selectPointer->Property->at(gpbeginteller + 14);
				y[15] = selectPointer->Property->at(gpbeginteller + 15);
				y[16] = selectPointer->Property->at(gpbeginteller + 16);
				y[17] = selectPointer->Property->at(gpbeginteller + 17);
				y[18] = selectPointer->Property->at(gpbeginteller + 18);
				y[19] = selectPointer->Property->at(gpbeginteller + 19);

				break;
			default:
				x[0] = selectPointer->Property->at(gpbeginteller);
				x[1] = selectPointer->Property->at(gpbeginteller + 1);
				x[2] = selectPointer->Property->at(gpbeginteller + 2);
				x[3] = selectPointer->Property->at(gpbeginteller + 3);
				x[4] = selectPointer->Property->at(gpbeginteller + 4);
				x[5] = selectPointer->Property->at(gpbeginteller + 5);
				x[6] = selectPointer->Property->at(gpbeginteller + 6);
				x[7] = selectPointer->Property->at(gpbeginteller + 7);
				x[8] = selectPointer->Property->at(gpbeginteller + 8);
				x[9] = selectPointer->Property->at(gpbeginteller + 9);
				x[10] = selectPointer->Property->at(gpbeginteller + 10);
				x[11] = selectPointer->Property->at(gpbeginteller + 11);
				x[12] = selectPointer->Property->at(gpbeginteller + 12);
				x[13] = selectPointer->Property->at(gpbeginteller + 13);
				x[14] = selectPointer->Property->at(gpbeginteller + 14);
				x[15] = selectPointer->Property->at(gpbeginteller + 15);
				x[16] = selectPointer->Property->at(gpbeginteller + 16);
				x[17] = selectPointer->Property->at(gpbeginteller + 17);
				x[18] = selectPointer->Property->at(gpbeginteller + 18);
				x[19] = selectPointer->Property->at(gpbeginteller + 19);
				y[0] = selectPointer->Property->at(gpbeginteller + 20);
				y[1] = selectPointer->Property->at(gpbeginteller + 21);
				y[2] = selectPointer->Property->at(gpbeginteller + 22);
				y[3] = selectPointer->Property->at(gpbeginteller + 23);
				y[4] = selectPointer->Property->at(gpbeginteller + 24);
				y[5] = selectPointer->Property->at(gpbeginteller + 25);
				y[6] = selectPointer->Property->at(gpbeginteller + 26);
				y[7] = selectPointer->Property->at(gpbeginteller + 27);
				y[8] = selectPointer->Property->at(gpbeginteller + 28);
				y[9] = selectPointer->Property->at(gpbeginteller + 29);
				y[10] = selectPointer->Property->at(gpbeginteller + 30);
				y[11] = selectPointer->Property->at(gpbeginteller + 31);
				y[12] = selectPointer->Property->at(gpbeginteller + 32);
				y[13] = selectPointer->Property->at(gpbeginteller + 33);
				y[14] = selectPointer->Property->at(gpbeginteller + 34);
				y[15] = selectPointer->Property->at(gpbeginteller + 35);
				y[16] = selectPointer->Property->at(gpbeginteller + 36);
				y[17] = selectPointer->Property->at(gpbeginteller + 37);
				y[18] = selectPointer->Property->at(gpbeginteller + 38);
				y[19] = selectPointer->Property->at(gpbeginteller + 39);
				break;
			};
		curvePoints->push_back(gpnum);
		for (int i = 0; i < gpnum; i++) {
			curvePoints->push_back(x[i]);
		}
		for (int i = 0; i < gpnum; i++) {
			curvePoints->push_back(y[i]);
		}
		return curvePoints;
	}


//property-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	
	void Item::SetPropNodeName(String^ PropNodeName)
	{
		PropNodeNamePointer = SelectPointer(PropNodeName);
	}

	void Item::SetTBValue(int Value, String^ ControlName)
	{
		bool bpchanged=false;
		int num = 0;
		int pointTeller = 0;
		for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
			char a = ControlName->ToCharArray()[i];
			num = num * 10 + a - '0';//char'0'=int 48
		}
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (num) {
			case 0:
				pointTeller = 0;
				break;
			case 1:
				pointTeller = 2;
				break;
			case 2:
				pointTeller = 3;
				break;
			case 3:
				pointTeller = 4;
				break;
			case 4:
				pointTeller = 5;
				break;
			case 5:
				pointTeller = 6;
				break;
			case 6:
				pointTeller = 7;
				break;
			case 7:
				pointTeller = 8;
				break;
			case 8:
				pointTeller = 9;
				break;
			case 9:
				pointTeller = 11;
				break;
			case 10:
				pointTeller = 13;
				break;
			case 11:
				pointTeller = 10;
				break;
			case 12:
				pointTeller = 12;
				break;
			case 13:
				pointTeller = 14;
				break;
			case 14:
				pointTeller = 15;
				break;
			case 15:
				pointTeller = 16;
				break;
			case 16:
				pointTeller = 18;
				break;
			case 17:
				pointTeller = 39 + Chart0Point;
				break;
			case 18:
				pointTeller = 19 + Chart0Point;
				break;
			case 19:
				pointTeller = 60;
				break;
			case 20:
				pointTeller = 61;
				break;
			case 21:
				pointTeller = 62 + Chart1Point;
				break;
			case 22:
				pointTeller = 82 + Chart1Point;
				break;
			case 23:
				pointTeller = 102 + Chart2Point;
				break;
			case 24:
				pointTeller = 82 + Chart2Point;
				break;
			case 25:
				pointTeller = 122;
				break;
			}
			if (pointTeller > 16)bpchanged = true;
			break;
		case 2:
			switch (num) {
			case 0:
				pointTeller = 1;
				break;
			case 1:
				pointTeller = 2;
				break;
			case 2:
				pointTeller = 3;
				break;
			case 3:
				pointTeller = 4;
				break;
			case 4:
				pointTeller = 5;
				break;
			case 5:
				pointTeller = 6;
				break;
			case 6:
				pointTeller = 7;
				break;
			case 7:
				pointTeller = 8;
				break;
			case 8:
				pointTeller = 9;
				break;
			case 9:
				pointTeller = 11;
				break;
			case 10:
				pointTeller = 32 + Chart0Point;
				break;
			case 11:
				pointTeller = 12 + Chart0Point;
				break;
			case 12:
				pointTeller = 53;
				break;
			case 13:
				pointTeller = 54 + Chart1Point;
				break;
			case 14:
				pointTeller = 74 + Chart1Point;
				break;
			case 15:
				pointTeller = 94 + Chart2Point;
				break;
			case 16:
				pointTeller = 74 + Chart2Point;
				break;
			}
			if (pointTeller > 10)bpchanged = true;
			break;
		case 3:
			switch (num) {
			case 0:
				pointTeller = 0;
				break;
			case 1:
				pointTeller = 2;
				break;
			case 2:
				pointTeller = 3;
				break;
			case 3:
				pointTeller = 4;
				break;
			case 4:
				pointTeller = 5;
				break;
			case 5:
				pointTeller = 6;
				break;
			case 6:
				pointTeller = 8;
				break;
			case 7:
				pointTeller = 10;
				break;
			case 8:
				pointTeller = 7;
				break;
			case 9:
				pointTeller = 9;
				break;
			case 10:
				pointTeller = 11;
				break;
			}
			break;
		case 4:
			switch (num) {
			case 0:
				pointTeller = 1;
				break;
			case 1:
				pointTeller = 2;
				break;
			case 2:
				pointTeller = 3;
				break;
			case 3:
				pointTeller = 4;
				break;
			case 4:
				pointTeller = 5;
				break;
			}
			break;
		case 5:
			pointTeller = 1;
			break;
		}
		PropNodeNamePointer->Property->at(pointTeller) = Value;
		if (bpchanged)
			PropNodeNamePointer->BirthPChange = true;
		else
			PropNodeNamePointer->PropChange = true;
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (num) {
			case 0:
				GroupChanger();
				break;
			case 1:
				Setter(pointTeller);
				break;
			case 2:
				Setter(pointTeller);
				break;
			case 3:
				Setter(pointTeller);
				break;
			case 4:
				if (PropNodeNamePointer->Property->at(6) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(6);
				}
				break;
			case 5:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 6:
				if (PropNodeNamePointer->Property->at(8) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(8);
				}
				break;
			case 7:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 8:
				if (PropNodeNamePointer->Property->at(10) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(10);
				}
				break;
			case 9:
				if (PropNodeNamePointer->Property->at(12) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(12);
				}
				break;
			case 10:
				if (PropNodeNamePointer->Property->at(14) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(14);
				}
				break;
			case 11:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 12:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 13:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 14:
				if (PropNodeNamePointer->Property->at(16) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(16);
				}
				break;
			case 15:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 16:
				Setter(pointTeller);
				break;
			case 17:
				if (PropNodeNamePointer->Property->at(122) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(123);
				}
				break;
			case 18:
				if (PropNodeNamePointer->Property->at(122) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(123);
				}
				break;
			case 19:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 20:
				Setter(pointTeller);
				break;
			case 21:
				if (PropNodeNamePointer->Property->at(60) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(61);
				}
				break;
			case 22:
				if (PropNodeNamePointer->Property->at(60) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(61);
				}
				break;
			case 23:
				if (PropNodeNamePointer->Property->at(60) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(62);
				}
				break;
			case 24:
				if (PropNodeNamePointer->Property->at(60) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(62);
				}
				break;
			case 25:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			}
			break;
		case 3:
			switch (num) {
			case 0:
				GroupChanger();
				break;
			case 1:
				if (PropNodeNamePointer->Property->at(3) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(3);
				}
				break;
			case 2:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 3:
				if (PropNodeNamePointer->Property->at(5) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(5);
				}
				break;
			case 4:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 5:
				if (PropNodeNamePointer->Property->at(7) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(7);
				}
				break;
			case 6:
				if (PropNodeNamePointer->Property->at(9) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(9);
				}
				break;
			case 7:
				if (PropNodeNamePointer->Property->at(11) == 0) {
					Setter(pointTeller);
				}
				else {
					Randomizer(11);
				}
				break;
			case 8:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 9:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			case 10:
				if (PropNodeNamePointer->Property->at(pointTeller) != 0) {
					Randomizer(pointTeller);
				}
				break;
			}
			break;
		}
}

	int Item::GetRandomInt() {
		std::random_device rd;
		srand(rd()*10);
		return (rand()%200)-100;
	}

	void Item::Randomizer(int pointTeller)
	{ 
		int gpointTeller = 0;
		int gpoint2Teller = 0;
		int gpoint3Teller = 0;
		int valueTeller = 0;
		int value2Teller = 0;
		int value3Teller = 0;
		int repeater = 0;
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (pointTeller) {
			case 6 :
				gpointTeller =4 ;
				valueTeller =5 ;
				repeater = 1;
				break;
			case 8 :
				gpointTeller =5 ;
				valueTeller =7 ;
				repeater = 1;
				break;
			case 10:
				gpointTeller = 6;
				valueTeller =9 ;
				repeater = 1;
				break;
			case 12:
				gpointTeller =7 ;
				valueTeller =11 ;
				repeater = 1;
				break;
			case 14: 
				gpointTeller = 8;
				valueTeller = 13;
				repeater = 1;
				break;
			case 16 :
				gpointTeller =9 ;
				valueTeller = 15;
				repeater = 1;
				break;
			case 60:
				gpointTeller =54 ;
				gpoint2Teller = 74;
				gpoint3Teller = 94;
				valueTeller = 62;
				value2Teller = 82;
				value3Teller = 102;
				repeater = repeater = PropNodeNamePointer->Property->at(61);
				break;
			case 61: 
				gpointTeller = 54 + Chart1Point;
				gpoint2Teller = 74 + Chart1Point;
				gpoint3Teller = 94 + Chart1Point;
				valueTeller = 62 + Chart1Point;
				value2Teller = 82 + Chart1Point;
				value3Teller = 102 + Chart1Point;
				repeater = 1;
				pointTeller = 60;
				break;
			case 62:
				gpointTeller = 54 + Chart1Point;
				gpoint2Teller = 74 + Chart1Point;
				gpoint3Teller = 94 + Chart1Point;
				valueTeller = 62 + Chart2Point;
				value2Teller = 82 + Chart2Point;
				value3Teller = 102 + Chart2Point;
				repeater = 1;
				pointTeller = 60;
				break;
			case 122://
				gpointTeller = 12;
				gpoint2Teller = 32;
				valueTeller = 19;
				value2Teller = 39;
				repeater = 1;
				break;
			case 123:
				gpointTeller = 12 + Chart0Point;
				gpoint2Teller = 32 + Chart0Point;
				valueTeller = 19 + Chart0Point;
				value2Teller = 39 + Chart0Point;
				repeater = PropNodeNamePointer->Property->at(18);
				pointTeller = 122;
				break;
			}
			for (int s = 0; s < repeater; s++) {
				for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
					int random = GetRandomInt();
					if (PropNodeNamePointer->Group->at(i) != nullptr) {
						double randomPercent = 0;
						randomPercent = PropNodeNamePointer->Property->at(pointTeller) * random / 1000000.0;
						PropNodeNamePointer->Group->at(i)->Property->at(gpointTeller+s) = PropNodeNamePointer->Property->at(valueTeller+s) + (int)((PropNodeNamePointer->Property->at(valueTeller+s) *randomPercent));
					if(gpointTeller + s>9)
						PropNodeNamePointer->Group->at(i)->BirthPChange = true;
					else
						PropNodeNamePointer->Group->at(i)->PropChange = true;
					}
				}
				if (value2Teller != 0) {
					for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
						int random = GetRandomInt();
						if (PropNodeNamePointer->Group->at(i) != nullptr) {
							double randomPercent = 0;
							randomPercent = PropNodeNamePointer->Property->at(pointTeller) * random / 1000000.0;
							PropNodeNamePointer->Group->at(i)->Property->at(gpoint2Teller+s) = PropNodeNamePointer->Property->at(value2Teller+s) + (int)((PropNodeNamePointer->Property->at(value2Teller + s) * randomPercent));
						}
					}
				}
				if (value3Teller != 0) {
					for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
						int random = GetRandomInt();
						if (PropNodeNamePointer->Group->at(i) != nullptr) {
							double randomPercent = 0;
							randomPercent = PropNodeNamePointer->Property->at(pointTeller) * random / 1000000.0;
							PropNodeNamePointer->Group->at(i)->Property->at(gpoint3Teller+s) = PropNodeNamePointer->Property->at(value3Teller+s) + (int)((PropNodeNamePointer->Property->at(value3Teller + s) * randomPercent));
						}
					}
				}
			}
			break;
		case 3:
			switch (pointTeller) {
			case 3:
				gpointTeller = 1;
				valueTeller =2;
				break;
			case 5:
				gpointTeller = 2;
				valueTeller = 4;
				break;
			case 7:
				gpointTeller = 3;
				valueTeller = 6;
				break;
			case 9:
				gpointTeller = 4;
				valueTeller = 8;
				break;
			case 11:
				gpointTeller = 5;
				valueTeller = 10;
				break;
			}
			for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
				int random = GetRandomInt();
				if (PropNodeNamePointer->Group->at(i) != nullptr) {
					PropNodeNamePointer->Group->at(i)->Property->at(gpointTeller) = PropNodeNamePointer->Property->at(valueTeller) + PropNodeNamePointer->Property->at(valueTeller) * PropNodeNamePointer->Property->at(pointTeller) * random / 200000;
				}
			}
			break;
		}
	}

	void Item::Setter(int pointTeller)
	{
		int gpointTeller = 0;
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (pointTeller) {
			case 2:
				gpointTeller = 1;
				break;
			case 3:
				gpointTeller = 2;
				break;
			case 4:
				gpointTeller = 3;
				break;
			case 5:
				gpointTeller = 4;
				break;
			case 7:
				gpointTeller = 5;
				break;
			case 9:
				gpointTeller = 6;
				break;
			case 11:
				gpointTeller = 7;
				break;
			case 13:
				gpointTeller = 8;
				break;
			case 15:
				gpointTeller = 9;
				break;
			case 18:
				gpointTeller = 11;
				break;
			case 61:
				gpointTeller = 53;
				break;
			default:
				if (pointTeller >= 19&& pointTeller < 39) {
					gpointTeller = pointTeller-7;
				}
				else if (pointTeller >= 39 && pointTeller < 59) {
					gpointTeller = pointTeller - 7;
				}
				else if (pointTeller >= 62 && pointTeller < 82) {
					gpointTeller = pointTeller - 8;
				}
				else if (pointTeller >= 82 && pointTeller < 102) {
					gpointTeller = pointTeller - 8;
				}
				else if (pointTeller >= 102 && pointTeller < 122) {
					gpointTeller = pointTeller - 8;
				}
				break;
			}
			for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
				if (PropNodeNamePointer->Group->at(i) != nullptr) {
					PropNodeNamePointer->Group->at(i)->Property->at(gpointTeller) = PropNodeNamePointer->Property->at(pointTeller);
					if (pointTeller==5)
						PropNodeNamePointer->Group->at(i)->BirthPChange = true;
					else
						PropNodeNamePointer->Group->at(i)->PropChange = true;
				}
			}
			break;
		case 3:
			switch (pointTeller) {
			case 2:
				gpointTeller = 1;
				break;
			case 4:
				gpointTeller = 2;
				break;
			case 6:
				gpointTeller = 3;
				break;
			case 8:
				gpointTeller = 4;
				break;
			case 10:
				gpointTeller = 5;
				break;
			}
			for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
				if (PropNodeNamePointer->Group->at(i) != nullptr) {
					PropNodeNamePointer->Group->at(i)->Property->at(gpointTeller) = PropNodeNamePointer->Property->at(pointTeller);
				}
			}
			break;
		}
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (pointTeller) {
			case 18:
				PointReset(18);
				break;
			case 61:
				PointReset(61);
				break;
			}
			break;
		}
}
	
	void Item::SetComboBoxValue(int Value, String^ ControlName)
	{
		int num = 0;
		int pointTeller = 0;
		int gpointTeller = 0;
		for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
			char a = ControlName->ToCharArray()[i];
			num = num * 10 + a - '0';//char'0'=int 48
		}
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (num) {
			case 0:
				pointTeller = 1;
				gpointTeller = 0;
				break;
			case 1:
				pointTeller = 17;
				gpointTeller = 10;
				break;
			case 2:
				pointTeller = 59;
				gpointTeller = 52;
				break;
			case 3:
				pointTeller = 123;
				gpointTeller = 114;
				break;
			}
			break;
		case 2:
			switch (num) {
			case 0:
				pointTeller = 0;
				break;
			case 1:
				pointTeller = 10;
				break;
			case 2:
				pointTeller = 52;
				break;
			case 3:
				pointTeller = 114;
				break;
			}
			break;
		case 3:
			pointTeller = 1;
			gpointTeller = 0;
			break;
		case 4:
			pointTeller = 0;
			break;
		case 5:
			pointTeller = 0;
			break;
		}
		PropNodeNamePointer->Property->at(pointTeller) = Value;
			PropNodeNamePointer->PropChange = true;
		for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
			if (PropNodeNamePointer->Group->at(i) != nullptr) {
				PropNodeNamePointer->Group->at(i)->Property->at(gpointTeller) =Value;
					PropNodeNamePointer->PropChange = true;
			}
		}
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (pointTeller) {
			case 17:
				PointReset(18);
				break;
			case 59:
				PointReset(61);
				break;
			}
			break;
		case 2:
			switch (pointTeller) {
			case 10:
				PointReset(11);
				break;
			case 52:
				PointReset(63);
				break;
			}
			break;
		}
	}

	int Item::GetPropNodeType()
	{
		return PropNodeNamePointer->NodeType;
	}

	int Item::GetValue(int ControlType,String^ControlName)
	{
		int num = 0;
		int pointTeller = 0;
		for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
			char a = ControlName->ToCharArray()[i];
			num = num * 10 + a - '0';//char'0'=int 48
		}
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (ControlType) {//0->ComboBox,1->TextBox&TrackBar
			case 0:
				switch (num) {
				case 0:
					pointTeller = 1;
					break;
				case 1:
					pointTeller = 17;
					break;
				case 2:
					pointTeller = 59;
					break;
				case 3:
					pointTeller = 123;
					break;
				}
				break;
			case 1:
				switch (num) {
				case 0:
					pointTeller = 0;
					break;
				case 1:
					pointTeller = 2;
					break;
				case 2:
					pointTeller = 3;
					break;
				case 3:
					pointTeller = 4;
					break;
				case 4:
					pointTeller = 5;
					break;
				case 5:
					pointTeller = 6;
					break;
				case 6:
					pointTeller = 7;
					break;
				case 7:
					pointTeller = 8;
					break;
				case 8:
					pointTeller = 9;
					break;
				case 9:
					pointTeller = 11;
					break;
				case 10:
					pointTeller = 13;
					break;
				case 11:
					pointTeller = 10;
					break;
				case 12:
					pointTeller = 12;
					break;
				case 13:
					pointTeller = 14;
					break;
				case 14:
					pointTeller = 15;
					break;
				case 15:
					pointTeller = 16;
					break;
				case 16:
					pointTeller = 18;
					break;
				case 17:
					pointTeller = 39 + Chart0Point;
					break;
				case 18:
					pointTeller = 19 + Chart0Point;
					break;
				case 19:
					pointTeller = 60;
					break;
				case 20:
					pointTeller = 61;
					break;
				case 21:
					pointTeller = 62 + Chart1Point;
					break;
				case 22:
					pointTeller = 82 + Chart1Point;
					break;
				case 23:
					pointTeller = 102 + Chart2Point;
					break;
				case 24:
					pointTeller = 82 + Chart2Point;
					break;
				case 25:
					pointTeller = 122;
					break;
				}
				break;
			}
			break;
		case 2:
			switch (ControlType) {//0->ComboBox,1->TextBox&TrackBar
			case 0:
				switch (num) {
				case 0:
					pointTeller = 0;
					break;
				case 1:
					pointTeller = 10;
					break;
				case 2:
					pointTeller = 52;
					break;
				case 3:
					pointTeller =114;
					break;
				}
				break;
			case 1:
				switch (num) {
				case 0:
					pointTeller = 1;
					break;
				case 1:
					pointTeller = 2;
					break;
				case 2:
					pointTeller = 3;
					break;
				case 3:
					pointTeller = 4;
					break;
				case 4:
					pointTeller = 5;
					break;
				case 5:
					pointTeller = 6;
					break;
				case 6:
					pointTeller = 7;
					break;
				case 7:
					pointTeller = 8;
					break;
				case 8:
					pointTeller = 9;
					break;
				case 9:
					pointTeller = 11;
					break;
				case 10:
					pointTeller = 32 + Chart0Point;
					break;
				case 11:
					pointTeller = 12 + Chart0Point;
					break;
				case 12:
					pointTeller = 53;
					break;
				case 13:
					pointTeller = 54 + Chart1Point;
					break;
				case 14:
					pointTeller = 74 + Chart1Point;
					break;
				case 15:
					pointTeller = 94 + Chart2Point;
					break;
				case 16:
					pointTeller = 74 + Chart2Point;
					break;
				}
				break;
			}
			break;
		case 3:
			switch (ControlType) {//0->ComboBox,1->TextBox&TrackBar
			case 0:
				pointTeller = 1;
				break;
			case 1:
				switch (num) {
				case 0:
					pointTeller = 0;
					break;
				case 1:
					pointTeller = 2;
					break;
				case 2:
					pointTeller = 3;
					break;
				case 3:
					pointTeller = 4;
					break;
				case 4:
					pointTeller = 5;
					break;
				case 5:
					pointTeller = 6;
					break;
				case 6:
					pointTeller = 8;
					break;
				case 7:
					pointTeller = 10;
					break;
				case 8:
					pointTeller = 7;
					break;
				case 9:
					pointTeller = 9;
					break;
				case 10:
					pointTeller = 11;
					break;
				}
				break;
			}
			break;
		case 4:
			switch (ControlType) {//0->ComboBox,1->TextBox&TrackBar
			case 0:
				pointTeller = 0;
				break;
			case 1:
				switch (num) {
				case 0:
					pointTeller = 1;
					break;
				case 1:
					pointTeller = 2;
					break;
				case 2:
					pointTeller = 3;
					break;
				case 3:
					pointTeller = 4;
					break;
				case 4:
					pointTeller = 5;
					break;
				}
				break;
			}
			break;
		case 5:
			switch (ControlType) {//0->ComboBox,1->TextBox&TrackBar
			case 0:
				pointTeller = 0;
				break;
			case 1:
				pointTeller = 1;
				break;
			}
			break;
		};
		return PropNodeNamePointer->Property->at(pointTeller);
	}

	void Item::PointReset(int pointNumTeller) {
		int turn = 0;
		int pbeginTeller = 0;
		int gpbeginTeller = 0;
		int pointNum = PropNodeNamePointer->Property->at(pointNumTeller);
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			switch (pointNumTeller) {
			case 18:
				turn = 2;
				pbeginTeller = 19;
				gpbeginTeller = 12;
				break;
			case 61:
				turn = 3;
				pbeginTeller = 62;
				gpbeginTeller = 54;
				break;
			}
			break;
		case 2:
			switch (pointNumTeller) {
			case 11:
				turn = 2;
				pbeginTeller = 12;
				break;
			case 53:
				turn = 3;
				pbeginTeller = 54;
				break;
			}
			break;
		}
		if (turn == 2) {
			for (int u = 0; u < pointNum; u++) {
				PropNodeNamePointer->Property->at(pbeginTeller + u) = 10000 * u / (pointNum - 1);
				PropNodeNamePointer->Property->at(pbeginTeller + 20 + u) = 10000 - 10000 * u / (pointNum - 1);
			}
			for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
				for (int u = 0; u < pointNum; u++) {
					PropNodeNamePointer->Group->at(i)->Property->at(gpbeginTeller + u) = 10000*u/(pointNum-1);
					PropNodeNamePointer->Group->at(i)->Property->at(gpbeginTeller + 20+ u) = 10000 - 10000 * u / (pointNum - 1);
				}
			}
		}
		else {
			for (int u = 0; u < pointNum; u++) {
				PropNodeNamePointer->Property->at(pbeginTeller + u) = 0;
				PropNodeNamePointer->Property->at(pbeginTeller + 20 + u) = 10000 * u / (pointNum - 1);
				PropNodeNamePointer->Property->at(pbeginTeller + 40 + u) = 0;
			}
			for (int i = 0; i < PropNodeNamePointer->Group->size(); i++) {
				for (int u = 0; u < pointNum; u++) {
					PropNodeNamePointer->Group->at(i)->Property->at(gpbeginTeller + u) = 0;
					PropNodeNamePointer->Group->at(i)->Property->at(gpbeginTeller + 20 + u) = 10000 * u / (pointNum - 1);
					PropNodeNamePointer->Group->at(i)->Property->at(gpbeginTeller + 40 + u) = 0;
				}
			}
		}
	}

	void Item::GroupChanger()
	{
		switch (PropNodeNamePointer->NodeType) {
		case 1:
			for (int i = PropNodeNamePointer->Group->size(); i > PropNodeNamePointer->Property->at(0); i--) {
				NodeChildSearcher(PropNodeNamePointer->Group->at(i-1));
				PropNodeNamePointer->Group->erase(PropNodeNamePointer->Group->begin() + i - 1);
			}
			PropNodeNamePointer->Group->shrink_to_fit();
			//
			for (int i = PropNodeNamePointer->Group->size(); i < PropNodeNamePointer->Property->at(0); i++) {
				PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
				shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{
					PropNodeNamePointer->Property->at(1),//0
					PropNodeNamePointer->Property->at(2),
					PropNodeNamePointer->Property->at(3),
					PropNodeNamePointer->Property->at(4),
					PropNodeNamePointer->Property->at(5),
					PropNodeNamePointer->Property->at(7),
					PropNodeNamePointer->Property->at(9),
					PropNodeNamePointer->Property->at(11),
					PropNodeNamePointer->Property->at(13),
					PropNodeNamePointer->Property->at(15),
					PropNodeNamePointer->Property->at(17),//10
					PropNodeNamePointer->Property->at(18),
					PropNodeNamePointer->Property->at(19),
					PropNodeNamePointer->Property->at(20),
					PropNodeNamePointer->Property->at(21),
					PropNodeNamePointer->Property->at(22),
					PropNodeNamePointer->Property->at(23),
					PropNodeNamePointer->Property->at(24),
					PropNodeNamePointer->Property->at(25),
					PropNodeNamePointer->Property->at(26),
					PropNodeNamePointer->Property->at(27),//20
					PropNodeNamePointer->Property->at(28),
					PropNodeNamePointer->Property->at(29),
					PropNodeNamePointer->Property->at(30),
					PropNodeNamePointer->Property->at(31),
					PropNodeNamePointer->Property->at(32),
					PropNodeNamePointer->Property->at(33),
					PropNodeNamePointer->Property->at(34),
					PropNodeNamePointer->Property->at(35),
					PropNodeNamePointer->Property->at(36),
					PropNodeNamePointer->Property->at(37),//30
					PropNodeNamePointer->Property->at(38),
					PropNodeNamePointer->Property->at(39),
					PropNodeNamePointer->Property->at(40),
					PropNodeNamePointer->Property->at(41),
					PropNodeNamePointer->Property->at(42),
					PropNodeNamePointer->Property->at(43),
					PropNodeNamePointer->Property->at(44),
					PropNodeNamePointer->Property->at(45),
					PropNodeNamePointer->Property->at(46),
					PropNodeNamePointer->Property->at(47),//40
					PropNodeNamePointer->Property->at(48),
					PropNodeNamePointer->Property->at(49),
					PropNodeNamePointer->Property->at(50),
					PropNodeNamePointer->Property->at(51),
					PropNodeNamePointer->Property->at(52),
					PropNodeNamePointer->Property->at(53),
					PropNodeNamePointer->Property->at(54),
					PropNodeNamePointer->Property->at(55),
					PropNodeNamePointer->Property->at(56),
					PropNodeNamePointer->Property->at(57),//50
					PropNodeNamePointer->Property->at(58),
					PropNodeNamePointer->Property->at(59),
					PropNodeNamePointer->Property->at(61),
					PropNodeNamePointer->Property->at(62),
					PropNodeNamePointer->Property->at(63),
					PropNodeNamePointer->Property->at(64),
					PropNodeNamePointer->Property->at(65),
					PropNodeNamePointer->Property->at(66),
					PropNodeNamePointer->Property->at(67),
					PropNodeNamePointer->Property->at(68),//60
					PropNodeNamePointer->Property->at(69),
					PropNodeNamePointer->Property->at(70),
					PropNodeNamePointer->Property->at(71),
					PropNodeNamePointer->Property->at(72),
					PropNodeNamePointer->Property->at(73),
					PropNodeNamePointer->Property->at(74),
					PropNodeNamePointer->Property->at(75),
					PropNodeNamePointer->Property->at(76),
					PropNodeNamePointer->Property->at(77),
					PropNodeNamePointer->Property->at(78),//70
					PropNodeNamePointer->Property->at(79),
					PropNodeNamePointer->Property->at(80),
					PropNodeNamePointer->Property->at(81),
					PropNodeNamePointer->Property->at(82),
					PropNodeNamePointer->Property->at(83),
					PropNodeNamePointer->Property->at(84),
					PropNodeNamePointer->Property->at(85),
					PropNodeNamePointer->Property->at(86),
					PropNodeNamePointer->Property->at(87),
					PropNodeNamePointer->Property->at(88),//80
					PropNodeNamePointer->Property->at(89),
					PropNodeNamePointer->Property->at(90),
					PropNodeNamePointer->Property->at(91),
					PropNodeNamePointer->Property->at(92),
					PropNodeNamePointer->Property->at(93),
					PropNodeNamePointer->Property->at(94),
					PropNodeNamePointer->Property->at(95),
					PropNodeNamePointer->Property->at(96),
					PropNodeNamePointer->Property->at(97),
					PropNodeNamePointer->Property->at(98),//90
					PropNodeNamePointer->Property->at(99),
					PropNodeNamePointer->Property->at(100),
					PropNodeNamePointer->Property->at(101),
					PropNodeNamePointer->Property->at(102),
					PropNodeNamePointer->Property->at(103),
					PropNodeNamePointer->Property->at(104),
					PropNodeNamePointer->Property->at(105),
					PropNodeNamePointer->Property->at(106),
					PropNodeNamePointer->Property->at(107),
					PropNodeNamePointer->Property->at(108),//100
					PropNodeNamePointer->Property->at(109),
					PropNodeNamePointer->Property->at(110),
					PropNodeNamePointer->Property->at(111),
					PropNodeNamePointer->Property->at(112),
					PropNodeNamePointer->Property->at(113),
					PropNodeNamePointer->Property->at(114),
					PropNodeNamePointer->Property->at(115),
					PropNodeNamePointer->Property->at(116),
					PropNodeNamePointer->Property->at(117),
					PropNodeNamePointer->Property->at(118),//110
					PropNodeNamePointer->Property->at(119),
					PropNodeNamePointer->Property->at(120),
						PropNodeNamePointer->Property->at(121),
						PropNodeNamePointer->Property->at(122),
                });
				shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
				shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
				shared_ptr<Node> newGroupNode(new Node{ 2 ,0,true,true,newGroupNodePath,PropNodeNamePointer,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
				PropNodeNamePointer->Group->push_back(newGroupNode);
			}
			break;
		case 3:
			for (int i = PropNodeNamePointer->Group->size(); i > PropNodeNamePointer->Property->at(0); i--) {
				NodeChildSearcher(PropNodeNamePointer->Group->at(i - 1));
				PropNodeNamePointer->Group->erase(PropNodeNamePointer->Group->begin() + i - 1);
			}
			PropNodeNamePointer->Group->shrink_to_fit();
			for (int i = PropNodeNamePointer->Group->size(); i < PropNodeNamePointer->Property->at(0); i++) {
				PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
				shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{
					PropNodeNamePointer->Property->at(1),//0
					PropNodeNamePointer->Property->at(2),
					PropNodeNamePointer->Property->at(4),
					PropNodeNamePointer->Property->at(6),
					PropNodeNamePointer->Property->at(8),
					PropNodeNamePointer->Property->at(10)
					});
				shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
				shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
				shared_ptr<Node> newGroupNode(new Node{ 4 ,0,true,true,newGroupNodePath,PropNodeNamePointer,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
				PropNodeNamePointer->Group->push_back(newGroupNode);
			}
			break;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////

	shared_ptr<vector<shared_ptr<Node>>> Item::MainTextNodeSearcher(shared_ptr<struct Node> Seacher)
	{
		shared_ptr<vector<shared_ptr<Node>>> MainOut(new vector<shared_ptr<Node>>{});
		for (int i = 0; i < Seacher->Child->size(); i++) {
			if (Seacher->Child->at(i) != nullptr) {
				MainOut->emplace_back(Seacher->Child->at(i));
			}
		}
		for (int i = 0; i < Seacher->Group->size(); i++) {
			MainOut->emplace_back(Seacher->Group->at(i));
		}
		return MainOut;
	}
	shared_ptr<vector<int>> Item::MainGraph(int gnum,shared_ptr<Node> selectPointer) {
		int gtypeteller = 0;
		if (selectPointer->NodeType == 1) {
			switch (gnum) {
			case 0:
				gtypeteller = 17;
				break;
			default:
				gtypeteller = 59;
				break;
			};
		}
		else {
			switch (gnum) {
			case 0:
				gtypeteller = 10;
				break;
			default:
				gtypeteller = 52;
				break;
			};
		}
		switch (selectPointer->Property->at(gtypeteller)) {
		case 0:
			return Rmaker(gnum, selectPointer);
			break;
		case 1:
			return Bmaker(gnum, selectPointer);
			break;
		default:
			return Dmaker(gnum, selectPointer);
		};
	}