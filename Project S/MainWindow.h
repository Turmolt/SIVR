#pragma once
#include "ProcWorker.h"
#include <TlHelp32.h>
#include <cstdio>
#include <stdio.h>
#include "Glob.h"
#include <msclr/marshal.h>
#include "ServerSetup.h"

namespace ProjectS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	
	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			

		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  startButton;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  endButton;
	private: System::Windows::Forms::Button^  checkBut;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  setupSerButton;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->endButton = (gcnew System::Windows::Forms::Button());
			this->checkBut = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->setupSerButton = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(110, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 63);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SIVR";
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(84, 32);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 23);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"start server";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(56, 104);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(273, 10);
			this->panel1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"server status:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoCheck = false;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(151, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Padding = System::Windows::Forms::Padding(0, 7, 0, 0);
			this->radioButton1->Size = System::Drawing::Size(14, 20);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// endButton
			// 
			this->endButton->Location = System::Drawing::Point(165, 32);
			this->endButton->Name = L"endButton";
			this->endButton->Size = System::Drawing::Size(75, 23);
			this->endButton->TabIndex = 5;
			this->endButton->Text = L"end server";
			this->endButton->UseVisualStyleBackColor = true;
			this->endButton->Click += gcnew System::EventHandler(this, &MainWindow::endButton_Click);
			// 
			// checkBut
			// 
			this->checkBut->Location = System::Drawing::Point(171, 3);
			this->checkBut->Name = L"checkBut";
			this->checkBut->Size = System::Drawing::Size(75, 23);
			this->checkBut->TabIndex = 6;
			this->checkBut->Text = L"check";
			this->checkBut->UseVisualStyleBackColor = true;
			this->checkBut->Click += gcnew System::EventHandler(this, &MainWindow::checkBut_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label2);
			this->flowLayoutPanel1->Controls->Add(this->radioButton1);
			this->flowLayoutPanel1->Controls->Add(this->checkBut);
			this->flowLayoutPanel1->Controls->Add(this->setupSerButton);
			this->flowLayoutPanel1->Controls->Add(this->startButton);
			this->flowLayoutPanel1->Controls->Add(this->endButton);
			this->flowLayoutPanel1->Location = System::Drawing::Point(53, 120);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(275, 100);
			this->flowLayoutPanel1->TabIndex = 7;
			// 
			// setupSerButton
			// 
			this->setupSerButton->Location = System::Drawing::Point(3, 32);
			this->setupSerButton->Name = L"setupSerButton";
			this->setupSerButton->Size = System::Drawing::Size(75, 23);
			this->setupSerButton->TabIndex = 7;
			this->setupSerButton->Text = L"setup server";
			this->setupSerButton->UseVisualStyleBackColor = true;
			this->setupSerButton->Click += gcnew System::EventHandler(this, &MainWindow::setupSerButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(383, 564);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ s = "vrpn_server.exe";
		marshal_context ctx;
		LPCTSTR q = ctx.marshal_as<const TCHAR*>(ProcWorker::servDir());
		if (!(ProcWorker::checkProc("vrpn_server.exe"))&&(ProcWorker::servDir()->Contains(s)))
		{

			System::Console::WriteLine(ProcWorker::servDir());
			
			ProcWorker::startProc(q);
		}
		else
			std::printf("true\n");
	}
private: System::Void endButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//if ((ProcWorker::checkProc("vrpn_server.exe")))
	ProcWorker::endProc("vrpn_server.exe");
}
private: System::Void checkBut_Click(System::Object^  sender, System::EventArgs^  e) {
	this->radioButton1->Checked = !(ProcWorker::checkProc("vrpn_server.exe")==0);
}

//when the "setup server" button is clicked, check to first make sure we haven't already opened that window.
private: System::Void setupSerButton_Click(System::Object^  sender, System::EventArgs^  e) {
	bool l = false;
	FormCollection^ fc = Application::OpenForms;
	for each(Form^ f in fc)
	{
		if (f->Name == "ServerSetup")
		{
			l = true;
			break;
		}
	}

	if (!l) {
		Form^ servSetup = gcnew ServerSetup();

		servSetup->Show();
	}
}
};

}
