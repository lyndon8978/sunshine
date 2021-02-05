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

  void collect();

  void setCurrentDir(const QDir& dir);

  const QDir& getCurrentDir() const;

  const QFileInfoList& getFileList() const;

 protected:
  QHash<QString, QString> extensions_;

 private:
  QDir current_dir_;

  QFileInfoList file_list_;

  bool flag_delete_extras_;
};
}  // namespace ss

#endif