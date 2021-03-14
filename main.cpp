#include <QApplication>

#include "assembler/assembler.h"
#include "file_collector/subtitle_file_collector.h"
#include "file_collector/video_file_collector.h"
#include "parser/parser.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  ss::Parser parser;
  if (!parser.process(app)) return -1;
  ss::SubtitleFileCollector::Ptr sfc(new ss::SubtitleFileCollector);
  sfc->setCurrentDir(parser.getSubtitleDir());
  sfc->setExtension(parser.getSubtitleExtension());
  sfc->setKeyWords(parser.getSubtitleKey());
  sfc->collect();
  ss::VideoFileCollector::Ptr vfc(new ss::VideoFileCollector);
  vfc->setCurrentDir(parser.getVideoDir());
  vfc->setClearFlag(parser.getClearFlag());
  vfc->collect();
  ss::Assembler a;
  a.assemble(sfc, vfc);
  return 0;
}