#!/bin/bash
# Created on December 22, 2014 by Ethan Ruffing

git submodule update --init --recursive
git submodule foreach git pull origin master
unzip convex/ChibiOS_2.6.2.zip convex/

