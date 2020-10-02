# How to use RTCOP/ContextROS sample

## install mono framework
> sudo apt install mono-devel

## change to src directory
> cd catkin_ws/src

## clone RTCOP
> git clone https://github.com/tanigawaikuta/RTCOP.git

## clone sample program
> git clone https://github.com/hisazumi/crostest

## build
```
cd crostest
sh gen.sh  # for running layer compiler
catkin build
```
