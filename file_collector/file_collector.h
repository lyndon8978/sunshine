/**
 * @file file_collector.h
 * @brief 文件搜集器
 * @author lyndon
 * @date 2021-03-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SS_FILE_COLLECTOR_H_
#define SS_FILE_COLLECTOR_H_

#include <QDir>
#include <QFileInfoList>
#include <QHash>

namespace ss {
/**
 * @brief 文件搜集
 *
 */
class FileCollector {
 public:
  FileCollector();
  virtual ~FileCollector();

  /**
   * @brief 文件搜集执行操作
   *
   */
  virtual void collect() = 0;

  /**
   * @brief 设置文件所在目录
   *
   * @param dir 文件所在目录
   */
  void setCurrentDir(const QDir& dir);

  /**
   * @brief 获取文件所在目录
   *
   * @return const QDir& 返回文件所在目录
   */
  const QDir& getCurrentDir() const;

  /**
   * @brief 返回所获取的文件列表
   *
   * @return const QFileInfoList& 文件列表
   */
  const QFileInfoList& getFileList() const;

 protected:
  /**
   * @brief 文件扩展名
   *
   */
  QHash<QString, QString> extensions_;

  /**
   * @brief 当前目录
   *
   */
  QDir current_dir_;
  /**
   * @brief 文件列表
   *
   */
  QFileInfoList file_list_;
};
}  // namespace ss

#endif // !SS_FILE_COLLECTOR_H_