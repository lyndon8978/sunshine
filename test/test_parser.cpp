#include <QDebug>

#include "../parser/parser.h"

int main(int argc, char *argv[]) 
{
  QCoreApplication app(argc, argv);
  QCoreApplication::setApplicationName("my-copy-program");
  QCoreApplication::setApplicationVersion("1.0");

  ss::Parser parser;
  parser.process(app);

  
  return 0;
}