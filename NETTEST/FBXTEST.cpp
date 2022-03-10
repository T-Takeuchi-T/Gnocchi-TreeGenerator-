#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <string>
#include <algorithm>
#include "Item.h"
#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "glu32.lib" )
#define _USE_MATH_DEFINES
#include<math.h>
#include <vector> 
#include <commctrl.h>
#include <fbxsdk.h>
#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
double campx=0, campy=0, campz=10, campxx = 1, campxy = 0, campxz = 0, campyx = 0, campyy = 1, campyz = 0, campzx = 0, campzy = 0, campzz = 1;
HWND edit[18];
PTSTR roottext,fractaltext;
HWND hwnd;

/*
void rotate(double posx, double posy, double posz, double argx, double argy, double argz, double* outx, double* outy, double* outz) {
	*outy = posy * cos(argx) - posz * sin(argx);
	*outz = posy * sin(argx) + posz * cos(argx);
	*outx = posx * cos(argy) - *outz * sin(argy);
	*outz = posx * sin(argy) + *outz * cos(argy);
	double temp = *outx;
	*outx = temp * cos(argz) - *outy * sin(argz);
	*outy = temp * sin(argz) + *outy * cos(argz);
}*/
void localrotate(double px, double py, double pz, double a, double nx, double ny, double nz, double* ox, double* oy, double* oz) {
	*ox = (px * (cos(a) + ((nx * nx) * (1 - cos(a))))) + (py * ((nx * ny * (1 - cos(a))) - (nz * sin(a)))) + (pz * ((nx * nz * (1 - cos(a))) + (ny * sin(a))));
	*oy = (px * ((nx * ny * (1 - cos(a))) + (nz * sin(a)))) + (py * (cos(a) + ((ny * ny) * (1 - cos(a))))) + (pz * ((ny * nz * (1 - cos(a))) - (nx * sin(a))));
	*oz = (px * ((nx * nz * (1 - cos(a))) - (ny * sin(a)))) + (py * ((ny * nz * (1 - cos(a))) + (nx * sin(a)))) + (pz * ((nz * nz) * (1 - cos(a)) + cos(a)));
	double tmp = sqrt((*ox * *ox) + (*oy * *oy) + (*oz * *oz));
	*ox /= tmp;
	*oy /= tmp;
	*oz /= tmp;
}


void maingraph(vector< vector<double>> v, shared_ptr<Node> node) {
	if (NULL != node->PathString) {
		std::free(node->PathString); node->PathString = NULL;
	}
	node->PathString = (PTSTR)calloc(100000, sizeof(TCHAR));
	PTSTR MainText = node->PathString;
	shared_ptr<vector<int>> graphpoint1 = MainForm::i.MainGraph(1, node);
	shared_ptr<vector<int>>graphpoint2 = MainForm::i.MainGraph(2, node);
	std::vector<double> MainTextx, MainTexty;
	lstrcat(MainText, TEXT("x"));
	lstrcat(MainText, std::to_wstring(node->Property->at(6) / 10000.0).c_str());
	lstrcat(MainText, TEXT("c"));
	lstrcat(MainText, TEXT("y"));
	lstrcat(MainText, std::to_wstring(node->Property->at(7) / 10000.0).c_str());
	lstrcat(MainText, TEXT("c"));
	lstrcat(MainText, TEXT("z"));
	lstrcat(MainText, std::to_wstring(node->Property->at(8) / 10000.0).c_str());
	lstrcat(MainText, TEXT("c"));
	if (node->Property->at(114) == 3)
	{
		lstrcat(MainText, TEXT("l"));
		lstrcat(MainText, std::to_wstring(node->Property->at(9) / 100.0).c_str());
		lstrcat(MainText, TEXT(","));
		lstrcat(MainText, std::to_wstring(node->Property->at(5) / 100.0).c_str());
		lstrcat(MainText, TEXT("c"));
	}
	else
	if (node->Property->at(114) != 1)
	{
		for (int n = 0; n < v.size(); n++) {
			double rotz;
			double fowz;
			double rotx;
			double fowx;
			if (n == 0) {
				rotz = atan2(graphpoint1->at(graphpoint1->at(0) + v[n][0] + 1), graphpoint1->at(v[n][0] + 1)) / M_PI * 180.0;
				fowz = sqrt(pow(graphpoint1->at(graphpoint1->at(0) + v[n][0] + 1), 2) + pow(graphpoint1->at(v[n][0] + 1), 2))* node->truelength;
				rotx = atan2(graphpoint2->at(graphpoint2->at(0) + v[n][0] + 1), graphpoint2->at(v[n][0] + 1)) / M_PI * 180.0;
				fowx = sqrt(pow(graphpoint2->at(graphpoint2->at(0) + v[n][0] + 1), 2) + pow(graphpoint2->at(v[n][0] + 1), 2)) * node->truelength;
			}
			else {
				rotz = atan2(graphpoint1->at(graphpoint1->at(0) + v[n][0] + 1) - graphpoint1->at(graphpoint1->at(0) + v[n - 1][0] + 1), graphpoint1->at(v[n][0] + 1) - graphpoint1->at(v[n - 1][0] + 1)) * 180.0 / M_PI;
				fowz = sqrt(pow(graphpoint1->at(graphpoint1->at(0) + v[n][0] + 1) - graphpoint1->at(graphpoint1->at(0) + v[n - 1][0] + 1), 2) + pow(graphpoint1->at(v[n][0] + 1) - graphpoint1->at(v[n - 1][0] + 1), 2)) * node->truelength;
				rotx = atan2(graphpoint2->at(graphpoint2->at(0) + v[n][0] + 1) - graphpoint2->at(graphpoint2->at(0) + v[n - 1][0] + 1), graphpoint2->at(v[n][0] + 1) - graphpoint2->at(v[n - 1][0] + 1)) * 180.0 / M_PI;
				fowx = sqrt(pow(graphpoint2->at(graphpoint2->at(0) + v[n][0] + 1) - graphpoint2->at(graphpoint2->at(0) + v[n - 1][0] + 1), 2) + pow(graphpoint2->at(v[n][0] + 1) - graphpoint2->at(v[n - 1][0] + 1), 2)) * node->truelength;
			} 
			wstring rotztxt = std::to_wstring(rotz);
			wstring  rotxtxt = std::to_wstring(rotx);
			wstring  fowztxt = std::to_wstring(fowz);
			wstring  fowxtxt = std::to_wstring(fowx);
			wstring rotztxtm = std::to_wstring(-rotz);
			wstring  rotxtxtm = std::to_wstring(-rotx);
			wstring  fowztxtm= std::to_wstring(-fowz);
			wstring  fowxtxtm = std::to_wstring(-fowx);
			lstrcat(MainText, TEXT("z"));
			lstrcat(MainText, rotztxt.c_str());
			lstrcat(MainText, TEXT("ch"));
			lstrcat(MainText, std::to_wstring(v[n][2] / 10000.0 * node->truebaseRadius).c_str());
			lstrcat(MainText, TEXT(","));
			lstrcat(MainText, fowztxt.c_str());
			lstrcat(MainText, TEXT("cz"));
			lstrcat(MainText, rotztxtm.c_str());
			lstrcat(MainText, TEXT("cx"));
			lstrcat(MainText, rotxtxt.c_str());
			if (node->Property->at(114) == 3) {
				lstrcat(MainText, TEXT("cw"));
				lstrcat(MainText, fowxtxt.c_str());
				lstrcat(MainText, TEXT("cz"));
			}
			else {
				lstrcat(MainText, TEXT("ch"));
				lstrcat(MainText, std::to_wstring(v[n][2] / 10000.0 *node->truebaseRadius).c_str());
				lstrcat(MainText, TEXT(","));
				lstrcat(MainText, fowxtxt.c_str());
				lstrcat(MainText, TEXT("cz"));
			}
			lstrcat(MainText, rotztxt.c_str());
			if (n != 0)
				if (v[n][1] == -1) {
					lstrcat(MainText, TEXT("cg"));
					lstrcat(MainText, std::to_wstring(v[n][2] / 10000.0 * node->truebaseRadius).c_str());
					lstrcat(MainText, TEXT("cz"));
		}
			else {
				lstrcat(MainText, TEXT("c"));
					if (node->MainChild->at(v[n][1])->Property->at(114) ==3) {
						lstrcat(MainText, TEXT("s"));
						lstrcat(MainText, TEXT("w"));
						lstrcat(MainText, std::to_wstring(v[n][2] / 10000.0  * node->truebaseRadius).c_str());
						lstrcat(MainText, TEXT("c"));
							}
					else {
						lstrcat(MainText, TEXT("["));
						lstrcat(MainText, std::to_wstring(node->MainChild->at(v[n][1])->Property->at(1)).c_str());
						lstrcat(MainText, TEXT("c"));
				}
				lstrcat(MainText, node->MainChild->at(v[n][1])->PathString);
					if (node->MainChild->at(v[n][1])->Property->at(114) == 3) {
				}
				else {
					lstrcat(MainText, TEXT("],5c"));
				}
				lstrcat(MainText, TEXT("z"));
			}
			lstrcat(MainText, rotztxtm.c_str());
			lstrcat(MainText, TEXT("cx"));
			lstrcat(MainText, rotxtxtm.c_str());
			lstrcat(MainText, TEXT("c"));
		}
		if (node->Property->at(114) == 2) {
			lstrcat(MainText, TEXT("f"));
			lstrcat(MainText, std::to_wstring(node->fracrate).c_str());
			lstrcat(MainText, TEXT("c"));
		}
}else {
		lstrcat(MainText, TEXT("f"));
		lstrcat(MainText, std::to_wstring( node->Property->at(9)/10000.0).c_str());
		lstrcat(MainText, TEXT("c"));
	}
}
void nodetotext(shared_ptr<Node> n) {
	shared_ptr<vector<shared_ptr<Node>>> MainOut = MainForm::i.MainTextNodeSearcher(n);
	switch (n->NodeType)
	{	//R=0,B=1,b=2,T=3,t=4,F=5
	case 0: {
		n->PathString = (PTSTR)calloc(100000, sizeof(TCHAR));
		PTSTR MainText = n->PathString;
		for (int i = 0; i < MainOut->size(); i++) {
			if (MainOut->at(i)->NodeType == 1) {
				for (int ii = 0; ii < MainOut->at(i)->Group->size(); ii++) {
					MainOut->at(i)->Group->at(ii)->truelength = n->truelength / 10000.0 * MainOut->at(i)->Group->at(ii)->Property->at(5);
					MainOut->at(i)->Group->at(ii)->truebaseRadius = n->truebaseRadius / 10000.0 * MainOut->at(i)->Group->at(ii)->Property->at(9);
			lstrcat(MainText, TEXT("["));
			lstrcat(MainText, std::to_wstring(MainOut->at(i)->Group->at(ii)->Property->at(1)).c_str());
			lstrcat(MainText, TEXT("c"));
			lstrcat(MainText, MainOut->at(i)->Group->at(ii)->PathString);
			lstrcat(MainText, TEXT("],5c"));
				}
				nodetotext(MainOut->at(i));
			}
		}		
		break; }
	case 1:
	{//B
		int bcount=0;
		
		for (int i = MainOut->size() - 1; i > -1; i--) 
		{
			switch (MainOut->at(i)->NodeType)
			{
			case 1: {
				//B Child ☞ b MainChild
				if(bcount!=0)
				for (int ii =0; ii < MainOut->at(i)->Group->size(); ii++) {
					MainOut->at(MainOut->size()-1-ii% bcount)->MainChild->emplace_back(MainOut->at(i)->Group->at(ii));
					MainOut->at(i)->Group->at(ii)->truelength = MainOut->at(MainOut->size()-1-ii% bcount)->truelength / 10000.0 * MainOut->at(i)->Group->at(ii) ->Property->at(5);
				}
				break; }
			case 2: {
				bcount++;
				if (!MainOut->at(i)->isMCRemoved) {
					shared_ptr<vector<shared_ptr<Node>>> tmpv(new vector<shared_ptr<Node>>{});
					MainOut->at(i)->MainChild = tmpv;
					MainOut->at(i)->isMCRemoved = true;
				}
				break; }
			}
		}

		for (int i = 0; i < MainOut->size(); i++) {
			nodetotext(MainOut->at(i));
		}
		break;
	}
	case 2:
	{//b
		for (int i = 0; i < MainOut->size(); i++) {
			if (MainOut->at(i)->NodeType == 1) {
				nodetotext(MainOut->at(i));
				for (int ii = 0; ii < MainOut->at(i)->Group->size(); ii++) {
					n->MainChild->emplace_back(MainOut->at(i)->Group->at(ii));
					MainOut->at(i)->Group->at(ii)->truelength = n->truelength / 10000.0 * MainOut->at(i)->Group->at(ii)->Property->at(5);
				}
			}
		}
		n->isMCRemoved = false;
		vector< vector<double>> bpdiv(0, vector<double>(3));
		vector< vector<double>> divp(0, vector<double>(2));
		vector<double>Radiustoshape;
		for (int i = 0; i < n->MainChild->size(); i++) {
			vector<double> tmpv;
			if (n->MainChild->at(i)->Property->at(4) > 10000) {
				tmpv = { 1, (double)i };
			}
			else
			{
				if (n->MainChild->at(i)->Property->at(4) < 0)
				{
					tmpv = { 0, (double)i };
				}
				else {
					tmpv = { n->MainChild->at(i)->Property->at(4) / 10000.0,  (double)i };
				}
			}
			bpdiv.emplace_back(tmpv);
			OutputDebugString(L"\nTMPchild num:");
			OutputDebugString(std::to_wstring(i).c_str());
			OutputDebugString(L" bp:");
			OutputDebugString(std::to_wstring(n->MainChild->at(i)->Property->at(4)).c_str());
		}
		std::sort(bpdiv.begin(), bpdiv.end(), [](const vector<double>& alpha, const vector<double>& beta) {return alpha[0] < beta[0]; });
		shared_ptr<vector<int>> graphpoint0 = MainForm::i.MainGraph(0, n);
		shared_ptr<vector<int>> graphpoint1 = MainForm::i.MainGraph(1, n);
		shared_ptr<vector<int>> graphpoint2 = MainForm::i.MainGraph(2, n);
		double sum = 0;
		for (int n = 1; n < graphpoint1->at(0); n++) {
			float b1 = (graphpoint1->at(graphpoint1->at(0) + n) - graphpoint1->at(graphpoint1->at(0) + n + 1));
			float b2 = (graphpoint1->at(n) - graphpoint1->at(n + 1));
			float b3 = (graphpoint2->at(graphpoint2->at(0) + n) - graphpoint2->at(graphpoint2->at(0) + n + 1));
			sum += sqrt((b1 * b1) + (b2 * b2) + (b3 * b3));
		}
		double sum2 = 0;
		int tmpn = 0, bpnum = 0;
		for (int n = 1; n < graphpoint1->at(0); n++) {
			vector<double> tmpv;
			float b1 = (graphpoint1->at(graphpoint1->at(0) + n) - graphpoint1->at(graphpoint1->at(0) + n + 1));
			float b2 = (graphpoint1->at(n) - graphpoint1->at(n + 1));
			float b3 = (graphpoint2->at(graphpoint2->at(0) + n) - graphpoint2->at(graphpoint2->at(0) + n + 1));
			sum2 += sqrt((b1 * b1) + (b2 * b2) + (b3 * b3));
			for (; sum2 > sum / 50 * tmpn; tmpn++) {

			}
			while (bpnum < bpdiv.size() && sum2 >= sum * bpdiv[bpnum][0]) {
				tmpv = { (double)tmpn ,bpdiv[bpnum][1] };
				bpdiv[bpnum] = tmpv;
				bpnum++;
			}
		}
		if(n->PropChange) {
			n->PropChange = false; 
		OutputDebugString(L"\n-b BEGIN-\n");
		vector< vector<double>> shapediv(0, vector<double>(2));
		vector< vector<double>> Radiuspriority(0, vector<double>(2));
		vector< vector<double>> shapepriority(0, vector<double>(2));
		n->fracrate = graphpoint0->at(101) / (double)graphpoint0->at(51);
		for (int n = 1; n < graphpoint0->at(0); n++) {
			if (n == 1) {
				vector<double> tmpv = { abs(atan2(graphpoint0->at(graphpoint0->at(0) + n + 1) - graphpoint0->at(graphpoint0->at(0) + n), graphpoint1->at(n + 1))),(double)n };
				Radiuspriority.emplace_back(tmpv);
			}
			else {
				vector<double> tmpv = { abs(atan2(graphpoint0->at(graphpoint0->at(0) + n + 1) - graphpoint0->at(graphpoint0->at(0) + n), graphpoint1->at(n + 1) - graphpoint1->at(n)) - atan2(graphpoint1->at(graphpoint1->at(0) + n) - graphpoint1->at(graphpoint1->at(0) + n - 1), graphpoint1->at(n) - graphpoint1->at(n - 1))),(double)n };
				Radiuspriority.emplace_back(tmpv);
			}
		}
		for (int n = 1; n < graphpoint1->at(0) - 1; n++) {
			vector<double> tmpv;
			float a1 = (graphpoint1->at(graphpoint1->at(0) + n + 2) - graphpoint1->at(graphpoint1->at(0) + n + 1));
			float b1 = (graphpoint1->at(graphpoint1->at(0) + n) - graphpoint1->at(graphpoint1->at(0) + n + 1));
			float a2 = (graphpoint1->at(n + 2) - graphpoint1->at(n + 1));
			float b2 = (graphpoint1->at(n) - graphpoint1->at(n + 1));
			float a3 = (graphpoint2->at(graphpoint2->at(0) + n + 2) - graphpoint2->at(graphpoint2->at(0) + n + 1));
			float b3 = (graphpoint2->at(graphpoint2->at(0) + n) - graphpoint2->at(graphpoint2->at(0) + n + 1));
			tmpv = {
				((a1 * b1) + (a2 * b2) + (a3 * b3)) / (sqrt((a1 * a1) + (a2 * a2) + (a3 * a3)) * sqrt((b1 * b1) + (b2 * b2) + (b3 * b3)))
			 ,(double)n };
			shapepriority.emplace_back(tmpv);
		}
		double sum2 = 0;
		int tmpn = 0;
		Radiustoshape.emplace_back(graphpoint0->at(graphpoint0->at(0) + 1));
		for (int n = 1; n < graphpoint1->at(0); n++) {
			vector<double> tmpv;
			float b1 = (graphpoint1->at(graphpoint1->at(0) + n) - graphpoint1->at(graphpoint1->at(0) + n + 1));
			float b2 = (graphpoint1->at(n) - graphpoint1->at(n + 1));
			float b3 = (graphpoint2->at(graphpoint2->at(0) + n) - graphpoint2->at(graphpoint2->at(0) + n + 1));
			sum2 += sqrt((b1 * b1) + (b2 * b2) + (b3 * b3));
			for (; sum2 > sum / 50 * tmpn; tmpn++) {
				Radiustoshape.emplace_back(graphpoint0->at(graphpoint0->at(0) + tmpn + 1));
				if (n < 50) {
					tmpv = { Radiuspriority[n][0] ,(double)tmpn };
					Radiuspriority[n] = tmpv;
				}
			}
		}

		std::sort(Radiuspriority.begin(), Radiuspriority.end(), [](const vector<double>& alpha, const vector<double>& beta) {return alpha[0] < beta[0]; });
		std::sort(shapepriority.begin(), shapepriority.end(), [](const vector<double>& alpha, const vector<double>& beta) {return alpha[0] > beta[0]; });


		for (int i = 0; i < n->Property->at(3) - 2; i++) {
			vector<double> tmpv = { Radiuspriority[i][1] ,-1 ,Radiustoshape[Radiuspriority[i][1]] };
			divp.emplace_back(tmpv);
		}
		for (int i = 0; i < n->Property->at(2) - 2; i++) {
			vector<double> tmpv = { shapepriority[i][1] ,-1 ,Radiustoshape[shapepriority[i][1]] };
			divp.emplace_back(tmpv);
		}
		vector<double> tmpv = { 0 ,-1,Radiustoshape[0] };
		divp.emplace_back(tmpv);
		tmpv = { 50 ,-1 ,Radiustoshape[50] };
		divp.emplace_back(tmpv);

		sort(divp.begin(), divp.end(), [](const vector<double>& alpha, const vector<double>& beta) {return alpha[0] < beta[0]; });
		for (int i = 1; i < divp.size(); i++) {
			if (divp[i][0] == divp[i - 1][0])
				divp.erase(divp.begin() + i);
		}
		n->divplist = divp;
		n->Radiustoshapelist = Radiustoshape; }
		divp = n->divplist;
		Radiustoshape = n->Radiustoshapelist;
		for (int i = 0; i < bpdiv.size(); i++) {
			vector<double> tmpv;
			if (n->MainChild->at(bpdiv[i][1])->Property->at(4) > 10000) {
				tmpv = { 50, (double)bpdiv[i][1],Radiustoshape[bpdiv[i][0]] / 10000.0 };
			}
			else
			{
				if (n->MainChild->at(bpdiv[i][1])->Property->at(4) < 0)
				{
					tmpv = { 0, (double)bpdiv[i][1],Radiustoshape[bpdiv[i][0]]/ 10000.0 };
				}
				else {
					tmpv = { bpdiv[i][0],(double)bpdiv[i][1],Radiustoshape[bpdiv[i][0]] /10000.0 };
				}
		}	
			n->MainChild->at(bpdiv[i][1])->truebaseRadius = n->truebaseRadius * Radiustoshape[bpdiv[i][0]] * n->MainChild->at(bpdiv[i][1])->Property->at(9) / 100000000.0;

				bpdiv[i]=tmpv;
			}
			divp.insert(divp.end(), bpdiv.begin(), bpdiv.end());
			sort(divp.begin(), divp.end(), [](const vector<double>& alpha, const vector<double>& beta) {return alpha[0] < beta[0]; });
			maingraph(divp, n);
		//}
		break;
	}
	}
}
void nodetotexttrigger() {
	std::free(roottext);
	nodetotext(MainForm::i.RootPointer);
	roottext = MainForm::i.RootPointer->PathString;
	fractaltext= MainForm::i.RootPointer->Child->at(0)->Group->at(0)->PathString;
	if (SendMessage(edit[17], TBM_GETPOS, 0, 0)) {
		SetWindowText(edit[0],roottext);
		SetWindowText(edit[2], fractaltext);
	}else{
		SetWindowText(edit[0], L"");
	}
}
bool loadbmp(GLuint texture, char* name)
{
	unsigned long sizeX;
	unsigned long sizeY;
	char* Data;
	FILE* File;
	unsigned long size;
	unsigned long i;
	unsigned short int planes;
	unsigned short int bpp;
	char tmp;
	if ((File = fopen(name, "rb")) == NULL) {
		OutputDebugStringW(L"ファイルがありません");
		return false;
	}
	fseek(File, 18, SEEK_CUR);
	if ((i = fread(&sizeX, 4, 1, File)) != 1) {
		OutputDebugStringW(L"読み込みエラー");
		return false;
	}
	if ((i = fread(&sizeY, 4, 1, File)) != 1) {
		OutputDebugStringW(L"読み込みエラー");
		return false;
	}
	size = sizeX * sizeY * 4;
	if ((fread(&planes, 2, 1, File)) != 1) {   //bmp->1
		OutputDebugStringW(L"プレーン数が読み込めません");
		return false;
	}
	if (planes != 1) {
		OutputDebugStringW(L"プレーン数が1以外です");
		return false;
	}
	if ((i = fread(&bpp, 2, 1, File)) != 1) {
		OutputDebugStringW(L"ビット数が読めません");
		return false;
	}
	if (bpp != 32) {
		OutputDebugStringW(L"32ビット画像ではありません");
		return false;
	}
	//92bitskip
	fseek(File, 92, SEEK_CUR);
	Data = (char*)malloc(size);
	if (Data == NULL) {
		OutputDebugStringW(L"メモリが確保できません");
		return false;
	}
	if ((i = fread(Data, size, 1, File)) != 1) {
		OutputDebugStringW(L"データが読めません");
		return false;
	}
	for (i = 0; i < size; i += 4) {//bgr -> rgb
		tmp = Data[i];
		Data[i] = Data[i + 2];
		Data[i + 2] = tmp;
	}
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, sizeX, sizeY, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glAlphaFunc(GL_GREATER, 0.5);
	std::free(Data);
	fclose(File);
	return true;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

	static PTSTR  outText;
	std::vector<double> memx, memy, memz, memxx, memxy, memxz, memyx, memyy, memyz, memzx, memzy, memzz, memv, membx, memby, membz,meme,fracmemrate;
	std::vector<bool>memr;
	static std::vector<double>  vx, vy, vz, p,uv,m;
	std::vector<POINT> pos;
	int mem = 0, fractalmem = 0; double fracrate=1;
	static int vnum = 0, pnum = 0;
	static double defx, defy, defz;

	HDC hdc;
	PAINTSTRUCT ps;
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case    WM_COMMAND:
	case	WM_HSCROLL:
	{
		if ((HWND)lp == edit[16])
	{
		FbxManager* manager = FbxManager::Create();

		FbxScene* scene = FbxScene::Create(manager, "");


		FbxImporter* importer = FbxImporter::Create(manager, "");

		importer->Initialize("fbxin.fbx", -1, manager->GetIOSettings());

		importer->Import(scene);


		importer->Destroy();

		FbxGeometryConverter geometry_converter(manager);
		geometry_converter.Triangulate(scene, true);

		FbxMesh* mesh = scene->GetSrcObject<FbxMesh>();
		FbxVector4* cp = mesh->GetControlPoints();
		int cpl = mesh->GetControlPointsCount();
		std::vector<double> vx ,vy,vz ;
		for (int i = 0; i < cpl;  i++) {
			vx.emplace_back(cp[i][0]);
			vy.emplace_back(cp[i][1]);
			vz.emplace_back(cp[i][2]);
		}
		int* p=mesh->GetPolygonVertices();
		int pl= mesh->GetPolygonVertexCount();
		/// 
				//メイン描画
		PictureBox^ pictureBox1 = MainForm ::MyForm::pictureBox1;
		Bitmap^ bmpPicBox;
		Graphics^ g;
		HDC oh;
		int format;
		HGLRC glRC;
		GLuint tex[2];
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1,                   
				PFD_DRAW_TO_WINDOW |   
				PFD_SUPPORT_OPENGL | 
				PFD_DOUBLEBUFFER,     
				PFD_TYPE_RGBA,        
				32,                  
				0, 0, 0, 0, 0, 0,    
				0,                   
				0,                    
				0,                  
				0, 0, 0, 0,         
				32,                   
				0,                   
				0,                    
				PFD_MAIN_PLANE,         
				0,                   
				0, 0, 0                
			};
			oh = GetDC(((HWND)pictureBox1->Handle.ToInt32()));
			format = ChoosePixelFormat(oh, &pfd);
			SetPixelFormat(oh, format, &pfd);
			glRC = wglCreateContext(oh);
			wglMakeCurrent(oh, glRC);
			glClearColor(0.375f, 0.375f, 0.375f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_ALPHA_TEST);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);

				glViewport(0, 0, pictureBox1->Width, pictureBox1->Height);

				glMatrixMode(GL_PROJECTION);		
				glLoadIdentity();						
				gluPerspective(60.0, (double)pictureBox1->Width / pictureBox1->Height, 1.0, 2000.0);
	
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				gluLookAt(campx, campy, campz, campx + campzx, campy + campzy, campz + campzz, 0.0, campyy, 0.0);
			
			glBegin(GL_LINES);
			glColor3d(1, 1, 1);
			for (int x = -500; x <= 500; x += 10) {
				glVertex3f(x, 0, 500);
				glVertex3f(x, 0, -500);
				glVertex3f(500, 0, x);
				glVertex3f(-500, 0, x);
			}
			glEnd();
			glEnable(GL_TEXTURE_2D);
				glBegin(GL_TRIANGLES);

				for (int i = 0; i < pl; i++) {
					glColor3d(vx[p[i]] / 50, -vy[p[i]] / 50, vz[p[i]] / 50);
					if (i % 3 == 0) {
						double d = sqrt(((((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]]))) * (((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]]))))
							+ ((((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]]))) * (((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]]))))
							+ ((((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]]))) * (((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])))));
						glNormal3d((((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]]))) / d,
							(((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]]))) / d,
							(((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]]))) / d);
					}
					glVertex3d(vx[p[i]], -vy[p[i]], vz[p[i]]);
				}

		//OGL  OWARI
			glDisable(GL_TEXTURE_2D);
			glEnd();
			glFlush();
			SwapBuffers(oh);
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(glRC);
		/// 
		scene->Destroy();
		manager->Destroy();
		//import owari
		}
		else
		{
			if ((HWND)lp == edit[15])
		{

			FbxManager* fbxmanager = FbxManager::Create();
		FbxIOSettings* ios_settings = FbxIOSettings::Create(fbxmanager, IOSROOT);
			//ios_settings->SetBoolProp(EXP_ASCIIFBX, true);
		fbxmanager->SetIOSettings(ios_settings);

			FbxScene* fbxscene = FbxScene::Create(fbxmanager, "");
			fbxsdk::FbxNode* root = fbxscene->GetRootNode();
			fbxsdk::FbxNode* child = fbxsdk::FbxNode::Create(fbxscene, "child");
			FbxMesh* pMesh = FbxMesh::Create(fbxscene, "mesh");
			
		fbxsdk::FbxGeometryElementUV* lUVElement = pMesh->CreateElementUV("uv");

			lUVElement->SetMappingMode(FbxGeometryElement::eByPolygonVertex);
			lUVElement->SetReferenceMode(FbxGeometryElement::eDirect);
			lUVElement->GetDirectArray().Resize(pnum);
			for (int lUVIndex = 0; lUVIndex < pnum; lUVIndex++)
			{
				FbxVector2 lUV(uv[2 * lUVIndex], uv[2 * lUVIndex + 1]);
				lUVElement->GetDirectArray().SetAt(lUVIndex, lUV);
			}
			//pMesh->GenerateNormals(true,true,false);
			child->AddNodeAttribute(pMesh);
			root->AddChild(child);
			fbxsdk::FbxLayer* lLayer = pMesh->GetLayer(0);
			fbxsdk::FbxLayerElementMaterial* lLayerElementMaterial = fbxsdk::FbxLayerElementMaterial::Create(pMesh, "");
			lLayerElementMaterial->SetMappingMode(fbxsdk::FbxLayerElement::eByPolygon);
			lLayerElementMaterial->SetReferenceMode(fbxsdk::FbxLayerElement::eIndexToDirect);
			lLayer->SetMaterials(lLayerElementMaterial);
			
		
			for (int i = 0; i < 2; i++) {
				FbxSurfacePhong* lMaterial = NULL;
				FbxString lMaterialName = "toto";
				FbxString lShadingName = "Phong";
				FbxDouble3 lBlack(0.0, 0.0, 0.0);
				FbxDouble3 lRed(1.0, 0.0, 0.0);
				FbxDouble3 lDiffuseColor(0, 0, 0.0);
				lMaterial = FbxSurfacePhong::Create(fbxscene, lMaterialName.Buffer());
				fbxsdk::FbxNode* lNode = pMesh->GetNode();
				lMaterial->Emissive.Set(lBlack);
				lMaterial->Ambient.Set(lRed);
				lMaterial->AmbientFactor.Set(1.);
				lMaterial->Diffuse.Set(lDiffuseColor);
				lMaterial->DiffuseFactor.Set(1.);
				lMaterial->TransparencyFactor.Set(0.4);
				lMaterial->ShadingModel.Set(lShadingName);
				lMaterial->Shininess.Set(0.5);
				lMaterial->Specular.Set(lBlack);
				lMaterial->SpecularFactor.Set(0.3);
				lNode->AddMaterial(lMaterial);


				FbxFileTexture* lTexture = FbxFileTexture::Create(fbxscene, "Diffuse Texture");

				if(i)
				lTexture->SetFileName("bmp.bmp");
				else
					lTexture->SetFileName("bmp2.bmp");
				lTexture->SetTextureUse(FbxTexture::eStandard);
				lTexture->SetMappingType(FbxTexture::eUV);
				lTexture->SetMaterialUse(FbxFileTexture::eModelMaterial);
				lTexture->SetSwapUV(false);
				lTexture->SetTranslation(0.0, 0.0);
				lTexture->SetScale(1.0, 1.0);
				lTexture->SetRotation(0.0, 0.0);

				lMaterial->Diffuse.ConnectSrcObject(lTexture);

				lTexture = FbxFileTexture::Create(fbxscene, "Ambient Texture");
				/*
				lTexture->SetFileName("bmp.bmp");
				lTexture->SetTextureUse(FbxTexture::eStandard);
				lTexture->SetMappingType(FbxTexture::eUV);
				lTexture->SetMaterialUse(FbxFileTexture::eModelMaterial);
				lTexture->SetSwapUV(false);
				lTexture->SetTranslation(0.0, 0.0);
				lTexture->SetScale(1.0, 1.0);
				lTexture->SetRotation(0.0, 0.0);

				lMaterial->Ambient.ConnectSrcObject(lTexture);

				lTexture = FbxFileTexture::Create(fbxscene, "Emissive Texture");

				lTexture->SetTextureUse(FbxTexture::eStandard);
				lTexture->SetMappingType(FbxTexture::eUV);
				lTexture->SetMaterialUse(FbxFileTexture::eModelMaterial);
				lTexture->SetSwapUV(false);
				lTexture->SetTranslation(0.0, 0.0);
				lTexture->SetScale(1.0, 1.0);
				lTexture->SetRotation(0.0, 0.0);
					lMaterial->Emissive.ConnectSrcObject(lTexture);

				// /////
					// lNode = pMesh->GetNode();
				*/
			}
			pMesh->InitControlPoints(vnum);
			FbxVector4* pCtrlPoint = pMesh->GetControlPoints();
			for (int i = 0; i < vnum; i++) {
				pCtrlPoint[i] = FbxVector4(vx[i] - defx, -vy[i] + defy, vz[i] - defz);
			}
			for (int i = 0; i < pnum;) {
				pMesh->BeginPolygon(1-m[i/3]);
				pMesh->AddPolygon(p[i]);
				i++;
				pMesh->AddPolygon(p[i]);
				i++;
				pMesh->AddPolygon(p[i]);
				i++;
				pMesh->EndPolygon();
			}
			pMesh->GenerateNormals(false, false,false);
	
	
			const char* fbx_path = "fbxout.fbx";

			FbxExporter* fbxexporter = FbxExporter::Create(fbxmanager, "");

			fbxexporter->Initialize(fbx_path, -1, fbxmanager->GetIOSettings());

			fbxexporter->Export(fbxscene);
		}
		else
		{
			if ((HWND)lp == edit[0] || (HWND)lp == edit[1] || (HWND)lp == edit[2]) {
				PTSTR strText,strText2;
				PTSTR inText = (PTSTR)calloc(100000, sizeof(TCHAR));
				if(SendMessage(edit[17], TBM_GETPOS, 0, 0)){
					strText = (PTSTR)calloc((GetWindowTextLength(edit[0]) + 1), sizeof(TCHAR));
					strText2 = (PTSTR)calloc((GetWindowTextLength(edit[2]) + 1), sizeof(TCHAR));
					GetWindowText(edit[0], strText, (GetWindowTextLength(edit[0]) + 1));
					GetWindowText(edit[2], strText2, (GetWindowTextLength(edit[2]) + 1));
				}
				else {
					strText = roottext;
					strText2 = fractaltext;
				}
				lstrcat(inText, strText);
				int rep= SendMessage(edit[1], TBM_GETPOS, 0, 0);
				for (int i = 1; i <= rep; i++) {
					std::free(outText);
					outText = (PTSTR)calloc(100000, sizeof(TCHAR));
					int tmp = lstrlen(inText);
					int tmplen = 0;
					for (int i = 0; i < tmp; i++) {
						switch (inText[i]) {
						case 'f': {
							memcpy(outText + i + tmplen, L"{", 1); tmplen++;
							PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
							while (inText[i] != 'c' && i < tmp) {
								i++;
								switch (inText[i]) {
								case '.':
									lstrcat(num, TEXT("."));
									break;
								case '1':
									lstrcat(num, TEXT("1"));
									break;
								case '2':
									lstrcat(num, TEXT("2"));
									break;
								case '3':
									lstrcat(num, TEXT("3"));
									break;
								case '4':
									lstrcat(num, TEXT("4"));
									break;
								case '5':
									lstrcat(num, TEXT("5"));
									break;
								case '6':
									lstrcat(num, TEXT("6"));
									break;
								case '7':
									lstrcat(num, TEXT("7"));
									break;
								case '8':
									lstrcat(num, TEXT("8"));
									break;
								case '9':
									lstrcat(num, TEXT("9"));
									break;
								case '0':
									lstrcat(num, TEXT("0"));
									break;
								}
							}
							lstrcat(outText, num); i--;
							std::free(num);
							memcpy(outText + i + tmplen, L"c", 1); i++;
							lstrcat(outText, strText2); tmplen += lstrlen(strText2);
							memcpy(outText + i + tmplen, L"}", 1); 
							break;
						}
						case 'g':
							memcpy(outText + i + tmplen, L"g", 1);
							break;
						case '[':
							memcpy(outText + i + tmplen, L"[", 1);
							break;
						case ']':
							memcpy(outText + i + tmplen, L"]", 1);
							break;
						case 'x':
							memcpy(outText + i + tmplen, L"x", 1);
							break;
						case 'y':
							memcpy(outText + i + tmplen, L"y", 1);
							break;
						case 'z':
							memcpy(outText + i + tmplen, L"z", 1);
							break;
						case 'h':
							memcpy(outText + i + tmplen, L"h", 1);
							break;
						case 'c':
							memcpy(outText + i + tmplen, L"c", 1);
							break;
						case '-':
							memcpy(outText + i + tmplen, L"-", 1);
							break;
						case '.':
							memcpy(outText + i + tmplen, L".", 1);
							break;
						case ',':
							memcpy(outText + i + tmplen, L",", 1);
							break;
						case '1':
							memcpy(outText + i + tmplen, L"1", 1);
							break;
						case '2':
							memcpy(outText + i + tmplen, L"2", 1);
							break;
						case '3':
							memcpy(outText + i + tmplen, L"3", 1);
							break;
						case '4':
							memcpy(outText + i + tmplen, L"4", 1);
							break;
						case '5':
							memcpy(outText + i + tmplen, L"5", 1);
							break;
						case '6':
							memcpy(outText + i + tmplen, L"6", 1);
							break;
						case '7':
							memcpy(outText + i + tmplen, L"7", 1);
							break;
						case '8':
							memcpy(outText + i + tmplen, L"8", 1);
							break;
						case '9':
							memcpy(outText + i + tmplen, L"9", 1);
							break;
						case '0':
							memcpy(outText + i + tmplen, L"0", 1);
							break;
						case 's':
							memcpy(outText + i + tmplen, L"s", 1);
							break;
						case 'l':
							memcpy(outText + i + tmplen, L"l", 1);
							break;
						case 'w':
							memcpy(outText + i + tmplen, L"w", 1);
							break;
						case '{':
							memcpy(outText + i + tmplen, L"{", 1);
							break;
						case '}':
							memcpy(outText + i + tmplen, L"}", 1);
							break;
						}
					}
					std::free(inText);
					inText = (PTSTR)calloc(100000, sizeof(TCHAR));
					lstrcat(inText, outText);

				}
				if (SendMessage(edit[17], TBM_GETPOS, 0, 0)) {
					std::free(strText);
					std::free(strText2);
				}
				std::free(inText);
			}
			if ((HWND)lp == edit[0] || (HWND)lp == edit[1] || (HWND)lp == edit[2] || (HWND)lp == edit[3] || (HWND)lp == edit[4] || (HWND)lp == edit[5] || (HWND)lp == edit[6] || (HWND)lp == edit[10] || (HWND)lp == edit[11] || (HWND)lp == edit[12] || (HWND)lp == edit[13] || (HWND)lp == edit[14]) {
				vx.clear();
				vy.clear();
				vz.clear();
				p.clear();
				m.clear();
				uv.clear();
				vnum = 0;
				pnum = 0;
				double x;
				double y;
				double z;
				double localxx = 1;
				double localxy = 0;
				double localxz = 0;
				double localyx = 0;
				double localyy = -1;
				double localyz = 0;
				double localzx = 0;
				double localzy = 0;
				double localzz = 1;
				defx = SendMessage(edit[3], TBM_GETPOS, 0, 0);
				defy = SendMessage(edit[4], TBM_GETPOS, 0, 0);
				defz = SendMessage(edit[5], TBM_GETPOS, 0, 0);
				double zmax = SendMessage(edit[6], TBM_GETPOS, 0, 0);
				double fow = SendMessage(edit[10], TBM_GETPOS, 0, 0) / 100.0;
				double rotarg = SendMessage(edit[11], TBM_GETPOS, 0, 0) / 100.0;
				double r = SendMessage(edit[12], TBM_GETPOS, 0, 0) / 100.0;
				double s = SendMessage(edit[14], TBM_GETPOS, 0, 0) / 100.0;
				int d = SendMessage(edit[13], TBM_GETPOS, 0, 0);
				memr.emplace_back(1);
				memv.emplace_back(0);	
				meme.emplace_back(3);
				x = defx;
				y = defy;
				z = defz;
				membx.emplace_back(0);
				memby.emplace_back(0);
				membz.emplace_back(0);
				int olen =lstrlen(outText);
				for (int i = 0; i < olen; i++) {
					switch (outText[i]) {
					case '{':
					{
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL); std::free(num);
						fractalmem++;
						fracmemrate.emplace_back(c);
						fracrate *= c;
						break;
					}
					case '}':
					{
						fractalmem--;
						fracrate /= fracmemrate[fractalmem];
						fracmemrate.pop_back();
						break; }
					case 'h':
					{
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != ',' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c2 = wcstod(num, NULL); std::free(num);
						num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);

					
						if (memr[mem]) {
							membx[mem] = x;
							memby[mem] = y;
							membz[mem] = z;
							memr[mem] = false;
							if (d % 2) {
								//最初p+z
								vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
								vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
								vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
								vnum++;
								//最終p+z60do
								for (int i = 0; i < meme[mem] - 1; ++i) {
									localrotate(localzx, localzy, localzz, M_PI / (meme[mem] / 2), localyx, localyy, localyz, &localzx, &localzy, &localzz);
									vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
									vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
									vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
									vnum++;
								}
								localrotate(localzx, localzy, localzz, -M_PI / (meme[mem] / 2) * (meme[mem] - 1), localyx, localyy, localyz, &localzx, &localzy, &localzz);

								for (int i = 0; i < memv.size() - 1; ++i)
									memv[i] += meme[mem];
							}
						}
						x += c * fow * fracrate * localyx;
						y += c * fow * fracrate * localyy;
						z += c * fow * fracrate * localyz;
						break;
					}
					case 'w': {
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);
						x += c * fow * fracrate * localyx;
						y += c * fow * fracrate * localyy;
						z += c * fow * fracrate * localyz;
						break;
					}
					case 'g': {
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);
					
						if (d % 2) {
							//ポリゴン
							if (memr[mem]) {
								//最初p+z
								vx.emplace_back(membx[mem] + (localzx * c * r * fracrate));
								vy.emplace_back(memby[mem] + (localzy * c * r * fracrate));
								vz.emplace_back(membz[mem] + (localzz * c * r * fracrate));
								vnum++;
								//最終p+z60do
								for (int i = 0; i < meme[mem] - 1; ++i) {
									localrotate(localzx, localzy, localzz, M_PI / (meme[mem] / 2), localyx, localyy, localyz, &localzx, &localzy, &localzz);
									vx.emplace_back(membx[mem] + (localzx * c * r * fracrate));
									vy.emplace_back(memby[mem] + (localzy * c * r * fracrate));
									vz.emplace_back(membz[mem] + (localzz * c * r * fracrate));
									vnum++;
								}
								localrotate(localzx, localzy, localzz, -M_PI / (meme[mem] / 2) * (meme[mem] - 1), localyx, localyy, localyz, &localzx, &localzy, &localzz);

								for (int i = 0; i < memv.size() - 1; ++i)
									memv[i] += meme[mem];
								memr[mem] = false;
							}

							membx[mem] = x;
							memby[mem] = y;
							membz[mem] = z;
							//最終p+z
							vx.emplace_back(membx[mem] + (localzx * c * r * fracrate));
							vy.emplace_back(memby[mem] + (localzy * c * r * fracrate));
							vz.emplace_back(membz[mem] + (localzz * c * r * fracrate));
							vnum++;
							//最終p+z60do
							for (int i = 0; i < meme[mem] - 1; ++i){
								localrotate(localzx, localzy, localzz, M_PI / ( meme[mem]/2), localyx, localyy, localyz, &localzx, &localzy, &localzz);
							vx.emplace_back(membx[mem] + (localzx * c * r * fracrate));
							vy.emplace_back(memby[mem] + (localzy * c * r * fracrate));
							vz.emplace_back(membz[mem] + (localzz * c * r * fracrate));
							vnum++;
						}
							for (int i = 0; i < meme[mem] - 1; ++i) {
								m.emplace_back(0);
								p.emplace_back(vnum - (i + 1 + meme[mem]) - memv[mem]);
								pnum++;
								p.emplace_back(vnum - 2 - i);
								pnum++;
								p.emplace_back(vnum - 1 - i);
								pnum++;
								uv.emplace_back(i / meme[mem]);
								uv.emplace_back(0);
								uv.emplace_back((i + 1) / meme[mem]);
								uv.emplace_back(1);
								uv.emplace_back(i / meme[mem]);
								uv.emplace_back(1);
								m.emplace_back(0);
								p.emplace_back(vnum - (i + 1 + meme[mem]) - memv[mem]);
								pnum++;
								p.emplace_back(vnum - (i + 2 + meme[mem]) - memv[mem]);
								pnum++;
								p.emplace_back(vnum - 2 - i);
								pnum++;
								uv.emplace_back(i / meme[mem]);
								uv.emplace_back(0);
								uv.emplace_back((i + 1) / meme[mem]);
								uv.emplace_back(0);
								uv.emplace_back((i + 1) / meme[mem]);
								uv.emplace_back(1);
							}
							m.emplace_back(0);
							p.emplace_back(vnum - (meme[mem] * 2) - memv[mem]);
							pnum++;
							p.emplace_back(vnum - 1);
							pnum++;
							p.emplace_back(vnum - meme[mem]);
							pnum++;
							uv.emplace_back((meme[mem] - 1) / meme[mem]);
							uv.emplace_back(0);
							uv.emplace_back(1);
							uv.emplace_back(1);
							uv.emplace_back((meme[mem] - 1) / meme[mem]);
							uv.emplace_back(1);
							m.emplace_back(0);
							p.emplace_back(vnum - (meme[mem] * 2) - memv[mem]);
							pnum++;
							p.emplace_back(vnum - (meme[mem] + 1) - memv[mem]);
							pnum++;
							p.emplace_back(vnum - 1);
							pnum++;
								uv.emplace_back((meme[mem] - 1) / meme[mem]);
								uv.emplace_back(0);
								uv.emplace_back(1);
								uv.emplace_back(0);
								uv.emplace_back(1);
								uv.emplace_back(1);
							localrotate(localzx, localzy, localzz, -M_PI / (meme[mem] / 2)*(meme[mem]-1), localyx, localyy, localyz, &localzx, &localzy, &localzz);

							for (int i = 0; i < memv.size() - 1; ++i)
								memv[i] += meme[mem];
							memv[mem] = 0;
						}
						else {

							vx.emplace_back(membx[mem]);
							vy.emplace_back(memby[mem]);
							vz.emplace_back(membz[mem]);
							vnum++;

							vx.emplace_back(x);
							vy.emplace_back(y);
							vz.emplace_back(z);
							vnum++;

							membx[mem] = x;
							memby[mem] = y;
							membz[mem] = z;
						}
						break;
					}
					case 's': {
						meme.emplace_back(2);
						memx.emplace_back(x);
						memy.emplace_back(y);
						memz.emplace_back(z);
						memxx.emplace_back(localxx);
						memxy.emplace_back(localxy);
						memxz.emplace_back(localxz);
						memyx.emplace_back(localyx);
						memyy.emplace_back(localyy);
						memyz.emplace_back(localyz);
						memzx.emplace_back(localzx);
						memzy.emplace_back(localzy);
						memzz.emplace_back(localzz);
						membx.emplace_back(0);
						memby.emplace_back(0);
						membz.emplace_back(0);
						memv.emplace_back(0);
						memr.emplace_back(1);
						mem++;
						break; }
					case '[': {
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						meme.emplace_back(wcstod(num, NULL));
						memx.emplace_back(x);
						memy.emplace_back(y);
						memz.emplace_back(z);
						memxx.emplace_back(localxx);
						memxy.emplace_back(localxy);
						memxz.emplace_back(localxz);
						memyx.emplace_back(localyx);
						memyy.emplace_back(localyy);
						memyz.emplace_back(localyz);
						memzx.emplace_back(localzx);
						memzy.emplace_back(localzy);
						memzz.emplace_back(localzz);
						membx.emplace_back(0);
						memby.emplace_back(0);
						membz.emplace_back(0);
						memv.emplace_back(0);
						memr.emplace_back(1);
						mem++;
						break;
					}
					case 'l': {
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != ',' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c2 = wcstod(num, NULL); std::free(num);
						num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);

					

							if (d % 2) {
							//ポリゴン
							if (memr[mem]) {
								membx[mem] = x;
								memby[mem] = y;
								membz[mem] = z;
								//最初p+z
								vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
								vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
								vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
								vnum++;
								//最終p+z60do
								for (int i = 0; i < meme[mem] - 1; ++i) {
									localrotate(localzx, localzy, localzz, M_PI / (meme[mem] / 2), localyx, localyy, localyz, &localzx, &localzy, &localzz);
									vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
									vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
									vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
									vnum++;
								}
								localrotate(localzx, localzy, localzz, -M_PI / (meme[mem] / 2) * (meme[mem] - 1), localyx, localyy, localyz, &localzx, &localzy, &localzz);

								for (int i = 0; i < memv.size() - 1; ++i)
									memv[i] += meme[mem];
								memr[mem] = false;
							}

							//最終p
							vx.emplace_back(x + fow * c * localyx * fracrate);
							vy.emplace_back(y + fow * c * localyy * fracrate);
							vz.emplace_back(z + fow * c * localyz * fracrate);
							vnum++;
							for (int i = 0; i < memv.size() - 1; ++i)
								memv[i] += 1;
							for (int i = 0; i < meme[mem] - 1; ++i) {
								m.emplace_back(1);
								p.emplace_back(vnum - 1);
								pnum++;
								p.emplace_back(vnum - (i + 2) - memv[mem]);
								pnum++;
								p.emplace_back(vnum - (i + 3) - memv[mem]);
								pnum++;
								uv.emplace_back(0.5);
								uv.emplace_back(1);
								uv.emplace_back(0);
								uv.emplace_back(0);
								uv.emplace_back(1);
								uv.emplace_back(0);
							}
							m.emplace_back(1);
							p.emplace_back(vnum - 1);
							pnum++;
							p.emplace_back(vnum - (1 + meme[mem]) - memv[mem]);
							pnum++;
							p.emplace_back(vnum - 2 - memv[mem]);
							pnum++;
							uv.emplace_back(-0.5);
							uv.emplace_back(1);
							uv.emplace_back(0);
							uv.emplace_back(0);
							uv.emplace_back(-1);
							uv.emplace_back(0);
						}
						else {

							vx.emplace_back(x + fow * c * localyx * fracrate);
							vy.emplace_back(y + fow * c * localyy * fracrate);
							vz.emplace_back(z + fow * c * localyz * fracrate);
							vnum++;

							vx.emplace_back(x);
							vy.emplace_back(y);
							vz.emplace_back(z);
							vnum++;
						}

						if (mem > 0) {
							x = memx[mem - 1];
							y = memy[mem - 1];
							z = memz[mem - 1];
							localxx = memxx[mem - 1];
							localxy = memxy[mem - 1];
							localxz = memxz[mem - 1];
							localyx = memyx[mem - 1];
							localyy = memyy[mem - 1];
							localyz = memyz[mem - 1];
							localzx = memzx[mem - 1];
							localzy = memzy[mem - 1];
							localzz = memzz[mem - 1];
							memx.pop_back();
							memy.pop_back();
							memz.pop_back();
							memxx.pop_back();
							memxy.pop_back();
							memxz.pop_back();
							memyx.pop_back();
							memyy.pop_back();
							memyz.pop_back();
							memzx.pop_back();
							memzy.pop_back();
							memzz.pop_back();
							membx.pop_back();
							memby.pop_back();
							membz.pop_back();
							memv.pop_back();
							memr.pop_back();
							meme.pop_back();
							mem--;
						}
						break; }
					case ']': {
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != ',' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c2 = wcstod(num, NULL); std::free(num);
						num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);

					

							if (d % 2) {
							//ポリゴン
							if (memr[mem]) {
								membx[mem] = x;
								memby[mem] = y;
								membz[mem] = z;
								//最初p+z
								vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
								vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
								vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
								vnum++;
								//最終p+z60do
								for (int i = 0; i < meme[mem] - 1; ++i) {
									localrotate(localzx, localzy, localzz, M_PI / (meme[mem] / 2), localyx, localyy, localyz, &localzx, &localzy, &localzz);
									vx.emplace_back(membx[mem] + (localzx * c2 * r * fracrate));
									vy.emplace_back(memby[mem] + (localzy * c2 * r * fracrate));
									vz.emplace_back(membz[mem] + (localzz * c2 * r * fracrate));
									vnum++;
								}
								localrotate(localzx, localzy, localzz, -M_PI / (meme[mem] / 2) * (meme[mem] - 1), localyx, localyy, localyz, &localzx, &localzy, &localzz);

								for (int i = 0; i < memv.size() - 1; ++i)
									memv[i] += meme[mem];
								memr[mem] = false;
							}

							//最終p
							vx.emplace_back(x + fow * c * localyx * fracrate);
							vy.emplace_back(y + fow * c * localyy * fracrate);
							vz.emplace_back(z + fow * c * localyz * fracrate);
							vnum++;
							for (int i = 0; i < memv.size() - 1; ++i)
								memv[i] += 1;
							for (int i = 0; i < meme[mem] - 1; ++i) {
								m.emplace_back(0);
								p.emplace_back(vnum - 1);
								pnum++;
								p.emplace_back(vnum - (i + 2) - memv[mem]);
								pnum++;
								p.emplace_back(vnum - (i + 3) - memv[mem]);
								pnum++;
								uv.emplace_back((i+0.5) / meme[mem]);
								uv.emplace_back(1);
								uv.emplace_back(i / meme[mem]);
								uv.emplace_back(0);
								uv.emplace_back((i + 1) / meme[mem]);
								uv.emplace_back(0);
							}
							m.emplace_back(0);
							p.emplace_back(vnum - 1);
							pnum++;
							p.emplace_back(vnum - (1+meme[mem]) - memv[mem]);
							pnum++;
							p.emplace_back(vnum - 2 - memv[mem]);
							pnum++;
							uv.emplace_back((meme[mem] - 1 + 0.5) / meme[mem]);
							uv.emplace_back(1);
							uv.emplace_back((meme[mem] - 1) / meme[mem]);
							uv.emplace_back(0);
							uv.emplace_back(1);
							uv.emplace_back(0);
						}
						else {

							vx.emplace_back(x + fow * c * localyx * fracrate);
							vy.emplace_back(y + fow * c * localyy * fracrate);
							vz.emplace_back(z + fow * c * localyz * fracrate);
							vnum++;

							vx.emplace_back(x);
							vy.emplace_back(y);
							vz.emplace_back(z);
							vnum++;
						}
						if (mem > 0) {
							x = memx[mem - 1];
							y = memy[mem - 1];
							z = memz[mem - 1];
							localxx = memxx[mem - 1];
							localxy = memxy[mem - 1];
							localxz = memxz[mem - 1];
							localyx = memyx[mem - 1];
							localyy = memyy[mem - 1];
							localyz = memyz[mem - 1];
							localzx = memzx[mem - 1];
							localzy = memzy[mem - 1];
							localzz = memzz[mem - 1];
							memx.pop_back();
							memy.pop_back();
							memz.pop_back();
							memxx.pop_back();
							memxy.pop_back();
							memxz.pop_back();
							memyx.pop_back();
							memyy.pop_back();
							memyz.pop_back();
							memzx.pop_back();
							memzy.pop_back();
							memzz.pop_back();
							membx.pop_back();
							memby.pop_back();
							membz.pop_back();
							memv.pop_back();
							memr.pop_back();
							meme.pop_back();
							mem--;
						}
						break;
					}
					case 'z': {
					
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);
					
						localrotate(localxx, localxy, localxz, rotarg * c / 180.0 * M_PI, localzx, localzy, localzz, &localxx, &localxy, &localxz);
						localrotate(localyx, localyy, localyz, rotarg * c / 180.0 * M_PI, localzx, localzy, localzz, &localyx, &localyy, &localyz);
						localrotate(localzx, localzy, localzz, rotarg * c / 180.0 * M_PI, localzx, localzy, localzz, &localzx, &localzy, &localzz);
						break;
					}
					case 'y': {
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);
					
						localrotate(localxx, localxy, localxz, rotarg * c / 180.0 * M_PI, localyx, localyy, localyz, &localxx, &localxy, &localxz);
						localrotate(localzx, localzy, localzz, rotarg * c / 180.0 * M_PI, localyx, localyy, localyz, &localzx, &localzy, &localzz);
						localrotate(localyx, localyy, localyz, rotarg * c / 180.0 * M_PI, localyx, localyy, localyz, &localyx, &localyy, &localyz);
						break;
					}
					case 'x': {
						PTSTR num = (PTSTR)calloc(100, sizeof(TCHAR));
						while (outText[i] != 'c' && i < olen) {
							i++;
							switch (outText[i]) {
							case '-':
								lstrcat(num, TEXT("-"));
								break;
							case '.':
								lstrcat(num, TEXT("."));
								break;
							case '1':
								lstrcat(num, TEXT("1"));
								break;
							case '2':
								lstrcat(num, TEXT("2"));
								break;
							case '3':
								lstrcat(num, TEXT("3"));
								break;
							case '4':
								lstrcat(num, TEXT("4"));
								break;
							case '5':
								lstrcat(num, TEXT("5"));
								break;
							case '6':
								lstrcat(num, TEXT("6"));
								break;
							case '7':
								lstrcat(num, TEXT("7"));
								break;
							case '8':
								lstrcat(num, TEXT("8"));
								break;
							case '9':
								lstrcat(num, TEXT("9"));
								break;
							case '0':
								lstrcat(num, TEXT("0"));
								break;
							}
						}
						double c = wcstod(num, NULL);std::free(num);
					
						localrotate(localyx, localyy, localyz, rotarg * c / 180.0 * M_PI, localxx, localxy, localxz, &localyx, &localyy, &localyz);
						localrotate(localzx, localzy, localzz, rotarg * c / 180.0 * M_PI, localxx, localxy, localxz, &localzx, &localzy, &localzz);
						localrotate(localxx, localxy, localxz, rotarg * c / 180.0 * M_PI, localxx, localxy, localxz, &localxx, &localxy, &localxz);
						break; }
					}
				}
			}
			if ((HWND)lp == edit[0] || (HWND)lp == edit[1] || (HWND)lp == edit[2] || (HWND)lp == edit[3] || (HWND)lp == edit[4] || (HWND)lp == edit[5] || (HWND)lp == edit[6] || (HWND)lp == edit[7] || (HWND)lp == edit[8] || (HWND)lp == edit[9] || (HWND)lp == edit[10] || (HWND)lp == edit[11] || (HWND)lp == edit[12] || (HWND)lp == edit[13] || (HWND)lp == edit[14] || (HWND)lp == edit[15])
			{
				if(SendMessage(edit[13], TBM_GETPOS, 0, 0) == 0 || SendMessage(edit[13], TBM_GETPOS, 0, 0) == 1){
				InvalidateRect(hwnd, NULL, TRUE);
				}
				else {
					SendMessage(hwnd , WM_PAINT , 0 , 0);
				}
			}
			
		}}
		return 0;
	case WM_PAINT: {
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 200, 0, TEXT("初期値"), 3);
		TextOut(hdc, 200, 20, TEXT("繰り返し回数"), 6);
		TextOut(hdc, 500, 40, TEXT("F変化"), 3);
		TextOut(hdc, 200, 60, TEXT("初期位置x"), 5);
		TextOut(hdc, 200, 80, TEXT("初期位置y"), 5);
		TextOut(hdc, 200, 100, TEXT("初期位置z"), 5);
		TextOut(hdc, 200, 120, TEXT("zmax"), 4);
		TextOut(hdc, 200, 140, TEXT("preview回転x"), 10);
		TextOut(hdc, 200, 160, TEXT("preview回転y"), 10);
		TextOut(hdc, 200, 180, TEXT("preview回転z"), 10);
		TextOut(hdc, 200, 200, TEXT("進む距離"), 4);
		TextOut(hdc, 200, 220, TEXT("回転量"), 3);
		TextOut(hdc, 200, 240, TEXT("枝半径"), 3);
		TextOut(hdc, 200, 260, TEXT("type"), 4);
		TextOut(hdc, 200, 280, TEXT("フラクタル比率"), 7);
		TextOut(hdc, 200, 340, TEXT("manual input"), 12);
		TextOut(hdc, 40, 300, outText, lstrlen(outText));
		double defx = SendMessage(edit[3], TBM_GETPOS, 0, 0);
		double defy = SendMessage(edit[4], TBM_GETPOS, 0, 0);
		double defz = SendMessage(edit[5], TBM_GETPOS, 0, 0);
		double zmax = SendMessage(edit[6], TBM_GETPOS, 0, 0);
		double viewx = SendMessage(edit[7], TBM_GETPOS, 0, 0);
		double  viewy = SendMessage(edit[8], TBM_GETPOS, 0, 0);
		double  viewz = SendMessage(edit[9], TBM_GETPOS, 0, 0);
		int d = SendMessage(edit[13], TBM_GETPOS, 0, 0);
		//メイン描画
		PictureBox^ pictureBox1 = MainForm ::MyForm::pictureBox1;
	    Bitmap^ bmpPicBox;
		Graphics^ g;
		if (d == 2 || d == 3) {
			delete(pictureBox1->Image);
			bmpPicBox = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			g = Graphics::FromImage(bmpPicBox);
		}
		HDC oh;
		int format;
		HGLRC glRC;
		GLuint tex[2];
		if (d > 3) {
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR),   
				1,                    
				PFD_DRAW_TO_WINDOW |   
				PFD_SUPPORT_OPENGL |  
				PFD_DOUBLEBUFFER, 
				PFD_TYPE_RGBA,       
				32,                   
				0, 0, 0, 0, 0, 0,     
				0,                  
				0,                    
				0,                    
				0, 0, 0, 0,          
				32,                 
				0,                     
				0,                    
				PFD_MAIN_PLANE,       
				0,                    
				0, 0, 0               
			};
			oh = GetDC(((HWND)pictureBox1->Handle.ToInt32()));
			int format = ChoosePixelFormat(oh, &pfd);
			SetPixelFormat(oh, format, &pfd);
			glRC = wglCreateContext(oh);
			wglMakeCurrent(oh, glRC);
			glClearColor(0.375f, 0.375f, 0.375f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_ALPHA_TEST);
		    glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);

			if (d > 5) {
				if (d > 7) {
					glGenTextures(2, tex);
					loadbmp(tex[0], "bmp.bmp");
					loadbmp(tex[1], "bmp2.bmp");
				}
				glViewport(0, 0, pictureBox1->Width, pictureBox1->Height);
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluPerspective(60.0, (double)pictureBox1->Width / pictureBox1->Height, 1.0, 2000.0);		
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				gluLookAt(campx, campy, campz, campx+ campzx, campy+ campzy, campz+ campzz, 0.0, campyy, 0.0);
			}
		}

		if (d > 5) {
			glBegin(GL_LINES);	
			glColor3d(1, 1, 1);
			for (int x = -500; x <= 500; x += 10) {
				glVertex3f(x, 0, 500);
				glVertex3f(x, 0, -500);
				glVertex3f(500, 0, x);
				glVertex3f(-500, 0, x);
			}
			glEnd();
			glEnable(GL_TEXTURE_2D);
			if (d == 6) {
				glBegin(GL_LINES);
				for (int i = 0; i < vnum; i++) {
					glColor3d(vx[i], -vy[i], vz[i]);
					glVertex3d(vx[i], -vy[i], vz[i]);
				}
			}
			else {
				glBegin(GL_TRIANGLES);
				
				for (int i = 0; i < pnum; i++) {
					if (d > 7) {
						if (i % 3 == 0) {
							glEnd();
							if (m[i/3]) {
								glBindTexture(GL_TEXTURE_2D, tex[1]);
							}
							else{
								glBindTexture(GL_TEXTURE_2D, tex[0]);
						}
							glBegin(GL_TRIANGLES);
						}
						glTexCoord2f(uv[i * 2], uv[i * 2 + 1]);
					}
					else {
						glColor3d(vx[p[i]] / 50, -vy[p[i]] / 50, vz[p[i]] / 50);
					}
					if (i % 3 == 0) {
						double d =sqrt(((((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]]))) * (((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]]))))
								+ ((((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]]))) * (((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]]))))
								+ ((((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]]))) * (((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])))));
						glNormal3d((((vy[p[i]] - vy[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])) - ((vz[p[i]] - vz[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])))/d, 
							(((vz[p[i]] - vz[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])) - ((vx[p[i]] - vx[p[i + 2]]) * (vz[p[i]] - vz[p[i + 1]])))/d,
							(((vx[p[i]] - vx[p[i + 2]]) * (vy[p[i]] - vy[p[i + 1]])) - ((vy[p[i]] - vy[p[i + 2]]) * (vx[p[i]] - vx[p[i + 1]])))/d);
					}
					glVertex3d(vx[p[i]], -vy[p[i]], vz[p[i]]);
	
				}
			}
		}
		else
			if (d % 2) {
				if (d == 5) {
					glBegin(GL_TRIANGLES);
				}
				for (int i = 0; i < pnum; i++) {
					double tex = vx[p[i]];
					double tey = vy[p[i]];
					double tez = vz[p[i]];
					double tempx;
					double tempy = tey - defy;
					double tempz = tez - defz;
					tey = (tempy * cos((viewx / 180.0) * M_PI)) - (tempz * sin((viewx / 180.0) * M_PI)) + defy;
					tez = (tempy * sin((viewx / 180.0) * M_PI)) + (tempz * cos((viewx / 180.0) * M_PI)) + defz;
					tempx = tex - defx;
					tempz = tez - defz;
					tex = (tempx * cos((viewy / 180.0) * M_PI)) - (tempz * sin((viewy / 180.0) * M_PI)) + defx;
					tez = (tempx * sin((viewy / 180.0) * M_PI)) + (tempz * cos((viewy / 180.0) * M_PI)) + defz;
					tempx = tex - defx;
					tempy = tey - defy;
					tex = (tempx * cos((viewz / 180.0) * M_PI)) - (tempy * sin((viewz / 180.0) * M_PI)) + defx;
					tey = (tempx * sin((viewz / 180.0) * M_PI)) + (tempy * cos((viewz / 180.0) * M_PI)) + defy;
					POINT point;
					point.x = tex + (((defx - tex) / zmax) * tez);
					point.y = tey + (((defy - tey) / zmax) * tez);
					pos.emplace_back(point);
					//net
					if (d == 3)
					{
						if (i % 3 == 2) {
							g->DrawLine(Pens::Blue, pos[i - 1].x, pos[i - 1].y, point.x, point.y);
							g->DrawLine(Pens::Blue, pos[i - 2].x, pos[i - 2].y, point.x, point.y);
						}
						if (i % 3 == 1)
							g->DrawLine(Pens::Blue, pos[i - 1].x, pos[i - 1].y, point.x, point.y);

					}
					//netend
					if (d == 5) {
						glVertex2f(point.x / (double)pictureBox1->Width * 2 - 1, -point.y / (double)pictureBox1->Height * 2 + 1);
					}
				}
				if (d == 1) {
					std::vector<int> ns(pnum / 3, 3);

					POINT* poss = pos.data();
					std::copy(pos.begin(), pos.end(), poss);
					int* nss = ns.data();
					std::copy(ns.begin(), ns.end(), nss);
					SelectObject(hdc, CreatePen(PS_SOLID, 0, RGB(0, 0, 0)));
					//SelectObject(hdc, CreateSolidBrush(RGB(128, 128, 128)));
					SetPolyFillMode(hdc, WINDING);
					PolyPolygon(hdc, poss, nss, pnum / 3);
				}
			}
			else {
				if (d == 4) {
					glBegin(GL_LINES);
				}
				for (int i = 0; i < vnum; i++) {
					double tex = vx[i];
					double tey = vy[i];
					double tez = vz[i];
					double tempx;
					double tempy = tey - defy;
					double tempz = tez - defz;
					tey = (tempy * cos((viewx / 180.0) * M_PI)) - (tempz * sin((viewx / 180.0) * M_PI)) + defy;
					tez = (tempy * sin((viewx / 180.0) * M_PI)) + (tempz * cos((viewx / 180.0) * M_PI)) + defz;
					tempx = tex - defx;
					tempz = tez - defz;
					tex = (tempx * cos((viewy / 180.0) * M_PI)) - (tempz * sin((viewy / 180.0) * M_PI)) + defx;
					tez = (tempx * sin((viewy / 180.0) * M_PI)) + (tempz * cos((viewy / 180.0) * M_PI)) + defz;
					tempx = tex - defx;
					tempy = tey - defy;
					tex = (tempx * cos((viewz / 180.0) * M_PI)) - (tempy * sin((viewz / 180.0) * M_PI)) + defx;
					tey = (tempx * sin((viewz / 180.0) * M_PI)) + (tempy * cos((viewz / 180.0) * M_PI)) + defy;
					POINT point;
					point.x = tex + (((defx - tex) / zmax) * tez);
					point.y = tey + (((defy - tey) / zmax) * tez);
					pos.emplace_back(point);

					//net
					if (d == 2 && i % 2 == 1)
						g->DrawLine(Pens::Blue, pos[i - 1].x, pos[i - 1].y, point.x, point.y);
					//netend
					if (d == 4) {
						glVertex2f(point.x / (double)pictureBox1->Width * 2 - 1, -point.y / (double)pictureBox1->Height * 2 + 1);
					}
				}
				if (d == 0) {
					std::vector<DWORD> ns(vnum / 2, 2);
					POINT* poss = pos.data();
					std::copy(pos.begin(), pos.end(), poss);
					DWORD* nss = ns.data();
					std::copy(ns.begin(), ns.end(), nss);
					PolyPolyline(hdc, poss, nss, vnum / 2);
				}
			}
		//OGL  OWARI
		if (d > 3) {
			glDeleteTextures(2,tex);
			glEnd();
			glFlush();
			SwapBuffers(oh);
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(glRC);
			DeleteDC(oh);
		}
		if (d ==3||d==2) pictureBox1->Image = bmpPicBox;
		delete(g);
		EndPaint(hwnd, &ps);
		ReleaseDC(hwnd, hdc); }
				 return 0;
	}
	case WM_CREATE:
		//InitCommonControls();
		edit[0] = CreateWindow(
			TEXT("EDIT"), TEXT("[5cf1c],25c"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			0, 0, 100000, 20, hwnd, NULL,
			NULL, NULL
		);
		edit[1] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 20,200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[1], TBM_SETRANGE, TRUE, MAKELPARAM(0, 10));
		SendMessage(edit[1], TBM_SETTICFREQ, 1, 0);
		SendMessage(edit[1], TBM_SETPOS, TRUE, 3);
		SendMessage(edit[1], TBM_SETPAGESIZE, 0, 1);
		edit[2] = CreateWindow(
			TEXT("EDIT"), TEXT("h5,20c[3cz30cf0.75c]5,25csz90cw5cl30,30ch,10cg5cy45cf0.95c"),
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
			0, 40, 100000, 20, hwnd, NULL,
			NULL, NULL
		);
		edit[3] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 60, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[3], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[3], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[3], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[3], TBM_SETPAGESIZE, 0, 1);
		edit[4] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 80, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[4], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[4], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[4], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[4], TBM_SETPAGESIZE, 0, 1);
		edit[5] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 100, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[5], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[5], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[5], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[5], TBM_SETPAGESIZE, 0, 1);
		edit[6] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 120, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[6], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[6], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[6], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[6], TBM_SETPAGESIZE, 0, 1);
		edit[7] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 140, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[7], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[7], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[7], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[7], TBM_SETPAGESIZE, 0, 1);
		edit[8] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 160, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[8], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[8], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[8], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[8], TBM_SETPAGESIZE, 0, 1);
		edit[9] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 180, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[9], TBM_SETRANGE, TRUE, MAKELPARAM(-2000, 2000));
		SendMessage(edit[9], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[9], TBM_SETPOS, TRUE, 0);
		SendMessage(edit[9], TBM_SETPAGESIZE, 0, 1);
		edit[10] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 200, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[10], TBM_SETRANGE, TRUE, MAKELPARAM(-1000, 1000));
		SendMessage(edit[10], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[10], TBM_SETPOS, TRUE, 100);
		SendMessage(edit[10], TBM_SETPAGESIZE, 0, 1);
		edit[11] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 220, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[11], TBM_SETRANGE, TRUE, MAKELPARAM(-1000, 1000));
		SendMessage(edit[11], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[11], TBM_SETPOS, TRUE, 100);
		SendMessage(edit[11], TBM_SETPAGESIZE, 0, 1);
		edit[12] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 240, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[12], TBM_SETRANGE, TRUE, MAKELPARAM(-1000, 1000));
		SendMessage(edit[12], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[12], TBM_SETPOS, TRUE, 100);
		SendMessage(edit[12], TBM_SETPAGESIZE, 0, 1);
		edit[13] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 260, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[13], TBM_SETRANGE, TRUE, MAKELPARAM(0, 9));
		SendMessage(edit[13], TBM_SETTICFREQ, 1, 0);
		SendMessage(edit[13], TBM_SETPOS, TRUE, 9);
		SendMessage(edit[13], TBM_SETPAGESIZE, 0, 1);
		edit[14] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 280, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[14], TBM_SETRANGE, TRUE, MAKELPARAM(-1000, 1000));
		SendMessage(edit[14], TBM_SETTICFREQ, 100, 0);
		SendMessage(edit[14], TBM_SETPOS, TRUE, 100);
		SendMessage(edit[14], TBM_SETPAGESIZE, 0, 1);
		edit[15] = CreateWindow(
			TEXT("BUTTON"), TEXT("出力"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 300, 40, 20,
			hwnd, NULL, NULL, NULL
		);
		edit[16] = CreateWindow(
			TEXT("BUTTON"), TEXT("インポート"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, 320, 100, 20,
			hwnd, NULL, NULL, NULL
		); 
		edit[17] = CreateWindow(TRACKBAR_CLASS, TEXT(""), WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS | TBS_TOOLTIPS,
			0, 340, 200, 20, hwnd, NULL, NULL, NULL);
		SendMessage(edit[17], TBM_SETRANGE, TRUE, MAKELPARAM(0, 1));
		SendMessage(edit[17], TBM_SETTICFREQ, 1, 0);
		SendMessage(edit[17], TBM_SETPOS, TRUE, 1);
		SendMessage(edit[17], TBM_SETPAGESIZE, 0, 1);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASS winc;
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("MAIN");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
		TEXT("MAIN"), TEXT("MAIN"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 1000, 800, NULL, NULL,
		hInstance, NULL
	);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm::MyForm form;
	Application::Run(% form);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
void camt() {
	if (MainForm::MyForm::tx != 0 || MainForm::MyForm::ty != 0) {
		campx += (campxx * MainForm::MyForm::tx) + (campyx * MainForm::MyForm::ty);
		campy += (campxy * MainForm::MyForm::tx) + (campyy * MainForm::MyForm::ty);
		campz += (campxz * MainForm::MyForm::tx) + (campyz * MainForm::MyForm::ty);

	}	SendMessage(hwnd, WM_PAINT, 0, 0);
}
void camr() {
	if (MainForm::MyForm::tx != 0 || MainForm::MyForm::ty != 0) {
		double temp1 = campyx, temp2 = campyy, temp3 = campyz;
		localrotate(campyx, campyy, campyz, (MainForm::MyForm::ty) / 180.0 * M_PI, campxx, campxy, campxz, &campyx, &campyy, &campyz);
		localrotate(campzx, campzy, campzz, (MainForm::MyForm::ty) / 180.0 * M_PI, campxx, campxy, campxz, &campzx, &campzy, &campzz);
		localrotate(campxx, campxy, campxz, (MainForm::MyForm::ty) / 180.0 * M_PI, campxx, campxy, campxz, &campxx, &campxy, &campxz);

		localrotate(campyx, campyy, campyz, (MainForm::MyForm::tx) / 180.0 * M_PI, temp1, temp2, temp3, &campyx, &campyy, &campyz);
		localrotate(campzx, campzy, campzz, (MainForm::MyForm::tx) / 180.0 * M_PI, temp1, temp2, temp3, &campzx, &campzy, &campzz);
		localrotate(campxx, campxy, campxz, (MainForm::MyForm::tx) / 180.0 * M_PI, temp1, temp2, temp3, &campxx, &campxy, &campxz);
	}	SendMessage(hwnd, WM_PAINT, 0, 0);
}
void camf() {
	if (MainForm::MyForm::tx != 0 || MainForm::MyForm::ty != 0) {
		campx += (campzx * MainForm::MyForm::tx);
		campy += (campzy * MainForm::MyForm::tx);
		campz += (campzz * MainForm::MyForm::tx);
	}
	SendMessage(hwnd, WM_PAINT, 0, 0);
}