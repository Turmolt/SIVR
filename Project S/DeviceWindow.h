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
	private: System::Windows::Forms::ComboBox^  devTypeBox;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::CheckedListBox^  HMDbox;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  applyDevices;
	private: System::Windows::Forms::RadioButton^  appliedRB;
	private: System::Windows::Forms::CheckedListBox^  MiscDevicesBox;
	private: System::Windows::Forms::CheckedListBox^  TrackerBox;
	private: System::Windows::Forms::CheckedListBox^  GamepadBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->devTypeBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->MiscDevicesBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->TrackerBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->GamepadBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->HMDbox = (gcnew System::Windows::Forms::CheckedListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->applyDevices = (gcnew System::Windows::Forms::Button());
			this->appliedRB = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			this->flowLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// devTypeBox
			// 
			this->devTypeBox->FormattingEnabled = true;
			this->devTypeBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"HMD", L"Tracker", L"Gamepad", L"Misc Devices" });
			this->devTypeBox->Location = System::Drawing::Point(12, 49);
			this->devTypeBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->devTypeBox->Name = L"devTypeBox";
			this->devTypeBox->Size = System::Drawing::Size(155, 24);
			this->devTypeBox->TabIndex = 0;
			this->devTypeBox->SelectedIndexChanged += gcnew System::EventHandler(this, &DeviceWindow::devTypeBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(13, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Device Type";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->MiscDevicesBox);
			this->flowLayoutPanel1->Controls->Add(this->TrackerBox);
			this->flowLayoutPanel1->Controls->Add(this->GamepadBox);
			this->flowLayoutPanel1->Controls->Add(this->HMDbox);
			this->flowLayoutPanel1->Location = System::Drawing::Point(43, 79);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(675, 471);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// MiscDevicesBox
			// 
			this->MiscDevicesBox->BackColor = System::Drawing::Color::AliceBlue;
			this->MiscDevicesBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->MiscDevicesBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MiscDevicesBox->FormattingEnabled = true;
			this->MiscDevicesBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Brenden Peter\'s Motion Platform", L"Mouse",
					L"Joystick"
			});
			this->MiscDevicesBox->Location = System::Drawing::Point(3, 2);
			this->MiscDevicesBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MiscDevicesBox->Name = L"MiscDevicesBox";
			this->MiscDevicesBox->Size = System::Drawing::Size(323, 193);
			this->MiscDevicesBox->TabIndex = 3;
			this->MiscDevicesBox->Visible = false;
			// 
			// TrackerBox
			// 
			this->TrackerBox->BackColor = System::Drawing::Color::AliceBlue;
			this->TrackerBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->TrackerBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->TrackerBox->FormattingEnabled = true;
			this->TrackerBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Phasespace", L"PPT System" });
			this->TrackerBox->Location = System::Drawing::Point(332, 2);
			this->TrackerBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TrackerBox->Name = L"TrackerBox";
			this->TrackerBox->Size = System::Drawing::Size(323, 193);
			this->TrackerBox->TabIndex = 2;
			this->TrackerBox->Visible = false;
			// 
			// GamepadBox
			// 
			this->GamepadBox->BackColor = System::Drawing::Color::AliceBlue;
			this->GamepadBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->GamepadBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->GamepadBox->FormattingEnabled = true;
			this->GamepadBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Playstation 3", L"Playstation 4", L"Xbox 360",
					L"Xbox One", L"Logitech", L"Mayflash Gamecube", L"Wiimote"
			});
			this->GamepadBox->Location = System::Drawing::Point(3, 199);
			this->GamepadBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->GamepadBox->Name = L"GamepadBox";
			this->GamepadBox->Size = System::Drawing::Size(323, 193);
			this->GamepadBox->TabIndex = 1;
			this->GamepadBox->Visible = false;
			// 
			// HMDbox
			// 
			this->HMDbox->BackColor = System::Drawing::Color::AliceBlue;
			this->HMDbox->Cursor = System::Windows::Forms::Cursors::Default;
			this->HMDbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->HMDbox->FormattingEnabled = true;
			this->HMDbox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Oculus Rift", L"zSight", L"dSight", L"SX111", L"Hololense" });
			this->HMDbox->Location = System::Drawing::Point(332, 199);
			this->HMDbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HMDbox->Name = L"HMDbox";
			this->HMDbox->Size = System::Drawing::Size(323, 193);
			this->HMDbox->TabIndex = 0;
			this->HMDbox->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel1->Location = System::Drawing::Point(19, 79);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(19, 471);
			this->panel1->TabIndex = 3;
			// 
			// applyDevices
			// 
			this->applyDevices->Location = System::Drawing::Point(128, 571);
			this->applyDevices->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->applyDevices->Name = L"applyDevices";
			this->applyDevices->Size = System::Drawing::Size(88, 26);
			this->applyDevices->TabIndex = 4;
			this->applyDevices->Text = L"Apply";
			this->applyDevices->UseVisualStyleBackColor = true;
			this->applyDevices->Click += gcnew System::EventHandler(this, &DeviceWindow::applyDevices_Click);
			// 
			// appliedRB
			// 
			this->appliedRB->AutoCheck = false;
			this->appliedRB->AutoSize = true;
			this->appliedRB->Location = System::Drawing::Point(223, 575);
			this->appliedRB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->appliedRB->Name = L"appliedRB";
			this->appliedRB->Size = System::Drawing::Size(17, 16);
			this->appliedRB->TabIndex = 5;
			this->appliedRB->TabStop = true;
			this->appliedRB->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 623);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Kill Client";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DeviceWindow::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Head", L"Hands", L"Tracker", L"Gamepad", L"Mouse" });
			this->comboBox1->Location = System::Drawing::Point(240, 623);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(160, 24);
			this->comboBox1->TabIndex = 7;
			// 
			// panel2
			// 
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
			this->panel2->Location = System::Drawing::Point(741, 15);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(345, 508);
			this->panel2->TabIndex = 8;
			// 
			// refreshDevices
			// 
			this->refreshDevices->Location = System::Drawing::Point(104, 380);
			this->refreshDevices->Margin = System::Windows::Forms::Padding(4);
			this->refreshDevices->Name = L"refreshDevices";
			this->refreshDevices->Size = System::Drawing::Size(100, 28);
			this->refreshDevices->TabIndex = 19;
			this->refreshDevices->Text = L"Refresh";
			this->refreshDevices->UseVisualStyleBackColor = true;
			this->refreshDevices->Click += gcnew System::EventHandler(this, &DeviceWindow::refreshDevices_Click);
			// 
			// KillClients
			// 
			this->KillClients->Location = System::Drawing::Point(104, 452);
			this->KillClients->Margin = System::Windows::Forms::Padding(4);
			this->KillClients->Name = L"KillClients";
			this->KillClients->Size = System::Drawing::Size(100, 28);
			this->KillClients->TabIndex = 18;
			this->KillClients->Text = L"Kill Clients";
			this->KillClients->UseVisualStyleBackColor = true;
			this->KillClients->Click += gcnew System::EventHandler(this, &DeviceWindow::KillClients_Click);
			// 
			// applyDevicePurposes
			// 
			this->applyDevicePurposes->Location = System::Drawing::Point(104, 416);
			this->applyDevicePurposes->Margin = System::Windows::Forms::Padding(4);
			this->applyDevicePurposes->Name = L"applyDevicePurposes";
			this->applyDevicePurposes->Size = System::Drawing::Size(100, 28);
			this->applyDevicePurposes->TabIndex = 17;
			this->applyDevicePurposes->Text = L"Apply";
			this->applyDevicePurposes->UseVisualStyleBackColor = true;
			// 
			// miscDeviceChoices
			// 
			this->miscDeviceChoices->FormattingEnabled = true;
			this->miscDeviceChoices->Location = System::Drawing::Point(75, 308);
			this->miscDeviceChoices->Margin = System::Windows::Forms::Padding(4);
			this->miscDeviceChoices->Name = L"miscDeviceChoices";
			this->miscDeviceChoices->Size = System::Drawing::Size(160, 24);
			this->miscDeviceChoices->TabIndex = 16;
			this->miscDeviceChoices->SelectedIndexChanged += gcnew System::EventHandler(this, &DeviceWindow::miscDeviceChoices_SelectedIndexChanged);
			// 
			// MDCheck
			// 
			this->MDCheck->AutoSize = true;
			this->MDCheck->Location = System::Drawing::Point(41, 286);
			this->MDCheck->Margin = System::Windows::Forms::Padding(4);
			this->MDCheck->Name = L"MDCheck";
			this->MDCheck->Size = System::Drawing::Size(18, 17);
			this->MDCheck->TabIndex = 15;
			this->MDCheck->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(69, 279);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 25);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Misc Devices";
			// 
			// handDeviceChoices
			// 
			this->handDeviceChoices->FormattingEnabled = true;
			this->handDeviceChoices->Location = System::Drawing::Point(75, 233);
			this->handDeviceChoices->Margin = System::Windows::Forms::Padding(4);
			this->handDeviceChoices->Name = L"handDeviceChoices";
			this->handDeviceChoices->Size = System::Drawing::Size(160, 24);
			this->handDeviceChoices->TabIndex = 13;
			// 
			// HTCheck
			// 
			this->HTCheck->AutoSize = true;
			this->HTCheck->Location = System::Drawing::Point(41, 210);
			this->HTCheck->Margin = System::Windows::Forms::Padding(4);
			this->HTCheck->Name = L"HTCheck";
			this->HTCheck->Size = System::Drawing::Size(18, 17);
			this->HTCheck->TabIndex = 12;
			this->HTCheck->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(69, 204);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Hand Tracking";
			// 
			// SpatialTrackingChoices
			// 
			this->SpatialTrackingChoices->FormattingEnabled = true;
			this->SpatialTrackingChoices->Location = System::Drawing::Point(75, 158);
			this->SpatialTrackingChoices->Margin = System::Windows::Forms::Padding(4);
			this->SpatialTrackingChoices->Name = L"SpatialTrackingChoices";
			this->SpatialTrackingChoices->Size = System::Drawing::Size(160, 24);
			this->SpatialTrackingChoices->TabIndex = 10;
			// 
			// headDeviceChoices
			// 
			this->headDeviceChoices->FormattingEnabled = true;
			this->headDeviceChoices->Location = System::Drawing::Point(75, 84);
			this->headDeviceChoices->Margin = System::Windows::Forms::Padding(4);
			this->headDeviceChoices->Name = L"headDeviceChoices";
			this->headDeviceChoices->Size = System::Drawing::Size(160, 24);
			this->headDeviceChoices->TabIndex = 9;
			// 
			// STCheck
			// 
			this->STCheck->AutoSize = true;
			this->STCheck->Location = System::Drawing::Point(41, 135);
			this->STCheck->Margin = System::Windows::Forms::Padding(4);
			this->STCheck->Name = L"STCheck";
			this->STCheck->Size = System::Drawing::Size(18, 17);
			this->STCheck->TabIndex = 8;
			this->STCheck->UseVisualStyleBackColor = true;
			// 
			// HMDCheck
			// 
			this->HMDCheck->AutoSize = true;
			this->HMDCheck->Location = System::Drawing::Point(41, 62);
			this->HMDCheck->Margin = System::Windows::Forms::Padding(4);
			this->HMDCheck->Name = L"HMDCheck";
			this->HMDCheck->Size = System::Drawing::Size(18, 17);
			this->HMDCheck->TabIndex = 7;
			this->HMDCheck->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(69, 129);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Spatial Tracking";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(69, 55);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(140, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Head Tracking";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel3->Location = System::Drawing::Point(28, 46);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(7, 313);
			this->panel3->TabIndex = 4;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold));
			this->Title->Location = System::Drawing::Point(21, 12);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(285, 29);
			this->Title->TabIndex = 2;
			this->Title->Text = L"Device Purpose Setup";
			// 
			// DeviceWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1105, 768);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->appliedRB);
			this->Controls->Add(this->applyDevices);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->devTypeBox);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"DeviceWindow";
			this->Text = L"DeviceWindow";
			this->Load += gcnew System::EventHandler(this, &DeviceWindow::DeviceWindow_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeviceWindow_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

	//select the device type box to be displayed
	private: System::Void devTypeBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		switch (this->devTypeBox->SelectedIndex) {
		case 0:
			this->HMDbox->Visible = true;
			this->GamepadBox->Visible = false;
			this->TrackerBox->Visible = false;
			this->MiscDevicesBox->Visible = false;
			break;
		case 1:
			this->HMDbox->Visible = false;
			this->GamepadBox->Visible = false;
			this->TrackerBox->Visible = true;
			this->MiscDevicesBox->Visible = false;
			break;
		case 2:
			this->HMDbox->Visible = false;
			this->GamepadBox->Visible = true;
			this->TrackerBox->Visible = false;
			this->MiscDevicesBox->Visible = false;
			break;
		case 3:
			this->HMDbox->Visible = false;
			this->GamepadBox->Visible = false;
			this->TrackerBox->Visible = false;
			this->MiscDevicesBox->Visible = true;
			break;
		default:
			break;
		}
	}

private: System::Void applyDevices_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ProcWorker::getBoss()->curMax < ProcWorker::getBoss()->clientArray->Length)
		switch (this->devTypeBox->SelectedIndex) {
			//hmds
		case 0:
			break;
			//trackers
		case 1:
			break;
			//gamepads
		case 2:
			if (this->GamepadBox->CheckedItems->Contains("Xbox 360")) {

				ProcWorker::getBoss()->newClient(DevType::Gamepad,"XInput0");
		}	
			break;
			//misc devices
		case 3:
			Console::Write("Mouse");
			if (this->MiscDevicesBox->CheckedItems->Contains("Mouse")) {
				Console::Write("Mouse");
				ProcWorker::getBoss()->newClient(DevType::Mouse, "Mouse0");
			}
			break;
		default:
			break;
		}
	else
		printf("Max Number of Devices achieved\n");
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	switch (this->comboBox1->SelectedIndex) {
	case 0:
		ProcWorker::getBoss()->killClient(DevType::HMD);
		break;
	case 1:
		ProcWorker::getBoss()->killClient(DevType::HandTracker);
		break;
	case 2:
		ProcWorker::getBoss()->killClient(DevType::Spatial);
		break;
	case 3:
		ProcWorker::getBoss()->killClient(DevType::Gamepad);
		break;
	case 4:
		ProcWorker::getBoss()->killClient(DevType::Mouse);
		break;
	case 5:
		ProcWorker::getBoss()->killClient(DevType::HeadTracker);
		break;
	}
}




//REFRESH DEVICE LIST
private: System::Void refreshDevices_Click(System::Object^  sender, System::EventArgs^  e) {
	this->headDeviceChoices->Items->Clear();
	this->handDeviceChoices->Items->Clear();
	this->SpatialTrackingChoices->Items->Clear();
	this->miscDeviceChoices->Items->Clear();

	array<SIVConfig^>^ headArray = ProcWorker::readDevices("Head");
	for each (SIVConfig^ device in headArray) {
		this->headDeviceChoices->Items->Add(device->deviceName);
	}

	array<SIVConfig^>^ handArray = ProcWorker::readDevices("Hands");
	for each (SIVConfig^ device in handArray) {
		this->handDeviceChoices->Items->Add(device->deviceName);
	}

	array<SIVConfig^>^ miscArray = ProcWorker::readDevices("Misc");
	for each (SIVConfig^ device in miscArray){
		this->miscDeviceChoices->Items->Add(device->deviceName);
	}

	array<SIVConfig^>^ spatialArray = ProcWorker::readDevices("Spatial");
	for each (SIVConfig^ device in spatialArray) {
		this->SpatialTrackingChoices->Items->Add(device->deviceName);
	}

}
private: System::Void miscDeviceChoices_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void KillClients_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
