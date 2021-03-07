#ifndef SS_VIDEO_FILE_COLLECTOR_H_
#define SS_VIDEO_FILE_COLLECTOR_H_

#include <QSharedPointer>

#include "file_collector.h"

namespace ss {
class VideoFileCollector : public FileCollector {
 public:
  VideoFileCollector();
  ~VideoFileCollector();

  typedef QSharedPointer<VideoFileCollector> Ptr;
  typedef QSharedPointer<const VideoFileCollector> ConstPtr;

  /**
   * @brief Filter videos.
   *
   */
  void collect();

  /**
   * @brief Whether to clear the directory.
   *
   * @param flag
   */
  void setClearFlag(bool flag);

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