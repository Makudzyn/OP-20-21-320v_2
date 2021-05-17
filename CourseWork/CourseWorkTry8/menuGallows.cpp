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
    gameGallows^ form = gcnew gameGallows();//Создание формы
    this->Hide(); //Закрытие текущей
    form->Show(); //Открытие созданной
}

System::Void CourseWorkTry8::menuGallows::menuRules_Click(System::Object^ sender, System::EventArgs^ e){
    MessageBox::Show("Виселица (GallowsGame) - всем известная логическая игра, в которой нужно отгадать по буквам слово. Угадывать буквы нужно верно, в противном случае к нарисованной виселице будут добавляться детали. Если виселица соберётся полностью - вы проиграете.", "Правила");
}

System::Void CourseWorkTry8::menuGallows::menuExit_Click(System::Object^ sender, System::EventArgs^ e){
    Application::Exit();
}

System::Void CourseWorkTry8::menuGallows::menuToolStrip_Click(System::Object^ sender, System::EventArgs^ e){
    return System::Void(); MessageBox::Show("Game created by Maksim Kunchenko", "Info", MessageBoxButtons::OK);
}
