echo 
:again
TestMaker.exe > input.txt
std.exe < input.txt > std_output.txt
hack.exe < input.txt > hack_output.txt
fc std_output.txt hack_output.txt
if not errorlevel 1 goto again
echo 
echo 
echo 
echo 
echo 
echo 
pause