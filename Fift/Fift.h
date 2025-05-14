#pragma once
	
#include "Fift3.h"
#include "Fift4.h"
#include "Fift5.h"
#include "PauseM.h"

namespace Fift {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Fift : public System::Windows::Forms::Form
	{
	public:
		Fift(void)
		{
			InitializeComponent();
		}

	protected:
		~Fift()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::Container^ components;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Start;
	private: System::Windows::Forms::RadioButton^ level1;
	private: System::Windows::Forms::RadioButton^ level2;
	private: System::Windows::Forms::RadioButton^ level3;
	private: System::Windows::Forms::Button^ buttonExitGame;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->level1 = (gcnew System::Windows::Forms::RadioButton());
			this->level2 = (gcnew System::Windows::Forms::RadioButton());
			this->level3 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonExitGame = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 28.2F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(112, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 62);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Пятнашки";
			// 
			// Start
			// 
			this->Start->BackColor = System::Drawing::Color::RoyalBlue;
			this->Start->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold));
			this->Start->ForeColor = System::Drawing::SystemColors::Control;
			this->Start->Location = System::Drawing::Point(85, 272);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(147, 51);
			this->Start->TabIndex = 5;
			this->Start->Text = L"Начать";
			this->Start->UseVisualStyleBackColor = false;
			this->Start->Click += gcnew System::EventHandler(this, &Fift::Start_Click);
			// 
			// level1
			// 
			this->level1->AutoSize = true;
			this->level1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->level1->Location = System::Drawing::Point(153, 160);
			this->level1->Name = L"level1";
			this->level1->Size = System::Drawing::Size(127, 32);
			this->level1->TabIndex = 4;
			this->level1->Text = L"Уровень 1";
			this->level1->UseVisualStyleBackColor = true;
			// 
			// level2
			// 
			this->level2->AutoSize = true;
			this->level2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->level2->Location = System::Drawing::Point(153, 187);
			this->level2->Name = L"level2";
			this->level2->Size = System::Drawing::Size(127, 32);
			this->level2->TabIndex = 3;
			this->level2->Text = L"Уровень 2";
			this->level2->UseVisualStyleBackColor = true;
			// 
			// level3
			// 
			this->level3->AutoSize = true;
			this->level3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->level3->Location = System::Drawing::Point(153, 214);
			this->level3->Name = L"level3";
			this->level3->Size = System::Drawing::Size(127, 32);
			this->level3->TabIndex = 2;
			this->level3->Text = L"Уровень 3";
			this->level3->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->label2->Location = System::Drawing::Point(148, 129);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(187, 28);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Выберите уровень:";
			// 
			// buttonExitGame
			// 
			this->buttonExitGame->BackColor = System::Drawing::Color::Gray;
			this->buttonExitGame->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->buttonExitGame->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonExitGame->Location = System::Drawing::Point(267, 273);
			this->buttonExitGame->Name = L"buttonExitGame";
			this->buttonExitGame->Size = System::Drawing::Size(147, 51);
			this->buttonExitGame->TabIndex = 0;
			this->buttonExitGame->Text = L"Завершить игру";
			this->buttonExitGame->UseVisualStyleBackColor = false;
			this->buttonExitGame->Click += gcnew System::EventHandler(this, &Fift::buttonExitGame_Click);
			// 
			// Fift
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OldLace;
			this->ClientSize = System::Drawing::Size(482, 353);
			this->Controls->Add(this->buttonExitGame);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->level3);
			this->Controls->Add(this->level2);
			this->Controls->Add(this->level1);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->label1);
			this->Name = L"Fift";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Пятнашки";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->level1->Checked) {
				Fift3^ form = gcnew Fift3(this);
				form->Show();
				this->Hide();
			}
			else if (this->level2->Checked) {
				Fift4^ form = gcnew Fift4(this);
				form->Show();
				this->Hide();
			}
			else if (this->level3->Checked) {
				Fift5^ form = gcnew Fift5(this);
				form->Show();
				this->Hide();
			}
		}

	private: System::Void buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	};
}
