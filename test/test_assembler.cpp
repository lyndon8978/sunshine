#include <QDebug>

#include "../assembler/assembler.h"


int main(int argc, char *argv[]) {
  ss::VideoFileCollector::Ptr vfc(new ss::VideoFileCollector);

  vfc->setCurrentDir(QDir("/mnt/data/qbit/Young.Sheldon.S01.1080p.BluRay.x264-SHORTBREHD[rartv] (copy)"));

  vfc->collect();

  // qDebug() << vfc.getFileList();

  ss::SubtitleFileCollector::Ptr sfc(new ss::SubtitleFileCollector);

  sfc->setCurrentDir(
      QDir("/home/lyndon/Downloads/15393545508315/"
           "Young.Sheldon.S01.1080p.BluRay.x264-SHORTBREHD/"));
  sfc->setKeyWords("chs.eng");
  sfc->collect();

  ss::Assembler assembler;
  assembler.assemble(vfc, sfc);

  return 0;
}