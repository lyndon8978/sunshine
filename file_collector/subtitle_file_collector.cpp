#include "subtitle_file_collector.h"

ss::SubtitleFileCollector::SubtitleFileCollector() : FileCollector() {}

ss::SubtitleFileCollector::~SubtitleFileCollector() {}

void ss::SubtitleFileCollector::setKeyWords(const QString &words) {
  key_words_ = words;
}

void ss::SubtitleFileCollector::setExtension(const QString &extension) {
  if (!extension.isEmpty()) {
    extensions_.clear();
    extensions_.insert(extension, extension);
  }
}

void ss::SubtitleFileCollector::collect() {
  file_list_.clear();
  // 1. 通过扩展名滤波
  QFileInfoList tmp_file_list =
      current_dir_.entryInfoList(QDir::Files, QDir::Name);
  for (QFileInfoList::const_iterator itr = tmp_file_list.begin();
       itr != tmp_file_list.end(); ++itr) {
    if (extensions_.contains(itr->suffix())) {
      file_list_.push_back(*itr);
    }
  }
  // 2. 通过关键字滤波
  for (QFileInfoList::iterator itr = file_list_.begin();
       itr != file_list_.end();) {
    if (itr->fileName().contains(key_words_, Qt::CaseInsensitive)) {
      ++itr;
    } else {
      itr = file_list_.erase(itr);
    }
  }
}