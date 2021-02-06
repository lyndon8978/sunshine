#include "subtitle_file_collector.h"

ss::SubtitleFileCollector::SubtitleFileCollector() : FileCollector() {
  extensions_.insert("ass", "ass");
}

ss::SubtitleFileCollector::~SubtitleFileCollector() {}

void ss::SubtitleFileCollector::setKeyWords(const QString &words) {
  key_words_ = words;
}

void ss::SubtitleFileCollector::collect() {
  file_list_.clear();
  // 1. filter by extesion
  QFileInfoList tmp_file_list =
      current_dir_.entryInfoList(QDir::Files, QDir::Name);
  for (QFileInfoList::const_iterator itr = tmp_file_list.begin();
       itr != tmp_file_list.end(); ++itr) {
    if (extensions_.contains(itr->suffix())) {
      file_list_.push_back(*itr);
    }
  }
  // 2. filter by key words
  for (QFileInfoList::iterator itr = file_list_.begin();
       itr != file_list_.end();) {
         if(itr->fileName().contains(key_words_, Qt::CaseInsensitive)) {
           ++itr;
         } else {
           itr = file_list_.erase(itr);
         }
  }
}