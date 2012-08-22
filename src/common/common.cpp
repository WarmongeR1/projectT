#include "common.h"


#include <QFile>
#include <QTextStream>
#include <QTextCodec>
///---------------------------------------------
QString getTextFromFile(QString filepath, QString encoding)
{
    QString filetext = "";
    if (QFile::exists(filepath))
    {
        QFile file(filepath);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            stream.setCodec(getCodecOfEncoding(encoding));
            filetext = stream.readAll();
            file.close();
        }
    }
    return filetext;
}

///---------------------------------------------
QTextCodec * getCodecOfEncoding(QString encoding)
{
    //    encoding = encoding.toUpper ();
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    if (encoding.toUpper ()== "UTF-8")        codec = QTextCodec::codecForName("UTF-8");
    if (encoding.toUpper ()== "UTF-16")       codec = QTextCodec::codecForName("UTF-16");
    if (encoding.toUpper ()== "UTF-32")       codec = QTextCodec::codecForName("UTF-32");
    if (encoding == "Windows-1251") codec = QTextCodec::codecForName("Windows-1251");
    if (encoding == "Windows-1252") codec = QTextCodec::codecForName("Windows-1252");
    if (encoding == "Windows-1253") codec = QTextCodec::codecForName("Windows-1253");
    if (encoding == "Windows-1254") codec = QTextCodec::codecForName("Windows-1254");
    if (encoding == "Windows-1255") codec = QTextCodec::codecForName("Windows-1255");
    if (encoding == "Windows-1256") codec = QTextCodec::codecForName("Windows-1256");
    if (encoding == "Windows-1257") codec = QTextCodec::codecForName("Windows-1257");
    if (encoding == "Windows-1258") codec = QTextCodec::codecForName("Windows-1258");
    if (encoding.toUpper ()== "KOI8-R")       codec = QTextCodec::codecForName("KOI8-R");
    if (encoding.toUpper ()== "KOI8-U")       codec = QTextCodec::codecForName("KOI8-U");

    //    qDebug() << " encoding = " << encoding;
    return codec;
}
///---------------------------------------------
///---------------------------------------------

///---------------------------------------------
///---------------------------------------------
///---------------------------------------------

