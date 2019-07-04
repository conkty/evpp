#pragma once

#include "evpp/platform_config.h"

#ifdef __cplusplus
#define GOOGLE_GLOG_DLL_DECL // ʹ�þ�̬glog��ʱ�����붨�����
#define GLOG_NO_ABBREVIATED_SEVERITIES // û�����������,��˵��Ϊ��Windows.h��ͻ

#include <glog/logging.h>

#ifdef GOOGLE_STRIP_LOG

#if GOOGLE_STRIP_LOG == 0
#define EVLOG_TRACE LOG(INFO)
#define EVLOG_DEBUG LOG(INFO)
#define EVLOG_INFO LOG(INFO)
#define DLOG_TRACE LOG(INFO) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define EVLOG_TRACE                                                            \
  if (false)                                                                   \
  LOG(INFO)
#define EVLOG_DEBUG                                                            \
  if (false)                                                                   \
  LOG(INFO)
#define EVLOG_INFO                                                             \
  if (false)                                                                   \
  LOG(INFO)
#define DLOG_TRACE                                                             \
  if (false)                                                                   \
  LOG(INFO)
#endif

#if GOOGLE_STRIP_LOG <= 1
#define EVLOG_WARN LOG(WARNING)
#define DLOG_WARN LOG(WARNING) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define EVLOG_WARN                                                             \
  if (false)                                                                   \
  LOG(WARNING)
#define DLOG_WARN                                                              \
  if (false)                                                                   \
  LOG(WARNING)
#endif

#define EVLOG_ERROR LOG(ERROR)
#define EVLOG_FATAL LOG(FATAL)

#else
#define EVLOG_TRACE std::cout << __FILE__ << ":" << __LINE__ << " "
#define EVLOG_DEBUG std::cout << __FILE__ << ":" << __LINE__ << " "
#define EVLOG_INFO std::cout << __FILE__ << ":" << __LINE__ << " "
#define EVLOG_WARN std::cout << __FILE__ << ":" << __LINE__ << " "
#define EVLOG_ERROR std::cout << __FILE__ << ":" << __LINE__ << " "
#define EVLOG_FATAL std::cout << __FILE__ << ":" << __LINE__ << " "
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";
#endif
#endif // end of define __cplusplus

//#ifdef _DEBUG
//#ifdef assert
//#undef assert
//#endif
//#define assert(expr)  { if (!(expr)) { LOG_FATAL << #expr ;} }
//#endif