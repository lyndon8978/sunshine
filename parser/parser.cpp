#include "parser.h"

#include <iostream>

ss::Parser::Parser()
    : video_dir_(QDir()),
      subtitle_dir_(QDir()),
      subtitle_extension_(QString()),
      subtitle_key_(QString()),
      clear_flag_(false) {}

ss::Parser::~Parser() {}

bool ss::Parser::process(const QCoreApplication& app) {
  parser_.setApplicationDescription("字幕文件与视频文件匹配工具");
  parser_.addHelpOption();
  parser_.addVersionOption();
  QString sd("sd");
  QString vd("vd");
  QString se("se");
  QString sk("sk");
  QString vc("vc");
  parser_.addOptions({
      // 字幕文件目录
      {sd, QCoreApplication::translate("main", "字幕文件的 <目录>."),
       QCoreApplication::translate("main", "目录")},
      // 视频文件目录
      {vd, QCoreApplication::translate("main", "视频文件的 <目录>."),
       QCoreApplication::translate("main", "目录")},
      // 字幕文件扩展名
      {se, QCoreApplication::translate("main", "字幕文件的 <扩展名>."),
       QCoreApplication::translate("main", "扩展名")},
      // 字幕文件关键字
      {sk, QCoreApplication::translate("main", "字幕文件的 <关键字>."),
       QCoreApplication::translate("main", "关键字")},
      // 是否清理视频文件夹
      {vc, QCoreApplication::translate("main", "清理视频文件夹")},
  });

  parser_.process(app);
  bool ret = true;
  if (!parser_.isSet(sd)) {
    std::cout << "未设置字幕文件目录，请使用 --sd <目录>" << std::endl;
    ret = false;
  } else {
    subtitle_dir_ = QDir(parser_.value(sd));
    if (!subtitle_dir_.exists()) {
      std::cout << "字幕文件目录不存在，请使用 --sd <目录>" << std::endl;
      ret = false;
    }
  }
  if (!parser_.isSet(vd)) {
    std::cout << "未设置视频文件目录，请使用 --vd <目录>" << std::endl;
    ret = false;
  } else {
    video_dir_ = QDir(parser_.value(vd));
    if (!video_dir_.exists()) {
      std::cout << "视频文件目录不存在，请使用 --vd <目录>" << std::endl;
      ret = false;
    }
  }
  if (!parser_.isSet(se)) {
    std::cout << "未设置字幕文件扩展名，请使用 -se <扩展名>" << std::endl;
    ret = false;
  } else {
    subtitle_extension_ = parser_.value(se);
  }
  if (parser_.isSet(sk)) subtitle_key_ = parser_.value(sk);
  if (parser_.isSet(vc)) clear_flag_ = true;
  if (ret) {
    // 输出打印
    std::cout << std::endl;
    std::cout << "<请确认以下信息!>" << std::endl;
    std::cout << std::endl;
    std::cout << "字幕目录: " << subtitle_dir_.absolutePath().toStdString()
              << std::endl;
    std::cout << "视频目录: " << video_dir_.absolutePath().toStdString()
              << std::endl;
    std::cout << "字幕扩展名: " << subtitle_extension_.toStdString()
              << std::endl;
    std::cout << "字幕关键字: " << subtitle_key_.toStdString() << std::endl;
    std::cout << "清理视频文件目录: " << clear_flag_ << std::endl;
    std::cout << std::endl;
    std::cout << "<按下Y继续, 否则退出!>";
    char c;
    std::cin >> c;
    if ((c != 'Y') && (c != 'y')) ret = false;
    std::cout << std::endl;
  }

  return ret;
}

const QDir& ss::Parser::getVideoDir() const { return video_dir_; }

const QDir& ss::Parser::getSubtitleDir() const { return subtitle_dir_; }

const QString& ss::Parser::getSubtitleKey() const { return subtitle_key_; }

const QString& ss::Parser::getSubtitleExtension() const {
  return subtitle_extension_;
}

const bool ss::Parser::getClearFlag() const { return clear_flag_; }