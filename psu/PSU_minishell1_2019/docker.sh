#!/bin/bash
SOURCE_FOLDER=/home/AvoidThis/delivery/PSU_minishell1_2019
DEST_FOLDER=/home/student

sudo docker run --rm -v "$SOURCE_FOLDER:$DEST_FOLDER" -it epitechcontent/epitest-docker bin/bash -c "useradd student && su - student"
