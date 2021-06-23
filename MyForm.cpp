#include "MyForm.h"

using namespace System;

[STAThreadAttribute]

void main()
{

	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew::CLRPROJECT::MyForm());

}


