#!/usr/bin/env sh
# Sends SIGQUIT to a process

if [ $# != 1 ]
then
	echo "Usage: $0 <pid>"
	exit 1
fi
kill -QUIT "$1"