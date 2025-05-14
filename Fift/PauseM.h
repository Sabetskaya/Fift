#pragma once
#include "HelpForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Fift {

	public ref class PauseM : public System::Windows::Forms::Form
	{
	public:
		
		PauseM(String^ gameMode)
		{
			InitializeComponent();
			
			this->gameMode = gameMode;

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; 
			this->MaximizeBox = false;
			this->MinimizeBox = false; 
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent; 
		}

	protected:
		~PauseM()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::Container^ components;


	private: System::Windows::Forms::Label^ labelPaused;
	private: System::Windows::Forms::Button^ buttonResume;
	private: System::Windows::Forms::Button^ buttonMainMenu; 
	private: System::Windows::Forms::Button^ buttonHelp;     

	private: System::String^ gameMode;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->labelPaused = (gcnew System::Windows::Forms::Label());
			   this->buttonResume = (gcnew System::Windows::Forms::Button());
			   this->buttonMainMenu = (gcnew System::Windows::Forms::Button()); 
			   this->buttonHelp = (gcnew System::Windows::Forms::Button());   
			   this->SuspendLayout();

			   // 
			   // labelPaused
			   // 
			   this->labelPaused->AutoSize = true;
			   this->labelPaused->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->labelPaused->Location = System::Drawing::Point(75, 30); 
			   this->labelPaused->Name = L"labelPaused";
			   this->labelPaused->Size = System::Drawing::Size(150, 50);
			   this->labelPaused->TabIndex = 0;
			   this->labelPaused->Text = L"Пауза";
			   // 
			   // buttonResume
			   // 
			   this->buttonResume->Location = System::Drawing::Point(80, 100); 
			   this->buttonResume->Name = L"buttonResume";
			   this->buttonResume->Size = System::Drawing::Size(140, 40);
			   this->buttonResume->TabIndex = 1;
			   this->buttonResume->Text = L"Продолжить";
			   this->buttonResume->UseVisualStyleBackColor = true;
			   this->buttonResume->Click += gcnew System::EventHandler(this, &PauseM::buttonResume_Click);

			   // 
			   // buttonMainMenu
			   // 
			   this->buttonMainMenu->Location = System::Drawing::Point(80, 150); 
			   this->buttonMainMenu->Name = L"buttonMainMenu";
			   this->buttonMainMenu->Size = System::Drawing::Size(140, 40);
			   this->buttonMainMenu->TabIndex = 2;
			   this->buttonMainMenu->Text = L"Главное меню";
			   this->buttonMainMenu->UseVisualStyleBackColor = true;
			   this->buttonMainMenu->Click += gcnew System::EventHandler(this, &PauseM::buttonMainMenu_Click);

			   // 
			   // buttonHelp
			   // 
			   this->buttonHelp->Location = System::Drawing::Point(80, 200); 
			   this->buttonHelp->Name = L"buttonHelp";
			   this->buttonHelp->Size = System::Drawing::Size(140, 40);
			   this->buttonHelp->TabIndex = 3;
			   this->buttonHelp->Text = L"Справка";
			   this->buttonHelp->UseVisualStyleBackColor = true;
			   this->buttonHelp->Click += gcnew System::EventHandler(this, &PauseM::buttonHelp_Click);


			   // 
			   // PauseM
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(300, 260); 
			   this->Controls->Add(this->buttonHelp); 
			   this->Controls->Add(this->buttonMainMenu); 
			   this->Controls->Add(this->buttonResume); 
			   this->Controls->Add(this->labelPaused); 
			   this->Name = L"PauseM";
			   this->Text = L"Пауза";
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }
#pragma endregion

	private: System::Void buttonResume_Click(System::Object^ sender, System::EventArgs^ e)
	{

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close(); 
	}

	private: System::Void buttonMainMenu_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Abort;
		this->Close(); 
	}

	private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HelpForm^ helpForm = gcnew HelpForm(this->gameMode);
		helpForm->ShowDialog(this); 
	}
	};
}