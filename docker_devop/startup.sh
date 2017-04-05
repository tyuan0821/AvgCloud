#!/bin/bash 

echo "================================"
echo "Environment healtcheck"
echo "================================"
echo "USER is:            $USER"
echo "HOME is set to:     $HOME"

echo "================================"
echo -n "Checking ssh keys"
if [ ! -e $HOME/.ssh/id_rsa ]
then 
	echo
	echo "Fixing ssh keys..."
	if [ -e $HOME/.ssh/id_rsa_orig ]
	then
		cp $HOME/.ssh/id_rsa_orig $HOME/.ssh/id_rsa
	else
		echo "id_rsa_orig not found. EXITING (1)"
		exit 1;
	fi
fi
if [ $(stat -c %a $HOME/.ssh/id_rsa) != 600 ]
then
	chmod 600 $HOME/.ssh/id_rsa
fi
echo "        OK"

echo "================================"
echo "Verify environment variables:"
echo
echo "AVG_BASE_ROOT: " $AVG_BASE_ROOT


echo "================================"
echo "Verify installed programs:"
echo
echo "g++:           " `g++ -dumpversion`
echo "git:           " `git --version`
echo "make:          " `make -version | head -1`
echo "python:        " `python -V 2>&1`

echo "================================"
echo "Verify git data:"
echo
echo "Git user:      " `git config --get user.name`
echo "Git e-mail:    " `git config --get user.email`

echo "================================"
echo "DONE"
echo "================================"



