#include "FormPrincipal.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:main")

using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Grafico::FormPrincipal form;
	Application::Run(% form);
}
