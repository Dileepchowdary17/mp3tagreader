#include "view.h"

int validate_view_arg(char *argv[]){
    char *txt = strrchr(argv[2],'.');
    if(txt == NULL || strcmp(txt,".mp3")!=0){
        printf("Error:It's not an mp3 file\n");
        return 1;
    }
    return 0;
}

int convertbigtolittleendien(char *size_of_tag){
    return((unsigned int)size_of_tag[0]<<24)|
        ((unsigned int)size_of_tag[1]<<16)|
        ((unsigned int)size_of_tag[2]<<8)|
        ((unsigned int)size_of_tag[3]);
}

int view_tag_reader(char *sample){
    FILE *fp = fopen(sample,"rb");
    if(fp == NULL){
        printf("Error: we can't open this file\n");\
        return 1;
    }

    char id[4];
    fread(id,1,3,fp);
    id[3]='\0';

    if(strcmp(id,"ID3")!=0){
        printf("ID3 tag not found\n");
        fclose(fp);
        return 1;
    }


    unsigned char version_nb[2];
    fread(version_nb,1,2,fp);
    printf("ID3 version : 2.%d.%d\n",
        version_nb[0],
        version_nb[1]);
    fseek(fp,5,SEEK_CUR);
    
    while(1){

        char tag_id[5];
        if(fread(tag_id,1,4,fp)!=4){
            break;
        }
        tag_id[4] = '\0';
        // printf("DEBUG: [%s]\n",tag_id);

        if(tag_id[0] == '\0'){
            break;
        }

        unsigned char size_of_tag[4];
        fread(size_of_tag,1,4,fp);

        unsigned int size_of_frame = convertbigtolittleendien((char*)size_of_tag);

        fseek(fp,2,SEEK_CUR);

        unsigned char encoded_data;
        fread(&encoded_data,1,1,fp);
        
        size_of_frame--;

        char *tag_data = malloc(size_of_frame + 1);

        if(tag_data == NULL){
            fclose(fp);
            return 1;
        }

        fread(tag_data,1,size_of_frame,fp);
        tag_data[size_of_frame] = '\0';

        if(strcmp(tag_id,"APIC")==0){
            free(tag_data);
            continue;
        }
        if(strcmp(tag_id,"TIT2")==0){
            printf("Title       : %s\n",tag_data);
        }
        if(strcmp(tag_id,"TYER")==0){
            printf("Year        : %s\n",tag_data);
        }
        if(strcmp(tag_id,"TPE1")==0){
            printf("Artist      : %s\n",tag_data);
        }
        if(strcmp(tag_id,"TALB")==0){
            printf("Album       : %s\n",tag_data);
        }
        if(strcmp(tag_id,"TCON")==0){
            printf("Genre       : %s\n",tag_data);
        }
        if(strcmp(tag_id,"COMM")==0){
            printf("Comments    : %s\n",tag_data);
        }

        free(tag_data);
    }
    fclose(fp);
    return 0;
}