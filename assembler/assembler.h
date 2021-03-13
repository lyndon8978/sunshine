/**
 * @file assembler.h
 * @brief 合并文件操作
 * @author lyndon
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SS_ASSEMBLER_H_
#define SS_ASSEMBLER_H_

#include "../file_collector/subtitle_file_collector.h"
#include "../file_collector/video_file_collector.h"

namespace ss {
/**
 * @brief 字幕文件合并器
 *
 */
class Assembler {
 public:
  Assembler();
  ~Assembler();

  /**
   * @brief
   * 合并文件，将字幕文件与视频文件进行匹配，并将字幕文件复制到视频文件所在文件夹
   *
   * @param vfcp 视频文件搜集器
   * @param sfcp 字幕文件搜集器
   */
  void assemble(VideoFileCollector::ConstPtr vfcp,
                SubtitleFileCollector::ConstPtr sfcp);

 private:
  /**
   * @brief 获取与视频最佳匹配字幕文件
   *
   * @param video_file 视频文件
   * @param subtitle_file_list 字幕文件列表
   * @return int 最佳字幕文件在列表中的位置
   */
  int getBestMatchSubtitle(const QFileInfo &video_file,
                           const QFileInfoList &subtitle_file_list);
  /**
   * @brief 计算字幕文件与视频文件匹配的分数
   *
   * @param file_name 字幕文件名字
   * @param key_words 关键字
   * @return int 计算返回分数
   */
  int calMatchScore(const QString &file_name, const QStringList &key_words);
};
}  // namespace ss

#endif // !SS_ASSEMBLER_H_