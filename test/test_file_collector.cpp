#include <QDebug>

#include "../file_collector/subtitle_file_collector.h"
#include "../file_collector/video_file_collector.h"

int main(int argc, char *argv[]) {
  // ss::VideoFileCollector vfc;

  // vfc.setCurrentDir(QDir("/mnt/data/qbit/Young.Sheldon.S01.1080p.BluRay.x264-SHORTBREHD[rartv]
  // (copy)"));

  // vfc.collect();

  // qDebug() << vfc.getFileList();

  ss::SubtitleFileCollector sfc;

  sfc.setCurrentDir(
      QDir("/home/lyndon/Downloads/161495770759757"));
  sfc.setKeyWords("简体&英文");
  sfc.collect();

  qDebug() << sfc.getFileList().size();

  return 0;
}