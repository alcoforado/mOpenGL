#include "EngineException.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


EngineException::EngineException(const char *format,...)
{
  char str[2000];
  va_list vl;
  va_start(vl,format);
  vsprintf(str,format,vl);
  va_end(vl);
  m_error = str;



}


