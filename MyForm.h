#pragma once
#include "Header.h"
namespace CLRPROJECT {

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
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Full_timetable;
	protected:

	private: System::Windows::Forms::Button^  Students_Info;
	private: System::Windows::Forms::Button^  Student_timetable;
	private: System::Windows::Forms::Button^  student_courses;
	private: System::Windows::Forms::Button^  Course_timing;
	private: System::Windows::Forms::Button^  Print_course;
	private: System::Windows::Forms::Button^  Save_clashes;
	private: System::Windows::Forms::Label^  label1;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Full_timetable = (gcnew System::Windows::Forms::Button());
			this->Students_Info = (gcnew System::Windows::Forms::Button());
			this->Student_timetable = (gcnew System::Windows::Forms::Button());
			this->student_courses = (gcnew System::Windows::Forms::Button());
			this->Course_timing = (gcnew System::Windows::Forms::Button());
			this->Print_course = (gcnew System::Windows::Forms::Button());
			this->Save_clashes = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Full_timetable
			// 
			this->Full_timetable->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Full_timetable->Location = System::Drawing::Point(281, 145);
			this->Full_timetable->Name = L"Full_timetable";
			this->Full_timetable->Size = System::Drawing::Size(161, 57);
			this->Full_timetable->TabIndex = 0;
			this->Full_timetable->Text = L"Full timetable";
			this->Full_timetable->UseVisualStyleBackColor = false;
			this->Full_timetable->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Students_Info
			// 
			this->Students_Info->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Students_Info->Location = System::Drawing::Point(500, 145);
			this->Students_Info->Name = L"Students_Info";
			this->Students_Info->Size = System::Drawing::Size(164, 57);
			this->Students_Info->TabIndex = 2;
			this->Students_Info->Text = L"Students Info";
			this->Students_Info->UseVisualStyleBackColor = false;
			this->Students_Info->Click += gcnew System::EventHandler(this, &MyForm::CPP_Click);
			// 
			// Student_timetable
			// 
			this->Student_timetable->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Student_timetable->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Student_timetable->Location = System::Drawing::Point(281, 264);
			this->Student_timetable->Name = L"Student_timetable";
			this->Student_timetable->Size = System::Drawing::Size(161, 61);
			this->Student_timetable->TabIndex = 3;
			this->Student_timetable->Text = L"Student timetable";
			this->Student_timetable->UseVisualStyleBackColor = false;
			this->Student_timetable->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// student_courses
			// 
			this->student_courses->BackColor = System::Drawing::SystemColors::ControlDark;
			this->student_courses->Location = System::Drawing::Point(500, 264);
			this->student_courses->Name = L"student_courses";
			this->student_courses->Size = System::Drawing::Size(164, 61);
			this->student_courses->TabIndex = 4;
			this->student_courses->Text = L"Student Courses";
			this->student_courses->UseVisualStyleBackColor = false;
			this->student_courses->Click += gcnew System::EventHandler(this, &MyForm::student_courses_Click);
			// 
			// Course_timing
			// 
			this->Course_timing->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Course_timing->Location = System::Drawing::Point(281, 394);
			this->Course_timing->Name = L"Course_timing";
			this->Course_timing->Size = System::Drawing::Size(161, 57);
			this->Course_timing->TabIndex = 5;
			this->Course_timing->Text = L"Course Timing";
			this->Course_timing->UseVisualStyleBackColor = false;
			this->Course_timing->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// Print_course
			// 
			this->Print_course->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Print_course->Location = System::Drawing::Point(500, 394);
			this->Print_course->Name = L"Print_course";
			this->Print_course->Size = System::Drawing::Size(154, 57);
			this->Print_course->TabIndex = 6;
			this->Print_course->Text = L"Print Course";
			this->Print_course->UseVisualStyleBackColor = false;
			this->Print_course->Click += gcnew System::EventHandler(this, &MyForm::Print_course_Click);
			// 
			// Save_clashes
			// 
			this->Save_clashes->BackColor = System::Drawing::SystemColors::ControlDark;
			this->Save_clashes->Location = System::Drawing::Point(281, 516);
			this->Save_clashes->Name = L"Save_clashes";
			this->Save_clashes->Size = System::Drawing::Size(161, 55);
			this->Save_clashes->TabIndex = 7;
			this->Save_clashes->Text = L"Save Clashes";
			this->Save_clashes->UseVisualStyleBackColor = false;
			this->Save_clashes->Click += gcnew System::EventHandler(this, &MyForm::Save_clashes_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(256, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(398, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TIMETABLE";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1052, 755);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Save_clashes);
			this->Controls->Add(this->Print_course);
			this->Controls->Add(this->Course_timing);
			this->Controls->Add(this->student_courses);
			this->Controls->Add(this->Student_timetable);
			this->Controls->Add(this->Students_Info);
			this->Controls->Add(this->Full_timetable);
			this->Name = L"MyForm";
			this->Text = L"TIME TABLE";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	//total subjects print
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		TTADT t;
		t.load_function("input.csv");
		t.print();
		MessageBox::Show("check Full timetable file");
	}
	//student info print
	private: System::Void CPP_Click(System::Object^  sender, System::EventArgs^  e) {

		TTADT t;
		t.load_function("input.csv");
		t.loadStudentInfo("Registration data.csv");
		t.Student_Info_print();
		MessageBox::Show("check Student_Info_print file");

	}

	//Print student timetable


	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		TTADT t;
		t.load_function("input.csv");
		t.loadStudentInfo("Registration data.csv");
		t.printStudentTimeTable("322");
		MessageBox::Show("check printStudentTimeTable file");
	}

	//Print student courses
private: System::Void student_courses_Click(System::Object^  sender, System::EventArgs^  e) {
	TTADT t;
	t.load_function("input.csv");
	t.loadStudentInfo("Registration data.csv");
	t.printStudentCourses("322");
	MessageBox::Show("check printStudentCourses file");
}
	//Specific Course timing

private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
	TTADT t;
	t.load_function("input.csv");
	t.loadStudentInfo("Registration data.csv");
	t.printCourseTimings("Human Computer Interaction","CS-E");
	MessageBox::Show("check printCourseTimings file");
}
	//print course on a specific daya,time and room number

private: System::Void Print_course_Click(System::Object^  sender, System::EventArgs^  e) {
	TTADT t;
	t.load_function("input.csv");
	t.loadStudentInfo("Registration data.csv");
	t.printCourse("Wednesday", "11:00 am","CS-2");
	MessageBox::Show("check printCourse file");
}
	//save clashes

private: System::Void Save_clashes_Click(System::Object^  sender, System::EventArgs^  e) {
	TTADT t;
	t.load_function("input.csv");
	t.loadStudentInfo("Registration data.csv");
	t.saveClashes();
	MessageBox::Show("check saveClashes file");
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
