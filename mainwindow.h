#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QMainWindow>
#include<QFileDialog>
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;


void encrypt();
void decrypt();
void vector_of_word();
void Count_the_number_of_words();
void Count_the_number_of_lines();
void Turn_the_content_to_upper_case();
void Turn_the_content_to_lower_case();
void Turn_file_content_to_first_caps();
bool Search_for_a_word_in_the_file(string search);
int Count_the_number_of_times_a_word_exists_in_the_file();

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_open_clicked();
    void on_btn_save_clicked();
    void on_btn_encrypt_clicked();
    void on_btn_decrypt_clicked();
    void on_textEdit_textChanged();
    void on_btn_edit_6_clicked();
    void on_btn_edit_7_clicked();
    void on_btn_edit_8_clicked();
    void on_btn_edit_4_clicked();
    void on_find_clicked();
    void on_btn_edit_2_clicked();
    void on_merge_clicked();

    void on_countWord_clicked();

    void on_count_btn_clicked();

private:
    Ui::MainWindow *ui;

};
//QString text;
#endif // MAINWINDOW_H
