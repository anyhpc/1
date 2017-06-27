/*
 * TraceLogConfigure.cpp
 *
 *  Created on: 2015��4��24��
 *      Author: euwyzbc
 */

#include "TraceLogConfigure.h"

TraceLogConfigure::TraceLogConfigure()
:level_(TRACE_LOG_DEBUG)
,target_(TRACE_LOG_TO_CONSOLE)
,filePath_(TraceLogFilePath)
,logBufSize_(LogBufSize)
,logLineNumberInFile_(0)
,logLineNumberInConsole_(0)
,fileLogStart_(false)
,consoleLogStart_(false)
{
  // TODO Auto-generated constructor stub

}

TraceLogConfigure::~TraceLogConfigure() {
  // TODO Auto-generated destructor stub
}

void TraceLogConfigure::setTraceLogLevel(TraceLogLevel traceLogLevel)
{
  level_ = traceLogLevel;
}

TraceLogLevel TraceLogConfigure::getTraceLogLevel() const
{
  return level_;
}

void TraceLogConfigure::setTraceLogTarget(TraceLogTarget target)
{
  target_ = target;
}
TraceLogTarget TraceLogConfigure::getTraceLogTarget() const
{
  return target_;
}

void TraceLogConfigure::setTraceLogFilePath(const std::string& filePath)
{
  filePath_ = filePath;
}

std::string TraceLogConfigure::getTraceLogFilePath() const
{
  return filePath_;
}

void TraceLogConfigure::setTraceLogBufSize(unsigned int logBufSize)
{
  logBufSize_ = logBufSize;
}

unsigned int TraceLogConfigure::getTraceLogBufSize() const
{
  return logBufSize_;
}

unsigned short  TraceLogConfigure::getLogLineNumberInFile() const
{
  return logLineNumberInFile_;
}
void  TraceLogConfigure::increaseLogLineNumberInFile()
{
  ++logLineNumberInFile_;
}

unsigned short TraceLogConfigure::getLogLineNumberInConsole() const
{
  return logLineNumberInConsole_;
}
void TraceLogConfigure::increaseLogLineNumberInConsole()
{
  ++logLineNumberInConsole_;
}

bool TraceLogConfigure::isFileLogStart() const
{
  return fileLogStart_;
}
void TraceLogConfigure::startFileLog()
{
  fileLogStart_ = true;
}
void TraceLogConfigure::stopFileLog()
{
  fileLogStart_ = false;
}
bool TraceLogConfigure::isConsoleLogStart() const
{
  return consoleLogStart_;
}
void TraceLogConfigure::startConsoleLog()
{
  consoleLogStart_ = true;
}
void TraceLogConfigure::stopConsoleLog()
{
  consoleLogStart_ = false;
}
