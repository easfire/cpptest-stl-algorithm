
//Facade
class File {};

class VideoFile: public File {
  // ...
};

class OggCompressionCodec {
  // ...
};

class MPEG4CompressionCodec {
  // ...
};

class CodecFactory {
  // ...
};

class BitrateReader {
  // ...
};

class AudioMixer {
  // ...
};

class VideoConverter {
  public:
    File* convert(String filename, String format); 
}

File* VideoConverter::convert(String filename, String format) {
  VideoFile* file = new VideoFile(filename);
  SourceCodec* sourceCodec = new OggCompressionCodec(file); 
}

