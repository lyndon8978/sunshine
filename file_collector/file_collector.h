#ifndef SS_FILE_COLLECTOR_H_
#define SS_FILE_COLLECTOR_H_

#include <QDir>
#include <QFileInfoList>
#include <QHash>

namespace ss {
class FileCollector {
 public:
  FileCollector();
  virtual ~FileCollector();

  /**
   * @brief Filter files.
   *
   */
  virtual void collect() = 0;

  /**
   * @brief Set the current dir.
   *
   * @param dir
   */
  void setCurrentDir(const QDir& dir);

  /**
   * @brief Get the current dir.
   *
   * @return const QDir&
   */
  const QDir& getCurrentDir() const;

  /**
   * @brief Get collected file list.
   *
   * @return const QFileInfoList&
   */
  const QFileInfoList& getFileList() const;

 protected:
  /**
   * @brief Extensions of files.
   *
   */
  QHash<QString, QString> extensions_;

  /**
   * @brief Current directory.
   *
   */
  QDir current_dir_;
  /**
   * @brief The collected file list.
   *
   */
  QFileInfoList file_list_;
};
}  // namespace ss

#endif