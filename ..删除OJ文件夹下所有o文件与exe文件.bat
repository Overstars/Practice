@echo off
chcp 65001
echo 您确定要删除OJ文件夹下的o文件与exe文件吗
pause
del OJ\*.o /s
del OJ\*.exe /s
del 网赛\*.o /s
del 网赛\*.exe /s
echo 苔花如米小，也学牡丹开
echo 你今天AC了吗~
pause
