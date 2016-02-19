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


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->serverDir = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 64);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(665, 506);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->serverDir);
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(662, 74);
			this->panel2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(27, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"VRPN Server directory";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(388, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ServerSetup::button2_Click);
			// 
			// serverDir
			// 
			this->serverDir->Location = System::Drawing::Point(31, 36);
			this->serverDir->Name = L"serverDir";
			this->serverDir->Size = System::Drawing::Size(351, 20);
			this->serverDir->TabIndex = 0;
			this->serverDir->Text = ProcWorker::servDir();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(3, 83);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(662, 423);
			this->panel1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(27, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enabled Devices";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25));
			this->label1->Location = System::Drawing::Point(39, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Server Setup";
			// 
			// ServerSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(689, 582);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"ServerSetup";
			this->Text = L"ServerSetup";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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
		ProcWorker::setServDir(s);
		
	}
};
}
