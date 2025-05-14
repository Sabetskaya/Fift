#pragma once

#include "PauseM.h"
#using <System.dll> 

namespace Fift {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Fift5 : public System::Windows::Forms::Form
	{
	public:
		Fift5(Form^ main)
		{
			mainForm = main;
			InitializeComponent();
			Init();
		}

	protected:
		~Fift5()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		event EventHandler<int>^ GameWon;

	private:System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::Button^ buttonFinish;
	private: System::Windows::Forms::Label^ moveCounterLabel;
	private: System::Windows::Forms::Label^ timerLabel;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Timer^ feedbackTimer; 

		   // Объявления кнопок игрового поля 5x5 (button51 ... button525)
	private: System::Windows::Forms::Button^ button51;
	private: System::Windows::Forms::Button^ button52;
	private: System::Windows::Forms::Button^ button53;
	private: System::Windows::Forms::Button^ button54;
	private: System::Windows::Forms::Button^ button55;
	private: System::Windows::Forms::Button^ button56;
	private: System::Windows::Forms::Button^ button57;
	private: System::Windows::Forms::Button^ button58;
	private: System::Windows::Forms::Button^ button59;
	private: System::Windows::Forms::Button^ button510;
	private: System::Windows::Forms::Button^ button511;
	private: System::Windows::Forms::Button^ button512;
	private: System::Windows::Forms::Button^ button513;
	private: System::Windows::Forms::Button^ button514;
	private: System::Windows::Forms::Button^ button515;
	private: System::Windows::Forms::Button^ button516;
	private: System::Windows::Forms::Button^ button517;
	private: System::Windows::Forms::Button^ button518;
	private: System::Windows::Forms::Button^ button519;
	private: System::Windows::Forms::Button^ button520;
	private: System::Windows::Forms::Button^ button521;
	private: System::Windows::Forms::Button^ button522;
	private: System::Windows::Forms::Button^ button523;
	private: System::Windows::Forms::Button^ button524;
	private: System::Windows::Forms::Button^ button525;

	private: int moveCounter = 0;
	private: int secondsElapsed = 0;

	private: System::Windows::Forms::Button^ buttonPause;

	private: array<System::Windows::Forms::Button^>^ allButtons;

	private: Button^ highlightedButton = nullptr;
	private: System::Windows::Forms::Label^ label1;
	private: Form^ mainForm;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {

			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->feedbackTimer = (gcnew System::Windows::Forms::Timer(this->components)); 
			   this->buttonFinish = (gcnew System::Windows::Forms::Button());
			   this->moveCounterLabel = (gcnew System::Windows::Forms::Label());
			   this->timerLabel = (gcnew System::Windows::Forms::Label());
			   this->button51 = (gcnew System::Windows::Forms::Button());
			   this->button52 = (gcnew System::Windows::Forms::Button());
			   this->button53 = (gcnew System::Windows::Forms::Button());
			   this->button54 = (gcnew System::Windows::Forms::Button());
			   this->button55 = (gcnew System::Windows::Forms::Button());
			   this->button56 = (gcnew System::Windows::Forms::Button());
			   this->button57 = (gcnew System::Windows::Forms::Button());
			   this->button58 = (gcnew System::Windows::Forms::Button());
			   this->button59 = (gcnew System::Windows::Forms::Button());
			   this->button510 = (gcnew System::Windows::Forms::Button());
			   this->button511 = (gcnew System::Windows::Forms::Button());
			   this->button512 = (gcnew System::Windows::Forms::Button());
			   this->button513 = (gcnew System::Windows::Forms::Button());
			   this->button514 = (gcnew System::Windows::Forms::Button());
			   this->button515 = (gcnew System::Windows::Forms::Button());
			   this->button516 = (gcnew System::Windows::Forms::Button());
			   this->button517 = (gcnew System::Windows::Forms::Button());
			   this->button518 = (gcnew System::Windows::Forms::Button());
			   this->button519 = (gcnew System::Windows::Forms::Button());
			   this->button520 = (gcnew System::Windows::Forms::Button());
			   this->button521 = (gcnew System::Windows::Forms::Button());
			   this->button522 = (gcnew System::Windows::Forms::Button());
			   this->button523 = (gcnew System::Windows::Forms::Button());
			   this->button524 = (gcnew System::Windows::Forms::Button());
			   this->button525 = (gcnew System::Windows::Forms::Button());
			   this->buttonPause = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   //
			   // timer
			   //
			   this->timer->Interval = 1000;
			   this->timer->Tick += gcnew System::EventHandler(this, &Fift5::timer_Tick);
			   //
			   // feedbackTimer
			   //
			   this->feedbackTimer->Interval = 200; 
			   this->feedbackTimer->Tick += gcnew System::EventHandler(this, &Fift5::feedbackTimer_Tick);
			   this->feedbackTimer->Tag = nullptr; 
			   //
			   // buttonFinish
			   //
			   this->buttonFinish->Location = System::Drawing::Point(449, 501);
			   this->buttonFinish->Name = L"buttonFinish";
			   this->buttonFinish->Size = System::Drawing::Size(100, 40);
			   this->buttonFinish->TabIndex = 27;
			   this->buttonFinish->Text = L"Выход";
			   this->buttonFinish->Click += gcnew System::EventHandler(this, &Fift5::buttonFinish_Click);
			   //
			   // moveCounterLabel
			   //
			   this->moveCounterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->moveCounterLabel->Location = System::Drawing::Point(22, 85);
			   this->moveCounterLabel->Name = L"moveCounterLabel";
			   this->moveCounterLabel->Size = System::Drawing::Size(130, 34);
			   this->moveCounterLabel->TabIndex = 26;
			   this->moveCounterLabel->Text = L"Ходы: 0";
			   this->moveCounterLabel->Click += gcnew System::EventHandler(this, &Fift5::moveCounterLabel_Click);
			   //
			   // timerLabel
			   //
			   this->timerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->timerLabel->Location = System::Drawing::Point(182, 85);
			   this->timerLabel->Name = L"timerLabel";
			   this->timerLabel->Size = System::Drawing::Size(126, 34);
			   this->timerLabel->TabIndex = 25;
			   this->timerLabel->Text = L"Время: 0с";
			   this->timerLabel->Click += gcnew System::EventHandler(this, &Fift5::timerLabel_Click);
			   //
			   // button51
			   //
			   this->button51->Location = System::Drawing::Point(27, 141); this->button51->Name = L"button51"; this->button51->Size = System::Drawing::Size(80, 80); this->button51->TabIndex = 0; this->button51->Text = L"1"; this->button51->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button52->Location = System::Drawing::Point(107, 141); this->button52->Name = L"button52"; this->button52->Size = System::Drawing::Size(80, 80); this->button52->TabIndex = 1; this->button52->Text = L"2"; this->button52->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button53->Location = System::Drawing::Point(187, 141); this->button53->Name = L"button53"; this->button53->Size = System::Drawing::Size(80, 80); this->button53->TabIndex = 2; this->button53->Text = L"3"; this->button53->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button54->Location = System::Drawing::Point(267, 141); this->button54->Name = L"button54"; this->button54->Size = System::Drawing::Size(80, 80); this->button54->TabIndex = 3; this->button54->Text = L"4"; this->button54->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button55->Location = System::Drawing::Point(347, 141); this->button55->Name = L"button55"; this->button55->Size = System::Drawing::Size(80, 80); this->button55->TabIndex = 4; this->button55->Text = L"5"; this->button55->Click += gcnew System::EventHandler(this, &Fift5::button_Click);

			   this->button56->Location = System::Drawing::Point(27, 221); this->button56->Name = L"button56"; this->button56->Size = System::Drawing::Size(80, 80); this->button56->TabIndex = 5; this->button56->Text = L"6"; this->button56->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button57->Location = System::Drawing::Point(107, 221); this->button57->Name = L"button57"; this->button57->Size = System::Drawing::Size(80, 80); this->button57->TabIndex = 6; this->button57->Text = L"7"; this->button57->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button58->Location = System::Drawing::Point(187, 221); this->button58->Name = L"button58"; this->button58->Size = System::Drawing::Size(80, 80); this->button58->TabIndex = 7; this->button58->Text = L"8"; this->button58->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button59->Location = System::Drawing::Point(267, 221); this->button59->Name = L"button59"; this->button59->Size = System::Drawing::Size(80, 80); this->button59->TabIndex = 8; this->button59->Text = L"9"; this->button59->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button510->Location = System::Drawing::Point(347, 221); this->button510->Name = L"button510"; this->button510->Size = System::Drawing::Size(80, 80); this->button510->TabIndex = 9; this->button510->Text = L"10"; this->button510->Click += gcnew System::EventHandler(this, &Fift5::button_Click);

			   this->button511->Location = System::Drawing::Point(27, 301); this->button511->Name = L"button511"; this->button511->Size = System::Drawing::Size(80, 80); this->button511->TabIndex = 10; this->button511->Text = L"11"; this->button511->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button512->Location = System::Drawing::Point(107, 301); this->button512->Name = L"button512"; this->button512->Size = System::Drawing::Size(80, 80); this->button512->TabIndex = 11; this->button512->Text = L"12"; this->button512->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button513->Location = System::Drawing::Point(187, 301); this->button513->Name = L"button513"; this->button513->Size = System::Drawing::Size(80, 80); this->button513->TabIndex = 12; this->button513->Text = L"13"; this->button513->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button514->Location = System::Drawing::Point(267, 301); this->button514->Name = L"button514"; this->button514->Size = System::Drawing::Size(80, 80); this->button514->TabIndex = 13; this->button514->Text = L"14"; this->button514->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button515->Location = System::Drawing::Point(347, 301); this->button515->Name = L"button515"; this->button515->Size = System::Drawing::Size(80, 80); this->button515->TabIndex = 14; this->button515->Text = L"15"; this->button515->Click += gcnew System::EventHandler(this, &Fift5::button_Click);

			   this->button516->Location = System::Drawing::Point(27, 381); this->button516->Name = L"button516"; this->button516->Size = System::Drawing::Size(80, 80); this->button516->TabIndex = 15; this->button516->Text = L"16"; this->button516->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button517->Location = System::Drawing::Point(107, 381); this->button517->Name = L"button517"; this->button517->Size = System::Drawing::Size(80, 80); this->button517->TabIndex = 16; this->button517->Text = L"17"; this->button517->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button518->Location = System::Drawing::Point(187, 381); this->button518->Name = L"button518"; this->button518->Size = System::Drawing::Size(80, 80); this->button518->TabIndex = 17; this->button518->Text = L"18"; this->button518->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button519->Location = System::Drawing::Point(267, 381); this->button519->Name = L"button519"; this->button519->Size = System::Drawing::Size(80, 80); this->button519->TabIndex = 18; this->button519->Text = L"19"; this->button519->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button520->Location = System::Drawing::Point(347, 381); this->button520->Name = L"button520"; this->button520->Size = System::Drawing::Size(80, 80); this->button520->TabIndex = 19; this->button520->Text = L"20"; this->button520->Click += gcnew System::EventHandler(this, &Fift5::button_Click);

			   this->button521->Location = System::Drawing::Point(27, 461); this->button521->Name = L"button521"; this->button521->Size = System::Drawing::Size(80, 80); this->button521->TabIndex = 20; this->button521->Text = L"21"; this->button521->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button522->Location = System::Drawing::Point(107, 461); this->button522->Name = L"button522"; this->button522->Size = System::Drawing::Size(80, 80); this->button522->TabIndex = 21; this->button522->Text = L"22"; this->button522->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button523->Location = System::Drawing::Point(187, 461); this->button523->Name = L"button523"; this->button523->Size = System::Drawing::Size(80, 80); this->button523->TabIndex = 22; this->button523->Text = L"23"; this->button523->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button524->Location = System::Drawing::Point(267, 461); this->button524->Name = L"button524"; this->button524->Size = System::Drawing::Size(80, 80); this->button524->TabIndex = 23; this->button524->Text = L"24"; this->button524->Click += gcnew System::EventHandler(this, &Fift5::button_Click);
			   this->button525->Location = System::Drawing::Point(347, 461); this->button525->Name = L"button525"; this->button525->Size = System::Drawing::Size(80, 80); this->button525->TabIndex = 24; this->button525->Text = L"25"; this->button525->Click += gcnew System::EventHandler(this, &Fift5::button_Click);


			   //
			   // buttonPause
			   //
			   this->buttonPause->Location = System::Drawing::Point(327, 75);
			   this->buttonPause->Name = L"buttonPause";
			   this->buttonPause->Size = System::Drawing::Size(100, 44);
			   this->buttonPause->TabIndex = 28;
			   this->buttonPause->Text = L"Пауза";
			   this->buttonPause->UseVisualStyleBackColor = true;
			   this->buttonPause->Click += gcnew System::EventHandler(this, &Fift5::buttonPause_Click);
			   //
			   // label1
			   //
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F));
			   this->label1->Location = System::Drawing::Point(241, 29);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(71, 45);
			   this->label1->TabIndex = 29;
			   this->label1->Text = L"5x5";
			   this->label1->Click += gcnew System::EventHandler(this, &Fift5::label1_Click);

			   //
			   // Fifteen5
			   //
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(582, 603);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->buttonPause);

			   this->Controls->Add(this->button51);
			   this->Controls->Add(this->button52);
			   this->Controls->Add(this->button53);
			   this->Controls->Add(this->button54);
			   this->Controls->Add(this->button55);
			   this->Controls->Add(this->button56);
			   this->Controls->Add(this->button57);
			   this->Controls->Add(this->button58);
			   this->Controls->Add(this->button59);
			   this->Controls->Add(this->button510);
			   this->Controls->Add(this->button511);
			   this->Controls->Add(this->button512);
			   this->Controls->Add(this->button513);
			   this->Controls->Add(this->button514);
			   this->Controls->Add(this->button515);
			   this->Controls->Add(this->button516);
			   this->Controls->Add(this->button517);
			   this->Controls->Add(this->button518);
			   this->Controls->Add(this->button519);
			   this->Controls->Add(this->button520);
			   this->Controls->Add(this->button521);
			   this->Controls->Add(this->button522);
			   this->Controls->Add(this->button523);
			   this->Controls->Add(this->button524);
			   this->Controls->Add(this->button525);
			   this->Controls->Add(this->timerLabel);
			   this->Controls->Add(this->moveCounterLabel);
			   this->Controls->Add(this->buttonFinish);

			   this->Name = L"Fifteen5";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Пятнашки 5x5";

			   this->ResumeLayout(false);
			   this->PerformLayout();
		   }

#pragma endregion 


	private: System::Void feedbackTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		feedbackTimer->Stop();
		Button^ btn = safe_cast<Button^>(feedbackTimer->Tag);
		if (btn != nullptr) {
			btn->BackColor = System::Drawing::SystemColors::Control; 
		}
		feedbackTimer->Tag = nullptr; 
	}

	private: System::Void Init()
	{
		array<int>^ numbers = gcnew array<int>(25) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 }; 
		Random^ rand = gcnew Random();

		for (int i = 0; i < numbers->Length; ++i)
		{
			int j = rand->Next(numbers->Length);
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}

		allButtons = gcnew array<System::Windows::Forms::Button^>(25);
		allButtons[0] = button51;
		allButtons[1] = button52;
		allButtons[2] = button53;
		allButtons[3] = button54;
		allButtons[4] = button55; 
		allButtons[5] = button56;
		allButtons[6] = button57;
		allButtons[7] = button58;
		allButtons[8] = button59;
		allButtons[9] = button510; 
		allButtons[10] = button511; 
		allButtons[11] = button512;
		allButtons[12] = button513;
		allButtons[13] = button514;
		allButtons[14] = button515; 
		allButtons[15] = button516; 
		allButtons[16] = button517;
		allButtons[17] = button518;
		allButtons[18] = button519;
		allButtons[19] = button520; 
		allButtons[20] = button521; 
		allButtons[21] = button522;
		allButtons[22] = button523;
		allButtons[23] = button524;
		allButtons[24] = button525; 


		// Установка текста для кнопок с использованием массива allButtons и перемешанных чисел
		for (int i = 0; i < allButtons->Length; ++i)
		{
			allButtons[i]->Text = numbers[i] == 25 ? "" : numbers[i].ToString(); 
		}

		moveCounter = 0;
		secondsElapsed = 0;
		moveCounterLabel->Text = "Ходы: 0";
		timerLabel->Text = "Время: 0с";
		timer->Start(); 
	}

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (!timer->Enabled) {
			return; 
		}

		Button^ clickedButton = safe_cast<Button^>(sender);
		int clickedIndex = -1;
		int emptyIndex = -1;

		// Находим индексы нажатой кнопки и пустой ячейки, перебирая массив allButtons (0-24).
		for (int i = 0; i < allButtons->Length; ++i)
		{
			if (allButtons[i] == clickedButton)
			{
				clickedIndex = i;
			}
			if (allButtons[i]->Text == "")
			{
				emptyIndex = i;
			}
		
			if (clickedIndex != -1 && emptyIndex != -1) break;
		}

		if (clickedIndex == -1 || emptyIndex == -1) return;

		int clickedRow = clickedIndex / 5; 
		int clickedCol = clickedIndex % 5; 
		int emptyRow = emptyIndex / 5;
		int emptyCol = emptyIndex % 5;

		if ((clickedRow == emptyRow && Math::Abs(clickedCol - emptyCol) == 1) ||
			(clickedCol == emptyCol && Math::Abs(clickedRow - emptyRow) == 1))
		{
			Button^ emptyButton = allButtons[emptyIndex]; 
			emptyButton->Text = clickedButton->Text; 
			clickedButton->Text = ""; 
		
			moveCounter++;
			moveCounterLabel->Text = "Ходы: " + moveCounter.ToString();

			bool win = true;
			for (int i = 0; i < allButtons->Length - 1; ++i)
			{
				if (allButtons[i]->Text != (i + 1).ToString())
				{
					win = false;
					break; 
				}
			}
			if (win && allButtons[24]->Text == "") 
			{
				timer->Stop();
				MessageBox::Show("Поздравляем! Вы собрали пятнашки за " + secondsElapsed + " секунд и " + moveCounter + " ходов!", "Победа!");
				GameWon(this, secondsElapsed); 
				Init(); 
			}
		}
		else 
		{

			if (clickedButton->Text != "") {
				clickedButton->BackColor = System::Drawing::Color::Red;
				feedbackTimer->Tag = clickedButton;
				feedbackTimer->Start(); 
			}
		}
	}
		
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		secondsElapsed++;
		timerLabel->Text = "Время: " + secondsElapsed.ToString() + "с";
	}

	private: System::Void buttonFinish_Click(System::Object^ sender, System::EventArgs^ e)
	{

		timer->Stop();
		this->Hide();
		mainForm->Show();
	}

	private: System::Void buttonPause_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Stop();
		PauseM^ menu = gcnew PauseM("5x5"); 
		menu->Owner = this; 

		System::Windows::Forms::DialogResult result = menu->ShowDialog(); 

		if (result == System::Windows::Forms::DialogResult::OK) {
	
			timer->Start();
		}
		else if (result == System::Windows::Forms::DialogResult::Abort) {

			this->Hide();
			mainForm->Show();
		}

	}

	private: System::Void moveCounterLabel_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timerLabel_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}


	};
}