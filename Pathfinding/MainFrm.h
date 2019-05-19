#pragma once

#include<vector>
#include<windows.h>
#include"TypeCellule.h"
#include"TypeAlgo.h"
#include"TypeLissage.h"
#include"RechercheChemin.h"

namespace Pathfinding {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainFrm
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class MainFrm : public System::Windows::Forms::Form
	{
	public:
		MainFrm(void)
		{
			InitializeComponent();
			this->SetStyle(ControlStyles::AllPaintingInWmPaint|ControlStyles::UserPaint|ControlStyles::DoubleBuffer , true);
			
			_RechercheChemin = new RechercheChemin();

			_outil = TypeCellule::Aucun;
			_lissage = TypeLissage::AucunLissage;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainFrm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  NGrilleBtn;






	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^	   groupBox5;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	//private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	
			 //interface
	private: TypeCellule  _outil;
    private: TypeLissage  _lissage;

    //RechercheChemin
    private: RechercheChemin*  _RechercheChemin;
	private: System::Windows::Forms::Label^  label6;





	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainFrm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->NGrilleBtn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			//this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Right;
			this->tabControl1->Location = System::Drawing::Point(800, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(210, 600);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(202, 574);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Environnement ";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->NGrilleBtn);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->numericUpDown2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->numericUpDown1);
			this->groupBox2->Location = System::Drawing::Point(6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(189, 104);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Grille";
			// 
			// NGrilleBtn
			// 
			this->NGrilleBtn->Location = System::Drawing::Point(16, 71);
			this->NGrilleBtn->Name = L"NGrilleBtn";
			this->NGrilleBtn->Size = System::Drawing::Size(111, 23);
			this->NGrilleBtn->TabIndex = 3;
			this->NGrilleBtn->Text = L"Créer Nouvelle Grille";
			this->NGrilleBtn->UseVisualStyleBackColor = true;
			this->NGrilleBtn->Click += gcnew System::EventHandler(this, &MainFrm::button4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(6, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 15);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Largeur   ..................";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(127, 40);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {80, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(51, 20);
			this->numericUpDown2->TabIndex = 2;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(6, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 15);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Hauteur   ..................";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(127, 14);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {60, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(51, 20);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Location = System::Drawing::Point(6, 116);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(189, 123);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Cellules";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Point de départ   ..............";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(153, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(25, 25);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainFrm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Obstacle   .........................";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(153, 56);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(25, 25);
			this->button2->TabIndex = 0;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainFrm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Point d\'arrivée   ...............";
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::DarkOrange;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Chocolate;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Orange;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(153, 87);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(25, 25);
			this->button3->TabIndex = 0;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainFrm::button3_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(202, 574);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Algorithme";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->radioButton10);
			this->groupBox4->Controls->Add(this->radioButton5);
			this->groupBox4->Controls->Add(this->radioButton4);
			this->groupBox4->Controls->Add(this->radioButton3);
			this->groupBox4->Controls->Add(this->radioButton2);
			this->groupBox4->Controls->Add(this->radioButton1);
			this->groupBox4->Location = System::Drawing::Point(6, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(188, 158);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Recherche de chemin ";
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Checked = true;
			this->radioButton10->Location = System::Drawing::Point(15, 19);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(56, 17);
			this->radioButton10->TabIndex = 1;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"Aucun";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton10_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(15, 134);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(99, 17);
			this->radioButton5->TabIndex = 0;
			this->radioButton5->Text = L"Bidirectionnelle ";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(15, 111);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(59, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->Text = L"Greedy";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(15, 88);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(36, 17);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->Text = L"A*";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(15, 65);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(61, 17);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->Text = L"Largeur";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(15, 42);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(77, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"Profondeur";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton1_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(202, 574);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Chemin";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radioButton9);
			this->groupBox5->Controls->Add(this->radioButton8);
			//this->groupBox5->Controls->Add(this->radioButton7);
			this->groupBox5->Controls->Add(this->radioButton6);
			this->groupBox5->Location = System::Drawing::Point(6, 6);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(190, 90);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Lissage";
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(16, 65);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(79, 17);
			this->radioButton9->TabIndex = 0;
			this->radioButton9->Text = L"Catmull-rom";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton9_CheckedChanged);
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(16, 42);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(62, 17);
			this->radioButton8->TabIndex = 0;
			this->radioButton8->Text = L"B-spline";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton8_CheckedChanged);
			// 
			// radioButton7
			// 
			//this->radioButton7->AutoSize = true;
			//this->radioButton7->Location = System::Drawing::Point(16, 42);
			//this->radioButton7->Name = L"radioButton7";
			//this->radioButton7->Size = System::Drawing::Size(91, 17);
			//this->radioButton7->TabIndex = 0;
			//this->radioButton7->Text = L"Courbe Bézier";
			//this->radioButton7->UseVisualStyleBackColor = true;
			//this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton7_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Checked = true;
			this->radioButton6->Location = System::Drawing::Point(16, 19);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(56, 17);
			this->radioButton6->TabIndex = 0;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Aucun";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MainFrm::radioButton6_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 1;
			// 
			// MainFrm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1010, 600);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainFrm";
			this->Text = L"Pathfinding";
			this->Load += gcnew System::EventHandler(this, &MainFrm::MainFrm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainFrm::MainFrm_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrm::MainFrm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainFrm::MainFrm_MouseMove);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: 
			

			System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				ResetOutils();
				this->button1->FlatAppearance->BorderSize=2;
				this->_outil = TypeCellule::Depart;

			}

			System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				ResetOutils();
				this->button2->FlatAppearance->BorderSize=2;
				this->_outil = TypeCellule::Arrivee;

			}

			System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				ResetOutils();
				this->button3->FlatAppearance->BorderSize=2;
				this->_outil = TypeCellule::Obstacle;

			}

			System::Void ResetOutils()
			{
				this->button1->FlatAppearance->BorderSize=1;
				this->button2->FlatAppearance->BorderSize=1;
				this->button3->FlatAppearance->BorderSize=1;
				this->_outil = TypeCellule::Aucun;

			}
			System::Void MainFrm_Load(System::Object^  sender, System::EventArgs^  e) {

				int nb_colonnes = static_cast<int>(this->numericUpDown1->Value);
				int nb_lignes = static_cast<int>(this->numericUpDown2->Value);

				_RechercheChemin->CreerTerrain(nb_lignes, nb_colonnes);

			}

			System::Void MainFrm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
			{

				//System::Drawing::Bitmap^ buff = gcnew System::Drawing::Bitmap(800,600);
				System::Drawing::Graphics^ g = e->Graphics;//System::Drawing::Graphics::FromImage(buff);
	
				g->Clear(Color::White);
				
				

				//dessiner la grille
				int x_offset = 800/2 - (_RechercheChemin->_nb_colonnes * _RechercheChemin->_espacement / 2);
				int y_offset = 600/2 - (_RechercheChemin->_nb_lignes * _RechercheChemin->_espacement / 2);

				for(int i=0;i<=_RechercheChemin->_nb_lignes;i++)
					g->DrawLine(System::Drawing::Pens::Black,
						x_offset,
						y_offset + (i * _RechercheChemin->_espacement),
						x_offset + (_RechercheChemin->_nb_colonnes * _RechercheChemin->_espacement),
						y_offset + (i * _RechercheChemin->_espacement));

				for(int i=0;i<=_RechercheChemin->_nb_colonnes;i++)
					g->DrawLine(System::Drawing::Pens::Black,
						x_offset + (i * _RechercheChemin->_espacement),
						y_offset,
						x_offset + (i * _RechercheChemin->_espacement),
						y_offset + (_RechercheChemin->_nb_lignes * _RechercheChemin->_espacement));


				

				int x1,x2,y1,y2;
				int k=0;
				std::vector<int> parc(_RechercheChemin->_terrain.size(),0);
				//dessiner les cellules parcourus
				for (int i=0; i<_RechercheChemin->_ArbreRecherche.size(); i++)
				{   
					if (_RechercheChemin->_ArbreRecherche[i])
					{
						x1 = _RechercheChemin->_terrain[_RechercheChemin->_ArbreRecherche[i]->deb].Centre_X;
						y1 = _RechercheChemin->_terrain[_RechercheChemin->_ArbreRecherche[i]->deb].Centre_Y;

						x2 = _RechercheChemin->_terrain[_RechercheChemin->_ArbreRecherche[i]->dest].Centre_X;
						y2 = _RechercheChemin->_terrain[_RechercheChemin->_ArbreRecherche[i]->dest].Centre_Y;

						g->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::Red,1),
							x1, y1, x2, y2);

						if(parc[_RechercheChemin->_ArbreRecherche[i]->deb] == 0)
						{

							g->DrawString(k.ToString(),gcnew System::Drawing::Font(
								L"Arial",_RechercheChemin->_espacement/6),
								System::Drawing::Brushes::Black,
								x1+_RechercheChemin->_espacement/10,
								y1+_RechercheChemin->_espacement/10);

							parc[_RechercheChemin->_ArbreRecherche[i]->deb] = 1;
						
							k++;
						}
					}
				}
				
				//dessiner les cellules
				Cellule c;

				for (std::vector<Cellule>::iterator It = _RechercheChemin->_terrain.begin(); It != _RechercheChemin->_terrain.end(); ++It)
				{
					c = (*It);
					switch(c.Type)
					{
					case TypeCellule::Obstacle:
						g->FillRectangle(
							System::Drawing::Brushes::DarkOrange,
							System::Drawing::RectangleF(c.X,c.Y,c.Largeur,c.Hauteur));
						g->DrawRectangle(
							System::Drawing::Pens::Orange,
							System::Drawing::Rectangle(c.X,c.Y,c.Largeur,c.Hauteur));
						g->DrawRectangle(
							System::Drawing::Pens::Chocolate,
							System::Drawing::Rectangle(c.X-1,c.Y-1,c.Largeur+1,c.Hauteur+1));
						break;
					case TypeCellule::Depart:
						g->FillRectangle(System::Drawing::Brushes::LightGreen,
							System::Drawing::RectangleF(c.X,c.Y,c.Largeur+1,c.Hauteur+1));
						g->DrawString(L"D",gcnew System::Drawing::Font(
							L"Arial",_RechercheChemin->_espacement/2,
							System::Drawing::FontStyle::Bold),
							System::Drawing::Brushes::Black,
							c.X+_RechercheChemin->_espacement/10,
							c.Y+_RechercheChemin->_espacement/10);
						break;
					case TypeCellule::Arrivee:
						g->FillRectangle(System::Drawing::Brushes::Red,
							System::Drawing::RectangleF(c.X,c.Y,c.Largeur+1,c.Hauteur+1));
						g->DrawString(L"A",gcnew System::Drawing::Font(
							L"Arial",_RechercheChemin->_espacement/2,
							System::Drawing::FontStyle::Bold),
							System::Drawing::Brushes::Black,
							c.X+_RechercheChemin->_espacement/10,
							c.Y+_RechercheChemin->_espacement/10);
						break;
					}
				}

				//dessiner le chemin
				if (_RechercheChemin->_chemin.size() > 0)
				{
					switch(_lissage)
					{
					case TypeLissage::AucunLissage:				
						{
							std::list<int>::iterator it = _RechercheChemin->_chemin.begin();
							std::list<int>::iterator nxt = it; ++nxt;

							for (it; nxt != _RechercheChemin->_chemin.end(); ++it, ++nxt)
								g->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::BlueViolet,3),
									_RechercheChemin->_terrain[*it].Centre_X,
									_RechercheChemin->_terrain[*it].Centre_Y,
									_RechercheChemin->_terrain[*nxt].Centre_X,
									_RechercheChemin->_terrain[*nxt].Centre_Y);
					
						}
						break;
					case TypeLissage::BSpline:
						{
							_RechercheChemin->_chemin_lisse.clear();
							_RechercheChemin->LissageBSpline();

							std::list<Vecteur2D>::iterator it = _RechercheChemin->_chemin_lisse.begin();
							std::list<Vecteur2D>::iterator nxt = it; ++nxt;

							for (it; nxt != _RechercheChemin->_chemin_lisse.end(); ++it, ++nxt)
								g->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::BlueViolet,3),
									(*it).x,
									(*it).y,
									(*nxt).x,
									(*nxt).y);

						}
						break;
					case TypeLissage::CatmullRom:
						{
							_RechercheChemin->_chemin_lisse.clear();
							_RechercheChemin->LissageCatmullRom();

							std::list<Vecteur2D>::iterator it = _RechercheChemin->_chemin_lisse.begin();
							std::list<Vecteur2D>::iterator nxt = it; ++nxt;

							for (it; nxt != _RechercheChemin->_chemin_lisse.end(); ++it, ++nxt)
								g->DrawLine(gcnew System::Drawing::Pen(System::Drawing::Color::BlueViolet,3),
									(*it).x,
									(*it).y,
									(*nxt).x,
									(*nxt).y);
						}
						break;
					/*case TypeLissage::CourbeBezier:
						{
							_RechercheChemin->_chemin_lisse.clear();

						}
						break;*/
					}
				}

				/*e->Graphics->DrawImage(buff,System::Drawing::PointF(0,0));
  
				delete buff;
				buff = nullptr;*/

			}

			System::Void ModifierCell(int x,int y,bool effacer)
			{
				// trouver le carreau pointé par x, y
				int xCarreau = (x - _RechercheChemin->x_decal) / _RechercheChemin->_espacement;
				int yCarreau = (y - _RechercheChemin->y_decal) / _RechercheChemin->_espacement;
				//s'assurer de ne pas deborder
				if(xCarreau>=0 && yCarreau>=0 && xCarreau<_RechercheChemin->_nb_colonnes && yCarreau<_RechercheChemin->_nb_lignes)
				{
					if(!effacer)
					{
						if(_RechercheChemin->CellVide(xCarreau,yCarreau))
							switch(_outil)
							{
							case TypeCellule::Obstacle:
								_RechercheChemin->ModifierPosition(xCarreau,yCarreau,TypeCellule::Obstacle);
								break;
							case TypeCellule::Depart:
								if(_RechercheChemin->index_depart != -1)
									_RechercheChemin->_terrain[_RechercheChemin->index_depart].Type = TypeCellule::Aucun;
								_RechercheChemin->index_depart = yCarreau * _RechercheChemin->_nb_colonnes + xCarreau;
								_RechercheChemin->ModifierPosition(xCarreau,yCarreau,TypeCellule::Depart);
								break;
							case TypeCellule::Arrivee:
								if(_RechercheChemin->index_arrivee != -1)
									_RechercheChemin->_terrain[_RechercheChemin->index_arrivee].Type = TypeCellule::Aucun;
								_RechercheChemin->index_arrivee = yCarreau * _RechercheChemin->_nb_colonnes + xCarreau;
								_RechercheChemin->ModifierPosition(xCarreau,yCarreau,TypeCellule::Arrivee);
								break;
							}
					}
					else
					{
						if(!_RechercheChemin->CellVide(xCarreau,yCarreau))
						{
							if(_RechercheChemin->_terrain[yCarreau * _RechercheChemin->_nb_colonnes + xCarreau].Type == TypeCellule::Obstacle)
							{
								_RechercheChemin->ModifierPosition(xCarreau,yCarreau,TypeCellule::Aucun);
							}
						}
					}
				}
			}

			
			System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				int nb_colonnes = static_cast<int>(this->numericUpDown1->Value);
				int nb_lignes = static_cast<int>(this->numericUpDown2->Value);
				
				_RechercheChemin->CreerTerrain(nb_lignes,nb_colonnes);

				_RechercheChemin->_chemin.clear();
				_RechercheChemin->_ArbreRecherche.clear();

				this->Invalidate();
			}
			
			System::Void MainFrm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				if(e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					this->ModifierCell(e->X,e->Y,false);
					this->Invalidate();
				}
				if(e->Button == System::Windows::Forms::MouseButtons::Right)
				{
					this->ModifierCell(e->X,e->Y,true);
					this->Invalidate();
				}
			}

			System::Void MainFrm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			{
				if(e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					this->ModifierCell(e->X,e->Y,false);
					this->Invalidate();
				}
				if(e->Button == System::Windows::Forms::MouseButtons::Right)
				{
					this->ModifierCell(e->X,e->Y,true);
					this->Invalidate();
				}
			}
			
			System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton10->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::AucunAlgo);
					this->Invalidate();
					label6->Text = "";
				}
			}

			System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton1->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::Profondeur);
					this->Invalidate();
					double tps = _RechercheChemin->TpsCalc*1000;
					label6->Text = "Temps de calcul :\n" + tps.ToString() + "ms";
				}
			}

			System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton2->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::Largeur);
					this->Invalidate();
					double tps = _RechercheChemin->TpsCalc*1000;
					label6->Text = "Temps de calcul :\n" + tps.ToString() + "ms";
				}
			}

			System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton3->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::AStar);
					this->Invalidate();
					double tps = _RechercheChemin->TpsCalc*1000;
					double cout = _RechercheChemin->CoutChemin;
					label6->Text = L"Temps de calcul :\n" + tps.ToString() + L"ms.\n" + L"Cout du chemin :\n" + cout.ToString();
				}
			}

			System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton4->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::Greedy);
					this->Invalidate();
					double tps = _RechercheChemin->TpsCalc*1000;
					label6->Text = "Temps de calcul :\n" + tps.ToString() + "ms";
				}
			}

			System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton5->Checked)
				{
					_RechercheChemin->ModifierAlgorithme(TypeAlgo::Bidirectionnelle);
					this->Invalidate();
					double tps = _RechercheChemin->TpsCalc*1000;
					label6->Text = "Temps de calcul :\n" + tps.ToString() + "ms";
				}
			}

			System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton6->Checked)
				{
					_lissage = TypeLissage::AucunLissage;
					this->Invalidate();
				}
			}

			//System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			//{
			//	if(radioButton7->Checked)
			//	{
			//		_lissage = TypeLissage::CourbeBezier;
			//		this->Invalidate();
			//	}
			//}

			System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton8->Checked)
				{
					_lissage = TypeLissage::BSpline;
					this->Invalidate();
				}
			}

			System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			{
				if(radioButton9->Checked)
				{
					_lissage = TypeLissage::CatmullRom;
					this->Invalidate();
				}
			}
};
}

