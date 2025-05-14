#pragma once

#include "PauseM.h"
#using <System.dll>

using namespace System::Diagnostics;
namespace Fift {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Fift4 : public System::Windows::Forms::Form
	{
	public:
		Fift4(Form^ main)
		{
			mainForm = main;
			InitializeComponent();
			Init();
		}

	protected:
		~Fift4()
		{
			if (components)
			{
				delete components;
			}
		}
	public: event EventHandler<int>^ GameWon;
	private:System::ComponentModel::IContainer^ components;

	private: System::Windows::Forms::Button^ buttonFinish;
	private: System::Windows::Forms::Label^ moveCounterLabel;
	private: System::Windows::Forms::Label^ timerLabel;
	private: System::Windows::Forms::Timer^ timer;

	private: System::Windows::Forms::Timer^ feedbackTimer;


		   // кнопки игрового поля 4x4 (button41 ... button416)
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button44;
	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::Button^ button49;
	private: System::Windows::Forms::Button^ button410;
	private: System::Windows::Forms::Button^ button411;
	private: System::Windows::Forms::Button^ button412;
	private: System::Windows::Forms::Button^ button413;
	private: System::Windows::Forms::Button^ button414;
	private: System::Windows::Forms::Button^ button415;
	private: System::Windows::Forms::Button^ button416;

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
			   this->button41 = (gcnew System::Windows::Forms::Button());
			   this->button42 = (gcnew System::Windows::Forms::Button());
			   this->button43 = (gcnew System::Windows::Forms::Button());
			   this->button44 = (gcnew System::Windows::Forms::Button());
			   this->button45 = (gcnew System::Windows::Forms::Button());
			   this->button46 = (gcnew System::Windows::Forms::Button());
			   this->button47 = (gcnew System::Windows::Forms::Button());
			   this->button48 = (gcnew System::Windows::Forms::Button());
			   this->button49 = (gcnew System::Windows::Forms::Button());
			   this->button410 = (gcnew System::Windows::Forms::Button());
			   this->button411 = (gcnew System::Windows::Forms::Button());
			   this->button412 = (gcnew System::Windows::Forms::Button());
			   this->button413 = (gcnew System::Windows::Forms::Button());
			   this->button414 = (gcnew System::Windows::Forms::Button());
			   this->button415 = (gcnew System::Windows::Forms::Button());
			   this->button416 = (gcnew System::Windows::Forms::Button());
			   this->buttonPause = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   //
			   // timer
			   //
			   this->timer->Interval = 1000;
			   this->timer->Tick += gcnew System::EventHandler(this, &Fift4::timer_Tick);
			   //
			   // feedbackTimer
			   //
			   this->feedbackTimer->Interval = 200;
			   this->feedbackTimer->Tick += gcnew System::EventHandler(this, &Fift4::feedbackTimer_Tick);
			   //
			   // buttonFinish
			   //
			   this->buttonFinish->Location = System::Drawing::Point(345, 419);
			   this->buttonFinish->Name = L"buttonFinish";
			   this->buttonFinish->Size = System::Drawing::Size(100, 40);
			   this->buttonFinish->TabIndex = 18;
			   this->buttonFinish->Text = L"Выход";
			   this->buttonFinish->Click += gcnew System::EventHandler(this, &Fift4::buttonFinish_Click);
			   //
			   // moveCounterLabel
			   //
			   this->moveCounterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->moveCounterLabel->Location = System::Drawing::Point(16, 92);
			   this->moveCounterLabel->Name = L"moveCounterLabel";
			   this->moveCounterLabel->Size = System::Drawing::Size(109, 30);
			   this->moveCounterLabel->TabIndex = 17;
			   this->moveCounterLabel->Text = L"Ходы: 0";
			   this->moveCounterLabel->Click += gcnew System::EventHandler(this, &Fift4::timerLabel_Click);
			   //
			   // timerLabel
			   //
			   this->timerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->timerLabel->Location = System::Drawing::Point(120, 92);
			   this->timerLabel->Name = L"timerLabel";
			   this->timerLabel->Size = System::Drawing::Size(116, 30);
			   this->timerLabel->TabIndex = 16;
			   this->timerLabel->Text = L"Время: 0с";
			   this->timerLabel->Click += gcnew System::EventHandler(this, &Fift4::timerLabel_Click);
			   //
			   // button41
			   //
			   this->button41->Location = System::Drawing::Point(19, 139);
			   this->button41->Name = L"button41";
			   this->button41->Size = System::Drawing::Size(80, 80);
			   this->button41->TabIndex = 0;
			   this->button41->Text = L"1";
			   this->button41->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button42
			   //
			   this->button42->Location = System::Drawing::Point(99, 139);
			   this->button42->Name = L"button42";
			   this->button42->Size = System::Drawing::Size(80, 80);
			   this->button42->TabIndex = 1;
			   this->button42->Text = L"2";
			   this->button42->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button43
			   //
			   this->button43->Location = System::Drawing::Point(179, 139);
			   this->button43->Name = L"button43";
			   this->button43->Size = System::Drawing::Size(80, 80);
			   this->button43->TabIndex = 2;
			   this->button43->Text = L"3";
			   this->button43->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button44
			   //
			   this->button44->Location = System::Drawing::Point(259, 139);
			   this->button44->Name = L"button44";
			   this->button44->Size = System::Drawing::Size(80, 80);
			   this->button44->TabIndex = 3;
			   this->button44->Text = L"4";
			   this->button44->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button45
			   //
			   this->button45->Location = System::Drawing::Point(19, 219);
			   this->button45->Name = L"button45";
			   this->button45->Size = System::Drawing::Size(80, 80);
			   this->button45->TabIndex = 4;
			   this->button45->Text = L"5";
			   this->button45->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button46
			   //
			   this->button46->Location = System::Drawing::Point(99, 219);
			   this->button46->Name = L"button46";
			   this->button46->Size = System::Drawing::Size(80, 80);
			   this->button46->TabIndex = 5;
			   this->button46->Text = L"6";
			   this->button46->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button47
			   //
			   this->button47->Location = System::Drawing::Point(179, 219);
			   this->button47->Name = L"button47";
			   this->button47->Size = System::Drawing::Size(80, 80);
			   this->button47->TabIndex = 6;
			   this->button47->Text = L"7";
			   this->button47->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button48
			   //
			   this->button48->Location = System::Drawing::Point(259, 219);
			   this->button48->Name = L"button48";
			   this->button48->Size = System::Drawing::Size(80, 80);
			   this->button48->TabIndex = 7;
			   this->button48->Text = L"8";
			   this->button48->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button49
			   //
			   this->button49->Location = System::Drawing::Point(19, 299);
			   this->button49->Name = L"button49";
			   this->button49->Size = System::Drawing::Size(80, 80);
			   this->button49->TabIndex = 8;
			   this->button49->Text = L"9";
			   this->button49->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button410
			   //
			   this->button410->Location = System::Drawing::Point(99, 299);
			   this->button410->Name = L"button410";
			   this->button410->Size = System::Drawing::Size(80, 80);
			   this->button410->TabIndex = 9;
			   this->button410->Text = L"10";
			   this->button410->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button411
			   //
			   this->button411->Location = System::Drawing::Point(259, 299);
			   this->button411->Name = L"button411";
			   this->button411->Size = System::Drawing::Size(80, 80);
			   this->button411->TabIndex = 10;
			   this->button411->Text = L"11";
			   this->button411->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button412
			   //
			   this->button412->Location = System::Drawing::Point(179, 299);
			   this->button412->Name = L"button412";
			   this->button412->Size = System::Drawing::Size(80, 80);
			   this->button412->TabIndex = 11;
			   this->button412->Text = L"12";
			   this->button412->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button413
			   //
			   this->button413->Location = System::Drawing::Point(19, 379);
			   this->button413->Name = L"button413";
			   this->button413->Size = System::Drawing::Size(80, 80);
			   this->button413->TabIndex = 12;
			   this->button413->Text = L"13";
			   this->button413->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button414
			   //
			   this->button414->Location = System::Drawing::Point(99, 379);
			   this->button414->Name = L"button414";
			   this->button414->Size = System::Drawing::Size(80, 80);
			   this->button414->TabIndex = 13;
			   this->button414->Text = L"14";
			   this->button414->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button415
			   //
			   this->button415->Location = System::Drawing::Point(179, 379);
			   this->button415->Name = L"button415";
			   this->button415->Size = System::Drawing::Size(80, 80);
			   this->button415->TabIndex = 14;
			   this->button415->Text = L"15";
			   this->button415->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // button416
			   //
			   this->button416->Location = System::Drawing::Point(259, 379);
			   this->button416->Name = L"button416";
			   this->button416->Size = System::Drawing::Size(80, 80);
			   this->button416->TabIndex = 15;
			   this->button416->Text = L"16";
			   this->button416->Click += gcnew System::EventHandler(this, &Fift4::button_Click);
			   //
			   // buttonPause
			   //
			   this->buttonPause->Location = System::Drawing::Point(242, 83);
			   this->buttonPause->Name = L"buttonPause";
			   this->buttonPause->Size = System::Drawing::Size(97, 39);
			   this->buttonPause->TabIndex = 19;
			   this->buttonPause->Text = L"Пауза";
			   this->buttonPause->UseVisualStyleBackColor = true;
			   this->buttonPause->Click += gcnew System::EventHandler(this, &Fift4::buttonPause_Click);
			   //
			   // label1
			   //
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F));
			   this->label1->Location = System::Drawing::Point(188, 19);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(71, 45);
			   this->label1->TabIndex = 20;
			   this->label1->Text = L"4x4";
			   this->label1->Click += gcnew System::EventHandler(this, &Fift4::label1_Click);
			   //
			   // Fift4
			   //
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(482, 503);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->buttonPause);
			   this->Controls->Add(this->button41);
			   this->Controls->Add(this->button42);
			   this->Controls->Add(this->button43);
			   this->Controls->Add(this->button44);
			   this->Controls->Add(this->button45);
			   this->Controls->Add(this->button46);
			   this->Controls->Add(this->button47);
			   this->Controls->Add(this->button48);
			   this->Controls->Add(this->button49);
			   this->Controls->Add(this->button410);
			   this->Controls->Add(this->button411);
			   this->Controls->Add(this->button412);
			   this->Controls->Add(this->button413);
			   this->Controls->Add(this->button414);
			   this->Controls->Add(this->button415);
			   this->Controls->Add(this->button416);
			   this->Controls->Add(this->timerLabel);
			   this->Controls->Add(this->moveCounterLabel);
			   this->Controls->Add(this->buttonFinish);
			   this->Name = L"Fift4";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Пятнашки 4x4";
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
		// Инициализация массива чисел для перемешивания
		array<int>^ numbers = gcnew array<int>(16) { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
		Random^ rand = gcnew Random();

		// Перемешивание массива чисел 
		for (int i = 0; i < numbers->Length; ++i)
		{
			int j = rand->Next(numbers->Length);
			int temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}

		allButtons = gcnew array<System::Windows::Forms::Button^>(16);
		allButtons[0] = button41; 
		allButtons[1] = button42; 
		allButtons[2] = button43; 
		allButtons[3] = button44; 
		allButtons[4] = button45; 
		allButtons[5] = button46;
		allButtons[6] = button47; 
		allButtons[7] = button48; 
		allButtons[8] = button49; 
		allButtons[9] = button410; 
		allButtons[10] = button412;
		allButtons[11] = button411;
		allButtons[12] = button413; 
		allButtons[13] = button414; 
		allButtons[14] = button415; 
		allButtons[15] = button416; 

		System::Diagnostics::Debug::WriteLine("--- Checking allButtons array mapping ---");
		for (int i = 0; i < allButtons->Length; ++i)
		{
			Button^ btn = allButtons[i];
			int expectedRow = i / 4;
			int expectedCol = i % 4;
			if (btn != nullptr) {
				String^ debugMessage = String::Format(
					"Index {0} (Expected Pos: Row {4}, Col {5}): Button Name = {1}, Current Text = '{2}', Location = ({3})",
					i, btn->Name, btn->Text, btn->Location.ToString(), expectedRow, expectedCol);
				System::Diagnostics::Debug::WriteLine(debugMessage);
			}
			else {
				System::Diagnostics::Debug::WriteLine(String::Format("Index {0}: Button is null!", i));
			}
		}
		System::Diagnostics::Debug::WriteLine("--- End of allButtons array check ---");

		for (int i = 0; i < allButtons->Length; ++i)
		{
			allButtons[i]->Text = numbers[i] == 16 ? "" : numbers[i].ToString();
		}

		// Сброс счетчиков и запуск таймера
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

		// Находим индексы нажатой кнопки и пустой кнопки в массиве allButtons
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

		int clickedRow = clickedIndex / 4;
		int clickedCol = clickedIndex % 4;
		int emptyRow = emptyIndex / 4;
		int emptyCol = emptyIndex % 4;

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
			if (win && allButtons[15]->Text == "") 
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

		PauseM^ menu = gcnew PauseM("4x4");
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

#pragma endregion // Конец сгенерированного дизайнером кода
	};
}