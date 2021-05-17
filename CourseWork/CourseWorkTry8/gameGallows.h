#pragma once

namespace CourseWorkTry8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Threading::Tasks;


	public ref class gameGallows : public System::Windows::Forms::Form	{
	public:
		gameGallows(void){
			InitializeComponent();
		}
	protected:
		~gameGallows() {
			if (components)	{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ hangmanPictureBox;
	private: System::Windows::Forms::TextBox^ wordTextBox;
	private: System::Windows::Forms::Button^ wordEntbutton;
	private: System::Windows::Forms::Label^ mainLabel;
	private: System::Windows::Forms::Button^ letterEntButton;
	private: System::Windows::Forms::TextBox^ letterTextBox;




	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)	{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gameGallows::typeid));
			this->hangmanPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->wordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->wordEntbutton = (gcnew System::Windows::Forms::Button());
			this->mainLabel = (gcnew System::Windows::Forms::Label());
			this->letterEntButton = (gcnew System::Windows::Forms::Button());
			this->letterTextBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hangmanPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// hangmanPictureBox
			// 
			this->hangmanPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hangmanPictureBox.Image")));
			this->hangmanPictureBox->Location = System::Drawing::Point(21, 36);
			this->hangmanPictureBox->Name = L"hangmanPictureBox";
			this->hangmanPictureBox->Size = System::Drawing::Size(300, 265);
			this->hangmanPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->hangmanPictureBox->TabIndex = 0;
			this->hangmanPictureBox->TabStop = false;
			// 
			// wordTextBox
			// 
			this->wordTextBox->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->wordTextBox->Location = System::Drawing::Point(363, 251);
			this->wordTextBox->Multiline = true;
			this->wordTextBox->Name = L"wordTextBox";
			this->wordTextBox->Size = System::Drawing::Size(132, 50);
			this->wordTextBox->TabIndex = 1;
			// 
			// wordEntbutton
			// 
			this->wordEntbutton->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->wordEntbutton->Location = System::Drawing::Point(521, 251);
			this->wordEntbutton->Name = L"wordEntbutton";
			this->wordEntbutton->Size = System::Drawing::Size(151, 50);
			this->wordEntbutton->TabIndex = 2;
			this->wordEntbutton->Text = L"Задать слово";
			this->wordEntbutton->UseVisualStyleBackColor = true;
			this->wordEntbutton->Click += gcnew System::EventHandler(this, &gameGallows::wordEntbutton_Click);
			// 
			// mainLabel
			// 
			this->mainLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mainLabel->Location = System::Drawing::Point(358, 36);
			this->mainLabel->Name = L"mainLabel";
			this->mainLabel->Size = System::Drawing::Size(314, 112);
			this->mainLabel->TabIndex = 3;
			this->mainLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// letterEntButton
			// 
			this->letterEntButton->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->letterEntButton->Location = System::Drawing::Point(521, 166);
			this->letterEntButton->Name = L"letterEntButton";
			this->letterEntButton->Size = System::Drawing::Size(151, 50);
			this->letterEntButton->TabIndex = 4;
			this->letterEntButton->Text = L"Ввести букву";
			this->letterEntButton->UseVisualStyleBackColor = true;
			this->letterEntButton->Click += gcnew System::EventHandler(this, &gameGallows::letterEntButton_Click);
			// 
			// letterTextBox
			// 
			this->letterTextBox->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->letterTextBox->Location = System::Drawing::Point(423, 166);
			this->letterTextBox->Multiline = true;
			this->letterTextBox->Name = L"letterTextBox";
			this->letterTextBox->Size = System::Drawing::Size(72, 50);
			this->letterTextBox->TabIndex = 5;
			// 
			// gameGallows
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(700, 337);
			this->Controls->Add(this->letterTextBox);
			this->Controls->Add(this->letterEntButton);
			this->Controls->Add(this->mainLabel);
			this->Controls->Add(this->wordEntbutton);
			this->Controls->Add(this->wordTextBox);
			this->Controls->Add(this->hangmanPictureBox);
			this->Name = L"gameGallows";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"gameGallows";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hangmanPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void wordEntbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void letterEntButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
