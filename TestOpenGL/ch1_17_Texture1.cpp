#include <iostream>
#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using std::cout;

int main() {
	printf("OpenGL:Texture ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true); // flip vertical
	unsigned char* data = stbi_load("pic.png", &width, &height, &nrChannels, 0);
	
	if (data == NULL) {
		printf("OpenGL:Texture error!\n");
		getchar();
	}

	for (size_t i = 0; i < 50; i++) {      // RGBA pic = R0,G0,B0,A0,R1,G1,B1,A1,R2,G2,B2,A2..............Rn,Gn,Bn,An
		cout << (int)data[i] << std::endl; // RGB pic = R0,G0,B0,R1,G1,B1,R2,G2,B2,..............Rn,Gn,Bn,
	}
	printf("OpenGL:Texture --------------------------------------------------------------------------\n");
	char ch = getchar();
	stbi_image_free(data);
	return 0;
}