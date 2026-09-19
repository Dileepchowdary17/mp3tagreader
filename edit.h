#ifndef EDIT_H
#define EDIT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validate_edit_arg(char *argv[]);

int edit_tag(char *option,char *new_name,char *filename);

int big_to_little_endien(unsigned char *tag_size);

void convert_integer_to_bigEndien(unsigned int new_tag_size, unsigned char *new_size_int);

#endif