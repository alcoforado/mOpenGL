#ifndef ENGINEEXCEPTION_H
#define ENGINEEXCEPTION_H
#include <string>

  class EngineException
  {
   private:

   protected:
    std::string m_error;
   public:
    EngineException(std::string error){m_error = error;}
    EngineException(const char *format,...);
    ~EngineException(){}
    std::string getError(){return m_error;}
  };



#endif // ENGINEEXCEPTION_H
