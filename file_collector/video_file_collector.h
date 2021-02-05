#ifndef SS_VIDEO_FILE_COLLECTOR_H_
#define SS_VIDEO_FILE_COLLECTOR_H_

#include "file_collector.h"

namespace ss {
class VideoFileCollector : public FileCollector {
 public:
  VideoFileCollector();
  ~VideoFileCollector();
};
}  // namespace ss

#endif