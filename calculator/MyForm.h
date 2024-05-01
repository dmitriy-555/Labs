#pragma once
#include <iostream>

unsigned long long factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ mod_button;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ clearMain_button;

	private: System::Windows::Forms::Button^ rightClear_button;

	private: System::Windows::Forms::Button^ leftClear_button;

	private: System::Windows::Forms::Button^ rightDeg_button;

	private: System::Windows::Forms::Button^ leftDeg_button;

	private: System::Windows::Forms::Button^ rightFact_button;

	private: System::Windows::Forms::Button^ leftFact_button;

	private: System::Windows::Forms::Button^ multiply_button;
	private: System::Windows::Forms::Button^ divide_button;


	private: System::Windows::Forms::Button^ minus_button;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ plus_button;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mod_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->clearMain_button = (gcnew System::Windows::Forms::Button());
			this->rightClear_button = (gcnew System::Windows::Forms::Button());
			this->leftClear_button = (gcnew System::Windows::Forms::Button());
			this->rightDeg_button = (gcnew System::Windows::Forms::Button());
			this->leftDeg_button = (gcnew System::Windows::Forms::Button());
			this->rightFact_button = (gcnew System::Windows::Forms::Button());
			this->leftFact_button = (gcnew System::Windows::Forms::Button());
			this->multiply_button = (gcnew System::Windows::Forms::Button());
			this->divide_button = (gcnew System::Windows::Forms::Button());
			this->minus_button = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->plus_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(12, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(271, 23);
			this->label2->TabIndex = 48;
			this->label2->Text = L"0";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// mod_button
			// 
			this->mod_button->ForeColor = System::Drawing::SystemColors::InfoText;
			this->mod_button->Location = System::Drawing::Point(12, 240);
			this->mod_button->Name = L"mod_button";
			this->mod_button->Size = System::Drawing::Size(132, 23);
			this->mod_button->TabIndex = 47;
			this->mod_button->Text = L"% (mod left)";
			this->mod_button->UseVisualStyleBackColor = true;
			this->mod_button->Click += gcnew System::EventHandler(this, &MyForm::mod_button_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(141, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 20);
			this->label1->TabIndex = 46;
			// 
			// clearMain_button
			// 
			this->clearMain_button->BackColor = System::Drawing::SystemColors::ControlLight;
			this->clearMain_button->ForeColor = System::Drawing::Color::Crimson;
			this->clearMain_button->Location = System::Drawing::Point(151, 240);
			this->clearMain_button->Name = L"clearMain_button";
			this->clearMain_button->Size = System::Drawing::Size(132, 23);
			this->clearMain_button->TabIndex = 45;
			this->clearMain_button->Text = L"clear main";
			this->clearMain_button->UseVisualStyleBackColor = false;
			this->clearMain_button->Click += gcnew System::EventHandler(this, &MyForm::clearMain_button_Click);
			// 
			// rightClear_button
			// 
			this->rightClear_button->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->rightClear_button->Location = System::Drawing::Point(151, 211);
			this->rightClear_button->Name = L"rightClear_button";
			this->rightClear_button->Size = System::Drawing::Size(132, 23);
			this->rightClear_button->TabIndex = 44;
			this->rightClear_button->Text = L"clear right";
			this->rightClear_button->UseVisualStyleBackColor = true;
			this->rightClear_button->Click += gcnew System::EventHandler(this, &MyForm::rightClear_button_Click);
			// 
			// leftClear_button
			// 
			this->leftClear_button->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->leftClear_button->Location = System::Drawing::Point(12, 211);
			this->leftClear_button->Name = L"leftClear_button";
			this->leftClear_button->Size = System::Drawing::Size(132, 23);
			this->leftClear_button->TabIndex = 43;
			this->leftClear_button->Text = L"clear left";
			this->leftClear_button->UseVisualStyleBackColor = true;
			this->leftClear_button->Click += gcnew System::EventHandler(this, &MyForm::leftClear_button_Click);
			// 
			// rightDeg_button
			// 
			this->rightDeg_button->Location = System::Drawing::Point(151, 182);
			this->rightDeg_button->Name = L"rightDeg_button";
			this->rightDeg_button->Size = System::Drawing::Size(132, 23);
			this->rightDeg_button->TabIndex = 42;
			this->rightDeg_button->Text = L"rigth^left";
			this->rightDeg_button->UseVisualStyleBackColor = true;
			this->rightDeg_button->Click += gcnew System::EventHandler(this, &MyForm::rightDeg_button_Click);
			// 
			// leftDeg_button
			// 
			this->leftDeg_button->Location = System::Drawing::Point(12, 181);
			this->leftDeg_button->Name = L"leftDeg_button";
			this->leftDeg_button->Size = System::Drawing::Size(132, 24);
			this->leftDeg_button->TabIndex = 41;
			this->leftDeg_button->Text = L"left^right";
			this->leftDeg_button->UseVisualStyleBackColor = true;
			this->leftDeg_button->Click += gcnew System::EventHandler(this, &MyForm::leftDeg_button_Click);
			// 
			// rightFact_button
			// 
			this->rightFact_button->Location = System::Drawing::Point(151, 152);
			this->rightFact_button->Name = L"rightFact_button";
			this->rightFact_button->Size = System::Drawing::Size(132, 23);
			this->rightFact_button->TabIndex = 40;
			this->rightFact_button->Text = L"! for right";
			this->rightFact_button->UseVisualStyleBackColor = true;
			this->rightFact_button->Click += gcnew System::EventHandler(this, &MyForm::rightFact_button_Click);
			// 
			// leftFact_button
			// 
			this->leftFact_button->Location = System::Drawing::Point(12, 152);
			this->leftFact_button->Name = L"leftFact_button";
			this->leftFact_button->Size = System::Drawing::Size(132, 23);
			this->leftFact_button->TabIndex = 39;
			this->leftFact_button->Text = L"! for left";
			this->leftFact_button->UseVisualStyleBackColor = true;
			this->leftFact_button->Click += gcnew System::EventHandler(this, &MyForm::leftFact_button_Click);
			// 
			// multiply_button
			// 
			this->multiply_button->Location = System::Drawing::Point(12, 123);
			this->multiply_button->Name = L"multiply_button";
			this->multiply_button->Size = System::Drawing::Size(132, 23);
			this->multiply_button->TabIndex = 38;
			this->multiply_button->Text = L"*";
			this->multiply_button->UseVisualStyleBackColor = true;
			this->multiply_button->Click += gcnew System::EventHandler(this, &MyForm::multiply_button_Click);
			// 
			// divide_button
			// 
			this->divide_button->Location = System::Drawing::Point(151, 123);
			this->divide_button->Name = L"divide_button";
			this->divide_button->Size = System::Drawing::Size(132, 23);
			this->divide_button->TabIndex = 37;
			this->divide_button->Text = L"/";
			this->divide_button->UseVisualStyleBackColor = true;
			this->divide_button->Click += gcnew System::EventHandler(this, &MyForm::divide_button_Click);
			// 
			// minus_button
			// 
			this->minus_button->Location = System::Drawing::Point(151, 94);
			this->minus_button->Name = L"minus_button";
			this->minus_button->Size = System::Drawing::Size(132, 23);
			this->minus_button->TabIndex = 36;
			this->minus_button->Text = L"-";
			this->minus_button->UseVisualStyleBackColor = true;
			this->minus_button->Click += gcnew System::EventHandler(this, &MyForm::minus_button_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 59);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(123, 20);
			this->textBox2->TabIndex = 35;
			this->textBox2->Text = L"0";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 20);
			this->textBox1->TabIndex = 34;
			this->textBox1->Text = L"0";
			// 
			// plus_button
			// 
			this->plus_button->Location = System::Drawing::Point(12, 94);
			this->plus_button->Name = L"plus_button";
			this->plus_button->Size = System::Drawing::Size(132, 23);
			this->plus_button->TabIndex = 33;
			this->plus_button->Text = L"+";
			this->plus_button->UseVisualStyleBackColor = true;
			this->plus_button->Click += gcnew System::EventHandler(this, &MyForm::plus_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(294, 284);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->mod_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->clearMain_button);
			this->Controls->Add(this->rightClear_button);
			this->Controls->Add(this->leftClear_button);
			this->Controls->Add(this->rightDeg_button);
			this->Controls->Add(this->leftDeg_button);
			this->Controls->Add(this->rightFact_button);
			this->Controls->Add(this->leftFact_button);
			this->Controls->Add(this->multiply_button);
			this->Controls->Add(this->divide_button);
			this->Controls->Add(this->minus_button);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->plus_button);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);

		}
#pragma endregion
	private:

		Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			bool commaEntered = false;
			if ((!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 8) || (e->KeyChar == ',' && commaEntered)) {
				e->Handled = true; 
			}
			if (e->KeyChar == ',') {
				commaEntered = true;
			}
		}
		Void plus_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			res = num_left + num_right;
			label2->Text = res.ToString();
		}

		Void minus_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			res = num_left - num_right;
			label2->Text = res.ToString();
		}

		Void multiply_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			res = num_left * num_right;
			label2->Text = res.ToString();
		}

		Void divide_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			if (num_right == 0) {
				MessageBox::Show("ќшибка: ƒеление на ноль.");
				return;
			}
			res = num_left / num_right;
			label2->Text = res.ToString();
		}

		Void leftFact_button_Click(System::Object^ sender, System::EventArgs^ e) {
			int num;
			if (!Int32::TryParse(textBox1->Text, num) || num < 0)
			{
				MessageBox::Show("ќшибка: ¬ведите целое положительно число.");
				return;
			}
			unsigned long long res = factorial(num);
			label2->Text = res.ToString();
		}

		Void rightFact_button_Click(System::Object^ sender, System::EventArgs^ e) {
			int num;
			if (!Int32::TryParse(textBox2->Text, num) || num < 0)
			{
				MessageBox::Show("ќшибка: ¬ведите целое положительно число.");
				return;
			}
			unsigned long long res = factorial(num);
			label2->Text = res.ToString();
		}

		Void leftDeg_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			res = Math::Pow(num_left, num_right);
			label2->Text = res.ToString();
		}

		Void rightDeg_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			res = Math::Pow(num_right, num_left); 
			label2->Text = res.ToString();
		}

		Void leftClear_button_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text = "0";
		}

		Void rightClear_button_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox2->Text = "0";
		}

		Void clearMain_button_Click(System::Object^ sender, System::EventArgs^ e) {
			label2->Text = "0";
		}

		Void mod_button_Click(System::Object^ sender, System::EventArgs^ e) {
			double num_left, num_right, res;
			num_left = System::Convert::ToDouble(textBox1->Text);
			num_right = System::Convert::ToDouble(textBox2->Text);
			if (num_right == 0) {
				MessageBox::Show("ќшибка: ƒеление на ноль.");
				return;
			}
			res = fmod(num_left, num_right);
			label2->Text = res.ToString();
		}

	};
}
