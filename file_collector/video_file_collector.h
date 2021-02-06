#ifndef SS_VIDEO_FILE_COLLECTOR_H_
#define SS_VIDEO_FILE_COLLECTOR_H_

#include "file_collector.h"

namespace ss {
class VideoFileCollector : public FileCollector {
 public:
  VideoFileCollector();
  ~VideoFileCollector();

  /**
   * @brief Filter videos.
   *
   */
  void collect();

 private:
  /**
   * @brief Remove files or dirs except for selected videos.
   *
   */
  void clear();

  /**
   * @brief Whether to clean the dir.
   * 
   */
  bool flag_clear_;
};
}  // namespace ss

#endif