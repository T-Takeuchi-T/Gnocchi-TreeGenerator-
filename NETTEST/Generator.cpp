#include "Generator.h"
#include <vector>
#include <windows.h>
#include <memory>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

int Generator::listItemWGType()
{
    switch (listItemType) {
    case 0:
        return ListItemObjectPointer->WorkType;
        break;
    case 1:
        return ListItemTreePointer->GenType;
        break;
    default:
        return -1;
    }
}

int Generator::GetValue(int ControlType, String^ ControlName)
{
	int navigator = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		navigator = navigator * 10 + a - '0';//char'0'=int 48
	}
	switch (listItemType) {
	case 0:
		switch (listItemWGType()) {
		case 0:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default :
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			default :
				return 0;
				break;
			}
			break;
		case 1:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			default:
				return 0;
				break;
			}
			break;
		case 2:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			default:
				return 0;
				break;
			}
			break;
		default :
			return 0;
			break;
		}
		break;
	case 1:
		switch (listItemWGType()) {
		case 0:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			default:
				return 0;
				break;
			}
			break;
		case 1:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 0:
					return 0;
					break;
				default:
					return 0;
					break;
				}
				break;
			default:
				return 0;
				break;
			}
			break;
		case 2:
			switch (ControlType) {
			case 0:
				switch (navigator) {
				case 0:
					return ListItemTreePointer->GenType;
					break;
				default:
					return 0;
					break;
				}
				break;
			case 1:
				switch (navigator) {
				case 1:
					return ListItemTreePointer->FStrings->at(0);
					break;
				case 3:
					return ListItemTreePointer->XPlace;
					break;
				case 4:
					return ListItemTreePointer->YPlace;
					break;
				case 5:
					return ListItemTreePointer->ZPlace;
					break;
				case 6:
					return ListItemTreePointer->FStrings->at(1);
					break;
				case 7:
					return ListItemTreePointer->FStrings->at(2);
					break;
				case 8:
					return ListItemTreePointer->FStrings->at(3);
					break;
				case 9:
					return ListItemTreePointer->FStrings->at(4);
					break;
				case 10:
					return ListItemTreePointer->FStrings->at(5);
					break;
				case 11:
					return ListItemTreePointer->FStrings->at(6);
					break;
				case 12:
					return ListItemTreePointer->FStrings->at(7);
					break;
				case 13:
					return ListItemTreePointer->FStrings->at(8);
					break;
				case 14:
					return ListItemTreePointer->FStrings->at(9);
					break;
				case 15:
					return ListItemTreePointer->FStrings->at(10);
					break;
				default:
					return 0;
					break;
				}
				break;
			default:
				return 0;
				break;
			}
			break;
		default:
			return 0;
			break;
		}
		break;
	default :
		return 0;
		break;
	}
}

String^ Generator::GetString(String^ ControlName)
{
	int navigator = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		navigator = navigator * 10 + a - '0';//char'0'=int 48
	}
	switch (navigator) {
	case 0:
		return msclr::interop::marshal_as<System::String^>(*(ListItemTreePointer->FString1));
		break;
	case 2:
		return msclr::interop::marshal_as<System::String^>(*(ListItemTreePointer->FString2));
		break;
	default:
		return "";
		break;
	}
}

void Generator::SetUp()
{
	shared_ptr<vector<shared_ptr<ObjectProp>>>setObjectPointers(new vector < shared_ptr<ObjectProp>>());
	shared_ptr<vector<shared_ptr<TreeProp>>>setTreePointers(new vector < shared_ptr<TreeProp>>());
	ListItemObjectPointer=nullptr;
	ListItemTreePointer=nullptr;
	ObjectNum=0;
	TreeNum=0;
	ObjectPointers = setObjectPointers;
	TreePointers = setTreePointers;
}

void Generator::ItemDelete(String^ ItemName)
{
	int navigator = 0;
	for (int i = 0; i < (ItemName->ToCharArray()->Length); i++) {
		char a = ItemName->ToCharArray()[i];
		switch (a) {
		case 'O':
			break;
		case 'T':
			break;
		default:
			navigator = navigator * 10 + a - '0';//char'0'=int 48
			break;
		}
	}
	switch (listItemType) {
	case 0:
		ObjectPointers->at(navigator) = nullptr;
		break;
	case 1:
		TreePointers->at(navigator) = nullptr;
		break;
	}
}

void Generator::ItemDuplicate(String^ ItemName)
{
	int navigator = 0;
	for (int i = 0; i < (ItemName->ToCharArray()->Length); i++) {
		char a = ItemName->ToCharArray()[i];
		switch (a) {
		case 'O':
			break;
		case 'T':
			break;
		default:
			navigator = navigator * 10 + a - '0';//char'0'=int 48
			break;
		}
	}
	switch (listItemType) {
	case 0:
		ObjectDuplicate(navigator);
		break;
	case 1:
		TreeDuplicate(navigator);
		break;
	}
}

void Generator::ObjectDuplicate(int navigator)
{
	shared_ptr<vector<int>>LightProperty(new vector<int>{
		});
	shared_ptr<vector<int>>BlockProperty(new vector<int>{
		});
	shared_ptr<vector<int>>LightBlockProperty(new vector<int>{
		});
	shared_ptr<ObjectProp> newItemO(new ObjectProp{
		ObjectPointers->at(navigator)->WorkType,
		ObjectPointers->at(navigator)->XScale,
		ObjectPointers->at(navigator)->YScale,
		ObjectPointers->at(navigator)->ZScale,
		ObjectPointers->at(navigator)->XPlace,
        ObjectPointers->at(navigator)->YPlace,
        ObjectPointers->at(navigator)->ZPlace,
		LightProperty,BlockProperty,LightBlockProperty });

	ObjectPointers->push_back(newItemO);
}

void Generator::TreeDuplicate(int navigator)
{
	shared_ptr<vector<int>>FullAIProperty(new vector<int>{
		});
	shared_ptr<vector<int>>ShapeAIProperty(new vector<int>{
		});
	shared_ptr<vector<int>>FStringsProperty(new vector<int>{
		TreePointers->at(navigator)->FStrings->at(0),
		TreePointers->at(navigator)->FStrings->at(1), 
		TreePointers->at(navigator)->FStrings->at(2), 
		TreePointers->at(navigator)->FStrings->at(3), 
		TreePointers->at(navigator)->FStrings->at(4), 
		TreePointers->at(navigator)->FStrings->at(5), 
		TreePointers->at(navigator)->FStrings->at(6), 
		TreePointers->at(navigator)->FStrings->at(7), 
		TreePointers->at(navigator)->FStrings->at(8), 
		TreePointers->at(navigator)->FStrings->at(9),
		TreePointers->at(navigator)->FStrings->at(10),
		});
	shared_ptr<string>FString1(new string(*TreePointers->at(navigator)->FString1));
	shared_ptr<string>FString2(new string(*TreePointers->at(navigator)->FString2));
	shared_ptr<TreeProp> newItemT(new TreeProp{
		TreePointers->at(navigator)->GenType, 
		TreePointers->at(navigator)->XPlace,
		TreePointers->at(navigator)->YPlace,
		TreePointers->at(navigator)->ZPlace,
		FullAIProperty,ShapeAIProperty,FStringsProperty,FString1,FString2 });

	TreePointers->push_back(newItemT);
}



void Generator::ObjectCreate()
{
	shared_ptr<vector<int>>LightProperty(new vector<int>{});
	shared_ptr<vector<int>>BlockProperty(new vector<int>{});
	shared_ptr<vector<int>>LightBlockProperty(new vector<int>{});
	shared_ptr<ObjectProp> newItem(new ObjectProp{ 0 ,1,1,1,0,0,0,LightProperty,BlockProperty,LightBlockProperty});

	ObjectPointers->push_back(newItem);
}

void Generator::TreeCreate()
{
	shared_ptr<vector<int>>FullAIProperty(new vector<int>{});
	shared_ptr<vector<int>>ShapeAIProperty(new vector<int>{});
	shared_ptr<vector<int>>FStringsProperty(new vector<int>{1,0,0,0,0,0,0,0,0,0,1});
	shared_ptr<string>FStrings1(new string(""));
	shared_ptr<string>FStrings2(new string(""));
	shared_ptr<TreeProp> newItem(new TreeProp{2,0,0,0,FullAIProperty,ShapeAIProperty,FStringsProperty,FStrings1,FStrings2 });

	TreePointers->push_back(newItem);
}

void Generator::SetString(String^ Value,String^ ControlName)
{
	int navigator = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		navigator = navigator * 10 + a - '0';//char'0'=int 48
	}
	switch (navigator) {
	case 0:
		*(ListItemTreePointer->FString1) = msclr::interop::marshal_as<std::string>(Value);
		break;
	case 2:
		*(ListItemTreePointer->FString2) = msclr::interop::marshal_as<std::string>(Value);
		break;
	}
}

void Generator::SetTBValue(int Value, String^ ControlName)
{
	int navigator = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		navigator = navigator * 10 + a - '0';//char'0'=int 48
	}
	switch (listItemType) {
	case 0:
		switch (listItemWGType()) {
		case 0:
				switch (navigator) {
				case 0:
					break;
				}
				break;
		case 1:
				switch (navigator) {
				case 0:
					break;
				}
				break;
		case 2:
				switch (navigator) {
				case 0:
					break;
				default:
					break;
				}
				break;
		}
		break;
	case 1:
		switch (listItemWGType()) {
		case 0:
				switch (navigator) {
				case 0:
					break;
				}
				break;
		case 1:
				switch (navigator) {
				case 0:
					break;
				}
				break;
		case 2:
				switch (navigator) {
				case 1:
					ListItemTreePointer->FStrings->at(0)=Value;
					break;
				case 3:
					ListItemTreePointer->XPlace = Value;
					break;
				case 4:
					ListItemTreePointer->YPlace = Value;
					break;
				case 5:
					ListItemTreePointer->ZPlace = Value;
					break;
				case 6:
					ListItemTreePointer->FStrings->at(1) = Value;
					break;
				case 7:
					ListItemTreePointer->FStrings->at(2) = Value;
					break;
				case 8:
					ListItemTreePointer->FStrings->at(3) = Value;
					break;
				case 9:
					ListItemTreePointer->FStrings->at(4) = Value;
					break;
				case 10:
					ListItemTreePointer->FStrings->at(5) = Value;
					break;
				case 11:
					ListItemTreePointer->FStrings->at(6) = Value;
					break;
				case 12:
					ListItemTreePointer->FStrings->at(7) = Value;
					break;
				case 13:
					ListItemTreePointer->FStrings->at(8) = Value;
					break;
				case 14:
					ListItemTreePointer->FStrings->at(9) = Value;
					break;
				case 15:
					ListItemTreePointer->FStrings->at(10) = Value;
					break;
				}
				break;
		}
		break;
	}
}

void Generator::SetComboBoxValue(int Value, String^ ControlName)
{

	int navigator = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		navigator = navigator * 10 + a - '0';//char'0'=int 48
	}
	switch (listItemType) {
	case 0:
		switch (listItemWGType()) {
		case 0:
			switch (navigator) {
			case 0:
				break;
			}
			break;
		case 1:
			switch (navigator) {
			case 0:
				break;
			}
			break;
		case 2:
			switch (navigator) {
			case 0:
				break;
			}
			break;
		}
		break;
	case 1:
		switch (listItemWGType()) {
		case 0:
			switch (navigator) {
			case 0:
				break;
			}
			break;
		case 1:
			switch (navigator) {
			case 0:
				break;
			}
			break;
		case 2:
			switch (navigator) {
			case 0:
				ListItemTreePointer->GenType = Value;
				break;
			}
			break;
		}
		break;
	}
}

void Generator::SetListItemPointer(String^ ListItemName)
{
	int navigator=0;
	for (int i = 0; i < (ListItemName->ToCharArray()->Length); i++) {
		char a = ListItemName->ToCharArray()[i];
		switch (a) {
		case 'O':
			break;
		case 'T':
			break;
		default:navigator= navigator* 10 + a - '0';//char'0'=int 48
			break;
		}
	}
	switch (listItemType) {
	case 0:
		ListItemObjectPointer = ObjectPointers->at(navigator);
		break;
	case 1:
		ListItemTreePointer= TreePointers->at(navigator);
		break;
	}
}
