#include<stdio.h>
#include<string.h>
#include "view.h"
#include "edit.h"

int main(int argc,char *argv[]){

    if(argc == 3){
        if(strcmp(argv[1],"-v")==0){

            if(validate_view_arg(argv) == 1){
                printf("Invalid Input\n");
                return 1;
            }

            view_tag_reader(argv[2]);
        }
        else{
            printf("Use this command to view the content :\n");
            printf("./a.out -v sample.mp3\n\n");
        }
        
    }
    
    else if(argc == 5){
        if(strcmp(argv[1],"-e")==0){
            
            if(validate_edit_arg(argv) == 1){
                printf("Invalid Input\n");
                return 1;
            }
            
            edit_tag(argv[2],argv[3],argv[4]);
        }
        else{
            printf("Use this command to view the content :\n");
            printf("./a.out -e <tag option> <new name> sample.mp3\n\n");
        }
    }
    else{
        printf("\nUse this commands : \n");
        printf("For displaying content :\n");
        printf("./a.out -v sample.mp3\n\n");
        printf("For edit :\n");
        printf("./a.out -e -t \"Enter_title\" sample.mp3\n");
        printf("./a.out -e -y \"Enter_year\" sample.mp3\n");
        printf("./a.out -e -a \"Enter_artist\" sample.mp3\n");
        printf("./a.out -e -A \"Enter_album\" sample.mp3\n");
        printf("./a.out -e -g \"Enter_genre\" sample.mp3\n");
        printf("./a.out -e -c \"Enter_comment\" sample.mp3\n");

    }

    return 0;
}