#ifndef VIEW_H
#define VIEW_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validate_view_arg(char *argv[]);

int view_tag_reader(char *sample);

int convertbigtolittleendien(char *size_of_tag);
#endif