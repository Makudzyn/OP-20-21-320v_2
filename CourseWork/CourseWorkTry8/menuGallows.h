#pragma once

namespace CourseWorkTry8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для menuGallows
	/// </summary>
	public ref class menuGallows : public System::Windows::Forms::Form
	{
	public:
		menuGallows(void)
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
		~menuGallows()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ menuStart;
	protected:
	private: System::Windows::Forms::Button^ menuRules;
	private: System::Windows::Forms::Button^ menuExit;
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStrip;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menuGallows::typeid));
			this->menuStart = (gcnew System::Windows::Forms::Button());
			this->menuRules = (gcnew System::Windows::Forms::Button());
			this->menuExit = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStart
			// 
			this->menuStart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuStart.Image")));
			this->menuStart->Location = System::Drawing::Point(200, 100);
			this->menuStart->Name = L"menuStart";
			this->menuStart->Size = System::Drawing::Size(300, 60);
			this->menuStart->TabIndex = 0;
			this->menuStart->UseVisualStyleBackColor = true;
			this->menuStart->Click += gcnew System::EventHandler(this, &menuGallows::menuStart_Click);
			// 
			// menuRules
			// 
			this->menuRules->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuRules.Image")));
			this->menuRules->Location = System::Drawing::Point(200, 200);
			this->menuRules->Name = L"menuRules";
			this->menuRules->Size = System::Drawing::Size(300, 60);
			this->menuRules->TabIndex = 1;
			this->menuRules->UseVisualStyleBackColor = true;
			this->menuRules->Click += gcnew System::EventHandler(this, &menuGallows::menuRules_Click);
			// 
			// menuExit
			// 
			this->menuExit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuExit.Image")));
			this->menuExit->Location = System::Drawing::Point(200, 300);
			this->menuExit->Name = L"menuExit";
			this->menuExit->Size = System::Drawing::Size(300, 60);
			this->menuExit->TabIndex = 2;
			this->menuExit->UseVisualStyleBackColor = true;
			this->menuExit->Click += gcnew System::EventHandler(this, &menuGallows::menuExit_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStrip });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(684, 24);
			this->menuStrip->TabIndex = 3;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// menuToolStrip
			// 
			this->menuToolStrip->Name = L"menuToolStrip";
			this->menuToolStrip->Size = System::Drawing::Size(94, 20);
			this->menuToolStrip->Text = L"О программе";
			this->menuToolStrip->Click += gcnew System::EventHandler(this, &menuGallows::menuToolStrip_Click);
			// 
			// menuGallows
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->menuExit);
			this->Controls->Add(this->menuRules);
			this->Controls->Add(this->menuStart);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"menuGallows";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"menuGallows";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void menuStart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menuRules_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menuExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menuToolStrip_Click(System::Object^ sender, System::EventArgs^ e);
};
}
