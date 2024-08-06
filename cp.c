#include<stdio.h>
#include<stdlib.h>

// 赋予别名
typedf uint8_t BYTE;

ine main(int argc, char *argv[])
{                              //读取二进制
    FILE *src = fopen(argv[1], "rb");
                               //写入二进制
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;
                //从src读取并放入b（一个中转处）
    while (fread(&b, sizeof(b), 1, src) !=o)
    {           //从b（一个中转处）并写入dst
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
