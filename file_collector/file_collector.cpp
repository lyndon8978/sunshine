#include "file_collector.h"

ss::FileCollector::FileCollector()
    : current_dir_(QDir()),
      extensions_(QHash<QString, QString>()),
      file_list_(QFileInfoList()) {}

ss::FileCollector::~FileCollector() {}

void ss::FileCollector::setCurrentDir(const QDir& dir) { current_dir_ = dir; }

const QDir& ss::FileCollector::getCurrentDir() const { return current_dir_; }

const QFileInfoList& ss::FileCollector::getFileList() const {
  return file_list_;
}