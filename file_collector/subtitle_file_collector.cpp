#include "subtitle_file_collector.h"

ss::SubtitleFileCollector::SubtitleFileCollector() : FileCollector() {
  extensions_.insert("ass", "ass");
}

ss::SubtitleFileCollector::~SubtitleFileCollector() {}