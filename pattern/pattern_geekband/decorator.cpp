//[decorator]

class Stream {
  public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream {
  public:
    virtual char Read(int number) {
      // 读文件流
    }
    virtual void Seek(int position) {
      // 定位文件流
    }
    virtual void Write(char data) {
      // 写文件流
    }
};

// 主体类
class NetworkStream : public Stream {
  public:
    virtual char Read(int number) {
      // 读流
    }
    virtual void Seek(int position) {
      // 定位流
    }
    virtual void Write(char data) {
      // 写流
    }
};

// 主体类
class MemoryStream : public Stream {
  public:
    virtual char Read(int number) {
      // 读流
    }
    virtual void Seek(int position) {
      // 定位流
    }
    virtual void Write(char data) {
      // 写流
    }
};

// 增加一层
class DecoratorStream : public Stream {
  protected:
    Stream* stream;

    DecoratorStream(Stream* stm) : stream(stm) {}
};


// 扩展操作
class CryptoStream : public DecoratorStream {

  public:
    // 添加构造函数
    CryptoStream(Stream* stm) : DecoratorStream(stm) {}

    virtual char Read(int number) {
      //额外的加密操作...
      stream->Read(number); //读文件流
    }
    ...
};

// 扩展操作
class BufferedStream : public DecoratorStream {

  public:
    BufferedStream(Stream* stm) : DecoratorStream(stm) {}

    virtual char Read(int number) {
      //额外的缓冲操作...
      stream->Read(number); //读文件流
    }
    ...
};

void Process() {
  // 运行时装配
  FileStream* s1 = new FileStream();
  CryptoStream* s11 = new CryptoStream(s1);
  BufferedStream* s12 = new BufferedStream(s1);
  BufferedStream* s13 = new BufferedStream(s11);  // CryptoBufferedFileStream

}
