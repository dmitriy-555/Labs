#pragma once
#include <iostream>
#include <string>

namespace My35Project {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ inputTextBox;
        System::Windows::Forms::Button^ processButton;
        System::Windows::Forms::TextBox^ resultTextBox;
    private: System::Windows::Forms::Button^ clearButton;




    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
            this->processButton = (gcnew System::Windows::Forms::Button());
            this->resultTextBox = (gcnew System::Windows::Forms::TextBox());
            this->clearButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // inputTextBox
            // 
            this->inputTextBox->Location = System::Drawing::Point(10, 10);
            this->inputTextBox->Name = L"inputTextBox";
            this->inputTextBox->Size = System::Drawing::Size(200, 20);
            this->inputTextBox->TabIndex = 0;
            // 
            // processButton
            // 
            this->processButton->Location = System::Drawing::Point(10, 40);
            this->processButton->Name = L"processButton";
            this->processButton->Size = System::Drawing::Size(80, 30);
            this->processButton->TabIndex = 1;
            this->processButton->Text = L"Выполнить";
            this->processButton->UseVisualStyleBackColor = true;
            this->processButton->Click += gcnew System::EventHandler(this, &MyForm::processButton_Click);
            // 
            // resultTextBox
            // 
            this->resultTextBox->Location = System::Drawing::Point(10, 80);
            this->resultTextBox->Name = L"resultTextBox";
            this->resultTextBox->ReadOnly = true;
            this->resultTextBox->Size = System::Drawing::Size(200, 20);
            this->resultTextBox->TabIndex = 2;
            // 
            // clearButton
            // 
            this->clearButton->Location = System::Drawing::Point(130, 40);
            this->clearButton->Name = L"clearButton";
            this->clearButton->Size = System::Drawing::Size(80, 30);
            this->clearButton->TabIndex = 3;
            this->clearButton->Text = L"Clear input";
            this->clearButton->UseVisualStyleBackColor = true;
            this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(224, 111);
            this->Controls->Add(this->clearButton);
            this->Controls->Add(this->resultTextBox);
            this->Controls->Add(this->processButton);
            this->Controls->Add(this->inputTextBox);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: 
        System::Void processButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ input = inputTextBox->Text;

        array<int>^ arr = gcnew array<int>(9);
        int count = 0;
        String^ ch = "";
        bool isMinus = 0;
        for (int i = 0; i < input->Length; i++) {
            if ((input[i] == ' ') && (i != (input->Length - 1)) && (input[i+1] == ' ')) {
                continue;
            }
            if (count > 9) {
                MessageBox::Show("Ошибка ввода!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (Char::IsDigit(input[i])) {
                ch += input[i];
            }
            else if ((i != (input->Length - 1)) && input[i] == '-' && Char::IsDigit(input[i + 1]) && isMinus == 0) {
                isMinus = 1;
                ch += input[i];
            }
            else if (input[i] == ' ' && ch != "") {
                isMinus = 0;
                arr[count] = Convert::ToInt32(ch);
                ch = "";
                count++;
            }
            else {
                MessageBox::Show("Ошибка ввода!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if ((i == input->Length - 1)  && (Char::IsDigit(input[i]))) {
                arr[count] = Convert::ToInt32(ch);
                ch = "";
                count++;
            }
        }
        
        if (count < 9) {
            MessageBox::Show("Введите 9 чисел (не считая пробелы).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        String^ result = "";
        for (int i = 0; i < 9; i++) {
            if (arr[i] % 6 == 0) {
                result += (arr[i] / 3).ToString() + " ";
            }
            else {
                result += (arr[i] - 5).ToString() + " ";
            }
        }

        resultTextBox->Text = result;
        }
        System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
            inputTextBox->Clear();
        }
    };
}
