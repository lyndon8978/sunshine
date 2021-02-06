#ifndef SS_SUBTITLE_FILE_COLLECTOR_H_
#define SS_SUBTITLE_FILE_COLLECTOR_H_

#include <QString>

#include "file_collector.h"

namespace ss {
class SubtitleFileCollector : public FileCollector {
 public:
  SubtitleFileCollector();
  ~SubtitleFileCollector();

  /**
   * @brief Collect subtitle files.
   *
   */
  void collect();

  /**
   * @brief Set the key words.
   * 
   * @param words 
   */
  void setKeyWords(const QString &words);

 private:
  /**
   * @brief Key words using to filter files.
   *
   */
  QString key_words_;
};
}  // namespace ss

#endif