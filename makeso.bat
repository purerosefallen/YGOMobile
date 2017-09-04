@echo off
echo Building data
cp -rf ../../222DIY/git-build-server/ocgcore Classes
cp -rf ../../222DIY/git-build-server/lflist.conf mobile/assets/data/core/3.5/config
rm -rf mobile/assets/data/core/3.5/config/strings.conf
cat ../../koishi_ocgupd/ygopro-7210srv/strings.conf ../../222DIY/git-build-server/expansions/strings.conf > mobile/assets/data/core/3.5/config/strings.conf
cp -rf ../cards.cdb mobile/assets/data
cp -rf ../script.zip mobile/assets/data
echo Compiling core
cd ../ndk
setx Path %cd%
cd ../ygopro-222DIY-mobile/libcore

ndk-build -j4
echo Pushing to GitHub
cd ..
git add . -A
git commit -m build
git push origin master
pause