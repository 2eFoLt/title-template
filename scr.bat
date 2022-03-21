@echo off
del /s *.pro.user
echo Removed all pro.user files, clean to commit/push
git status
pause
