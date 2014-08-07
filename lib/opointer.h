#ifndef  _MY_OPointer_
#define _MY_OPointer_


/** OPointer 
 *
 */
template<class Type>
class OPointer 
{
 private:
  Type *_ptr;
 protected:



  
 public:
  OPointer(){_ptr=NULL;}
  OPointer(Type *p){_ptr=p;}
  ~OPointer()
  {
    if (_ptr)
    {
      //printf("Opointer Deleting address %p\n",_ptr);
      delete _ptr;
    }
  }
  Type* operator -> ()
  {
    assert(_ptr);
    return _ptr;
  }
  Type& operator *() const {return *_ptr;}
  Type* operator = (Type *p){_ptr = p;return p;}

  //operator Type*(){return _ptr;}
  operator Type*& (){return _ptr;}
  operator Type* () const {return _ptr;}

  //operator void*& (){return _ptr;}
  //operator long int() const {return (long int) _ptr;}
  //operator bool () const {return _ptr != NULL;}
  Type* ptr(){return _ptr;}
  void free(){assert(_ptr);delete _ptr;_ptr=NULL;}
  void if_free()
  {
    if (_ptr)
    {
      delete _ptr;
     _ptr=NULL;
    }
  }
};


#endif
