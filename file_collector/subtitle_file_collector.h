#ifndef SS_SUBTITLE_FILE_COLLECTOR_H_
#define SS_SUBTITLE_FILE_COLLECTOR_H_

#include "file_collector.h"

namespace ss {
class SubtitleFileCollector : public FileCollector {
 public:
  SubtitleFileCollector();
  ~SubtitleFileCollector();
};
}  // namespace ss

#endif