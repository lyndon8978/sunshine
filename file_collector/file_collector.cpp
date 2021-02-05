#include "file_collector.h"

#include <QDebug>

ss::FileCollector::FileCollector()
    : current_dir_(QDir()),
      extensions_(QHash<QString, QString>()),
      file_list_(QFileInfoList()), flag_delete_extras_(false) {}

ss::FileCollector::~FileCollector() {}

void ss::FileCollector::collect() {
  if (current_dir_.exists()) {
    file_list_.clear();
    QFileInfoList list = current_dir_.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
    qDebug() << list;
    for (QFileInfoList::const_iterator itr = list.begin(); itr != list.end();
         ++itr) {
      if (extensions_.contains(itr->suffix())) {
        file_list_.push_back(*itr);
      }
    }
  }
}

void ss::FileCollector::setCurrentDir(const QDir& dir) { current_dir_ = dir; }

const QDir& ss::FileCollector::getCurrentDir() const { return current_dir_; }

const QFileInfoList& ss::FileCollector::getFileList() const {
  return file_list_;
}