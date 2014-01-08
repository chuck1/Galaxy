#ifndef __JESS_ASIO_MESSAGE_EXT_H__
#define __JESS_ASIO_MESSAGE_EXT_H__

struct pass {
  template<typename ...T> pass(T...) {}
};

namespace gal
{
  namespace network
  {
    template<class.. Args> class message_ext: public message
    {
      public:
        void  write_expand(std::shared_ptr<Args>... args)
        {
          pass{(args->write(shared_from_this()), 1)...};
        }
        void  read_expand(Args&... args, message_shared msg)
        {
          pass{(args->read(shared_from_this()), 1)...};
        }

    };
  }
}

#endif
