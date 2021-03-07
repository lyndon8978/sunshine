#include <QDebug>

#include "../assembler/assembler.h"

int main(int argc, char *argv[]) {
  ss::VideoFileCollector::Ptr vfc(new ss::VideoFileCollector);

  vfc->setCurrentDir(QDir(
      "/mnt/data/qbit/WandaVision.S01.1080p.DSNP.WEBRip.DDP5.1.x264-TOMMY[rartv]"));
  // vfc->setCurrentDir(
  //     QDir("/home/lyndon/workspace/test_sunshine_video"));

  vfc->setClearFlag(true);
  vfc->collect();

  // qDebug() << vfc.getFileList();

  ss::SubtitleFileCollector::Ptr sfc(new ss::SubtitleFileCollector);

  sfc->setCurrentDir(QDir(
      "/home/lyndon/Downloads/161495770759757"));
  // sfc->setCurrentDir(
  //     QDir("/home/lyndon/workspace/test_sunshine_subs"));
  sfc->setKeyWords("简体&英文");
  sfc->collect();

  ss::Assembler assembler;
  assembler.assemble(vfc, sfc);

  return 0;
}