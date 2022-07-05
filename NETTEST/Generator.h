#include <vector>
#include <windows.h>
#include <memory>
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

struct ObjectProp {
	int WorkType;//0->Light,1->Block,2->LightBlock
	int XScale;
	int YScale;
	int ZScale;
	int XPlace;
	int YPlace;
	int ZPlace;
	shared_ptr<vector<int>>Light;
	shared_ptr<vector<int>>Block;
	shared_ptr<vector<int>>LightBlock;
};

struct TreeProp {
	int GenType;//0->FullAI,1->ShapeAI,2->FStrings
	int XPlace;
	int YPlace;
	int ZPlace;
	shared_ptr<vector<int>>FullAI;
	shared_ptr<vector<int>>ShapeAI;
	shared_ptr<vector<int>>FStrings;
	// 0:repeat,zmax,previewrotationx,y,z,golength,rotation,radius,type,fratio
	// 10:manualinput
	shared_ptr<string> FString1;
	shared_ptr<string> FString2;
};

#pragma once
class Generator
{
private:
	shared_ptr<vector<shared_ptr<ObjectProp>>>ObjectPointers;
	shared_ptr<vector<shared_ptr<TreeProp>>>TreePointers;
	shared_ptr<ObjectProp >ListItemObjectPointer;
	shared_ptr<TreeProp >ListItemTreePointer;
public:
	int ScrollX;
	int ScrollY;
	int ObjectNum;
	int TreeNum;
	int listItemType;//0->O,1->T
	int listItemWGType();
	int GetValue(int ControlType, String^ ControlName);//0->CB,1->TB
	String^ GetString(String^ ControlName);
	void SetUp();
	void ItemDelete(String^ ItemName);
	void ItemDuplicate(String^ ItemName);
	void ObjectDuplicate(int navigator);
	void TreeDuplicate(int navigator);
	void ObjectCreate();
	void TreeCreate();
	void SetString(String^ Value,String^ ControlName);
	void SetTBValue(int Value, String^ ControlName);
	void SetComboBoxValue(int Value, String^ ControlName);
	void SetListItemPointer(String^ ListItemName);
};