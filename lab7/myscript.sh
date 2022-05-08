#!/bin/bash

# Course resource directory and the destination directory to save for the 
# changed files.
RESOURCE_DIR="$HOME/Course_Resources/starter_code"
DEST_DIR="$HOME/H9shen_CS5008SPRING2022"
DEFAULT_FOLDER="lab7"
${ASSIGNMENT}

# Step0: Function to prompt the user to enter the assignment they want the starter
# code. If the user enter nothing, it will use the default lab7, which is this lab.
prompt_user_select_assignment() {
    echo -n "Please enter the assignment of which starter code you want:"
    read -r ASSIGNMENT
}

# Step1: Function to change to the local course resource directory. If the 
# directory does not exists, exit the program with failure code 1.
change_dir_to_resource() {
    echo "Changed to resource directory '$RESOURCE_DIR'."
    cd "$RESOURCE_DIR" || exit 1
}

# Step2: Function to make a new directory based on argument to save the changed
# files once copied from the course resource directory if it does not exist.
make_dest_dir_if_not_exist() {
    local dest_dir
    if [[ -n "$1" ]]; then
        dest_dir="$DEST_DIR/$1"
    else 
        dest_dir="$DEST_DIR/$DEFAULT_FOLDER"
    fi
    echo "Make a new github directory '$dest_dir' if it does not exist."
    mkdir -p "$dest_dir"
    chmod 700 "$dest_dir"
}

# Step3: Function to pull the course resource directory to reflect all the changes.
pull_dir() {
    echo "Git pull"
    git pull
}

# Step4: Function to compare the current git HEAD with the previous HEAD to 
# determine the files changed and copy these files to the changed_file directory.
copy_files() {
    if [[ -n "$1" ]]; then
        echo "Copied changed files from resource folder '$RESOURCE_DIR/$1' to my github directory '$DEST_DIR/$1'."
        files=$(git diff --name-only HEAD^ HEAD -- "$1")
    else
        echo "Copied changed files from resource directory '$RESOURCE_DIR/$DEFAULT_FOLDER' to my github directory '$DEST_DIR/$DEFAULT_FOLDER'."
        files=$(git diff --name-only HEAD^ HEAD -- "$DEFAULT_FOLDER")
    fi

    local resource_dir

    if [[ -n "$1" ]]; then
        resource_dir="$RESOURCE_DIR/$1"
    else
        resource_dir="$RESOURCE_DIR/$DEFAULT_FOLDER"
    fi

    for file in $files; do
        cp -R "$resource_dir/$file" "$DEST_DIR/$file"
    done
}

# Step5: Call these functions to run the shell script program.
prompt_user_select_assignment

change_dir_to_resource

make_dest_dir_if_not_exist "$ASSIGNMENT"

pull_dir

copy_files "$ASSIGNMENT"
