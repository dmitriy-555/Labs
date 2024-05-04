#include <fstream>

namespace lab36 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO; // Добавлено пространство имен System::IO

    /// <summary>
    /// Сводка для MyForm
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
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ mainButton;
    private: System::Windows::Forms::Label^ resultLabel;


    protected:

    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->mainButton = (gcnew System::Windows::Forms::Button());
            this->resultLabel = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->BackColor = System::Drawing::Color::Black;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(260, 67);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Нажмите кнопку, чтобы считать матрицуц (5,9) из файла и вывести полученную матриц"
                L"у";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // mainButton
            // 
            this->mainButton->Location = System::Drawing::Point(54, 83);
            this->mainButton->Name = L"mainButton";
            this->mainButton->Size = System::Drawing::Size(180, 54);
            this->mainButton->TabIndex = 1;
            this->mainButton->Text = L"Выполнить";
            this->mainButton->UseVisualStyleBackColor = true;
            this->mainButton->Click += gcnew System::EventHandler(this, &MyForm::mainButton_Click);
            // 
            // resultLabel
            // 
            this->resultLabel->AutoSize = true;
            this->resultLabel->BackColor = System::Drawing::Color::White;
            this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->resultLabel->ForeColor = System::Drawing::Color::Black;
            this->resultLabel->Location = System::Drawing::Point(12, 159);
            this->resultLabel->Name = L"resultLabel";
            this->resultLabel->Size = System::Drawing::Size(0, 19);
            this->resultLabel->TabIndex = 2;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(284, 261);
            this->Controls->Add(this->resultLabel);
            this->Controls->Add(this->mainButton);
            this->Controls->Add(this->label1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void mainButton_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            StreamReader^ reader = gcnew StreamReader("inputFile.txt");
            String^ line;
            array<array<int>^>^ matrix = gcnew array<array<int>^>(5);

            for (int i = 0; i < 5; i++) {
                line = reader->ReadLine();
                array<String^>^ elements = line->Split(' ');
                matrix[i] = gcnew array<int>(9);

                for (int j = 0; j < elements->Length; j++) {
                    matrix[i][j] = Convert::ToInt32(elements[j]);
                }
            }

            reader->Close();

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 9; j++) {
                    if (matrix[i][j] > 0) {
                        matrix[i][j] = -matrix[i][j];
                    }
                    else {
                        matrix[i][j] = 0;
                    }
                }
            }

            resultLabel->Text = "";
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 9; j++) {
                    resultLabel->Text += matrix[i][j].ToString() + " ";
                }
                resultLabel->Text += Environment::NewLine;
            }
        }
        catch (FileNotFoundException^ ex) {
            MessageBox::Show("Файл не найден: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}
