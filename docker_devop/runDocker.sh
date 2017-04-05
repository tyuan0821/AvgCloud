#!/bin/bash

if [ -e  /home/${USER}/.babun-docker/setup.sh ]
then
	source /home/${USER}/.babun-docker/setup.sh
fi

export CYG_PATH=`echo $CYGWIN_HOME | sed -e 's@C:@/c@'`
echo "Your HOME dir: (${CYG_PATH}/${HOME})"

export SSH_PATH=$CYG_PATH/home/${USER}/.ssh
echo ".ssh: $SSH_PATH"
export D_HOME=/root


export WORKSPACE=${CYG_PATH}/`pwd`/git_workspace
if [ ! -e git_workspace ] 
then 
	echo "Git repository is placed in $WORKSPACE"
	git clone ssh://gitolite@openalm.lmera.ericsson.se/hss-prototype-team/CloudifyAVG.git git_workspace
fi

#export ETC_PATH=$CYG_PATH/etc/ 
#echo "etc: $ETC_PATH"

echo "USER: $USER"

echo "docker run -it \
	-v ${SSH_PATH}/id_rsa:${D_HOME}/.ssh/id_rsa_orig \
	-v ${CYG_PATH}/${HOME}/.gitconfig:${D_HOME}/.gitconfig \
	-v ${CYG_PATH}/${HOME}/HSS_Proto/CloudifyAVG/docker_devop/startup.sh:${D_HOME}/startup.sh \
	-v ${WORKSPACE}:${D_HOME}/workspace \
	--rm \
	--name avgops \
        armdocker.rnd.ericsson.se/proj_hss/avg_devops:3 bash"

#
#	-v ${ETC_PATH}/passwd:/etc/passwd:ro \
#	-v ${ETC_PATH}/groups:/etc/groups:ro \
#
