#pragma once
#include <fstream>
#include <string>
#include "ProcWorker.h"

namespace ProjectS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DeviceWindow
	/// </summary>
	public ref class DeviceWindow : public System::Windows::Forms::Form
	{
	public:
		DeviceWindow(void)
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
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// devTypeBox
			// 
			this->devTypeBox->FormattingEnabled = true;
			this->devTypeBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"HMD", L"Tracker", L"Gamepad", L"Misc Devices" });
			this->devTypeBox->Location = System::Drawing::Point(12, 49);
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
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(979, 471);
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
			this->MiscDevicesBox->Location = System::Drawing::Point(3, 3);
			this->MiscDevicesBox->Name = L"MiscDevicesBox";
			this->MiscDevicesBox->Size = System::Drawing::Size(323, 214);
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
			this->TrackerBox->Location = System::Drawing::Point(332, 3);
			this->TrackerBox->Name = L"TrackerBox";
			this->TrackerBox->Size = System::Drawing::Size(323, 214);
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
			this->GamepadBox->Location = System::Drawing::Point(3, 223);
			this->GamepadBox->Name = L"GamepadBox";
			this->GamepadBox->Size = System::Drawing::Size(323, 214);
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
			this->HMDbox->Location = System::Drawing::Point(332, 223);
			this->HMDbox->Name = L"HMDbox";
			this->HMDbox->Size = System::Drawing::Size(323, 214);
			this->HMDbox->TabIndex = 0;
			this->HMDbox->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel1->Location = System::Drawing::Point(18, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(19, 471);
			this->panel1->TabIndex = 3;
			// 
			// applyDevices
			// 
			this->applyDevices->Location = System::Drawing::Point(128, 571);
			this->applyDevices->Name = L"applyDevices";
			this->applyDevices->Size = System::Drawing::Size(88, 26);
			this->applyDevices->TabIndex = 4;
			this->applyDevices->Text = L"Apply";
			this->applyDevices->UseVisualStyleBackColor = true;
			// 
			// appliedRB
			// 
			this->appliedRB->AutoCheck = false;
			this->appliedRB->AutoSize = true;
			this->appliedRB->Location = System::Drawing::Point(223, 575);
			this->appliedRB->Name = L"appliedRB";
			this->appliedRB->Size = System::Drawing::Size(17, 16);
			this->appliedRB->TabIndex = 5;
			this->appliedRB->TabStop = true;
			this->appliedRB->UseVisualStyleBackColor = true;
			// 
			// DeviceWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(486, 768);
			this->Controls->Add(this->appliedRB);
			this->Controls->Add(this->applyDevices);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->devTypeBox);
			this->Name = L"DeviceWindow";
			this->Text = L"DeviceWindow";
			this->Load += gcnew System::EventHandler(this, &DeviceWindow::DeviceWindow_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
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
};
}