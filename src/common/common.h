#ifndef __COMMON_H
#define __COMMON_H

#include <QStringList>
class QTextCodec;
class QString;
/**
  @funcion
  Parse function
  Begin parse - get text of file
  step number *: parse text, and delete plock parse
  @return text  QString
  */
QString parseProjectFile(QString filename);

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
void parseToc(QString *text);


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
/**
  @function
  Return text of file with encoding - default = utf-8
  @param filepath  path to file
  @param encoding  encoding from file
  @return text
  */
QString getTextFromFile(QString filepath, QString encoding="UTF-8");

/**
  @function
  Return codec of encoding
  @param encoding
  @return codec
  */
 QTextCodec *getCodecOfEncoding(QString encoding);

#endif // end __COMMON_H
