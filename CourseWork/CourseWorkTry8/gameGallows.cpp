#include "gameGallows.h"
#include "menuGallows.h"
#include "functions.h"

std::string word, scrtWord;
int sizeWord = 0, hptrue = 0, hp = 0, count = 0;
bool flag = false;


System::Void CourseWorkTry8::gameGallows::wordEntbutton_Click(System::Object^ sender, System::EventArgs^ e){
    hptrue = 0; hp = 0;
    word.clear();
    scrtWord.clear();
    hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\0.jpg");
    mainLabel->Text = "";
    String^ text = wordTextBox->Text->ToString();
    word = Convert_String_to_string(text, word);
    for (int i = 0; i < text->Length; i++) {
        mainLabel->Text += "?";
        scrtWord += "?";
        sizeWord++;
    }

    wordTextBox->Text = "";
}


System::Void CourseWorkTry8::gameGallows::letterEntButton_Click(System::Object^ sender, System::EventArgs^ e) {
    flag = false;
    
    if (letterTextBox->Text->Length == 1) { 
        for (int i = 0; i < sizeWord; i++) {
            if (letterTextBox->Text[0] == word[i]) {
                flag = true;
                hptrue++;
                scrtWord[i] = word[i];
                mainLabel->Text = "";
            }
        }
        if (flag == true) {
            mainLabel->Text = Convert_string_to_String(scrtWord);
            if (hptrue == sizeWord) MessageBox::Show("Ты победил!");
        }
        else if(flag == false) {
            hp++;
            if (hp == 1) 
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\1.jpg");
            if (hp == 2)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\2.jpg");
            if (hp == 3)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\3.jpg");
            if (hp == 4)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\4.jpg");
            if (hp == 5)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\5.jpg");
            if (hp == 6)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\6.jpg");
            if (hp == 7)
                hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\7.jpg");

            if (hp == 7) {
                MessageBox::Show("Ты проиграл!");
                mainLabel->Text = "";
                mainLabel->Text = Convert_string_to_String(word);
            }
        }
    }
    else if (letterTextBox->Text->Length > 1){
        if (letterTextBox->Text == Convert_string_to_String(word)){
            mainLabel->Text = "";
            for (int i = 0; i < sizeWord; i++) {
                mainLabel->Text += word[i];
            }
            MessageBox::Show("Ты победил!");
        }
        else{
            hangmanPictureBox->Image = Image::FromFile("C:\\Users\\alt\\source\\repos\\CourseWorkTry8\\CourseWorkTry8\\Images\\7.jpg");
            MessageBox::Show("Ты проиграл!");
            mainLabel->Text = "";
            mainLabel->Text = Convert_string_to_String(word);
        }
    }
    letterTextBox->Text = "";
}
