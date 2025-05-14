#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Fift {

	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(String^ gameMode)
		{
			InitializeComponent();
			SetHelpText(gameMode);

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false; 
			this->MinimizeBox = false; 
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent; 
		}

	protected:
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TextBox^ helpTextBox;
	private: System::Windows::Forms::Button^ buttonCloseHelp;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->helpTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->buttonCloseHelp = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();

			   //
			   // helpTextBox
			   //
			   this->helpTextBox->Location = System::Drawing::Point(12, 12);
			   this->helpTextBox->Multiline = true; 
			   this->helpTextBox->Name = L"helpTextBox";
			   this->helpTextBox->ReadOnly = true; 
			   this->helpTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical; 
			   this->helpTextBox->Size = System::Drawing::Size(360, 180); 
			   this->helpTextBox->TabIndex = 0;
			   //
			   // buttonCloseHelp
			   //
			   this->buttonCloseHelp->Location = System::Drawing::Point(140, 200); 
			   this->buttonCloseHelp->Name = L"buttonCloseHelp";
			   this->buttonCloseHelp->Size = System::Drawing::Size(100, 30); 
			   this->buttonCloseHelp->TabIndex = 1;
			   this->buttonCloseHelp->Text = L"«акрыть";
			   this->buttonCloseHelp->UseVisualStyleBackColor = true;
			   this->buttonCloseHelp->Click += gcnew System::EventHandler(this, &HelpForm::buttonCloseHelp_Click);

			   //
			   // HelpForm
			   //
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(384, 241); 
			   this->Controls->Add(this->buttonCloseHelp);
			   this->Controls->Add(this->helpTextBox);
			   this->Name = L"HelpForm";
			   this->Text = L"—правка"; 
			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }
#pragma endregion

	private:
		void SetHelpText(String^ gameMode)
		{
			if (gameMode == "3x3")
			{
				helpTextBox->Text =
					"—правка дл€ игры 3x3:\r\n\r\n" +
					"ѕеремещайте пронумерованные плитки, нажима€ на плитку, соседствующую с пустой €чейкой.\r\n" +
					"÷ель игры - расположить плитки по пор€дку от 1 до 8, оставив пустую €чейку в правом нижнем углу.";
			}
			else if (gameMode == "4x4")
			{
				helpTextBox->Text =
					"—правка дл€ игры 4x4:\r\n\r\n" +
					"Ёто классическа€ игра \"ѕ€тнашки\". ѕеремещайте пронумерованные плитки (от 1 до 15), нажима€ на плитку, соседствующую с пустой €чейкой.\r\n" +
					"÷ель игры - расположить плитки по пор€дку от 1 до 15, оставив пустую €чейку в правом нижнем углу.";
			}
			else if (gameMode == "5x5")
			{
				helpTextBox->Text =
					"—правка дл€ игры 5x5:\r\n\r\n" +
					"Ѕолее сложна€ верси€ игры с полем 5x5. ѕеремещайте пронумерованные плитки (от 1 до 24), нажима€ на плитку, соседствующую с пустой €чейкой.\r\n" +
					"÷ель игры - расположить плитки по пор€дку от 1 до 24, оставив пустую €чейку в правом нижнем углу.";
			}
			else 
			{
				helpTextBox->Text =
					"ќбща€ справка по игре \"ѕ€тнашки\":\r\n\r\n" +
					"Ќажимайте на плитки, расположенные р€дом с пустой €чейкой, чтобы переместить их в эту €чейку.\r\n" +
					"—оберите плитки по пор€дку, чтобы выиграть.";
			}
		}

	private: System::Void buttonCloseHelp_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	};
}