#include "edit.h"

int validate_edit_arg(char *argv[]){
    char *txt = strrchr(argv[4],'.');

    if(txt == NULL || strcmp(txt,".mp3")!= 0){
        printf("Error : not an mp3 file\n");
        return 1;
    }
    return 0;
}

int big_to_little_endien(unsigned char *tag_size){

    return (unsigned int)tag_size[0]<<24 |
        (unsigned int)tag_size[1]<<16 |
        (unsigned int)tag_size[2]<<8 |
        (unsigned int)tag_size[3];
}

void convert_integer_to_bigEndien(unsigned int new_tag_size, unsigned char *new_size_int){
    new_size_int[0] = (new_tag_size >> 24) & 0xFF;
    new_size_int[1] = (new_tag_size >> 16) & 0xFF;
    new_size_int[2] = (new_tag_size >> 8 ) & 0xFF;
    new_size_int[3] = (new_tag_size      ) & 0xFF;
}

int edit_tag(char *option,char *new_name,char *filename){
    FILE *src = fopen(filename,"r");
    if(src == NULL){
        perror("");
        return 1;
    }

    FILE *temp = fopen("tempfile.mp3","w");
    if(temp == NULL){
        fclose(src);
        return 1;
    }

    char tag_to_edit[5];

    if(strcmp(option,"-t")==0){
        strcpy(tag_to_edit,"TIT2");
    }
    else if(strcmp(option,"-y")==0){
        strcpy(tag_to_edit,"TYER");
    }
    else if(strcmp(option,"-A")==0){
        strcpy(tag_to_edit,"TALB");
    }
    else if(strcmp(option,"-a")==0){
        strcpy(tag_to_edit,"TPE1");
    }
    else if(strcmp(option,"-g")==0){
        strcpy(tag_to_edit,"TCON");
    }
    else if(strcmp(option,"-c")==0){
        strcpy(tag_to_edit,"COMM");
    }
    else{
        printf("Edit is not supported for this option.\n");
        fclose(src);
        fclose(temp);
        return 1;
    }

    char header[10];
    fread(header,1,10,src);
    fwrite(header,1,10,temp);

    char tag_id[5];
    while(1){

        fread(tag_id,1,4,src);
        tag_id[4] = '\0';

        if(tag_id[0] == '\0'){
            break;
        }

        unsigned char tag_size[4];

        fread(tag_size,1,4,src);

        unsigned int frame_size = big_to_little_endien(tag_size);

        char flag[2];
        fread(flag,1,2,src);

        unsigned char encoded;
        fread(&encoded,1,1,src);

        if(frame_size>0){
            frame_size--;
        }

        char *data= malloc(frame_size+1);
        if(data == NULL){
            fclose(src);
            fclose(temp);
            remove("tempfile.mp3");
            return 1;
        }

        fread(data,1,frame_size,src);
        data[frame_size] = '\0';

        if(strcmp(tag_id,tag_to_edit)==0){
            fwrite(tag_id,1,4,temp);

            unsigned int new_tag_size = strlen(new_name)+1;

            unsigned char new_size_int[4];
            convert_integer_to_bigEndien(new_tag_size,new_size_int);

            fwrite(new_size_int,1,4,temp);
            fwrite(flag,1,2,temp);

            encoded = 0;
            fwrite(&encoded,1,1,temp);

            fwrite(new_name,1,strlen(new_name),temp);

        }
        else{
            fwrite(tag_id,1,4,temp);
            fwrite(tag_size,1,4,temp);
            fwrite(flag,1,2,temp);
            fwrite(&encoded,1,1,temp);
            fwrite(data,1,frame_size,temp);
        }
        free(data);

        if(strcmp(tag_id,"COMM")==0){
            break;
        }
    }

    int ch;

    while((ch = fgetc(src))!=EOF){
        fputc(ch,temp);
    }

    fclose(src);
    fclose(temp);

    remove(filename);

    rename("tempfile.mp3",filename);

    printf("Tag Edited Successfully\n");
    return 0;
}