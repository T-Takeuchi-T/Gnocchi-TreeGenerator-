#include <vector>
#include <windows.h>
#include <memory>

extern void nodetotexttrigger();
extern void camt();
extern void camr();
extern void camf();

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
struct Node {
	int NodeType;//R=0,B=1,b=2,T=3,t=4,F=5
	int NodeNum;//配列からの取得、入力に用いる　増え続ける数字 0~

	bool PropChange;
	bool BirthPChange;
	PTSTR PathString;

	shared_ptr<Node> Parent;
	shared_ptr<vector<int>> Property;/*

									 B->

									 0:group,textureorTwig,rings,shaperadius,Radiusradius,birthplace,birthplacerandmize,Maxlong,Maxlongrandmize,XRotation
									 10:XRotationrandmize,YRotation,YRotationrandmize,ZRotation,ZRotationrandmize,BaseRadius,BaseRadiusRandmize,RadiusGraphtype,Radiusgraphpoint,tgpx0
									 20:tgpx1,tgpx2,tgpx3,tgpx4,tgpx5,tgpx6,tgpx7,tgpx8,tgpx9,tgpx10
									 30:tgpx11,tgpx12,tgpx13,tgpx14,tgpx15,tgpx16,tgpx17,tgpx18,tgpx19,tgpy0
									 40:tgpy1,tgpy2,tgpy3,tgpy4,tgpy5,tgpy6,tgpy7,tgpy8,tgpy9,tgpy10
									 50:tgpy11,tgpy12,tgpy13,tgpy14,tgpy15,tgpy16,tgpy17,tgpy18,tgpy19,shapegraphtype
									 60:shapegraphrandomize,shapegraphpoint,xyzsx0,xyzsx1,xyzsx2,xyzsx3,xyzsx4,xyzsx5,xyzsx6,xyxsx7
									 70:xyzsx8,xyzsx9,xyzsx10,xyzsx11,xyzsx12,xyzsx13,xyzx14,xyxsx15,xyzsx16,xyxsx17
									 80:xyzsx18,xyzsx19,xyzsy0,xyzsy1,xyzsy2,xyzsy3,xyzsy4,xyzsy5,xyzsy6,xyxsy7
									 90:xyzsy8,xyzsy9,xyzsy10,xyzsy11,xyzsy12,xyzsy13,xyzy14,xyxsy15,xyzy16,xyxsy17
									 100:xyzsy18,xyzsy19,xyzsz0,xyzsz1,xyzsz2,xyzsz3,xyzsz4,xyzsz5,xyzsz6,xyxsz7
									 110:xyzsz8,xyzsz9,xyzsz10,xyzsz11,xyzsz12,xyzsz13,xyzz14,xyxsz15,xyzz16,xyxsz17
									 120:xyzsz18,xyzsz19,BaseRadiusGraphRandomize,Fractal

									 b->

									 0:textureorTwig,rings,shaperadius,Radiusradius,birthplace,Maxlong,XRotation,YRotation,ZRotation,BaseRadius
									 10:RadiusGraphtype,Radiusgraphpoint,tgpx0,tgpx1,tgpx2,tgpx3,tgpx4,tgpx5,tgpx6,tgpx7
									 20:tgpx8,tgpx9tgpx10,tgpx11,tgpx12,tgpx13,tgpx14,tgpx15,tgpx16,tgpx17
									 30:tgpx18,tgpx19,tgpy0,tgpy1,tgpy2,tgpy3,tgpy4,tgpy5,tgpy6,tgpy7
									 40:tgpy8,tgpy9,tgpy10,tgpy11,tgpy12,tgpy13,tgpy14,tgpy15,tgpy16,tgpy17
									 50:tgpy18,tgpy19,shapegraphtype,shapegraphpoint,xyzsx0,xyzsx1,xyzsx2,xyzsx3,xyzsx4,xyzsx5
									 60:xyzsx6,xyxsx7,xyzsx8,xyzsx9,xyzsx10,xyzsx11,xyzsx12,xyzsx13,xyzx14,xyxsx15
									 70:xyzsx16,xyxsx17,xyzsx18,xyzsx19,xyzsy0,xyzsy1,xyzsy2,xyzsy3,xyzsy4,xyzsy5
									 80:xyzsy6,xyxsy7,xyzsy8,xyzsy9,xyzsy10,xyzsy11,xyzsy12,xyzsy13,xyzy14,xyxsy15
									 90:xyzy16,xyxsy17,xyzsy18,xyzsy19,xyzsz0,xyzsz1,xyzsz2,xyzsz3,xyzsz4,xyzsz5
									 100:xyzsz6,xyxsz7,xyzsz8,xyzsz9,xyzsz10,xyzsz11,xyzsz12,xyzsz13,xyzz14,xyxsz15
									 110:xyzz16,xyxsz17,xyzsz18,xyzsz19,Fractal

									 T->

									 0:group,textureorTwig,birthplace,birthplacerandmize,Maxlong,Maxlongrandmize,XRotation,XRotationrandmize,YRotation,YRotationrandmize
									 10:ZRotation,ZRotationrandmize

									 t->

									 0:textureorTwig,birthplace,Maxlong,XRotation,YRotation,ZRotation

									 F->

									 0:fractal,fractalrepeat

									 */
	shared_ptr<vector<shared_ptr<Node>>> Child;
	shared_ptr<vector<shared_ptr<Node>>> Group;

	shared_ptr<vector<shared_ptr<Node>>> MainChild;
	vector< vector<double>> divplist;
    vector<double> Radiustoshapelist;
	bool isMCRemoved;
	float truelength;
	float truebaseRadius;
	float fracrate;
};
#pragma once
class Item
{
private:
	//node
	int SelectNodeNum(String^ NodeName);
	void NodeChildSearcher(shared_ptr<struct Node> Seacher);
	
	shared_ptr<struct Node> SelectPointer(String^ NodeName);
	//graph
	int GetExpansionCoefficientInt(int max ,int num);
	shared_ptr<vector<int>>Rmaker(int gnum,shared_ptr<Node> selectPointer);
	shared_ptr<vector<int>>Bmaker(int gnum,shared_ptr<Node> selectPointer);
	shared_ptr<vector<int>>Dmaker(int gnum,shared_ptr<Node> selectPointer);
	//prop
	int GetRandomInt();
	void Randomizer(int pointTeller);
	void Setter(int pointTeller);
	void GroupChanger();
	void PointReset(int pointNumTeller);
	shared_ptr<struct Node> PropNodeNamePointer;

public:
	//勝手にpublic
	
	 shared_ptr<struct Node> RootPointer;
	//node
	int c_num(String^ NodeName);
	void NodeDelete(String^ NodeName);
	void NodeBCreate(String^ NodeName);
	void NodeTCreate(String^ NodeName);
	void NodeFCreate(String^ NodeName);
	void NodeStartRoot();
	//graph
	shared_ptr<vector<int>> Item::RenewGraph(int gnum);
	shared_ptr<vector<int>> Item::GetPoint(int gnum);
	//prop
	int ScrollX;
	int ScrollY;
	int Chart0Point;
	int Chart1Point;
	int Chart2Point;
	int GetPropNodeType();
	int GetValue(int ControlType,String^ ControlName);
	void SetPropNodeName(String^PropNodeName);
	void SetTBValue(int Value,String^ControlName);
	void SetComboBoxValue(int Value, String^ ControlName);
	//----------------------
	shared_ptr<vector<shared_ptr<Node>>>MainTextNodeSearcher(shared_ptr<struct Node> Seacher);
    shared_ptr<vector<int>> MainGraph(int gnum, shared_ptr<Node> selectPointer);
};


