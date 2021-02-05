#include "../file_collector/video_file_collector.h"

#include "../file_collector/subtitle_file_collector.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    ss::VideoFileCollector vfc;

    vfc.setCurrentDir(QDir("/mnt/data/qbit/Young.Sheldon.S01.1080p.BluRay.x264-SHORTBREHD[rartv]"));

    qDebug() << vfc.getCurrentDir().entryInfoList(QDir::Files| QDir::NoDotAndDotDot, QDir::Name).size();

    vfc.collect();

    qDebug() << vfc.getFileList().size();


    ss::SubtitleFileCollector sfc;

    sfc.setCurrentDir(QDir("/home/lyndon/Downloads/15393545508315/Young.Sheldon.S01.1080p.BluRay.x264-SHORTBREHD/"));

    qDebug() << sfc.getCurrentDir().entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name).size();

    sfc.collect();

    qDebug() << sfc.getFileList().size();


    return 0;
}