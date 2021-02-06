
#ifndef SS_ASSEMBLER_H_
#define SS_ASSEMBLER_H_

#include "../file_collector/subtitle_file_collector.h"
#include "../file_collector/video_file_collector.h"

namespace ss {
class Assembler {
 public:
  Assembler();
  ~Assembler();

  /**
   * @brief Assemble.
   *
   * @param vfcp
   * @param sfcp
   */
  void assemble(VideoFileCollector::ConstPtr vfcp,
                SubtitleFileCollector::ConstPtr sfcp);

 private:
  int getBestMatchSubtitle(const QFileInfo &video_file,
                           const QFileInfoList &subtitle_file_list);
  int calMatchScore(const QString &file_name, const QStringList &key_words);
};
}  // namespace ss

#endif