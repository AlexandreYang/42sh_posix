#!/bin/bash

BASEDIR=$(dirname $0)

export obj_name=$1
export path_to_create=$2
export up_name=$(echo $obj_name | tr 'a-z' 'A-Z')
export h_file_name=$obj_name".h"
export git_root="$(git rev-parse --show-toplevel)"
export src_folder=$path_to_create/srcs/$obj_name
export template_folder=$BASEDIR/obj_templates

LEN=$(echo ${#obj_name})
if [ $LEN -lt 5 ]; then
	padding="	"
else
	padding=""
fi

##########################CREATE FOLDER#########################################
mkdir -p $path_to_create/srcs/$obj_name
function generate_file ()
{
	src=$1
	dst=$2
	cat $src | sed -e "s/<OBJ_NAME>/$obj_name/g" | sed -e "s/<PADDING>/$padding/g" | sed -e "s/<OBJ_NAME_UPPER>/$up_name/g" > $dst
}

generate_file $template_folder/obj.h includes/$h_file_name
generate_file $template_folder/obj_new.c $src_folder/$obj_name"_new.c"
generate_file $template_folder/obj_del.c $src_folder/$obj_name"_del.c"
