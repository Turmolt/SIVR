#pragma once

#include <fstream>
#include <string>
#include "ProcWorker.h"
#include "Glob.h"

namespace ProjectS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for DeviceWindow
	/// </summary>
	public ref class DeviceWindow : public System::Windows::Forms::Form
	{
	public:
		DeviceWindow(void)
		{

			InitializeComponent();
			//create the boss of the program
			ProcWorker::setBoss(gcnew Boss());

			refreshDeviceList();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeviceWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:












	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  Title;
	private: System::Windows::Forms::ComboBox^  miscDeviceChoices;
	private: System::Windows::Forms::CheckBox^  MDCheck;





	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  handDeviceChoices;
	private: System::Windows::Forms::CheckBox^  HTCheck;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  SpatialTrackingChoices;

	private: System::Windows::Forms::ComboBox^  headDeviceChoices;
	private: System::Windows::Forms::CheckBox^  STCheck;
	private: System::Windows::Forms::CheckBox^  HMDCheck;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  refreshDevices;
	private: System::Windows::Forms::Button^  KillClients;
	private: System::Windows::Forms::Button^  applyDevicePurposes;




	protected:

	protected:

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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->refreshDevices = (gcnew System::Windows::Forms::Button());
			this->KillClients = (gcnew System::Windows::Forms::Button());
			this->applyDevicePurposes = (gcnew System::Windows::Forms::Button());
			this->miscDeviceChoices = (gcnew System::Windows::Forms::ComboBox());
			this->MDCheck = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->handDeviceChoices = (gcnew System::Windows::Forms::ComboBox());
			this->HTCheck = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SpatialTrackingChoices = (gcnew System::Windows::Forms::ComboBox());
			this->headDeviceChoices = (gcnew System::Windows::Forms::ComboBox());
			this->STCheck = (gcnew System::Windows::Forms::CheckBox());
			this->HMDCheck = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel2->Controls->Add(this->refreshDevices);
			this->panel2->Controls->Add(this->KillClients);
			this->panel2->Controls->Add(this->applyDevicePurposes);
			this->panel2->Controls->Add(this->miscDeviceChoices);
			this->panel2->Controls->Add(this->MDCheck);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->handDeviceChoices);
			this->panel2->Controls->Add(this->HTCheck);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->SpatialTrackingChoices);
			this->panel2->Controls->Add(this->headDeviceChoices);
			this->panel2->Controls->Add(this->STCheck);
			this->panel2->Controls->Add(this->HMDCheck);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->Title);
			this->panel2->Location = System::Drawing::Point(12, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(259, 413);
			this->panel2->TabIndex = 8;
			// 
			// refreshDevices
			// 
			this->refreshDevices->Location = System::Drawing::Point(78, 309);
			this->refreshDevices->Name = L"refreshDevices";
			this->refreshDevices->Size = System::Drawing::Size(75, 23);
			this->refreshDevices->TabIndex = 19;
			this->refreshDevices->Text = L"Refresh";
			this->refreshDevices->UseVisualStyleBackColor = true;
			this->refreshDevices->Click += gcnew System::EventHandler(this, &DeviceWindow::refreshDevices_Click);
			// 
			// KillClients
			// 
			this->KillClients->Location = System::Drawing::Point(78, 367);
			this->KillClients->Name = L"KillClients";
			this->KillClients->Size = System::Drawing::Size(75, 23);
			this->KillClients->TabIndex = 18;
			this->KillClients->Text = L"Kill Clients";
			this->KillClients->UseVisualStyleBackColor = true;
			this->KillClients->Click += gcnew System::EventHandler(this, &DeviceWindow::KillClients_Click);
			// 
			// applyDevicePurposes
			// 
			this->applyDevicePurposes->Location = System::Drawing::Point(78, 338);
			this->applyDevicePurposes->Name = L"applyDevicePurposes";
			this->applyDevicePurposes->Size = System::Drawing::Size(75, 23);
			this->applyDevicePurposes->TabIndex = 17;
			this->applyDevicePurposes->Text = L"Launch";
			this->applyDevicePurposes->UseVisualStyleBackColor = true;
			this->applyDevicePurposes->Click += gcnew System::EventHandler(this, &DeviceWindow::applyDevicePurposes_Click_1);
			// 
			// miscDeviceChoices
			// 
			this->miscDeviceChoices->FormattingEnabled = true;
			this->miscDeviceChoices->Location = System::Drawing::Point(56, 250);
			this->miscDeviceChoices->Name = L"miscDeviceChoices";
			this->miscDeviceChoices->Size = System::Drawing::Size(121, 21);
			this->miscDeviceChoices->TabIndex = 16;
			this->miscDeviceChoices->SelectedIndexChanged += gcnew System::EventHandler(this, &DeviceWindow::miscDeviceChoices_SelectedIndexChanged);
			// 
			// MDCheck
			// 
			this->MDCheck->AutoSize = true;
			this->MDCheck->Location = System::Drawing::Point(31, 232);
			this->MDCheck->Name = L"MDCheck";
			this->MDCheck->Size = System::Drawing::Size(15, 14);
			this->MDCheck->TabIndex = 15;
			this->MDCheck->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(52, 227);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 20);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Misc Devices";
			// 
			// handDeviceChoices
			// 
			this->handDeviceChoices->FormattingEnabled = true;
			this->handDeviceChoices->Location = System::Drawing::Point(56, 189);
			this->handDeviceChoices->Name = L"handDeviceChoices";
			this->handDeviceChoices->Size = System::Drawing::Size(121, 21);
			this->handDeviceChoices->TabIndex = 13;
			// 
			// HTCheck
			// 
			this->HTCheck->AutoSize = true;
			this->HTCheck->Location = System::Drawing::Point(31, 171);
			this->HTCheck->Name = L"HTCheck";
			this->HTCheck->Size = System::Drawing::Size(15, 14);
			this->HTCheck->TabIndex = 12;
			this->HTCheck->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(52, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Hand Tracking";
			// 
			// SpatialTrackingChoices
			// 
			this->SpatialTrackingChoices->FormattingEnabled = true;
			this->SpatialTrackingChoices->Location = System::Drawing::Point(56, 128);
			this->SpatialTrackingChoices->Name = L"SpatialTrackingChoices";
			this->SpatialTrackingChoices->Size = System::Drawing::Size(121, 21);
			this->SpatialTrackingChoices->TabIndex = 10;
			// 
			// headDeviceChoices
			// 
			this->headDeviceChoices->FormattingEnabled = true;
			this->headDeviceChoices->Location = System::Drawing::Point(56, 68);
			this->headDeviceChoices->Name = L"headDeviceChoices";
			this->headDeviceChoices->Size = System::Drawing::Size(121, 21);
			this->headDeviceChoices->TabIndex = 9;
			// 
			// STCheck
			// 
			this->STCheck->AutoSize = true;
			this->STCheck->Location = System::Drawing::Point(31, 110);
			this->STCheck->Name = L"STCheck";
			this->STCheck->Size = System::Drawing::Size(15, 14);
			this->STCheck->TabIndex = 8;
			this->STCheck->UseVisualStyleBackColor = true;
			// 
			// HMDCheck
			// 
			this->HMDCheck->AutoSize = true;
			this->HMDCheck->Location = System::Drawing::Point(31, 50);
			this->HMDCheck->Name = L"HMDCheck";
			this->HMDCheck->Size = System::Drawing::Size(15, 14);
			this->HMDCheck->TabIndex = 7;
			this->HMDCheck->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(52, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Spatial Tracking";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(52, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Head Tracking";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel3->Location = System::Drawing::Point(21, 37);
			this->panel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(5, 254);
			this->panel3->TabIndex = 4;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold));
			this->Title->Location = System::Drawing::Point(16, 10);
			this->Title->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(190, 25);
			this->Title->TabIndex = 2;
			this->Title->Text = L"VR Purpose Setup";
			// 
			// DeviceWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(283, 434);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"DeviceWindow";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"S I V R";
			this->Load += gcnew System::EventHandler(this, &DeviceWindow::DeviceWindow_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeviceWindow_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

	


private: System::Void refreshDeviceList() {
	this->headDeviceChoices->Items->Clear();
	this->handDeviceChoices->Items->Clear();
	this->SpatialTrackingChoices->Items->Clear();
	this->miscDeviceChoices->Items->Clear();

	array<String^>^ headArray = ProcWorker::readDevices("Head");
	for each (String^ device in headArray) {
		this->headDeviceChoices->Items->Add(device);
	}

	array<String^>^ handArray = ProcWorker::readDevices("Hands");
	for each (String^ device in handArray) {
		this->handDeviceChoices->Items->Add(device);
	}

	array<String^>^ miscArray = ProcWorker::readDevices("Misc");
	for each (String^ device in miscArray) {
		this->miscDeviceChoices->Items->Add(device);
	}

	array<String^>^ spatialArray = ProcWorker::readDevices("Spatial");
	for each (String^ device in spatialArray) {
		this->SpatialTrackingChoices->Items->Add(device);
	}
}


//REFRESH DEVICE LIST
private: System::Void refreshDevices_Click(System::Object^  sender, System::EventArgs^  e) {
	refreshDeviceList();
}
private: System::Void miscDeviceChoices_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void KillClients_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ProcWorker::getBoss()->server->running) {
		ProcWorker::getBoss()->killServer();
		Console::WriteLine("Killing Server");
	}
	if(this->MDCheck->Checked)
		ProcWorker::getBoss()->killClient(DevType::Misc);
	if(this->HMDCheck->Checked)
		ProcWorker::getBoss()->killClient(DevType::HeadTracker);
	if(this->HTCheck->Checked)
		ProcWorker::getBoss()->killClient(DevType::HandTracker);
	if(this->STCheck->Checked)
		ProcWorker::getBoss()->killClient(DevType::Spatial);



	
	//SIVRServer* s = new SIVRServer(7777, "n", "n", "p", "b");

	//s->spatialData.positionArray[0] = 2.5;
	//s->spatialData.positionArray[1] = 5.12;
	//s->spatialData.positionArray[2] = 3.5;

	//s->miscData.positionArray[0] = 0.1;
	//s->miscData.positionArray[1] = 2.0;
	//s->miscData.positionArray[2] = 1.3;

	//s->miscData.rotationArray[0] = 0.2;
	//s->miscData.rotationArray[1] = 2.1;
	//s->miscData.rotationArray[2] = 1.4;
	//s->miscData.rotationArray[3] = 33.3;
	//Console::WriteLine("Oy");
	//char* st = s->MakeMsg();
	//Console::WriteLine(st);
	//
	//float pos1[3];
	//float rotation[4];
	//float position[3];

	//int psize = (sizeof(float)) * 3;
	//int rsize = (sizeof(float)) * 4;

	//memcpy(pos1, st, psize);
	//memcpy(position, st+psize, psize);
	//memcpy(rotation, st + psize+psize, rsize);
	//String^ strng = "";
	//for (int i = 0; i < 3; i++)
	//	strng += pos1[i].ToString() + " p1 ";
	//for (int i = 0; i < 3; i++)
	//	strng += position[i].ToString() + " p ";
	//for (int i = 0; i < 4; i++)
	//	strng += rotation[i].ToString() + " r ";

	//Console::WriteLine(strng);
}
private: System::Void applyDevicePurposes_Click_1(System::Object^  sender, System::EventArgs^  e) {
//	if (ProcWorker::getBoss()->curMax < ProcWorker::getBoss()->clientArray->Length) {

	int clientCount = 0;

	if (this->HMDCheck->Checked&&!this->headDeviceChoices->SelectedItem->ToString()->Equals("")) {
		//Console::WriteLine("Go");
		SIVConfig^ headConfig = ProcWorker::readConfig(DevType::HeadTracker, this->headDeviceChoices->SelectedItem->ToString());
		//Console::WriteLine("Master");
		ProcWorker::getBoss()->newClient(DevType::HeadTracker, this->headDeviceChoices->SelectedItem->ToString(), headConfig);
		clientCount++;
	}
	if (this->HTCheck->Checked&&!this->handDeviceChoices->SelectedItem->ToString()->Equals("")) {
		//Console::WriteLine("Go");
		SIVConfig^ handConfig = ProcWorker::readConfig(DevType::HandTracker, this->handDeviceChoices->SelectedItem->ToString());
		//Console::WriteLine("Master");
		ProcWorker::getBoss()->newClient(DevType::HandTracker, this->handDeviceChoices->SelectedItem->ToString(), handConfig);
		clientCount++;
	}
	if (this->STCheck->Checked&&!this->SpatialTrackingChoices->SelectedItem->ToString()->Equals("")) {
		//Console::WriteLine("Go");
		SIVConfig^ spatialConfig = ProcWorker::readConfig(DevType::Spatial, this->SpatialTrackingChoices->SelectedItem->ToString());
		//Console::WriteLine("Master");
		ProcWorker::getBoss()->newClient(DevType::Spatial, this->SpatialTrackingChoices->SelectedItem->ToString(), spatialConfig);
		clientCount++;
	}
	if (this->MDCheck->Checked&&!this->miscDeviceChoices->SelectedItem->ToString()->Equals("")) {
		//Console::WriteLine("Go");
		SIVConfig^ miscConfig = ProcWorker::readConfig(DevType::Misc, this->miscDeviceChoices->SelectedItem->ToString());
		//Console::WriteLine("Master");
		ProcWorker::getBoss()->newClient(DevType::Misc, this->miscDeviceChoices->SelectedItem->ToString(), miscConfig);
		clientCount++;
	}

	if (clientCount > 0) {
		Console::WriteLine("Start");

		ProcWorker::getBoss()->startServer();
	}
	else
		Console::WriteLine("No clients selected to launch.");
		/*
		switch (this->devTypeBox->SelectedIndex) {
		//hmds
		case 0:
		break;
		//trackers
		case 1:
		break;
		//gamepads
		case 2:
		if (this->miscDeviceChoices->Items[this->miscDeviceChoices->SelectedIndex]->ToString()=="XInput") {
		Console::WriteLine("Go");
		ProcWorker::readConfig(DevType::Gamepad, "XInput");
		//ProcWorker::getBoss()->newClient(DevType::Gamepad,"XInput0", ProcWorker::GetCfg("Misc"));
		ProcWorker::GetCfg("Misc");
		}
		break;
		//misc devices
		case 3:
		Console::Write("Mouse");
		if (this->MiscDevicesBox->CheckedItems->Contains("Mouse")) {
		Console::Write("Mouse");
		//ProcWorker::getBoss()->newClient(DevType::Mouse, "Mouse0");
		}
		break;
		default:
		break;
		*/
//	}
	//else
	//	printf("Max Number of Devices achieved\n");
}

};
}
