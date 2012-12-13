#include "common.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QStandardItem>
#include <QDir>
#include <QDirIterator>

#include "debughelper.h"
#include <QProcess>

//------------------------------------------------------------------------------
QString getEncodingFromFile(QString file, QString language)
{
    QProcess pr;

#ifdef Q_OS_WIN
    pr.start("enca.exe -L " +language + " \""  + file + "\"");
#endif
#ifdef Q_OS_LINUX
    pr.start("enca -L " + language + " \""  + file + "\"");
#endif
    //    pr.start("pwd");

    QString encoding = "";
    if (pr.waitForFinished() == true)
    {
        QByteArray b = pr.readAll();
        encoding = QString(b);
    }
    if (encoding.indexOf("Universal transformation format 8 bits;") >= 0 ) encoding = "UTF-8";
    if (encoding.indexOf("Universal transformation format 16 bits;") >= 0 ) encoding = "UTF-16";
    if (encoding.indexOf("Universal transformation format 32 bits;") >= 0 ) encoding = "UTF-32";
    if (encoding.indexOf("Universal character set 2 bytes; UCS-2; BMP") >= 0) encoding = "UCS-2";
    if (encoding.indexOf("MS-Windows code page 1251") >= 0) encoding = "Windows-1251";
    if (encoding.indexOf("MS-Windows code page 1252") >= 0) encoding = "Windows-1252";
    if (encoding.indexOf("MS-Windows code page 1253") >= 0) encoding = "Windows-1253";
    if (encoding.indexOf("MS-Windows code page 1254") >= 0) encoding = "Windows-1254";
    if (encoding.indexOf("MS-Windows code page 1255") >= 0) encoding = "Windows-1255";
    if (encoding.indexOf("MS-Windows code page 1256") >= 0) encoding = "Windows-1256";
    if (encoding.indexOf("MS-Windows code page 1257") >= 0) encoding = "Windows-1257";
    if (encoding.indexOf("MS-Windows code page 1258") >= 0) encoding = "Windows-1258";
    if (encoding.indexOf("7bit ASCII characters") >= 0) encoding = "ASCII";
    if (encoding.indexOf("KOI8-R Cyrillic") >= 0) encoding = "KOI8-R";
    if (encoding.indexOf("KOI8-U Cyrillic") >= 0) encoding = "KOI8-U";
    if (encoding.indexOf("Unrecognized encoding") >= 0) encoding = "UTF-8";
    //    qDebug() << "encoding = " << encoding;
    return encoding;
}
//------------------------------------------------------------------------------
QString getFileNameAbs(const QString file)
{
    QStringList list;
    list << file.split("/");
    QString str = list.last();
    list = str.split(".");
    str = list.first();
    return str;
}
//------------------------------------------------------------------------------
QString getFileName(const QString file)
{
    QStringList list;
    list << file.split("/");
    QString str = list.last();
    return str;
}
//------------------------------------------------------------------------------
QString absolutifyFileName(QString fn, QString path)
{
    QString afn;
    if (!fn.isEmpty())
    {
        QDir dir(path);
        afn = dir.cleanPath( dir.absoluteFilePath(fn) );
    }
    return afn;
}
//------------------------------------------------------------------------------
QTextCodec * getCodecOfEncoding(QString encoding)
{
    //    encoding = encoding.toUpper ();
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    if (encoding.toUpper ()== "UTF-8")        codec = QTextCodec::codecForName("UTF-8");
    if (encoding.toUpper ()== "UTF-16")       codec = QTextCodec::codecForName("UTF-16");
    if (encoding.toUpper ()== "UTF-16BE")       codec = QTextCodec::codecForName("UTF-16BE");
    if (encoding.toUpper ()== "UTF-16LE")       codec = QTextCodec::codecForName("UTF-16LE");
    if (encoding.toUpper ()== "UTF-32")       codec = QTextCodec::codecForName("UTF-32");
    if (encoding.toUpper ()== "UTF-32BE")       codec = QTextCodec::codecForName("UTF-32BE");
    if (encoding.toUpper ()== "UTF-32LE")       codec = QTextCodec::codecForName("UTF-32LE");
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

    //        qDebug() << " encoding = " << encoding;
    return codec;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool createEmptyHtml(QString fileName, QString title, QString text)
{
    bool ret = true;
    QFile file(fileName);
    if (!file.exists())
    {
        //create file if it's not exist
        if (file.open(QIODevice::ReadWrite))
        {
            //try to open or create file
            QTextStream ts(&file);
            ts.setCodec("UTF-8");
            ts << "<html>\n<head>" << endl;
            ts << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" << endl;
            ts << "<title>" << title <<"</title>" << endl;
            ts << "</head>\n<body>\n" << text << "\n</body>\n</html>" << endl;
            file.close();
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}
//------------------------------------------------------------------------------
bool createEmpty(QString fileName, QString text)
{
    bool ret = false;
    QFile file(fileName);
    if (!file.exists())
    {
        //create file if it's not exist
        if (file.open(QIODevice::ReadWrite))
        {
            //try to open or create file
            QTextStream ts(&file);
            ts.setCodec("UTF-8");
            ts << text;
            file.close();
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}
//------------------------------------------------------------------------------
bool createEmptyHtml(QString fileName, QString title)
{
    bool ret = true;
    QFile file(fileName);
    if (!file.exists())
    {
        //create file if it's not exist
        if (file.open(QIODevice::ReadWrite))
        {
            //try to open or create file
            QTextStream ts(&file);
            ts.setCodec("UTF-8");
            ts << "<html>\n<head>" << endl;
            ts << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" << endl;
            ts << "<title>" << title <<"</title>" << endl;
            ts << "</head>\n<body>\n</body></html>" << endl;
            file.close();
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}
//------------------------------------------------------------------------------
void replaceStrInFile(QString filepath, QString old, QString newstr)
{
    QFile file(filepath);
    QString str;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        stream.setCodec(getCodecOfEncoding("UTF-8"));
        str = stream.readAll();
        str.replace(old, newstr);
    }
    else
    {
        qDebug() << "Error: not open file (replacestrinfile):" << filepath;
    }
    file.close();

    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setCodec(getCodecOfEncoding("UTF-8"));
        stream << str;
        file.close();
    }
    else
    {
        qDebug() << "Error: not open file (replacestrinfile write):" << filepath;
    }

}
//------------------------------------------------------------------------------
QString getTextFromHtmlFile(QString filePath)
{
    QString str = "";
    QFile file(filePath);
    //    qDebug() << filePath;
    file.close();
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString encoding = getEncodingFromFile(filePath);
            stream.setCodec(getCodecOfEncoding(encoding));
            str = stream.readAll();
            //        //        qDebug() << "str = " << str;
            //        int body = QString("<body>").length();
            //        int posBegin = str.indexOf("<body>");

            //        int posEnd = str.indexOf("</body>");
            //        str = str.mid(posBegin + body,
            //                      posEnd - posBegin - body);
            file.close();
        }
        else
        {
            myDebug() << "Error: not open file(getTextFromHtmlFile):" << filePath;
        }
    }

    return str;
}
//------------------------------------------------------------------------------
bool createEmptyXML(QString fileName)
{
    bool ret = false;
    QFile file(fileName);
    if (!file.exists())
    {
        //create file if it's not exist
        if (file.open(QIODevice::ReadWrite))
        {
            //try to open or create file
            QTextStream ts(&file);
            ts.setCodec("UTF-8");
            ts << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
            ts << "<!DOCTYPE xbel>" << endl;
            ts << "<xbel version=\"1.0\">" << endl;
            file.close();
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}
//-------------------------------------------------------------------------------
QStringList removeEmptyQStringFromQStringList(QStringList *list)
{
    QStringList listn;
    for(int i = 0; i < list->size(); i++)
    {
        if(!list->at(i).isEmpty()
                && list->at(i) != ""
                && list->at(i) != " ")
        {
            listn << list->at(i);
        }
    }
    //    myDebug() << listn;
    return listn;
}
//-------------------------------------------------------------------------------
QStringList recursiveFind(QString directory)
{
    //// подумать, нужен ли чистый рекурсивный поиск
    //// если нет, то сюда вставить обработку getModuleFilesList
    QStringList list;
    QDirIterator iterator (directory, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        iterator.next();
        list << iterator.fileInfo().absoluteFilePath();
    }
    return list;
}
//-------------------------------------------------------------------------------
QString getTextFromFile(QString filepath, QString encoding = "UTF-8")
{
    QString filetext = "";
    if (QFile::exists(filepath))
    {
        QFile file(filepath);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            stream.setCodec(getCodecOfEncoding(getEncodingFromFile(filepath)));
            filetext = stream.readAll();
            file.close();
        }
    }
    return filetext;
}
//-------------------------------------------------------------------------------
QStandardItemModel* parseProjectFile(QString filename)
{
    QString text = getTextFromFile(filename);
    //    qDebug() << "namespace = " << getNamespace(&text);
    //    qDebug() << "virtualFolder=  " << getVirtualFolder(&text);
    //    qDebug() << "files = " << parseFiles(&text);
    //    QString str = "";
    QStandardItemModel *model;
    return model;
}
//------------------------------------------------------------------------------
QString getNamespace(QString *mtext)
{
    QString namespaceFile = getParamProject(mtext, "namespace");
    return namespaceFile;
}
//------------------------------------------------------------------------------
QString getVirtualFolder(QString *mtext)
{
    QString folder = getParamProject(mtext, "virtualFolder");
    return folder;
}
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
void parseFilterSection(QString *mtext)
{

}
//------------------------------------------------------------------------------
QStandardItemModel* parseToc(QString *mtext)
{
    QString text = *mtext;
    int posBegin = text.indexOf("<toc>");
    int posEnd = text.indexOf("</toc>", posBegin);
    QString tocText = text.mid(posBegin + QString("<toc>").length(),
                               posEnd - posBegin
                               - QString("<toc>").length());

//    qDebug() << tocText;


    QStringList tocList = tocText.split("\n");
//    qDebug() << "tocList = " << tocList;
    for (int i = 0; i < tocList.size(); i++)
    {
        qDebug() << "at(" << i << ") = " << tocList.at(i);
    }

    QStandardItemModel *standardModel =  new QStandardItemModel ;



    QStandardItem *rootNode = standardModel->invisibleRootItem();
    QStandardItem *americaItem = new QStandardItem("America");
    rootNode->appendRow(americaItem);

    return standardModel;
}
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
QStringList parseKeyWords(QString *text)
{
    QStringList list;
    return list;
}
//------------------------------------------------------------------------------
QString * deleteTagText(QString *str, QString tag)
{
    str->remove("<" + tag + ">");
    str->remove("</" + tag + ">");
    str->remove(" ");
    return str;
}
//------------------------------------------------------------------------------

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


//QStringList
