#!/bin/bash

# ===============================================
# Date:                           08. 11. 2024.
# Author:                     Slađan Stevanović
# ===============================================

# Ensure UTF-8 encoding
export LANG=en_US.UTF-8

echo "=============================="
echo " PATH variable has been updated!"
echo "=============================="

if [ -d "../ssh" ]; then
    exit 0
fi

echo
read -p "Enter your name and surname: " name_and_surname
read -p "Enter your email: " email
read -p "Enter your index number (format XXXXGG): " index_number

password_input() {
    echo
    read -s -p "Enter the password for your SSH key: " password
    echo
    read -s -p "Re-enter the password for your SSH key: " repeated_password

    if [ "$password" != "$repeated_password" ]; then
        echo
        echo "==============================================="
        echo " Passwords do not match! Please try again..."
        echo "==============================================="
        password_input
    fi
}

password_input

mkdir ssh
cd ssh || exit
ssh-keygen -t rsa -b 2048 -f key -N "$password" > /dev/null

# Try to copy to clipboard
if command -v xclip > /dev/null; then
    xclip -sel clip < key.pub
    echo "SSH key copied to clipboard using xclip."
elif command -v xsel > /dev/null; then
    xsel --clipboard < key.pub
    echo "SSH key copied to clipboard using xsel."
else
    echo "==================================================================="
    echo " Unable to copy SSH key to clipboard. Please manually copy the key:"
    echo "==================================================================="
    cat key.pub
fi
cd ..

echo
echo "==================================================================="
echo " Your public key, which you add to BitBucket, is ready!"
echo " After adding the key, press any key to continue..."
echo "==================================================================="
read -n 1

echo
echo "==============================================================================="
echo " Great! When BitBucket prompts you for a password, enter your SSH key password."
echo "==============================================================================="

repository_name="P1"
mkdir "$repository_name"
cd "$repository_name" || exit
git init > /dev/null
git config --local user.name "$name_and_surname"
git config --local user.email "$email"
git config --local core.sshCommand "ssh -i ../../ssh/key"
git remote add origin "git@github.com:Kaisharev/P1.git"
git pull origin master
git branch --set-upstream-to=origin/master master
cd ..

echo
echo "========================================================"
echo " Your repository has been cloned and is ready for use!"
echo "========================================================"
