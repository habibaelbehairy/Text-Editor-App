#include "mainwindow.h"
#include "ui_mainwindow.h"

QString text;
int numOfWords;
int numOfLines = 1;
vector<string> word;
string searchWord;
string countWord;
QString secText;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->seacrhLabel->hide();
    ui->textSeacrh->hide();
    ui->find->hide();
    ui->count_btn->hide();
    ui->textCount->hide();
    ui->countLabel->hide();


}

MainWindow::~MainWindow()
{
    delete ui;

}

void Turn_file_content_to_first_caps()
{
    string tempText = text.toUtf8().constData();
    for (int i = 0; i < text.length(); i++)
    {
        tempText[i] = tolower(tempText[i]);
    }

    tempText[0] = toupper(tempText[0]);

    for (int i = 0; i < tempText.length(); i++)
    {
        if ((tempText[i] == ' ') || (tempText[i] == '\n'))
        {
            tempText[i+1] = toupper(tempText[i+1]);
        }
    }
    text = QString::fromStdString(tempText);
}


void Turn_the_content_to_lower_case()
{
    string tempText = text.toUtf8().constData();
    for (int i = 0; i < tempText.length(); i++)
    {
        tempText[i] = tolower(tempText[i]);
    }
    text = QString::fromStdString(tempText);
}


void Turn_the_content_to_upper_case()
{
    string tempText = text.toUtf8().constData();
    for (int i = 0; i < tempText.length(); i++)
    {
        tempText[i] = toupper(tempText[i]);
    }
    text = QString::fromStdString(tempText);
}
int Count_the_number_of_times_a_word_exists_in_the_file(string search)
{
    string upper;
    int s = 0, counter = 0;
    vector_of_word();
    for (int x = 0; x < search.length(); x++)
    {
        search[x] = toupper(search[x]);
    }



    for (int y = 0; y < word.size(); y++)
    {
        upper = word[y];
        for (int z = 0; z < upper.length(); z++)
        {
            upper[z] = toupper(upper[z]);
        }

        if (search == upper)
        {
            s++;
            counter += 1;
        }
    }
    if (s > 0)
    {
        return counter;
        s = 0;
    }
    else
    {
        return 0;
    }
    word.clear();

}

bool Search_for_a_word_in_the_file(string search)
{
    string upper;
    int s = 0 ;
    vector_of_word();
    for (int x = 0; x < search.length(); x++)
    {
        search[x] = toupper(search[x]);
    }



    for (int y = 0; y < word.size(); y++)
    {
        upper = word[y];
        for (int z = 0; z < upper.length(); z++)
        {
            upper[z] = toupper(upper[z]);
        }

        if (search == upper)
        {
            s++;
        }
    }
    if (s > 0)
    {
        return true;
        s = 0;
    }
    else
    {
        return false;
    }


    word.clear();

}

void vector_of_word()
{
    string tempText = text.toUtf8().constData();
    string letters = "";
    int i = 0;

    while (i < tempText.length())
    {
        if ((tempText[i] != ' ') && (tempText[i] != '\n'))
        {
            letters += tempText[i];
            //i++;
        }
        else // (letters.size() != 0)
        {
            word.push_back(letters);
            letters.clear();
        }
        i++;
    }
    word.push_back(letters);

}
void Count_the_number_of_words()
{
    vector_of_word();
    numOfWords = word.size();
    word.clear();
}

void Count_the_number_of_lines()
{
    numOfLines = 1;
    for (int i = 0; i < text.length(); i++)
    {
      if (text[i] == '\n')
      {
            ++numOfLines;
      }
    }
    if (text == "")
    {
       numOfLines = 0;
    }
}

void encrypt()
{

    string tempText = text.toUtf8().constData();
    string encryption = "";
    int numofshifts=1;

    for (int c = 0; c < tempText.length(); c++)
    {


        if (tempText[c] == '\n')
        {
            encryption+='\n';
        }
        else
        {
        encryption += char(int(tempText[c]) + numofshifts);
        }


    }
    tempText = encryption;
    text = QString::fromStdString(tempText);

}


void decrypt()
{
    string tempText = text.toUtf8().constData();
    string decryption= "";
    int numofshifts=1;

    for (int c = 0; c < tempText.length(); c++)
    {


        if (tempText[c] == '\n')
        {
            decryption+='\n';
        }
        else
        {
        decryption += char(int(tempText[c]) - numofshifts);
        }


    }
    tempText = decryption;
    text = QString::fromStdString(tempText);

}

void MainWindow::on_btn_open_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Choose The File");
    QFile file (file_name);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "..", "Couldn't Open File");
        return;

    }
    QTextStream in(&file);
    text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_btn_save_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Choose The File", "Untitled","(*.txt)");
    QFile file (file_name);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "..", "Couldn't Open File");
        return;

    }
    QTextStream out(&file);
    QString SaveText = ui->textEdit->toPlainText();
    out << SaveText;
    file.flush();
    file.close();
}


void MainWindow::on_btn_encrypt_clicked()
{

    encrypt();
    ui->textEdit->setText(text);
}

void MainWindow::on_btn_decrypt_clicked()
{
    decrypt();
    ui->textEdit->setText(text);
}


void MainWindow::on_textEdit_textChanged()
{
    text = ui->textEdit->toPlainText();
    Count_the_number_of_words();
    Count_the_number_of_lines();
    QString words = QString::number(numOfWords);
    ui->wordsNum->setText(words);
    QString lines = QString::number(numOfLines);
    ui->linesNum->setText(lines);
}


void MainWindow::on_btn_edit_6_clicked()
{
    Turn_the_content_to_upper_case();
    ui->textEdit->setText(text);
}


void MainWindow::on_btn_edit_7_clicked()
{
    Turn_the_content_to_lower_case();
    ui->textEdit->setText(text);

}


void MainWindow::on_btn_edit_8_clicked()
{
    Turn_file_content_to_first_caps();
    ui->textEdit->setText(text);
}


void MainWindow::on_btn_edit_4_clicked()
{
    ui->seacrhLabel->show();
    ui->textSeacrh->show();
    ui->find->show();
    ui->count_btn->hide();
    ui->textCount->hide();
    ui->countLabel->hide();
}


void MainWindow::on_find_clicked()
{
    QString s;
    s = ui->textSeacrh->toPlainText();
    searchWord = s.toUtf8().constData();
    if (Search_for_a_word_in_the_file(searchWord))
    {
         QMessageBox::information(0, QString ("Result"), QString("The Word Exists!"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(0, QString ("Result"), QString("The Word Doesn't Exist!"),QMessageBox::Ok);
    }
    ui->seacrhLabel->hide();
    ui->textSeacrh->setText("");
    ui->textSeacrh->hide();
    ui->find->hide();
}


void MainWindow::on_btn_edit_2_clicked()
{
    text ="";
    ui->textEdit->setText(text);
}



void MainWindow::on_merge_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Choose The File");
    QFile file (file_name);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "..", "Couldn't Open File");
        return;

    }
    QTextStream in(&file);
    secText = in.readAll();
    file.close();
    text = text + '\n' + secText;
    ui->textEdit->setText(text);
}


void MainWindow::on_countWord_clicked()
{
    ui->count_btn->show();
    ui->textCount->show();
    ui->countLabel->show();
    ui->seacrhLabel->hide();
    ui->textSeacrh->hide();
    ui->find->hide();
}


void MainWindow::on_count_btn_clicked()
{
    QString s;
    s = ui->textCount->toPlainText();
    countWord = s.toUtf8().constData();
    int x = 0;
    x = Count_the_number_of_times_a_word_exists_in_the_file(countWord);

    QString number = QString::number(x);
    if (x > 0)
    {
        QMessageBox::information(0, QString ("Result"), QString(number),QMessageBox::Ok);

    }
    else
    {
        QMessageBox::information(0, QString ("Result"), QString("The Word Doesn't Exist!"),QMessageBox::Ok);
    }
    ui->textCount->setText(" ");
    ui->count_btn->hide();
    ui->textCount->hide();
    ui->countLabel->hide();

}

