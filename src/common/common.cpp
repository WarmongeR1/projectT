#include "common.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>

#include <QDebug>

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
QString parseProjectFile(QString filename)
{
    QString text = getTextFromFile(filename);
//    qDebug() << "namespace = " << getNamespace(&text);
//    qDebug() << "virtualFolder=  " << getVirtualFolder(&text);
//    qDebug() << "files = " << parseFiles(&text);
    QString str = "";
    return str;
}
///---------------------------------------------
QString getNamespace(QString *mtext)
{
    QString namespaceFile = getParamProject(mtext, "namespace");
    return namespaceFile;
}
///---------------------------------------------
QString getVirtualFolder(QString *mtext)
{
    QString folder = getParamProject(mtext, "virtualFolder");
    return folder;
}
///---------------------------------------------
QString getParamProject(QString *mtext, QString param)
{
    QString text = *mtext;
    int posBegin, posEnd;
    posBegin = text.indexOf("<" + param + ">")
            + QString("<" + param + ">").length();


    posEnd = text.indexOf("</" + param + ">", posBegin);
    - QString("</" + param + ">").length();;

    QString str = text.mid(posBegin,
                           posEnd - posBegin);

    mtext->remove("<" + param + ">" +
                  str +
                  "</" + param + ">");
    return str;
}
///---------------------------------------------
void parseFilterSection(QString *text)
{

}
///---------------------------------------------
void parseToc(QString *text)
{

}
///---------------------------------------------
QStringList parseFiles(QString *mtext)
{
    QStringList textlist =  QString(*mtext).split("\n");
    QStringList list;
    //    qDebug() << textlist;
    for (int i = 0; i < textlist.size(); i++)
    {
        QString strati = textlist.at(i);
        if (strati.indexOf("<file>") != -1)
        {
            list << *deleteTagText(&strati, "file");
        }
    }
    return list;
}
///---------------------------------------------
QStringList parseKeyWords(QString *text)
{
    QStringList list;
    return list;
}
///---------------------------------------------
QString * deleteTagText(QString *str, QString tag)
{
    str->remove("<" + tag + ">");
    str->remove("</" + tag + ">");
    str->remove(" ");
    return str;
}
///---------------------------------------------

QString urlifyFileName(const QString &fileName)
{
    QString name = fileName;
    QUrl url(name);
#if defined(Q_OS_WIN32)
    if (!url.isValid() || url.scheme().isEmpty() || url.scheme().toLower() != QString("file:")) {
        int i = name.indexOf(QChar('#'));
        QString anchor = name.mid(i);
        name = name.toLower();
        if (i > -1)
            name.replace(i, anchor.length(), anchor);
        name.replace(QChar('\\'), QChar('/'));
        foreach (QFileInfo drive, QDir::drives()) {
            if (name.startsWith(drive.absolutePath().toLower())) {
                name = QString("file:") + name;
                break;
            }
        }
    }
#else
    if (!url.isValid() || url.scheme().isEmpty())
        name.prepend(QString("file:"));
#endif
    return name;
}

//-------------------------------------------------
QString unurlifyFileName(const QString &fileName)
{
    QString fn = fileName;
#if defined(Q_OS_WIN32) //!+! check in Linux if this works correct
    if (fn.startsWith("file:///")) {
        fn.remove(0,8);
    }
#endif
    if (fn.startsWith("file:")) {
        fn.remove(0,5);
    }
    return fn;
}

//-------------------------------------------------
//Turns absolute path to relative to 'path'
//Difference from QDir::relativeFilePath() in: adds "./" and removes "file:" or "file:///"
QString relatifyFileName(QString url, QString path)
{
    QString str = unurlifyFileName(url);
    if ((!str.isEmpty()) && (!str.startsWith("."))){
        //we assume that the passing paths have "/" as a dir separator, since that's how Qt stores paths
        if (!path.endsWith("/")) path = path + "/";
        QFileInfo fi(str);
        QString path1 = fi.absolutePath()  + "/"; path1 = path1.trimmed();
        QString path2 = path.trimmed();
        //Now we have two correct defined paths, let's make "str" relative to path1
        //For Windows we need to be sure that both paths are on the same drive
        if (path1[0] == path2[0]) {
            if ( path1 == path2){	//same path
                str = "./" + fi.fileName();
            }else{	//build relative path
                int n1 = path1.length();
                int n2 = path2.length();
                int n = n1;
                if (n > n2)  n = n2;
                QString commonPath = "";
                QString prefix = "";
                int i;
                for (i=0; i<n; i++){
                    if (path1[i] == path2[i]) commonPath += path2[i];
                    else break;
                }
                path1.remove(0, commonPath.length() );
                path2.remove(0, commonPath.length() );
                n = path2.count("/");
                if (n == 0)
                    prefix = "./";
                else
                    for (i=1; i<=n; i++) prefix += "../";
                str = prefix + path1 + fi.fileName();
            }
        }
    }
    return str;
}	//relatifyFileName
