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

	public ref class Fift3 : public System::Windows::Forms::Form
	{
	public:
		Fift3(Form^ main)
		{
			mainForm = main;
			InitializeComponent();
			Init();
		}

	protected:
		~Fift3()
		{
			if (components)
			{
				delete components;
			}
		}
	public: event EventHandler<int>^ GameWon;

	private: System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::Button^ buttonFinish;
	private: System::Windows::Forms::Label^ moveCounterLabel;
	private: System::Windows::Forms::Label^ timerLabel;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Timer^ feedbackTimer; 

		   // кнопки игрового поля 3x3 (button31 ... button39)
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button39;

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
			   this->button31 = (gcnew System::Windows::Forms::Button());
			   this->button32 = (gcnew System::Windows::Forms::Button());
			   this->button33 = (gcnew System::Windows::Forms::Button());
			   this->button34 = (gcnew System::Windows::Forms::Button());
			   this->button35 = (gcnew System::Windows::Forms::Button());
			   this->button36 = (gcnew System::Windows::Forms::Button());
			   this->button37 = (gcnew System::Windows::Forms::Button());
			   this->button38 = (gcnew System::Windows::Forms::Button());
			   this->button39 = (gcnew System::Windows::Forms::Button());
			   this->buttonPause = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   //
			   // timer
			   //
			   this->timer->Interval = 1000;
			   this->timer->Tick += gcnew System::EventHandler(this, &Fift3::timer_Tick);
			   //
			   // feedbackTimer
			   //
			   this->feedbackTimer->Interval = 200; 
			   this->feedbackTimer->Tick += gcnew System::EventHandler(this, &Fift3::feedbackTimer_Tick);
			   this->feedbackTimer->Tag = nullptr; 
			   //
			   // buttonFinish
			   //
			   this->buttonFinish->Location = System::Drawing::Point(286, 300);
			   this->buttonFinish->Name = L"buttonFinish";
			   this->buttonFinish->Size = System::Drawing::Size(100, 40);
			   this->buttonFinish->TabIndex = 18;
			   this->buttonFinish->Text = L"Выход";
			   this->buttonFinish->Click += gcnew System::EventHandler(this, &Fift3::buttonFinish_Click);
			   //
			   // moveCounterLabel
			   //
			   this->moveCounterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->moveCounterLabel->Location = System::Drawing::Point(12, 60);
			   this->moveCounterLabel->Name = L"moveCounterLabel";
			   this->moveCounterLabel->Size = System::Drawing::Size(109, 30);
			   this->moveCounterLabel->TabIndex = 17;
			   this->moveCounterLabel->Text = L"Ходы: 0";
			   //
			   // timerLabel
			   //
			   this->timerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->timerLabel->Location = System::Drawing::Point(135, 60);
			   this->timerLabel->Name = L"timerLabel";
			   this->timerLabel->Size = System::Drawing::Size(145, 30);
			   this->timerLabel->TabIndex = 16;
			   this->timerLabel->Text = L"Время: 0с";
			   //
			   // button31
			   //
			   this->button31->Location = System::Drawing::Point(20, 100);
			   this->button31->Name = L"button31";
			   this->button31->Size = System::Drawing::Size(80, 80);
			   this->button31->TabIndex = 0;
			   this->button31->Text = L"1";
			   this->button31->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button32
			   //
			   this->button32->Location = System::Drawing::Point(100, 100);
			   this->button32->Name = L"button32";
			   this->button32->Size = System::Drawing::Size(80, 80);
			   this->button32->TabIndex = 1;
			   this->button32->Text = L"2";
			   this->button32->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button33
			   //
			   this->button33->Location = System::Drawing::Point(180, 100);
			   this->button33->Name = L"button33";
			   this->button33->Size = System::Drawing::Size(80, 80);
			   this->button33->TabIndex = 2;
			   this->button33->Text = L"3";
			   this->button33->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button34
			   //
			   this->button34->Location = System::Drawing::Point(20, 180);
			   this->button34->Name = L"button34";
			   this->button34->Size = System::Drawing::Size(80, 80);
			   this->button34->TabIndex = 3;
			   this->button34->Text = L"4";
			   this->button34->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button35
			   //
			   this->button35->Location = System::Drawing::Point(100, 180);
			   this->button35->Name = L"button35";
			   this->button35->Size = System::Drawing::Size(80, 80);
			   this->button35->TabIndex = 4;
			   this->button35->Text = L"5";
			   this->button35->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button36
			   //
			   this->button36->Location = System::Drawing::Point(180, 180);
			   this->button36->Name = L"button36";
			   this->button36->Size = System::Drawing::Size(80, 80);
			   this->button36->TabIndex = 5;
			   this->button36->Text = L"6";
			   this->button36->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button37
			   //
			   this->button37->Location = System::Drawing::Point(20, 260);
			   this->button37->Name = L"button37";
			   this->button37->Size = System::Drawing::Size(80, 80);
			   this->button37->TabIndex = 6;
			   this->button37->Text = L"7";
			   this->button37->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button38
			   //
			   this->button38->Location = System::Drawing::Point(100, 260);
			   this->button38->Name = L"button38";
			   this->button38->Size = System::Drawing::Size(80, 80);
			   this->button38->TabIndex = 7;
			   this->button38->Text = L"8";
			   this->button38->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // button39
			   //
			   this->button39->Location = System::Drawing::Point(180, 260);
			   this->button39->Name = L"button39";
			   this->button39->Size = System::Drawing::Size(80, 80);
			   this->button39->TabIndex = 8;
			   this->button39->Text = L"9";
			   this->button39->Click += gcnew System::EventHandler(this, &Fift3::button_Click);
			   //
			   // buttonPause
			   //
			   this->buttonPause->Location = System::Drawing::Point(286, 60);
			   this->buttonPause->Name = L"buttonPause";
			   this->buttonPause->Size = System::Drawing::Size(80, 35);
			   this->buttonPause->TabIndex = 19;
			   this->buttonPause->Text = L"Пауза";
			   this->buttonPause->UseVisualStyleBackColor = true;
			   this->buttonPause->Click += gcnew System::EventHandler(this, &Fift3::buttonPause_Click);
			   //
			   // label1
			   //
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F));
			   this->label1->Location = System::Drawing::Point(120, 10);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(71, 45);
			   this->label1->TabIndex = 20;
			   this->label1->Text = L"3x3";
			   //
			   // Fift3
			   //
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(393, 380);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->buttonPause);
			   this->Controls->Add(this->button31);
			   this->Controls->Add(this->button32);
			   this->Controls->Add(this->button33);
			   this->Controls->Add(this->button34);
			   this->Controls->Add(this->button35);
			   this->Controls->Add(this->button36);
			   this->Controls->Add(this->button37);
			   this->Controls->Add(this->button38);
			   this->Controls->Add(this->button39);
			   this->Controls->Add(this->timerLabel);
			   this->Controls->Add(this->moveCounterLabel);
			   this->Controls->Add(this->buttonFinish);
			   this->Name = L"Fift3";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Пятнашки 3x3";
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
		// Инициализация массива чисел (1-9 для 3x3)
		array<int>^ numbers = gcnew array<int>(9) { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		Random^ rand = gcnew Random();

		// Перемешивание чисел
		for (int i = 0; i < numbers->Length; ++i)
		{
			int j = rand->Next(numbers->Length);
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}

		allButtons = gcnew array<System::Windows::Forms::Button^>(9);
		allButtons[0] = button31;
		allButtons[1] = button32;
		allButtons[2] = button33;
		allButtons[3] = button34;
		allButtons[4] = button35;
		allButtons[5] = button36;
		allButtons[6] = button37;
		allButtons[7] = button38;
		allButtons[8] = button39;

		// Установка текста для кнопок
		for (int i = 0; i < allButtons->Length; ++i)
		{
			allButtons[i]->Text = numbers[i] == 9 ? "" : numbers[i].ToString();
		}

		moveCounter = 0;
		secondsElapsed = 0;
		moveCounterLabel->Text = "Ходы: 0";
		timerLabel->Text = "Время: 0с";
		timer->Start();
	}

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Проверка на паузу
		if (!timer->Enabled) {
			return; 
		}

		Button^ clickedButton = safe_cast<Button^>(sender);
		int clickedIndex = -1;
		int emptyIndex = -1;

		// Находим индексы нажатой кнопки и пустой ячейки
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

		int clickedRow = clickedIndex / 3;
		int clickedCol = clickedIndex % 3;
		int emptyRow = emptyIndex / 3;
		int emptyCol = emptyIndex % 3;

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
			if (win && allButtons[8]->Text == "") 
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

		PauseM^ menu = gcnew PauseM("3x3");
		menu->Owner = this;

		System::Windows::Forms::DialogResult result = menu->ShowDialog();

		if (result == System::Windows::Forms::DialogResult::OK)
		{
			timer->Start();
		}
		else if (result == System::Windows::Forms::DialogResult::Abort)
		{
			this->Hide();
			mainForm->Show();
		}
	}

	private: System::Void timerLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}