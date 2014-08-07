#ifndef ENGINEEXCEPTION_H
#define ENGINEEXCEPTION_H
#include <string>

  class Exception
  {
   private:

   protected:
    std::string m_error;
   public:
    Exception(std::string error){m_error = error;}
    Exception(const char *format,...);
    ~Exception(){}
    std::string getError(){return m_error;}
  };



#endif // ENGINEEXCEPTION_H
