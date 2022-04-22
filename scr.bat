@echo off
del /s /q *.pro.user
rmdir /s /q build-echoClient-Desktop_Qt_6_2_3_MinGW_64_bit-Debug
rmdir /s /q build-echoServer-Desktop_Qt_6_2_3_MinGW_64_bit-Debug
rmdir /s /q build-graphDraw-Desktop_Qt_6_2_3_MinGW_64_bit-Debug
echo Clean to commit/push
pause
