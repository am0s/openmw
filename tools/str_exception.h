#ifndef __STR_EXCEPTION_H
#define __STR_EXCEPTION_H

#include <exception>
#include <string>

/// A simple exception that takes and returns a string
class str_exception : public std::exception
{
  std::string msg;

 public:

  str_exception(const std::string &m) : msg(m) {}
  const char* what() const throw() { return msg.c_str(); }
};

#endif