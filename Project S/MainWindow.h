#pragma once
#include "ProcWorker.h"
#include <TlHelp32.h>
#include <cstdio>
#include <stdio.h>
#include "Glob.h"
#include <msclr/marshal.h>
#include "ServerSetup.h"
#include "DeviceWindow.h"
#include "Boss.h"

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
			
			//create the boss of the program
			ProcWorker::setBoss(gcnew Boss());
			
			

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
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  setupDevice;
	private: System::Windows::Forms::Button^  checkConfig;
	private: System::Windows::Forms::Panel^  panel3;
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->setupDevice = (gcnew System::Windows::Forms::Button());
			this->checkConfig = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(147, 47);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 76);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SIVR";
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(112, 40);
			this->startButton->Margin = System::Windows::Forms::Padding(4);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(100, 28);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"start server";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(75, 128);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(364, 12);
			this->panel1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label2->Location = System::Drawing::Point(4, 0);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(179, 31);
			this->label2->TabIndex = 3;
			this->label2->Text = L"server status:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoCheck = false;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(191, 4);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Padding = System::Windows::Forms::Padding(0, 9, 0, 0);
			this->radioButton1->Size = System::Drawing::Size(17, 25);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// endButton
			// 
			this->endButton->Location = System::Drawing::Point(220, 40);
			this->endButton->Margin = System::Windows::Forms::Padding(4);
			this->endButton->Name = L"endButton";
			this->endButton->Size = System::Drawing::Size(100, 28);
			this->endButton->TabIndex = 5;
			this->endButton->Text = L"end server";
			this->endButton->UseVisualStyleBackColor = true;
			this->endButton->Click += gcnew System::EventHandler(this, &MainWindow::endButton_Click);
			// 
			// checkBut
			// 
			this->checkBut->Location = System::Drawing::Point(216, 4);
			this->checkBut->Margin = System::Windows::Forms::Padding(4);
			this->checkBut->Name = L"checkBut";
			this->checkBut->Size = System::Drawing::Size(104, 28);
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
			this->flowLayoutPanel1->Location = System::Drawing::Point(71, 148);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(367, 88);
			this->flowLayoutPanel1->TabIndex = 7;
			// 
			// setupSerButton
			// 
			this->setupSerButton->Location = System::Drawing::Point(4, 40);
			this->setupSerButton->Margin = System::Windows::Forms::Padding(4);
			this->setupSerButton->Name = L"setupSerButton";
			this->setupSerButton->Size = System::Drawing::Size(100, 28);
			this->setupSerButton->TabIndex = 7;
			this->setupSerButton->Text = L"setup server";
			this->setupSerButton->UseVisualStyleBackColor = true;
			this->setupSerButton->Click += gcnew System::EventHandler(this, &MainWindow::setupSerButton_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(74, 244);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(364, 12);
			this->panel2->TabIndex = 3;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->label3);
			this->flowLayoutPanel2->Controls->Add(this->setupDevice);
			this->flowLayoutPanel2->Controls->Add(this->checkConfig);
			this->flowLayoutPanel2->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel2->Location = System::Drawing::Point(71, 267);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(367, 47);
			this->flowLayoutPanel2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label3->Location = System::Drawing::Point(4, 0);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 31);
			this->label3->TabIndex = 3;
			this->label3->Text = L"devices:";
			// 
			// setupDevice
			// 
			this->setupDevice->Location = System::Drawing::Point(127, 4);
			this->setupDevice->Margin = System::Windows::Forms::Padding(4);
			this->setupDevice->Name = L"setupDevice";
			this->setupDevice->Size = System::Drawing::Size(100, 28);
			this->setupDevice->TabIndex = 6;
			this->setupDevice->Text = L"setup device";
			this->setupDevice->UseVisualStyleBackColor = true;
			this->setupDevice->Click += gcnew System::EventHandler(this, &MainWindow::setupDevice_Click);
			// 
			// checkConfig
			// 
			this->checkConfig->Location = System::Drawing::Point(235, 4);
			this->checkConfig->Margin = System::Windows::Forms::Padding(4);
			this->checkConfig->Name = L"checkConfig";
			this->checkConfig->Size = System::Drawing::Size(85, 28);
			this->checkConfig->TabIndex = 1;
			this->checkConfig->Text = L"check";
			this->checkConfig->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel3->Location = System::Drawing::Point(74, 322);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(364, 12);
			this->panel3->TabIndex = 4;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(519, 459);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ s = "vrpn_server.exe";
		marshal_context ctx;
		LPCTSTR q = ctx.marshal_as<const TCHAR*>(ProcWorker::servDir());
		if (!(ProcWorker::checkProc("vrpn_server.exe")) && (ProcWorker::servDir()->Contains(s)))
		{

			System::Console::WriteLine(ProcWorker::servDir());

			ProcWorker::startProc(q);
		}
		else if (ProcWorker::checkProc("vrpn_server.exe"))
			std::printf("Already Open\n");
		else
			std::printf("Server directory set to incorrect path\n");
		
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
private: System::Void setupDevice_Click(System::Object^  sender, System::EventArgs^  e) {
	bool l = false;
	FormCollection^ fc = Application::OpenForms;
	for each(Form^ f in fc)
	{
		if (f->Name == "DeviceWindow")
		{
			l = true;
			break;
		}
	}

	if (!l) {
		Form^ dw = gcnew DeviceWindow();
		dw->Show();
	}
}
private: System::Void MainWindow_Load(System::Object^  sender, System::EventArgs^  e) {
}
};

}
