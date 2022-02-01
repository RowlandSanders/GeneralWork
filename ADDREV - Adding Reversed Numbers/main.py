num = int(input())
temp=[]
for i in range(num):
    temp.append(input().split(" "))
    
def reverseSum(a,b):
    a = a[::-1]
    b = b[::-1]
    c = int(a)+int(b)
    c=str(c)[::-1]
    return int(c)
    

for i in range(len(temp)):
  print(reverseSum(temp[i][0],temp[i][1]))
