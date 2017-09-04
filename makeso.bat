@echo off
echo Building data
cp -rf ../../222DIY/git-build-server/ocgcore Classes
cp -rf ../../222DIY/git-build-server/lflist.conf mobile/assets/data/core/3.5/config
rm -rf mobile/assets/data/core/3.5/config/strings.conf
cat ../../koishi_ocgupd/ygopro-7210srv/strings.conf ../../222DIY/git-build-server/expansions/strings.conf > mobile/assets/data/core/3.5/config/strings.conf
cp -rf ../script.zip mobile/assets/data

echo Merging database
mkdir databases
cd databases
cp -rf ../../../222DIY/git-build-server/expansions/222DIY.cdb .
cp -rf ../../../koishi_ocgupd/ygopro-7210srv/cards.cdb .
cp -rf ../../../koishi_ocgupd/ygopro-7210srv/expansions/pre-release.cdb .
cp -rf ../../../koishi_ocgupd/ygopro-7210srv/expansions/pre-update.cdb .
sqlite3 < ../merge.bat
cat *.mg > merge
rm -rf ../mobile/assets/data/cards.cdb
sqlite3 ../mobile/assets/data/cards.cdb < merge
cd ..
rm -rf databases

echo Compiling core
cd ../ndk
setx Path %cd%
cd ../ygopro-222DIY-mobile/libcore

ndk-build -j4
pause