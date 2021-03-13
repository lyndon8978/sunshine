/**
 * @file video_file_collector.h
 * @brief 视频文件搜集
 * @author lyndon
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SS_VIDEO_FILE_COLLECTOR_H_
#define SS_VIDEO_FILE_COLLECTOR_H_

#include <QSharedPointer>

#include "file_collector.h"

namespace ss {
/**
 * @brief 视频文件搜集器
 *
 */
class VideoFileCollector : public FileCollector {
 public:
  VideoFileCollector();
  ~VideoFileCollector();

  typedef QSharedPointer<VideoFileCollector> Ptr;
  typedef QSharedPointer<const VideoFileCollector> ConstPtr;

  /**
   * @brief 搜集
   *
   */
  void collect();

  /**
   * @brief 设置是否清理除视频以外文件的标志
   *
   * @param flag 清除标志
   */
  void setClearFlag(bool flag);

 private:
  /**
   * @brief 清除除视频以外文件操作
   *
   */
  void clear();

  /**
   * @brief 清除标志
   *
   */
  bool flag_clear_;
};
}  // namespace ss

#endif // !SS_VIDEO_FILE_COLLECTOR_H_