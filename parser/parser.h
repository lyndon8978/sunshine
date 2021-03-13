/**
 * @file parser.h
 * @brief 命令行解析器
 * @author lyndon
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef SS_PARSER_H_
#define SS_PARSER_H_

#include <QCommandLineParser>
#include <QDir>

/**
 * @brief 命令解析器
 *
 */
namespace ss {
class Parser {
 public:
  Parser();
  ~Parser();
  /**
   * @brief 执行命令解析
   *
   * @param app 输入app应用程序
   * @return true 解析成功程序继续
   * @return false 解析失败返回
   */
  bool process(const QCoreApplication& app);

  /**
   * @brief 获取视频文件目录
   *
   * @return const QDir& 视频文件目录
   */
  const QDir& getVideoDir() const;
  /**
   * @brief 获取字幕文件目录
   *
   * @return const QDir& 字幕文件目录
   */
  const QDir& getSubtitleDir() const;
  /**
   * @brief 获取字幕文件关键字
   *
   * @return const QString& 字幕文件关键字
   */
  const QString& getSubtitleKey() const;
  /**
   * @brief 获取字幕文件拓展名
   *
   * @return const QString& 字幕文件拓展名
   */
  const QString& getSubtitleExtension() const;
  /**
   * @brief 获取视频文件清理标志
   *
   * @return true 清理
   * @return false 不清理
   */
  const bool getClearFlag() const;

 private:
  /**
   * @brief 命令行解析器
   *
   */
  QCommandLineParser parser_;
  /**
   * @brief 视频文件目录
   *
   */
  QDir video_dir_;
  /**
   * @brief 字幕文件目录
   *
   */
  QDir subtitle_dir_;
  /**
   * @brief 字幕文件拓展名
   *
   */
  QString subtitle_extension_;
  /**
   * @brief 字幕文件滤波关键字
   *
   */
  QString subtitle_key_;
  /**
   * @brief 视频文件目录清理标志
   *
   */
  bool clear_flag_;
};
}  // namespace ss

#endif  // !SS_PARSER_H_