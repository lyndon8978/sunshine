#include "video_file_collector.h"

ss::VideoFileCollector::VideoFileCollector() : FileCollector() {
  extensions_.insert("mkv", "mkv");
}

ss::VideoFileCollector::~VideoFileCollector() {}