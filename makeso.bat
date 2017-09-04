@echo off
cp -rf ../../ygopro-server/ygopro-server/servers/ygopro-222/ygopro/ocgcore Classes
cd libcore

ndk-build -j4
pause