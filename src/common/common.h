#ifndef __COMMON_H
#define __COMMON_H

#include <QStringList>
#include <QUrl>
#include <QFileInfo>
class QTextCodec;
class QString;
class QStandardItemModel;




/**
  \brief
  @function
  Auto detect encoding file
  @param filepath  QString of file path
  @param language  QString of language, default = russian
  @return encoding  QString encoding
  */
QString getEncodingFromFile(QString file, QString language="russian");


/**
  @function
  Retun name of file
  Example:
  /home/warmonger/develop/other/file.ru  return file
  @return name_file
  */
QString getFileNameAbs(const QString file);
/**
  @function
  Retun name of file
  Example:
  /home/warmonger/develop/other/file.ru  return file.ru
  @param filepath
  @return name_file
  */
QString getFileName(const QString file);
/**
  @function
  Returns absolute file path
  @param filepath
  @param folder
  @return filename
  */
QString absolutifyFileName(QString fn, QString path);
/**
  @function
  Return codec from string
  @param encoding(String)
  @return encoding(Codec)
   */
QTextCodec* getCodecOfEncoding(QString encoding); // получает строку с названием кодировки и возвращает кодес с этй кодировкой ( написана для уменьшения дублирования кода)
/**
  @function
  Replace text in file
  @param file_path
  @param old_text
  @param new_text
  */
void replaceStrInFile(QString filepath, QString old, QString newstr);
/**
  \brief
  @function
  Create empty xml file.
  @param file_path
  @return bool
  */
bool createEmptyXML(QString fileName);
/**
 * @brief removeEmptyQStringFromQStringList
 * @param list
 * @return
 */
QStringList removeEmptyQStringFromQStringList(QStringList *list);

/**
  @function
  Create empty html file,
  @param file_path
  @param title
  @return bool
  */
bool createEmptyHtml(QString fileName, QString title);

/**
  @function
  Create empty html file with text,
  @param file_path
  @param title
  @param text
  @return bool
  */
bool createEmptyHtml(QString fileName, QString title, QString text);
/**
  @function
  Create empty file with text,
  @param file_path
  @param text
  @return bool
  */
bool createEmpty(QString fileName, QString text);
/**
  @function
  Retrun text from <body> </body>
  @param file_path
  @return text
  */
QString getTextFromHtmlFile(QString fileName);

/**
 * @brief recursiveFind
 * @param directory
 * @return
 */
QStringList recursiveFind(QString directory);


/**
  @function
  get text from file
  @param file  QString path to file
  @param encoding
  @return QString
  */
QString getTextFromFile(QString file, QString encoding); // достать весь текст из файла




// TRASH!!!
// DELETE!!!
/**
  @funcion
  Parse function
  Begin parse - get text of file
  step number *: parse text, and delete plock parse
  @return text  QString
  */
QStandardItemModel* parseProjectFile(QString filename);

/**
  @function
  Parse function
  Return namespace from project file
  @param *text  text
  @return namespace
  */
QString getNamespace(QString *text);
/**
  @function
  Parse function
  Return virtual folder from project file
  @param *text  text
  @return virtual folder
  */
QString getVirtualFolder(QString *text);

/**
  @function
  Parse function
  Parse block <filter section>
  (files, keywords, toc)
  @param *text  text
  */
void parseFilterSection(QString *text);

/**
  @function
  Parse function
  Parse block <toc> </toc>
  @param *text
  */
QStandardItemModel* parseToc(QString *text);


/**
  @function
  Parse function
  Parse block <files> </files> and return list files
  @param *text  text
  @return list  list files
  */
QStringList parseFiles(QString *text);
/**
  @function
  Parse function
  Parse block <keywords> </keywords> and return list of key
  @param *text  text
  @return list  list key words
  */
QStringList parseKeyWords(QString *text);


QString getParamProject(QString *mtext, QString param);
QString *deleteTagText(QString *str, QString tag);


#endif // end __COMMON_H
