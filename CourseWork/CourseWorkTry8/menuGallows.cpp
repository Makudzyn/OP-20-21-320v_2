#include "menuGallows.h"
#include "gameGallows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CourseWorkTry8::menuGallows form;
    Application::Run(% form);
}


System::Void CourseWorkTry8::menuGallows::menuStart_Click(System::Object^ sender, System::EventArgs^ e){
    gameGallows^ form = gcnew gameGallows();//�������� �����
    this->Hide(); //�������� �������
    form->Show(); //�������� ���������
}

System::Void CourseWorkTry8::menuGallows::menuRules_Click(System::Object^ sender, System::EventArgs^ e){
    MessageBox::Show("�������� (GallowsGame) - ���� ��������� ���������� ����, � ������� ����� �������� �� ������ �����. ��������� ����� ����� �����, � ��������� ������ � ������������ �������� ����� ����������� ������. ���� �������� �������� ��������� - �� ����������.", "�������");
}

System::Void CourseWorkTry8::menuGallows::menuExit_Click(System::Object^ sender, System::EventArgs^ e){
    Application::Exit();
}

System::Void CourseWorkTry8::menuGallows::menuToolStrip_Click(System::Object^ sender, System::EventArgs^ e){
    return System::Void(); MessageBox::Show("Game created by Maksim Kunchenko", "Info", MessageBoxButtons::OK);
}
