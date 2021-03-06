#include "video_file_collector.h"

#include <QFile>

ss::VideoFileCollector::VideoFileCollector()
    : FileCollector(), flag_clear_(false) {
  extensions_.insert("mkv", "mkv");
  extensions_.insert("mp4", "mp4");
}

void ss::VideoFileCollector::collect() {
  file_list_.clear();
  QFileInfoList tmp_file_list =
      current_dir_.entryInfoList(QDir::Files, QDir::Name);
  for (QFileInfoList::const_iterator itr = tmp_file_list.begin();
       itr != tmp_file_list.end(); ++itr) {
    if (extensions_.contains(itr->suffix())) {
      file_list_.push_back(*itr);
    }
  }
  if (flag_clear_) {
    clear();
  }
}

ss::VideoFileCollector::~VideoFileCollector() {}

void ss::VideoFileCollector::clear() {
  // 1. 移除多余目录
  QFileInfoList dir_list =
      current_dir_.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
  for (QFileInfoList::const_iterator itr = dir_list.begin();
       itr != dir_list.end(); ++itr) {
    QDir delete_dir(itr->absoluteFilePath());
    delete_dir.removeRecursively();
  }
  // 2. 移除多余文件
  QFileInfoList file_list = current_dir_.entryInfoList(QDir::Files);
  for (QFileInfoList::const_iterator itr = file_list.begin();
       itr != file_list.end(); ++itr) {
    if (!extensions_.contains(itr->suffix())) {
      QFile delete_file(itr->absoluteFilePath());
      delete_file.remove();
    }
  }
}

void ss::VideoFileCollector::setClearFlag(bool flag) { flag_clear_ = flag; }