@echo off

echo Building data

cd temp/ygopro-222DIY
git checkout master
git pull origin master
cp -rf ocgcore ../../Classes
cp -rf lflist.conf ../../mobile/assets/data/core/3.5/config
rm -rf ../../mobile/assets/data/core/3.5/config/strings.conf
cat ../koishi_ocgupd/ygopro-7210srv/strings.conf expansions/strings.conf > ../../mobile/assets/data/core/3.5/config/strings.conf

echo Copying files
git checkout data
git pull origin data

cd ..

rm -rf pics
rm -rf script
cp -rf ygopro-222DIY/expansions/pics .
cp -rf ygopro-222DIY/expansions/script .
cp -rf koishi_ocgupd/data/pics .
cp -rf koishi_ocgupd/data/expansions/pics .
cp -rf koishi_ocgupd/ygopro-7210srv/expansions/script .
cp -rf ygopro-scripts/*.lua script

echo Zipping files
rm -rf ../mobile/assets/data/script.zip
rm -rf ../../pics.zip
"../tools/7za.exe" a ../mobile/assets/data/script.zip script -xr!.git* -mx=0
"../tools/7za.exe" a ../../pics.zip pics -xr!.git* -mx=0

echo Merging databases
rm -rf ../mobile/assets/data/cards.cdb
"../tools/sqlite3.exe" koishi_ocgupd/ygopro-7210srv/cards.cdb < ../tools/mgcmd
"../tools/sqlite3.exe" ../mobile/assets/data/cards.cdb < merge.mg
"../tools/sqlite3.exe" koishi_ocgupd/ygopro-7210srv/expansions/pre-release.cdb < ../tools/mgcmd
"../tools/sqlite3.exe" ../mobile/assets/data/cards.cdb < merge.mg
"../tools/sqlite3.exe" koishi_ocgupd/ygopro-7210srv/expansions/pre-update.cdb < ../tools/mgcmd
"../tools/sqlite3.exe" ../mobile/assets/data/cards.cdb < merge.mg
"../tools/sqlite3.exe" ygopro-222DIY/expansions/222DIY.cdb < ../tools/mgcmd
"../tools/sqlite3.exe" ../mobile/assets/data/cards.cdb < merge.mg

echo Compiling core
cd ../libcore
"../ndk/ndk-build.cmd" -j4

echo Pushing to GitHub
cd ..
git add . -A
git commit -m "Build"
git push origin master

echo Make complete
pause