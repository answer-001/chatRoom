#ifndef FLASH_H
#define FLASH_H

#include <QMainWindow>
#include <QMovie>//动态图片显示
#include <QTextToSpeech>//文本转语音

namespace Ui
{
class Flash;
}

class Flash : public QMainWindow
{
    Q_OBJECT

public:
    explicit Flash(QWidget* parent = nullptr);
    ~Flash();

    void Showgif(QString filename);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Flash* ui;
    QMovie* movie;//init dynamtic object
    QTextToSpeech* speech;
};

#endif // FLASH_H
