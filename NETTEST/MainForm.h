#pragma once
#include "Item.h"
#include "Texture.h"
#include "Material.h"
#include "Twig.h"
#include "Generator.h"
#include "Info.h"
#include<string>

namespace MainForm {			

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	class Item i;
	class Texture tr;
	class Material mt;
	class Twig tw;
	class Generator gn;
	class Info in;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		static double tx, ty;
		
	public:
		MyForm(void)
		{
			i.NodeStartRoot();
			tr.SetUp();
			mt.SetUp();
			tw.SetUp();
			gn.SetUp();
			InitializeComponent();
			setTableLayoutPanelControlComponent ();
			SetTableLayoutPanelE();
			SetIcon();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;

	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;

	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::SplitContainer^ splitContainerA1;
	private: System::Windows::Forms::SplitContainer^ splitContainerA2;
	private: System::Windows::Forms::SplitContainer^ splitContainerA3;
	private: System::Windows::Forms::SplitContainer^ splitContainerB1;
	private: System::Windows::Forms::SplitContainer^ splitContainerB2;
	private: System::Windows::Forms::SplitContainer^ splitContainerB3;
	private: System::Windows::Forms::SplitContainer^ splitContainerC1;
	private: System::Windows::Forms::SplitContainer^ splitContainerC2;
	private: System::Windows::Forms::SplitContainer^ splitContainerC3;
	private: System::Windows::Forms::SplitContainer^ splitContainerD1;
	private: System::Windows::Forms::SplitContainer^ splitContainerD2;
		   
	public:static System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::TreeView^ treeViewB1;

	private: System::Windows::Forms::ListView^ listViewA1;
	private: System::Windows::Forms::ListView^ listViewA2;
	private: System::Windows::Forms::ListView^ listViewB1;
	private: System::Windows::Forms::ListView^ listViewC1;
	private: System::Windows::Forms::ListView^ listViewC2;
	private: System::Windows::Forms::ListView^ listViewD1;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelA;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelB;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelC;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelD;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanelE;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeView;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewA1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewA2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewB1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewB2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewC1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewC2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripOfTreeViewD1;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ makeTwigToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ addNewTextureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateTextureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteTextureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addNewTextureLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateTextureLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteTextureLayerToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ addNewMaterialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateMaterialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteMaterialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addNewMaterialLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateMaterialLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteMaterialLayerToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ addNewTwigToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateTwigToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteTwigToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addNewTwigLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateTwigLayerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteTwigLayerToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ addObjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addTreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ duplicateObjTreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteObjTreToolStripMenuItem;

     //ForPropControl
	private:
		   Label^ NonFocus;

		   //ForItem
		   Label^ label0;
		   Label^ label1;
		   Label^ label2;
		   Label^ label3;
		   Label^ label4;
		   Label^ label5;
		   Label^ label6;
		   Label^ label7;
		   Label^ label8;
		   Label^ label9;
		   Label^ label10;
		   Label^ label11;
		   Label^ label12;
		   Label^ label13;
		   Label^ label14;
		   Label^ label15;
		   Label^ label16;
		   Label^ label17;
		   Label^ label18;
		   Label^ label19;
		   Label^ label20;
		   Label^ label21;
		   Label^ label22;
		   Label^ label23;
		   Label^ label24;
		   Label^ label25;//btgryou
		   Label^ label26;

		   ComboBox^ comboBox0;
		   ComboBox^ comboBox1;
		   ComboBox^ comboBox2;
		   ComboBox^ comboBox3;

		   DataVisualization::Charting::Chart^ chart0;
		   DataVisualization::Charting::Chart^ chart1;
		   DataVisualization::Charting::Chart^ chart2;

		   TextBox^ textBox0;
		   TextBox^ textBox1;
		   TextBox^ textBox2;
		   TextBox^ textBox3;
		   TextBox^ textBox4;
		   TextBox^ textBox5;
		   TextBox^ textBox6;
		   TextBox^ textBox7;
		   TextBox^ textBox8;
		   TextBox^ textBox9;
		   TextBox^ textBox10;
		   TextBox^ textBox11;
		   TextBox^ textBox12;
		   TextBox^ textBox13;
		   TextBox^ textBox14;
		   TextBox^ textBox15;
		   TextBox^ textBox16;
		   TextBox^ textBox17;
		   TextBox^ textBox18;
		   TextBox^ textBox19;//btgryou
		   TrackBar^ trackBar0;
		   TrackBar^ trackBar1;
		   TrackBar^ trackBar2;
		   TrackBar^ trackBar3;
		   TrackBar^ trackBar4;
		   TrackBar^ trackBar5;
		   TrackBar^ trackBar6;
		   TrackBar^ trackBar7;
		   TrackBar^ trackBar8;
		   TrackBar^ trackBar9;
		   TrackBar^ trackBar10;
		   TrackBar^ trackBar11;
		   TrackBar^ trackBar12;
		   TrackBar^ trackBar13;
		   TrackBar^ trackBar14;
		   TrackBar^ trackBar15;
		   TrackBar^ trackBar16;
		   TrackBar^ trackBar17;
		   TrackBar^ trackBar18;
		   TrackBar^ trackBar19;
		   TrackBar^ trackBar20;
		   TrackBar^ trackBar21;
		   TrackBar^ trackBar22;
		   TrackBar^ trackBar23;
		   TrackBar^ trackBar24;
		   TrackBar^ trackBar25;//btgryou


		   //ForTexture





		   //ForMaterial





		   //ForTwig





		   //ForGenerator
		   Label^ labelD0;
		   Label^ labelD1;
		   Label^ labelD2;
		   Label^ labelD3;
		   Label^ labelD4;
		   Label^ labelD5;
		   Label^ labelD6;
		   Label^ labelD7;
		   Label^ labelD8;
		   Label^ labelD9;
		   Label^ labelD10;
		   Label^ labelD11;
		   Label^ labelD12;
		   Label^ labelD13;
		   Label^ labelD14;

		   ComboBox^ comboBoxD0;

		   TextBox^ textBoxD0;
		   TextBox^ textBoxD1;
		   TextBox^ textBoxD2;
		   TextBox^ textBoxD3;
		   TextBox^ textBoxD4;
		   TextBox^ textBoxD5;
		   TextBox^ textBoxD6;
		   TextBox^ textBoxD7;
		   TextBox^ textBoxD8;
		   TextBox^ textBoxD9;
		   TextBox^ textBoxD10;
		   TextBox^ textBoxD11;
		   TextBox^ textBoxD12;
		   TextBox^ textBoxD13;
		   TextBox^ textBoxD14;
		   TextBox^ textBoxD15;

		   TrackBar^ trackBarD0;
		   TrackBar^ trackBarD1;
		   TrackBar^ trackBarD2;
		   TrackBar^ trackBarD3;
		   TrackBar^ trackBarD4;
		   TrackBar^ trackBarD5;
		   TrackBar^ trackBarD6;
		   TrackBar^ trackBarD7;
		   TrackBar^ trackBarD8;
		   TrackBar^ trackBarD9;
		   TrackBar^ trackBarD10;
		   TrackBar^ trackBarD11;
		   TrackBar^ trackBarD12;
		   TrackBar^ trackBarD13;

		   Button^ buttonD0;
		   Button^ buttonD1;

		   //ForGenerator
		   Button^ buttonE0;
		   Button^ buttonE1;

private: System::Windows::Forms::ToolStripMenuItem^ makeFractalToolStripMenuItem;








	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::TreeNode^ treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"R"));

			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseWheel);
			
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->contextMenuStripOfTreeView = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->makeTwigToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->makeFractalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainerA1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerA2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerA3 = (gcnew System::Windows::Forms::SplitContainer());
			this->listViewA1 = (gcnew System::Windows::Forms::ListView());
			this->listViewA2 = (gcnew System::Windows::Forms::ListView());
			this->contextMenuStripOfTreeViewA1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStripOfTreeViewA2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addNewTextureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateTextureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteTextureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewTextureLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateTextureLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteTextureLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanelA = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainerB1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerB2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerB3 = (gcnew System::Windows::Forms::SplitContainer());
			this->treeViewB1 = (gcnew System::Windows::Forms::TreeView());
			this->listViewB1 = (gcnew System::Windows::Forms::ListView());
			this->contextMenuStripOfTreeViewB1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStripOfTreeViewB2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addNewMaterialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateMaterialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteMaterialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewMaterialLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateMaterialLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteMaterialLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanelB = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainerC1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerC2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerC3 = (gcnew System::Windows::Forms::SplitContainer());
			this->listViewC1 = (gcnew System::Windows::Forms::ListView());
			this->listViewC2 = (gcnew System::Windows::Forms::ListView());
			this->contextMenuStripOfTreeViewC1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStripOfTreeViewC2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addNewTwigToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateTwigToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteTwigToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewTwigLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateTwigLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteTwigLayerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanelC = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainerD1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainerD2 = (gcnew System::Windows::Forms::SplitContainer());
			this->listViewD1 = (gcnew System::Windows::Forms::ListView());
			this->contextMenuStripOfTreeViewD1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addTreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->duplicateObjTreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteObjTreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanelD = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanelE = (gcnew System::Windows::Forms::TableLayoutPanel());

			this->tabControl1->SuspendLayout();

			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
            this->contextMenuStripOfTreeView->SuspendLayout();

			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA1))->BeginInit();
			this->splitContainerA1->Panel1->SuspendLayout();
			this->splitContainerA1->Panel2->SuspendLayout();
			this->splitContainerA1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA2))->BeginInit();
			this->splitContainerA2->Panel1->SuspendLayout();
			this->splitContainerA2->Panel2->SuspendLayout();
			this->splitContainerA2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA3))->BeginInit();
			this->splitContainerA3->Panel1->SuspendLayout();
			this->splitContainerA3->Panel2->SuspendLayout();
			this->splitContainerA3->SuspendLayout();
			this->contextMenuStripOfTreeViewA1->SuspendLayout();
			this->contextMenuStripOfTreeViewA2->SuspendLayout();

			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB1))->BeginInit();
			this->splitContainerB1->Panel1->SuspendLayout();
			this->splitContainerB1->Panel2->SuspendLayout();
			this->splitContainerB1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB2))->BeginInit();
			this->splitContainerB2->Panel1->SuspendLayout();
			this->splitContainerB2->Panel2->SuspendLayout();
			this->splitContainerB2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB3))->BeginInit();
			this->splitContainerB3->Panel1->SuspendLayout();
			this->splitContainerB3->Panel2->SuspendLayout();
			this->splitContainerB3->SuspendLayout();
			this->contextMenuStripOfTreeViewB1->SuspendLayout();
			this->contextMenuStripOfTreeViewB2->SuspendLayout();

			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC1))->BeginInit();
			this->splitContainerC1->Panel1->SuspendLayout();
			this->splitContainerC1->Panel2->SuspendLayout();
			this->splitContainerC1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC2))->BeginInit();
			this->splitContainerC2->Panel1->SuspendLayout();
			this->splitContainerC2->Panel2->SuspendLayout();
			this->splitContainerC2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC3))->BeginInit();
			this->splitContainerC3->Panel1->SuspendLayout();
			this->splitContainerC3->Panel2->SuspendLayout();
			this->splitContainerC3->SuspendLayout();
			this->contextMenuStripOfTreeViewC1->SuspendLayout();
			this->contextMenuStripOfTreeViewC2->SuspendLayout();

			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerD1))->BeginInit();
			this->splitContainerD1->Panel1->SuspendLayout();
			this->splitContainerD1->Panel2->SuspendLayout();
			this->splitContainerD1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerD2))->BeginInit();
			this->splitContainerD2->Panel1->SuspendLayout();
			this->splitContainerD2->Panel2->SuspendLayout();
			this->splitContainerD2->SuspendLayout();
			this->contextMenuStripOfTreeViewD1->SuspendLayout();

			this->tabPage6->SuspendLayout();

			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->tabControl1->ItemSize = System::Drawing::Size(100, 20);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(0, 0);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(784, 441);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->TabStop = false;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(776, 413);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"     Tree     ";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::Color::Gray;
			this->splitContainer1->Cursor = System::Windows::Forms::Cursors::Default;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Gray;
			this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainer1->Panel1MinSize = 0;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Panel2MinSize = 0;
			this->splitContainer1->Size = System::Drawing::Size(770, 407);
			this->splitContainer1->SplitterDistance = 500;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 407);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->treeView1);
			this->splitContainer2->Panel1MinSize = 0;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->splitContainer2->Panel2->Controls->Add(this->tableLayoutPanel);
			this->splitContainer2->Panel2MinSize = 0;
			this->splitContainer2->Size = System::Drawing::Size(267, 407);
			this->splitContainer2->SplitterDistance = 150;
			this->splitContainer2->SplitterWidth = 3;
			this->splitContainer2->TabIndex = 0;
			// 
			// treeView1
			// 
			this->treeView1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->treeView1->ContextMenuStrip = this->contextMenuStripOfTreeView;
			this->treeView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->treeView1->ForeColor = System::Drawing::Color::White;
			this->treeView1->Location = System::Drawing::Point(0, 0);
			this->treeView1->Name = L"treeView1";
			treeNode1->Name = L"R";
			treeNode1->Text = L"R";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 });
			this->treeView1->SelectedNode=treeNode1;
			this->treeView1->Size = System::Drawing::Size(267, 150);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView1_AfterSelect);
			// 
			// contextMenuStripOfTreeView
			// 
			this->contextMenuStripOfTreeView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem1,
					this->makeTwigToolStripMenuItem, this->deleteToolStripMenuItem
			});
			this->contextMenuStripOfTreeView->Name = L"contextMenuStripOfTreeView";
			this->contextMenuStripOfTreeView->Size = System::Drawing::Size(144, 92);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(143, 22);
			this->toolStripMenuItem1->Text = L"Make Branch";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::MakeBranch);
			// 
			// makeTwigToolStripMenuItem
			// 
			this->makeTwigToolStripMenuItem->Name = L"makeTwigToolStripMenuItem";
			this->makeTwigToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->makeTwigToolStripMenuItem->Text = L"Make Twig";
			this->makeTwigToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::MakeTwig);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::DeleteNode);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->AutoScroll = true;
			this->tableLayoutPanel->ColumnCount = 1;


			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 1;
		
			
			this->tableLayoutPanel->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanel->TabIndex = 0;
			this->tableLayoutPanel->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::tableLayoutPanel_Scroll);
			this->tableLayoutPanel->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::tableLayoutPanel_MouseWheel);


			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainerA1);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(776, 413);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"   Texture    ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainerA1
			// 
			this->splitContainerA1->BackColor = System::Drawing::Color::Gray;
			this->splitContainerA1->Cursor = System::Windows::Forms::Cursors::Default;
			this->splitContainerA1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerA1->Location = System::Drawing::Point(3, 3);
			this->splitContainerA1->Margin = System::Windows::Forms::Padding(0);
			// 
			// splitContainerA1.Panel1
			// 
			this->splitContainerA1->Panel1->BackColor = System::Drawing::Color::Gray;
			//this->splitContainerA1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainerA1->Panel1MinSize = 0;
			// 
			// splitContainerA1.Panel2
			// 
			this->splitContainerA1->Panel2->Controls->Add(this->splitContainerA2);
			this->splitContainerA1->Panel2MinSize = 0;
			this->splitContainerA1->Size = System::Drawing::Size(770, 407);
			this->splitContainerA1->SplitterDistance = 500;
			this->splitContainerA1->SplitterWidth = 3;
			this->splitContainerA1->TabIndex = 1;
			// 
			// splitContainerA2
			// 
			this->splitContainerA2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerA2->Location = System::Drawing::Point(0, 0);
			this->splitContainerA2->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerA2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerA2.Panel1
			// 
			this->splitContainerA2->Panel1->Controls->Add(this->splitContainerA3);
			this->splitContainerA2->Panel1MinSize = 0;
			// 
			// splitContainerA2.Panel2
			// 
			this->splitContainerA2->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->splitContainerA2->Panel2->Controls->Add(this->tableLayoutPanelA);
			this->splitContainerA2->Panel2MinSize = 0;
			this->splitContainerA2->Size = System::Drawing::Size(267, 407);
			this->splitContainerA2->SplitterDistance = 150;
			this->splitContainerA2->SplitterWidth = 3;
			this->splitContainerA2->TabIndex = 1;
			// 
			// splitContainerA3
			// 
			this->splitContainerA3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerA3->Location = System::Drawing::Point(0, 0);
			this->splitContainerA3->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerA3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerA3.Panel1
			// 
			this->splitContainerA3->Panel1->Controls->Add(this->listViewA1);
			this->splitContainerA3->Panel1MinSize = 0;
			// 
			// splitContainerA3.Panel2
			// 
			this->splitContainerA3->Panel2->Controls->Add(this->listViewA2);
			this->splitContainerA3->Panel2MinSize = 0;
			this->splitContainerA2->SplitterDistance = 150;
			this->splitContainerA2->SplitterWidth = 3;
			this->splitContainerA2->TabIndex = 1;
			// 
			// listViewA1
			// 
			this->listViewA1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewA1->ContextMenuStrip = this->contextMenuStripOfTreeViewA1;
			this->listViewA1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewA1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewA1->ForeColor = System::Drawing::Color::White;
			this->listViewA1->TabIndex = 1;
			// 
			// listViewA2
			// 
			this->listViewA2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewA2->ContextMenuStrip = this->contextMenuStripOfTreeViewA2;
			this->listViewA2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewA2->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewA2->ForeColor = System::Drawing::Color::White;
			this->listViewA2->TabIndex = 1;
			// 
			// contextMenuStripOfTreeViewA1
			// 
			this->contextMenuStripOfTreeViewA1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewTextureToolStripMenuItem,
					this->duplicateTextureToolStripMenuItem, this->deleteTextureToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewA1->Size = System::Drawing::Size(144, 92);
			// 
			// contextMenuStripOfTreeViewA2
			// 
			this->contextMenuStripOfTreeViewA2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewTextureLayerToolStripMenuItem,
					this->duplicateTextureLayerToolStripMenuItem,
					this->deleteTextureLayerToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewA2->Size = System::Drawing::Size(144, 92);
			// 
			// addNewTextureToolStripMenuItem
			// 
			this->addNewTextureToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewTextureToolStripMenuItem->Text = L"Add";
			// 
			// duplicateTextureToolStripMenuItem
			// 
			this->duplicateTextureToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateTextureToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteTextureToolStripMenuItem
			// 
			this->deleteTextureToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteTextureToolStripMenuItem->Text = L"Delete";
			// 
			// addNewTextureLayerToolStripMenuItem
			// 
			this->addNewTextureLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewTextureLayerToolStripMenuItem->Text = L"Add";
			// 
			// duplicateTextureLayerToolStripMenuItem
			// 
			this->duplicateTextureLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateTextureLayerToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteTextureLayerToolStripMenuItem
			// 
			this->deleteTextureLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteTextureLayerToolStripMenuItem->Text = L"Delete";
			// 
			// tableLayoutPanelA
			// 
			this->tableLayoutPanelA->AutoScroll = true;
			this->tableLayoutPanelA->ColumnCount = 1;

			this->tableLayoutPanelA->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelA->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelA->RowCount = 1;

			this->tableLayoutPanelA->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanelA->TabIndex = 1;


			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->splitContainerB1);
			this->tabPage3->Location = System::Drawing::Point(4, 24);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(776, 413);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"   Material   ";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// splitContainerB1
			// 
			this->splitContainerB1->BackColor = System::Drawing::Color::Gray;
			this->splitContainerB1->Cursor = System::Windows::Forms::Cursors::Default;
			this->splitContainerB1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerB1->Location = System::Drawing::Point(3, 3);
			this->splitContainerB1->Margin = System::Windows::Forms::Padding(0);
			// 
			// splitContainerB1.Panel1
			// 
			this->splitContainerB1->Panel1->BackColor = System::Drawing::Color::Gray;
			//this->splitContainerB1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainerB1->Panel1MinSize = 0;
			// 
			// splitContainerB1.Panel2
			// 
			this->splitContainerB1->Panel2->Controls->Add(this->splitContainerB2);
			this->splitContainerB1->Panel2MinSize = 0;
			this->splitContainerB1->Size = System::Drawing::Size(770, 407);
			this->splitContainerB1->SplitterDistance = 500;
			this->splitContainerB1->SplitterWidth = 3;
			this->splitContainerB1->TabIndex = 2;
			// 
			// splitContainerB2
			// 
			this->splitContainerB2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerB2->Location = System::Drawing::Point(0, 0);
			this->splitContainerB2->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerB2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerB2.Panel1
			// 
			this->splitContainerB2->Panel1->Controls->Add(this->splitContainerB3);
			this->splitContainerB2->Panel1MinSize = 0;
			// 
			// splitContainerB2.Panel2
			// 
			this->splitContainerB2->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->splitContainerB2->Panel2->Controls->Add(this->tableLayoutPanelB);
			this->splitContainerB2->Panel2MinSize = 0;
			this->splitContainerB2->Size = System::Drawing::Size(267, 407);
			this->splitContainerB2->SplitterDistance = 150;
			this->splitContainerB2->SplitterWidth = 3;
			this->splitContainerB2->TabIndex = 2;
			// 
			// splitContainerB3
			// 
			this->splitContainerB3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerB3->Location = System::Drawing::Point(0, 0);
			this->splitContainerB3->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerB3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerB3.Panel1
			// 
			this->splitContainerB3->Panel1->Controls->Add(this->listViewB1);
			this->splitContainerB3->Panel1MinSize = 0;
			// 
			// splitContainerB3.Panel2
			// 
			this->splitContainerB3->Panel2->Controls->Add(this->treeViewB1);
			this->splitContainerB3->Panel2MinSize = 0;
			this->splitContainerB2->SplitterDistance = 150;
			this->splitContainerB2->SplitterWidth = 3;
			this->splitContainerB2->TabIndex = 2;
			// 
			// listViewB1
			// 
			this->listViewB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewB1->ContextMenuStrip = this->contextMenuStripOfTreeViewB1;
			this->listViewB1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewB1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewB1->ForeColor = System::Drawing::Color::White;
			this->listViewB1->TabIndex = 2;
			// 
			// treeViewB1
			// 
			this->treeViewB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->treeViewB1->ContextMenuStrip = this->contextMenuStripOfTreeViewB2;
			this->treeViewB1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeViewB1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->treeViewB1->ForeColor = System::Drawing::Color::White;
			this->treeViewB1->TabIndex =2;
			// 
			// contextMenuStripOfTreeViewB1
			// 
			this->contextMenuStripOfTreeViewB1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewMaterialToolStripMenuItem,
					this->duplicateMaterialToolStripMenuItem,
					this->deleteMaterialToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewB1->Size = System::Drawing::Size(144, 92);
			// 
			// contextMenuStripOfTreeViewB2
			// 
			this->contextMenuStripOfTreeViewB2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewMaterialLayerToolStripMenuItem,
					this->duplicateMaterialLayerToolStripMenuItem,
					this->deleteMaterialLayerToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewB2->Size = System::Drawing::Size(144, 92);
			// 
			// addNewMaterialToolStripMenuItem
			// 
			this->addNewMaterialToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewMaterialToolStripMenuItem->Text = L"Add";
			// 
			// duplicateMaterialToolStripMenuItem
			// 
			this->duplicateMaterialToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateMaterialToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteMaterialToolStripMenuItem
			// 
			this->deleteMaterialToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteMaterialToolStripMenuItem->Text = L"Delete";
			// 
			// addNewMaterialLayerToolStripMenuItem
			// 
			this->addNewMaterialLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewMaterialLayerToolStripMenuItem->Text = L"Add";
			// 
			// duplicateMaterialLayerToolStripMenuItem
			// 
			this->duplicateMaterialLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateMaterialLayerToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteMaterialLayerToolStripMenuItem
			// 
			this->deleteMaterialLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteMaterialLayerToolStripMenuItem->Text = L"Delete";
			// 
			// tableLayoutPanelB
			// 
			this->tableLayoutPanelB->AutoScroll = true;
			this->tableLayoutPanelB->ColumnCount = 1;

			this->tableLayoutPanelB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelB->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelB->RowCount = 1;

			this->tableLayoutPanelB->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanelB->TabIndex = 2;


			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->splitContainerC1);
			this->tabPage4->Location = System::Drawing::Point(4, 24);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(776, 413);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"     Twig     ";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// splitContainerC1
			// 
			this->splitContainerC1->BackColor = System::Drawing::Color::Gray;
			this->splitContainerC1->Cursor = System::Windows::Forms::Cursors::Default;
			this->splitContainerC1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerC1->Location = System::Drawing::Point(3, 3);
			this->splitContainerC1->Margin = System::Windows::Forms::Padding(0);
			// 
			// splitContainerC1.Panel1
			// 
			this->splitContainerC1->Panel1->BackColor = System::Drawing::Color::Gray;
			//this->splitContainerC1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainerC1->Panel1MinSize = 0;
			// 
			// splitContainerC1.Panel2
			// 
			this->splitContainerC1->Panel2->Controls->Add(this->splitContainerC2);
			this->splitContainerC1->Panel2MinSize = 0;
			this->splitContainerC1->Size = System::Drawing::Size(770, 407);
			this->splitContainerC1->SplitterDistance = 500;
			this->splitContainerC1->SplitterWidth = 3;
			this->splitContainerC1->TabIndex = 3;
			// 
			// splitContainerC2
			// 
			this->splitContainerC2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerC2->Location = System::Drawing::Point(0, 0);
			this->splitContainerC2->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerC2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerC2.Panel1
			// 
			this->splitContainerC2->Panel1->Controls->Add(this->splitContainerC3);
			this->splitContainerC2->Panel1MinSize = 0;
			// 
			// splitContainerC2.Panel2
			// 
			this->splitContainerC2->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->splitContainerC2->Panel2->Controls->Add(this->tableLayoutPanelC);
			this->splitContainerC2->Panel2MinSize = 0;
			this->splitContainerC2->Size = System::Drawing::Size(267, 407);
			this->splitContainerC2->SplitterDistance = 150;
			this->splitContainerC2->SplitterWidth = 3;
			this->splitContainerC2->TabIndex = 3;
			// 
			// splitContainerC3
			// 
			this->splitContainerC3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerC3->Location = System::Drawing::Point(0, 0);
			this->splitContainerC3->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerC3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerC3.Panel1
			// 
			this->splitContainerC3->Panel1->Controls->Add(this->listViewC1);
			this->splitContainerC3->Panel1MinSize = 0;
			// 
			// splitContainerC3.Panel2
			// 
			this->splitContainerC3->Panel2->Controls->Add(this->listViewC2);
			this->splitContainerC3->Panel2MinSize = 0;
			this->splitContainerC2->SplitterDistance = 150;
			this->splitContainerC2->SplitterWidth = 3;
			this->splitContainerC2->TabIndex = 3;
			// 
			// listViewC1
			// 
			this->listViewC1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewC1->ContextMenuStrip = this->contextMenuStripOfTreeViewC1;
			this->listViewC1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewC1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewC1->ForeColor = System::Drawing::Color::White;
			this->listViewC1->TabIndex = 3;
			// 
			// listViewC2
			// 
			this->listViewC2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewC2->ContextMenuStrip = this->contextMenuStripOfTreeViewC2;
			this->listViewC2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewC2->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewC2->ForeColor = System::Drawing::Color::White;
			this->listViewC2->TabIndex = 3;
			// 
			// contextMenuStripOfTreeViewC1
			// 
			this->contextMenuStripOfTreeViewC1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewTwigToolStripMenuItem,
					this->duplicateTwigToolStripMenuItem,
					this->deleteTwigToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewC1->Size = System::Drawing::Size(144, 92);
			// 
			// contextMenuStripOfTreeViewC2
			// 
			this->contextMenuStripOfTreeViewC2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addNewTwigLayerToolStripMenuItem,
					this->duplicateTwigLayerToolStripMenuItem,
					this->deleteTwigLayerToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewC2->Size = System::Drawing::Size(144, 92);
			// 
			// addNewTwigToolStripMenuItem
			// 
			this->addNewTwigToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewTwigToolStripMenuItem->Text = L"Add";
			// 
			// duplicateTwigToolStripMenuItem
			// 
			this->duplicateTwigToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateTwigToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteTwigToolStripMenuItem
			// 
			this->deleteTwigToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteTwigToolStripMenuItem->Text = L"Delete";
			// 
			// addNewTwigLayerToolStripMenuItem
			// 
			this->addNewTwigLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addNewTwigLayerToolStripMenuItem->Text = L"Add";
			// 
			// duplicateTwigLayerToolStripMenuItem
			// 
			this->duplicateTwigLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateTwigLayerToolStripMenuItem->Text = L"Duplicate";
			// 
			// deleteTwigLayerToolStripMenuItem
			// 
			this->deleteTwigLayerToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteTwigLayerToolStripMenuItem->Text = L"Delete";
			// 
			// tableLayoutPanelC
			// 
			this->tableLayoutPanelC->AutoScroll = true;
			this->tableLayoutPanelC->ColumnCount = 1;

			this->tableLayoutPanelC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelC->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelC->RowCount = 1;

			this->tableLayoutPanelC->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanelC->TabIndex = 3;


			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->splitContainerD1);
			this->tabPage5->Location = System::Drawing::Point(4, 24);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(776, 413);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"   Generator  ";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// splitContainerD1
			// 
			this->splitContainerD1->BackColor = System::Drawing::Color::Gray;
			this->splitContainerD1->Cursor = System::Windows::Forms::Cursors::Default;
			this->splitContainerD1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerD1->Location = System::Drawing::Point(3, 3);
			this->splitContainerD1->Margin = System::Windows::Forms::Padding(0);
			// 
			// splitContainerD1.Panel1
			// 
			this->splitContainerD1->Panel1->BackColor = System::Drawing::Color::Gray;
			//this->splitContainerD1->Panel1->Controls->Add(this->pictureBox1);
			this->splitContainerD1->Panel1MinSize = 0;
			// 
			// splitContainerD1.Panel2
			// 
			this->splitContainerD1->Panel2->Controls->Add(this->splitContainerD2);
			this->splitContainerD1->Panel2MinSize = 0;
			this->splitContainerD1->Size = System::Drawing::Size(770, 407);
			this->splitContainerD1->SplitterDistance = 500;
			this->splitContainerD1->SplitterWidth = 3;
			this->splitContainerD1->TabIndex = 4;
			// 
			// splitContainerD2
			// 
			this->splitContainerD2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerD2->Location = System::Drawing::Point(0, 0);
			this->splitContainerD2->Margin = System::Windows::Forms::Padding(0);
			this->splitContainerD2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainerD2.Panel1
			// 
			this->splitContainerD2->Panel1->Controls->Add(this->listViewD1);
			this->splitContainerD2->Panel1MinSize = 0;
			// 
			// splitContainerD2.Panel2
			// 
			this->splitContainerD2->Panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->splitContainerD2->Panel2->Controls->Add(this->tableLayoutPanelD);
			this->splitContainerD2->Panel2MinSize = 0;
			this->splitContainerD2->Size = System::Drawing::Size(267, 407);
			this->splitContainerD2->SplitterDistance = 150;
			this->splitContainerD2->SplitterWidth = 3;
			this->splitContainerD2->TabIndex = 4;
			// 
			// listViewD1
			// 
			this->listViewD1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewD1->ContextMenuStrip = this->contextMenuStripOfTreeViewD1;
			this->listViewD1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listViewD1->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->listViewD1->ForeColor = System::Drawing::Color::White;
			this->listViewD1->TabIndex = 4;
			this->listViewD1->View = View::Details;
			this->listViewD1->Columns->Add(gcnew ColumnHeader());
			this->listViewD1->HeaderStyle = ColumnHeaderStyle::None;
			this->listViewD1->LabelEdit = true;
			this->listViewD1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listViewD1_SelectedIndexChanged);
			// 
			// contextMenuStripOfTreeViewD1
			// 
			this->contextMenuStripOfTreeViewD1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addObjectToolStripMenuItem,
					this->addTreeToolStripMenuItem,
					this->duplicateObjTreToolStripMenuItem,
					this->deleteObjTreToolStripMenuItem
			});
			this->contextMenuStripOfTreeViewD1->Size = System::Drawing::Size(144, 92);
			// 
			// addObjectToolStripMenuItem
			// 
			this->addObjectToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addObjectToolStripMenuItem->Text = L"Add Object";
			this->addObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::AddObject);
			// 
			// addTreeToolStripMenuItem
			// 
			this->addTreeToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addTreeToolStripMenuItem->Text = L"Add Tree";
			this->addTreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::AddTree);
			// 
			// duplicateObjTreToolStripMenuItem
			// 
			this->duplicateObjTreToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->duplicateObjTreToolStripMenuItem->Text = L"Duplicate";
			this->duplicateObjTreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::DuplicateObjTre);
			// 
			// deleteObjTreToolStripMenuItem
			// 
			this->deleteObjTreToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->deleteObjTreToolStripMenuItem->Text = L"Delete";
			this->deleteObjTreToolStripMenuItem-> Click += gcnew System::EventHandler(this, &MyForm::DeleteObjTre);
			// 
			// tableLayoutPanelD
			// 
			this->tableLayoutPanelD->AutoScroll = true;
			this->tableLayoutPanelD->ColumnCount = 1;

			this->tableLayoutPanelD->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelD->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelD->RowCount = 1;

			this->tableLayoutPanelD->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanelD->TabIndex = 4;
			this->tableLayoutPanelD->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::tableLayoutPanelD_Scroll);
			this->tableLayoutPanelD->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::tableLayoutPanelD_MouseWheel);

			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->tableLayoutPanelE);
			this->tabPage6->Location = System::Drawing::Point(4, 24);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(776, 413);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"     Info      ";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanelE
			// 
			this->tableLayoutPanelE->AutoScroll = true;
			this->tableLayoutPanelE->ColumnCount = 1;

			this->tableLayoutPanelE->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelE->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelE->RowCount = 1;

			this->tableLayoutPanelE->Size = System::Drawing::Size(267, 254);
			this->tableLayoutPanelE->TabIndex = 5;

			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 441);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);

			this->tabPage1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->contextMenuStripOfTreeView->ResumeLayout(false);

			this->tabPage2->ResumeLayout(false);
			this->splitContainerA1->Panel1->ResumeLayout(false);
			this->splitContainerA1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA1))->EndInit();
			this->splitContainerA1->ResumeLayout(false);
			this->splitContainerA2->Panel1->ResumeLayout(false);
			this->splitContainerA2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA2))->EndInit();
			this->splitContainerA2->ResumeLayout(false);
			this->splitContainerA3->Panel1->ResumeLayout(false);
			this->splitContainerA3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerA3))->EndInit();
			this->splitContainerA3->ResumeLayout(false);
			this->contextMenuStripOfTreeViewA1->ResumeLayout(false);
			this->contextMenuStripOfTreeViewA2->ResumeLayout(false);

			this->tabPage3->ResumeLayout(false);
			this->splitContainerB1->Panel1->ResumeLayout(false);
			this->splitContainerB1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB1))->EndInit();
			this->splitContainerB1->ResumeLayout(false);
			this->splitContainerB2->Panel1->ResumeLayout(false);
			this->splitContainerB2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB2))->EndInit();
			this->splitContainerB2->ResumeLayout(false);
			this->splitContainerB3->Panel1->ResumeLayout(false);
			this->splitContainerB3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerB3))->EndInit();
			this->splitContainerB3->ResumeLayout(false);
			this->contextMenuStripOfTreeViewB1->ResumeLayout(false);
			this->contextMenuStripOfTreeViewB2->ResumeLayout(false);

			this->tabPage4->ResumeLayout(false);
			this->splitContainerC1->Panel1->ResumeLayout(false);
			this->splitContainerC1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC1))->EndInit();
			this->splitContainerC1->ResumeLayout(false);
			this->splitContainerC2->Panel1->ResumeLayout(false);
			this->splitContainerC2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC2))->EndInit();
			this->splitContainerC2->ResumeLayout(false);
			this->splitContainerC3->Panel1->ResumeLayout(false);
			this->splitContainerC3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerC3))->EndInit();
			this->splitContainerC3->ResumeLayout(false);
			this->contextMenuStripOfTreeViewC1->ResumeLayout(false);
			this->contextMenuStripOfTreeViewC2->ResumeLayout(false);

			this->tabPage5->ResumeLayout(false);
			this->splitContainerD1->Panel1->ResumeLayout(false);
			this->splitContainerD1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerD1))->EndInit();
			this->splitContainerD1->ResumeLayout(false);
			this->splitContainerD2->Panel1->ResumeLayout(false);
			this->splitContainerD2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerD2))->EndInit();
			this->splitContainerD2->ResumeLayout(false);
			this->contextMenuStripOfTreeViewD1->ResumeLayout(false);

			this->tabPage6->ResumeLayout(false);

			this->ResumeLayout(false);

		}

#pragma endregion
	private:void setTableLayoutPanelControlComponent(void) {
		//FotItem
		this->label0 = (gcnew Label());
		this->label1 = (gcnew Label());
		this->label2 = (gcnew Label());
		this->label3 = (gcnew Label());
		this->label4 = (gcnew Label());
		this->label5 = (gcnew Label());
		this->label6 = (gcnew Label());
		this->label7 = (gcnew Label());
		this->label8 = (gcnew Label());
		this->label9 = (gcnew Label());
		this->label10 = (gcnew Label());
		this->label11 = (gcnew Label());
		this->label12 = (gcnew Label());
		this->label13 = (gcnew Label());
		this->label14 = (gcnew Label());
		this->label15 = (gcnew Label());
		this->label16 = (gcnew Label());
		this->label17 = (gcnew Label());
		this->label18 = (gcnew Label());
		this->label19 = (gcnew Label());
		this->label20 = (gcnew Label());
		this->label21 = (gcnew Label());
		this->label22 = (gcnew Label());
		this->label23 = (gcnew Label());
		this->label24 = (gcnew Label());
		this->label25 = (gcnew Label());
		this->label26 = (gcnew Label());
		this->comboBox0 = (gcnew ComboBox());
		this->comboBox1 = (gcnew ComboBox());
		this->comboBox2 = (gcnew ComboBox());
		this->comboBox3 = (gcnew ComboBox());
		this->chart0 = (gcnew DataVisualization::Charting::Chart());
		this->chart1 = (gcnew DataVisualization::Charting::Chart());
		this->chart2 = (gcnew DataVisualization::Charting::Chart());
		this->textBox0 = (gcnew TextBox());
		this->textBox1 = (gcnew TextBox());
		this->textBox2 = (gcnew TextBox());
		this->textBox3 = (gcnew TextBox());
		this->textBox4 = (gcnew TextBox());
		this->textBox5 = (gcnew TextBox());
		this->textBox6 = (gcnew TextBox());
		this->textBox7 = (gcnew TextBox());
		this->textBox8 = (gcnew TextBox());
		this->textBox9 = (gcnew TextBox());
		this->textBox10 = (gcnew TextBox());
		this->textBox11 = (gcnew TextBox());
		this->textBox12 = (gcnew TextBox());
		this->textBox13 = (gcnew TextBox());
		this->textBox14 = (gcnew TextBox());
		this->textBox15 = (gcnew TextBox());
		this->textBox16 = (gcnew TextBox());
		this->textBox17 = (gcnew TextBox());
		this->textBox18 = (gcnew TextBox());
		this->textBox19 = (gcnew TextBox());
		this->trackBar0 = (gcnew TrackBar());
		this->trackBar1 = (gcnew TrackBar());
		this->trackBar2 = (gcnew TrackBar());
		this->trackBar3 = (gcnew TrackBar());
		this->trackBar4 = (gcnew TrackBar());
		this->trackBar5 = (gcnew TrackBar());
		this->trackBar6 = (gcnew TrackBar());
		this->trackBar7 = (gcnew TrackBar());
		this->trackBar8 = (gcnew TrackBar());
		this->trackBar9 = (gcnew TrackBar());
		this->trackBar10 = (gcnew TrackBar());
		this->trackBar11 = (gcnew TrackBar());
		this->trackBar12 = (gcnew TrackBar());
		this->trackBar13 = (gcnew TrackBar());
		this->trackBar14 = (gcnew TrackBar());
		this->trackBar15 = (gcnew TrackBar());
		this->trackBar16 = (gcnew TrackBar());
		this->trackBar17 = (gcnew TrackBar());
		this->trackBar18 = (gcnew TrackBar());
		this->trackBar19 = (gcnew TrackBar());
		this->trackBar20 = (gcnew TrackBar());
		this->trackBar21 = (gcnew TrackBar());
		this->trackBar22 = (gcnew TrackBar());
		this->trackBar23 = (gcnew TrackBar());
		this->trackBar24 = (gcnew TrackBar());
		this->trackBar25 = (gcnew TrackBar());

		//ForTexture


		//ForMaterial


		//ForTwig


		//ForGenerator
		this->labelD0 = (gcnew Label());
		this->labelD1 = (gcnew Label());
		this->labelD2 = (gcnew Label());
		this->labelD3 = (gcnew Label());
		this->labelD4 = (gcnew Label());
		this->labelD5 = (gcnew Label());
		this->labelD6 = (gcnew Label());
		this->labelD7 = (gcnew Label());
		this->labelD8 = (gcnew Label());
		this->labelD9 = (gcnew Label());
		this->labelD10 = (gcnew Label());
		this->labelD11 = (gcnew Label());
		this->labelD12 = (gcnew Label());
		this->labelD13 = (gcnew Label());
		this->labelD14 = (gcnew Label());

		this->comboBoxD0 = (gcnew ComboBox());

		this->textBoxD0 = (gcnew TextBox());
		this->textBoxD1 = (gcnew TextBox());
		this->textBoxD2 = (gcnew TextBox());
		this->textBoxD3 = (gcnew TextBox());
		this->textBoxD4 = (gcnew TextBox());
		this->textBoxD5 = (gcnew TextBox());
		this->textBoxD6 = (gcnew TextBox());
		this->textBoxD7 = (gcnew TextBox());
		this->textBoxD8 = (gcnew TextBox());
		this->textBoxD9 = (gcnew TextBox());
		this->textBoxD10 = (gcnew TextBox());
		this->textBoxD11 = (gcnew TextBox());
		this->textBoxD12 = (gcnew TextBox());
		this->textBoxD13 = (gcnew TextBox());
		this->textBoxD14 = (gcnew TextBox());
		this->textBoxD15 = (gcnew TextBox());

		this->trackBarD0 = (gcnew TrackBar());
		this->trackBarD1 = (gcnew TrackBar());
		this->trackBarD2 = (gcnew TrackBar());
		this->trackBarD3 = (gcnew TrackBar());
		this->trackBarD4 = (gcnew TrackBar());
		this->trackBarD5 = (gcnew TrackBar());
		this->trackBarD6 = (gcnew TrackBar());
		this->trackBarD7 = (gcnew TrackBar());
		this->trackBarD8 = (gcnew TrackBar());
		this->trackBarD9 = (gcnew TrackBar());
		this->trackBarD10 = (gcnew TrackBar());
		this->trackBarD11 = (gcnew TrackBar());
		this->trackBarD12 = (gcnew TrackBar());
		this->trackBarD13 = (gcnew TrackBar());

		this->buttonD0 = (gcnew Button());
		this->buttonD1 = (gcnew Button());

		//ForInfo
		this->buttonE0 = (gcnew Button());
		this->buttonE1 = (gcnew Button());
	};

	/*
■■■■■■■■■■■                         ■■■■■■■■                                            
■■■■■■■■■■■                          ■■■■■■     ■■                                      
■■                                     ■■       ■■                                      
■■                                     ■■       ■■                                      
■■                                     ■■       ■■                                      
■■               ■■■■       ■■  ■■■    ■■     ■■■■■■■      ■■■■       ■■  ■■■■    ■■■■  
■■             ■■■■■■■■     ■■ ■■■■    ■■     ■■■■■■■    ■■■■■■■■     ■■ ■■■■■■ ■■■■■■■ 
■■            ■■■    ■■■    ■■■        ■■       ■■      ■■■    ■■■    ■■■    ■■■■    ■■■
■■■■■■■■■■    ■■      ■■    ■■         ■■       ■■      ■■      ■■    ■■      ■■      ■■
■■■■■■■■■■   ■■        ■■   ■■         ■■       ■■     ■■       ■■    ■■      ■■      ■■
■■           ■■        ■■   ■■         ■■       ■■     ■■■      ■■■   ■■      ■■      ■■
■■           ■■        ■■   ■■         ■■       ■■     ■■■■■■■■■■■■   ■■      ■■      ■■
■■           ■■        ■■   ■■         ■■       ■■     ■■             ■■      ■■      ■■
■■           ■■        ■■   ■■         ■■       ■■     ■■             ■■      ■■      ■■
■■            ■■      ■■    ■■         ■■       ■■      ■■      ■     ■■      ■■      ■■
■■            ■■■    ■■■    ■■         ■■       ■■      ■■■    ■■■    ■■      ■■      ■■
■■             ■■■■■■■■     ■■       ■■■■■■     ■■■■     ■■■■■■■■     ■■      ■■      ■■
■■               ■■■■       ■■      ■■■■■■■■     ■■■■      ■■■■■      ■■      ■■      ■■
	*/


	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
		i.SetPropNodeName(treeView1->SelectedNode->Name);
		i.ScrollX = 0;
		i.ScrollY = 0;
		i.Chart0Point = 0;
		i.Chart1Point = 0;
		i.Chart2Point = 0;
		tableLayoutPanel->SuspendLayout();
		for (int i = 0; i < tableLayoutPanel->RowCount; i++) {
			for (int s = 0; s < tableLayoutPanel->ColumnCount; s++) {
				tableLayoutPanel->Controls->Remove(tableLayoutPanel->GetControlFromPosition(s, i));
			}
		}
		tableLayoutPanel->ColumnCount = 0;
		tableLayoutPanel->RowCount = 0;
		tableLayoutPanel->AutoScrollPosition = Point (0,0);
		tableLayoutPanel->SetColumnSpan(label0, 1);
		tableLayoutPanel->SetColumnSpan(label1, 1);
		tableLayoutPanel->SetColumnSpan(label2, 1);
		tableLayoutPanel->SetColumnSpan(label3, 1);
		tableLayoutPanel->SetColumnSpan(label4, 1);
		tableLayoutPanel->SetColumnSpan(label5, 1);
		tableLayoutPanel->SetColumnSpan(label6, 1);
		tableLayoutPanel->SetColumnSpan(label7, 1);
		tableLayoutPanel->SetColumnSpan(label8, 1);
		tableLayoutPanel->SetColumnSpan(label9, 1);
		tableLayoutPanel->SetColumnSpan(label10, 1);
		tableLayoutPanel->SetColumnSpan(label11, 1);
		tableLayoutPanel->SetColumnSpan(label12, 1);
		tableLayoutPanel->SetColumnSpan(label13, 1);
		tableLayoutPanel->SetColumnSpan(label14, 1);
		tableLayoutPanel->SetColumnSpan(label15, 1);
		tableLayoutPanel->SetColumnSpan(label16, 1);
		tableLayoutPanel->SetColumnSpan(label17, 1);
		tableLayoutPanel->SetColumnSpan(label18, 1);
		tableLayoutPanel->SetColumnSpan(label19, 1);
		tableLayoutPanel->SetColumnSpan(label20, 1);
		tableLayoutPanel->SetColumnSpan(label21, 1);
		tableLayoutPanel->SetColumnSpan(label22, 1);
		tableLayoutPanel->SetColumnSpan(label23, 1);
		tableLayoutPanel->SetColumnSpan(label24, 1);
		tableLayoutPanel->SetColumnSpan(label25, 1);
		tableLayoutPanel->SetColumnSpan(label26, 1);
		tableLayoutPanel->SetColumnSpan(comboBox0, 1);
		tableLayoutPanel->SetColumnSpan(comboBox1, 1);
		tableLayoutPanel->SetColumnSpan(comboBox2, 1);
		tableLayoutPanel->SetColumnSpan(comboBox3, 1);
		tableLayoutPanel->SetColumnSpan(chart0, 1);
		tableLayoutPanel->SetColumnSpan(chart1, 1);
		tableLayoutPanel->SetColumnSpan(chart2, 1);
		tableLayoutPanel->SetColumnSpan(textBox0, 1);
		tableLayoutPanel->SetColumnSpan(textBox1, 1);
		tableLayoutPanel->SetColumnSpan(textBox2, 1);
		tableLayoutPanel->SetColumnSpan(textBox3, 1);
		tableLayoutPanel->SetColumnSpan(textBox4, 1);
		tableLayoutPanel->SetColumnSpan(textBox5, 1);
		tableLayoutPanel->SetColumnSpan(textBox6, 1);
		tableLayoutPanel->SetColumnSpan(textBox7, 1);
		tableLayoutPanel->SetColumnSpan(textBox8, 1);
		tableLayoutPanel->SetColumnSpan(textBox9, 1);
		tableLayoutPanel->SetColumnSpan(textBox10, 1);
		tableLayoutPanel->SetColumnSpan(textBox11, 1);
		tableLayoutPanel->SetColumnSpan(textBox12, 1);
		tableLayoutPanel->SetColumnSpan(textBox13, 1);
		tableLayoutPanel->SetColumnSpan(textBox14, 1);
		tableLayoutPanel->SetColumnSpan(textBox15, 1);
		tableLayoutPanel->SetColumnSpan(textBox16, 1);
		tableLayoutPanel->SetColumnSpan(textBox17, 1);
		tableLayoutPanel->SetColumnSpan(textBox18, 1);
		tableLayoutPanel->SetColumnSpan(textBox19, 1);
		tableLayoutPanel->SetColumnSpan(trackBar0, 1);
		tableLayoutPanel->SetColumnSpan(trackBar1, 1);
		tableLayoutPanel->SetColumnSpan(trackBar2, 1);
		tableLayoutPanel->SetColumnSpan(trackBar3, 1);
		tableLayoutPanel->SetColumnSpan(trackBar4, 1);
		tableLayoutPanel->SetColumnSpan(trackBar5, 1);
		tableLayoutPanel->SetColumnSpan(trackBar6, 1);
		tableLayoutPanel->SetColumnSpan(trackBar7, 1);
		tableLayoutPanel->SetColumnSpan(trackBar8, 1);
		tableLayoutPanel->SetColumnSpan(trackBar9, 1);
		tableLayoutPanel->SetColumnSpan(trackBar10, 1);
		tableLayoutPanel->SetColumnSpan(trackBar11, 1);
		tableLayoutPanel->SetColumnSpan(trackBar12, 1);
		tableLayoutPanel->SetColumnSpan(trackBar13, 1);
		tableLayoutPanel->SetColumnSpan(trackBar14, 1);
		tableLayoutPanel->SetColumnSpan(trackBar15, 1);
		tableLayoutPanel->SetColumnSpan(trackBar16, 1);
		tableLayoutPanel->SetColumnSpan(trackBar17, 1);
		tableLayoutPanel->SetColumnSpan(trackBar18, 1);
		tableLayoutPanel->SetColumnSpan(trackBar19, 1);
		tableLayoutPanel->SetColumnSpan(trackBar20, 1);
		tableLayoutPanel->SetColumnSpan(trackBar21, 1);
		tableLayoutPanel->SetColumnSpan(trackBar22, 1);
		tableLayoutPanel->SetColumnSpan(trackBar23, 1);
		tableLayoutPanel->SetColumnSpan(trackBar24, 1);
		tableLayoutPanel->SetColumnSpan(trackBar25, 1);
		tableLayoutPanel->SetRowSpan(label0, 1);
		tableLayoutPanel->SetRowSpan(label1, 1);
		tableLayoutPanel->SetRowSpan(label2, 1);
		tableLayoutPanel->SetRowSpan(label3, 1);
		tableLayoutPanel->SetRowSpan(label4, 1);
		tableLayoutPanel->SetRowSpan(label5, 1);
		tableLayoutPanel->SetRowSpan(label6, 1);
		tableLayoutPanel->SetRowSpan(label7, 1);
		tableLayoutPanel->SetRowSpan(label8, 1);
		tableLayoutPanel->SetRowSpan(label9, 1);
		tableLayoutPanel->SetRowSpan(label10, 1);
		tableLayoutPanel->SetRowSpan(label11, 1);
		tableLayoutPanel->SetRowSpan(label12, 1);
		tableLayoutPanel->SetRowSpan(label13, 1);
		tableLayoutPanel->SetRowSpan(label14, 1);
		tableLayoutPanel->SetRowSpan(label15, 1);
		tableLayoutPanel->SetRowSpan(label16, 1);
		tableLayoutPanel->SetRowSpan(label17, 1);
		tableLayoutPanel->SetRowSpan(label18, 1);
		tableLayoutPanel->SetRowSpan(label19, 1);
		tableLayoutPanel->SetRowSpan(label20, 1);
		tableLayoutPanel->SetRowSpan(label21, 1);
		tableLayoutPanel->SetRowSpan(label22, 1);
		tableLayoutPanel->SetRowSpan(label23, 1);
		tableLayoutPanel->SetRowSpan(label24, 1);
		tableLayoutPanel->SetRowSpan(label25, 1);
		tableLayoutPanel->SetRowSpan(label26, 1);
		tableLayoutPanel->SetRowSpan(comboBox0, 1);
		tableLayoutPanel->SetRowSpan(comboBox1, 1);
		tableLayoutPanel->SetRowSpan(comboBox2, 1);
		tableLayoutPanel->SetRowSpan(comboBox3, 1);
		tableLayoutPanel->SetRowSpan(chart0, 1);
		tableLayoutPanel->SetRowSpan(chart1, 1);
		tableLayoutPanel->SetRowSpan(chart2, 1);
		tableLayoutPanel->SetRowSpan(textBox0, 1);
		tableLayoutPanel->SetRowSpan(textBox1, 1);
		tableLayoutPanel->SetRowSpan(textBox2, 1);
		tableLayoutPanel->SetRowSpan(textBox3, 1);
		tableLayoutPanel->SetRowSpan(textBox4, 1);
		tableLayoutPanel->SetRowSpan(textBox5, 1);
		tableLayoutPanel->SetRowSpan(textBox6, 1);
		tableLayoutPanel->SetRowSpan(textBox7, 1);
		tableLayoutPanel->SetRowSpan(textBox8, 1);
		tableLayoutPanel->SetRowSpan(textBox9, 1);
		tableLayoutPanel->SetRowSpan(textBox10, 1);
		tableLayoutPanel->SetRowSpan(textBox11, 1);
		tableLayoutPanel->SetRowSpan(textBox12, 1);
		tableLayoutPanel->SetRowSpan(textBox13, 1);
		tableLayoutPanel->SetRowSpan(textBox14, 1);
		tableLayoutPanel->SetRowSpan(textBox15, 1);
		tableLayoutPanel->SetRowSpan(textBox16, 1);
		tableLayoutPanel->SetRowSpan(textBox17, 1);
		tableLayoutPanel->SetRowSpan(textBox18, 1);
		tableLayoutPanel->SetRowSpan(textBox19, 1);
		tableLayoutPanel->SetRowSpan(trackBar0, 1);
		tableLayoutPanel->SetRowSpan(trackBar1, 1);
		tableLayoutPanel->SetRowSpan(trackBar2, 1);
		tableLayoutPanel->SetRowSpan(trackBar3, 1);
		tableLayoutPanel->SetRowSpan(trackBar4, 1);
		tableLayoutPanel->SetRowSpan(trackBar5, 1);
		tableLayoutPanel->SetRowSpan(trackBar6, 1);
		tableLayoutPanel->SetRowSpan(trackBar7, 1);
		tableLayoutPanel->SetRowSpan(trackBar8, 1);
		tableLayoutPanel->SetRowSpan(trackBar9, 1);
		tableLayoutPanel->SetRowSpan(trackBar10, 1);
		tableLayoutPanel->SetRowSpan(trackBar11, 1);
		tableLayoutPanel->SetRowSpan(trackBar12, 1);
		tableLayoutPanel->SetRowSpan(trackBar13, 1);
		tableLayoutPanel->SetRowSpan(trackBar14, 1);
		tableLayoutPanel->SetRowSpan(trackBar15, 1);
		tableLayoutPanel->SetRowSpan(trackBar16, 1);
		tableLayoutPanel->SetRowSpan(trackBar17, 1);
		tableLayoutPanel->SetRowSpan(trackBar18, 1);
		tableLayoutPanel->SetRowSpan(trackBar19, 1);
		tableLayoutPanel->SetRowSpan(trackBar20, 1);
		tableLayoutPanel->SetRowSpan(trackBar21, 1);
		tableLayoutPanel->SetRowSpan(trackBar22, 1);
		tableLayoutPanel->SetRowSpan(trackBar23, 1);
		tableLayoutPanel->SetRowSpan(trackBar24, 1);
		tableLayoutPanel->SetRowSpan(trackBar25, 1);
		trackBar0->Orientation = Orientation::Horizontal;
		trackBar1->Orientation = Orientation::Horizontal;
		trackBar2->Orientation = Orientation::Horizontal;
		trackBar3->Orientation = Orientation::Horizontal;
		trackBar4->Orientation = Orientation::Horizontal;
		trackBar5->Orientation = Orientation::Horizontal;
		trackBar6->Orientation = Orientation::Horizontal;
		trackBar7->Orientation = Orientation::Horizontal;
		trackBar8->Orientation = Orientation::Horizontal;
		trackBar9->Orientation = Orientation::Horizontal;
		trackBar10->Orientation = Orientation::Horizontal;
		trackBar11->Orientation = Orientation::Horizontal;
		trackBar12->Orientation = Orientation::Horizontal;
		trackBar13->Orientation = Orientation::Horizontal;
		trackBar14->Orientation = Orientation::Horizontal;
		trackBar15->Orientation = Orientation::Horizontal;
		trackBar16->Orientation = Orientation::Horizontal;
		trackBar17->Orientation = Orientation::Horizontal;
		trackBar18->Orientation = Orientation::Horizontal;
		trackBar19->Orientation = Orientation::Horizontal;
		trackBar20->Orientation = Orientation::Horizontal;
		trackBar21->Orientation = Orientation::Horizontal;
		trackBar22->Orientation = Orientation::Horizontal;
		trackBar23->Orientation = Orientation::Horizontal;
		trackBar24->Orientation = Orientation::Horizontal;
		trackBar25->Orientation = Orientation::Horizontal;

		switch (treeView1->SelectedNode->Text->ToCharArray()[0]){
		case 'B':
			SetBPropertyPanel(treeView1->SelectedNode->Name);
			break;
		case 'b':
			SetbPropertyPanel(treeView1->SelectedNode->Name);
			break;
		case 'T':
			SetTPropertyPanel(treeView1->SelectedNode->Name);
			break;
		case 't':
			SettPropertyPanel(treeView1->SelectedNode->Name);
			break;
		case 'F':
			SetFPropertyPanel(treeView1->SelectedNode->Name);
			break;
		default:
			break;
		}
		tableLayoutPanel->ResumeLayout(true);
	}
		   private: System::Void MakeBranch(System::Object^ sender, System::EventArgs^ e) {
				   if (treeView1->SelectedNode->Text == "R" || treeView1->SelectedNode->Text == "B"
					   || treeView1->SelectedNode->Text == "b") {
					   TreeNode^ treenode = gcnew TreeNode();
					   treenode->Text = "B";
					   treenode->Name = treeView1->SelectedNode->Name + "-" + "B" + i.c_num(treeView1->SelectedNode->Name);
					   treeView1->SelectedNode->Nodes->Add(treenode);
					   TreeNode^ treenodeG = gcnew TreeNode();
					   treenodeG->Text = "G";
					   treenode->Nodes->Add(treenodeG);
					   TreeNode^ treenodeg = gcnew TreeNode();
					   treenodeg->Text = "b";
					   treenodeg->Name = treenode->Name + "-" + "b" + 0;
					   treenodeG->Nodes->Add(treenodeg);
					   i.NodeBCreate(treeView1->SelectedNode->Name);
					   System::Diagnostics::Debug::WriteLine(treenode->Name);
					   System::Diagnostics::Debug::WriteLine(treenodeg->Name);
				   }
				   nodetotexttrigger();
		   }

private: System::Void MakeTwig(System::Object^ sender, System::EventArgs^ e) {
	if (treeView1->SelectedNode->Text == "R" || treeView1->SelectedNode->Text == "B"
		|| treeView1->SelectedNode->Text == "b") {
		TreeNode^ treenode = gcnew TreeNode();
		treenode->Text = "T";
		treenode->Name = treeView1->SelectedNode->Name + "-" + "T" + i.c_num(treeView1->SelectedNode->Name);
		treeView1->SelectedNode->Nodes->Add(treenode);
		TreeNode^ treenodeG = gcnew TreeNode();
		treenodeG->Text = "G";
		treenode->Nodes->Add(treenodeG);
		TreeNode^ treenodeg = gcnew TreeNode();
		treenodeg->Text = "t";
		treenodeg->Name = treenode->Name + "-" + "t" + 0;
		treenodeG->Nodes->Add(treenodeg);
		i.NodeTCreate(treeView1->SelectedNode->Name);
		System::Diagnostics::Debug::WriteLine(treenode->Name);
		System::Diagnostics::Debug::WriteLine(treenodeg->Name);
	}
}
/*
private: System::Void MakeFractal(System::Object^ sender, System::EventArgs^ e) {
		   if (treeView1->SelectedNode->Text == "R" || treeView1->SelectedNode->Text == "B"
			   || treeView1->SelectedNode->Text == "b") {
			   TreeNode^ treenode = gcnew TreeNode();
			   treenode->Text = "F";
			   treenode->Name = treeView1->SelectedNode->Name + "-" + "F" + i.c_num(treeView1->SelectedNode->Name);
			   treeView1->SelectedNode->Nodes->Add(treenode);
			   i.NodeFCreate(treeView1->SelectedNode->Name);
			   System::Diagnostics::Debug::WriteLine(treenode->Name);
		   }
}*/

	   private: System::Void DeleteNode(System::Object^ sender, System::EventArgs^ e) {
		   if (treeView1->SelectedNode->Text == "B" || treeView1->SelectedNode->Text == "T" || treeView1->SelectedNode->Text == "F") {
			   i.NodeDelete(treeView1->SelectedNode->Name);
			   treeView1->SelectedNode->Remove();
		   }
	   }

 private:void SetBPropertyPanel(String^ SelectedNodeName) {//表示のされ方が変な時はintializeに追加されてるtablelayoutpanelのstileあたりを消す!
		   label0->Text = "GroupNum";
		   label1->Text = "Texture";
		   label2->Text = "Rings";
		   label3->Text = "ShapeDivisionNum";
		   label4->Text = "RadiusDivisionNum";
		   label5->Text = "BirthPlace";
		   label6->Text = "BirthPlaceRandomize";
		   label7->Text = "Length";
		   label8->Text = "LengthRandomize";
		   label9->Text = "XRotation";
		   label10->Text = "YRotation";
		   label11->Text = "ZRotation";
		   label12->Text = "XRotationRandomize";
		   label13->Text = "YRotationRandomize";
		   label14->Text = "ZRotationRandomize";
		   label15->Text = "BaseRadius";
		   label16->Text = "BaseRadiusRandomize";
		   label17->Text = "BaseRadiusGraphType";
		   label18->Text = "BaseRadiusGraphPointNum";
		   label19->Text = "BaseRadiusGraph";
		   label20->Text = "ShapeGraphRandomize";
		   label21->Text = "ShapeGraphType";
		   label22->Text = "ShapeGraphPointNum";
		   label23->Text = "YXShapeGraph";
		   label24->Text = "YZShapeGraph";
		   label25->Text = "BaseRadiusGraphRandomize";
		   label26->Text = "FractalOption";
		   label0->ForeColor = Color::White;
		   label1->ForeColor = Color::White;
		   label2->ForeColor = Color::White;
		   label3->ForeColor = Color::White;
		   label4->ForeColor = Color::White;
		   label5->ForeColor = Color::White;
		   label6->ForeColor = Color::White;
		   label7->ForeColor = Color::White;
		   label8->ForeColor = Color::White;
		   label9->ForeColor = Color::White;
		   label10->ForeColor = Color::White;
		   label11->ForeColor = Color::White;
		   label12->ForeColor = Color::White;
		   label13->ForeColor = Color::White;
		   label14->ForeColor = Color::White;
		   label15->ForeColor = Color::White;
		   label16->ForeColor = Color::White;
		   label17->ForeColor = Color::White;
		   label18->ForeColor = Color::White;
		   label19->ForeColor = Color::White;
		   label20->ForeColor = Color::White;
		   label21->ForeColor = Color::White;
		   label22->ForeColor = Color::White;
		   label23->ForeColor = Color::White;
		   label24->ForeColor = Color::White;
		   label25->ForeColor = Color::White;
		   label26->ForeColor = Color::White;
		   label0->Dock = DockStyle::Bottom;
		   label1->Dock = DockStyle::Bottom;
		   label2->Dock = DockStyle::Bottom;
		   label3->Dock = DockStyle::Bottom;
		   label4->Dock = DockStyle::Bottom;
		   label5->Dock = DockStyle::Bottom;
		   label6->Dock = DockStyle::Bottom;
		   label7->Dock = DockStyle::Bottom;
		   label8->Dock = DockStyle::Bottom;
		   label9->Dock = DockStyle::Bottom;
		   label10->Dock = DockStyle::Bottom;
		   label11->Dock = DockStyle::Bottom;
		   label12->Dock = DockStyle::Bottom;
		   label13->Dock = DockStyle::Bottom;
		   label14->Dock = DockStyle::Bottom;
		   label15->Dock = DockStyle::Bottom;
		   label16->Dock = DockStyle::Bottom;
		   label17->Dock = DockStyle::Bottom;
		   label18->Dock = DockStyle::Bottom;
		   label19->Dock = DockStyle::Bottom;
		   label20->Dock = DockStyle::Bottom;
		   label21->Dock = DockStyle::Bottom;
		   label22->Dock = DockStyle::Bottom;
		   label23->Dock = DockStyle::Bottom;
		   label24->Dock = DockStyle::Bottom;
		   label25->Dock = DockStyle::Bottom;
		   label26->Dock = DockStyle::Bottom;
		   comboBox0->Name = "0";
		   comboBox1->Name = "1";
		   comboBox2->Name = "2";
		   comboBox3->Name = "3";
		   comboBox0->Dock = DockStyle::Bottom;
		   comboBox1->Dock = DockStyle::Bottom;
		   comboBox2->Dock = DockStyle::Bottom;
		   comboBox3->Dock = DockStyle::Bottom;
		   comboBox0->DropDownStyle = ComboBoxStyle::DropDownList;
		   comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
		   comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;
		   comboBox3->DropDownStyle = ComboBoxStyle::DropDownList;
		   comboBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   comboBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   comboBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   comboBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   comboBox0->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
		   comboBox1->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
		   comboBox2->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
		   comboBox3->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
		   comboBox0->Items->Clear();
		   comboBox1->Items->Clear();
		   comboBox2->Items->Clear();
		   comboBox3->Items->Clear();
		   comboBox1->Items->Add("R");
		   comboBox1->Items->Add("B");
		   comboBox1->Items->Add("D");
		   comboBox2->Items->Add("R");
		   comboBox2->Items->Add("B");
		   comboBox2->Items->Add("D");
		   comboBox3->Items->Add("Normal");
		   comboBox3->Items->Add("Fractal(THIS ITSELF)");
		   comboBox3->Items->Add("Fractal(TOP)");
		   comboBox3->Items->Add("Leaf");
		   if (i.GetValue(0, comboBox0->Name) != -1) {
			   comboBox0->SelectedIndex = i.GetValue(0, comboBox0->Name);
		   }
		   comboBox1->SelectedIndex = i.GetValue(0, comboBox1->Name);
		   comboBox2->SelectedIndex = i.GetValue(0, comboBox2->Name);
		   comboBox3->SelectedIndex = i.GetValue(0, comboBox3->Name);
		   chart0->Name = "0";
		   chart1->Name = "1";
		   chart2->Name = "2";
		   chart0->Dock = DockStyle::Fill;
		   chart1->Dock = DockStyle::Fill;
		   chart2->Dock = DockStyle::Fill;
		   chart0->BackColor = Color::FromArgb(64,64,64);
		   chart1->BackColor = Color::FromArgb(64, 64, 64);
		   chart2->BackColor = Color::FromArgb(64, 64, 64);
		   chart0->ChartAreas->Clear();
		   chart1->ChartAreas->Clear();
		   chart2->ChartAreas->Clear();
		   chart0->ChartAreas->Add("NewChartArea");
		   chart1->ChartAreas->Add("NewChartArea");
		   chart2->ChartAreas->Add("NewChartArea");
		   chart0->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
		   chart1->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
		   chart2->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
		   chart0->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
		   chart1->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
		   chart2->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
		   chart0->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
		   chart1->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
		   chart2->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
		   chart0->ChartAreas[0]->AxisX->Minimum=0;
		   chart1->ChartAreas[0]->AxisX->Minimum = 0;
		   chart2->ChartAreas[0]->AxisX->Minimum = 0;
		   chart0->ChartAreas[0]->AxisX->Maximum = 10000;
		   chart1->ChartAreas[0]->AxisX->Maximum = 10000;
		   chart2->ChartAreas[0]->AxisX->Maximum = 10000;
		   chart0->ChartAreas[0]->AxisY->Minimum = 0;
		   chart1->ChartAreas[0]->AxisY->Minimum = -10000;
		   chart2->ChartAreas[0]->AxisY->Minimum = -10000;
		   chart0->ChartAreas[0]->AxisY->Maximum = 10000;
		   chart1->ChartAreas[0]->AxisY->Maximum = 10000;
		   chart2->ChartAreas[0]->AxisY->Maximum = 10000;
		   chart0->ChartAreas[0]->AxisX->Interval = 1000;
		   chart1->ChartAreas[0]->AxisX->Interval = 1000;
		   chart2->ChartAreas[0]->AxisX->Interval = 1000;
		   chart0->ChartAreas[0]->AxisY->Interval = 1000;
		   chart1->ChartAreas[0]->AxisY->Interval = 2000;
		   chart2->ChartAreas[0]->AxisY->Interval = 2000;
		   chart0->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
		   chart1->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
		   chart2->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
		   chart0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   chart1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   chart2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox0->Name = "0";
		   textBox1->Name = "1";
		   textBox2->Name = "2";
		   textBox3->Name = "3";
		   textBox4->Name = "4";
		   textBox5->Name = "5";
		   textBox6->Name = "6";
		   textBox7->Name = "7";
		   textBox8->Name = "8";
		   textBox9->Name = "9";
		   textBox10->Name = "10";
		   textBox11->Name = "11";
		   textBox12->Name = "12";
		   textBox13->Name = "13";
		   textBox14->Name = "14";
		   textBox15->Name = "15";
		   textBox16->Name = "16";
		   textBox17->Name = "19";
		   textBox18->Name = "20";
		   textBox19->Name = "25";
		   textBox0->Dock = DockStyle::Bottom;
		   textBox1->Dock = DockStyle::Bottom;
		   textBox2->Dock = DockStyle::Bottom;
		   textBox3->Dock = DockStyle::Bottom;
		   textBox4->Dock = DockStyle::Bottom;
		   textBox5->Dock = DockStyle::Bottom;
		   textBox6->Dock = DockStyle::Bottom;
		   textBox7->Dock = DockStyle::Bottom;
		   textBox8->Dock = DockStyle::Bottom;
		   textBox9->Dock = DockStyle::Bottom;
		   textBox10->Dock = DockStyle::Bottom;
		   textBox11->Dock = DockStyle::Bottom;
		   textBox12->Dock = DockStyle::Bottom;
		   textBox13->Dock = DockStyle::Bottom;
		   textBox14->Dock = DockStyle::Bottom;
		   textBox15->Dock = DockStyle::Bottom;
		   textBox16->Dock = DockStyle::Bottom;
		   textBox17->Dock = DockStyle::Bottom;
		   textBox18->Dock = DockStyle::Bottom;
		   textBox19->Dock = DockStyle::Bottom;
		   textBox0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox12->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox13->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox14->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox15->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox16->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox17->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox18->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox19->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
		   textBox0->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox1->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox3->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox4->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox5->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox6->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox7->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox8->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox9->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox10->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox11->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox12->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox13->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox14->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox15->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox16->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox17->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox18->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox19->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
		   textBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox11->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox12->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox13->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox14->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox15->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox16->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox17->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox18->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox19->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
		   textBox1->Text = i.GetValue(1, textBox1->Name).ToString();
		   textBox2->Text = i.GetValue(1, textBox2->Name).ToString();
		   textBox3->Text = i.GetValue(1, textBox3->Name).ToString();
		   textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
		   textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
		   textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
		   textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
		   textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
		   textBox9->Text = ((double)i.GetValue(1, textBox9->Name) / 10000).ToString();
		   textBox10->Text = ((double)i.GetValue(1, textBox10->Name) / 10000).ToString();
		   textBox11->Text = ((double)i.GetValue(1, textBox11->Name) / 10000).ToString();
		   textBox12->Text = ((double)i.GetValue(1, textBox12->Name) / 10000).ToString();
		   textBox13->Text = ((double)i.GetValue(1, textBox13->Name) / 10000).ToString();
		   textBox14->Text = ((double)i.GetValue(1, textBox14->Name) / 10000).ToString();
		   textBox15->Text = ((double)i.GetValue(1, textBox15->Name) / 10000).ToString();
		   textBox16->Text = i.GetValue(1, textBox16->Name).ToString();
		   textBox17->Text = ((double)i.GetValue(1, textBox17->Name) / 10000).ToString();
		   textBox18->Text = i.GetValue(1, textBox18->Name).ToString();
		   textBox19->Text = ((double)i.GetValue(1, textBox19->Name) / 10000).ToString();
		   trackBar0->Name = "0";
		   trackBar1->Name = "1";
		   trackBar2->Name = "2";
		   trackBar3->Name = "3";
		   trackBar4->Name = "4";
		   trackBar5->Name = "5";
		   trackBar6->Name = "6";
		   trackBar7->Name = "7";
		   trackBar8->Name = "8";
		   trackBar9->Name = "9";
		   trackBar10->Name = "10";
		   trackBar11->Name = "11";
		   trackBar12->Name = "12";
		   trackBar13->Name = "13";
		   trackBar14->Name = "14";
		   trackBar15->Name = "15";
		   trackBar16->Name = "16";
		   trackBar17->Name = "17";
		   trackBar18->Name = "18";
		   trackBar19->Name = "19";
		   trackBar20->Name = "20";
		   trackBar21->Name = "21";
		   trackBar22->Name = "22";
		   trackBar23->Name = "23";
		   trackBar24->Name = "24";
		   trackBar25->Name = "25";
		   trackBar17->Orientation = Orientation::Vertical;
		   trackBar21->Orientation = Orientation::Vertical;
		   trackBar23->Orientation = Orientation::Vertical;
		   trackBar0->Dock = DockStyle::Bottom;
		   trackBar1->Dock = DockStyle::Bottom;
		   trackBar2->Dock = DockStyle::Bottom;
		   trackBar3->Dock = DockStyle::Bottom;
		   trackBar4->Dock = DockStyle::Bottom;
		   trackBar5->Dock = DockStyle::Bottom;
		   trackBar6->Dock = DockStyle::Bottom;
		   trackBar7->Dock = DockStyle::Bottom;
		   trackBar8->Dock = DockStyle::Bottom;
		   trackBar9->Dock = DockStyle::Bottom;
		   trackBar10->Dock = DockStyle::Bottom;
		   trackBar11->Dock = DockStyle::Bottom;
		   trackBar12->Dock = DockStyle::Bottom;
		   trackBar13->Dock = DockStyle::Bottom;
		   trackBar14->Dock = DockStyle::Bottom;
		   trackBar15->Dock = DockStyle::Bottom;
		   trackBar16->Dock = DockStyle::Bottom;
		   trackBar17->Dock = DockStyle::Right;
		   trackBar18->Dock = DockStyle::Bottom;
		   trackBar19->Dock = DockStyle::Bottom;
		   trackBar20->Dock = DockStyle::Bottom;
		   trackBar21->Dock = DockStyle::Right;
		   trackBar22->Dock = DockStyle::Bottom;
		   trackBar23->Dock = DockStyle::Right;
		   trackBar24->Dock = DockStyle::Bottom;
		   trackBar25->Dock = DockStyle::Bottom;
		   trackBar0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar11->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar12->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar13->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar14->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar15->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar16->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar17->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar18->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar19->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar20->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar21->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar22->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar23->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar24->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar25->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
		   trackBar0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar11->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar12->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar13->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar14->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar15->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar16->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar17->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar18->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar19->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar20->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar21->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar22->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar23->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar24->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar25->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
		   trackBar0->Minimum = 1;
		   trackBar1->Minimum = 3;
		   trackBar2->Minimum = 2;
		   trackBar3->Minimum = 2;
		   trackBar4->Minimum = 0;
		   trackBar5->Minimum = 0;
		   trackBar6->Minimum = 0;
		   trackBar7->Minimum = 0;
		   trackBar8->Minimum = 0;
		   trackBar9->Minimum = 0;
		   trackBar10->Minimum = 0;
		   trackBar11->Minimum = 0;
		   trackBar12->Minimum = 0;
		   trackBar13->Minimum = 0;
		   trackBar14->Minimum = 0;
		   trackBar15->Minimum = 0;
		   trackBar16->Minimum = 2;
		   trackBar17->Minimum = 0;
		   trackBar18->Minimum = 0;
		   trackBar19->Minimum = 0;
		   trackBar20->Minimum = 2;
		   trackBar21->Minimum = -10000;
		   trackBar22->Minimum = 0;
		   trackBar23->Minimum = -10000;
		   trackBar24->Minimum = 0;
		   trackBar25->Minimum = 0;
		   trackBar0->Maximum = 20;
		   trackBar1->Maximum = 20;
		   trackBar2->Maximum = 20;
		   trackBar3->Maximum = 20;
		   trackBar4->Maximum = 10000;
		   trackBar5->Maximum = 10000;
		   trackBar6->Maximum = 10000;
		   trackBar7->Maximum = 10000;
		   trackBar8->Maximum = 3600000;
		   trackBar9->Maximum = 3600000;
		   trackBar10->Maximum = 3600000;
		   trackBar11->Maximum = 10000;
		   trackBar12->Maximum = 10000;
		   trackBar13->Maximum = 10000;
		   trackBar14->Maximum = 10000;
		   trackBar15->Maximum = 10000;
		   trackBar16->Maximum = 20;
		   trackBar17->Maximum = 10000;
		   trackBar18->Maximum = 10000;
		   trackBar19->Maximum = 10000;
		   trackBar20->Maximum = 20;
		   trackBar21->Maximum = 10000;
		   trackBar22->Maximum = 10000;
		   trackBar23->Maximum = 10000;
		   trackBar24->Maximum = 10000;
		   trackBar25->Maximum = 10000;
		   trackBar0->TickFrequency = 2;
		   trackBar1->TickFrequency = 2;
		   trackBar2->TickFrequency = 2;
		   trackBar3->TickFrequency = 2;
		   trackBar4->TickFrequency = 1000;
		   trackBar5->TickFrequency = 1000;
		   trackBar6->TickFrequency = 1000;
		   trackBar7->TickFrequency = 1000;
		   trackBar8->TickFrequency = 300000;
		   trackBar9->TickFrequency = 300000;
		   trackBar10->TickFrequency = 300000;
		   trackBar11->TickFrequency = 1000;
		   trackBar12->TickFrequency = 1000;
		   trackBar13->TickFrequency = 1000;
		   trackBar14->TickFrequency = 1000;
		   trackBar15->TickFrequency = 1000;
		   trackBar16->TickFrequency = 2;
		   trackBar17->TickFrequency = 1000;
		   trackBar18->TickFrequency = 1000;
		   trackBar19->TickFrequency = 1000;
		   trackBar20->TickFrequency = 2;
		   trackBar21->TickFrequency = 2000;
		   trackBar22->TickFrequency = 1000;
		   trackBar23->TickFrequency = 2000;
		   trackBar24->TickFrequency = 1000;
		   trackBar25->TickFrequency = 1000;
		
		   tableLayoutPanel->ColumnCount = 20;
		   tableLayoutPanel->RowCount = 67;
		   for (int i = 0; i < 20;i++) {
			   tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
		   }
		   for (int i = 0; i < 67; i++) {
			   tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
		   }

		   tableLayoutPanel->Controls->Add(label0, 1, 0);
		   tableLayoutPanel->Controls->Add(label1, 1, 1);
		   tableLayoutPanel->Controls->Add(label2, 1, 2);
		   tableLayoutPanel->Controls->Add(label3, 1, 3);
		   tableLayoutPanel->Controls->Add(label4, 1, 4);
		   tableLayoutPanel->Controls->Add(label5, 1, 5);
		   tableLayoutPanel->Controls->Add(label6, 1, 6);
		   tableLayoutPanel->Controls->Add(label7, 1, 7);
		   tableLayoutPanel->Controls->Add(label8, 1, 8);
		   tableLayoutPanel->Controls->Add(label9, 1, 9);
		   tableLayoutPanel->Controls->Add(label10, 1, 10);
		   tableLayoutPanel->Controls->Add(label11, 1, 11);
		   tableLayoutPanel->Controls->Add(label12, 1, 12);
		   tableLayoutPanel->Controls->Add(label13, 1, 13);
		   tableLayoutPanel->Controls->Add(label14, 1, 14);
		   tableLayoutPanel->Controls->Add(label15, 1, 15);
		   tableLayoutPanel->Controls->Add(label16, 1, 16);
		   tableLayoutPanel->Controls->Add(label17, 1, 18);
		   tableLayoutPanel->Controls->Add(label18, 1, 19);
		   tableLayoutPanel->Controls->Add(label19, 1, 20);
		   tableLayoutPanel->Controls->Add(label20, 1, 34);
		   tableLayoutPanel->Controls->Add(label21, 1, 35);
		   tableLayoutPanel->Controls->Add(label22, 1, 36);
		   tableLayoutPanel->Controls->Add(label23, 1, 37);
		   tableLayoutPanel->Controls->Add(label24, 1, 51);
		   tableLayoutPanel->Controls->Add(label25, 1, 17);
		   tableLayoutPanel->Controls->Add(label26, 1, 65);//
		   tableLayoutPanel->Controls->Add(comboBox0, 7, 1);
		   tableLayoutPanel->Controls->Add(comboBox1, 7, 18);
		   tableLayoutPanel->Controls->Add(comboBox2, 7, 35);
		   tableLayoutPanel->Controls->Add(comboBox3, 7, 65);//
		   tableLayoutPanel->Controls->Add(chart0, 4, 21);
		   tableLayoutPanel->Controls->Add(chart1, 4, 38);
		   tableLayoutPanel->Controls->Add(chart2, 4, 52);
		   tableLayoutPanel->Controls->Add(textBox0, 16, 0);
		   tableLayoutPanel->Controls->Add(textBox1, 16, 2);
		   tableLayoutPanel->Controls->Add(textBox2, 16, 3);
		   tableLayoutPanel->Controls->Add(textBox3, 16, 4);
		   tableLayoutPanel->Controls->Add(textBox4, 16, 5);
		   tableLayoutPanel->Controls->Add(textBox5, 16, 6);
		   tableLayoutPanel->Controls->Add(textBox6, 16, 7);
		   tableLayoutPanel->Controls->Add(textBox7, 16, 8);
		   tableLayoutPanel->Controls->Add(textBox8, 16, 9);
		   tableLayoutPanel->Controls->Add(textBox9, 16, 10);
		   tableLayoutPanel->Controls->Add(textBox10, 16, 11);
		   tableLayoutPanel->Controls->Add(textBox11, 16, 12);
		   tableLayoutPanel->Controls->Add(textBox12, 16, 13);
		   tableLayoutPanel->Controls->Add(textBox13, 16, 14);
		   tableLayoutPanel->Controls->Add(textBox14, 16, 15);
		   tableLayoutPanel->Controls->Add(textBox15, 16, 16);
		   tableLayoutPanel->Controls->Add(textBox16, 16, 19);
		   tableLayoutPanel->Controls->Add(textBox17, 16, 34);
		   tableLayoutPanel->Controls->Add(textBox18, 16, 36);
		   tableLayoutPanel->Controls->Add(textBox19, 16, 17);
		   tableLayoutPanel->Controls->Add(trackBar0, 7, 0);
		   tableLayoutPanel->Controls->Add(trackBar1, 7, 2);
		   tableLayoutPanel->Controls->Add(trackBar2, 7, 3);
		   tableLayoutPanel->Controls->Add(trackBar3, 7, 4);
		   tableLayoutPanel->Controls->Add(trackBar4, 7, 5);
		   tableLayoutPanel->Controls->Add(trackBar5, 7, 6);
		   tableLayoutPanel->Controls->Add(trackBar6, 7, 7);
		   tableLayoutPanel->Controls->Add(trackBar7, 7, 8);
		   tableLayoutPanel->Controls->Add(trackBar8, 7, 9);
		   tableLayoutPanel->Controls->Add(trackBar9, 7, 10);
		   tableLayoutPanel->Controls->Add(trackBar10, 7, 11);
		   tableLayoutPanel->Controls->Add(trackBar11, 7, 12);
		   tableLayoutPanel->Controls->Add(trackBar12, 7, 13);
		   tableLayoutPanel->Controls->Add(trackBar13, 7, 14);
		   tableLayoutPanel->Controls->Add(trackBar14, 7, 15);
		   tableLayoutPanel->Controls->Add(trackBar15, 7, 16);
		   tableLayoutPanel->Controls->Add(trackBar16, 7, 19);
		   tableLayoutPanel->Controls->Add(trackBar17, 3, 21);
		   tableLayoutPanel->Controls->Add(trackBar18, 4, 33);
		   tableLayoutPanel->Controls->Add(trackBar19, 7, 34);
		   tableLayoutPanel->Controls->Add(trackBar20, 7, 36);
		   tableLayoutPanel->Controls->Add(trackBar21, 3, 38);
		   tableLayoutPanel->Controls->Add(trackBar22, 4, 50);
		   tableLayoutPanel->Controls->Add(trackBar23, 3, 52);
		   tableLayoutPanel->Controls->Add(trackBar24, 4, 64);
		   tableLayoutPanel->Controls->Add(trackBar25,7, 17);
		   
		   tableLayoutPanel->SetColumnSpan(label0, 5);
		   tableLayoutPanel->SetColumnSpan(label1, 5);
		   tableLayoutPanel->SetColumnSpan(label2, 5);
		   tableLayoutPanel->SetColumnSpan(label3, 5);
		   tableLayoutPanel->SetColumnSpan(label4, 5);
		   tableLayoutPanel->SetColumnSpan(label5, 5);
		   tableLayoutPanel->SetColumnSpan(label6, 5);
		   tableLayoutPanel->SetColumnSpan(label7, 5);
		   tableLayoutPanel->SetColumnSpan(label8, 5);
		   tableLayoutPanel->SetColumnSpan(label9, 5);
		   tableLayoutPanel->SetColumnSpan(label10, 5);
		   tableLayoutPanel->SetColumnSpan(label11, 5);
		   tableLayoutPanel->SetColumnSpan(label12, 5);
		   tableLayoutPanel->SetColumnSpan(label13, 5);
		   tableLayoutPanel->SetColumnSpan(label14, 5);
		   tableLayoutPanel->SetColumnSpan(label15, 5);
		   tableLayoutPanel->SetColumnSpan(label16, 5);
		   tableLayoutPanel->SetColumnSpan(label17, 5);
		   tableLayoutPanel->SetColumnSpan(label18, 5);
		   tableLayoutPanel->SetColumnSpan(label19, 5);
		   tableLayoutPanel->SetColumnSpan(label20, 5);
		   tableLayoutPanel->SetColumnSpan(label21, 5);
		   tableLayoutPanel->SetColumnSpan(label22, 5);
		   tableLayoutPanel->SetColumnSpan(label23, 5);
		   tableLayoutPanel->SetColumnSpan(label24, 5);
		   tableLayoutPanel->SetColumnSpan(label25, 5);
		   tableLayoutPanel->SetColumnSpan(label26, 5);
		   tableLayoutPanel->SetColumnSpan(comboBox0, 12);
		   tableLayoutPanel->SetColumnSpan(comboBox1, 12);
		   tableLayoutPanel->SetColumnSpan(comboBox2, 12);
		   tableLayoutPanel->SetColumnSpan(comboBox3, 12);
		   tableLayoutPanel->SetColumnSpan(chart0, 15);
		   tableLayoutPanel->SetColumnSpan(chart1, 15);
		   tableLayoutPanel->SetColumnSpan(chart2, 15);
		   tableLayoutPanel->SetColumnSpan(textBox0, 3);
		   tableLayoutPanel->SetColumnSpan(textBox1, 3);
		   tableLayoutPanel->SetColumnSpan(textBox2, 3);
		   tableLayoutPanel->SetColumnSpan(textBox3, 3);
		   tableLayoutPanel->SetColumnSpan(textBox4, 3);
		   tableLayoutPanel->SetColumnSpan(textBox5, 3);
		   tableLayoutPanel->SetColumnSpan(textBox6, 3);
		   tableLayoutPanel->SetColumnSpan(textBox7, 3);
		   tableLayoutPanel->SetColumnSpan(textBox8, 3);
		   tableLayoutPanel->SetColumnSpan(textBox9, 3);
		   tableLayoutPanel->SetColumnSpan(textBox10, 3);
		   tableLayoutPanel->SetColumnSpan(textBox11, 3);
		   tableLayoutPanel->SetColumnSpan(textBox12, 3);
		   tableLayoutPanel->SetColumnSpan(textBox13, 3);
		   tableLayoutPanel->SetColumnSpan(textBox14, 3);
		   tableLayoutPanel->SetColumnSpan(textBox15, 3);
		   tableLayoutPanel->SetColumnSpan(textBox16, 3);
		   tableLayoutPanel->SetColumnSpan(textBox17, 3);
		   tableLayoutPanel->SetColumnSpan(textBox18, 3);
		   tableLayoutPanel->SetColumnSpan(textBox19, 3);
		   tableLayoutPanel->SetColumnSpan(trackBar0, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar1, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar2, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar3, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar4, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar5, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar6, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar7, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar8, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar9, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar10, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar11, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar12, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar13, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar14, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar15, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar16, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar18, 15);
		   tableLayoutPanel->SetColumnSpan(trackBar19, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar20, 8);
		   tableLayoutPanel->SetColumnSpan(trackBar22, 15);
		   tableLayoutPanel->SetColumnSpan(trackBar24, 15);
		   tableLayoutPanel->SetColumnSpan(trackBar25, 8);
		   tableLayoutPanel->SetRowSpan(chart0, 12);
		   tableLayoutPanel->SetRowSpan(chart1, 12);
		   tableLayoutPanel->SetRowSpan(chart2, 12);
		   tableLayoutPanel->SetRowSpan(trackBar17, 12);
		   tableLayoutPanel->SetRowSpan(trackBar21, 12);
		   tableLayoutPanel->SetRowSpan(trackBar23, 12);

		   SetTrackBarValue(trackBar0->Name);
		   SetTrackBarValue(trackBar1->Name);
		   SetTrackBarValue(trackBar2->Name);
		   SetTrackBarValue(trackBar3->Name);
		   SetTrackBarValue(trackBar4->Name);
		   SetTrackBarValue(trackBar5->Name);
		   SetTrackBarValue(trackBar6->Name);
		   SetTrackBarValue(trackBar7->Name);
		   SetTrackBarValue(trackBar8->Name);
		   SetTrackBarValue(trackBar9->Name);
		   SetTrackBarValue(trackBar10->Name);
		   SetTrackBarValue(trackBar11->Name);
		   SetTrackBarValue(trackBar12->Name);
		   SetTrackBarValue(trackBar13->Name);
		   SetTrackBarValue(trackBar14->Name);
		   SetTrackBarValue(trackBar15->Name);
		   SetTrackBarValue(trackBar16->Name);
		   SetTrackBarValue(trackBar17->Name);
		   SetTrackBarValue(trackBar18->Name);
		   SetTrackBarValue(trackBar19->Name);
		   SetTrackBarValue(trackBar20->Name);
		   SetTrackBarValue(trackBar21->Name);
		   SetTrackBarValue(trackBar22->Name);
		   SetTrackBarValue(trackBar23->Name);
		   SetTrackBarValue(trackBar24->Name);
		   SetTrackBarValue(trackBar25->Name);
		   SetTextBoxValue(textBox0->Name);
		   SetTextBoxValue(textBox1->Name);
		   SetTextBoxValue(textBox2->Name);
		   SetTextBoxValue(textBox3->Name);
		   SetTextBoxValue(textBox4->Name);
		   SetTextBoxValue(textBox5->Name);
		   SetTextBoxValue(textBox6->Name);
		   SetTextBoxValue(textBox7->Name);
		   SetTextBoxValue(textBox8->Name);
		   SetTextBoxValue(textBox9->Name);
		   SetTextBoxValue(textBox10->Name);
		   SetTextBoxValue(textBox11->Name);
		   SetTextBoxValue(textBox12->Name);
		   SetTextBoxValue(textBox13->Name);
		   SetTextBoxValue(textBox14->Name);
		   SetTextBoxValue(textBox15->Name);
		   SetTextBoxValue(textBox16->Name);
		   SetTextBoxValue(textBox17->Name);
		   SetTextBoxValue(textBox18->Name);
		   SetTextBoxValue(textBox19->Name);
		   RePaintChart(chart0->Name);
		   RePaintChart(chart1->Name);
		   RePaintChart(chart2->Name);
}



private:void SetbPropertyPanel(String^ SelectedNodeName) {
	label0->Text = "Texture";
	label1->Text = "Rings";
	label2->Text = "ShapeDivisionNum";
	label3->Text = "RadiusDivisionNum";
	label4->Text = "BirthPlace";
	label5->Text = "Length";
	label6->Text = "XRotation";
	label7->Text = "YRotation";
	label8->Text = "ZRotation";
	label9->Text = "BaseRadius";
	label10->Text = "BaseRadiusGraphType";
	label11->Text = "BaseRadiusGraphPointNum";
	label12->Text = "BaseRadiusGraph";
	label13->Text = "ShapeGraphType";
	label14->Text = "ShapeGraphPointNum";
	label15->Text = "YXShapeGraph";
	label16->Text = "YZShapeGraph";
	label17->Text = "FractalOption";
	label0->ForeColor = Color::White;
	label1->ForeColor = Color::White;
	label2->ForeColor = Color::White;
	label3->ForeColor = Color::White;
	label4->ForeColor = Color::White;
	label5->ForeColor = Color::White;
	label6->ForeColor = Color::White;
	label7->ForeColor = Color::White;
	label8->ForeColor = Color::White;
	label9->ForeColor = Color::White;
	label10->ForeColor = Color::White;
	label11->ForeColor = Color::White;
	label12->ForeColor = Color::White;
	label13->ForeColor = Color::White;
	label14->ForeColor = Color::White;
	label15->ForeColor = Color::White;
	label16->ForeColor = Color::White;
	label17->ForeColor = Color::White;
	label0->Dock = DockStyle::Bottom;
	label1->Dock = DockStyle::Bottom;
	label2->Dock = DockStyle::Bottom;
	label3->Dock = DockStyle::Bottom;
	label4->Dock = DockStyle::Bottom;
	label5->Dock = DockStyle::Bottom;
	label6->Dock = DockStyle::Bottom;
	label7->Dock = DockStyle::Bottom;
	label8->Dock = DockStyle::Bottom;
	label9->Dock = DockStyle::Bottom;
	label10->Dock = DockStyle::Bottom;
	label11->Dock = DockStyle::Bottom;
	label12->Dock = DockStyle::Bottom;
	label13->Dock = DockStyle::Bottom;
	label14->Dock = DockStyle::Bottom;
	label15->Dock = DockStyle::Bottom;
	label16->Dock = DockStyle::Bottom;
	label17->Dock = DockStyle::Bottom;
	comboBox0->Name = "0";
	comboBox1->Name = "1";
	comboBox2->Name = "2";
	comboBox3->Name = "3";
	comboBox0->Dock = DockStyle::Bottom;
	comboBox1->Dock = DockStyle::Bottom;
	comboBox2->Dock = DockStyle::Bottom;
	comboBox3->Dock = DockStyle::Bottom;
	comboBox0->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox3->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox0->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox1->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox2->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox3->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox0->Items->Clear();
	comboBox1->Items->Clear();
	comboBox2->Items->Clear();
	comboBox3->Items->Clear();
	comboBox1->Items->Add("R");
	comboBox1->Items->Add("B");
	comboBox1->Items->Add("D");
	comboBox2->Items->Add("R");
	comboBox2->Items->Add("B");
	comboBox2->Items->Add("D");
	comboBox3->Items->Add("Normal");
	comboBox3->Items->Add("Fractal(THIS ITSELF)");
	comboBox3->Items->Add("Fractal(TOP)");
	comboBox3->Items->Add("Leaf");
	if (i.GetValue(0, comboBox0->Name) != -1) {
		comboBox0->SelectedIndex = i.GetValue(0, comboBox0->Name);
	}
	comboBox1->SelectedIndex = i.GetValue(0, comboBox1->Name);
	comboBox2->SelectedIndex = i.GetValue(0, comboBox2->Name);
	comboBox3->SelectedIndex = i.GetValue(0, comboBox3->Name);
	chart0->Name = "0";
	chart1->Name = "1";
	chart2->Name = "2";
	chart0->Dock = DockStyle::Fill;
	chart1->Dock = DockStyle::Fill;
	chart2->Dock = DockStyle::Fill;
	chart0->BackColor = Color::FromArgb(64, 64, 64);
	chart1->BackColor = Color::FromArgb(64, 64, 64);
	chart2->BackColor = Color::FromArgb(64, 64, 64);
	chart0->ChartAreas->Clear();
	chart1->ChartAreas->Clear();
	chart2->ChartAreas->Clear();
	chart0->ChartAreas->Add("NewChartArea");
	chart1->ChartAreas->Add("NewChartArea");
	chart2->ChartAreas->Add("NewChartArea");
	chart0->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
	chart1->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
	chart2->ChartAreas[0]->BackColor = Color::FromArgb(32, 32, 32);
	chart0->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
	chart1->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
	chart2->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
	chart0->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
	chart1->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
	chart2->ChartAreas[0]->AxisY->LabelStyle->Enabled = false;
	chart0->ChartAreas[0]->AxisX->Minimum = 0;
	chart1->ChartAreas[0]->AxisX->Minimum = 0;
	chart2->ChartAreas[0]->AxisX->Minimum = 0;
	chart0->ChartAreas[0]->AxisX->Maximum = 10000;
	chart1->ChartAreas[0]->AxisX->Maximum = 10000;
	chart2->ChartAreas[0]->AxisX->Maximum = 10000;
	chart0->ChartAreas[0]->AxisY->Minimum = 0;
	chart1->ChartAreas[0]->AxisY->Minimum = -10000;
	chart2->ChartAreas[0]->AxisY->Minimum = -10000;
	chart0->ChartAreas[0]->AxisY->Maximum = 10000;
	chart1->ChartAreas[0]->AxisY->Maximum = 10000;
	chart2->ChartAreas[0]->AxisY->Maximum = 10000;
	chart0->ChartAreas[0]->AxisX->Interval = 1000;
	chart1->ChartAreas[0]->AxisX->Interval = 1000;
	chart2->ChartAreas[0]->AxisX->Interval = 1000;
	chart0->ChartAreas[0]->AxisY->Interval = 1000;
	chart1->ChartAreas[0]->AxisY->Interval = 2000;
	chart2->ChartAreas[0]->AxisY->Interval = 2000;
	chart0->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
	chart1->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
	chart2->Click += gcnew System::EventHandler(this, &MyForm::chart_Click);
	chart0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	chart1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	chart2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox0->Name = "0";
	textBox1->Name = "1";
	textBox2->Name = "2";
	textBox3->Name = "3";
	textBox4->Name = "4";
	textBox5->Name = "5";
	textBox6->Name = "6";
	textBox7->Name = "7";
	textBox8->Name = "8";
	textBox9->Name = "9";
	textBox10->Name = "12";
	textBox0->Dock = DockStyle::Bottom;
	textBox1->Dock = DockStyle::Bottom;
	textBox2->Dock = DockStyle::Bottom;
	textBox3->Dock = DockStyle::Bottom;
	textBox4->Dock = DockStyle::Bottom;
	textBox5->Dock = DockStyle::Bottom;
	textBox6->Dock = DockStyle::Bottom;
	textBox7->Dock = DockStyle::Bottom;
	textBox8->Dock = DockStyle::Bottom;
	textBox9->Dock = DockStyle::Bottom;
	textBox10->Dock = DockStyle::Bottom;
	textBox0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox0->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox1->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox3->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox4->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox5->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox6->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox7->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox8->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox9->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox10->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
	textBox1->Text = i.GetValue(1, textBox1->Name).ToString();
	textBox2->Text = i.GetValue(1, textBox2->Name).ToString();
	textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
	textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
	textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
	textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
	textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
	textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
	textBox9->Text = i.GetValue(1, textBox9->Name).ToString();
	textBox10->Text = i.GetValue(1, textBox10->Name).ToString();
	trackBar0->Name = "0";
	trackBar1->Name = "1";
	trackBar2->Name = "2";
	trackBar3->Name = "3";
	trackBar4->Name = "4";
	trackBar5->Name = "5";
	trackBar6->Name = "6";
	trackBar7->Name = "7";
	trackBar8->Name = "8";
	trackBar9->Name = "9";
	trackBar10->Name = "10";
	trackBar11->Name = "11";
	trackBar12->Name = "12";
	trackBar13->Name = "13";
	trackBar14->Name = "14";
	trackBar15->Name = "15";
	trackBar16->Name = "16";
	trackBar10->Orientation = Orientation::Vertical;
	trackBar13->Orientation = Orientation::Vertical;
	trackBar15->Orientation = Orientation::Vertical;
	trackBar0->Dock = DockStyle::Bottom;
	trackBar1->Dock = DockStyle::Bottom;
	trackBar2->Dock = DockStyle::Bottom;
	trackBar3->Dock = DockStyle::Bottom;
	trackBar4->Dock = DockStyle::Bottom;
	trackBar5->Dock = DockStyle::Bottom;
	trackBar6->Dock = DockStyle::Bottom;
	trackBar7->Dock = DockStyle::Bottom;
	trackBar8->Dock = DockStyle::Bottom;
	trackBar9->Dock = DockStyle::Bottom;
	trackBar10->Dock = DockStyle::Right;
	trackBar11->Dock = DockStyle::Bottom;
	trackBar12->Dock = DockStyle::Bottom;
	trackBar13->Dock = DockStyle::Right;
	trackBar14->Dock = DockStyle::Bottom;
	trackBar15->Dock = DockStyle::Right;
	trackBar16->Dock = DockStyle::Bottom;
	trackBar0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar11->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar12->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar13->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar14->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar15->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar16->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar11->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar12->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar13->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar14->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar15->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar16->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar0->Minimum = 3;
	trackBar1->Minimum = 2;
	trackBar2->Minimum = 2;
	trackBar3->Minimum = 0;
	trackBar4->Minimum = 0;
	trackBar5->Minimum = 0;
	trackBar6->Minimum = 0;
	trackBar7->Minimum = 0;
	trackBar8->Minimum = 0;
	trackBar9->Minimum = 2;
	trackBar10->Minimum = 0;
	trackBar11->Minimum = 0;
	trackBar12->Minimum = 2;
	trackBar13->Minimum = -10000;
	trackBar14->Minimum = 0;
	trackBar15->Minimum = -10000;
	trackBar16->Minimum = 0;
	trackBar0->Maximum = 20;
	trackBar1->Maximum = 20;
	trackBar2->Maximum = 20;
	trackBar3->Maximum = 10000;
	trackBar4->Maximum = 10000;
	trackBar5->Maximum = 3600000;
	trackBar6->Maximum = 3600000;
	trackBar7->Maximum = 3600000;
	trackBar8->Maximum = 10000;
	trackBar9->Maximum = 20;
	trackBar10->Maximum = 10000;
	trackBar11->Maximum = 10000;
	trackBar12->Maximum = 20;
	trackBar13->Maximum = 10000;
	trackBar14->Maximum = 10000;
	trackBar15->Maximum = 10000;
	trackBar16->Maximum = 10000;
	trackBar0->TickFrequency = 2;
	trackBar1->TickFrequency = 2;
	trackBar2->TickFrequency = 2;
	trackBar3->TickFrequency = 1000;
	trackBar4->TickFrequency = 1000;
	trackBar5->TickFrequency = 300000;
	trackBar6->TickFrequency = 300000;
	trackBar7->TickFrequency = 300000;
	trackBar8->TickFrequency = 1000;
	trackBar9->TickFrequency = 2;
	trackBar10->TickFrequency = 1000;
	trackBar11->TickFrequency = 1000;
	trackBar12->TickFrequency = 2;
	trackBar13->TickFrequency = 2000;
	trackBar14->TickFrequency = 1000;
	trackBar15->TickFrequency = 2000;
	trackBar16->TickFrequency = 1000;

	tableLayoutPanel->ColumnCount = 20;
	tableLayoutPanel->RowCount = 58;
	for (int i = 0; i < 20; i++) {
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
	}
	for (int i = 0; i < 58; i++) {
		tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
	}

	tableLayoutPanel->Controls->Add(label0, 1, 0);
	tableLayoutPanel->Controls->Add(label1, 1, 1);
	tableLayoutPanel->Controls->Add(label2, 1, 2);
	tableLayoutPanel->Controls->Add(label3, 1, 3);
	tableLayoutPanel->Controls->Add(label4, 1, 4);
	tableLayoutPanel->Controls->Add(label5, 1, 5);
	tableLayoutPanel->Controls->Add(label6, 1, 6);
	tableLayoutPanel->Controls->Add(label7, 1, 7);
	tableLayoutPanel->Controls->Add(label8, 1, 8);
	tableLayoutPanel->Controls->Add(label9, 1, 9);
	tableLayoutPanel->Controls->Add(label10, 1, 10);
	tableLayoutPanel->Controls->Add(label11, 1, 11);
	tableLayoutPanel->Controls->Add(label12, 1, 12);
	tableLayoutPanel->Controls->Add(label13, 1, 26);
	tableLayoutPanel->Controls->Add(label14, 1, 27);
	tableLayoutPanel->Controls->Add(label15, 1, 28);
	tableLayoutPanel->Controls->Add(label16, 1, 42);
	tableLayoutPanel->Controls->Add(label17, 1, 56);//
	tableLayoutPanel->Controls->Add(comboBox0, 7, 0);
	tableLayoutPanel->Controls->Add(comboBox1, 7, 10);
	tableLayoutPanel->Controls->Add(comboBox2, 7, 26);
	tableLayoutPanel->Controls->Add(comboBox3, 7, 56);//
	tableLayoutPanel->Controls->Add(chart0, 4, 13);
	tableLayoutPanel->Controls->Add(chart1, 4, 29);
	tableLayoutPanel->Controls->Add(chart2, 4, 43);
	tableLayoutPanel->Controls->Add(textBox0, 16, 1);
	tableLayoutPanel->Controls->Add(textBox1, 16, 2);
	tableLayoutPanel->Controls->Add(textBox2, 16, 3);
	tableLayoutPanel->Controls->Add(textBox3, 16, 4);
	tableLayoutPanel->Controls->Add(textBox4, 16, 5);
	tableLayoutPanel->Controls->Add(textBox5, 16, 6);
	tableLayoutPanel->Controls->Add(textBox6, 16, 7);
	tableLayoutPanel->Controls->Add(textBox7, 16, 8);
	tableLayoutPanel->Controls->Add(textBox8, 16, 9);
	tableLayoutPanel->Controls->Add(textBox9, 16, 11);
	tableLayoutPanel->Controls->Add(textBox10, 16, 27);
	tableLayoutPanel->Controls->Add(trackBar0, 7, 1);
	tableLayoutPanel->Controls->Add(trackBar1, 7, 2);
	tableLayoutPanel->Controls->Add(trackBar2, 7, 3);
	tableLayoutPanel->Controls->Add(trackBar3, 7, 4);
	tableLayoutPanel->Controls->Add(trackBar4, 7, 5);
	tableLayoutPanel->Controls->Add(trackBar5, 7, 6);
	tableLayoutPanel->Controls->Add(trackBar6, 7, 7);
	tableLayoutPanel->Controls->Add(trackBar7, 7, 8);
	tableLayoutPanel->Controls->Add(trackBar8, 7, 9);
	tableLayoutPanel->Controls->Add(trackBar9, 7, 11);
	tableLayoutPanel->Controls->Add(trackBar10, 3, 13);
	tableLayoutPanel->Controls->Add(trackBar11, 4, 25);
	tableLayoutPanel->Controls->Add(trackBar12, 7, 27);
	tableLayoutPanel->Controls->Add(trackBar13, 3, 29);
	tableLayoutPanel->Controls->Add(trackBar14, 4, 41);
	tableLayoutPanel->Controls->Add(trackBar15, 3, 43);
	tableLayoutPanel->Controls->Add(trackBar16, 4, 55);

	tableLayoutPanel->SetColumnSpan(label0, 5);
	tableLayoutPanel->SetColumnSpan(label1, 5);
	tableLayoutPanel->SetColumnSpan(label2, 5);
	tableLayoutPanel->SetColumnSpan(label3, 5);
	tableLayoutPanel->SetColumnSpan(label4, 5);
	tableLayoutPanel->SetColumnSpan(label5, 5);
	tableLayoutPanel->SetColumnSpan(label6, 5);
	tableLayoutPanel->SetColumnSpan(label7, 5);
	tableLayoutPanel->SetColumnSpan(label8, 5);
	tableLayoutPanel->SetColumnSpan(label9, 5);
	tableLayoutPanel->SetColumnSpan(label10, 5);
	tableLayoutPanel->SetColumnSpan(label11, 5);
	tableLayoutPanel->SetColumnSpan(label12, 5);
	tableLayoutPanel->SetColumnSpan(label13, 5);
	tableLayoutPanel->SetColumnSpan(label14, 5);
	tableLayoutPanel->SetColumnSpan(label15, 5);
	tableLayoutPanel->SetColumnSpan(label16, 5);
	tableLayoutPanel->SetColumnSpan(label17, 5);
	tableLayoutPanel->SetColumnSpan(comboBox0, 12);
	tableLayoutPanel->SetColumnSpan(comboBox1, 12);
	tableLayoutPanel->SetColumnSpan(comboBox2, 12);
	tableLayoutPanel->SetColumnSpan(comboBox3, 12);
	tableLayoutPanel->SetColumnSpan(chart0, 15);
	tableLayoutPanel->SetColumnSpan(chart1, 15);
	tableLayoutPanel->SetColumnSpan(chart2, 15);
	tableLayoutPanel->SetColumnSpan(textBox0, 3);
	tableLayoutPanel->SetColumnSpan(textBox1, 3);
	tableLayoutPanel->SetColumnSpan(textBox2, 3);
	tableLayoutPanel->SetColumnSpan(textBox3, 3);
	tableLayoutPanel->SetColumnSpan(textBox4, 3);
	tableLayoutPanel->SetColumnSpan(textBox5, 3);
	tableLayoutPanel->SetColumnSpan(textBox6, 3);
	tableLayoutPanel->SetColumnSpan(textBox7, 3);
	tableLayoutPanel->SetColumnSpan(textBox8, 3);
	tableLayoutPanel->SetColumnSpan(textBox9, 3);
	tableLayoutPanel->SetColumnSpan(textBox10, 3);
	tableLayoutPanel->SetColumnSpan(trackBar0, 8);
	tableLayoutPanel->SetColumnSpan(trackBar1, 8);
	tableLayoutPanel->SetColumnSpan(trackBar2, 8);
	tableLayoutPanel->SetColumnSpan(trackBar3, 8);
	tableLayoutPanel->SetColumnSpan(trackBar4, 8);
	tableLayoutPanel->SetColumnSpan(trackBar5, 8);
	tableLayoutPanel->SetColumnSpan(trackBar6, 8);
	tableLayoutPanel->SetColumnSpan(trackBar7, 8);
	tableLayoutPanel->SetColumnSpan(trackBar8, 8);
	tableLayoutPanel->SetColumnSpan(trackBar9, 8);
	tableLayoutPanel->SetColumnSpan(trackBar11, 15);
	tableLayoutPanel->SetColumnSpan(trackBar12, 8);
	tableLayoutPanel->SetColumnSpan(trackBar14, 15);
	tableLayoutPanel->SetColumnSpan(trackBar16, 15);
	tableLayoutPanel->SetRowSpan(chart0, 12);
	tableLayoutPanel->SetRowSpan(chart1, 12);
	tableLayoutPanel->SetRowSpan(chart2, 12);
	tableLayoutPanel->SetRowSpan(trackBar10, 12);
	tableLayoutPanel->SetRowSpan(trackBar13, 12);
	tableLayoutPanel->SetRowSpan(trackBar15, 12);
	
	SetTrackBarValue(trackBar0->Name);
	SetTrackBarValue(trackBar1->Name);
	SetTrackBarValue(trackBar2->Name);
	SetTrackBarValue(trackBar3->Name);
	SetTrackBarValue(trackBar4->Name);
	SetTrackBarValue(trackBar5->Name);
	SetTrackBarValue(trackBar6->Name);
	SetTrackBarValue(trackBar7->Name);
	SetTrackBarValue(trackBar8->Name);
	SetTrackBarValue(trackBar9->Name);
	SetTrackBarValue(trackBar10->Name);
	SetTrackBarValue(trackBar11->Name);
	SetTrackBarValue(trackBar12->Name);
	SetTrackBarValue(trackBar13->Name);
	SetTrackBarValue(trackBar14->Name);
	SetTrackBarValue(trackBar15->Name);
	SetTrackBarValue(trackBar16->Name);
	SetTextBoxValue(textBox0->Name);
	SetTextBoxValue(textBox1->Name);
	SetTextBoxValue(textBox2->Name);
	SetTextBoxValue(textBox3->Name);
	SetTextBoxValue(textBox4->Name);
	SetTextBoxValue(textBox5->Name);
	SetTextBoxValue(textBox6->Name);
	SetTextBoxValue(textBox7->Name);
	SetTextBoxValue(textBox8->Name);
	SetTextBoxValue(textBox9->Name);
	SetTextBoxValue(textBox10->Name);
	RePaintChart(chart0->Name);
	RePaintChart(chart1->Name);
	RePaintChart(chart2->Name);
}

private:void SetTPropertyPanel(String^ SelectedNodeName) {
	label0->Text = "Group";
	label1->Text = "Texture";
	label2->Text = "BirthPlace";
	label3->Text = "BirthPlaceRandomize";
	label4->Text = "Length";
	label5->Text = "LengthRandomize";
	label6->Text = "XRotation";
	label7->Text = "YRotation";
	label8->Text = "ZRotation";
	label9->Text = "XRotationRandomize";
	label10->Text = "YRotationRandomize";
	label11->Text = "ZRotationRandomize";
	label0->ForeColor = Color::White;
	label1->ForeColor = Color::White;
	label2->ForeColor = Color::White;
	label3->ForeColor = Color::White;
	label4->ForeColor = Color::White;
	label5->ForeColor = Color::White;
	label6->ForeColor = Color::White;
	label7->ForeColor = Color::White;
	label8->ForeColor = Color::White;
	label9->ForeColor = Color::White;
	label10->ForeColor = Color::White;
	label11->ForeColor = Color::White;
	label0->Dock = DockStyle::Bottom;
	label1->Dock = DockStyle::Bottom;
	label2->Dock = DockStyle::Bottom;
	label3->Dock = DockStyle::Bottom;
	label4->Dock = DockStyle::Bottom;
	label5->Dock = DockStyle::Bottom;
	label6->Dock = DockStyle::Bottom;
	label7->Dock = DockStyle::Bottom;
	label8->Dock = DockStyle::Bottom;
	label9->Dock = DockStyle::Bottom;
	label10->Dock = DockStyle::Bottom;
	label11->Dock = DockStyle::Bottom;
	comboBox0->Name = "0";
	comboBox0->Dock = DockStyle::Bottom;
	comboBox0->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox0->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox0->Items->Clear();
	if (i.GetValue(0, comboBox0->Name) != -1) {
		comboBox0->SelectedIndex = i.GetValue(0, comboBox0->Name);
	}
	textBox0->Name = "0";
	textBox1->Name = "1";
	textBox2->Name = "2";
	textBox3->Name = "3";
	textBox4->Name = "4";
	textBox5->Name = "5";
	textBox6->Name = "6";
	textBox7->Name = "7";
	textBox8->Name = "8";
	textBox9->Name = "9";
	textBox10->Name = "10";
	textBox0->Dock = DockStyle::Bottom;
	textBox1->Dock = DockStyle::Bottom;
	textBox2->Dock = DockStyle::Bottom;
	textBox3->Dock = DockStyle::Bottom;
	textBox4->Dock = DockStyle::Bottom;
	textBox5->Dock = DockStyle::Bottom;
	textBox6->Dock = DockStyle::Bottom;
	textBox7->Dock = DockStyle::Bottom;
	textBox8->Dock = DockStyle::Bottom;
	textBox9->Dock = DockStyle::Bottom;
	textBox10->Dock = DockStyle::Bottom;
	textBox0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox0->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox1->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox3->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox4->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox5->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox6->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox7->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox8->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox9->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox10->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
	textBox1->Text = ((double)i.GetValue(1, textBox1->Name) / 10000).ToString();
	textBox2->Text = ((double)i.GetValue(1, textBox2->Name) / 10000).ToString();
	textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
	textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
	textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
	textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
	textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
	textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
	textBox9->Text = ((double)i.GetValue(1, textBox9->Name) / 10000).ToString();
	textBox10->Text = ((double)i.GetValue(1, textBox10->Name) / 10000).ToString();
	trackBar0->Name = "0";
	trackBar1->Name = "1";
	trackBar2->Name = "2";
	trackBar3->Name = "3";
	trackBar4->Name = "4";
	trackBar5->Name = "5";
	trackBar6->Name = "6";
	trackBar7->Name = "7";
	trackBar8->Name = "8";
	trackBar9->Name = "9";
	trackBar10->Name = "10";
	trackBar0->Dock = DockStyle::Bottom;
	trackBar1->Dock = DockStyle::Bottom;
	trackBar2->Dock = DockStyle::Bottom;
	trackBar3->Dock = DockStyle::Bottom;
	trackBar4->Dock = DockStyle::Bottom;
	trackBar5->Dock = DockStyle::Bottom;
	trackBar6->Dock = DockStyle::Bottom;
	trackBar7->Dock = DockStyle::Bottom;
	trackBar8->Dock = DockStyle::Bottom;
	trackBar9->Dock = DockStyle::Bottom;
	trackBar10->Dock = DockStyle::Bottom;
	trackBar0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar0->Minimum = 1;
	trackBar1->Minimum = 0;
	trackBar2->Minimum = 0;
	trackBar3->Minimum = 0;
	trackBar4->Minimum = 0;
	trackBar5->Minimum = 0;
	trackBar6->Minimum = 0;
	trackBar7->Minimum = 0;
	trackBar8->Minimum = 0;
	trackBar9->Minimum = 0;
	trackBar10->Minimum = 0;
	trackBar0->Maximum = 20;
	trackBar1->Maximum = 10000;
	trackBar2->Maximum = 10000;
	trackBar3->Maximum = 10000;
	trackBar4->Maximum = 10000;
	trackBar5->Maximum = 3600000;
	trackBar6->Maximum = 3600000;
	trackBar7->Maximum = 3600000;
	trackBar8->Maximum = 10000;
	trackBar9->Maximum = 10000;
	trackBar10->Maximum = 10000;
	trackBar0->TickFrequency = 2;
	trackBar1->TickFrequency = 1000;
	trackBar2->TickFrequency = 1000;
	trackBar3->TickFrequency = 1000;
	trackBar4->TickFrequency = 1000;
	trackBar5->TickFrequency = 300000;
	trackBar6->TickFrequency = 300000;
	trackBar7->TickFrequency = 300000;
	trackBar8->TickFrequency = 1000;
	trackBar9->TickFrequency = 1000;
	trackBar10->TickFrequency = 1000;

	tableLayoutPanel->ColumnCount = 20;
	tableLayoutPanel->RowCount = 13;
	for (int i = 0; i < 20; i++) {
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
	}
	for (int i = 0; i < 13; i++) {
		tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
	}

	tableLayoutPanel->Controls->Add(label0, 1, 0);
	tableLayoutPanel->Controls->Add(label1, 1, 1);
	tableLayoutPanel->Controls->Add(label2, 1, 2);
	tableLayoutPanel->Controls->Add(label3, 1, 3);
	tableLayoutPanel->Controls->Add(label4, 1, 4);
	tableLayoutPanel->Controls->Add(label5, 1, 5);
	tableLayoutPanel->Controls->Add(label6, 1, 6);
	tableLayoutPanel->Controls->Add(label7, 1, 7);
	tableLayoutPanel->Controls->Add(label8, 1, 8);
	tableLayoutPanel->Controls->Add(label9, 1, 9);
	tableLayoutPanel->Controls->Add(label10, 1, 10);
	tableLayoutPanel->Controls->Add(label11, 1, 11);
	tableLayoutPanel->Controls->Add(comboBox0, 7, 1);
	tableLayoutPanel->Controls->Add(textBox0, 16, 0);
	tableLayoutPanel->Controls->Add(textBox1, 16, 2);
	tableLayoutPanel->Controls->Add(textBox2, 16, 3);
	tableLayoutPanel->Controls->Add(textBox3, 16, 4);
	tableLayoutPanel->Controls->Add(textBox4, 16, 5);
	tableLayoutPanel->Controls->Add(textBox5, 16, 6);
	tableLayoutPanel->Controls->Add(textBox6, 16, 7);
	tableLayoutPanel->Controls->Add(textBox7, 16, 8);
	tableLayoutPanel->Controls->Add(textBox8, 16, 9);
	tableLayoutPanel->Controls->Add(textBox9, 16, 10);
	tableLayoutPanel->Controls->Add(textBox10, 16, 11);
	tableLayoutPanel->Controls->Add(trackBar0, 7, 0);
	tableLayoutPanel->Controls->Add(trackBar1, 7, 2);
	tableLayoutPanel->Controls->Add(trackBar2, 7, 3);
	tableLayoutPanel->Controls->Add(trackBar3, 7, 4);
	tableLayoutPanel->Controls->Add(trackBar4, 7, 5);
	tableLayoutPanel->Controls->Add(trackBar5, 7, 6);
	tableLayoutPanel->Controls->Add(trackBar6, 7, 7);
	tableLayoutPanel->Controls->Add(trackBar7, 7, 8);
	tableLayoutPanel->Controls->Add(trackBar8, 7, 9);
	tableLayoutPanel->Controls->Add(trackBar9, 7, 10);
	tableLayoutPanel->Controls->Add(trackBar10, 7, 11);

	tableLayoutPanel->SetColumnSpan(label0, 5);
	tableLayoutPanel->SetColumnSpan(label1, 5);
	tableLayoutPanel->SetColumnSpan(label2, 5);
	tableLayoutPanel->SetColumnSpan(label3, 5);
	tableLayoutPanel->SetColumnSpan(label4, 5);
	tableLayoutPanel->SetColumnSpan(label5, 5);
	tableLayoutPanel->SetColumnSpan(label6, 5);
	tableLayoutPanel->SetColumnSpan(label7, 5);
	tableLayoutPanel->SetColumnSpan(label8, 5);
	tableLayoutPanel->SetColumnSpan(label9, 5);
	tableLayoutPanel->SetColumnSpan(label10, 5);
	tableLayoutPanel->SetColumnSpan(label11, 5);
	tableLayoutPanel->SetColumnSpan(comboBox0, 12);
	tableLayoutPanel->SetColumnSpan(textBox0, 3);
	tableLayoutPanel->SetColumnSpan(textBox1, 3);
	tableLayoutPanel->SetColumnSpan(textBox2, 3);
	tableLayoutPanel->SetColumnSpan(textBox3, 3);
	tableLayoutPanel->SetColumnSpan(textBox4, 3);
	tableLayoutPanel->SetColumnSpan(textBox5, 3);
	tableLayoutPanel->SetColumnSpan(textBox6, 3);
	tableLayoutPanel->SetColumnSpan(textBox7, 3);
	tableLayoutPanel->SetColumnSpan(textBox8, 3);
	tableLayoutPanel->SetColumnSpan(textBox9, 3);
	tableLayoutPanel->SetColumnSpan(textBox10, 3);
	tableLayoutPanel->SetColumnSpan(trackBar0, 8);
	tableLayoutPanel->SetColumnSpan(trackBar1, 8);
	tableLayoutPanel->SetColumnSpan(trackBar2, 8);
	tableLayoutPanel->SetColumnSpan(trackBar3, 8);
	tableLayoutPanel->SetColumnSpan(trackBar4, 8);
	tableLayoutPanel->SetColumnSpan(trackBar5, 8);
	tableLayoutPanel->SetColumnSpan(trackBar6, 8);
	tableLayoutPanel->SetColumnSpan(trackBar7, 8);
	tableLayoutPanel->SetColumnSpan(trackBar8, 8);
	tableLayoutPanel->SetColumnSpan(trackBar9, 8);
	tableLayoutPanel->SetColumnSpan(trackBar10, 8);

	
	SetTrackBarValue(trackBar0->Name);
	SetTrackBarValue(trackBar1->Name);
	SetTrackBarValue(trackBar2->Name);
	SetTrackBarValue(trackBar3->Name);
	SetTrackBarValue(trackBar4->Name);
	SetTrackBarValue(trackBar5->Name);
	SetTrackBarValue(trackBar6->Name);
	SetTrackBarValue(trackBar7->Name);
	SetTrackBarValue(trackBar8->Name);
	SetTrackBarValue(trackBar9->Name);
	SetTrackBarValue(trackBar10->Name);
	SetTextBoxValue(textBox0->Name);
	SetTextBoxValue(textBox1->Name);
	SetTextBoxValue(textBox2->Name);
	SetTextBoxValue(textBox3->Name);
	SetTextBoxValue(textBox4->Name);
	SetTextBoxValue(textBox5->Name);
	SetTextBoxValue(textBox6->Name);
	SetTextBoxValue(textBox7->Name);
	SetTextBoxValue(textBox8->Name);
	SetTextBoxValue(textBox9->Name);
	SetTextBoxValue(textBox10->Name);
}

private:void SettPropertyPanel(String^ SelectedNodeName) {
	label0->Text = "Texture";
	label1->Text = "BirthPlace";
	label2->Text = "Length";
	label3->Text = "XRotation";
	label4->Text = "YRotation";
	label5->Text = "ZRotation";
	label0->ForeColor = Color::White;
	label1->ForeColor = Color::White;
	label2->ForeColor = Color::White;
	label3->ForeColor = Color::White;
	label4->ForeColor = Color::White;
	label5->ForeColor = Color::White;
	label0->Dock = DockStyle::Bottom;
	label1->Dock = DockStyle::Bottom;
	label2->Dock = DockStyle::Bottom;
	label3->Dock = DockStyle::Bottom;
	label4->Dock = DockStyle::Bottom;
	label5->Dock = DockStyle::Bottom;
	comboBox0->Name = "0";
	comboBox0->Dock = DockStyle::Bottom;
	comboBox0->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox0->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox0->Items->Clear();
	if (i.GetValue(0, comboBox0->Name) != -1) {
		comboBox0->SelectedIndex = i.GetValue(0, comboBox0->Name);
	}
	textBox0->Name = "0";
	textBox1->Name = "1";
	textBox2->Name = "2";
	textBox3->Name = "3";
	textBox4->Name = "4";
	textBox0->Dock = DockStyle::Bottom;
	textBox1->Dock = DockStyle::Bottom;
	textBox2->Dock = DockStyle::Bottom;
	textBox3->Dock = DockStyle::Bottom;
	textBox4->Dock = DockStyle::Bottom;
	textBox0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox0->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox1->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox3->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox4->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox0->Text = ((double)i.GetValue(1, textBox0->Name) / 10000).ToString();
	textBox1->Text = ((double)i.GetValue(1, textBox1->Name) / 10000).ToString();
	textBox2->Text = ((double)i.GetValue(1, textBox2->Name) / 10000).ToString();
	textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
	textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
	trackBar0->Name = "0";
	trackBar1->Name = "1";
	trackBar2->Name = "2";
	trackBar3->Name = "3";
	trackBar4->Name = "4";
	trackBar0->Dock = DockStyle::Bottom;
	trackBar1->Dock = DockStyle::Bottom;
	trackBar2->Dock = DockStyle::Bottom;
	trackBar3->Dock = DockStyle::Bottom;
	trackBar4->Dock = DockStyle::Bottom;
	trackBar0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar0->Minimum = 0;
	trackBar1->Minimum = 0;
	trackBar2->Minimum = 0;
	trackBar3->Minimum = 0;
	trackBar4->Minimum = 0;
	trackBar0->Maximum = 10000;
	trackBar1->Maximum = 10000;
	trackBar2->Maximum = 3600000;
	trackBar3->Maximum = 3600000;
	trackBar4->Maximum = 3600000;
	trackBar0->TickFrequency = 1000;
	trackBar1->TickFrequency = 1000;
	trackBar2->TickFrequency = 300000;
	trackBar3->TickFrequency = 300000;
	trackBar4->TickFrequency = 300000;

	tableLayoutPanel->ColumnCount = 20;
	tableLayoutPanel->RowCount = 7;
	for (int i = 0; i < 20; i++) {
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
	}
	for (int i = 0; i < 7; i++) {
		tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
	}

	tableLayoutPanel->Controls->Add(label0, 1, 0);
	tableLayoutPanel->Controls->Add(label1, 1, 1);
	tableLayoutPanel->Controls->Add(label2, 1, 2);
	tableLayoutPanel->Controls->Add(label3, 1, 3);
	tableLayoutPanel->Controls->Add(label4, 1, 4);
	tableLayoutPanel->Controls->Add(label5, 1, 5);
	tableLayoutPanel->Controls->Add(comboBox0, 7, 0);
	tableLayoutPanel->Controls->Add(textBox0, 16, 1);
	tableLayoutPanel->Controls->Add(textBox1, 16, 2);
	tableLayoutPanel->Controls->Add(textBox2, 16, 3);
	tableLayoutPanel->Controls->Add(textBox3, 16, 4);
	tableLayoutPanel->Controls->Add(textBox4, 16, 5);
	tableLayoutPanel->Controls->Add(trackBar0, 7, 1);
	tableLayoutPanel->Controls->Add(trackBar1, 7, 2);
	tableLayoutPanel->Controls->Add(trackBar2, 7, 3);
	tableLayoutPanel->Controls->Add(trackBar3, 7, 4);
	tableLayoutPanel->Controls->Add(trackBar4, 7, 5);

	tableLayoutPanel->SetColumnSpan(label0, 5);
	tableLayoutPanel->SetColumnSpan(label1, 5);
	tableLayoutPanel->SetColumnSpan(label2, 5);
	tableLayoutPanel->SetColumnSpan(label3, 5);
	tableLayoutPanel->SetColumnSpan(label4, 5);
	tableLayoutPanel->SetColumnSpan(label5, 5);
	tableLayoutPanel->SetColumnSpan(comboBox0, 12);
	tableLayoutPanel->SetColumnSpan(textBox0, 3);
	tableLayoutPanel->SetColumnSpan(textBox1, 3);
	tableLayoutPanel->SetColumnSpan(textBox2, 3);
	tableLayoutPanel->SetColumnSpan(textBox3, 3);
	tableLayoutPanel->SetColumnSpan(textBox4, 3);
	tableLayoutPanel->SetColumnSpan(trackBar0, 8);
	tableLayoutPanel->SetColumnSpan(trackBar1, 8);
	tableLayoutPanel->SetColumnSpan(trackBar2, 8);
	tableLayoutPanel->SetColumnSpan(trackBar3, 8);
	tableLayoutPanel->SetColumnSpan(trackBar4, 8);

	
	SetTrackBarValue(trackBar0->Name);
	SetTrackBarValue(trackBar1->Name);
	SetTrackBarValue(trackBar2->Name);
	SetTrackBarValue(trackBar3->Name);
	SetTrackBarValue(trackBar4->Name);
	SetTextBoxValue(textBox0->Name);
	SetTextBoxValue(textBox1->Name);
	SetTextBoxValue(textBox2->Name);
	SetTextBoxValue(textBox3->Name);
	SetTextBoxValue(textBox4->Name);
}

private:void SetFPropertyPanel(String^ SelectedNodeName) {
	label0->Text = "Fractal";
	label1->Text = "FractalRepeat";
	label0->ForeColor = Color::White;
	label1->ForeColor = Color::White;
	label0->Dock = DockStyle::Bottom;
	label1->Dock = DockStyle::Bottom;
	comboBox0->Name = "0";
	comboBox0->Dock = DockStyle::Bottom;
	comboBox0->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	comboBox0->Leave += gcnew System::EventHandler(this, &MyForm::comboBox_TextChanged);
	comboBox0->Items->Clear();
	if (i.GetValue(0, comboBox0->Name) != -1) {
		comboBox0->SelectedIndex = i.GetValue(0, comboBox0->Name);
	}
	textBox0->Name = "0";
	textBox0->Dock = DockStyle::Bottom;
	textBox0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBox0->Leave += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
	textBox0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	textBox0->Text = ((double)i.GetValue(1, textBox0->Name) / 10000).ToString();
	trackBar0->Name = "0";
	trackBar0->Dock = DockStyle::Bottom;
	trackBar0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar_Scroll);
	trackBar0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControl_GotFocus);
	trackBar0->Minimum = 1;
	trackBar0->Maximum = 20;
	trackBar0->TickFrequency = 2;

	tableLayoutPanel->ColumnCount = 20;
	tableLayoutPanel->RowCount = 3;
	for (int i = 0; i < 20; i++) {
		tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
	}
	for (int i = 0; i < 3; i++) {
		tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
	}

	tableLayoutPanel->Controls->Add(label0, 1, 0);
	tableLayoutPanel->Controls->Add(label1, 1, 1);
	tableLayoutPanel->Controls->Add(comboBox0, 7, 0);
	tableLayoutPanel->Controls->Add(textBox0, 16, 1);
	tableLayoutPanel->Controls->Add(trackBar0, 7, 1);

	tableLayoutPanel->SetColumnSpan(label0, 5);
	tableLayoutPanel->SetColumnSpan(label1, 5);
	tableLayoutPanel->SetColumnSpan(comboBox0, 12);
	tableLayoutPanel->SetColumnSpan(textBox0, 3);
	tableLayoutPanel->SetColumnSpan(trackBar0, 8);

	
	SetTrackBarValue(trackBar0->Name);
	SetTextBoxValue(textBox0->Name);
}

private: System::Void comboBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	i.SetComboBoxValue(((ComboBox^)sender)->SelectedIndex,((Control^)sender)->Name);
	int num = 0;
	for (int i = 0; i < (((Control^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((Control^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 1:
			i.Chart0Point = 0;
			SetTrackBarValue(trackBar17->Name);
			SetTrackBarValue(trackBar18->Name);
			RePaintChart(chart0->Name);
			break;
		case 2:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTrackBarValue(trackBar21->Name);
			SetTrackBarValue(trackBar22->Name);
			SetTrackBarValue(trackBar23->Name);
			SetTrackBarValue(trackBar24->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		}
		break;
	case 2:
		switch (num) {
		case 1:
			i.Chart0Point = 0;
			SetTrackBarValue(trackBar10->Name);
			SetTrackBarValue(trackBar11->Name);
			RePaintChart(chart0->Name);
			break;
		case 2:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTrackBarValue(trackBar13->Name);
			SetTrackBarValue(trackBar14->Name);
			SetTrackBarValue(trackBar15->Name);
			SetTrackBarValue(trackBar16->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		}
		break;
	}
	nodetotexttrigger();
}

private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int num = 0;
	int value = 0;
	int minimum = 0;
	int maximum = 16777216;
	string ControlText = "";
	for (int i = 0; i < (((TextBox^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((TextBox^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	for (int i = 0; i < ((TextBox^)sender)->Text->ToCharArray()->Length; i++) {
		ControlText += ((TextBox^)sender)->Text->ToCharArray()[i];
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			minimum = trackBar0->Minimum;
			maximum = trackBar0->Maximum;
			break;
		case 1:
			minimum = trackBar1->Minimum;
			break;
		case 2:
			minimum = trackBar2->Minimum;
			break;
		case 3:
			minimum = trackBar3->Minimum;
			break;
		case 4:
			minimum = trackBar4->Minimum;
			break;
		case 5:
			minimum = trackBar5->Minimum;
			break;
		case 6:
			minimum = trackBar6->Minimum;
			break;
		case 7:
			minimum = trackBar7->Minimum;
			break;
		case 8:
			minimum = trackBar8->Minimum;
			break;
		case 9:
			minimum = trackBar9->Minimum;
			break;
		case 10:
			minimum = trackBar10->Minimum;
			break;
		case 11:
			minimum = trackBar11->Minimum;
			break;
		case 12:
			minimum = trackBar12->Minimum;
			break;
		case 13:
			minimum = trackBar13->Minimum;
			break;
		case 14:
			minimum = trackBar14->Minimum;
			break;
		case 15:
			minimum = trackBar15->Minimum;
			break;
		case 16:
			minimum = trackBar16->Minimum;
			maximum = trackBar16->Maximum;
			break;
		case 17:
			minimum = trackBar17->Minimum;
			break;
		case 18:
			minimum = trackBar18->Minimum;
			break;
		case 19:
			minimum = trackBar19->Minimum;
			break;
		case 20:
			minimum = trackBar20->Minimum;
			maximum = trackBar20->Maximum;
			break; 
		case 21:
			minimum = trackBar21->Minimum;
			break;
		case 22:
			minimum = trackBar22->Minimum;
			break;
		case 23:
			minimum = trackBar23->Minimum;
			break;
		case 24:
			minimum = trackBar24->Minimum;
			break;
		case 25:
			minimum = trackBar25->Minimum;
			break;
		}
		if (num == 0 || num == 1 || num == 2 || num == 3 || num == 16 || num == 20) {
			value = std::stoi(ControlText);
		}
		else {
			value = (int)(std::stod(ControlText) * 10000);
		}
		break;
	case 2:
		switch (num) {
		case 0:
			minimum = trackBar0->Minimum;
			break;
		case 1:
			minimum = trackBar1->Minimum;
			break;
		case 2:
			minimum = trackBar2->Minimum;
			break;
		case 3:
			minimum = trackBar3->Minimum;
			break;
		case 4:
			minimum = trackBar4->Minimum;
			break;
		case 5:
			minimum = trackBar5->Minimum;
			break;
		case 6:
			minimum = trackBar6->Minimum;
			break;
		case 7:
			minimum = trackBar7->Minimum;
			break;
		case 8:
			minimum = trackBar8->Minimum;
			break;
		case 9:
			minimum = trackBar9->Minimum;
			maximum = trackBar9->Maximum;
			break;
		case 10:
			minimum = trackBar10->Minimum;
			break;
		case 11:
			minimum = trackBar11->Minimum;
			break;
		case 12:
			minimum = trackBar12->Minimum;
			maximum = trackBar12->Maximum;
			break;
		case 13:
			minimum = trackBar13->Minimum;
			break;
		case 14:
			minimum = trackBar14->Minimum;
			break;
		case 15:
			minimum = trackBar15->Minimum;
			break;
		case 16:
			minimum = trackBar16->Minimum;
			break;
		}
		if (num == 0 || num == 1 || num == 2 ||num == 9 || num == 12) {
			value = std::stoi(ControlText);
		}
		else {
			value = (int)(std::stod(ControlText) * 10000);
		}
		break;
	case 3:
		switch (num) {
		case 0:
			minimum = trackBar0->Minimum;
			break;
		case 1:
			minimum = trackBar1->Minimum;
			break;
		case 2:
			minimum = trackBar2->Minimum;
			break;
		case 3:
			minimum = trackBar3->Minimum;
			break;
		case 4:
			minimum = trackBar4->Minimum;
			break;
		case 5:
			minimum = trackBar5->Minimum;
			break;
		case 6:
			minimum = trackBar6->Minimum;
			break;
		case 7:
			minimum = trackBar7->Minimum;
			break;
		case 8:
			minimum = trackBar8->Minimum;
			break;
		case 9:
			minimum = trackBar9->Minimum;
			break;
		case 10:
			minimum = trackBar10->Minimum;
			break;
		}
		if (num == 0) {
			value = std::stoi(ControlText);
		}
		else {
			value = (int)(std::stod(ControlText) * 10000);
		}
		break;
	case 4:
		switch (num) {
		case 0:
			minimum = trackBar0->Minimum;
			break;
		case 1:
			minimum = trackBar1->Minimum;
			break;
		case 2:
			minimum = trackBar2->Minimum;
			break;
		case 3:
			minimum = trackBar3->Minimum;
			break;
		case 4:
			minimum = trackBar4->Minimum;
			break;
		}
		value = (int)(std::stod(ControlText) * 10000);
		break;
	case 5:
		minimum = trackBar0->Minimum;
		value = std::stoi(ControlText);
		break;
	}
	if (value < minimum) {
		value = minimum;
	}
	if (value > maximum) {
		value = maximum;
	}
	switch (i.GetPropNodeType()) {
	case 1:
		if (((Control^)sender)->Name == "0") {
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n > value; n--) {
				GroupNodeDeleter(n - 1);
			}
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n < value; n++) {
				GroupNodeCreater(n);
			}
		}
		break;
	case 3:
		if (((Control^)sender)->Name == "0") {
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n > value; n--) {
				GroupNodeDeleter(n - 1);
			}
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n < value; n++) {
				GroupNodeCreater(n);
			}
		}
		break;
	}
	i.SetTBValue(value, ((Control^)sender)->Name);
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 9:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 10:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 11:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 12:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 13:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 14:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 15:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 16:
			i.Chart0Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar17->Name);
			SetTrackBarValue(trackBar18->Name);
			RePaintChart(chart0->Name);
			break;
		case 19:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 20:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar21->Name);
			SetTrackBarValue(trackBar22->Name);
			SetTrackBarValue(trackBar23->Name);
			SetTrackBarValue(trackBar24->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 25:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 9:
			i.Chart0Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar10->Name);
			SetTrackBarValue(trackBar11->Name);
			RePaintChart(chart0->Name);
			break;
		case 12:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar13->Name);
			SetTrackBarValue(trackBar14->Name);
			SetTrackBarValue(trackBar15->Name);
			SetTrackBarValue(trackBar16->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		}
		break;
	case 3:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 9:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 10:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 4:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 5:
		SetTextBoxValue(((Control^)sender)->Name);
		SetTrackBarValue(((Control^)sender)->Name);
		break;
	}
	nodetotexttrigger();
}

private: System::Void tableLayoutPanel_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	i.ScrollX = -tableLayoutPanel->AutoScrollPosition.X;
	i.ScrollY = -tableLayoutPanel->AutoScrollPosition.Y;
}

private: System::Void tableLayoutPanel_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    i.ScrollX = -tableLayoutPanel->AutoScrollPosition.X;
    i.ScrollY = -tableLayoutPanel->AutoScrollPosition.Y;
}

private: System::Void tableLayoutPanelControl_GotFocus(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->AutoScrollPosition=Point(i.ScrollX,i.ScrollY);
	tableLayoutPanel->ResumeLayout(true);
}

private: System::Void tableLayoutPanelControl_Enter(System::Object^ sender, System::EventArgs^ e) {
    tableLayoutPanel->SuspendLayout();
}

private: System::Void trackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
	switch (i.GetPropNodeType()) {
	case 1:
		if (((Control^)sender)->Name == "0") {
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n > ((TrackBar^)sender)->Value; n--) {
				GroupNodeDeleter(n-1);
			}
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n < ((TrackBar^)sender)->Value; n++) {
				GroupNodeCreater(n);
			}
		}
		break;
	case 3:
		if (((Control^)sender)->Name == "0") {
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n > ((TrackBar^)sender)->Value; n--) {
				GroupNodeDeleter(n - 1);
			}
			for (int n = i.GetValue(1, ((Control^)sender)->Name); n < ((TrackBar^)sender)->Value; n++) {
				GroupNodeCreater(n);
			}
		}
		break;
	}
	i.SetTBValue(((TrackBar^)sender)->Value,((Control^)sender)->Name);
	int num = 0;
	for (int i = 0; i < (((Control^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((Control^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 9:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 10:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 11:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 12:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 13:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 14:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 15:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 16:
			i.Chart0Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar17->Name);
			SetTrackBarValue(trackBar18->Name);
			RePaintChart(chart0->Name);
			break;
		case 17:
			RePaintChart(chart0->Name);
			break;
		case 18:
			RePaintChart(chart0->Name);
			break;
		case 19:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 20:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar21->Name);
			SetTrackBarValue(trackBar22->Name);
			SetTrackBarValue(trackBar23->Name);
			SetTrackBarValue(trackBar24->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 21:
			RePaintChart(chart1->Name);
			break;
		case 22:
			SetTrackBarValue(trackBar24->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 23:
			RePaintChart(chart2->Name);
			break;
		case 24:
			SetTrackBarValue(trackBar22->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 25:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 9:
			i.Chart0Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar10->Name);
			SetTrackBarValue(trackBar11->Name);
			RePaintChart(chart0->Name);
			break;
		case 10:
			RePaintChart(chart0->Name);
			break;
		case 11:
			RePaintChart(chart0->Name);
			break;
		case 12:
			i.Chart1Point = 0;
			i.Chart2Point = 0;
			SetTextBoxValue(((Control^)sender)->Name);
			SetTrackBarValue(trackBar13->Name);
			SetTrackBarValue(trackBar14->Name);
			SetTrackBarValue(trackBar15->Name);
			SetTrackBarValue(trackBar16->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 13:
			RePaintChart(chart1->Name);
			break;
		case 14:
			SetTrackBarValue(trackBar16->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		case 15:
			RePaintChart(chart2->Name);
			break;
		case 16:
			SetTrackBarValue(trackBar14->Name);
			RePaintChart(chart1->Name);
			RePaintChart(chart2->Name);
			break;
		}
		break;
	case 3:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 5:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 6:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 7:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 8:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 9:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 10:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 4:
		switch (num) {
		case 0:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 1:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 2:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 3:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		case 4:
			SetTextBoxValue(((Control^)sender)->Name);
			break;
		}
		break;
	case 5:
		SetTextBoxValue(((Control^)sender)->Name);
		break;
	}
	nodetotexttrigger();
}

private: System::Void textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter) {
		ActiveControl = NonFocus;
	}
}

private:void GroupNodeCreater(int num) {
	TreeNode^ treenode = gcnew TreeNode();
	switch (i.GetPropNodeType()) {
	case 1:
		treenode->Text = "b";
		treenode->Name = treeView1->SelectedNode->Name + "-" + "b" + num;
		treeView1->SelectedNode->Nodes[0]->Nodes->Add(treenode);
		System::Diagnostics::Debug::WriteLine(treenode->Name);
		break;
	case 3:
		treenode->Text = "t";
		treenode->Name = treeView1->SelectedNode->Name + "-" + "t" + num;
		treeView1->SelectedNode->Nodes[0]->Nodes->Add(treenode);
		System::Diagnostics::Debug::WriteLine(treenode->Name);
		break;
	}
}

private:void GroupNodeDeleter(int num) {
	treeView1->SelectedNode->Nodes[0]->Nodes[num]->Remove();
}

private:void SetTextBoxValue(String^ ControlName) {
	int num = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
			break;
		case 1:
			textBox1->Text = i.GetValue(1, textBox1->Name).ToString();
			break;
		case 2:
			textBox2->Text = i.GetValue(1, textBox2->Name).ToString();
			break;
		case 3:
			textBox3->Text = i.GetValue(1, textBox3->Name).ToString();
			break;
		case 4:
			textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
			break;
		case 5:
			textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
			break;
		case 6:
			textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
			break;
		case 7:
			textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
			break;
		case 8:
			textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
			break;
		case 9:
			textBox9->Text = ((double)i.GetValue(1, textBox9->Name) / 10000).ToString();
			break;
		case 10:
			textBox10->Text = ((double)i.GetValue(1, textBox10->Name) / 10000).ToString();
			break;
		case 11:
			textBox11->Text = ((double)i.GetValue(1, textBox11->Name) / 10000).ToString();
			break;
		case 12:
			textBox12->Text = ((double)i.GetValue(1, textBox12->Name) / 10000).ToString();
			break;
		case 13:
			textBox13->Text = ((double)i.GetValue(1, textBox13->Name) / 10000).ToString();
			break;
		case 14:
			textBox14->Text = ((double)i.GetValue(1, textBox14->Name) / 10000).ToString();
			break;
		case 15:
			textBox15->Text = ((double)i.GetValue(1, textBox15->Name) / 10000).ToString();
			break;
		case 16:
			textBox16->Text = i.GetValue(1, textBox16->Name).ToString();
			break;
		case 19:
			textBox17->Text = ((double)i.GetValue(1, textBox17->Name) / 10000).ToString();
			break;
		case 20:
			textBox18->Text = i.GetValue(1, textBox18->Name).ToString();
			break;
		case 25:
			textBox19->Text = ((double)i.GetValue(1, textBox19->Name) / 10000).ToString();
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
			break;
		case 1:
			textBox1->Text = i.GetValue(1, textBox1->Name).ToString();
			break;
		case 2:
			textBox2->Text = i.GetValue(1, textBox2->Name).ToString();
			break;
		case 3:
			textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
			break;
		case 4:
			textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
			break;
		case 5:
			textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
			break;
		case 6:
			textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
			break;
		case 7:
			textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
			break;
		case 8:
			textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
			break;
		case 9:
			textBox9->Text = i.GetValue(1, textBox9->Name).ToString();
			break;
		case 12:
			textBox12->Text = i.GetValue(1, textBox12->Name).ToString();
			break;
		}
		break;
	case 3:
		switch (num) {
		case 0:
			textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
			break;
		case 1:
			textBox1->Text = ((double)i.GetValue(1, textBox1->Name) / 10000).ToString();
			break;
		case 2:
			textBox2->Text = ((double)i.GetValue(1, textBox2->Name) / 10000).ToString();
			break;
		case 3:
			textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
			break;
		case 4:
			textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
			break;
		case 5:
			textBox5->Text = ((double)i.GetValue(1, textBox5->Name) / 10000).ToString();
			break;
		case 6:
			textBox6->Text = ((double)i.GetValue(1, textBox6->Name) / 10000).ToString();
			break;
		case 7:
			textBox7->Text = ((double)i.GetValue(1, textBox7->Name) / 10000).ToString();
			break;
		case 8:
			textBox8->Text = ((double)i.GetValue(1, textBox8->Name) / 10000).ToString();
			break;
		case 9:
			textBox9->Text = ((double)i.GetValue(1, textBox9->Name) / 10000).ToString();
			break;
		case 10:
			textBox10->Text = ((double)i.GetValue(1, textBox10->Name) / 10000).ToString();
			break;
		}
		break;
	case 4:
		switch (num) {
		case 0:
			textBox0->Text = ((double)i.GetValue(1, textBox0->Name) / 10000).ToString();
			break;
		case 1:
			textBox1->Text = ((double)i.GetValue(1, textBox1->Name) / 10000).ToString();
			break;
		case 2:
			textBox2->Text = ((double)i.GetValue(1, textBox2->Name) / 10000).ToString();
			break;
		case 3:
			textBox3->Text = ((double)i.GetValue(1, textBox3->Name) / 10000).ToString();
			break;
		case 4:
			textBox4->Text = ((double)i.GetValue(1, textBox4->Name) / 10000).ToString();
			break;
		}
		break;
	case 5:
		textBox0->Text = i.GetValue(1, textBox0->Name).ToString();
		break;
	}
}

private:void SetTrackBarValue(String^ ControlName) {
	int num = 0;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			if (trackBar0->Maximum < i.GetValue(1, trackBar0->Name)) {
				trackBar0->Value = trackBar0->Maximum;
			}
			else {
				trackBar0->Value = i.GetValue(1, trackBar0->Name);
			}
			break;
		case 1:
			if (trackBar1->Maximum < i.GetValue(1, trackBar1->Name)) {
				trackBar1->Value = trackBar1->Maximum;
			}
			else {
				trackBar1->Value = i.GetValue(1, trackBar1->Name);
			}
			break;
		case 2:
			if (trackBar2->Maximum < i.GetValue(1, trackBar2->Name)) {
				trackBar2->Value = trackBar2->Maximum;
			}
			else {
				trackBar2->Value = i.GetValue(1, trackBar2->Name);
			}
			break;
		case 3:
			if (trackBar3->Maximum < i.GetValue(1, trackBar3->Name)) {
				trackBar3->Value = trackBar3->Maximum;
			}
			else {
				trackBar3->Value = i.GetValue(1, trackBar3->Name);
			}
			break;
		case 4:
			if (trackBar4->Maximum < i.GetValue(1, trackBar4->Name)) {
				trackBar4->Value = trackBar4->Maximum;
			}
			else {
				trackBar4->Value = i.GetValue(1, trackBar4->Name);
			}
			break;
		case 5:
			if (trackBar5->Maximum < i.GetValue(1, trackBar5->Name)) {
				trackBar5->Value = trackBar5->Maximum;
			}
			else {
				trackBar5->Value = i.GetValue(1, trackBar5->Name);
			}
			break;
		case 6:
			if (trackBar6->Maximum < i.GetValue(1, trackBar6->Name)) {
				trackBar6->Value = trackBar6->Maximum;
			}
			else {
				trackBar6->Value = i.GetValue(1, trackBar6->Name);
			}
			break;
		case 7:
			if (trackBar7->Maximum < i.GetValue(1, trackBar7->Name)) {
				trackBar7->Value = trackBar7->Maximum;
			}
			else {
				trackBar7->Value = i.GetValue(1, trackBar7->Name);
			}
			break;
		case 8:
			if (trackBar8->Maximum < i.GetValue(1, trackBar8->Name)) {
				trackBar8->Value = trackBar8->Maximum;
			}
			else {
				trackBar8->Value = i.GetValue(1, trackBar8->Name);
			}
			break;
		case 9:
			if (trackBar9->Maximum < i.GetValue(1, trackBar9->Name)) {
				trackBar9->Value = trackBar9->Maximum;
			}
			else {
				trackBar9->Value = i.GetValue(1, trackBar9->Name);
			}
			break;
		case 10:
			if (trackBar10->Maximum < i.GetValue(1, trackBar10->Name)) {
				trackBar10->Value = trackBar10->Maximum;
			}
			else {
				trackBar10->Value = i.GetValue(1, trackBar10->Name);
			}
			break;
		case 11:
			if (trackBar11->Maximum < i.GetValue(1, trackBar11->Name)) {
				trackBar11->Value = trackBar11->Maximum;
			}
			else {
				trackBar11->Value = i.GetValue(1, trackBar11->Name);
			}
			break;
		case 12:
			if (trackBar12->Maximum < i.GetValue(1, trackBar12->Name)) {
				trackBar12->Value = trackBar12->Maximum;
			}
			else {
				trackBar12->Value = i.GetValue(1, trackBar12->Name);
			}
			break;
		case 13:
			if (trackBar13->Maximum < i.GetValue(1, trackBar13->Name)) {
				trackBar13->Value = trackBar13->Maximum;
			}
			else {
				trackBar13->Value = i.GetValue(1, trackBar13->Name);
			}
			break;
		case 14:
			if (trackBar14->Maximum < i.GetValue(1, trackBar14->Name)) {
				trackBar14->Value = trackBar14->Maximum;
			}
			else {
				trackBar14->Value = i.GetValue(1, trackBar14->Name);
			}
			break;
		case 15:
			if (trackBar15->Maximum < i.GetValue(1, trackBar15->Name)) {
				trackBar15->Value = trackBar15->Maximum;
			}
			else {
				trackBar15->Value = i.GetValue(1, trackBar15->Name);
			}
			break;
		case 16:
			if (trackBar16->Maximum < i.GetValue(1, trackBar16->Name)) {
				trackBar16->Value = trackBar16->Maximum;
			}
			else {
				trackBar16->Value = i.GetValue(1, trackBar16->Name);
			}
			break;
		case 17:
			if (trackBar17->Maximum < i.GetValue(1, trackBar17->Name)) {
				trackBar17->Value = trackBar17->Maximum;
			}
			else {
				trackBar17->Value = i.GetValue(1, trackBar17->Name);
			}
			break;
		case 18:
			if (trackBar18->Maximum < i.GetValue(1, trackBar18->Name)) {
				trackBar18->Value = trackBar18->Maximum;
			}
			else {
				trackBar18->Value = i.GetValue(1, trackBar18->Name);
			}
			break;
		case 19:
			if (trackBar19->Maximum < i.GetValue(1, trackBar19->Name)) {
				trackBar19->Value = trackBar19->Maximum;
			}
			else {
				trackBar19->Value = i.GetValue(1, trackBar19->Name);
			}
			break;
		case 20:
			if (trackBar20->Maximum < i.GetValue(1, trackBar20->Name)) {
				trackBar20->Value = trackBar20->Maximum;
			}
			else {
				trackBar20->Value = i.GetValue(1, trackBar20->Name);
			}
			break;
		case 21:
			if (trackBar21->Maximum < i.GetValue(1, trackBar21->Name)) {
				trackBar21->Value = trackBar21->Maximum;
			}
			else {
				trackBar21->Value = i.GetValue(1, trackBar21->Name);
			}
			break;
		case 22:
			if (trackBar22->Maximum < i.GetValue(1, trackBar22->Name)) {
				trackBar22->Value = trackBar22->Maximum;
			}
			else {
				trackBar22->Value = i.GetValue(1, trackBar22->Name);
			}
			break;
		case 23:
			if (trackBar23->Maximum < i.GetValue(1, trackBar23->Name)) {
				trackBar23->Value = trackBar23->Maximum;
			}
			else {
				trackBar23->Value = i.GetValue(1, trackBar23->Name);
			}
			break;
		case 24:
			if (trackBar24->Maximum < i.GetValue(1, trackBar24->Name)) {
				trackBar24->Value = trackBar24->Maximum;
			}
			else {
				trackBar24->Value = i.GetValue(1, trackBar24->Name);
			}
			break;
		case 25:
			if (trackBar25->Maximum < i.GetValue(1, trackBar25->Name)) {
				trackBar25->Value = trackBar25->Maximum;
			}
			else {
				trackBar25->Value = i.GetValue(1, trackBar25->Name);
			}
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			if (trackBar0->Maximum < i.GetValue(1, trackBar0->Name)) {
				trackBar0->Value = trackBar0->Maximum;
			}
			else {
				trackBar0->Value = i.GetValue(1, trackBar0->Name);
			}
			break;
		case 1:
			if (trackBar1->Maximum < i.GetValue(1, trackBar1->Name)) {
				trackBar1->Value = trackBar1->Maximum;
			}
			else {
				trackBar1->Value = i.GetValue(1, trackBar1->Name);
			}
			break;
		case 2:
			if (trackBar2->Maximum < i.GetValue(1, trackBar2->Name)) {
				trackBar2->Value = trackBar2->Maximum;
			}
			else {
				trackBar2->Value = i.GetValue(1, trackBar2->Name);
			}
			break;
		case 3:
			if (trackBar3->Maximum < i.GetValue(1, trackBar3->Name)) {
				trackBar3->Value = trackBar3->Maximum;
			}
			else {
				trackBar3->Value = i.GetValue(1, trackBar3->Name);
			}
			break;
		case 4:
			if (trackBar4->Maximum < i.GetValue(1, trackBar4->Name)) {
				trackBar4->Value = trackBar4->Maximum;
			}
			else {
				trackBar4->Value = i.GetValue(1, trackBar4->Name);
			}
			break;
		case 5:
			if (trackBar5->Maximum < i.GetValue(1, trackBar5->Name)) {
				trackBar5->Value = trackBar5->Maximum;
			}
			else {
				trackBar5->Value = i.GetValue(1, trackBar5->Name);
			}
			break;
		case 6:
			if (trackBar6->Maximum < i.GetValue(1, trackBar6->Name)) {
				trackBar6->Value = trackBar6->Maximum;
			}
			else {
				trackBar6->Value = i.GetValue(1, trackBar6->Name);
			}
			break;
		case 7:
			if (trackBar7->Maximum < i.GetValue(1, trackBar7->Name)) {
				trackBar7->Value = trackBar7->Maximum;
			}
			else {
				trackBar7->Value = i.GetValue(1, trackBar7->Name);
			}
			break;
		case 8:
			if (trackBar8->Maximum < i.GetValue(1, trackBar8->Name)) {
				trackBar8->Value = trackBar8->Maximum;
			}
			else {
				trackBar8->Value = i.GetValue(1, trackBar8->Name);
			}
			break;
		case 9:
			if (trackBar9->Maximum < i.GetValue(1, trackBar9->Name)) {
				trackBar9->Value = trackBar9->Maximum;
			}
			else {
				trackBar9->Value = i.GetValue(1, trackBar9->Name);
			}
			break;
		case 10:
			if (trackBar10->Maximum < i.GetValue(1, trackBar10->Name)) {
				trackBar10->Value = trackBar10->Maximum;
			}
			else {
				trackBar10->Value = i.GetValue(1, trackBar10->Name);
			}
			break;
		case 11:
			if (trackBar11->Maximum < i.GetValue(1, trackBar11->Name)) {
				trackBar11->Value = trackBar11->Maximum;
			}
			else {
				trackBar11->Value = i.GetValue(1, trackBar11->Name);
			}
			break;
		case 12:
			if (trackBar12->Maximum < i.GetValue(1, trackBar12->Name)) {
				trackBar12->Value = trackBar12->Maximum;
			}
			else {
				trackBar12->Value = i.GetValue(1, trackBar12->Name);
			}
			break;
		case 13:
			if (trackBar13->Maximum < i.GetValue(1, trackBar13->Name)) {
				trackBar13->Value = trackBar13->Maximum;
			}
			else {
				trackBar13->Value = i.GetValue(1, trackBar13->Name);
			}
			break;
		case 14:
			if (trackBar14->Maximum < i.GetValue(1, trackBar14->Name)) {
				trackBar14->Value = trackBar14->Maximum;
			}
			else {
				trackBar14->Value = i.GetValue(1, trackBar14->Name);
			}
			break;
		case 15:
			if (trackBar15->Maximum < i.GetValue(1, trackBar15->Name)) {
				trackBar15->Value = trackBar15->Maximum;
			}
			else {
				trackBar15->Value = i.GetValue(1, trackBar15->Name);
			}
			break;
		case 16:
			if (trackBar16->Maximum < i.GetValue(1, trackBar16->Name)) {
				trackBar16->Value = trackBar16->Maximum;
			}
			else {
				trackBar16->Value = i.GetValue(1, trackBar16->Name);
			}
			break;
		}
		break;
	case 3:
		switch (num) {
		case 0:
			if (trackBar0->Maximum < i.GetValue(1, trackBar0->Name)) {
				trackBar0->Value = trackBar0->Maximum;
			}
			else {
				trackBar0->Value = i.GetValue(1, trackBar0->Name);
			}
			break;
		case 1:
			if (trackBar1->Maximum < i.GetValue(1, trackBar1->Name)) {
				trackBar1->Value = trackBar1->Maximum;
			}
			else {
				trackBar1->Value = i.GetValue(1, trackBar1->Name);
			}
			break;
		case 2:
			if (trackBar2->Maximum < i.GetValue(1, trackBar2->Name)) {
				trackBar2->Value = trackBar2->Maximum;
			}
			else {
				trackBar2->Value = i.GetValue(1, trackBar2->Name);
			}
			break;
		case 3:
			if (trackBar3->Maximum < i.GetValue(1, trackBar3->Name)) {
				trackBar3->Value = trackBar3->Maximum;
			}
			else {
				trackBar3->Value = i.GetValue(1, trackBar3->Name);
			}
			break;
		case 4:
			if (trackBar4->Maximum < i.GetValue(1, trackBar4->Name)) {
				trackBar4->Value = trackBar4->Maximum;
			}
			else {
				trackBar4->Value = i.GetValue(1, trackBar4->Name);
			}
			break;
		case 5:
			if (trackBar5->Maximum < i.GetValue(1, trackBar5->Name)) {
				trackBar5->Value = trackBar5->Maximum;
			}
			else {
				trackBar5->Value = i.GetValue(1, trackBar5->Name);
			}
			break;
		case 6:
			if (trackBar6->Maximum < i.GetValue(1, trackBar6->Name)) {
				trackBar6->Value = trackBar6->Maximum;
			}
			else {
				trackBar6->Value = i.GetValue(1, trackBar6->Name);
			}
			break;
		case 7:
			if (trackBar7->Maximum < i.GetValue(1, trackBar7->Name)) {
				trackBar7->Value = trackBar7->Maximum;
			}
			else {
				trackBar7->Value = i.GetValue(1, trackBar7->Name);
			}
			break;
		case 8:
			if (trackBar8->Maximum < i.GetValue(1, trackBar8->Name)) {
				trackBar8->Value = trackBar8->Maximum;
			}
			else {
				trackBar8->Value = i.GetValue(1, trackBar8->Name);
			}
			break;
		case 9:
			if (trackBar9->Maximum < i.GetValue(1, trackBar9->Name)) {
				trackBar9->Value = trackBar9->Maximum;
			}
			else {
				trackBar9->Value = i.GetValue(1, trackBar9->Name);
			}
			break;
		case 10:
			if (trackBar10->Maximum < i.GetValue(1, trackBar10->Name)) {
				trackBar10->Value = trackBar10->Maximum;
			}
			else {
				trackBar10->Value = i.GetValue(1, trackBar10->Name);
			}
			break;
		}
		break;
	case 4:
		switch (num) {
		case 0:
			if (trackBar0->Maximum < i.GetValue(1, trackBar0->Name)) {
				trackBar0->Value = trackBar0->Maximum;
			}
			else {
				trackBar0->Value = i.GetValue(1, trackBar0->Name);
			}
			break;
		case 1:
			if (trackBar1->Maximum < i.GetValue(1, trackBar1->Name)) {
				trackBar1->Value = trackBar1->Maximum;
			}
			else {
				trackBar1->Value = i.GetValue(1, trackBar1->Name);
			}
			break;
		case 2:
			if (trackBar2->Maximum < i.GetValue(1, trackBar2->Name)) {
				trackBar2->Value = trackBar2->Maximum;
			}
			else {
				trackBar2->Value = i.GetValue(1, trackBar2->Name);
			}
			break;
		case 3:
			if (trackBar3->Maximum < i.GetValue(1, trackBar3->Name)) {
				trackBar3->Value = trackBar3->Maximum;
			}
			else {
				trackBar3->Value = i.GetValue(1, trackBar3->Name);
			}
			break;
		case 4:
			if (trackBar4->Maximum < i.GetValue(1, trackBar4->Name)) {
				trackBar4->Value = trackBar4->Maximum;
			}
			else {
				trackBar4->Value = i.GetValue(1, trackBar4->Name);
			}
			break;
		}
		break;
	case 5:
		if (trackBar0->Maximum < i.GetValue(1, trackBar0->Name)) {
			trackBar0->Value = trackBar0->Maximum;
		}
		else {
			trackBar0->Value = i.GetValue(1, trackBar0->Name);
		}
		break;
	}
}

private:void RePaintChart(String^ ControlName) {
	int num = 0;
	shared_ptr<vector<int>> point;
	shared_ptr<vector<int>> graphpoint;
	for (int i = 0; i < (ControlName->ToCharArray()->Length); i++) {
		char a = ControlName->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			chart0->Series->Clear();
			chart0->Series->Add("GraphPoint");
			chart0->Series->Add("Point");
			chart0->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart0->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart0->Series["GraphPoint"]->Color = Color::LightGray;
			chart0->Series["Point"]->Color = Color::White;
			chart0->Series["GraphPoint"]->BorderWidth = 4;
			chart0->Series["Point"]->MarkerSize = 12;
			chart0->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart0->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));
		
			}
			for (int n = 0; n < point->at(0); n++) {
				chart0->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		case 1:
			chart1->Series->Clear();
			chart1->Series->Add("GraphPoint");
			chart1->Series->Add("Point");
			chart1->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart1->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart1->Series["GraphPoint"]->Color = Color::LightGray;
			chart1->Series["Point"]->Color = Color::White;
			chart1->Series["GraphPoint"]->BorderWidth = 4;
			chart1->Series["Point"]->MarkerSize = 12;
			chart1->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart1->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));	
			}
			for (int n = 0; n < point->at(0); n++) {
				chart1->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		case 2:
			chart2->Series->Clear();
			chart2->Series->Add("GraphPoint");
			chart2->Series->Add("Point");
			chart2->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart2->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart2->Series["GraphPoint"]->Color = Color::LightGray;
			chart2->Series["Point"]->Color = Color::White;
			chart2->Series["GraphPoint"]->BorderWidth = 4;
			chart2->Series["Point"]->MarkerSize = 12;
			chart2->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart2->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));
			}	
			for (int n = 0; n < point->at(0); n++) {
				chart2->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			chart0->Series->Clear();
			chart0->Series->Add("GraphPoint");
			chart0->Series->Add("Point");
			chart0->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart0->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart0->Series["GraphPoint"]->Color = Color::LightGray;
			chart0->Series["Point"]->Color = Color::White;
			chart0->Series["GraphPoint"]->BorderWidth = 4;
			chart0->Series["Point"]->MarkerSize = 12;
			chart0->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart0->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));
		
			}
			for (int n = 0; n < point->at(0); n++) {
				chart0->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		case 1:
			chart1->Series->Clear();
			chart1->Series->Add("GraphPoint");
			chart1->Series->Add("Point");
			chart1->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart1->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart1->Series["GraphPoint"]->Color = Color::LightGray;
			chart1->Series["Point"]->Color = Color::White;
			chart1->Series["GraphPoint"]->BorderWidth = 4;
			chart1->Series["Point"]->MarkerSize = 12;
			chart1->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart1->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));
			}
			for (int n = 0; n < point->at(0); n++) {
				chart1->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		case 2:
			chart2->Series->Clear();
			chart2->Series->Add("GraphPoint");
			chart2->Series->Add("Point");
			chart2->Series["GraphPoint"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			chart2->Series["Point"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			chart2->Series["GraphPoint"]->Color = Color::LightGray;
			chart2->Series["Point"]->Color = Color::White;
			chart2->Series["GraphPoint"]->BorderWidth = 4;
			chart2->Series["Point"]->MarkerSize = 12;
			chart2->Series["Point"]->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			graphpoint = i.RenewGraph(num);
			point = i.GetPoint(num);
			for (int n = 0; n < graphpoint->at(0); n++) {
				chart2->Series["GraphPoint"]->Points->AddXY(graphpoint->at(n + 1), graphpoint->at(graphpoint->at(0) + n + 1));
			}
			for (int n = 0; n < point->at(0); n++) {
				chart2->Series["Point"]->Points->AddXY(point->at(n + 1), point->at(point->at(0) + n + 1));
			}
			break;
		}
		break;
	}
}

private: System::Void chart_Click(System::Object^ sender, System::EventArgs^ e) {
	int num = 0;
	for (int i = 0; i < (((Control^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((Control^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	System::Windows::Forms::DataVisualization::Charting::HitTestResult^ result = ((System::Windows::Forms::DataVisualization::Charting::Chart^)sender)->HitTest(((MouseEventArgs^)e)->X, ((MouseEventArgs^)e)->Y);
	if (result->ChartElementType == System::Windows::Forms::DataVisualization::Charting::ChartElementType::DataPoint) {
		if (result->Series->Name == "Point") {
			switch (i.GetPropNodeType()) {
			case 1:
				switch (num) {
				case 0:
					i.Chart0Point = result->PointIndex;
					break;
				case 1:
					i.Chart1Point = result->PointIndex;
					break;
				case 2:
					i.Chart2Point = result->PointIndex;
					break;
				}
				break;
			case 2:
				switch (num) {
				case 0:
					i.Chart0Point = result->PointIndex;
					break;
				case 1:
					i.Chart1Point = result->PointIndex;
					break;
				case 2:
					i.Chart2Point = result->PointIndex;
					break;
				}
				break;
			}
		}
	}
	switch (i.GetPropNodeType()) {
	case 1:
		switch (num) {
		case 0:
			SetTrackBarValue(trackBar17->Name);
			SetTrackBarValue(trackBar18->Name);
			break;
		case 1:
			SetTrackBarValue(trackBar21->Name);
			SetTrackBarValue(trackBar22->Name);
			break;
		case 2:
			SetTrackBarValue(trackBar23->Name);
			SetTrackBarValue(trackBar24->Name);
			break;
		}
		break;
	case 2:
		switch (num) {
		case 0:
			SetTrackBarValue(trackBar10->Name);
			SetTrackBarValue(trackBar11->Name);
			break;
		case 1:
			SetTrackBarValue(trackBar13->Name);
			SetTrackBarValue(trackBar14->Name);
			break;
		case 2:
			SetTrackBarValue(trackBar15->Name);
			SetTrackBarValue(trackBar16->Name);
			break;
		}
		break;
	}
	nodetotexttrigger();
}			
	   
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			tx = (double)((pictureBox1->Width / 2) - e->X) / (pictureBox1->Width / 2) * 5;
			ty = (double)((pictureBox1->Height / 2) - e->Y) / (pictureBox1->Height / 2) * 5;
			camt();
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			tx = (double)((pictureBox1->Width / 2) - e->X) / (pictureBox1->Width / 2) * 5;
			ty = -(double)((pictureBox1->Height / 2) - e->Y) / (pictureBox1->Height / 2) * 5;
			camr();
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
			tx = (double)((pictureBox1->Width / 2) - e->X) / (pictureBox1->Width / 2) * 5;
			ty = (double)((pictureBox1->Height / 2) - e->Y) / (pictureBox1->Height / 2) * 5;
			camt();
		}
	}
	private: System::Void pictureBox1_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		tx = e->Delta / 10.0;
		camf();
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		tx = 0;
		ty = 0;
		camt();
	}
		   




/*
■■■■■■■■■■■                        ■■■■■■■■■■■■■■                                                                        
■■■■■■■■■■■                         ■■■■■■■■■■■■■                              ■■                                        
■■                                       ■■                                    ■■                                        
■■                                       ■■                                    ■■                                        
■■                                       ■■                                    ■■                                        
■■               ■■■■       ■■  ■■■      ■■           ■■■■      ■■       ■■  ■■■■■■■   ■■      ■■    ■■  ■■■     ■■■■    
■■             ■■■■■■■■     ■■ ■■■■      ■■         ■■■■■■■■     ■■     ■■   ■■■■■■■   ■■      ■■    ■■ ■■■■   ■■■■■■■■  
■■            ■■■    ■■■    ■■■          ■■        ■■■    ■■■    ■■■   ■■      ■■      ■■      ■■    ■■■      ■■■    ■■■ 
■■■■■■■■■■    ■■      ■■    ■■           ■■        ■■      ■■     ■■  ■■■      ■■      ■■      ■■    ■■       ■■      ■■ 
■■■■■■■■■■   ■■        ■■   ■■           ■■       ■■       ■■      ■■ ■■       ■■      ■■      ■■    ■■      ■■       ■■ 
■■           ■■        ■■   ■■           ■■       ■■■      ■■■      ■■■        ■■      ■■      ■■    ■■      ■■■      ■■■
■■           ■■        ■■   ■■           ■■       ■■■■■■■■■■■■      ■■■        ■■      ■■      ■■    ■■      ■■■■■■■■■■■■
■■           ■■        ■■   ■■           ■■       ■■                ■■■        ■■      ■■      ■■    ■■      ■■          
■■           ■■        ■■   ■■           ■■       ■■               ■■ ■■       ■■      ■■      ■■    ■■      ■■          
■■            ■■      ■■    ■■           ■■        ■■      ■      ■■   ■■      ■■      ■■      ■■    ■■       ■■      ■  
■■            ■■■    ■■■    ■■           ■■        ■■■    ■■■    ■■■   ■■      ■■      ■■■    ■■■    ■■       ■■■    ■■■ 
■■             ■■■■■■■■     ■■           ■■         ■■■■■■■■     ■■     ■■     ■■■■     ■■■■■■ ■■    ■■        ■■■■■■■■  
■■               ■■■■       ■■           ■■           ■■■■■     ■■       ■■     ■■■■     ■■■■  ■■    ■■          ■■■■■   

*/









/*
                                                                                                                         ■■  
■■■■■■■■■■■                          ■■■          ■■■                                                 ■■                 ■■  
■■■■■■■■■■■                          ■■■■         ■■■                  ■■                             ■■                 ■■  
■■                                   ■■■■        ■■■■                  ■■                                                ■■  
■■                                   ■■■■■       ■■■■                  ■■                                                ■■  
■■                                   ■■ ■■      ■■ ■■                  ■■                                                ■■  
■■               ■■■■       ■■  ■■■  ■■  ■■    ■■■ ■■      ■■■■■     ■■■■■■■      ■■■■       ■■  ■■■  ■■      ■■■■■      ■■  
■■             ■■■■■■■■     ■■ ■■■■  ■■  ■■■   ■■  ■■    ■■■■■■■■    ■■■■■■■    ■■■■■■■■     ■■ ■■■■  ■■    ■■■■■■■■     ■■  
■■            ■■■    ■■■    ■■■      ■■   ■■  ■■■  ■■    ■■    ■■■     ■■      ■■■    ■■■    ■■■      ■■    ■■    ■■■    ■■  
■■■■■■■■■■    ■■      ■■    ■■       ■■   ■■■ ■■   ■■           ■■     ■■      ■■      ■■    ■■       ■■           ■■    ■■  
■■■■■■■■■■   ■■        ■■   ■■       ■■    ■■■■    ■■           ■■     ■■     ■■       ■■    ■■       ■■           ■■    ■■  
■■           ■■        ■■   ■■       ■■    ■■■■    ■■           ■■     ■■     ■■■      ■■■   ■■       ■■           ■■    ■■  
■■           ■■        ■■   ■■       ■■     ■■     ■■     ■■■■■■■■     ■■     ■■■■■■■■■■■■   ■■       ■■     ■■■■■■■■    ■■  
■■           ■■        ■■   ■■       ■■      ■     ■■    ■■     ■■     ■■     ■■             ■■       ■■    ■■     ■■    ■■  
■■           ■■        ■■   ■■       ■■            ■■   ■■      ■■     ■■     ■■             ■■       ■■   ■■      ■■    ■■  
■■            ■■      ■■    ■■       ■■            ■■   ■■      ■■     ■■      ■■      ■     ■■       ■■   ■■      ■■    ■■  
■■            ■■■    ■■■    ■■       ■■            ■■   ■■■    ■■■     ■■      ■■■    ■■■    ■■       ■■   ■■■    ■■■    ■■  
■■             ■■■■■■■■     ■■       ■■            ■■    ■■■■■■■ ■■■   ■■■■     ■■■■■■■■     ■■       ■■    ■■■■■■■ ■■■  ■■■■
■■               ■■■■       ■■       ■■            ■■     ■■■■■  ■■■    ■■■■      ■■■■■      ■■       ■■     ■■■■■  ■■■   ■■■
*/












/*
■■■■■■■■■■■                        ■■■■■■■■■■■■■■                     ■■               
■■■■■■■■■■■                         ■■■■■■■■■■■■■                     ■■               
■■                                       ■■                                            
■■                                       ■■                                         ■■ 
■■                                       ■■                                        ■■■■
■■               ■■■■       ■■  ■■■      ■■       ■■      ■■     ■■   ■■      ■■■■■■   
■■             ■■■■■■■■     ■■ ■■■■      ■■       ■■     ■■■     ■■   ■■     ■■■■■■■■  
■■            ■■■    ■■■    ■■■          ■■       ■■     ■■■     ■■   ■■    ■■     ■■  
■■■■■■■■■■    ■■      ■■    ■■           ■■        ■■    ■■■■    ■■   ■■    ■■     ■■  
■■■■■■■■■■   ■■        ■■   ■■           ■■        ■■   ■■ ■■   ■■    ■■    ■■     ■■■ 
■■           ■■        ■■   ■■           ■■        ■■   ■■ ■■   ■■    ■■    ■■     ■■  
■■           ■■        ■■   ■■           ■■        ■■   ■■  ■■  ■■    ■■    ■■     ■■  
■■           ■■        ■■   ■■           ■■         ■■  ■   ■■  ■■    ■■     ■■■■■■■   
■■           ■■        ■■   ■■           ■■         ■■ ■■   ■■ ■■     ■■      ■■■■■    
■■            ■■      ■■    ■■           ■■         ■■ ■■    ■ ■■     ■■     ■         
■■            ■■■    ■■■    ■■           ■■          ■■■     ■■■■     ■■    ■■         
■■             ■■■■■■■■     ■■           ■■          ■■■     ■■■      ■■    ■■■■■■■■■  
■■               ■■■■       ■■           ■■          ■■■     ■■■      ■■     ■■■■■■■■■ 
                                                                            ■■      ■■■
                                                                           ■■        ■■
                                                                           ■■        ■■
                                                                           ■■        ■■
                                                                            ■■■■■■■■■■ 
                                                                             ■■■■■■■   
*/














/*
■■■■■■■■■■■                              ■■■■■■                                                                                                     
■■■■■■■■■■■                            ■■■■■■■■■                                                                       ■■                           
■■                                    ■■■     ■■■                                                                      ■■                           
■■                                    ■■        ■■                                                                     ■■                           
■■                                   ■■■        ■                                                                      ■■                           
■■               ■■■■       ■■  ■■■  ■■                  ■■■■       ■■  ■■■■         ■■■■       ■■  ■■■    ■■■■■     ■■■■■■■      ■■■■       ■■  ■■■
■■             ■■■■■■■■     ■■ ■■■■  ■■                ■■■■■■■■     ■■ ■■■■■■      ■■■■■■■■     ■■ ■■■■  ■■■■■■■■    ■■■■■■■    ■■■■■■■■     ■■ ■■■■
■■            ■■■    ■■■    ■■■      ■■               ■■■    ■■■    ■■■    ■■■    ■■■    ■■■    ■■■      ■■    ■■■     ■■      ■■■    ■■■    ■■■    
■■■■■■■■■■    ■■      ■■    ■■      ■■■               ■■      ■■    ■■      ■■    ■■      ■■    ■■              ■■     ■■      ■■      ■■    ■■     
■■■■■■■■■■   ■■        ■■   ■■      ■■■      ■■■■■■  ■■       ■■    ■■      ■■   ■■       ■■    ■■              ■■     ■■     ■■        ■■   ■■     
■■           ■■        ■■   ■■      ■■■      ■■■■■■  ■■■      ■■■   ■■      ■■   ■■■      ■■■   ■■              ■■     ■■     ■■        ■■   ■■     
■■           ■■        ■■   ■■       ■■          ■■  ■■■■■■■■■■■■   ■■      ■■   ■■■■■■■■■■■■   ■■        ■■■■■■■■     ■■     ■■        ■■   ■■     
■■           ■■        ■■   ■■       ■■          ■■  ■■             ■■      ■■   ■■             ■■       ■■     ■■     ■■     ■■        ■■   ■■     
■■           ■■        ■■   ■■       ■■         ■■■  ■■             ■■      ■■   ■■             ■■      ■■      ■■     ■■     ■■        ■■   ■■     
■■            ■■      ■■    ■■        ■■        ■■■   ■■      ■     ■■      ■■    ■■      ■     ■■      ■■      ■■     ■■      ■■      ■■    ■■     
■■            ■■■    ■■■    ■■        ■■■      ■■■■   ■■■    ■■■    ■■      ■■    ■■■    ■■■    ■■      ■■■    ■■■     ■■      ■■■    ■■■    ■■     
■■             ■■■■■■■■     ■■         ■■■■■■■■■ ■■    ■■■■■■■■     ■■      ■■     ■■■■■■■■     ■■       ■■■■■■■ ■■■   ■■■■     ■■■■■■■■     ■■     
■■               ■■■■       ■■           ■■■■■   ■■      ■■■■■      ■■      ■■       ■■■■■      ■■        ■■■■■  ■■■    ■■■■      ■■■■       ■■     
*/



private: System::Void listViewD1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listViewD1->SelectedItems->Count != 0) {
		switch (listViewD1->SelectedItems[0]->Name->ToCharArray()[0]) {
		case 'O':
			gn.listItemType = 0;
			break;
		case 'T':
			gn.listItemType = 1;
			break;
		}
		gn.SetListItemPointer(listViewD1->SelectedItems[0]->Name);
		gn.ScrollX = 0;
		gn.ScrollY = 0;
		ResetTableLayoutPanelD();
	}
}

private:void ResetTableLayoutPanelD() {
	tableLayoutPanelD->SuspendLayout();
	for (int i = 0; i < tableLayoutPanelD->RowCount; i++) {
		for (int s = 0; s < tableLayoutPanelD->ColumnCount; s++) {
			tableLayoutPanelD->Controls->Remove(tableLayoutPanelD->GetControlFromPosition(s, i));
		}
	}
	tableLayoutPanelD->ColumnCount = 0;
	tableLayoutPanelD->RowCount = 0;
	tableLayoutPanelD->AutoScrollPosition = Point(0, 0);
	tableLayoutPanelD->SetColumnSpan(labelD0, 1);
	tableLayoutPanelD->SetColumnSpan(labelD1, 1);
	tableLayoutPanelD->SetColumnSpan(labelD2, 1);
	tableLayoutPanelD->SetColumnSpan(labelD3, 1);
	tableLayoutPanelD->SetColumnSpan(labelD4, 1);
	tableLayoutPanelD->SetColumnSpan(labelD5, 1);
	tableLayoutPanelD->SetColumnSpan(labelD6, 1);
	tableLayoutPanelD->SetColumnSpan(labelD7, 1);
	tableLayoutPanelD->SetColumnSpan(labelD8, 1);
	tableLayoutPanelD->SetColumnSpan(labelD9, 1);
	tableLayoutPanelD->SetColumnSpan(labelD10, 1);
	tableLayoutPanelD->SetColumnSpan(labelD11, 1);
	tableLayoutPanelD->SetColumnSpan(labelD12, 1);
	tableLayoutPanelD->SetColumnSpan(labelD13, 1);
	tableLayoutPanelD->SetColumnSpan(labelD14, 1);
	tableLayoutPanelD->SetColumnSpan(comboBoxD0, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD0, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD1, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD2, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD3, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD4, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD5, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD6, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD7, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD8, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD9, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD10, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD11, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD12, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD13, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD14, 1);
	tableLayoutPanelD->SetColumnSpan(textBoxD15, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD0, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD1, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD2, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD3, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD4, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD5, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD6, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD7, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD8, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD9, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD10, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD11, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD12, 1);
	tableLayoutPanelD->SetColumnSpan(trackBarD13, 1);
	tableLayoutPanelD->SetColumnSpan(buttonD0, 1);
	tableLayoutPanelD->SetColumnSpan(buttonD1, 1);

	tableLayoutPanelD->SetRowSpan(labelD0, 1);
	tableLayoutPanelD->SetRowSpan(labelD1, 1);
	tableLayoutPanelD->SetRowSpan(labelD2, 1);
	tableLayoutPanelD->SetRowSpan(labelD3, 1);
	tableLayoutPanelD->SetRowSpan(labelD4, 1);
	tableLayoutPanelD->SetRowSpan(labelD5, 1);
	tableLayoutPanelD->SetRowSpan(labelD6, 1);
	tableLayoutPanelD->SetRowSpan(labelD7, 1);
	tableLayoutPanelD->SetRowSpan(labelD8, 1);
	tableLayoutPanelD->SetRowSpan(labelD9, 1);
	tableLayoutPanelD->SetRowSpan(labelD10, 1);
	tableLayoutPanelD->SetRowSpan(labelD11, 1);
	tableLayoutPanelD->SetRowSpan(labelD12, 1);
	tableLayoutPanelD->SetRowSpan(labelD13, 1);
	tableLayoutPanelD->SetRowSpan(labelD14, 1);
	tableLayoutPanelD->SetRowSpan(comboBoxD0, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD0, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD1, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD2, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD3, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD4, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD5, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD6, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD7, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD8, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD9, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD10, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD11, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD12, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD13, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD14, 1);
	tableLayoutPanelD->SetRowSpan(textBoxD15, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD0, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD1, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD2, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD3, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD4, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD5, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD6, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD7, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD8, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD9, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD10, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD11, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD12, 1);
	tableLayoutPanelD->SetRowSpan(trackBarD13, 1);
	tableLayoutPanelD->SetRowSpan(buttonD0, 1);
	tableLayoutPanelD->SetRowSpan(buttonD1, 1);
	trackBarD0->Orientation = Orientation::Horizontal;
	trackBarD1->Orientation = Orientation::Horizontal;
	trackBarD2->Orientation = Orientation::Horizontal;
	trackBarD3->Orientation = Orientation::Horizontal;
	trackBarD4->Orientation = Orientation::Horizontal;
	trackBarD5->Orientation = Orientation::Horizontal;
	trackBarD6->Orientation = Orientation::Horizontal;
	trackBarD7->Orientation = Orientation::Horizontal;
	trackBarD8->Orientation = Orientation::Horizontal;
	trackBarD9->Orientation = Orientation::Horizontal;
	trackBarD10->Orientation = Orientation::Horizontal;
	trackBarD11->Orientation = Orientation::Horizontal;
	trackBarD12->Orientation = Orientation::Horizontal;
	trackBarD13->Orientation = Orientation::Horizontal;

	switch (gn.listItemType) {
	case 0:
		switch (gn.listItemWGType()) {
		case 0:
			SetDOLPropertyPanel();
			break;
		case 1:
			SetDOBPropertyPanel();
			break;
		case 2:
			SetDOLBPropertyPanel();
			break;
		}
		break;
	case 1:
		switch (gn.listItemWGType()) {
		case 0:
			SetDTFAPropertyPanel();
			break;
		case 1:
			SetDTSAPropertyPanel();
			break;
		case 2:
			SetDTFSPropertyPanel();
			break;
		}
		break;
	default:
		break;
	}
	tableLayoutPanelD->ResumeLayout(true);
}

private:void SetDOLPropertyPanel() {
}

private:void SetDOBPropertyPanel() {
}

private:void SetDOLBPropertyPanel() {
}

private:void SetDTFAPropertyPanel() {
}

private:void SetDTSAPropertyPanel() {
}

private:void SetDTFSPropertyPanel() {
	labelD0->Text = "GenType";
	labelD1->Text = "Repeat";
	labelD2->Text = "BirthX";
	labelD3->Text = "BirthY";
	labelD4->Text = "BirthZ";
	labelD5->Text = "ZMax";
	labelD6->Text = "previewRX";
	labelD7->Text = "previewRY";
	labelD8->Text = "previewRZ";
	labelD9->Text = "GoLength";
	labelD10->Text = "Rotation";
	labelD11->Text = "Radius";
	labelD12->Text = "Type";
	labelD13->Text = "FractalRatio";
	labelD14->Text = "ManualInput";

	labelD0->ForeColor = Color::White;
	labelD1->ForeColor = Color::White;
	labelD2->ForeColor = Color::White;
	labelD3->ForeColor = Color::White;
	labelD4->ForeColor = Color::White;
	labelD5->ForeColor = Color::White;
	labelD6->ForeColor = Color::White;
	labelD7->ForeColor = Color::White;
	labelD8->ForeColor = Color::White;
	labelD9->ForeColor = Color::White;
	labelD10->ForeColor = Color::White;
	labelD11->ForeColor = Color::White;
	labelD12->ForeColor = Color::White;
	labelD13->ForeColor = Color::White;
	labelD14->ForeColor = Color::White;

	labelD0->Dock = DockStyle::Bottom;
	labelD1->Dock = DockStyle::Bottom;
	labelD2->Dock = DockStyle::Bottom;
	labelD3->Dock = DockStyle::Bottom;
	labelD4->Dock = DockStyle::Bottom;
	labelD5->Dock = DockStyle::Bottom;
	labelD6->Dock = DockStyle::Bottom;
	labelD7->Dock = DockStyle::Bottom;
	labelD8->Dock = DockStyle::Bottom;
	labelD9->Dock = DockStyle::Bottom;
	labelD10->Dock = DockStyle::Bottom;
	labelD11->Dock = DockStyle::Bottom;
	labelD12->Dock = DockStyle::Bottom;
	labelD13->Dock = DockStyle::Bottom;
	labelD14->Dock = DockStyle::Bottom;

	comboBoxD0->Name = "0";
	comboBoxD0->Dock = DockStyle::Bottom;
	comboBoxD0->DropDownStyle = ComboBoxStyle::DropDownList;
	comboBoxD0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	comboBoxD0->Leave += gcnew System::EventHandler(this, &MyForm::comboBoxD_TextChanged);
	comboBoxD0->Items->Clear();
	comboBoxD0->Items->Add("FA");
	comboBoxD0->Items->Add("SA");
	comboBoxD0->Items->Add("FS");
	comboBoxD0->SelectedIndex =2;

	textBoxD0->Name = "0";
	textBoxD1->Name = "1";
	textBoxD2->Name = "2";
	textBoxD3->Name = "3";
	textBoxD4->Name = "4";
	textBoxD5->Name = "5";
	textBoxD6->Name = "6";
	textBoxD7->Name = "7";
	textBoxD8->Name = "8";
	textBoxD9->Name = "9";
	textBoxD10->Name = "10";
	textBoxD11->Name = "11";
	textBoxD12->Name = "12";
	textBoxD13->Name = "13";
	textBoxD14->Name = "14";
	textBoxD15->Name = "15";

	textBoxD0->Dock = DockStyle::Bottom;
	textBoxD1->Dock = DockStyle::Bottom;
	textBoxD2->Dock = DockStyle::Bottom;
	textBoxD3->Dock = DockStyle::Bottom;
	textBoxD4->Dock = DockStyle::Bottom;
	textBoxD5->Dock = DockStyle::Bottom;
	textBoxD6->Dock = DockStyle::Bottom;
	textBoxD7->Dock = DockStyle::Bottom;
	textBoxD8->Dock = DockStyle::Bottom;
	textBoxD9->Dock = DockStyle::Bottom;
	textBoxD10->Dock = DockStyle::Bottom;
	textBoxD11->Dock = DockStyle::Bottom;
	textBoxD12->Dock = DockStyle::Bottom;
	textBoxD13->Dock = DockStyle::Bottom;
	textBoxD14->Dock = DockStyle::Bottom;
	textBoxD15->Dock = DockStyle::Bottom;

	textBoxD0->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD7->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD8->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD9->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD10->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD11->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD12->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD13->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD14->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);
	textBoxD15->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox_KeyPress);

	textBoxD0->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD1->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD2->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD3->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD4->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD5->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD6->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD7->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD8->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD9->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD10->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD11->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD12->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD13->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD14->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);
	textBoxD15->Leave += gcnew System::EventHandler(this, &MyForm::textBoxD_TextChanged);

	textBoxD0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD11->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD12->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD13->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD14->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	textBoxD15->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);

	textBoxD1->Text = gn.GetValue(1, textBoxD1->Name).ToString();
	textBoxD3->Text = gn.GetValue(1, textBoxD3->Name).ToString();
	textBoxD4->Text = gn.GetValue(1, textBoxD4->Name).ToString();
	textBoxD5->Text = gn.GetValue(1, textBoxD5->Name).ToString();
	textBoxD6->Text = gn.GetValue(1, textBoxD6->Name).ToString();
	textBoxD7->Text = gn.GetValue(1, textBoxD7->Name).ToString();
	textBoxD8->Text = gn.GetValue(1, textBoxD8->Name).ToString();
	textBoxD9->Text = gn.GetValue(1, textBoxD9->Name).ToString();
	textBoxD10->Text = gn.GetValue(1, textBoxD10->Name).ToString();
	textBoxD11->Text = gn.GetValue(1, textBoxD11->Name).ToString();
	textBoxD12->Text = gn.GetValue(1, textBoxD12->Name).ToString();
	textBoxD13->Text = gn.GetValue(1, textBoxD13->Name).ToString();
	textBoxD14->Text = gn.GetValue(1, textBoxD14->Name).ToString();
	textBoxD15->Text = gn.GetValue(1, textBoxD15->Name).ToString();

	textBoxD0->Text = gn.GetString(textBoxD0->Name);
	textBoxD2->Text = gn.GetString(textBoxD2->Name);

	trackBarD0->Name = "1";
	trackBarD1->Name = "3";
	trackBarD2->Name = "4";
	trackBarD3->Name = "5";
	trackBarD4->Name = "6";
	trackBarD5->Name = "7";
	trackBarD6->Name = "8";
	trackBarD7->Name = "9";
	trackBarD8->Name = "10";
	trackBarD9->Name = "11";
	trackBarD10->Name = "12";
	trackBarD11->Name = "13";
	trackBarD12->Name = "14";
	trackBarD13->Name = "15";

	trackBarD0->Dock = DockStyle::Bottom;
	trackBarD1->Dock = DockStyle::Bottom;
	trackBarD2->Dock = DockStyle::Bottom;
	trackBarD3->Dock = DockStyle::Bottom;
	trackBarD4->Dock = DockStyle::Bottom;
	trackBarD5->Dock = DockStyle::Bottom;
	trackBarD6->Dock = DockStyle::Bottom;
	trackBarD7->Dock = DockStyle::Bottom;
	trackBarD8->Dock = DockStyle::Bottom;
	trackBarD9->Dock = DockStyle::Bottom;
	trackBarD10->Dock = DockStyle::Bottom;
	trackBarD11->Dock = DockStyle::Bottom;
	trackBarD12->Dock = DockStyle::Bottom;
	trackBarD13->Dock = DockStyle::Bottom;

	trackBarD0->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD10->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD11->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD12->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);
	trackBarD13->Scroll += gcnew System::EventHandler(this, &MyForm::trackBarD_Scroll);

	trackBarD0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD2->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD3->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD4->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD5->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD6->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD7->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD8->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD9->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD10->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD11->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD12->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	trackBarD13->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);

	trackBarD0->Minimum = 0;
	trackBarD1->Minimum = -2000;
	trackBarD2->Minimum = -2000;
	trackBarD3->Minimum = -2000;
	trackBarD4->Minimum = -2000;
	trackBarD5->Minimum = -2000;
	trackBarD6->Minimum = -2000;
	trackBarD7->Minimum = -2000;
	trackBarD8->Minimum = -1000;
	trackBarD9->Minimum = -1000;
	trackBarD10->Minimum = -1000;
	trackBarD11->Minimum = 0;
	trackBarD12->Minimum = -1000;
	trackBarD13->Minimum = 0;

	trackBarD0->Maximum = 10;
	trackBarD1->Maximum = 2000;
	trackBarD2->Maximum = 2000;
	trackBarD3->Maximum = 2000;
	trackBarD4->Maximum = 2000;
	trackBarD5->Maximum = 2000;
	trackBarD6->Maximum = 2000;
	trackBarD7->Maximum = 2000;
	trackBarD8->Maximum = 1000;
	trackBarD9->Maximum = 1000;
	trackBarD10->Maximum = 1000;
	trackBarD11->Maximum = 9;
	trackBarD12->Maximum = 1000;
	trackBarD13->Maximum = 1;

	trackBarD0->TickFrequency = 1;
	trackBarD1->TickFrequency = 200;
	trackBarD2->TickFrequency = 200;
	trackBarD3->TickFrequency = 200;
	trackBarD4->TickFrequency = 200;
	trackBarD5->TickFrequency = 200;
	trackBarD6->TickFrequency = 200;
	trackBarD7->TickFrequency = 200;
	trackBarD8->TickFrequency = 100;
	trackBarD9->TickFrequency = 100;
	trackBarD10->TickFrequency = 100;
	trackBarD11->TickFrequency = 1;
	trackBarD12->TickFrequency = 100;
	trackBarD13->TickFrequency = 1;

	trackBarD0->Value = ValueBind(gn.GetValue(1,trackBarD0->Name),  trackBarD0->Minimum, trackBarD0->Maximum);
	trackBarD1->Value = ValueBind(gn.GetValue(1, trackBarD1->Name), trackBarD1->Minimum, trackBarD1->Maximum);
	trackBarD2->Value = ValueBind(gn.GetValue(1, trackBarD2->Name), trackBarD2->Minimum, trackBarD2->Maximum);
	trackBarD3->Value = ValueBind(gn.GetValue(1, trackBarD3->Name), trackBarD3->Minimum, trackBarD3->Maximum);
	trackBarD4->Value = ValueBind(gn.GetValue(1, trackBarD4->Name), trackBarD4->Minimum, trackBarD4->Maximum);
	trackBarD5->Value = ValueBind(gn.GetValue(1, trackBarD5->Name), trackBarD5->Minimum, trackBarD5->Maximum);
	trackBarD6->Value = ValueBind(gn.GetValue(1, trackBarD6->Name), trackBarD6->Minimum, trackBarD6->Maximum);
	trackBarD7->Value = ValueBind(gn.GetValue(1, trackBarD7->Name), trackBarD7->Minimum, trackBarD7->Maximum);
	trackBarD8->Value = ValueBind(gn.GetValue(1, trackBarD8->Name), trackBarD8->Minimum, trackBarD8->Maximum);
	trackBarD9->Value = ValueBind(gn.GetValue(1, trackBarD9->Name), trackBarD9->Minimum, trackBarD9->Maximum);
	trackBarD10->Value = ValueBind(gn.GetValue(1, trackBarD10->Name), trackBarD10->Minimum, trackBarD10->Maximum);
	trackBarD11->Value = ValueBind(gn.GetValue(1, trackBarD11->Name), trackBarD11->Minimum, trackBarD11->Maximum);
	trackBarD12->Value = ValueBind(gn.GetValue(1, trackBarD12->Name), trackBarD12->Minimum, trackBarD12->Maximum);
	trackBarD13->Value = ValueBind(gn.GetValue(1, trackBarD13->Name), trackBarD13->Minimum, trackBarD13->Maximum);

	buttonD0->Name = "0";
	buttonD1->Name = "1";

	buttonD0->Text = "出力";
	buttonD1->Text = "インポート";

	buttonD0->ForeColor = Color::White;
	buttonD1->ForeColor = Color::White;

	buttonD0->FlatStyle = FlatStyle::Flat;
	buttonD1->FlatStyle = FlatStyle::Flat;

	buttonD0->Dock = DockStyle::Bottom;
	buttonD1->Dock = DockStyle::Bottom;

	buttonD0->Click += gcnew System::EventHandler(this, &MyForm::buttonD_Click);
	buttonD1->Click += gcnew System::EventHandler(this, &MyForm::buttonD_Click);

	buttonD0->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);
	buttonD1->GotFocus += gcnew System::EventHandler(this, &MyForm::tableLayoutPanelControlD_GotFocus);

	tableLayoutPanelD->ColumnCount = 20;
	tableLayoutPanelD->RowCount = 20;
	for (int i = 0; i < 20; i++) {
		tableLayoutPanelD->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
	}
	for (int i = 0; i < 20; i++) {
		tableLayoutPanelD->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
	}

	tableLayoutPanelD->Controls->Add(labelD0, 1, 0);
	tableLayoutPanelD->Controls->Add(labelD1, 1, 2);
	tableLayoutPanelD->Controls->Add(labelD2, 1, 4);
	tableLayoutPanelD->Controls->Add(labelD3, 1, 5);
	tableLayoutPanelD->Controls->Add(labelD4, 1, 6);
	tableLayoutPanelD->Controls->Add(labelD5, 1, 7);
	tableLayoutPanelD->Controls->Add(labelD6, 1, 8);
	tableLayoutPanelD->Controls->Add(labelD7, 1, 9);
	tableLayoutPanelD->Controls->Add(labelD8, 1, 10);
	tableLayoutPanelD->Controls->Add(labelD9, 1, 11);
	tableLayoutPanelD->Controls->Add(labelD10, 1, 12);
	tableLayoutPanelD->Controls->Add(labelD11, 1, 13);
	tableLayoutPanelD->Controls->Add(labelD12, 1, 14);
	tableLayoutPanelD->Controls->Add(labelD13, 1, 15);
	tableLayoutPanelD->Controls->Add(labelD14, 1, 18);

	tableLayoutPanelD->Controls->Add(comboBoxD0, 7, 0);

	tableLayoutPanelD->Controls->Add(textBoxD0, 1, 1);
	tableLayoutPanelD->Controls->Add(textBoxD1, 16, 2);
	tableLayoutPanelD->Controls->Add(textBoxD2, 1, 3);
	tableLayoutPanelD->Controls->Add(textBoxD3, 16, 4);
	tableLayoutPanelD->Controls->Add(textBoxD4, 16, 5);
	tableLayoutPanelD->Controls->Add(textBoxD5, 16, 6);
	tableLayoutPanelD->Controls->Add(textBoxD6, 16, 7);
	tableLayoutPanelD->Controls->Add(textBoxD7, 16, 8);
	tableLayoutPanelD->Controls->Add(textBoxD8, 16, 9);
	tableLayoutPanelD->Controls->Add(textBoxD9, 16, 10);
	tableLayoutPanelD->Controls->Add(textBoxD10, 16, 11);
	tableLayoutPanelD->Controls->Add(textBoxD11, 16, 12);
	tableLayoutPanelD->Controls->Add(textBoxD12, 16, 13);
	tableLayoutPanelD->Controls->Add(textBoxD13, 16, 14);
	tableLayoutPanelD->Controls->Add(textBoxD14, 16, 15);
	tableLayoutPanelD->Controls->Add(textBoxD15, 16, 18);

	tableLayoutPanelD->Controls->Add(trackBarD0, 7, 2);
	tableLayoutPanelD->Controls->Add(trackBarD1, 7, 4);
	tableLayoutPanelD->Controls->Add(trackBarD2, 7, 5);
	tableLayoutPanelD->Controls->Add(trackBarD3, 7, 6);
	tableLayoutPanelD->Controls->Add(trackBarD4, 7, 7);
	tableLayoutPanelD->Controls->Add(trackBarD5, 7, 8);
	tableLayoutPanelD->Controls->Add(trackBarD6, 7, 9);
	tableLayoutPanelD->Controls->Add(trackBarD7, 7, 10);
	tableLayoutPanelD->Controls->Add(trackBarD8, 7, 11);
	tableLayoutPanelD->Controls->Add(trackBarD9, 7, 12);
	tableLayoutPanelD->Controls->Add(trackBarD10, 7, 13);
	tableLayoutPanelD->Controls->Add(trackBarD11, 7, 14);
	tableLayoutPanelD->Controls->Add(trackBarD12, 7, 15);
	tableLayoutPanelD->Controls->Add(trackBarD13, 7, 18);

	tableLayoutPanelD->Controls->Add(buttonD0, 7, 16);
	tableLayoutPanelD->Controls->Add(buttonD1, 7, 17);

	tableLayoutPanelD->SetColumnSpan(labelD0, 5);
	tableLayoutPanelD->SetColumnSpan(labelD1, 5);
	tableLayoutPanelD->SetColumnSpan(labelD2, 5);
	tableLayoutPanelD->SetColumnSpan(labelD3, 5);
	tableLayoutPanelD->SetColumnSpan(labelD4, 5);
	tableLayoutPanelD->SetColumnSpan(labelD5, 5);
	tableLayoutPanelD->SetColumnSpan(labelD6, 5);
	tableLayoutPanelD->SetColumnSpan(labelD7, 5);
	tableLayoutPanelD->SetColumnSpan(labelD8, 5);
	tableLayoutPanelD->SetColumnSpan(labelD9, 5);
	tableLayoutPanelD->SetColumnSpan(labelD10, 5);
	tableLayoutPanelD->SetColumnSpan(labelD11, 5);
	tableLayoutPanelD->SetColumnSpan(labelD12, 5);
	tableLayoutPanelD->SetColumnSpan(labelD13, 5);
	tableLayoutPanelD->SetColumnSpan(labelD14, 5);

	tableLayoutPanelD->SetColumnSpan(comboBoxD0, 12);

	tableLayoutPanelD->SetColumnSpan(textBoxD0, 18);
	tableLayoutPanelD->SetColumnSpan(textBoxD1, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD2, 18);
	tableLayoutPanelD->SetColumnSpan(textBoxD3, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD4, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD5, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD6, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD7, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD8, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD9, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD10, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD11, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD12, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD13, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD14, 3);
	tableLayoutPanelD->SetColumnSpan(textBoxD15, 3);

	tableLayoutPanelD->SetColumnSpan(trackBarD0, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD1, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD2, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD3, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD4, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD5, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD6, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD7, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD8, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD9, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD10, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD11, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD12, 8);
	tableLayoutPanelD->SetColumnSpan(trackBarD13, 8);

	tableLayoutPanelD->SetColumnSpan(buttonD0, 8);
	tableLayoutPanelD->SetColumnSpan(buttonD1, 8);
}

 private: System::Void AddObject(System::Object^ sender, System::EventArgs^ e) {
	 gn.ObjectCreate();
	 ListViewItem^ item = gcnew ListViewItem();
	 item->Text = "O";
	 item->Name = "O" + gn.ObjectNum.ToString();
	 gn.ObjectNum += 1;
	 listViewD1->Items->Add(item);
 }

private: System::Void AddTree(System::Object^ sender, System::EventArgs^ e) {
	gn.TreeCreate();
	ListViewItem^ item = gcnew ListViewItem();
	item->Text = "T";
	item->Name = "T" + gn.TreeNum.ToString();
	gn.TreeNum += 1;
	listViewD1->Items->Add(item);
}

private: System::Void DuplicateObjTre(System::Object^ sender, System::EventArgs^ e) {
	if (listViewD1->SelectedItems->Count != 0) {
		gn.ItemDuplicate(listViewD1->SelectedItems[0]->Name);
		ListViewItem^ item = gcnew ListViewItem();
		switch (gn.listItemType) {
		case 0:
			item->Text = "O";
			item->Name = "O" + gn.ObjectNum.ToString();
			gn.ObjectNum += 1;
			listViewD1->Items->Add(item);
			break;
		case 1:
			item->Text = "T";
			item->Name = "T" + gn.TreeNum.ToString();
			gn.TreeNum += 1;
			listViewD1->Items->Add(item);
			break;
		}
	}
}

private: System::Void DeleteObjTre(System::Object^ sender, System::EventArgs^ e) {
	if (listViewD1->SelectedItems->Count != 0) {
		gn.ItemDelete(listViewD1->SelectedItems[0]->Name);
		listViewD1->SelectedItems[0]->Remove();
	}
}

private: System::Void tableLayoutPanelD_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	gn.ScrollX = -tableLayoutPanelD->AutoScrollPosition.X;
	gn.ScrollY = -tableLayoutPanelD->AutoScrollPosition.Y;
}

private: System::Void tableLayoutPanelD_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	gn.ScrollX = -tableLayoutPanelD->AutoScrollPosition.X;
	gn.ScrollY = -tableLayoutPanelD->AutoScrollPosition.Y;
}

private: System::Void tableLayoutPanelControlD_GotFocus(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanelD->AutoScrollPosition = Point(gn.ScrollX, gn.ScrollY);
	tableLayoutPanelD->ResumeLayout(true);
}

private: System::Void comboBoxD_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	gn.SetComboBoxValue(((ComboBox^)sender)->SelectedIndex, ((Control^)sender)->Name);
}

private: System::Void textBoxD_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		   int num = 0;
		   int value = 0;
		   int min = -16777216;
		   int max = 16777216;
		   string ControlText = "";
		   for (int i = 0; i < (((TextBox^)sender)->Name->ToCharArray()->Length); i++) {
			   char a = ((TextBox^)sender)->Name->ToCharArray()[i];
			   num = num * 10 + a - '0';//char'0'=int 48
		   }
		   for (int i = 0; i < ((TextBox^)sender)->Text->ToCharArray()->Length; i++) {
			   ControlText += ((TextBox^)sender)->Text->ToCharArray()[i];
		   }

		   //switchnonaka
           //value = std::stoi(ControlText);
		   //value = (int)(std::stod(ControlText) * 10000);
		  
		   switch (gn.listItemType) {
		   case 0:
			   switch (gn.listItemWGType()) {
			   case 0:
				   switch(num) {
				   }
				   break;
			   case 1:
				   switch (num) {
				   }
				   break;
			   case 2:
				   switch (num) {
				   }
				   break;
			   }
			   break;
		   case 1:
			   switch (gn.listItemWGType()) {
			   case 0:
				   switch (num) {
				   }
				   break;
			   case 1:
				   switch (num) {
				   }
				   break;
			   case 2:
				   switch (num) {
				   case 0:
					   gn.SetString(((TextBox^)sender)->Text, ((Control^)sender)->Name);
					   break;
				   case 1:
					   min = trackBarD0->Minimum;
					   max = trackBarD0->Maximum;
					   value = ValueBind(std::stoi(ControlText),min,max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD1->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD0->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name),trackBarD0->Minimum, trackBarD0->Maximum);
					   break;
				   case 2:
					   gn.SetString(((TextBox^)sender)->Text, ((Control^)sender)->Name);
					   break;
				   case 3:
					   min = trackBarD1->Minimum;
					   max = trackBarD1->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD3->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD1->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD1->Minimum, trackBarD1->Maximum);
					   break;
				   case 4:
					   min = trackBarD2->Minimum;
					   max = trackBarD2->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD4->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD2->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD2->Minimum, trackBarD2->Maximum);
					   break;
				   case 5:
					   min = trackBarD3->Minimum;
					   max = trackBarD3->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD5->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD3->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD3->Minimum, trackBarD3->Maximum);
					   break;
				   case 6:
					   min = trackBarD4->Minimum;
					   max = trackBarD4->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD6->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD4->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD4->Minimum, trackBarD4->Maximum);
					   break;
				   case 7:
					   min = trackBarD5->Minimum;
					   max = trackBarD5->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD7->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD5->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD5->Minimum, trackBarD5->Maximum);
					   break;
				   case 8:
					   min = trackBarD6->Minimum;
					   max = trackBarD6->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD8->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD6->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD6->Minimum, trackBarD6->Maximum);
					   break;
				   case 9:
					   min = trackBarD7->Minimum;
					   max = trackBarD7->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD9->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD7->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD7->Minimum, trackBarD7->Maximum);
					   break;
				   case 10:
					   min = trackBarD8->Minimum;
					   max = trackBarD8->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD10->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD8->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD8->Minimum, trackBarD8->Maximum);
					   break;
				   case 11:
					   min = trackBarD9->Minimum;
					   max = trackBarD9->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD11->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD9->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD9->Minimum, trackBarD9->Maximum);
					   break;
				   case 12:
					   min = trackBarD10->Minimum;
					   max = trackBarD10->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD12->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD10->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD10->Minimum, trackBarD10->Maximum);
					   break;
				   case 13:
					   min = trackBarD11->Minimum;
					   max = trackBarD11->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD13->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD11->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD11->Minimum, trackBarD11->Maximum);
					   break;
				   case 14:
					   min = trackBarD12->Minimum;
					   max = trackBarD12->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD14->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD12->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD12->Minimum, trackBarD12->Maximum);
					   break;
				   case 15:
					   min = trackBarD13->Minimum;
					   max = trackBarD13->Maximum;
					   value = ValueBind(std::stoi(ControlText), min, max);
					   gn.SetTBValue(value, ((Control^)sender)->Name);
					   textBoxD15->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
					   trackBarD13->Value = ValueBind(gn.GetValue(1, ((Control^)sender)->Name), trackBarD13->Minimum, trackBarD13->Maximum);
					   break;
				   }
				   break;
			   }
			   break;
		   }
}

private: System::Void trackBarD_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int num = 0;
	for (int i = 0; i < (((TrackBar^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((TrackBar^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}

	switch (gn.listItemType) {
	case 0:
		switch (gn.listItemWGType()) {
		case 0:
			switch (num) {
			}
			break;
		case 1:
			switch (num) {
			}
			break;
		case 2:
			switch (num) {
			}
			break;
		}
		break;
	case 1:
		switch (gn.listItemWGType()) {
		case 0:
			switch (num) {
			}
			break;
		case 1:
			switch (num) {
			}
			break;
		case 2:
			switch (num) {
			case 1:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD1->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 3:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD3->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 4:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD4->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 5:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD5->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 6:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD6->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 7:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD7->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 8:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD8->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 9:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD9->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 10:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD10->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 11:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD11->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 12:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD12->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 13:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD13->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 14:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD14->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			case 15:
				gn.SetTBValue(((TrackBar^)sender)->Value, ((Control^)sender)->Name);
				textBoxD15->Text = gn.GetValue(1, ((Control^)sender)->Name).ToString();
				break;
			}
			break;
		}
		break;
	}
}

private: System::Void buttonD_Click(System::Object^ sender, System::EventArgs^ e) {
	int num = 0;
	for (int i = 0; i < (((Button^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((Button^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (gn.listItemType) {
	case 0:
		switch (gn.listItemWGType()) {
		case 0:
			switch (num) {

			}
			break;
		case 1:
			switch (num) {

			}
			break;
		case 2:
			switch (num) {

			}
			break;
		}
		break;
	case 1:
		switch (gn.listItemWGType()) {
		case 0:
			switch (num) {

			}
			break;
		case 1:
			switch (num) {

			}
			break;
		case 2:
			switch (num) {
			case 0:
				break;
			case 1:
				break;
			}
			break;
		}
		break;
	}
}

private: int ValueBind(int value,int min ,int max) {
	if (value < min) {
		value = min;
	}
	if (value > max) {
		value = max;
	}
	return value;
}


 /*■■■■■■■■■■■                         ■■                     ■■■■            
	■■■■■■■■■■■                         ■■                    ■■■■■            
	■■                                  ■■                   ■■■               
	■■                                  ■■                   ■■                
	■■                                  ■■                   ■■                
	■■             ■■■■■       ■■  ■■   ■■     ■■  ■■■■    ■■■■■■■    ■■■■■    
	■■            ■■■■■■■■     ■■ ■■■   ■■     ■■■■■■■■■     ■■      ■■■■■■■■  
	■■■■■■■■■■   ■■■    ■■■    ■■■■     ■■     ■■■■   ■■■    ■■     ■■■    ■■■ 
	■■■■■■■■■■   ■■      ■■    ■■■      ■■     ■■■     ■■    ■■     ■■      ■■ 
	■■          ■■■      ■■■   ■■       ■■     ■■      ■■    ■■    ■■■      ■■■
	■■          ■■        ■■   ■■       ■■     ■■      ■■    ■■    ■■        ■■
	■■          ■■        ■■   ■■       ■■     ■■      ■■    ■■    ■■        ■■
	■■          ■■       ■■■   ■■       ■■     ■■      ■■    ■■    ■■       ■■■
	■■           ■■      ■■    ■■       ■■     ■■      ■■    ■■     ■■      ■■ 
	■■           ■■■    ■■■    ■■       ■■     ■■      ■■    ■■     ■■■    ■■■ 
	■■            ■■■■■■■■     ■■       ■■     ■■      ■■    ■■      ■■■■■■■■  
	■■             ■■■■■       ■■       ■■     ■■      ■■    ■■       ■■■■■    
	 */

	   private:void SetTableLayoutPanelE() {
		   tableLayoutPanelE->SuspendLayout();
		   
		   buttonE0->Name = "0";
		   buttonE1->Name = "1";

		   buttonE0->Text = "Save";
		   buttonE1->Text = "Load";

		   buttonE0->ForeColor = Color::White;
		   buttonE1->ForeColor = Color::White;

		   buttonE0->FlatStyle = FlatStyle::Flat;
		   buttonE1->FlatStyle = FlatStyle::Flat;

		   buttonE0->Dock = DockStyle::Bottom;
		   buttonE1->Dock = DockStyle::Bottom;

		   buttonE0->Click += gcnew System::EventHandler(this, &MyForm::buttonE_Click);
		   buttonE1->Click += gcnew System::EventHandler(this, &MyForm::buttonE_Click);

		   tableLayoutPanelE->BackColor= System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
			   static_cast<System::Int32>(static_cast<System::Byte>(64)));

		   tableLayoutPanelE->ColumnCount = 20;
		   tableLayoutPanelE->RowCount = 8;
		   for (int i = 0; i < 20; i++) {
			   tableLayoutPanelE->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 5));
		   }
		   for (int i = 0; i < 8; i++) {
			   tableLayoutPanelE->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
		   }
		   tableLayoutPanelE->Controls->Add(buttonE0, 6, 1);
		   tableLayoutPanelE->Controls->Add(buttonE1, 6, 3);

		   tableLayoutPanelE->SetColumnSpan(buttonE0, 8);
		   tableLayoutPanelE->SetColumnSpan(buttonE1, 8);

		   tableLayoutPanelE->ResumeLayout(true);
	   }

private: System::Void SetIcon() {
	System::Drawing::Icon^ icon = gcnew System::Drawing::Icon("icon1.ico",16,16);
	this->Icon = icon;
}

private: System::Void buttonE_Click(System::Object^ sender, System::EventArgs^ e) {
	int num = 0;
	for (int i = 0; i < (((Button^)sender)->Name->ToCharArray()->Length); i++) {
		char a = ((Button^)sender)->Name->ToCharArray()[i];
		num = num * 10 + a - '0';//char'0'=int 48
	}
	switch (num) {
	case 0:
		FileSave();
		break;
	case 1:
		FileLoad();
		break;
	}
}

private: void FileSave() {
	Stream ^myStream;
	SaveFileDialog ^saveFileDialog = gcnew SaveFileDialog();

	saveFileDialog->Filter = "gnsv files (*.gnsv)|*.gnsv";
	saveFileDialog->FilterIndex = 1;
	saveFileDialog->RestoreDirectory = true;

	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		try {
			myStream = saveFileDialog->OpenFile(); 

			StreamWriter^ writer = gcnew StreamWriter(myStream);

			// Code to write the stream goes here.

			//For item
			writer->WriteLine("<Item>");
			writer=iSaveRepeater(i.RootPointer,writer,1);
			writer->WriteLine("</Item>");

			//For ...





			writer->Close();
			myStream->Close();

		}catch(...){

		};
	}
}

private: StreamWriter^  iSaveRepeater (shared_ptr<struct Node> pointer ,StreamWriter^ writer,int tabnum) {
	String^ tabs = TabReturn(tabnum);
	switch (pointer->NodeType) {
	case 0:
		writer->WriteLine(tabs + "<R>");
		break;
	case 1:
		writer->WriteLine(tabs + "<B>");
		break;
	case 2:
		writer->WriteLine(tabs + "<b>");
		break;
	case 3:
		writer->WriteLine(tabs + "<T>");
		break;
	case 4:
		writer->WriteLine(tabs + "<t>");
		break;
	case 5:
		writer->WriteLine(tabs + "<F>");
		break;
	}
	writer->WriteLine(tabs+"NodeType:"+pointer->NodeType);
	writer->WriteLine(tabs+"Property:");
	switch (pointer->NodeType) {
	case 0:
		break;
	case 1:
		for (int i = 0; i < 124; i++) {
			writer->WriteLine(tabs + "	" + pointer->Property->at(i));
		}
		break;
	case 2:
		for (int i = 0; i < 115; i++) {
			writer->WriteLine(tabs + "	" + pointer->Property->at(i));
		}
		break;
	case 3:
		for (int i = 0; i < 12; i++) {
			writer->WriteLine(tabs + "	" + pointer->Property->at(i));
		}
		break;
	case 4:
		for (int i = 0; i < 6; i++) {
			writer->WriteLine(tabs + "	" + pointer->Property->at(i));
		}
		break;
	case 5:
		break;
	}
	writer->WriteLine(tabs + "Child:");
	for (int i = 0; i < pointer->Child->size(); i++) {
		if (pointer->Child->at(i) == nullptr) {
			continue;
		}
		writer = iSaveRepeater(pointer->Child->at(i),writer,tabnum+1);
	}
	writer->WriteLine(tabs + "Group:");
	for (int i = 0; i < pointer->Group->size(); i++) {
		if (pointer->Group->at(i) == nullptr) {
			continue;
		}
		writer = iSaveRepeater(pointer->Group->at(i), writer, tabnum + 1);
	}
	switch (pointer->NodeType) {
	case 0:
		writer->WriteLine(tabs + "</R>");
		break;
	case 1:
		writer->WriteLine(tabs + "</B>");
		break;
	case 2:
		writer->WriteLine(tabs + "</b>");
		break;
	case 3:
		writer->WriteLine(tabs + "</T>");
		break;
	case 4:
		writer->WriteLine(tabs + "</t>");
		break;
	case 5:
		writer->WriteLine(tabs + "</F>");
		break;
	}
	return writer;
}

private: String^ TabReturn(int tabnum){
	String^ tabs="";
	for (int i = 0; i < tabnum; i++) {
		tabs += "	";
	}
	return tabs;
}

private: void FileLoad() {
	Stream^ myStream;
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	openFileDialog->InitialDirectory = "c:\\";
	openFileDialog->Filter = "gnsv files (*.gnsv)|*.gnsv";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		
		myStream = openFileDialog->OpenFile();
		
		StreamReader^ reader = gcnew StreamReader(myStream);

		// Code to write the stream goes here.

		//For Item

		iNodeReset();
		iRootLoad(reader);

		//For ...




		reader->Close();
		myStream->Close();
	}


}

private: int ValueReturn(String^ str) {
	int value = 0;
	bool pm = false;
	for (int i = 0; i < (str->ToCharArray()->Length); i++) {
		char a = str->ToCharArray()[i];
		value = value * 10 + a - '0';//char'0'=int 48
		if (a == '	') {
			value = 0;
		}
		if (a == ':') {
			value = 0;
		}
		if (a == '-') {
			value = 0;
			pm = true;
		}
	}
	if (pm == true) {
		value = value * (-1);
	}
	return value;
}

private: System::Void iNodeReset() {
	int num = treeView1->Nodes[0]->Nodes->Count;
	for (int s = 0; s < num;s++) {
		i.NodeDelete(treeView1->Nodes[0]->Nodes[0]->Name);
		treeView1->Nodes[0]->Nodes[0]->Remove();
	}
	shared_ptr<vector<shared_ptr<Node>>>rootNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>rootNodeGroup(new vector<shared_ptr<Node>>());
	i.RootPointer->Child=rootNodeChild;
	i.RootPointer->Group=rootNodeGroup;
	i.RootPointer->NodeNum = 0;
}

private: StreamReader^ iRootLoad(StreamReader^ reader) {
	reader->ReadLine();
	reader->ReadLine();
	reader->ReadLine();
	reader->ReadLine();
	reader->ReadLine();

	//child
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "") , "Group:"); line = reader->ReadLine()) {
		System::Diagnostics::Debug::WriteLine(line);
		reader = iLoadRepeater(i.RootPointer, reader,treeView1->Nodes[0]);
	}
	//group
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "")->Replace("R", "")->Replace("B", "")->Replace("b", "")->Replace("T", "")->Replace("t", "")->Replace("F", "")->Replace("Item", ""), "</>"); line = reader->ReadLine()) {
		System::Diagnostics::Debug::WriteLine(line);
		reader = iLoadRepeater(i.RootPointer, reader, treeView1->Nodes[0]);
	}

	return reader;
}

private: StreamReader^ iLoadRepeater(shared_ptr<struct Node> parentPointer, StreamReader^ reader, TreeNode^ parentTreeNode) {
	switch (ValueReturn(reader->ReadLine())) {
	case 1:
		reader = iBLoad(parentPointer, reader, parentTreeNode);
		break;
	case 2:
		reader = ibLoad(parentPointer, reader, parentTreeNode);
		break;
	case 3:
		reader = iTLoad(parentPointer, reader, parentTreeNode);
		break;
	case 4:
		reader = itLoad(parentPointer, reader, parentTreeNode);
		break;
	default:
		break;
	}
	return reader;
}

private: StreamReader^ iBLoad(shared_ptr<struct Node> parentPointer, StreamReader^ reader, TreeNode^ parentTreeNode) {
	reader->ReadLine();

	TreeNode^ treenode = gcnew TreeNode();
	treenode->Text = "B";
	treenode->Name = parentTreeNode->Name + "-" + "B" + parentPointer->NodeNum;
	parentTreeNode->Nodes->Add(treenode);
	TreeNode^ treenodeG = gcnew TreeNode();
	treenodeG->Text = "G";
	treenode->Nodes->Add(treenodeG);

	shared_ptr<vector<int>>newNodeProperty(new vector<int>{
		ValueReturn(reader->ReadLine()),//0
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//10
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//20
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//30
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//40
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//50
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//60
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//70
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//80
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//90
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//100
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//110
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//120
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine())
		});
	shared_ptr<vector<shared_ptr<Node>>>newNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newNode(new Node{ 1 ,0,false,false,nullptr,parentPointer,newNodeProperty,newNodeChild,newNodeGroup });
	parentPointer->NodeNum += 1;
	parentPointer->Child->push_back(newNode);

	reader->ReadLine();

	//child
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", ""), "Group:"); line = reader->ReadLine()) {
		System::Diagnostics::Debug::WriteLine(line);
		reader = iLoadRepeater(newNode, reader, treenode);
	}
	//group
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "")->Replace("R", "")->Replace("B", "")->Replace("b", "")->Replace("T", "")->Replace("t", "")->Replace("F", "")->Replace("Item", ""), "</>"); line = reader->ReadLine()) {
		System::Diagnostics::Debug::WriteLine(line);
		reader = iLoadRepeater(newNode, reader, treenode);
	}

	return reader;
}

private: StreamReader^ ibLoad(shared_ptr<struct Node> parentPointer, StreamReader^ reader, TreeNode^ parentTreeNode) {
	reader->ReadLine();

	TreeNode^ treenodeg = gcnew TreeNode();
	treenodeg->Text = "b";
	treenodeg->Name = parentTreeNode->Name + "-" + "b" + parentPointer->Group->size();
	parentTreeNode->Nodes[0]->Nodes->Add(treenodeg);

	PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
	shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{
		ValueReturn(reader->ReadLine()),//0
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//10
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//20
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//30
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//40
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//50
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//60
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//70
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//80
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//90
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//100
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//110
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine())
	});
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newGroupNode(new Node{ 2 ,0,true,true,newGroupNodePath,parentPointer,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
	parentPointer->Group->push_back(newGroupNode);

	reader->ReadLine();

	//child
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", ""), "Group:"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newGroupNode, reader, treenodeg);
	}
	//group
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "")->Replace("R", "")->Replace("B", "")->Replace("b", "")->Replace("T", "")->Replace("t", "")->Replace("F", "")->Replace("Item", ""), "</>"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newGroupNode, reader, treenodeg);
	}

	return reader;
}

private: StreamReader^ iTLoad(shared_ptr<struct Node> parentPointer, StreamReader^ reader, TreeNode^ parentTreeNode) {
	reader->ReadLine();

	TreeNode^ treenode = gcnew TreeNode();
	treenode->Text = "T";
	treenode->Name = parentTreeNode->Name + "-" + "T" + parentPointer->NodeNum;
	parentTreeNode->Nodes->Add(treenode);
	TreeNode^ treenodeG = gcnew TreeNode();
	treenodeG->Text = "G";
	treenode->Nodes->Add(treenodeG);

	shared_ptr<vector<int>>newNodeProperty(new vector<int>{
		ValueReturn(reader->ReadLine()),//0
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),//10
		ValueReturn(reader->ReadLine())
		});
	shared_ptr<vector<shared_ptr<Node>>>newNodeChild(new vector < shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newNode(new Node{ 3,0,false,false,nullptr,parentPointer,newNodeProperty,newNodeChild,newNodeGroup });
	parentPointer->NodeNum += 1;
	parentPointer->Child->push_back(newNode);

	reader->ReadLine();

	//child
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", ""), "Group:"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newNode, reader, treenode);
	}
	//group
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "")->Replace("R", "")->Replace("B", "")->Replace("b", "")->Replace("T", "")->Replace("t", "")->Replace("F", "")->Replace("Item", ""), "</>"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newNode, reader, treenode);
	}

	return reader;
}

private: StreamReader^ itLoad(shared_ptr<struct Node> parentPointer, StreamReader^ reader, TreeNode^ parentTreeNode) {
	reader->ReadLine();

	TreeNode^ treenodeg = gcnew TreeNode();
	treenodeg->Text = "t";
	treenodeg->Name = parentTreeNode->Name + "-" + "t" + parentPointer->Group->size();
	parentTreeNode->Nodes[0]->Nodes->Add(treenodeg);

	PTSTR newGroupNodePath = (PTSTR)calloc(100000, sizeof(TCHAR));
	shared_ptr<vector<int>>newGroupNodeProperty(new vector<int>{
		ValueReturn(reader->ReadLine()),//0
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine()),
		ValueReturn(reader->ReadLine())
		});
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeChild(new vector<shared_ptr<Node>>());
	shared_ptr<vector<shared_ptr<Node>>>newGroupNodeGroup(new vector<shared_ptr<Node>>());
	shared_ptr<Node> newGroupNode(new Node{ 4 ,0,true,true,newGroupNodePath,parentPointer,newGroupNodeProperty,newGroupNodeChild,newGroupNodeGroup });
	parentPointer->Group->push_back(newGroupNode);

	reader->ReadLine();

	//child
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", ""), "Group:"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newGroupNode, reader, treenodeg);
	}
	//group
	for (String^ line = reader->ReadLine(); !String::Equals(line->Replace("	", "")->Replace("R", "")->Replace("B", "")->Replace("b", "")->Replace("T", "")->Replace("t", "")->Replace("F", "")->Replace("Item", ""), "</>"); line = reader->ReadLine()) {
		reader = iLoadRepeater(newGroupNode, reader, treenodeg);
	}

	return reader;
}






};
}