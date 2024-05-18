#pragma once

namespace WordFinder {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void) {
            InitializeComponent();
        }

    protected:
        ~MyForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textBoxInput;
        System::Windows::Forms::Button^ buttonFind;
        System::Windows::Forms::Button^ buttonClear; // Новая кнопка "Очистить"
        System::Windows::Forms::Label^ labelResult;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
            this->buttonFind = (gcnew System::Windows::Forms::Button());
            this->buttonClear = (gcnew System::Windows::Forms::Button());
            this->labelResult = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBoxInput
            // 
            this->textBoxInput->Location = System::Drawing::Point(12, 12);
            this->textBoxInput->Name = L"textBoxInput";
            this->textBoxInput->Size = System::Drawing::Size(360, 20);
            this->textBoxInput->TabIndex = 0;
            // 
            // buttonFind
            // 
            this->buttonFind->Location = System::Drawing::Point(297, 38);
            this->buttonFind->Name = L"buttonFind";
            this->buttonFind->Size = System::Drawing::Size(75, 23);
            this->buttonFind->TabIndex = 1;
            this->buttonFind->Text = L"Найти";
            this->buttonFind->UseVisualStyleBackColor = true;
            this->buttonFind->Click += gcnew System::EventHandler(this, &MyForm::buttonFind_Click);
            // 
            // buttonClear
            // 
            this->buttonClear->Location = System::Drawing::Point(12, 38);
            this->buttonClear->Name = L"buttonClear";
            this->buttonClear->Size = System::Drawing::Size(75, 23);
            this->buttonClear->TabIndex = 2;
            this->buttonClear->Text = L"Очистить";
            this->buttonClear->UseVisualStyleBackColor = true;
            this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);
            // 
            // labelResult
            // 
            this->labelResult->Location = System::Drawing::Point(12, 67);
            this->labelResult->Name = L"labelResult";
            this->labelResult->Size = System::Drawing::Size(360, 185);
            this->labelResult->TabIndex = 3;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(384, 261);
            this->Controls->Add(this->labelResult);
            this->Controls->Add(this->buttonClear);
            this->Controls->Add(this->buttonFind);
            this->Controls->Add(this->textBoxInput);
            this->Name = L"MyForm";
            this->Text = L"Word Finder";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        bool ContainsOnlyLetters(String^ word) {
            for each (Char c in word) {
                if (!Char::IsLetter(c)) return false;
            }
            return true;
        }

        System::Void buttonFind_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ input = textBoxInput->Text;

            array<String^>^ words = input->Split(gcnew array<wchar_t> {' '}, StringSplitOptions::RemoveEmptyEntries);
            int count = 0;
            String^ matchingWords = ""; 

            for each (String ^ word in words) {
                if (ContainsOnlyLetters(word)) {
                    Char firstChar = Char::ToLower(word[0]);
                    Char lastChar = Char::ToLower(word[word->Length - 1]);
                    if (firstChar == lastChar) {
                        count++;
                        matchingWords += word + " "; 
                    }
                }
            }

            
            labelResult->Text = "Количество слов, начинающихся и заканчивающихся на одну и ту же букву: " + count.ToString() + "\n";
            labelResult->Text += "Слова: " + matchingWords;
        }

        System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
            textBoxInput->Text = ""; 
            labelResult->Text = ""; 
        }
    };
}
