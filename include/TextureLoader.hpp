#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <string>

using namespace std;
class TextureLoader {
	private:
		unsigned char * rawData;
		bool isInitialized;
	public:
		void loadFile(string file);
		unsigned char * getData();
		TextureLoader();
		~TextureLoader();
};
#endif
