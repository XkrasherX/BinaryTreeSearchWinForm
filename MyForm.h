#pragma once


#include "BinaryTreeSearch.h"
namespace lab7 {

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
			tree = new BinaryTreeSearch();
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete tree;
			tree = nullptr;
		}
	private: BinaryTreeSearch* tree;
	private: System::Windows::Forms::Label^ EnterSequenceLabel;
	protected:
	private: System::Windows::Forms::TextBox^ EnterSequenceTextBox;
	private: System::Windows::Forms::TextBox^ InformationTextBox;
	private: System::Windows::Forms::Label^ InformationLabel;
	private: System::Windows::Forms::Button^ PreorderBTSButton;

	private: System::Windows::Forms::Button^ FindElementBTSButton;
	private: System::Windows::Forms::Button^ FindParrentDescendantButton;
	private: System::Windows::Forms::Button^ FindSecondConsonantButton;
	private: System::Windows::Forms::Button^ CreateTreeButton;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EnterSequenceLabel = (gcnew System::Windows::Forms::Label());
			this->EnterSequenceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InformationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InformationLabel = (gcnew System::Windows::Forms::Label());
			this->PreorderBTSButton = (gcnew System::Windows::Forms::Button());
			this->FindElementBTSButton = (gcnew System::Windows::Forms::Button());
			this->FindParrentDescendantButton = (gcnew System::Windows::Forms::Button());
			this->FindSecondConsonantButton = (gcnew System::Windows::Forms::Button());
			this->CreateTreeButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// EnterSequenceLabel
			// 
			this->EnterSequenceLabel->AutoSize = true;
			this->EnterSequenceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterSequenceLabel->Location = System::Drawing::Point(12, 35);
			this->EnterSequenceLabel->Name = L"EnterSequenceLabel";
			this->EnterSequenceLabel->Size = System::Drawing::Size(392, 29);
			this->EnterSequenceLabel->TabIndex = 0;
			this->EnterSequenceLabel->Text = L"Введіть послідовність символів: ";
			// 
			// EnterSequenceTextBox
			// 
			this->EnterSequenceTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EnterSequenceTextBox->Location = System::Drawing::Point(17, 82);
			this->EnterSequenceTextBox->Name = L"EnterSequenceTextBox";
			this->EnterSequenceTextBox->Size = System::Drawing::Size(435, 35);
			this->EnterSequenceTextBox->TabIndex = 1;
			// 
			// InformationTextBox
			// 
			this->InformationTextBox->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->InformationTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InformationTextBox->Location = System::Drawing::Point(18, 237);
			this->InformationTextBox->Multiline = true;
			this->InformationTextBox->Name = L"InformationTextBox";
			this->InformationTextBox->ReadOnly = true;
			this->InformationTextBox->Size = System::Drawing::Size(408, 384);
			this->InformationTextBox->TabIndex = 2;
			// 
			// InformationLabel
			// 
			this->InformationLabel->AutoSize = true;
			this->InformationLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InformationLabel->Location = System::Drawing::Point(13, 196);
			this->InformationLabel->Name = L"InformationLabel";
			this->InformationLabel->Size = System::Drawing::Size(476, 29);
			this->InformationLabel->TabIndex = 3;
			this->InformationLabel->Text = L"Інформація про бінарне дерево пошуку:";
			// 
			// PreorderBTSButton
			// 
			this->PreorderBTSButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PreorderBTSButton->Location = System::Drawing::Point(524, 183);
			this->PreorderBTSButton->Name = L"PreorderBTSButton";
			this->PreorderBTSButton->Size = System::Drawing::Size(267, 84);
			this->PreorderBTSButton->TabIndex = 4;
			this->PreorderBTSButton->Text = L"Зворотний обхід";
			this->PreorderBTSButton->UseVisualStyleBackColor = true;
			this->PreorderBTSButton->Click += gcnew System::EventHandler(this, &MyForm::PreorderBTSButton_Click);
			// 
			// FindElementBTSButton
			// 
			this->FindElementBTSButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FindElementBTSButton->Location = System::Drawing::Point(524, 538);
			this->FindElementBTSButton->Name = L"FindElementBTSButton";
			this->FindElementBTSButton->Size = System::Drawing::Size(267, 84);
			this->FindElementBTSButton->TabIndex = 5;
			this->FindElementBTSButton->Text = L"Знайди елемент в дереві";
			this->FindElementBTSButton->UseVisualStyleBackColor = true;
			this->FindElementBTSButton->Click += gcnew System::EventHandler(this, &MyForm::FindElementBTSButton_Click);
			// 
			// FindParrentDescendantButton
			// 
			this->FindParrentDescendantButton->Location = System::Drawing::Point(524, 307);
			this->FindParrentDescendantButton->Name = L"FindParrentDescendantButton";
			this->FindParrentDescendantButton->Size = System::Drawing::Size(267, 84);
			this->FindParrentDescendantButton->TabIndex = 6;
			this->FindParrentDescendantButton->Text = L"Знайти батька і нащадка елемента";
			this->FindParrentDescendantButton->UseVisualStyleBackColor = true;
			this->FindParrentDescendantButton->Click += gcnew System::EventHandler(this, &MyForm::FindParrentDescendantButton_Click);
			// 
			// FindSecondConsonantButton
			// 
			this->FindSecondConsonantButton->Location = System::Drawing::Point(524, 423);
			this->FindSecondConsonantButton->Name = L"FindSecondConsonantButton";
			this->FindSecondConsonantButton->Size = System::Drawing::Size(267, 84);
			this->FindSecondConsonantButton->TabIndex = 7;
			this->FindSecondConsonantButton->Text = L"Знайти 2 приголосну";
			this->FindSecondConsonantButton->UseVisualStyleBackColor = true;
			this->FindSecondConsonantButton->Click += gcnew System::EventHandler(this, &MyForm::FindSecondConsonantButton_Click);
			// 
			// CreateTreeButton
			// 
			this->CreateTreeButton->Location = System::Drawing::Point(524, 60);
			this->CreateTreeButton->Name = L"CreateTreeButton";
			this->CreateTreeButton->Size = System::Drawing::Size(267, 84);
			this->CreateTreeButton->TabIndex = 8;
			this->CreateTreeButton->Text = L"Створити дерево";
			this->CreateTreeButton->UseVisualStyleBackColor = true;
			this->CreateTreeButton->Click += gcnew System::EventHandler(this, &MyForm::CreateTreeButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 644);
			this->Controls->Add(this->CreateTreeButton);
			this->Controls->Add(this->FindSecondConsonantButton);
			this->Controls->Add(this->FindParrentDescendantButton);
			this->Controls->Add(this->FindElementBTSButton);
			this->Controls->Add(this->PreorderBTSButton);
			this->Controls->Add(this->InformationLabel);
			this->Controls->Add(this->InformationTextBox);
			this->Controls->Add(this->EnterSequenceTextBox);
			this->Controls->Add(this->EnterSequenceLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//оновити інформацію про дерево
	private: void refreshInfoTextBox() {
		std::string information = tree->postorder();
		InformationTextBox->Text = "Дерево при зворотному обході: " + Environment::NewLine + gcnew String(information.c_str());
	}

	private: System::Void CreateTreeButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ input = EnterSequenceTextBox->Text->Trim();

		if (input->Length == 0)
		{
			MessageBox::Show("Введіть символ!");
			return;
		}

		array<String^>^ parts = input->Split(gcnew array<Char>{' '}, StringSplitOptions::RemoveEmptyEntries);

		array<char>^ symbols = gcnew array<char>(parts->Length);

		for (int i = 0; i < parts->Length; i++)
		{
			//кожна частина має бути одним символом
			if (parts[i]->Length != 1 || parts[i][0] > 127)
			{
				MessageBox::Show("Неправильний символ: " + parts[i]);
				return;
			}

			//нижній регістр
			symbols[i] = (char)Char::ToLower(parts[i][0]);
		}

		//перевірка на повтори у першому записі
		for (int i = 0; i < symbols->Length; i++)
		{
			for (int j = i + 1; j < symbols->Length; j++)
			{
				if (symbols[i] == symbols[j])
				{
					MessageBox::Show("Символ: " + Char::ToString((wchar_t)symbols[i]) + " вже є у записі!");
					return;
				}
			}
		}

		//перевірка на повтори у дереві
		for (int i = 0; i < symbols->Length; i++)
		{
			if (tree->findData(symbols[i]))
			{
				MessageBox::Show("Символ: " + Char::ToString((wchar_t)symbols[i]) + " вже є у дереві!");
				return;
			}
		}

		//усе перевірено, додаємо
		for (int i = 0; i < symbols->Length; i++)
		{
			tree->insertData(symbols[i]);
		}

		refreshInfoTextBox();
	}
	private: System::Void PreorderBTSButton_Click(System::Object^ sender, System::EventArgs^ e) {

		InformationTextBox->Clear();
		InformationTextBox->Text = "Зворотний обхід дерева: " +
			Environment::NewLine +
			gcnew String(tree->postorder().c_str());

	}
	private: System::Void FindParrentDescendantButton_Click(System::Object^ sender, System::EventArgs^ e) {

		InformationTextBox->Clear();
		char c = Convert::ToChar(EnterSequenceTextBox->Text);
		InformationTextBox->Text = "Вивід батька і нащадків(у прямому порядку) для символа " +
			Char::ToString((wchar_t)c) + ":" +
			Environment::NewLine +
			gcnew String(tree->parentAndDescendants(c).c_str());

	}
	private: System::Void FindSecondConsonantButton_Click(System::Object^ sender, System::EventArgs^ e) {

		InformationTextBox->Clear();
		if (tree->secondConsonantLetter() == '\n') InformationTextBox->Text = "У дереві менше 2 приголосних";
		
		InformationTextBox->Text = "Друга приголосна в дереві(за зворотним обходом): " +
			Environment::NewLine +
			Char::ToString((wchar_t)tree->secondConsonantLetter());

	}
	private: System::Void FindElementBTSButton_Click(System::Object^ sender, System::EventArgs^ e) {

		InformationTextBox->Clear();
		char c = Convert::ToChar(EnterSequenceTextBox->Text);

		if (!c) return;
		if (tree->findData(c)) {
			InformationTextBox->Text = "Символ " + Char::ToString((wchar_t)c) + " є у дереві";
		}
		else {
			InformationTextBox->Text = "Символ " + Char::ToString((wchar_t)c) + " не є у дереві";
		}

	}
	};
}
