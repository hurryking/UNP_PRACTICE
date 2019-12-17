#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 1,j =0;
    char k = '\n';

    //开始写入
    FILE *fp;
    fp=fopen("1.txt","wb");
    fwrite(&i,sizeof(i),1,fp);
    fwrite(&j,sizeof(j),1,fp);
    fwrite(&k,sizeof(k),1,fp);
    fclose(fp);

    return 0;
}