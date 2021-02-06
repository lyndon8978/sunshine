#include "assembler.h"

#include <QDebug>

ss::Assembler::Assembler() {}

ss::Assembler::~Assembler() {}

void ss::Assembler::assemble(VideoFileCollector::ConstPtr vfcp,
                             SubtitleFileCollector::ConstPtr sfcp) {
  QFileInfoList video_file_list = vfcp->getFileList();
  QFileInfoList subtitle_file_list = sfcp->getFileList();
  for (QFileInfoList::const_iterator itr = video_file_list.begin();
       itr != video_file_list.end(); ++itr) {
    int index = getBestMatchSubtitle(*itr, subtitle_file_list);
    if (index > -1) {
      // 1. find the pair subtitle
      qDebug() << *itr;
      qDebug() << subtitle_file_list.at(index);
      qDebug() << "  ";
      subtitle_file_list.removeAt(index);
    }
  }
}

int ss::Assembler::getBestMatchSubtitle(
    const QFileInfo &video_file, const QFileInfoList &subtitle_file_list) {
  QStringList key_words = video_file.completeBaseName().split('.', QString::SkipEmptyParts);
  int index = -1;
  int score = -1;
  for (size_t i = 0; i < subtitle_file_list.size(); ++i) {
    int tmp_score =
        calMatchScore(subtitle_file_list.at(i).completeBaseName(), key_words);
    if (score < tmp_score) {
      score = tmp_score;
      index = i;
    }
  }
  return index;
}

int ss::Assembler::calMatchScore(const QString &file_name,
                                 const QStringList &key_words) {
  int score = 0;
  for (QStringList::const_iterator itr = key_words.begin();
       itr != key_words.end(); ++itr) {
    if (file_name.contains(*itr, Qt::CaseInsensitive)) {
      ++score;
    }
  }
  return score;
}