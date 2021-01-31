input = open("./numbers.txt").readline
n = int(input())
res = 0
for i in range(n):
    res += int(input())
print( res, "bytes" )
print( res / 1024, "KB" )
print( res / 1024 / 1024, "MB" )
print( res / 1024 / 1024 / 1024, "GB" )