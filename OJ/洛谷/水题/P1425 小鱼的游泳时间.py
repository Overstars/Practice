import sys
# open('P1425.txt', mode='r')
# print("LALALALALA")
a, b, c, d = map(int, input().split())
diff=c*60+d-a*60-b
# print("LALALALALA")
print(diff//60, end=' ')
print(diff%60)
