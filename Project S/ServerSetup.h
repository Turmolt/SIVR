#pragma once
#include <windows.h>
#include <ShlObj.h>
#include <commdlg.h>
#include "ProcWorker.h"
#include "Glob.h"

namespace ProjectS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ServerSetup
	/// </summary>
	public ref class ServerSetup : public System::Windows::Forms::Form
	{
	public:
		ServerSetup(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->serverDir->Text = ProcWorker::servDir();
				
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerSetup()
		{
			if (components)
			{

				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	protected:
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  configDir;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  serverDir;




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
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->serverDir = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->configDir = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Location = System::Drawing::Point(16, 79);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(679, 211);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->serverDir);
			this->panel1->Location = System::Drawing::Point(4, 4);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(673, 91);
			this->panel1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(36, 16);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(208, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"VRPN Server directory";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(517, 44);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 28);
			this->button4->TabIndex = 1;
			this->button4->Text = L"browse";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ServerSetup::button4_Click);
			// 
			// serverDir
			// 
			this->serverDir->Location = System::Drawing::Point(41, 44);
			this->serverDir->Margin = System::Windows::Forms::Padding(4);
			this->serverDir->Name = L"serverDir";
			this->serverDir->Size = System::Drawing::Size(467, 22);
			this->serverDir->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->configDir);
			this->panel2->Location = System::Drawing::Point(4, 103);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(673, 91);
			this->panel2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(36, 16);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"VRPN Config directory";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(517, 44);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 1;
			this->button2->Text = L"browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ServerSetup::button2_Click);
			// 
			// configDir
			// 
			this->configDir->Location = System::Drawing::Point(41, 44);
			this->configDir->Margin = System::Windows::Forms::Padding(4);
			this->configDir->Name = L"configDir";
			this->configDir->Size = System::Drawing::Size(467, 22);
			this->configDir->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->label1->Location = System::Drawing::Point(52, 16);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(263, 48);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Server Setup";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(215, 298);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 3;
			this->button1->Text = L"save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ServerSetup::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(367, 298);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 4;
			this->button3->Text = L"cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ServerSetup::button3_Click);
			// 
			// ServerSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(729, 347);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ServerSetup";
			this->Text = L"ServerSetup";
			this->Load += gcnew System::EventHandler(this, &ServerSetup::ServerSetup_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//Button was clicked to browse for the directory of the server
		char filename[MAX_PATH];
		OPENFILENAME o;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&o, sizeof(o));
		o.lStructSize = sizeof(o);
		o.hwndOwner = NULL;
		o.lpstrFilter = "Config File\0*.cfg\0Any File\0*.*\0";
		o.lpstrFile = filename;
		o.nMaxFile = MAX_PATH;
		o.lpstrTitle = "Please select vrpn.cfg";
		o.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&o))
		{

		}

		String^ s = gcnew String(filename);
		this->configDir->Text = s;

	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	ProcWorker::setServDir(this->serverDir->Text);
	//ProcWorker::setConfigDir(this->configDir->Text);
	this->Close();
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

private: System::Void ServerSetup_Load(System::Object^  sender, System::EventArgs^  e) {
	this->configDir->Text = ProcWorker::configDir();
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//Button was clicked to browse for the directory of the server
	printf("ello");
	char filename[MAX_PATH];
	OPENFILENAME o = { 0 };
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&o, sizeof(o));
	o.lStructSize = sizeof(o);
	o.hwndOwner = NULL;
	o.lpstrFilter = "Executable\0*.exe\0Any File\0*.*\0";
	o.lpstrFile = filename;
	o.nMaxFile = MAX_PATH;
	o.lpstrTitle = "Please select vrpn_server.exe";
	o.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&o))
	{

	}

	String^ s = gcnew String(filename);
	this->serverDir->Text = s;
}
};
}
