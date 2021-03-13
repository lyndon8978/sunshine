/**
 * @file subtitle_file_collector.h
 * @brief 字幕文件搜集
 * @author lyndon
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SS_SUBTITLE_FILE_COLLECTOR_H_
#define SS_SUBTITLE_FILE_COLLECTOR_H_

#include <QSharedPointer>

#include "file_collector.h"

namespace ss {
/**
 * @brief 字幕文件搜集器
 *
 */
class SubtitleFileCollector : public FileCollector {
 public:
  SubtitleFileCollector();
  ~SubtitleFileCollector();

  typedef QSharedPointer<SubtitleFileCollector> Ptr;
  typedef QSharedPointer<const SubtitleFileCollector> ConstPtr;

  /**
   * @brief 搜集
   *
   */
  void collect();

  /**
   * @brief 设置滤波关键字
   *
   * @param words 关键字
   */
  void setKeyWords(const QString &words);

  /**
   * @brief 设置字幕拓展名
   *
   * @param extension 拓展名
   */
  void setExtension(const QString &extension);

 private:
  /**
   * @brief 关键字
   *
   */
  QString key_words_;
};
}  // namespace ss

#endif  // !SS_SUBTITLE_FILE_COLLECTOR_H_