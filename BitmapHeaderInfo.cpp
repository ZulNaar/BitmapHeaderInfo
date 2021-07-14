#include <stdio.h>

void main() {

	unsigned char buffer[54];

	FILE* img = fopen("Test.bmp", "rb");
	fseek(img, 0, SEEK_SET);
	fread(buffer, sizeof(unsigned char), 54, img);

	//BITMAPHEADER - 14 bytes
	unsigned char file_signature[2] = { buffer[0], buffer[1] };
	int file_size = buffer[2];
	int reserved_area = buffer[6];
	int data_offset = buffer[10];

	//BITMAPINFOHEADER - 40 bytes
	int info_header_size = buffer[14];
	int img_width = buffer[18];
	int img_height = buffer[22];
	short int no_planes = buffer[26];
	short int color_depth = buffer[28];
	int compression = buffer[30];
	int raw_size = buffer[34];
	int h_resolution = buffer[38];
	int v_resolution = buffer[42];
	int palette_colors = buffer[46];
	int no_important_colors = buffer[50];

	printf("File signature: %c%c(0x%02X%02Xh - little endian)\n", buffer[0], buffer[1], buffer[1], buffer[0]); // 'B' = 0x42 'M' = 0x4D
	printf("File size: %d bytes\n", file_size);
	printf("Reserved area data: %d\n", reserved_area);
	printf("Offset at which data begins: %d(0x%02Xh)\n", data_offset, data_offset);
	printf("Info header size: %d(0x%02Xh) bytes\n", info_header_size, info_header_size);
	printf("Image width: %d pixels\n", img_width);
	printf("Image height: %d pixels\n", img_height);
	printf("Number of color planes: %hd\n", no_planes);
	printf("Color depth: %hd (bits per pixel)\n", color_depth);
	printf("Compression: %d (if 0 then no compression is applied)\n", compression);
	printf("Size of the raw bitmap data(including padding): %d bytes\n", raw_size);
	printf("Horisontal resolution(print resolution): %d\n", h_resolution);
	printf("Vertical resulution(print resolution): %d\n", v_resolution);
	printf("Number of colors in the palette: %d\n", palette_colors);
	printf("Number of important colors: %d (0 means all colors are important)\n", no_important_colors);

	fclose(img);
}